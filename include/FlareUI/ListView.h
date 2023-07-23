//
// Created by zjh on 2023/7/23.
//

#ifndef FLARELIST_LISTVIEW_H
#define FLARELIST_LISTVIEW_H

#include <QWidget>
#include <QList>
#include <QWheelEvent>

class ListView : public QWidget {
Q_OBJECT

    QList<QWidget *> *WidgetList;

    int Spacing;

    int MarginLeft;

    bool IsScrollable;

    int MoveSpeed;
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

    int spacing() const;

    int marginLeft() const;

    bool isScrollable() const;

    int moveSpeed() const;
};


#endif //FLARELIST_LISTVIEW_H
