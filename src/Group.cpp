#include "Shape.h"
#include "Group.h"
#include <iostream>

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
   //item->setFlag(QGraphicsItem::ItemIsMovable,false);
   item->setParentItem(this);
   this->list.push_back(item); 
   groupPath+=item->shape();
}

void Group::updatePosition(QPointF pos){
      this->setPos(pos);
      for(int i = 0; i< this->list.size(); i++)
      {
        this->list[i]->updatePosition(pos);
      }
}
