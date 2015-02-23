#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // to disable when MainWindow initialization
    ui->pushButton_2->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Omage"),".",tr("Image Files(*.png *.jpg *.jpeg *.bmp"));
    // warning:toAscii
    image=cv::imread(fileName.toLatin1().data());
    if(image.data){
        ui->pushButton_2->setEnabled(true);
    }
    cv::namedWindow("Original Image");
    cv::imshow("Original Image",image);
}

void MainWindow::on_pushButton_2_clicked()
{
    cv::flip(image,image,1);
    cv::cvtColor(image,image,CV_BGR2RGB);
    QImage img = QImage((const unsigned char*)(image.data),image.cols,image.rows,QImage::Format_RGB888);;
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->label->resize(ui->label->pixmap()->size());
}
