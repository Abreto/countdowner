#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QDateTime>

#define format_num(n)   ( ( (n) < 10 ) ? QString("0%1").arg(n) : QString("%1").arg(n) )

namespace Ui {
    class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

public slots:
    void update_time();

protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::MainWidget *ui;
    QTimer  *main_timer;
    QDateTime to;
};

#endif // MAINWIDGET_H
