#include "Canvas.h"
#include "SelectMode.h"
#include "Shape.h"
#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>

SelectMode::SelectMode(Canvas* canvas) : Mode(canvas), moveState(0), selectState(0), pressState(0){
    
}
SelectMode::~SelectMode(){
    
}
void SelectMode::mousePressEvent(QGraphicsSceneMouseEvent * event){
  QTransform transform;
  Shape* item = dynamic_cast<Shape*>(canvas->itemAt(event->scenePos(), transform));
  if (item)
  {
    this->selectState = 1;
  }
  else
    this->selectState = 0;
  this->pressState = 1;
}
void SelectMode::mouseMoveEvent(QGraphicsSceneMouseEvent * event){
  this->moveState = 1;
}
void SelectMode::mouseReleaseEvent(QGraphicsSceneMouseEvent * event){
  if(this->pressState ==1)
  {
    if (this->selectState==1)
    {
      QTransform transform;
      Shape* item = dynamic_cast<Shape*>(canvas->itemAt(event->buttonDownScenePos(Qt::LeftButton), transform));
      if (this->moveState==1)
      {
        item->setPos(item->scenePos()+event->scenePos()-event->buttonDownScenePos(Qt::LeftButton));
        item->updatePosition();
      }
      else
      {
        this->unselectAll();
        if(!item->isSelected()) {
          item->setSelected(true);
        }
      }
    }
    else
    {
      if (this->moveState==1)
      {
        this->unselectAll();
        QRectF rect(event->buttonDownScenePos(Qt::LeftButton), event->scenePos());
        QPolygonF p(rect);
        QPainterPath path;
        path.addPolygon(p);
        QTransform transform;
        canvas->setSelectionArea(path, Qt::ContainsItemShape, transform);
      }      
      else
      {
        this->unselectAll();
      }
    }
  }

  this->moveState = 0;
  this->selectState = 0;
  this->pressState = 0;

  QList<QGraphicsItem *> selected = canvas->selectedItems();
  std::cout<<"select :"<< selected.size()<<std::endl;
}

void SelectMode::mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event)
{
    
}

void SelectMode::unselectAll()
{
  QList<QGraphicsItem *> selected = canvas->selectedItems();
  for(int i = 0; i < selected.size(); ++i) {
    Shape* item = dynamic_cast<Shape*>(selected[i]);
    if(item) item->setSelected(false);
  }
}
