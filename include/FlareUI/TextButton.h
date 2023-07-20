#ifndef FLARE_TEXTBUTTON_H
#define FLARE_TEXTBUTTON_H
#include "BaseButton.h"
#include <QString>
#include <QPainter>
#include "FlareColor.h"
#include "flare_global.h"

typedef float_t f32;

namespace Flare {
	class FLARE_EXPORT TextButton : public BaseButton {
		Q_OBJECT
	private:
		QColor* buttonBrushColor;
		QColor* buttonBrushHoverColor;
		QColor* buttonBrushPressedColor;
		QColor* buttonPenColor;
		QColor* buttonPenHoverColor;
		QColor* buttonPenPressedColor;
		QColor* buttonTextColor;
		QColor* buttonTextHoverColor;
		QColor* buttonTextPressedColor;
		bool AutoSize;

	protected:
		void paintEvent(QPaintEvent* Event) override;
	public:

		struct Color {
			QColor buttonBrushColor;
			QColor buttonBrushHoverColor;
			QColor buttonBrushPressedColor;
			QColor buttonPenColor;
			QColor buttonPenHoverColor;
			QColor buttonPenPressedColor;
			QColor buttonTextColor;
			QColor buttonTextHoverColor;
			QColor buttonTextPressedColor;
			Color setButtonColor(const QColor& ButtonColor);
			Color setButtonPenColor(const QColor& ButtonColor);
			Color setButtonBrushColor(const QColor& ButtonColor);
			Color setTextColor(QColor TextColor);
			Color(QColor ButtonColor, QColor TextColor);
		};

		QColor ButtonBrushColor() const;
		QColor ButtonBrushHoverColor() const;
		QColor ButtonBrushPressedColor() const;
		QColor ButtonTextColor() const;
		QColor ButtonTextHoverColor() const;
		QColor ButtonTextPressedColor() const;

		void setButtonBrushColor(const QColor& color);
		void setButtonBrushHoverColor(const QColor& color);
		void setButtonBrushPressedColor(const QColor& color);
		void setButtonTextColor(const QColor& color);
		void setButtonTextHoverColor(const QColor& color);
		void setButtonTextPressedColor(const QColor& color);
		void setColor(const Color& color);

		explicit TextButton(QWidget* parent = nullptr);
		explicit TextButton(const QString& text, QWidget* parent = nullptr);
		TextButton(const QString& text, Color& color, QWidget* parent = nullptr);

		~TextButton();
	};
}


#endif

