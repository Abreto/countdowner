#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget),
    to(QDate(2012, 4, 10), QTime(9,0))
{
    ui->setupUi(this);
    setWindowFlags( windowFlags() | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint );
    //setAttribute(Qt::WA_TranslucentBackground, true);
    move(100,50);

    main_timer = new QTimer(this);
    connect(main_timer, SIGNAL(timeout()), this, SLOT(update_time()));
    main_timer->start(1000);
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::update_time()
{
    int days = 0, hours = 0, mins = 0, secs = 0, tc = 0;

    tc = to.toTime_t() - QDateTime::currentDateTime().toTime_t(); // 剩余秒数
    days = (int)(tc/60/60/24);  // 计算天数
    tc -= days*60*60*24;
    hours = (int)(tc/60/60);    // 计算时数
    tc -= hours*60*60;
    mins = (int)(tc/60);        // 计算分数
    tc -= mins*60;
    secs = tc%60;               // 计算秒数

    ui->ldays->setText( format_num(days) );
    ui->lhours->setText( format_num(hours) );
    ui->lmins->setText( format_num(mins) );
    ui->lsecs->setText( format_num(secs) );
}

void MainWidget::paintEvent(QPaintEvent *e)
{
    QPainter p(this );
    p.fillRect(rect(), QColor(0xff,0,0,10));
}
