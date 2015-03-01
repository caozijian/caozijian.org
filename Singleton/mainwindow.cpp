#include "mainwindow.h"
#include "main.h"
#include "ui_mainwindow.h"



ColorDetectController *ColorDetectController::singleton=0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Open Image"),".",tr("Image files(*.png *.jpg *.jped *.bmp)"));
    ColorDetectController::getInstance()->setInputImage(filename.toLatin1().data());
    cv::namedWindow("Input Image");
    cv::imshow("Input Image",ColorDetectController::getInstance()->getInputImage());
}

void MainWindow::on_pushButton_2_clicked()
{
    ColorDetectController::getInstance()->setTargetColor(130,190,230);
    ColorDetectController::getInstance()->process();
    cv::namedWindow("Output Image");
    cv::imshow("Output Image",ColorDetectController::getInstance()->getLastResult());

}
