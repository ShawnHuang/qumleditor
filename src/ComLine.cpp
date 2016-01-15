#include "Shape.h"
#include "Line.h"
#include "ComLine.h"
#include <iostream>
#include <cmath>
#include <QDebug>

ComLine::ComLine()
{
}

ComLine::~ComLine()
{
    
}

QRectF ComLine::boundingRect() const
{
  return Line::boundingRect();
}

QPainterPath ComLine::shape() const
{
  return (Line::shape()|arrowPath);
}

void ComLine::paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget )
{
  Line::paint(painter, option, widget);
  painter->setBrush(QColor(255, 255, 255));
  painter->drawPath(this->arrowPath);
}

void ComLine::updatePosition()
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
  QPointF arrowP3 = this->line.p1() + QPointF(sin(angle + M_PI/2) * 2 * arrowSize,
                                  cos(angle + M_PI/2) * 2 * arrowSize);
  this->arrowPath = QPainterPath();
  this->arrowPath.moveTo(this->line.p1());
  this->arrowPath.lineTo(arrowP1);
  this->arrowPath.lineTo(arrowP3);
  this->arrowPath.lineTo(arrowP2);
  this->arrowPath.lineTo(this->line.p1());
}
