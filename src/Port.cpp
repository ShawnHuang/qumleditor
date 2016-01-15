#include "Shape.h"
#include "Line.h"
#include "Port.h"
#include <QGraphicsItem>
#include <iostream>

Port::Port(QPointF pos, QGraphicsItem* parent)
{
  this->setParentItem(parent);
  this->setPos(pos);
  boundPath.addRect( 0, 0, 5, 5);
}

Port::~Port()
{

}

QRectF Port::boundingRect() const
{
  return boundPath.boundingRect();
}

QPainterPath Port::shape() const
{
  return boundPath;
}

void Port::paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget )
{
  painter->setPen(QPen(QColor(0, 0, 0), 1, Qt::SolidLine,
                      Qt::FlatCap, Qt::MiterJoin));
  painter->setBrush(QColor(0, 0, 0));

  if(this->parentItem()->isSelected())
    painter->drawPath(boundPath);
}

void Port::addLine(Line* line)
{
   this->lines.push_back(line); 
}

void Port::updatePosition()
{
  for(std::vector<Line*>::size_type i = 0; i != lines.size(); i++) {
    this->lines[i]->updatePosition();
  }
}
