#include "reqformwidget.h"
#include "ui_reqformwidget.h"

ReqFormWidget::ReqFormWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ReqFormWidget)
{
    ui->setupUi(this);
    this->setFocusPolicy(Qt::ClickFocus);
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

