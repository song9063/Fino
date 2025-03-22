#ifndef PARAMSTABLEWIDGET_H
#define PARAMSTABLEWIDGET_H

#include <QWidget>
#include "paramstablemodel.h"

namespace Ui {
class ParamsTableWidget;
}

class ParamsTableWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ParamsTableWidget(QWidget *parent = nullptr);
    ~ParamsTableWidget();

    void setModel(ParamsTableModel *pModel);

private:
    void initUI();

private:
    Ui::ParamsTableWidget *ui;
};

#endif // PARAMSTABLEWIDGET_H
