# FlareUI

This is a UI library based on Qt, which offers modern and visually appealing controls and UI features, fully compatible with Qt's functionality and advantages. 



[Chinese](README.md)

## Project Description

This is a UI library that I suddenly thought of writing a few days ago when I had nothing to do. The FlareUI library is an extension of the Qt library. It is a solution for developers to reduce the use of Qss and avoid reinventing the wheel. It implements some controls based on the MacOS style.

## Features

1. Convenient API<br>For example, when writing programs, you don't have to rewrite controls for some tedious operations, just write a piece of code like this:

   ```cpp
   #include "FlareWindow.h"
   #include "PushButton.h"
   #include <QApplication>
   int main(int argc, char* argv[]) {
   	Q_INIT_RESOURCE(FlareWindow);
   	QApplication a(argc, argv);
   	Flare::FlareWindow MainWindow;
   	Flare::PushButton button("Hello Falre!", &MainWindow);
   	MainWindow.resize(200, 200);
   	button.move(40,90);
   	button.resize(120, 20);
   	MainWindow.show();
   	return a.exec();
   }
   ```

   And you can achieve:

   ![Window Code](assets/MainWindow.png)

2. Based on the Mac style, normally implementing a style requires writing a lot of code, but here I have implemented it, so you can just "new" and enjoy the results.

## Development Environment

Using **Qt6.6.0**, but this is not very important because the code does not use any new features. It is based on QtWidget, and I am not very familiar with QML, so I didn't use it.

## Installation Guide

This will be written later. I've been fixing bugs for half a day and haven't finished yet.

## Usage Examples

I will write the usage examples on my blog, so there's no need to include them here.

## Contribution Guidelines

Welcome to contribute to the project!

- Submit bug reports: Please submit detailed bug reports, including reproducible steps and relevant information, on the issue page.
- Make feature requests: Put forward your new ideas or improvement suggestions for the project on the issue page.
- Submit pull requests: Fork the project, make modifications, and submit them to me through pull requests.

Please respect others, abide by laws and regulations, and follow the code of conduct of this project.

Thank you for your participation and support! If you have any questions, please feel free to contact me.

My work email is [zjh_3456789@outlook.com](mailto:zjh_3456789@outlook.com).

## Copyright Information

This project is licensed under the [BSD 3-Clause License](https://opensource.org/licenses/BSD-3-Clause). This license allows you to use, modify, and distribute the source code of this project freely, as long as you comply with the following three conditions:

- You must retain the original copyright notice and license statement.
- You must indicate the changes you made in any modified files.

If you have any questions about this license, please refer to the [BSD 3-Clause License FAQ](https://www.gnu.org/licenses/license-list.en.html#ModifiedBSD).

## Acknowledgements

If you want to become one of the contributors, please refer to the [Contribution Guidelines](https://bing.vcanbb.top/web/#如何贡献) to learn how to join us.👏

## Current Plans

- [ ] Implement all the Button controls.
- [ ] Complete the title bar fix for FlareWindow.
- [ ] Extend existing controls.

## Related Resources

My blog: [zjhzzy](https://c2.binjie.fun/zjhzzy.github.io)

I will post some progress on this library and some examples on my blog.