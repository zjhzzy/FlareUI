//
// Created by zjh_3 on 2023/7/25.
//

#ifndef FLARE_MENU_H
#define FLARE_MENU_H

#include "flare_global.h"
#include "PushButton.h"
#include "Widget.h"
#include <QVector>
//Todo: Menu的bug修完了，接下来任务就是ImageBox了
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
