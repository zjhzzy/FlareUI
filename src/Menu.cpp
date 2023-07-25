//
// Created by zjh_3 on 2023/7/25.
//
#include "Menu.h"


Flare::MenuButton::MenuButton(Flare::PushButton *menuButton, const int &index) :
        button(menuButton), index(index), QObject() {
    connect(button, &PushButton::clicked, this, [this, &index]() {
        emit clicked(index);
    });
}

int Flare::MenuButton::Index() const {
    return index;
}

Flare::PushButton &Flare::MenuButton::Button() {
    return *button;
}

Flare::Menu::Menu() : buttonVector(QVector<MenuButton *>()) {

}

void Flare::Menu::addButton(Flare::PushButton *button) {
    button->setParent(this);
    buttonVector.push_back(new MenuButton(button, buttonVector.size()));
    int widthTemp = 0;
    int heightTemp = 0;
    widthTemp = buttonVector.first()->Button().width();
    for (const auto &item: buttonVector) {
        heightTemp += item->Button().height();
    }
    setFixedSize(widthTemp, heightTemp);
}

void Flare::Menu::showEvent(QShowEvent *) {
    if (buttonVector.empty())
        return;
    buttonVector.first()->Button().move(0, 0);
    for (int i = 1; i != buttonVector.size(); i++) {
        buttonVector.at(i)->Button().move(0, buttonVector.at(i - 1)->Button().y() +
                                             buttonVector.at(i - 1)->Button().height());
    }
}

