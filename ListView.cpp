//
// Created by zjh_3 on 2023/7/23.
//

#include "ListView.h"

ListView::ListView(QWidget *parent) :
        QWidget(parent),
        WidgetList(new QList<QWidget *>()),
        Spacing(0), MarginLeft(0), IsScrollable(false) {

}

void ListView::append(QWidget *w) {
    w->setParent(this);
    WidgetList->push_back(w);
    // 如果已经可见那就显示
    if (isVisible()) {
        setPosition();
    }
}

void ListView::remove(const int &i) {
    WidgetList->remove(i);
    if (isVisible()) {
        setPosition();
    }
}

void ListView::clear() {
    WidgetList->clear();
}

void ListView::setSpacing(const int &s) {
    Spacing = s;
}


void ListView::showEvent(QShowEvent *event) {
    QWidget::showEvent(event);
    for (const auto &i: *WidgetList)
        i->show();
    setPosition();
}

void ListView::setMarginLeft(const int &m) {
    MarginLeft = m;
}

void ListView::setPosition() {
    assert(!WidgetList->empty());
    WidgetList->at(0)->move(marginLeft(), 0);
    for (int i = 1; i != WidgetList->size(); ++i) {
        WidgetList->at(i)->move(marginLeft(),
                                WidgetList->at(i - 1)->y() + WidgetList->at(i - 1)->height() + spacing());
    }
}

int ListView::spacing() const {
    return Spacing;
}

int ListView::marginLeft() const {
    return MarginLeft;
}

void ListView::setScrollable(const bool &s) {
    IsScrollable = s;
}

bool ListView::isScrollable() const {
    return IsScrollable;
}

void ListView::wheelEvent(QWheelEvent *event) {
    QWidget::wheelEvent(event);
    if (isScrollable()) {
        allWidgetMove(event->angleDelta().y());
    }
    //! 要记得在使用VS时将这个类继承于Flare::Widget然后加一层isAbove的判断
}

void ListView::setMoveSpeed(const int &s) {
    MoveSpeed = s;
}

int ListView::moveSpeed() const {
    return MoveSpeed;
}

void ListView::allWidgetMove(const int &n) {
    if (WidgetList->empty()) {
        return;
    }
    if (n > 0) { // 向下
        // 如果 如果列表的第一个元素移动后坐标大于等于0就不移动
        if (WidgetList->first()->y() + moveSpeed() < 0) {
            for (const auto &item: *WidgetList)
                item->move(item->x(), item->y() + moveSpeed());
            // 如果移动后的位置大于0但是移动后的位置小于移动的距离便默认为显示不正常重置视图
        } else
            setPosition();
    } else if (n < 0) { // 向上
        // 如果列表的最后一位在移动后他的底部小于高就不移动
        if (WidgetList->back()->y() + WidgetList->back()->height() - moveSpeed() > height()) {
            for (const auto &item: *WidgetList)
                item->move(item->x(), item->y() - moveSpeed());
        }
    } else {
        qDebug()
                << "呕吼，你发现了什么蜜汁错误，请联系该软件的开发者，或者去Github上的FlareUI储存库去提交issue，感谢你对本ui库做出的贡献";
        return;
    }
}

