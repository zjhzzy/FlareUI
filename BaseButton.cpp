#include "BaseButton.h"

namespace Flare {
    void BaseButton::enterEvent(QEnterEvent *event) {
        QAbstractButton::enterEvent(event);
        isAbove = true;
        update();
        emit moveAbove();
    }

    void BaseButton::leaveEvent(QEvent *event) {
        QAbstractButton::leaveEvent(event);
        isAbove = false;
        update();
        emit leaveAbove();
    }

    void BaseButton::mousePressEvent(QMouseEvent *event) {
        QAbstractButton::mousePressEvent(event);
        isPress = true;
        update();
    }

    void BaseButton::mouseReleaseEvent(QMouseEvent *event) {
        QAbstractButton::mouseReleaseEvent(event);
        isPress = false;
        update();
    }

    BaseButton::BaseButton(QWidget *parent) :
            QAbstractButton(parent),
            isAbove(false), isPress(false),
            isIcon(false), buttonIcon(new QIcon()),
            buttonHoverIcon(new QIcon()),
            buttonPressedIcon(new QIcon()) {
    }

    BaseButton::~BaseButton() {
        delete buttonHoverIcon;
        delete buttonIcon;
        delete buttonPressedIcon;
    }


    bool BaseButton::IsPress() const {
        return isPress;
    }

    bool BaseButton::IsAbove() const {
        return isAbove;
    }

    void Flare::BaseButton::setAllIcon(const QIcon &icon) {
        isIcon = true;
        *buttonHoverIcon = icon;
        *buttonIcon = icon;
        *buttonPressedIcon = icon;
    }

    Flare::BaseButton::Icon Flare::BaseButton::Icon::setAllIcon(const QIcon &icon) {
        buttonIcon = icon;
        buttonHoverIcon = icon;
        buttonPressedIcon = icon;
        return *this;
    }

    void Flare::BaseButton::setIcon(const Icon &icon) {
        isIcon = true;
        *buttonIcon = icon.buttonIcon;
        *buttonHoverIcon = icon.buttonHoverIcon;
        *buttonPressedIcon = icon.buttonPressedIcon;
    }

    bool Flare::BaseButton::isSetIcon() const {
        return isIcon;
    }

    QIcon BaseButton::ButtonIcon() {
        return *buttonIcon;
    }

    QIcon BaseButton::ButtonHoverIcon() {
        return *buttonHoverIcon;
    }

    QIcon BaseButton::ButtonPressedIcon() {
        return *buttonPressedIcon;
    }

}