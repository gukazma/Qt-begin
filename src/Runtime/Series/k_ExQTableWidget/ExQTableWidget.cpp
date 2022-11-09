﻿#include "ExQTableWidget.h"
#include "ui_ExQTableWidget.h"
#include <qdatetime.h>
#include <qfont.h>
#include <qicon.h>
#include <qnamespace.h>
#include <qtablewidget.h>
#include <QDate>

ExQTableWidget::ExQTableWidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExQTableWidget)
{
    ui->setupUi(this);
    setWindowTitle(QString::fromLocal8Bit("QTableWidget的讲解和使用"));

    m_labCellIndex = new QLabel(QString::fromLocal8Bit("当前单元格坐标："), this);          //状态栏初始化
    m_labCellIndex->setMinimumWidth(250);
    m_labCellType = new QLabel(QString::fromLocal8Bit("当前单元格类型："), this);
    m_labCellType->setMinimumWidth(200);
    m_labStudID = new QLabel(QString::fromLocal8Bit("学生ID："), this);
    m_labStudID->setMinimumWidth(200);
    ui->statusbar->addWidget(m_labCellIndex);
    ui->statusbar->addWidget(m_labCellType);
    ui->statusbar->addWidget(m_labStudID);
    ui->chkBoxHeadEdit->setChecked(Qt::Unchecked);

    setCentralWidget(ui->splitter_2);
    on_btnSetHeader_clicked();
    createItemsARow(0, QString::fromLocal8Bit("小明"), QString::fromLocal8Bit("男"), {2019, 9, 12},  QString::fromLocal8Bit("中国"), 100 , true);
}

void ExQTableWidget::on_btnSetHeader_clicked()
{
    QTableWidgetItem* item = nullptr;
    QStringList list;
    list << QString::fromLocal8Bit("姓名") << QString::fromLocal8Bit("性别") << QString::fromLocal8Bit("出生日期") << QString::fromLocal8Bit("籍贯") << QString::fromLocal8Bit("分数") << QString::fromLocal8Bit("是否喜欢二次元");

    ui->tableWidget->setColumnCount(list.count());
    for (int i = 0; i < ui->tableWidget->columnCount(); ++i) {
        item = new QTableWidgetItem(list.at(i));
        QFont font;
        font.setBold(true);
        font.setPointSize(12);
        item->setFont(font);
        item->setTextColor(Qt::red);
        ui->tableWidget->setHorizontalHeaderItem(i, item);
    }
    
}


void ExQTableWidget::createItemsARow(int row, QString name, QString sex, QDate birth, QString nation, int score, bool isAnime)
{
    QTableWidgetItem* item = nullptr;
    int stunID = 20190913;
    QString str = "";

    item = new QTableWidgetItem(name, cellType::ctName);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    stunID += row;
    item->setData(Qt::UserRole, QVariant(stunID));
    ui->tableWidget->setItem(row, fieldColNum::colName, item);

    item = new QTableWidgetItem(sex, cellType::ctSex);
    QIcon icon;
    if (sex == QString::fromLocal8Bit("男"))
        icon.addFile(":/images/Image002.ico");
    else
        icon.addFile(":/images/Image003.ico");
    item->setIcon(icon);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->tableWidget->setItem(row, fieldColNum::colSex,  item);
    
    item = new QTableWidgetItem(birth.toString("yyyy-MM-dd"), cellType::ctBirth);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->tableWidget->setItem(row, fieldColNum::colBirth, item);

    item = new QTableWidgetItem(nation, cellType::ctNation);          //籍贯
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->tableWidget->setItem(row, fieldColNum::colNation, item);

    item = new QTableWidgetItem(str.setNum(score), cellType::ctScore);
    item->setTextAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
    ui->tableWidget->setItem(row, fieldColNum::colScore, item);

    item = new QTableWidgetItem(QString::fromLocal8Bit("喜欢"), cellType::ctLikeAnime);
    if (isAnime) 
        item->setCheckState(Qt::Checked);
    else
        item->setCheckState(Qt::Unchecked);

    item->setTextAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
    item->setBackgroundColor(Qt::gray);
    ui->tableWidget->setItem(row, fieldColNum::colLikeAnime, item);

}


ExQTableWidget::~ExQTableWidget()
{
    delete ui;
}
