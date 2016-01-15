#include "Shape.h"
#include "Line.h"
#include "GenLine.h"
#include <iostream>
#include <cmath>
#include <QDebug>

GenLine::GenLine()
{
}

GenLine::~GenLine()
{
    
}

QRectF GenLine::boundingRect() const
{
  return Line::boundingRect();
}

QPainterPath GenLine::shape() const
{
  return (Line::shape()|arrowPath);
}

void GenLine::paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget )
{
  Line::paint(painter, option, widget);
  painter->setBrush(QColor(255, 255, 255));
  painter->drawPath(this->arrowPath);
}

void GenLine::updatePosition()
{
  Line::updatePosition();
  double angle = acos(this->line.dx() / this->line.length());
  if (this->line.dy() >= 0)
      angle = (M_PI * 2) - angle;
  int arrowSize =10;
  QPointF arrowP1 = this->line.p1() + QPointF(sin(angle + M_PI / 3) * arrowSize,
                                  cos(angle + M_PI / 3) * arrowSize);
  QPointF arrowP2 = this->line.p1() + QPointF(sin(angle + M_PI - M_PI / 3) * arrowSize,
                                  cos(angle + M_PI - M_PI / 3) * arrowSize);
  this->arrowPath = QPainterPath();
  this->arrowPath.moveTo(this->line.p1());
  this->arrowPath.lineTo(arrowP1);
  this->arrowPath.lineTo(arrowP2);
  this->arrowPath.lineTo(this->line.p1());
  qDebug()<<this->line.p1();

}
