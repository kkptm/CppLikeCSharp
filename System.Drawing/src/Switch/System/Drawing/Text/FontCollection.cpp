#include "../../../../../include/Switch/System/Drawing/Text/FontCollection.hpp"
#include "../../../../Native/Api.hpp"

System::Drawing::Text::FontCollection::FontCollection() : families(Native::FontFamilyApi::GetInstalledFontFamilies()) {
}
