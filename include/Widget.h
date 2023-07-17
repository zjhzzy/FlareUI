#ifndef FLARE_WIDGET_H
#define FLARE_WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include "FlareColor.h"
namespace Flare {
	class FLARE_EXPORT Widget : public QWidget {
		Q_OBJECT
	private:
		bool isAbove;
		f32 xRadius;
		f32 yRadius;
		QColor* WidgetBackColor;
	protected:
		void paintEvent(QPaintEvent* Event) override;
		void enterEvent(QEnterEvent* Event) override;
		void leaveEvent(QEvent* Event) override;
		void mousePressEvent(QMouseEvent* Event) override;
		void mouseReleaseEvent(QMouseEvent* Event) override;
	public:
		Widget(QWidget* parent = nullptr);
		~Widget();

		f32 XRadius();
		f32 YRadius();
		QColor WidgetColor();

		void setxRadius(f32 Radius);
		void setyRadius(f32 Radius);
		void setRadius(f32 XRadius, f32 YRadius);
		void setWidgetColor(const QColor& color);
	signals:
		void press(QPoint mouseOffset);
		void release();
	};
}

#endif