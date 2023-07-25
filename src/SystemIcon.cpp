#include "SystemIcon.h"

using namespace Flare;

void Flare::SystemIcon::connectSlots() {
    connect(this, &QSystemTrayIcon::activated, this, [this]
            (QSystemTrayIcon::ActivationReason reason) {
        switch (reason) {
            case QSystemTrayIcon::Unknown:
                emit Unknown();
                break;
            case QSystemTrayIcon::Context:
                emit Context();
                break;
            case QSystemTrayIcon::DoubleClick:
                emit DoubleClick();
                break;
            case QSystemTrayIcon::Trigger:
                emit Trigger();
                break;
            case QSystemTrayIcon::MiddleClick:
                emit MiddleClick();
                break;
            default:
                QSystemTrayIcon::showMessage("FlareUI Error",
                                             "你碰到了莫名奇妙的Bug请你告知FlareUI库的开发者或者你使用的软件的开发者",
                                             QSystemTrayIcon::Warning);
                break;
        }
    });
}

void SystemIcon::showMenu() {
    if (iconMenu) {
        // Get the screen geometry
        QScreen *screen = QGuiApplication::primaryScreen();
        QRect screenGeometry = screen->availableGeometry();

        // Get the menu size
        QSize menuSize = iconMenu->sizeHint();

        // Calculate the menu position
        int x = QCursor::pos().x() - menuSize.width() / 2;
        int y = QCursor::pos().y() + 10;

        // Adjust the menu position to ensure it stays within the screen boundaries
        if (x < screenGeometry.left())
            x = screenGeometry.left();
        else if (x + menuSize.width() > screenGeometry.right())
            x = screenGeometry.right() - menuSize.width();
        if (y < screenGeometry.top())
            y = screenGeometry.top();
        else if (y + menuSize.height() > screenGeometry.bottom())
            y = screenGeometry.bottom() - menuSize.height();

        // Show the menu at the adjusted position
        iconMenu->move(QPoint(x, y));
    }
}


void Flare::SystemIcon::setTriggerMenu(QSystemTrayIcon::ActivationReason trigger) {
    switch (trigger) {
        case QSystemTrayIcon::Unknown:
            connect(this, &SystemIcon::Unknown, this, [this]() {
                showMenu();
            });
            break;
        case QSystemTrayIcon::Context:
            connect(this, &SystemIcon::Context, this, [this]() {
                showMenu();
            });
            break;
        case QSystemTrayIcon::DoubleClick:
            connect(this, &SystemIcon::DoubleClick, this, [this]() {
                showMenu();
            });
            break;
        case QSystemTrayIcon::Trigger:
            connect(this, &SystemIcon::Trigger, this, [this]() {
                showMenu();
            });
            break;
        case QSystemTrayIcon::MiddleClick:
            connect(this, &SystemIcon::MiddleClick, this, [this]() {
                showMenu();
            });
            break;
        default:
            QSystemTrayIcon::showMessage("FlareUI Erro",
                                         "你碰到了莫名奇妙的Bug请你告知FlareUI库的开发者或者你使用的软件的开发者",
                                         QSystemTrayIcon::Warning);
            break;
    }
}

SystemIcon::SystemIcon(QObject *parent)
        : QSystemTrayIcon(parent), iconMenu(nullptr) {}

SystemIcon::SystemIcon(const QIcon &icon, QObject *parent)
        : QSystemTrayIcon(icon, parent), iconMenu(nullptr) {}

SystemIcon::SystemIcon(Menu *appMenu, const QIcon &icon, QObject *parent)
        : QSystemTrayIcon(icon, parent), iconMenu(appMenu) {}

SystemIcon::~SystemIcon() {}

void Flare::SystemIcon::setMenu(Flare::Menu *menu) {
    iconMenu = menu;
}

