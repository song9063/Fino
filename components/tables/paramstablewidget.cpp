#include "paramstablewidget.h"
#include "ui_paramstablewidget.h"

const int PT_WIDTH_COL_0 = 40;
const int PT_WIDTH_COL_1 = 80;
const int PT_WIDTH_COL_2 = 80;
const int PT_WIDTH_COL_3 = 80;

ParamsTableWidget::ParamsTableWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ParamsTableWidget){
    ui->setupUi(this);
}

ParamsTableWidget::~ParamsTableWidget(){
    delete ui;
}

void ParamsTableWidget::setModel(ParamsTableModel *pModel){
    this->ui->tableView->setModel(pModel);

    initUI();
}

void ParamsTableWidget::initUI(){
    ui->tableView->horizontalHeader()->show();

    /*pTable->setColumnWidth(0, PT_WIDTH_COL_0);
    pTable->setColumnWidth(1, PT_WIDTH_COL_1);
    pTable->setColumnWidth(2, PT_WIDTH_COL_2);
    pTable->setColumnWidth(3, PT_WIDTH_COL_3);*/

    ui->tableView->resizeColumnsToContents();

}

void ParamsTableWidget::on_btAddParam_clicked()
{
    qDebug() << "ADd";

    ParamsTableModel *pModel = (ParamsTableModel *)ui->tableView->model();
    pModel->addParam(QJsonObject());
}

