#include "Shape.h"
#include "Port.h"
#include "BasicBox.h"
#include "UseCaseBox.h"
#include <iostream>

UseCaseBox::UseCaseBox()
{
  QPointF points[4] = {QPointF(45, 0), QPointF(45, 75), QPointF(0, 35), QPointF(95, 35)};
  //for (unsigned int i = 0; i < sizeof(points); ++i)
  for (unsigned int i = 0; i < sizeof(points)/sizeof(*points); ++i)
  {
    this->ports.push_back(new Port(points[i], this));    
  }
  BasicBox::boundPath.addEllipse( 0, 0, 100, 80);
  std::cout<<"usecase created"<<std::endl;
}

UseCaseBox::~UseCaseBox()
{

}

QRectF UseCaseBox::boundingRect() const
{
  return BasicBox::boundPath.boundingRect();
}

QPainterPath UseCaseBox::shape() const
{
  return BasicBox::boundPath;
}

void UseCaseBox::paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget )
{
  painter->setPen(QPen(QColor(0, 0, 0), 1, Qt::SolidLine,
                      Qt::FlatCap, Qt::MiterJoin));
  painter->setBrush(QColor(200, 200, 200));

  painter->drawPath(BasicBox::boundPath);
  painter->drawText(0, 0, 100, 80, Qt::AlignCenter, name);
  std::cout<<"usecase paint"<<std::endl;
}
