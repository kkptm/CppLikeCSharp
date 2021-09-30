#pragma once

#include <Switch/System/Object.hpp>
#include <Switch/System/IO//BinaryReader.hpp>

#include "../../../../include/Switch/System/Drawing/Image.hpp"
#include "../../../../include/Switch/System/Drawing/Imaging/FrameDimension.hpp"

namespace Switch {
  namespace System {
    namespace Drawing {
      class Tif : public object {
      public:
        template<typename TStream>
        Tif(const TStream& stream) : reader(stream) {}

        Tif(refptr<System::IO::Stream> stream) : reader(stream) {}

        void Read(Image& image) {
        }

      private:
        System::IO::BinaryReader reader;
      };
    }
  }
}
