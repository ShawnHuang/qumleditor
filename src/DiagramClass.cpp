#include "Arrow.h"
#include "DiagramClass.h"
#include "CanvasScene.h"
#include <QDebug>

DiagramClass::DiagramClass()
{
    //QPainterPath path;
    //path.moveTo(200, 50);
    //path.arcTo(150, 0, 50, 50, 0, 90);
    //path.arcTo(50, 0, 50, 50, 90, 90);
    //path.arcTo(50, 50, 50, 50, 180, 90);
    //path.arcTo(150, 50, 50, 50, 270, 90);
    //path.lineTo(200, 25);
    //myPolygon = path.toFillPolygon();
    name="";
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    //setPolygon(myPolygon);
}

DiagramClass::~DiagramClass()
{
    
}
void DiagramClass::removeArrow(Arrow *arrow)
{
    int index = arrows.indexOf(arrow);

    if (index != -1)
        arrows.removeAt(index);
}
void DiagramClass::removeArrows()
{
    foreach (Arrow *arrow, arrows) {
        arrow->startItem()->removeArrow(arrow);
        arrow->endItem()->removeArrow(arrow);
        //scene()->removeItem(arrow);
        delete arrow;
    }
}
void DiagramClass::addArrow(Arrow *arrow)
{
    arrows.append(arrow);
}
void DiagramClass::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
          QWidget *widget)
{
  QFont font=painter->font() ;
  font.setPointSize(18);
  painter->setFont(font);
  painter->drawText(QPoint(0, 0), name);
  QRectF rect = this->boundingRect();
  if (this->mode==4)
  {
    painter->drawLine(-rect.width()/2,-rect.height()/6,rect.width()/2,-rect.height()/6);
    painter->drawLine(-rect.width()/2,rect.height()/6,rect.width()/2,rect.height()/6);
    painter->drawRect(-100,-100,200,200);
  }
  else
    painter->drawEllipse(-100,-100,200,200);
  if (this->isSelected())
  {
    painter->setPen(QPen(Qt::blue, 1, Qt::SolidLine));
    painter->setBrush(Qt::blue);
    painter->drawRect(-5, -rect.height()/2,10,10);
    painter->drawRect(-5, rect.height()/2-10,10,10);
    painter->drawRect(-rect.width()/2, -5,10,10);
    painter->drawRect(rect.width()/2-10, -5,10,10);
  }
  //QGraphicsPolygonItem::paint(painter, option, widget);
}
void DiagramClass::getPort(QPointF* point, QPointF* output)
{
    //qDebug()<<*point;
    QPointF top = mapFromScene(*point)-QPointF(0,-100);
    QPointF left = mapFromScene(*point)-QPointF(-100,0);
    QPointF right = mapFromScene(*point)-QPointF(100,0);
    QPointF bottom = mapFromScene(*point)-QPointF(0,100);

    double dist[4];
    dist[0] = sqrt(pow(top.x(), 2) + pow(top.y(), 2));
    dist[1] = sqrt(pow(left.x(), 2) + pow(left.y(), 2));
    dist[2] = sqrt(pow(right.x(), 2) + pow(right.y(), 2));
    dist[3] = sqrt(pow(bottom.x(), 2) + pow(bottom.y(), 2));

    double min=2147483647;
    int min_i;
    for(int i = 0;i<4;i++)
    {
       if (dist[i]<min)
       {
         min_i = i;
         min = dist[i];
       } 
    }
    switch(min_i){
       case 0:
         *output = QPointF(0,-100);
         break;
       case 1:
         *output = QPointF(-100,0);
         break;
       case 2:
         *output = QPointF(100,0);
         break;
       case 3:
         *output = QPointF(0,100);
         break;
    }
}
void DiagramClass::setType(int mode)
{
  this->mode = mode;    
  if (this->mode==4)
  {
    myPolygon << QPointF(-100, -100) << QPointF(-100, 100)
              << QPointF(100, 100) << QPointF(100, -100)
              << QPointF(-100, -100);
    setPolygon(myPolygon);
  }
  else{
    myPolygon << QPointF(-100, -100) << QPointF(-100, 100)
              << QPointF(100, 100) << QPointF(100, -100)
              << QPointF(-100, -100);
    setPolygon(myPolygon);
  }
}
