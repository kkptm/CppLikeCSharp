
#include "../Includes/System.h"

using namespace System;

Object* ValueType::MemberwiseClone() const {
  Object* pObject_O = null;

  if (Is<Boolean>(this))
    pObject_O = ((Object*)this)->MemberwiseClone<Boolean>();
  /*
   else if (Is<System::Byte>(_Value_O))
   pObject_O = (System::ValueType*)_Value_O.MemberwiseClone<System::Byte>();
   else if (Is<System::Char>(_Value_O))
   pObject_O = (System::ValueType*)_Value_O.MemberwiseClone<System::Char>();
   else if (Is<System::DateTime>(_Value_O))
   pObject_O = (System::ValueType*)_Value_O.MemberwiseClone<System::DateTime>();
   else if (Is<System::Double>(_Value_O))
   pObject_O = (System::ValueType*)_Value_O.MemberwiseClone<System::Double>();
   else if (Is<System::Int16>(_Value_O))
   pObject_O = (System::ValueType*)_Value_O.MemberwiseClone<System::Int16>();
   */
  return pObject_O;
}

