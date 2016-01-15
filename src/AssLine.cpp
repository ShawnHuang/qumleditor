#include "Shape.h"
#include "Line.h"
#include "AssLine.h"
#include <iostream>

AssLine::AssLine()
{
}

AssLine::~AssLine()
{
    
}

QRectF AssLine::boundingRect() const
{
  return Line::boundingRect();
}

QPainterPath AssLine::shape() const
{
  return Line::shape();
}

void AssLine::paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget )
{
  Line::paint(painter, option, widget);
}
