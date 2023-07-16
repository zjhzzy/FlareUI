#ifndef FLARE_WINDOW_H
#define FLARE_WINDOW_H

#include <QWidget>
#include "IconButton.h"
#include "flare_global.h"

namespace Flare {
	class FLARE_EXPORT FlareWindow : public QWidget {
		Q_OBJECT

	public:
		FlareWindow(QWidget* parent = nullptr);
		~FlareWindow();
	protected:
		void connectSlot();
	private:
		IconButton* CloseButton;
		IconButton* HideButton;
		IconButton* EnlargeButton;
	};
}

#endif