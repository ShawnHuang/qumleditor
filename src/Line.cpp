#include "Shape.h"
#include "Line.h"
#include "Port.h"
#include <iostream>
#include <QGraphicsScene>
#include <QDebug>

Line::Line() : begin(0), end(0)
{
  std::cout<<"line created"<<std::endl;
}

Line::~Line()
{
    
}

QRectF Line::boundingRect() const
{
  return linePath.boundingRect();
}

QPainterPath Line::shape() const
{
  return linePath;
}

void Line::paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget )
{
  painter->setPen(QPen(QColor(127,127,127),2));
  painter->drawPath( linePath);
}
void Line::updatePosition(){
    this->line = QLineF(this->begin->scenePos(), this->end->scenePos());
    linePath = QPainterPath();
    linePath.moveTo(this->line.p1());
    linePath.lineTo(this->line.p2());
    // not sure if it is added to scene
    if(this->scene()) this->scene()->update();
}

void Line::setPorts(Port* begin, Port* end)
{
  begin->addLine(this);
  end->addLine(this);
  this->begin = begin;
  this->end = end;
  this->updatePosition();
}
