
#include "qmyclass.h"


using namespace std;


void QMyLabel::listRsetText(QListWidgetItem *item)
{
    this->setText(item->text());
}

void QMyLabel::tabRsetText(QTableWidgetItem * item)
{
    this->setText(item->text());
}

//接收 itemClicked() 信号函数传递过来的 item 参数
void MyWidget::treeWidgetClicked(QTreeWidgetItem *item)
{
    for(int i=0;i<item->childCount();i++){ //遍历 item 结点所有的子结点
        QTreeWidgetItem *childItem = item->child(i); //找到每个子结点
        childItem->setCheckState(0,item->checkState(0)); //将子结点的选中状态调整为和父结点相同
    }
}

void MyWidget::buttonClicked(QAbstractButton * butClicked)
{
    if(butClicked == (QAbstractButton*)g_disagreeBut){
        this->close();
    }
}
