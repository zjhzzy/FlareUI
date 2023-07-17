#ifndef FLARE_ICONBUTTON_H
#define FLARE_ICONBUTTON_H

#include <QAbstractButton>
#include <QPainter>
#include "flare_global.h"
#include "FlareColor.h"

typedef float_t f32;
// 一个图像按钮
namespace Flare {
	class FLARE_EXPORT IconButton : public QAbstractButton {
		Q_OBJECT
	public:
		struct Color {
			QColor buttonBackColor;
			QColor buttonBackHaverColor;
			QColor buttonBackPressedColor;
			Color setAllColor(const QColor& color);
		};

		struct Icon {
			QIcon buttonIcon;
			QIcon buttonHovenIcon;
			QIcon buttonPressedIcon;
			Icon setAllIcon(const QIcon& icon = QIcon());
		};

		f32 XRadius();
		f32 YRadius();

		void setIcon(const Icon& icon);
		void setColor(const Color& color);
		void setxRadius(const f32 Radius);
		void setyRadius(const f32 Radius);
		void setRadius(const f32 XRadius,const f32 YRadius);

		explicit IconButton(QWidget* parent = nullptr);
		explicit IconButton(const Icon& icon, QWidget* parent = nullptr);

		~IconButton();

	private:
		QIcon* buttonIcon;
		QIcon* buttonHovenIcon;
		QIcon* buttonPressedIcon;

		QColor* buttonBackColor;
		QColor* buttonBackHoverColor;
		QColor* buttonBackPressedColor;
		
		bool isPress;
		bool isAbove;
		f32 xRadius;
		f32 yRadius;

	protected:
		void paintEvent(QPaintEvent* Event) override;
		void enterEvent(QEnterEvent* Event) override;
		void leaveEvent(QEvent* Event) override;
		void connectSlot();

	};
}

#endif