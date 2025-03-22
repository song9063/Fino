#ifndef REQFORMWIDGET_H
#define REQFORMWIDGET_H

#include <QWidget>
#include <QKeyEvent>


#include "components/tables/paramstablewidget.h"
namespace Ui {
class ReqFormWidget;
}

class ReqFormWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ReqFormWidget(QWidget *parent = nullptr);
    ~ReqFormWidget();

protected:
    void keyReleaseEvent(QKeyEvent *event);

private:
    void initReqWidgets();
    void initRespWidgets();

    ParamsTableModel *pQueryParamsModel;
private:
    Ui::ReqFormWidget *ui;
};

#endif // REQFORMWIDGET_H
