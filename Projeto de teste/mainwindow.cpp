#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QImage img;
    img.load("F:/Unp/8ªSemestre/Visão Computacional/Nova pasta/Flor.bmp","BMP");
    ImageProcessing::RGBImage<int> rgbimg = ImageProcessing::QImage2RGBImage<int>(img);
    ImageProcessing::GrayImage<int> grayimg = ImageProcessing::QImage2GrayImage<int>(img);

    ui->label->setPixmap(QPixmap::fromImage(ImageProcessing::RGBImage2QImage<int>(rgbimg)));
    ui->label_2->setPixmap(QPixmap::fromImage(ImageProcessing::GrayImage2QImage<int>(grayimg)));

    std::cout << ImageProcessing::GetPixel<int>(50,10,100) << std::endl;
    std::cout << ImageProcessing::Histogram<int>(grayimg.getGray()) << std::endl;

}

MainWindow::~MainWindow()
{
    delete ui;
}
