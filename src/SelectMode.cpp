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
  std::cout<<"select pressed"<<std::endl;
}
void SelectMode::mouseMoveEvent(QGraphicsSceneMouseEvent * event){
  std::cout<<"select moved"<<std::endl;
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
        item->updatePosition(item->scenePos()+event->scenePos()-event->buttonDownScenePos(Qt::LeftButton));
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

  std::cout<<"select released"<<std::endl;
}

void SelectMode::mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event)
{
    
}

void SelectMode::unselectAll()
{
  QList<QGraphicsItem *> selected = canvas->selectedItems();
  qDebug()<<selected.size();
  for(int i = 0; i < selected.size(); ++i) {
    qDebug()<<selected[i];
    Shape* item = dynamic_cast<Shape*>(selected[i]);
    if(item) item->setSelected(false);
  }
}
