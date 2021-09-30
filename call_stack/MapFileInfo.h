namespace stacktrace {
  struct MapFileInformation : public object {
  public:
    MapFileInformation() {}
    MapFileInformation(const MapFileInformation& mfi) : generatedDate(mfi.generatedDate) {}

    static MapFileInformation GetMapFileInformation(const string& fileName) {
      DateTime generatedDate;

      Using(System::IO::StreamReader rd(fileName)) {
        while(not rd.EndOfStream()) {
          string line = rd.ReadLine();
          if (line.StartsWith(" Timestamp is ")) {
            line = line.Substring(String(" Timestamp is ").GetLength());
            line = line.Remove(line.IndexOf(" ("));
            generatedDate = DateTime::SpecifyKind(DateTime(Int64::Parse(line, 16) * TimeSpan::TicksPerSecond(), DateTimeKind::Utc), DateTimeKind::Local);
          }
        }
      }

      return MapFileInformation(generatedDate);
    }

    const DateTime& GetGeneratedDate() const { return this->generatedDate; }
  private:
    MapFileInformation(const DateTime& generatedDate) : generatedDate(generatedDate) {}

    DateTime generatedDate;
  };
}
