//
// Created by zjh_3 on 2023/7/23.
//

#include "ListView.h"


Flare::ListView::ListView(QWidget *parent) :
        Widget(parent),
        WidgetList(new QList<QWidget *>()),
        spacing(0), marginLeft(0), isScrollable(false),moveSpeed(20),topMargin(0) {

}

void Flare::ListView::append(QWidget *w) {
    w->setParent(this);
    WidgetList->push_back(w);
    // 如果已经可见那就显示
    if (isVisible()) {
        setPosition();
    }
}

void Flare::ListView::remove(const int &i) {
    WidgetList->remove(i);
    if (isVisible()) {
        setPosition();
    }
}

void Flare::ListView::clear() {
    WidgetList->clear();
}

void Flare::ListView::setSpacing(const int &s) {
    spacing = s;
}


void Flare::ListView::showEvent(QShowEvent *event) {
    QWidget::showEvent(event);
    for (const auto &i: *WidgetList)
        i->show();
    setPosition();
}

void Flare::ListView::setMarginLeft(const int &m) {
    marginLeft = m;
}

void Flare::ListView::setPosition() {
    if(WidgetList->empty())
        return;
    WidgetList->at(0)->move(MarginLeft(), TopMargin());
    for (int i = 1; i != WidgetList->size(); ++i) {
        WidgetList->at(i)->move(MarginLeft(),
                                WidgetList->at(i - 1)->y() + WidgetList->at(i - 1)->height() + Spacing());
    }
}

int Flare::ListView::Spacing() const {
    return spacing;
}

int Flare::ListView::MarginLeft() const {
    return marginLeft;
}

void Flare::ListView::setScrollable(const bool &s) {
    isScrollable = s;
}

bool Flare::ListView::IsScrollable() const {
    return isScrollable;
}

void Flare::ListView::wheelEvent(QWheelEvent *event) {
    QWidget::wheelEvent(event);
    if (IsScrollable()) {
        allWidgetMove(event->angleDelta().y());
    }
    //! 要记得在使用VS时将这个类继承于Flare::Widget然后加一层isAbove的判断
}

void Flare::ListView::setMoveSpeed(const int &s) {
    moveSpeed = s;
}

int Flare::ListView::MoveSpeed() const {
    return moveSpeed;
}

void Flare::ListView::allWidgetMove(const int &n) {
    if (WidgetList->empty()) {
        return;
    }
    if (n > 0) { // 向下
        // 如果 如果列表的第一个元素移动后坐标大于等于0就不移动
        if (WidgetList->first()->y() + MoveSpeed() < TopMargin()) {
            for (const auto &item: *WidgetList)
                item->move(item->x(), item->y() + MoveSpeed());
            // 如果移动后的位置大于0但是移动后的位置小于移动的距离便默认为显示不正常重置视图
        } else
            setPosition();
    } else if (n < 0) { // 向上
        // 如果列表的最后一位在移动后他的底部小于高就不移动
        if (WidgetList->back()->y() + WidgetList->back()->height() - MoveSpeed() > height()) {
            for (const auto &item: *WidgetList)
                item->move(item->x(), item->y() - MoveSpeed());
        }
    } else {
        qDebug()
                << "呕吼，你发现了什么蜜汁错误，请联系该软件的开发者，或者去Github上的FlareUI储存库去提交issue，感谢你对本ui库做出的贡献";
        return;
    }
}
void Flare::ListView::setTopMargin(const int &i) {
    topMargin = i;
}

int Flare::ListView::TopMargin() const {
    return topMargin;
}