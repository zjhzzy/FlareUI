#ifndef FLARE_WIDGET_H
#define FLARE_WIDGET_H

#include <QtWidgets/QWidget>
#include <QtGui/QPainter>
#include <QtGui/QMouseEvent>
#include <QtGui/QFocusEvent>
#include "FlareColor.h"

typedef float_t f32;

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
		explicit Widget(QWidget* parent = nullptr);
		~Widget() override;

		f32 XRadius() const;
		f32 YRadius() const;
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