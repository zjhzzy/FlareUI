#ifndef FLARE_PUSHBUTTON_H
#define FLARE_PUSHBUTTON_H
#include <QPainter>
#include "flare_global.h"
#include "FlareColor.h"
#include "BaseButton.h"

namespace Flare {
	class FLARE_EXPORT PushButton : public BaseButton {
		Q_OBJECT
	private:
		QColor* buttonBackColor;
		QColor* buttonTextColor;
		QColor* buttonBackHoverColor;
		QColor* buttonTextHoverColor;
		QColor* buttonBackPressedColor;
		QColor* buttonTextPressedColor;
		QIcon* buttonIcon;
		QIcon* buttonHoverIcon;
		QIcon* buttonPressedIcon;
		bool isIcon;
	protected:
		void paintEvent(QPaintEvent* event) override;
	public:
		struct Color {
			QColor buttonBackColor;
			QColor buttonTextColor;
			QColor buttonBackHoverColor;
			QColor buttonTextHoverColor;
			QColor buttonBackPressedColor;
			QColor buttonTextPressedColor;
			Color setAllBackColor(const QColor& color);
			Color setAllTextColor(const QColor& color);
		};

		struct Icon {
			QIcon buttonIcon;
			QIcon buttonHoverIcon;
			QIcon buttonPressedIcon;
			Icon setAllIcon(const QIcon& icon);
		};

		PushButton(QWidget* parent = nullptr);
		~PushButton();

		void setButtonColor(const QColor& color);
		void setButtonHoverColor(const QColor& color);
		void setButtonPressedColor(const QColor& color);
		void setButtonTextColor(const QColor& color);
		void setButtonTextHoverColor(const QColor& color);
		void setButtonTextPressedColor(const QColor& color);
		void setColor(const Color& color);
		
		void setAllIcon(const QIcon& icon);
		void setIcon(const Icon& icon);
		bool isSetIcon();

	};
}

#endif
