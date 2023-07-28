/*
 * 版权所有 (c) 2023 Zeng Jing Hong. 保留所有权利.
 * 版权所有者：Zeng Jing Hong
 * 起始年份：2023
 * 本软件遵循BSD 2-Clause协议。
 * 对于使用本库所产生的任何直接或间接损失和风险，版权所有者不承担任何责任。
 */

#ifndef FLARE_PUSHBUTTON_H
#define FLARE_PUSHBUTTON_H
#include <QtGui/QPainter>
#include "flare_global.h"
#include "FlareColor.h"
#include "BaseButton.h"

namespace Flare {
	class FLARE_EXPORT PushButton : public BaseButton {
		Q_OBJECT
	protected:
		void paintEvent(QPaintEvent* event) override;
	public:
		struct Color {
			QColor buttonBackPenColor;
			QColor buttonBackPenHoverColor;
			QColor buttonBackPenPressedColor;
			QColor buttonBackBrushColor;
			QColor buttonBackBrushHoverColor;
			QColor buttonBackBrushPressedColor;
			QColor buttonTextColor;
			QColor buttonTextHoverColor;
			QColor buttonTextPressedColor;
            Color();
			Color setAllBackColor(const QColor& color);
			Color setAllPenColor(const QColor& color);
			Color setAllBrushColor(const QColor& color);
			Color setAllTextColor(const QColor& color);
		};



		explicit PushButton(QWidget* parent = nullptr);
		explicit PushButton(const QString& Text, QWidget* parent = nullptr);
		PushButton(Icon *icon, const QString& Text, QWidget* parent = nullptr);
        PushButton(const PushButton &button);
		~PushButton();

		void setButtonPenColor(const QColor& color);
		void setButtonPenHoverColor(const QColor& color);
		void setButtonPenPressedColor(const QColor& color);
		void setButtonBrushColor(const QColor& color);
		void setButtonBrushHoverColor(const QColor& color);
		void setButtonBrushPressedColor(const QColor& color);
		void setButtonTextColor(const QColor& color);
		void setButtonTextHoverColor(const QColor& color);
		void setButtonTextPressedColor(const QColor& color);
		void setColor(Color* color);


        void setXRadius(const f32& Radius);
        void setYRadius(const f32& Radius);
        void setRadius(const f32& x, const f32& y);
        f32 XRadius();
        f32 YRadius();
    private:
        f32 xRadius;
        f32 yRadius;
        Color* buttonColor;
	};
}

#endif