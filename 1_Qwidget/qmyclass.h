#ifndef QMYCLASS_H
#define QMYCLASS_H

#include <QLabel>
#include <QListWidgetItem>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>

extern QPushButton *g_agreeBut;
extern QPushButton *g_disagreeBut;

class QMyLabel:public QLabel{
    Q_OBJECT
public slots:
    void listRsetText(QListWidgetItem *item);
    void tabRsetText(QTableWidgetItem * item);
};

//自定义槽函数
class MyWidget:public QWidget{
    Q_OBJECT
public slots:
    void treeWidgetClicked(QTreeWidgetItem * item);
    void buttonClicked(QAbstractButton * butClicked);
};

#endif // QMYCLASS_H
