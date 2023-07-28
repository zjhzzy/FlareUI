/*
 * 版权所有 (c) 2023 Zeng Jing Hong. 保留所有权利.
 * 版权所有者：Zeng Jing Hong
 * 起始年份：2023
 * 本软件遵循BSD 2-Clause协议。
 * 对于使用本库所产生的任何直接或间接损失和风险，版权所有者不承担任何责任。
 */

#ifndef FLARE_WIDGET_H
#define FLARE_WIDGET_H

#include <QtWidgets/QWidget>
#include <QtGui/QPainter>
#include <QtGui/QMouseEvent>
#include <QtGui/QFocusEvent>
#include "flare_global.h"
#include "FlareColor.h"

namespace Flare {
	class FLARE_EXPORT Widget : public QWidget {
		Q_OBJECT
	private:
		bool isAbove;
		f32 xRadius;
		f32 yRadius;
		QColor* backColor;
	protected:
		void paintEvent(QPaintEvent* Event) override;
		void enterEvent(QEnterEvent* Event) override;
		void leaveEvent(QEvent* Event) override;
		void mousePressEvent(QMouseEvent* Event) override;
		void mouseReleaseEvent(QMouseEvent* Event) override;
	public:
		explicit Widget(QWidget* parent = nullptr);
		~Widget() override;

		f32 XRadius() const;
		f32 YRadius() const;
		QColor BackColor();

		void setxRadius(f32 Radius);
		void setyRadius(f32 Radius);
		void setRadius(f32 XRadius, f32 YRadius);
		void setBackColor(const QColor& color);
	signals:
		void press(QPoint mouseOffset);
		void release();
	};
}

#endif