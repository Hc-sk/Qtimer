#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("请选择你的英雄");
    timer = new QTimer;
    picid = 2;
    QImage img;
    img.load("D:\\qtfiles\\Qtimer\\pic1.jpg");
    ui->label->setPixmap(QPixmap::fromImage(img));

    connect(timer,&QTimer::timeout,this,&Widget::timeoutSlot);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_startButton_clicked()
{
    timer->start(TIMEOUT);
}

void Widget::timeoutSlot(){
    QString path("D:\\qtfiles\\Qtimer\\pic");
    path+=QString::number(picid);
    path+=(".jpg");

    QImage img;
    img.load(path);
    ui->label->setPixmap(QPixmap::fromImage(img));

    picid++;
    if(5==picid)
        picid=1;
}
void Widget::on_closeButton_clicked()
{
    timer->stop();
}


void Widget::on_singleButton_clicked()
{
    QTimer::singleShot(1,this,SLOT(timeoutSlot()));
}

