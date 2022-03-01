
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include "qmyclass.h"

QPushButton *g_agreeBut;
QPushButton *g_disagreeBut;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //添加窗口
    //QWidget widget;
    MyWidget widget;
    widget.resize(1280, 900); //指定窗口的尺寸
    widget.setFont(QFont("宋体", 16)); //指定窗口显示文字的大小

    //QPushButton按钮的创建
    QPushButton but("按钮控件", &widget); //创建一个按钮，并内嵌到 widget 窗口中
    but.setGeometry(0, 0, 100, 50); //设置按钮的位置和尺寸
    but.move(10, 10); //按钮move位置位于距窗口左上角 (10, 10) 的位置
    but.resize(100, 30); //调整按钮的尺寸
    but.setStyleSheet("QPushButton{font:20px;}"); //设置按钮上文字的大小
    QObject::connect(&but, &QPushButton::clicked, &but, &QWidget::hide); //信号与槽，实现当用户点击按钮时, 该按钮隐藏

    //QLabel文本框的创建
    QLabel lab("name", &widget);
    lab.setAlignment(Qt::AlignLeft); //设置文本框内容居中显示
    lab.setGeometry(10, 300, 200, 100); //设置文本框的坐标和尺寸
    lab.setStyleSheet("QLabel{font:22px; color:red; background-color:rgb(f9, f9, f9);}"); //设置文本框的外观，包括字体的大小和颜色、按钮的背景色
    lab.setText("<a href=\"http://c.biancheng.net\">C语言中文网"); //设置文本框要显示超链接内容
    lab.setToolTip("点击超链接显示URL"); //当用户鼠标位于文本框上时，显示提示内容
    lab.setToolTipDuration(1000); //提示内容显示 1 秒
    QObject::connect(&lab, &QLabel::linkActivated, &lab, &QLabel::setText); //为文本框设置信号和槽，当用户点击超链接时，将文本框内容改为超链接的 URL
    //lab.show(); //文本框显示

    //QLineEdit单行输入框的创建
    QLineEdit lineEdit(&widget); //创建账号输入框
    lineEdit.move(10, 50); //指定输入框位于父窗口中的位置
    lineEdit.setPlaceholderText("请输入账号..."); //设置提示信息
    lineEdit.setClearButtonEnabled(true); //让输入框显示“一键清除”按钮
    QLineEdit lineEditPass(&widget); //创建密码输入框
    lineEditPass.setPlaceholderText("请输入密码...");
    lineEditPass.move(10, 90);
    lineEditPass.setEchoMode(QLineEdit::Password);

    //QListWidget列表框的创建
    QListWidget listWidget(&widget);
    listWidget.resize(300, 120);
    listWidget.move(10, 170);
    listWidget.setFont(QFont("宋体",14));
    listWidget.addItem("1.C语言中文网");
    listWidget.addItem("2.http://c.biancheng.net");
    listWidget.addItem(new QListWidgetItem("3.Qt教程"));
    //使用列表
    QMyLabel print;
    print.setText("选中内容");
    print.setParent(&widget);
    print.resize(400, 20);
    print.move(0, 140);
    print.setAlignment(Qt::AlignCenter);
    QObject::connect(&listWidget, &QListWidget::itemClicked, &print, &QMyLabel::listRsetText);

    //QTableWidget表格的创建
    QTableWidget TableWidget(4, 3, &widget);    //在 widget 窗口中添加一个 4 行 3 列的表格
    TableWidget.resize(800, 200);           //自定义表格的尺寸
    TableWidget.move(10, 360);
    TableWidget.setFont(QFont("宋体", 16)); //自定义字体大小
    TableWidget.setHorizontalHeaderLabels(QStringList() << "教程" << "网址" << "状态");    //设置表格中每一行的表头
    TableWidget.setEditTriggers(QAbstractItemView::NoEditTriggers);    //设置表格数据区内的所有单元格都不允许编辑
    TableWidget.setColumnWidth(0, 150);
    TableWidget.setColumnWidth(1, 400);
    TableWidget.setColumnWidth(2, 150);
    //设置表格中每一行的内容
    TableWidget.setItem(0,0,new QTableWidgetItem("C语言教程"));
    TableWidget.setItem(0,1,new QTableWidgetItem("http://c.biancheng.net/c/"));
    TableWidget.setItem(0,2,new QTableWidgetItem("已更新完毕"));
    TableWidget.setItem(1,0,new QTableWidgetItem("Qt教程"));
    TableWidget.setItem(1,1,new QTableWidgetItem("http://c.biancheng.net/qt/"));
    TableWidget.setItem(1,2,new QTableWidgetItem("正在更新"));
    TableWidget.setItem(2,0,new QTableWidgetItem("C++教程"));
    TableWidget.setItem(2,1,new QTableWidgetItem("http://c.biancheng.net/cplus/"));
    TableWidget.setItem(2,2,new QTableWidgetItem("已更新完毕"));
    //使用表格
    QMyLabel tab;
    tab.setText("选中单元格");
    tab.setParent(&widget);
    tab.resize(400, 50);
    tab.move(10, 320);
    tab.setAlignment(Qt::AlignCenter);
    tab.setFont(QFont("宋体", 16));
    QObject::connect(&TableWidget, &QTableWidget::itemClicked, &tab, &QMyLabel::tabRsetText); //为表格和文本框之间建立关联

    //QTreeWidget控件的创建
    QTreeWidget treeWidget(&widget);
    QTreeWidgetItem item1, item2, item3;
    QTreeWidgetItem item2_1;
    //设置列数
    treeWidget.setColumnCount(3);
    treeWidget.setColumnWidth(0, 200);
    treeWidget.setColumnWidth(1, 400);
    treeWidget.resize(800, 200);
    treeWidget.move(400, 50);
    treeWidget.addTopLevelItem(&item1);
    treeWidget.addTopLevelItem(&item2);
    //设置结点
    item1.setCheckState(0, Qt::Unchecked); //结点1
    item1.setIcon(0, QIcon("../p_c.png"));
    item1.setText(0, "1.C语言教程");
    item1.setText(1, "http://c.biancheng.net");
    item1.setText(2, "已完成");
    item2.setCheckState(0, Qt::PartiallyChecked); //结点2,部分选中状态,选中了其中一部分子结点
    item2.setIcon(0, QIcon("../p_c.png"));
    item2.setText(0, "2.Python");
    item2.setText(1, "http://c.biancheng.net/python/");
    item2.setText(2, "未完成");
    item2.addChild(&item2_1); //为结点添加子结点
    item2_1.setCheckState(0, Qt::Checked);
    item2_1.setIcon(0, QIcon("../p_c.png"));
    item2_1.setText(0, "child 2_1");
    item2_1.setText(1, "child 2_2");
    item2_1.setText(2, "child 2_3");
    //添加信号和槽机制，当某个结点被点击时，调整所有子结点的选中状态，同时将所有子结点展开
    QObject::connect(&treeWidget, &QTreeWidget::itemClicked, &widget, &MyWidget::treeWidgetClicked);
    QObject::connect(&treeWidget, &QTreeWidget::itemClicked, &treeWidget, &QTreeWidget::expandItem);
    //添加其它控件
    //treeWidget.addTopLevelItem(&item3);
    //treeWidget.setItemWidget(&item3, 1, &TableWidget);

    //QMessageBox对话框
    QMessageBox MBox(QMessageBox::Question, "Title", "text");
    MBox.setWindowTitle("QMessageBox自定义对话框");
    MBox.setText("这是一个自定义的对话框");
    MBox.setIconPixmap(QPixmap("../p_c.png"));
    g_agreeBut = MBox.addButton("同意", QMessageBox::AcceptRole);
    g_disagreeBut = MBox.addButton("拒绝", QMessageBox::RejectRole);
    QObject::connect(&MBox, &QMessageBox::buttonClicked, &widget, &MyWidget::buttonClicked); //添加信号和槽，监听用户点击的按钮，如果用户拒绝，则主窗口随之关闭。

    //QFile文件操作

    //Qt布局管理详解（垂直布局,水平布局,网格布局,表单布局,分组布局）

    //让 widget 窗口显示
    widget.show();
    MBox.exec();
    if (MBox.clickedButton() == (QAbstractButton*)g_agreeBut) {
        qDebug() << "用户点击了同意按钮";//在 Qt Creator 的输出窗口中输出指定字符串
    }

    return a.exec();
}

