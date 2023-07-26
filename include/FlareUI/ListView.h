//
// Created by zjh on 2023/7/23.
//

#ifndef FLARELIST_LISTVIEW_H
#define FLARELIST_LISTVIEW_H

#include "Widget.h"
#include <QList>
#include <QWheelEvent>

namespace Flare {
class FLARE_EXPORT ListView : public Widget {
    Q_OBJECT

    QList<QWidget *> *WidgetList;

    int spacing;

    int marginLeft;

    bool isScrollable;

    int moveSpeed;
protected:
    void showEvent(QShowEvent *event) override;

    void setPosition();

    void wheelEvent(QWheelEvent *event) override;

    void allWidgetMove(const int& n);

public:
    explicit ListView(QWidget *parent = nullptr);

    void append(QWidget *w);

    void remove(const int &i);

    void clear();

    void setSpacing(const int &s);

    void setMarginLeft(const int &m);

    void setScrollable(const bool &s = true);

    void setMoveSpeed(const int &s);

    int Spacing() const;

    int MarginLeft() const;

    bool IsScrollable() const;

    int MoveSpeed() const;
};
}


#endif //FLARELIST_LISTVIEW_H
