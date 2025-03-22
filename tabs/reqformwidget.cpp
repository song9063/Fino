#include "reqformwidget.h"
#include "ui_reqformwidget.h"


ReqFormWidget::ReqFormWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ReqFormWidget)
{
    ui->setupUi(this);
    this->setFocusPolicy(Qt::ClickFocus);

    initReqWidgets();
    initRespWidgets();
}

ReqFormWidget::~ReqFormWidget()
{
    delete ui;
}

void ReqFormWidget::keyReleaseEvent(QKeyEvent *event)
{
    if(event->modifiers() & Qt::ControlModifier){
        if(event->key() == Qt::Key_Return)
        qDebug() << "RUN";
    }

    QWidget::keyReleaseEvent(event);
}

void ReqFormWidget::initReqWidgets()
{
    ui->tabWidgetReq->clear();

    // testing
    pQueryParamsModel = new ParamsTableModel(this);
    ParamsTableWidget *pParamsTable= new ParamsTableWidget(this);
    pParamsTable->setModel(pQueryParamsModel);

    ui->tabWidgetReq->addTab(pParamsTable, tr("Params"));


}

void ReqFormWidget::initRespWidgets()
{
    ui->tabWidgetResp->clear();
}

