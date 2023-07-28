/*
 * 版权所有 (c) 2023 Zeng Jing Hong. 保留所有权利.
 * 版权所有者：Zeng Jing Hong
 * 起始年份：2023
 * 本软件遵循BSD 2-Clause协议。
 * 对于使用本库所产生的任何直接或间接损失和风险，版权所有者不承担任何责任。
 */

#ifndef FLARE_MENU_H
#define FLARE_MENU_H

#include "flare_global.h"
#include "PushButton.h"
#include "Widget.h"
#include <QVector>
// Todo: 这个垃圾谁爱用谁用，我是不想修Bug了
namespace Flare {

    class FLARE_EXPORT MenuButton : public QObject {
    Q_OBJECT

        PushButton *button;
        int index;
    public:
        MenuButton(PushButton *menuButton, const int &index);

        int Index() const;

        PushButton& Button();

    signals:

        void clicked(int index);
    };

    class FLARE_EXPORT Menu : public Widget {
    Q_OBJECT

    private:
        QVector<MenuButton *> buttonVector;
    protected:
        void showEvent(QShowEvent*) override;
    public:
        void addButton(PushButton *button);

        Menu();
        ~Menu();

    signals:

        void clickedIndex(int index);

    };
}

#endif //FLARE_MENU_H
