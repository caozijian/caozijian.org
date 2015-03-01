#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include "main.h"


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
ColorDetectController colordetect;

void MainWindow::on_pushButton_clicked()
{
    QString fileName =QFileDialog::getOpenFileName(this,tr("Open Image"),".",tr("Image Files(*.png *.jpg *.jpeg *.bmp)"));
    colordetect.setInputImage(fileName.toLatin1().data());
    cv::namedWindow("Input Image");
    cv::imshow("Input Image",colordetect.getInputImage());
}

void MainWindow::on_pushButton_2_clicked()
{
    colordetect.setTargetColor(130,190,230);
    colordetect.process();
    cv::namedWindow("Output Image");
    cv::imshow("Output Image",colordetect.getLastResult());
}
