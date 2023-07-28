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
            isIcon(false), buttonIcon(new Icon()) {
    }

    BaseButton::~BaseButton() {
        delete buttonIcon;
    }


    bool BaseButton::IsPress() const {
        return isPress;
    }

    bool BaseButton::IsAbove() const {
        return isAbove;
    }

    void Flare::BaseButton::setAllIcon(const QIcon &icon) {
        isIcon = true;
        buttonIcon->buttonHoverIcon = icon;
        buttonIcon->buttonIcon = icon;
        buttonIcon->buttonPressedIcon = icon;
    }

    Flare::BaseButton::Icon Flare::BaseButton::Icon::setAllIcon(const QIcon &icon) {
        buttonIcon = icon;
        buttonHoverIcon = icon;
        buttonPressedIcon = icon;
        return *this;
    }

    void Flare::BaseButton::setIcon(Icon *icon) {
        isIcon = true;
        delete buttonIcon;
        buttonIcon = icon;
    }

    bool Flare::BaseButton::IsIcon() const {
        return isIcon;
    }

    QIcon BaseButton::ButtonIcon() {
        return buttonIcon->buttonIcon;
    }

    QIcon BaseButton::ButtonHoverIcon() {
        return buttonIcon->buttonHoverIcon;
    }

    QIcon BaseButton::ButtonPressedIcon() {
        return buttonIcon->buttonPressedIcon;
    }
    BaseButton::Icon::Icon() {
        qDebug()<< "BaseButton Icon 初始化";
        buttonIcon = QIcon();
        buttonHoverIcon = QIcon();
        buttonPressedIcon = QIcon();
    }
    BaseButton::BaseButton(const Flare::BaseButton &button) {
        isPress = false;
        isAbove = false;
        isIcon = button.isIcon;
        buttonIcon = button.buttonIcon;
    }
}