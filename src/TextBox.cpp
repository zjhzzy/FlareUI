//
// Created by zjh_3 on 2023/7/27.
//

#include "TextBox.h"

void Flare::TextBox::setText(const QString &string) {
    boxText = string;
    setTextArray();
}

QString Flare::TextBox::Text() {
    return boxText;
}

void Flare::TextBox::paintEvent(QPaintEvent *event) {
    Widget::paintEvent(event);
    QPainter painter(this);
    painter.setFont(font());
    QFontMetrics fontMetrics = painter.fontMetrics();

    painter.setPen(boxColor);
    painter.setBrush(boxColor);

    if (LineLength() == 0) {
        i32 x = (width() / 2) - (fontMetrics.horizontalAdvance(Text()) / 2);
        i32 y = (height() / 2) - (fontMetrics.height() / 2);

        painter.drawText(x, y, Text());
        painter.end();
        return;
    } else {
        i32 x = (width() / 2) - (fontMetrics.horizontalAdvance(textArray.front()) / 2);
        i32 y = (height() / 2) -
                ((fontMetrics.height() * textArray.size() + textArray.size() * verticalGap - verticalGap) / 2);
        painter.drawText(x, y, textArray.front());

        for (int i = 1; i != textArray.size(); i++) {
            y += fontMetrics.height() + verticalGap;
            painter.drawText(x, y, textArray.at(i));
        }

        painter.end();
        return;
    }
}

void Flare::TextBox::setLineLength(const i32 &length) {
    lineLength = length;
    setTextArray();
}

Flare::TextBox::TextBox(QWidget *parent) :
        Widget(parent),
        boxText(QString()),
        lineLength(0),
        textArray(vector<QString>()),
        verticalGap(1),
        expurgate(false) {
    setTextArray();
    qDebug() << "调用TextBox构造函数";
}

Flare::TextBox::TextBox(QString Text, QWidget *parent) :
        Widget(parent),
        boxText(std::move(Text)),
        textArray(vector<QString>()),
        lineLength(0),
        verticalGap(1),
        expurgate(false) {
    setTextArray();
    qDebug() << "调用TextBox构造函数";
}

i32 Flare::TextBox::LineLength() const {
    return lineLength;
}

void Flare::TextBox::setVerticalGap(const i32 &Gap) {
    verticalGap = Gap;
}

i32 Flare::TextBox::VerticalGap() const {
    return verticalGap;
}

void Flare::TextBox::setTextColor(const QColor &color) {
    boxColor = color;
}

QColor Flare::TextBox::TextColor() {
    return boxColor;
}


void Flare::TextBox::setTextArray() {
    textArray = vector<QString>();
    textArray.emplace_back(QString());
    // 蜜汁命名但是我不想改反正代码不会出错
    int i = 0;
    int j = 0;
    for (const auto &item: boxText) {
        if (i == lineLength) {
            textArray.emplace_back(QString());
            j++;
            i = 0;
        }
        textArray.at(j).append(item);
        i++;
    }
    qDebug() << "已经调用一次";
    for (const auto &item: textArray)
        qDebug() << item;
}

int Flare::TextBox::textArrayLength() {
    return textArray.size();
}

void Flare::TextBox::setStrikethrough(const bool &Expurgate) {
    QFont Font(font());
    Font.setStrikeOut(Expurgate);
    setFont(Font);
    expurgate = Expurgate;
}

bool Flare::TextBox::Strikethrough() const {
    return expurgate;
}

bool Flare::TextBox::Underline() const {
    return underline;
}

void Flare::TextBox::setUnderline(const bool &underLine) {
    QFont Font(font());
    Font.setUnderline(underLine);
    setFont(Font);
    underline = underLine;
}
