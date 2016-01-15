#include "Shape.h"
#include <iostream>

Shape::Shape()
{
    std::cout<<"shape created"<<std::endl;
}

Shape::~Shape()
{
    
}

void Shape::updatePosition(){
    std::cout<<"shape updatePosition"<<std::endl;
}
//QRectF Shape::boundingRect() const
//{
//  //return m_qPath.boundingRect();
//}

//QPainterPath Shape::shape() const
//{
//  //return m_qPath;
//}
//
//void Shape::paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget )
//{
//  //painter->fillPath( m_qPath, m_qBrush );
//}
//
void Shape::mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event)
{
    
}
void Shape::mouseMoveEvent(QGraphicsSceneMouseEvent * event)
{
    
}
void Shape::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    
}
void Shape::mouseReleaseEvent(QGraphicsSceneMouseEvent * event)
{
    
}
