/*
 * 版权所有 (c) 2023 Zeng Jing Hong. 保留所有权利.
 * 版权所有者：Zeng Jing Hong
 * 起始年份：2023
 * 本软件遵循BSD 2-Clause协议。
 * 对于使用本库所产生的任何直接或间接损失和风险，版权所有者不承担任何责任。
 */
#ifndef FLARE_TEXTBOX_H
#define FLARE_TEXTBOX_H
#include <vector>
#include "Widget.h"

using std::vector;

namespace Flare {
    class FLARE_EXPORT TextBox : public Widget{
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
        int textArrayLength();
        void setStrikethrough(const bool& Expurgate = true);
        void setUnderline(const bool& underLine = true);
        bool Underline() const;
        bool Strikethrough() const;
        ~TextBox() = default;
    protected:
        void paintEvent(QPaintEvent* event) override;
        void setTextArray();
    private:
        i32 verticalGap;
        i32 lineLength;
        bool expurgate;
        bool underline;
        vector<QString> textArray;
        QString boxText;
        QColor boxColor;
    };
}


#endif //FLARE_TEXTBOX_H
