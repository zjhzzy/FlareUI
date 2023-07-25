#ifndef FLARE_SYSTEMICON_H
#define FLARE_SYSTEMICON_H

#include <QSystemTrayIcon>
#include <QGuiApplication>
#include <QScreen>
#include "flare_global.h"
#include "Menu.h"

namespace Flare {

    class FLARE_EXPORT SystemIcon : public QSystemTrayIcon {
    Q_OBJECT

        SystemIcon(Menu *appMenu, const QIcon &icon, QObject *parent);

    private:
        Menu *iconMenu;

    protected:

        void connectSlots();

        void showMenu();

    public:
        explicit SystemIcon(QObject *parent = nullptr);

        explicit SystemIcon(const QIcon &icon, QObject *parent = nullptr);

        SystemIcon(QMenu *appMenu, const QIcon &icon, QObject *parent = nullptr);

        ~SystemIcon();

        void setTriggerMenu(ActivationReason trigger);

        void setMenu(Menu *menu);

    signals:

        void Unknown();

        void Context();

        void Trigger();

        void MiddleClick();

        void DoubleClick();

        void hovered();
    };

} // namespace Flare

#endif