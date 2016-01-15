#include "Mode.h"
#include "Shape.h"
#include "BasicBox.h"
#include "Group.h"
#include "Canvas.h"
#include <iostream>
#include <QInputDialog>

Canvas::Canvas()
{
    
}

Canvas::~Canvas()
{
  std::cout<<"Canvas delete"<<std::endl; 
}

void Canvas::setMode(Mode* mode)
{
    std::cout<<"Set Mode"<<std::endl; 
    this->mode = mode;
}

QGraphicsItem* Canvas::itemAt(const QPointF & position, const QTransform & deviceTransform) const
{
  QGraphicsItem* select = 0;
  for(QGraphicsItem* item = QGraphicsScene::itemAt(position, deviceTransform);item!=0;item = item->parentItem())
  {
    select = item;
  }
  return select;
}

// ask TA
void Canvas::group()
{
    QList<QGraphicsItem*> selected = this->selectedItems(); 
    if (selected.count()>0)
    {
        Group* group = new Group();
        for(int i = 0; i < selected.size(); ++i) {
          Shape *item = dynamic_cast<Shape *>(selected[i]);
          this->removeItem(item);
          group->add(item);
          std::cout<<"item"<<i<<std::endl; 
        }
        this->addItem(group);
    }
    std::cout<<"Group"<<selected.count()<<std::endl; 
}

// ask TA
void Canvas::ungroup()
{
    std::cout<<"UnGroup"<<std::endl; 
}

// ask TA
void Canvas::named()
{
    QList<QGraphicsItem*> selected = this->selectedItems(); 
    if (selected.count()==1)
    {
      bool isOK; 
      QString text = QInputDialog::getText(NULL, "Input Dialog", 
                                                         "Rename", 
                                                         QLineEdit::Normal, 
                                                         "", 
                                                         &isOK); 
      if(isOK) { 
        // Only basicbox can be selected
        BasicBox *item = dynamic_cast<BasicBox *>(selected.first());
        if (item)
        {
          item->setName(text);  
          item->update();
        }
      }
    } 
    std::cout<<"Named"<<std::endl; 
}

void Canvas::mouseMoveEvent(QGraphicsSceneMouseEvent * event)
{
    this->mode->mouseMoveEvent(event);
}

void Canvas::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    this->mode->mousePressEvent(event);
}

void Canvas::mouseReleaseEvent(QGraphicsSceneMouseEvent * event)
{
    this->mode->mouseReleaseEvent(event);
}

void Canvas::mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event)
{

}
/* vim: set ft=cpp.qt : */
