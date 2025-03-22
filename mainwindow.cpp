#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "values/consts.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initUI()
{
    ui->splitterMain->setStretchFactor(0, 1);
    ui->splitterMain->setStretchFactor(1, 2);
}
