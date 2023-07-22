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

void Flare::SystemIcon::showMenu() {
	if (QCursor::pos().x() + iconMenu->width() < QGuiApplication::primaryScreen()->geometry().width()) {
		iconMenu->show();
		iconMenu->move(QCursor::pos().x(), QCursor::pos().y() + iconMenu->height());
	} else {
		iconMenu->show();
		iconMenu->move(QCursor::pos().x() - iconMenu->width(), QCursor::pos().y() + iconMenu->height());
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

SystemIcon::SystemIcon(QObject* parent)
	: QSystemTrayIcon(parent), iconMenu(nullptr) {}

SystemIcon::SystemIcon(const QIcon& icon, QObject* parent)
	: QSystemTrayIcon(icon, parent), iconMenu(nullptr) {}

SystemIcon::SystemIcon(Menu* appMenu, const QIcon& icon, QObject* parent)
	: QSystemTrayIcon(icon, parent), iconMenu(appMenu) {}

SystemIcon::~SystemIcon() {}


void SystemIcon::show() {
	QSystemTrayIcon::show();
}

void SystemIcon::hide() {
	QSystemTrayIcon::hide();
}

void Flare::SystemIcon::setIcon(const QIcon& icon) {
	QSystemTrayIcon::setIcon(icon);
}

void Flare::SystemIcon::setToolTip(const QString& tip) {
	QSystemTrayIcon::setToolTip(tip);
}

void Flare::SystemIcon::setContextMenu(Menu* menu) {
	this->iconMenu = menu;
}

void Flare::SystemIcon::showMessage(const QString& title, const QString& message, QSystemTrayIcon::MessageIcon icon, int msecs) {
	QSystemTrayIcon::showMessage(title, message, icon, msecs);
}

void Flare::SystemIcon::showMessage(const QString& title, const QString& message, const QIcon& icon, int msecs) {
	QSystemTrayIcon::showMessage(title, message, icon, msecs);
}
