#include "View.h"
#include "DiagramClass.h"
#include "UMLButton.h"
#include <QAction>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
#include <QInputDialog>

#include <QButtonGroup>
#include <QGridLayout>
#include <QToolButton>
#include <QString>
#include <QLabel>
#include <QToolBox>
#include <QMenuBar>

#include <QGraphicsRectItem>
#include <QRubberBand>
#include <QDebug>

View::View(QWidget *parent) : QMainWindow(parent){
    setWindowTitle(tr("QUMLeditor"));
    //setStyleSheet("*{background:#ccc;color:999;}");
    //QMenu *file = menuBar()->addMenu(tr("&File"));
    //QToolBar *toolBar = addToolBar(tr("&File"));
    //QStatusBar *statusbar = statusBar() ;

    cscene = new CanvasScene;
    cscene->setSceneRect(QRectF(-200,-200,400,400));
    // a white semi-transparent foreground
    //cscene->setBackgroundBrush(Qt::yellow);
    // a grid foreground
    //cscene->setForegroundBrush(QBrush(Qt::lightGray, Qt::CrossPattern));

    cview = new CanvasView; 
    cview->setDragMode(QGraphicsView::RubberBandDrag);
    cview->setScene(cscene);
    cview->resize(400,400);

    QButtonGroup *buttonGroup = new QButtonGroup(this);
    buttonGroup->setExclusive(true);

    UMLButton *button = new UMLButton(cscene,CanvasScene::Select);
    button->setChecked(true);
    UMLButton *button2 = new UMLButton(cscene,CanvasScene::AssoLine);
    UMLButton *button3 = new UMLButton(cscene,CanvasScene::GenLine);
    UMLButton *button4 = new UMLButton(cscene,CanvasScene::ComLine);
    UMLButton *button5 = new UMLButton(cscene,CanvasScene::ClassDiagram);
    UMLButton *button6 = new UMLButton(cscene,CanvasScene::UseCaseDiagram);


    buttonGroup->addButton(button);
    buttonGroup->addButton(button2);
    buttonGroup->addButton(button3);
    buttonGroup->addButton(button4);
    buttonGroup->addButton(button5);
    buttonGroup->addButton(button6);

    QGridLayout *toollayout = new QGridLayout;
    toollayout->addWidget(button, 0, 0, Qt::AlignHCenter);
    toollayout->addWidget(button2, 1, 0, Qt::AlignHCenter);
    toollayout->addWidget(button3, 2, 0, Qt::AlignHCenter);
    toollayout->addWidget(button4, 3, 0, Qt::AlignHCenter);
    toollayout->addWidget(button5, 4, 0, Qt::AlignHCenter);
    toollayout->addWidget(button6, 5, 0, Qt::AlignHCenter);
    toollayout->setAlignment(Qt::AlignTop);
    QWidget *widget = new QWidget;
    widget->setLayout(toollayout);
    widget->setMinimumWidth(100);
    //widget->setMaximumHeight(100);


    //QList<QGraphicsItem*> groupItems;
    //QGraphicsRectItem* rect = cscene->addRect(QRectF(-10, -10, 20, 20));
    //QGraphicsRectItem* rect2 = cscene->addRect(QRectF(-200, -200, 20, 20));
    //rect->setFlag(QGraphicsItem::ItemIsMovable);
    //rect2->setFlag(QGraphicsItem::ItemIsMovable);
    //rect->setFlag(QGraphicsItem::ItemIsSelectable);
    //rect2->setFlag(QGraphicsItem::ItemIsSelectable);
    //rect2->setParentItem(rect);
    //groupItems.append(rect);
    //groupItems.append(rect2);
    //QGraphicsItemGroup * cliGroup = cscene->createItemGroup(groupItems);
    //cliGroup->setFlag(QGraphicsItem::ItemIsMovable);

    //QLabel *qview = new QLabel("test\n\rtest\n\rtest\n\rtest\n\rtest\n\rtest\n\rtest\n\rtest\n\rtest\n\r");
    //QToolBox *toolBox = new QToolBox;
    //toolBox->setSizePolicy(QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Ignored));
    //toolBox->setMinimumWidth(widget->sizeHint().width());
    //toolBox->addItem(widget, tr("Basic Flowchart Shapes")); 

    QWidget *mainWidget = new QWidget;

    QMenuBar *menubar = new QMenuBar;
    QMenu *file =  menubar->addMenu(tr("&File"));
    QAction *exit_action = new QAction(tr("Exit"), mainWidget);
    file->addAction(exit_action);
    connect(exit_action, SIGNAL(triggered()), this, SLOT(close()));
    QMenu *edit =  menubar->addMenu(tr("&Edit"));
    QAction *group = new QAction(tr("Group"), mainWidget);
    edit->addAction(group);
    connect(group, SIGNAL(triggered()), this, SLOT(group()));
    QAction *ungroup = new QAction(tr("UnGroup"), mainWidget);
    edit->addAction(ungroup);
    connect(ungroup, SIGNAL(triggered()), this, SLOT(ungroup()));
    QAction *change_obj_name = new QAction(tr("Change Object Name"), mainWidget);
    edit->addAction(change_obj_name);
    connect(change_obj_name, SIGNAL(triggered()), this, SLOT(rename()));


    QHBoxLayout *layout = new QHBoxLayout;
    //layout->setAlignment(Qt::AlignBottom);
    layout->addWidget(widget,0);
    layout->setAlignment(widget,Qt::AlignTop);
    layout->addWidget(cview,1);
    layout->setMenuBar(menubar);
    mainWidget->setLayout(layout);

    setCentralWidget(mainWidget);

}
View::~View() {
  
}

void View::rename(){
  QList<QGraphicsItem*> selected = cscene->selectedItems(); 
  if (selected.count()==1)
  {
    bool isOK; 
    QString text = QInputDialog::getText(NULL, "Input Dialog", 
                                                       "Rename", 
                                                       QLineEdit::Normal, 
                                                       "", 
                                                       &isOK); 
    DiagramClass *item = qgraphicsitem_cast<DiagramClass *>(selected.first());
    if(isOK) { 
      if (item)
        item->name = text;  
        cscene->update();
    }
  }
}
void View::group(){
  QList<QGraphicsItem*> selected = cscene->selectedItems(); 
  if (selected.count()>1)
  {
    QGraphicsItemGroup *parent = cscene->createItemGroup(selected);
    parent->setFlag(QGraphicsItem::ItemIsMovable);
    parent->setFlag(QGraphicsItem::ItemIsSelectable);

    //foreach(QGraphicsItem* item, selected) {
    //  DiagramClass *dc_item = qgraphicsitem_cast<DiagramClass *>(item);
    //  dc_item->setParentItem(parent);
    //}
  }
}
void View::ungroup(){
  QList<QGraphicsItem*> selected = cscene->selectedItems(); 
  if (selected.count()==1)
  {
    //QGraphicsItem *item = selected.first();
    QGraphicsItemGroup *item = qgraphicsitem_cast<QGraphicsItemGroup *>(selected.first());
    //qDebug()<<QGraphicsItemGroup::Type<<item->type();
    if(item->type()==QGraphicsItemGroup::Type)
    {
      cscene->destroyItemGroup(item);
    }
  }
}
/* vim: set ft=cpp.qt: */
