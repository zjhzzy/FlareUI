/*
 * 版权所有 (c) 2023 Zeng Jing Hong. 保留所有权利.
 * 版权所有者：Zeng Jing Hong
 * 起始年份：2023
 * 本软件遵循BSD 2-Clause协议。
 * 对于使用本库所产生的任何直接或间接损失和风险，版权所有者不承担任何责任。
 */

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

    int topMargin;
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
    void setTopMargin(const int &i);
    int TopMargin() const;
};
}


#endif //FLARELIST_LISTVIEW_H
