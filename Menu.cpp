#include "Menu.h"

void Flare::Menu::setBackColor(const QColor& color) {
	Back->setWidgetColor(color);
}

QColor Flare::Menu::BackColor() {
	return Back->WidgetColor();
}

void Flare::Menu::addButton(const QString& buttonText) {
	ButtonList->emplace_back(MenuButton(ButtonList->size(), buttonText, this));
	connect(&ButtonList->back(), &MenuButton::clickedIndex, this, [this](int Index) {
		emit clickedButton(Index);
		});
}

Flare::Menu::Menu()
	: QWidget(nullptr), Back(new Widget()),ButtonList(new std::list<MenuButton>()) {
	Back->resize(size());
	Back->move(0, 0);
}

Flare::Menu::~Menu() {}

Flare::Menu::MenuButton::MenuButton(int Index, const QString& Text, Menu* Parent) :
	index(Index), PushButton(Text, (QWidget*)Parent) {}
