#ifndef WIDGET_H
#define WIDGET_H
#define TIMEOUT 1*1000
#include <QTimer>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_startButton_clicked();
    void timeoutSlot();

    void on_closeButton_clicked();

    void on_singleButton_clicked();

private:
    Ui::Widget *ui;
    QTimer *timer;
    int picid;
};
#endif // WIDGET_H
