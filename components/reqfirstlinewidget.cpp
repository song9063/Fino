#include "reqfirstlinewidget.h"
#include "ui_reqfirstlinewidget.h"

ReqFirstLineWidget::ReqFirstLineWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ReqFirstLineWidget){
    ui->setupUi(this);

    m_arMethods = {
        "GET", "POST", "PUT", "PATCH", "DELETE",
        "HEAD", "OPTIONS",
        "CONNECT", "TRACE"
    };

    ui->cbMethods->addItems(m_arMethods);
    ui->cbMethods->insertSeparator(2);
    ui->cbMethods->insertSeparator(6);
}

ReqFirstLineWidget::~ReqFirstLineWidget(){
    delete ui;
}
