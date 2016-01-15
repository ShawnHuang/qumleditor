#include "Shape.h"
#include "Port.h"
#include "BasicBox.h"
#include "ClassBox.h"
#include <iostream>

ClassBox::ClassBox()
{
  QPointF points[4] = {QPointF(45, 0), QPointF(45, 85), QPointF(0, 43), QPointF(85, 43)};
  //for (unsigned int i = 0; i < sizeof(points); ++i)
  for (unsigned int i = 0; i < sizeof(points)/sizeof(*points); ++i)
  {
    this->ports.push_back(new Port(points[i], this));    
  }
  BasicBox::boundPath.addRect( 0, 0, 90, 90);
  std::cout<<"usecase created"<<std::endl;
}

ClassBox::~ClassBox()
{
    
}

QRectF ClassBox::boundingRect() const
{
  return BasicBox::boundPath.boundingRect();
}

QPainterPath ClassBox::shape() const
{
  return BasicBox::boundPath;
}

void ClassBox::paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget )
{
  painter->setPen(QPen(QColor(0, 0, 0), 1, Qt::SolidLine,
                      Qt::FlatCap, Qt::MiterJoin));
  painter->setBrush(QColor(200, 200, 200));

  painter->drawPath(BasicBox::boundPath);
  painter->drawLine(QLine(0, 30, 90, 30));
  painter->drawLine(QLine(0, 60, 90, 60));
  painter->drawText(0, 0, 90, 30, Qt::AlignCenter, name);
  std::cout<<"class paint"<<std::endl;
}
