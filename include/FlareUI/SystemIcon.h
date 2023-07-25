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

    private:
        Widget *iconMenu;

    protected:

        void connectSlots();

        void showMenu();

    public:
        explicit SystemIcon(QObject *parent = nullptr);

        explicit SystemIcon(const QIcon &icon, QObject *parent = nullptr);

        SystemIcon(Widget *appMenu, const QIcon &icon, QObject *parent = nullptr);

        ~SystemIcon();

        void setTriggerMenu(ActivationReason trigger);

        void setMenu(Widget *menu);

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