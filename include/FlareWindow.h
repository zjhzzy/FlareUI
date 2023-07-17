#ifndef FLARE_WINDOW_H
#define FLARE_WINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include "Widget.h"
#include "IconButton.h"
#include "flare_global.h"

namespace Flare {
	class FLARE_EXPORT FlareWindow : public QMainWindow {
		Q_OBJECT

	public:
		FlareWindow(QWidget* parent = nullptr);
		~FlareWindow();
	protected:
		void connectSlot();
		void widgetMove();
		void resizeEvent(QResizeEvent* Event) override;
		void restoreOriginalSize();
		void mouseMoveEvent(QMouseEvent* event) override;
	private:
		bool isMax;
		bool isTitlePress;
		Widget* Title;
		Widget* Background;
		IconButton* CloseButton;
		IconButton* HideButton;
		IconButton* EnlargeButton;
		IconButton::Icon* EnlargeIcon;
		IconButton::Icon* MinimizeIcon;
		QPoint* OriginalPoint;
		QPoint* MousePoint;
		QSize* OriginalSize;
	};
}

#endif