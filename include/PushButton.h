#ifndef FLARE_PUSH_BUTTON_H
#define FLARE_PUSH_BUTTON_H
#include "BaseButton.h"
#include <QString>
#include <QPainter>
#include "FlareColor.h"
#include "flare_global.h"

typedef float_t f32;

namespace Flare {
	class FLARE_EXPORT PushButton : public BaseButton {
		Q_OBJECT
	private:
		QColor* buttonColor;
		QColor* buttonHoverColor;
		QColor* buttonPressedColor;
		QColor* buttonTextColor;
		QColor* buttonTextHoverColor;
		QColor* buttonTextPressedColor;
		
	protected:
		void paintEvent(QPaintEvent* Event) override;
		
	public:

		struct Color {
			QColor buttonColor;
			QColor buttonHoverColor;
			QColor buttonPressedColor;
			QColor buttonTextColor;
			QColor buttonTextHoverColor;
			QColor buttonTextPressedColor;
			Color setButtonColor(QColor ButtonColor);
			Color setTextColor(QColor TextColor);
			Color(QColor ButtonColor, QColor TextColor);
		};

		QColor ButtonColor() const;
		QColor ButtonHoverColor() const;
		QColor ButtonPressedColor() const;
		QColor ButtonTextColor() const;
		QColor ButtonTextHoverColor() const;
		QColor ButtonTextPressedColor() const;

		void setButtonColor(const QColor& color);
		void setButtonHoverColor(const QColor& color);
		void setButtonPressedColor(const QColor& color);
		void setButtonTextColor(const QColor& color);
		void setButtonTextHoverColor(const QColor& color);
		void setButtonTextPressedColor(const QColor& color);
		void setColor(const Color& color);

		explicit PushButton(QWidget* parent = nullptr);
		explicit PushButton(const QString& text, QWidget* parent = nullptr);
		PushButton(const QString& text, Color& color, QWidget* parent = nullptr);

		~PushButton();
	};
}


#endif

