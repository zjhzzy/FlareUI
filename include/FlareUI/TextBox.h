/*
 * 版权所有 (c) 2023 Zeng Jing Hong. 保留所有权利.
 * 本软件包含FlareUI库的全部代码。
 * 版权所有者：Zeng Jing Hong
 * 起始年份：2023
 *
 * 本软件遵循BSD 2-Clause协议。
 * 详细的协议条款请参见附加文件LICENSE.txt。
 * 除非依照BSD 2-Clause协议的明确规定，否则未经版权所有者明确授权，
 * 在本软件中使用、复制、修改、合并、发布、分发、再授权及贩售等行为是被禁止的。
 *
 * 对于使用本库所产生的任何直接或间接损失和风险，版权所有者不承担任何责任。
 */

#ifndef FLARE_TEXTBOX_H
#define FLARE_TEXTBOX_H
#include <QVector>
#include <QString>
#include "Widget.h"

namespace Flare {
    class TextBox : public Widget{
        Q_OBJECT
    public:
        void setText(const QString &string);
        void setLineLength(const i32 &length);
        void setVerticalGap(const i32 &Gap);
        void setTextColor(const QColor& color);
        QString Text();
        i32 LineLength() const;
        i32 VerticalGap() const;
        QColor TextColor();
        explicit TextBox(QWidget* parent = nullptr);
        explicit TextBox(QString Text, QWidget *parent = nullptr);
        ~TextBox() = default;
    protected:
        void paintEvent(QPaintEvent* event) override;
        void setTextArray();
    private:
        i32 verticalGap;
        i32 lineLength;
        QVector<QString> textArray;
        QString boxText;
        QColor boxColor;
    };
}


#endif //FLARE_TEXTBOX_H
