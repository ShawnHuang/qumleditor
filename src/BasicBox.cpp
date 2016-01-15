#include "Shape.h"
#include "Port.h"
#include "Line.h"
#include "BasicBox.h"
#include <iostream>
#include <cmath>
#include <QDebug>
#include <QGraphicsScene>

BasicBox::BasicBox() : name("")
{
    std::cout<<"basicbox created"<<std::endl;
    this->setFlag(QGraphicsItem::ItemIsSelectable,true);
    //this->setFlag(QGraphicsItem::ItemIsMovable,true);
}

BasicBox::~BasicBox()
{
    
}

QRectF BasicBox::boundingRect() const
{
  return boundPath.boundingRect();
}

QPainterPath BasicBox::shape() const
{
  return boundPath;
}

Port* BasicBox::getPort(QPointF clicked)
{
    double dist[this->ports.size()];
    double max=2147483647;
    int min_idx;
    for(unsigned int i = 0; i < this->ports.size(); i++)
    {
        //qDebug()<<this->ports[i]->scenePos();
        //qDebug()<<clicked;
        dist[i] = sqrt(pow((this->ports[i]->scenePos()-clicked).x(), 2) + pow((this->ports[i]->scenePos()-clicked).y(), 2));
        if (dist[i]<max)
        {
          max = dist[i];
          min_idx = i;
        }
    }
    return this->ports[min_idx];
}

void BasicBox::updatePosition(){
      for(std::vector<Port*>::size_type i = 0; i != this->ports.size(); i++) {
        this->ports[i]->updatePosition();
      }
}

void BasicBox::setName(QString name)
{
    this->name = name;
}
