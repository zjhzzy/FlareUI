#ifndef FLARE_MENU_H
#define FLARE_MENU_H

#include <QtWidgets/QWidget>
#include <list>
#include "PushButton.h"
#include "Widget.h"

namespace Flare {
	class Menu : public QWidget {
		Q_OBJECT

			class MenuButton : public PushButton {
			Q_OBJECT

				int index;
			public:
				MenuButton(int Index, const QString& Text, Menu* Parent);
			signals:
				void clickedIndex(int Index);

		};
	private:
		Widget* Back;
		std::list<MenuButton>* ButtonList;

	public:
		void setBackColor(const QColor& color);
		QColor BackColor();
		void addButton(const QString& buttonText);

	signals:
		void clickedButton(int index);

		Menu();
		~Menu();
	};
}

#endif