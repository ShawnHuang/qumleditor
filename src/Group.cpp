#include "Shape.h"
#include "Group.h"
#include <iostream>
#include <QDebug>

Group::Group()
{
    this->setFlag(QGraphicsItem::ItemIsSelectable,true);
    //this->setFlag(QGraphicsItem::ItemIsMovable,true);
    //this->groupPath.addRect( 0, 0, 200, 200);
    std::cout<<"group created"<<std::endl;
}

Group::~Group()
{
    
}

QRectF Group::boundingRect() const
{
  return groupPath.boundingRect();
}

QPainterPath Group::shape() const
{
  return groupPath;
}

void Group::paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget )
{

}

void Group::add(Shape* item)
{
   item->setFlag(QGraphicsItem::ItemIsSelectable,false);
   item->setParentItem(this);
   this->list.push_back(item); 
   groupPath.addPath(mapFromItem(item,item->shape()));
}

void Group::updatePosition(){
      for(unsigned int i = 0; i< this->list.size(); i++)
      {
        this->list[i]->updatePosition();
      }
}

std::vector<Shape*> Group::getList()
{
  return this->list;
}
