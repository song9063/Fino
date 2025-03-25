#ifndef REQFIRSTLINEWIDGET_H
#define REQFIRSTLINEWIDGET_H

#include <QWidget>

namespace Ui {
class ReqFirstLineWidget;
}

class ReqFirstLineWidget : public QWidget{
    Q_OBJECT

public:
    explicit ReqFirstLineWidget(QWidget *parent = nullptr);
    ~ReqFirstLineWidget();

    QStringList m_arMethods;

private:
    Ui::ReqFirstLineWidget *ui;
};

#endif // REQFIRSTLINEWIDGET_H
