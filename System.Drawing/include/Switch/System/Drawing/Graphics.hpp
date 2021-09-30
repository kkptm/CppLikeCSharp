/// @file
/// @brief Contains Switch::System::Drawing::Graphics class.
#pragma once

#include <Switch/System/Object.hpp>
#include <Switch/System/String.hpp>
#include <Switch/System/Convert.hpp>
#include "../../SystemDrawingExport.hpp"
#include "Brush.hpp"
#include "Color.hpp"
#include "Font.hpp"
#include "SolidBrush.hpp"
#include "Pen.hpp"
#include "Point.hpp"
#include "Rectangle.hpp"
#include "RectangleF.hpp"
#include "Size.hpp"
#include "SizeF.hpp"

/// @cond
namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        class Control;
      }
    }
  }
}
/// @endcond

namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      enum class StringAlignment {
        Near,
        Center,
        Far
      };

      class system_drawing_export_ StringFormat {
      public:
        StringFormat() {}
        StringFormat(const StringFormat& stringFormat) : alignment(stringFormat.alignment), lineAlignment(stringFormat.lineAlignment) {}

        property_<StringAlignment> Alignment {
          get_ {return this->alignment;},
          set_ {this->alignment = value;}
        };

        property_<StringAlignment> LineAlignment {
          get_ {return this->lineAlignment;},
          set_ {this->lineAlignment = value;}
        };

      private:
        StringAlignment alignment = StringAlignment::Near;
        StringAlignment lineAlignment = StringAlignment::Near;
      };

      class system_drawing_export_ Graphics : public Object {
      public:
        /// @cond
        ~Graphics();
        /// @endcond

        property_<RectangleF, readonly_> ClipBounds {
          get_ { return this->clipRectangle; }
        };

        void Clear(const Color& color);

        void DrawArc(const Pen& pen, int32 x, int32 y, int32 w, int32 h, float startAngle, float sweepAngle);

        void DrawArc(const Pen& pen, const Rectangle& rectangle, float startAngle, float sweepAngle) {this->DrawArc(pen, rectangle.X(), rectangle.Y(), rectangle.Width(), rectangle.Height(), startAngle, sweepAngle);}

        void DrawBezier(const Pen& pen, double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);

        void DrawBezier(const Pen& pen, int32 x1, int32 y1, int32 x2, int32 y2, int32 x3, int32 y3, int32 x4, int32 y4) {this->DrawBezier(pen, Convert::ToDouble(x1), Convert::ToDouble(y1), Convert::ToDouble(x2), Convert::ToDouble(y2), Convert::ToDouble(x3), Convert::ToDouble(y3), Convert::ToDouble(x4), Convert::ToDouble(y4));}

        void DrawEllipse(const Pen& pen, int32 x, int32 y, int32 w, int32 h) {this->DrawArc(pen, x, y, w, h, 0.0f, 360.0f);}

        void DrawEllipse(const Pen& pen, const Rectangle& rectangle) {this->DrawEllipse(pen, rectangle.X(), rectangle.Y(), rectangle.Width(), rectangle.Height());}

        void DrawLine(const Pen& pen, Point p1, Point p2) {DrawLine(pen, p1.X, p1.Y, p2.X, p2.Y);}

        void DrawLine(const Pen& pen, int32 x1, int32 y1, int32 x2, int32 y2);

        void DrawPie(const Pen& pen, int32 x, int32 y, int32 w, int32 h, float startAngle, float sweepAngle);

        void DrawPie(const Pen& pen, const Rectangle& rectangle, float startAngle, float sweepAngle) {this->DrawPie(pen, rectangle.X(), rectangle.Y(), rectangle.Width(), rectangle.Height(), startAngle, sweepAngle);}

        void DrawRectangle(const Pen& pen, int32 x, int32 y, int32 w, int32 h);

        void DrawRectangle(const Pen& pen, const Rectangle& r) {this->DrawRectangle(pen, r.Left(), r.Top(), r.Width(), r.Height());}

        void FillEllipse(const Brush& brush, int32 x, int32 y, int32 w, int32 h) {this->FillPie(brush, x, y, w, h, 0.0f, 360.0f);}

        void FillEllipse(const Brush& brush, const Rectangle& rectangle) {this->DrawEllipse(brush, rectangle.X(), rectangle.Y(), rectangle.Width(), rectangle.Height());}

        void DrawString(const string& str, const Font& font, const Brush& brush, const float x, float y) {
          SizeF size = MeasureString(str, font);
          DrawString(str, font, brush, RectangleF(x, y, size.Width, size.Height), StringFormat());
        }

        void DrawString(const string& str, const Font& font, const Brush& brush, const float x, float y, const StringFormat& format) {
          SizeF size = MeasureString(str, font);
          DrawString(str, font, brush, RectangleF(x, y, size.Width, size.Height), format);
        }

        void DrawString(const string& str, const Font& font, const Brush& brush, const RectangleF& layoutRectangle) {DrawString(str, font, brush, layoutRectangle, StringFormat());}

        void DrawString(const string& str, const Font& font, const Brush& brush, const RectangleF& layoutRectangle, const StringFormat& format);

        void FillPie(const Brush& brush, int32 x, int32 y, int32 w, int32 h, float startAngle, float sweepAngle);

        void FillPie(const Brush& brush, const Rectangle& rectangle, float startAngle, float sweepAngle) {this->FillPie(brush, rectangle.X(), rectangle.Y(), rectangle.Width(), rectangle.Height(), startAngle, sweepAngle);}

        void FillRectangle(const Brush& brush, int32 x, int32 y, int32 w, int32 h);

        void FillRectangle(const Brush& brush, const Rectangle& r) {this->FillRectangle(brush, r.Left(), r.Top(), r.Width(), r.Height());}

        SizeF MeasureString(const string& str, const Font& font) const;

        static Graphics FromHwndInternal(intptr hwnd);

        static Graphics FromHdcInternal(intptr hdc);

      private:
        friend class Switch::System::Windows::Forms::Control;
        void SetRectangle(const Rectangle& clipRectangle) { this->clipRectangle = clipRectangle; }
        Graphics(intptr hdc, const Rectangle& clipRectangle) : hdc(hdc), clipRectangle(clipRectangle) {}
        Graphics(intptr hwnd, intptr hdc, const Rectangle& clipRectangle) : hwnd(hwnd), hdc(hdc), clipRectangle(clipRectangle) {}
        Graphics(const Graphics& graphics) : clipRectangle(graphics.clipRectangle) {}
        static void SetColor(const System::Drawing::Color& color);

        intptr hwnd = IntPtr::Zero;
        intptr hdc = IntPtr::Zero;
        Rectangle clipRectangle;
      };
    }
  }
}
