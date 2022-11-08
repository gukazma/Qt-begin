#ifndef EXQTREEWIDGET_H
#define EXQTREEWIDGET_H

#include <QMainWindow>
#include <qobjectdefs.h>

namespace Ui {
class ExQTreeWidget;
}

class QTreeWidgetItem;

class ExQTreeWidget : public QMainWindow
{
    Q_OBJECT

public:
    enum treeItemType {         //枚举，节点类型
        itemRoot,
        itemFile,
        itemImage
    };

     enum treeColNum {           //目录树列表的编号
        colItem = 0,
        colItemType = 1
    };

public:
    explicit ExQTreeWidget(QWidget *parent = nullptr);
    ~ExQTreeWidget();

private slots:
    void on_actAddFolder_triggered();
    void on_actAddFile_triggered();


private:
    void initTree();
    void addFolderItem(QTreeWidgetItem *parItem, QString dirName);
    void addImageItem(QTreeWidgetItem *parItem, QString fileName);

    QString getFinalFolderName(const QString &pathName);


private:
    Ui::ExQTreeWidget *ui;
};

#endif // EXQTREEWIDGET_H