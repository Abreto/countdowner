#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDateTime>

#define format_num(n)   ( ( (n) < 10 ) ? QString("0%1").arg(n) : QString("%1").arg(n) )

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void update_time();

private:
    Ui::MainWindow *ui;
    QTimer  *main_timer;
    QDateTime to;
};

#endif // MAINWINDOW_H
