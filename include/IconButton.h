#ifndef FLARE_ICONBUTTON_H
#define FLARE_ICONBUTTON_H

#include "BaseButton.h"
#include <QPainter>
#include "flare_global.h"
#include "FlareColor.h"

typedef float_t f32;
// 一个图像按钮
namespace Flare {
	class FLARE_EXPORT IconButton : public BaseButton {
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

		void setIcon(const Icon& icon);
		void setColor(const Color& color);

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

	protected:
		void paintEvent(QPaintEvent* Event) override;

	};
}

#endif