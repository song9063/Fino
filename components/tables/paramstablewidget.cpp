#include "paramstablewidget.h"
#include "ui_paramstablewidget.h"

ParamsTableWidget::ParamsTableWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ParamsTableWidget)
{
    ui->setupUi(this);

    initUI();
}

ParamsTableWidget::~ParamsTableWidget()
{
    delete ui;
}

void ParamsTableWidget::setModel(ParamsTableModel *pModel)
{
    this->ui->tableView->setModel(pModel);
}

void ParamsTableWidget::initUI()
{
    this->ui->tableView->horizontalHeader()->show();
}
