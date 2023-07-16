#include "FlareWindow.h"

Flare::FlareWindow::FlareWindow(QWidget* parent)
	: QWidget(parent),
	CloseButton(new IconButton()),
	HideButton(new IconButton()),
	EnlargeButton(new IconButton()) {
	
}

Flare::FlareWindow::~FlareWindow() {}

void Flare::FlareWindow::connectSlot() {
	connect(CloseButton, &IconButton::clicked, this, &FlareWindow::close);
	connect(HideButton, &IconButton::clicked, this, &FlareWindow::hide);
	// TODO: 等下要写关于按钮是最大化,还是缩小化的逻辑了
}
