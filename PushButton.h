#ifndef FLARE_PUSH_BUTTON_H
#define FLARE_PUSH_BUTTON_H
#include <QPushButton>
#include <QString>
#include <QPainter>
#include "FlareColor.h"
#include "flare_global.h"

typedef float_t f32;

namespace Flare {
	class FLARE_EXPORT PushButton : public QAbstractButton {
		Q_OBJECT
	private:
		QColor* buttonColor;
		QColor* buttonHoverColor;
		QColor* buttonPressedColor;
		QColor* buttonTextColor;
		QColor* buttonTextHoverColor;
		QColor* buttonTextPressedColor;
		bool isAbove;
		bool isPress;
		f32 xRadius;
		f32 yRadius;
		void setIcon();
		QIcon icon();
		
	protected:
		void paintEvent(QPaintEvent* Event) override;
		void enterEvent(QEnterEvent* Event) override;
		void leaveEvent(QEvent* Event) override;
		void connectSlot();
		
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

		f32 XRadius();
		f32 YRadius();

		void setButtonColor(const QColor& color);
		void setButtonHoverColor(const QColor& color);
		void setButtonPressedColor(const QColor& color);
		void setButtonTextColor(const QColor& color);
		void setButtonTextHoverColor(const QColor& color);
		void setButtonTextPressedColor(const QColor& color);
		void setColor(const Color& color);

		void setxRadius(f32 Radius);
		void setyRadius(f32 Radius);
		void setRadius(f32 XRadius, f32 YRadius);


		explicit PushButton(QWidget* parent = nullptr);
		explicit PushButton(const QString& text, QWidget* parent = nullptr);
		PushButton(const QString& text, Color& color, QWidget* parent = nullptr);

		~PushButton();
	};
}


#endif

