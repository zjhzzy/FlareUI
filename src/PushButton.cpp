#include "PushButton.h"

void Flare::PushButton::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setFont(font());
    QFontMetrics metrics(font());

    if (!IsAbove()) {
        painter.setPen(buttonColor->buttonBackPenColor);
        painter.setBrush(buttonColor->buttonBackBrushColor);
    } else {
        if (IsPress()) {
            painter.setPen(buttonColor->buttonBackPenPressedColor);
            painter.setBrush(buttonColor->buttonBackBrushPressedColor);
        } else {
            painter.setPen(buttonColor->buttonBackPenHoverColor);
            painter.setBrush(buttonColor->buttonBackPenHoverColor);
        }
    }

    painter.drawRoundedRect(1, 1, width() - 2, height() - 2, XRadius(), YRadius(),Qt::RelativeSize);

    f32 X = 0.f;
    f32 Y = 0.f;
    if (IsIcon()) {
        X = (width() - (iconSize().width() + metrics.horizontalAdvance(text()))) / 2.f;
        Y = (height() - iconSize().height()) / 2.f;
        if (!IsAbove()) {
            painter.drawPixmap(X, Y, ButtonIcon().pixmap(iconSize()));
            painter.setPen(buttonColor->buttonTextColor);
            painter.setBrush(buttonColor->buttonTextColor);
        } else {
            if (IsPress()) {
                painter.drawPixmap(X, Y, ButtonPressedIcon().pixmap(iconSize()));
                painter.setPen(buttonColor->buttonTextPressedColor);
                painter.setBrush(buttonColor->buttonTextPressedColor);
            } else {
                painter.drawPixmap(X, Y, ButtonHoverIcon().pixmap(iconSize()));
                painter.setPen(buttonColor->buttonTextHoverColor);
                painter.setBrush(buttonColor->buttonTextHoverColor);
            }
        }
        X = X + iconSize().width();
        Y = (height() + metrics.ascent() - metrics.descent()) / 2.f;
    } else {
        if (!IsAbove()) {
            painter.setPen(buttonColor->buttonTextColor);
            painter.setBrush(buttonColor->buttonTextColor);
        } else {
            if (IsPress()) {
                painter.setPen(buttonColor->buttonTextPressedColor);
                painter.setBrush(buttonColor->buttonTextPressedColor);
            } else {
                painter.setPen(buttonColor->buttonTextHoverColor);
                painter.setBrush(buttonColor->buttonTextHoverColor);
            }
        }
        X = (width() - metrics.horizontalAdvance(text())) / 2.f;
        Y = (height() + metrics.ascent() - metrics.descent()) / 2.f;
    }

    painter.drawText(X, Y, text());

    painter.end();
}


Flare::PushButton::PushButton(QWidget *parent) :
        BaseButton(parent),
        xRadius(0), yRadius(0),
        buttonColor(new Color()){

}

Flare::PushButton::PushButton(const QString &Text, QWidget *parent) : PushButton(parent) {
    setText(Text);
}

Flare::PushButton::PushButton(Icon *icon, const QString &Text, QWidget *parent) : PushButton(Text, parent) {
    setIcon(icon);
}
Flare::PushButton::~PushButton() {
}

void Flare::PushButton::setButtonPenColor(const QColor &color) {
    buttonColor->buttonBackPenColor = color;
}

void Flare::PushButton::setButtonPenHoverColor(const QColor &color) {
    buttonColor->buttonBackPenHoverColor = color;
}

void Flare::PushButton::setButtonPenPressedColor(const QColor &color) {
    buttonColor->buttonBackPenPressedColor = color;
}

void Flare::PushButton::setButtonBrushColor(const QColor &color) {
    buttonColor->buttonBackBrushColor = color;
}

void Flare::PushButton::setButtonBrushHoverColor(const QColor &color) {
    buttonColor->buttonBackBrushHoverColor = color;
}

void Flare::PushButton::setButtonBrushPressedColor(const QColor &color) {
    buttonColor->buttonBackBrushPressedColor = color;
}

void Flare::PushButton::setButtonTextColor(const QColor &color) {
    buttonColor->buttonTextColor = color;
}

void Flare::PushButton::setButtonTextHoverColor(const QColor &color) {
    buttonColor->buttonTextHoverColor = color;
}

void Flare::PushButton::setButtonTextPressedColor(const QColor &color) {
    buttonColor->buttonTextPressedColor = color;
}


void Flare::PushButton::setColor(Color *color){
    delete buttonColor;
    buttonColor = color;
    qDebug() << "setColor方法调用成功";
}

Flare::PushButton::Color Flare::PushButton::Color::setAllBackColor(const QColor &color) {
    qDebug() << "调用setAllBackColor方法";
    setAllPenColor(color);
    setAllBrushColor(color);
    return *this;
}

Flare::PushButton::Color Flare::PushButton::Color::setAllPenColor(const QColor &color) {
    qDebug() <<"调用setAllPenColor方法";
    buttonBackPenColor = color;
    buttonBackPenHoverColor = color;
    buttonBackPenPressedColor = color;
    return *this;
}

Flare::PushButton::Color Flare::PushButton::Color::setAllBrushColor(const QColor &color) {
    qDebug() << "调用setAllBrushColor方法";
    buttonBackBrushColor = color;
    buttonBackBrushHoverColor = color;
    buttonBackBrushPressedColor = color;
    return *this;
}

Flare::PushButton::Color Flare::PushButton::Color::setAllTextColor(const QColor &color) {
    qDebug() << "调用setAllTextColor方法";
    buttonTextColor = color;
    buttonTextHoverColor = color;
    buttonTextPressedColor = color;
    return *this;
}

void Flare::PushButton::setXRadius(const f32 &Radius) {
    xRadius = Radius;
}

void Flare::PushButton::setYRadius(const f32 &Radius) {
    yRadius = Radius;
}

void Flare::PushButton::setRadius(const f32 &x, const f32 &y) {
    setXRadius(x);
    setYRadius(y);
}

f32 Flare::PushButton::XRadius() {
    return xRadius;
}

f32 Flare::PushButton::YRadius() {
    return yRadius;
}

Flare::PushButton::Color::Color(){
    qDebug() << "初始化Color类";
    buttonTextColor = QColor();
    buttonTextHoverColor = QColor();
    buttonTextPressedColor = QColor();
    buttonBackBrushColor = QColor();
    buttonBackBrushHoverColor = QColor();
    buttonBackBrushPressedColor = QColor();
    buttonBackPenColor = QColor();
    buttonBackPenHoverColor = QColor();
    buttonBackPenPressedColor = QColor();
};