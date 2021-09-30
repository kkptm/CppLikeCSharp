#if defined(__linux__) || defined(__APPLE__)

#include <cstdio>
#include <cstring>

#if defined(__APPLE__)
#include <sys/mount.h>
#else
#include <sys/statfs.h>
#endif
#include <sys/statvfs.h>

#include "../../include/Switch/System/Collections/Generic/Dictionary.hpp"
#include "Api.hpp"

bool Native::DriveApi::GetAvailableFreeSpace(const string& rootPathName, int64& freeBytes, int64& totalNumberOfBytes, int64& totalNumberOfFreeBytes) {
  struct statfs stat;
  if (::statfs(rootPathName.Data(), &stat) != 0)
    return false;

  freeBytes = (stat.f_flags & ST_RDONLY) == ST_RDONLY ? 0 : stat.f_bavail * stat.f_bsize;
  totalNumberOfBytes = stat.f_blocks * stat.f_bsize;
  totalNumberOfFreeBytes = (stat.f_flags & ST_RDONLY) == ST_RDONLY ? 0 : stat.f_bfree * stat.f_bsize;
  return true;
}

namespace {
  string rootDrive = {"/"};
  #if defined(__APPLE__)
  string AmovibleMountedPoint() {return "/Volumes";}
  System::Array<string> ramDrives = {"/Dev"};
  System::Array<string> networkDrives = {"/net", "/home"};
  #else
  string AmovibleMountedPoint() {return System::Environment::ExpandEnvironmentVariables("/media/%USER%");}
  System::Array<string> ramDrives = {"/run/vmblock-fuse", "/run/user/1000/gvfs"};
  System::Array<string> networkDrives = {"/net", "/home", "/Network/Servers"};
  #endif
}

System::IO::DriveType Native::DriveApi::GetDriveType(const string& rootPathName) {
  if (ramDrives.Contains(rootPathName))
    return System::IO::DriveType::Ram;
  if (rootPathName.StartsWith(AmovibleMountedPoint()))
    return System::IO::DriveType::CDRom;
  if (networkDrives.Contains(rootPathName))
    return System::IO::DriveType::Network;
  return System::IO::DriveType::Fixed;
}

System::Array<string> Native::DriveApi::GetDrives() {
  System::Collections::Generic::List<string> drives;
  drives.Add(rootDrive);
  drives.AddRange(ramDrives);
  drives.AddRange(networkDrives);

  for (string drive : Native::DirectoryApi::EnumerateDirectories(AmovibleMountedPoint(), "*")) {
    struct statfs stat;
    #if defined(__APPLE__)
    if (statfs(drive.Data(), &stat) == 0 && string(stat.f_mntonname) != rootDrive)
    #else
    if (statfs(drive.Data(), &stat) == 0)
    #endif
      drives.Add(drive);
  }

  return drives.ToArray();
}

bool Native::DriveApi::GetVolumeInformation(const string& rootPathName, string& volumeName, string& fileSystemName) {
  struct statfs stat;
  if (statfs(rootPathName.Data(), &stat) != 0)
    return false;

  volumeName = rootPathName;
  #if defined(__APPLE__)
  fileSystemName = stat.f_fstypename;
  #else
  static System::Collections::Generic::Dictionary<uint32, string> fileSystemNames = {{0x0000adf5, "adfs"}, {0x0000adff, "adfs"}, {0x42465331, "befs"}, {0x1BADFACE, "bfs"}, {0xFF534D42, "cifs"}, {0x73757245, "coda"}, {0x012FF7B7, "coh"}, {0x28cd3d45, "cramfs"}, {0x00001373, "devfs"}, {0x00414A53, "efs"}, {0x0000137D, "ext"}, {0x0000EF51, "ext2"}, {0x0000EF52, "ext3"}, {0x0000EF53, "ext4"}, {0x00004244, "hfs"}, {0xF995E849, "hpfs"}, {0x958458f6, "hgfs"}, {0x00009660, "isofs"}, {0x000072b6, "jffs2"}, {0x3153464a, "jfs"}, {0x0000137F, "minix"}, {0x0000138F, "minix"}, {0x00002468, "minix2"}, {0x00002478, "minix2"}, {0x00004d44, "fat32"}, {0x0000564c, "ncp"}, {0x00006969, "nfs"}, {0x5346544e, "ntfs"}, {0x00009fa1, "openprom"}, {0x00009fa0, "proc"}, {0x0000002f, "qnx4"}, {0x52654973, "reiserfs"}, {0x00007275, "romfs"}, {0x0000517B, "smb"}, {0x012FF7B6, "sysv2"}, {0x012FF7B5, "sysv4"}, {0x01021994, "tmpfs"}, {0x15013346, "udf"}, {0x00011954, "ufs"}, {0x00009fa2, "usb device"}, {0xa501FCF5, "vxfs"}, {0x012FF7B4, "xenix"}, {0x58465342, "xfs"}, {0x012FD16D, "_xiafs"}};
  if (!fileSystemNames.ContainsKey(stat.f_type))
    fileSystemName = "unknown";
  else
    fileSystemName = fileSystemNames[stat.f_type];
  #endif
  return true;
}

bool Native::DriveApi::SetVolumeLabel(const string& rootPathName, const string& volumeName) {
  // It's not possible to change volume label on Apple System
  return false;
}

#endif
