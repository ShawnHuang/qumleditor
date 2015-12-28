#include "Arrow.h"

#include <math.h>

#include <QPen>
#include <QPainter>
#include "DiagramClass.h"
#include <QDebug>

const qreal Pi = 3.14;

Arrow::Arrow(DiagramClass *startItem, DiagramClass *endItem, QPointF *begin, QPointF *end, QGraphicsItem *parent)
    : QGraphicsLineItem(parent)
{
    myStartItem = startItem;
    myEndItem = endItem;
    this->begin = *begin;
    this->end = *end;
    //qDebug()<<this->begin<<this->end;
    myStartItem->getPort(&this->begin, &port_begin);
    myEndItem->getPort(&this->end, &port_end);
    setFlag(QGraphicsItem::ItemIsSelectable, false);
    myColor = Qt::black;
    setPen(QPen(myColor, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
}

QRectF Arrow::boundingRect() const
{
    qreal extra = (pen().width() + 20) / 2.0;

    return QRectF(line().p1(), QSizeF(line().p2().x() - line().p1().x(),
                                      line().p2().y() - line().p1().y()))
        .normalized()
        .adjusted(-extra, -extra, extra, extra);
}
////! [1]
//
////! [2]
QPainterPath Arrow::shape() const
{
    QPainterPath path = QGraphicsLineItem::shape();
    path.addPolygon(arrowHead);
    return path;
}
////! [2]
//
////! [3]
void Arrow::updatePosition()
{
    QLineF line(mapFromItem(myStartItem, 0, 0), mapFromItem(myEndItem, 0, 0));
    setLine(line);
}
////! [3]
//
////! [4]
void Arrow::paint(QPainter *painter, const QStyleOptionGraphicsItem *,
          QWidget *)
{
    if (myStartItem->collidesWithItem(myEndItem))
        return;

    QPen myPen = pen();
    myPen.setColor(myColor);
    qreal arrowSize = 20;
    painter->setPen(myPen);
    painter->setBrush(myColor);
//! [4] //! [5]

    QLineF centerLine(myStartItem->pos(), myEndItem->pos());
    QPolygonF endPolygon = myEndItem->polygon();
    QPointF p1 = endPolygon.first() + myEndItem->pos();
    QPointF p2;
    QPointF intersectPoint;
    QLineF polyLine;
    for (int i = 1; i < endPolygon.count(); ++i) {
        p2 = endPolygon.at(i) + myEndItem->pos();
        polyLine = QLineF(p1, p2);
        QLineF::IntersectType intersectType =
            polyLine.intersect(centerLine, &intersectPoint);
        if (intersectType == QLineF::BoundedIntersection)
            break;
        p1 = p2;
    }


    
    //setLine(QLineF(intersectPoint, myStartItem->pos()));
    //setLine(QLineF(this->port_end, this->port_begin));
    setLine(QLineF(this->port_end+myEndItem->pos(), this->port_begin+myStartItem->pos()));
//! [5] //! [6]
      double angle = ::acos(line().dx() / line().length());
      if (line().dy() >= 0)
          angle = (Pi * 2) - angle;

  //! //! [7]
      painter->drawLine(line());
      if(this->mode==2){
        QPointF arrowP1 = line().p1() + QPointF(sin(angle + Pi / 3) * arrowSize,
                                        cos(angle + Pi / 3) * arrowSize);
        QPointF arrowP2 = line().p1() + QPointF(sin(angle + Pi - Pi / 3) * arrowSize,
                                        cos(angle + Pi - Pi / 3) * arrowSize);

        arrowHead.clear();
        arrowHead << line().p1() << arrowP1 << arrowP2;
        painter->setBrush(Qt::NoBrush);
        painter->drawPolygon(arrowHead);
      }
      if(this->mode==3){
        QPointF arrowP1 = line().p1() + QPointF(sin(angle + Pi / 3) * arrowSize,
                                        cos(angle + Pi / 3) * arrowSize);
        QPointF arrowP2 = line().p1() + QPointF(sin(angle + Pi - Pi / 3) * arrowSize,
                                        cos(angle + Pi - Pi / 3) * arrowSize);
        QPointF arrowP3 = line().p1() + QPointF(sin(angle + Pi/2) * 2 * arrowSize,
                                        cos(angle + Pi/2) * 2 * arrowSize);
        arrowHead.clear();
        arrowHead << line().p1() << arrowP1 << arrowP3 << arrowP2;

        painter->setBrush(Qt::NoBrush);
        painter->drawPolygon(arrowHead);
      }
      if (isSelected()) {
              painter->setPen(QPen(myColor, 1, Qt::DashLine));
          QLineF myLine = line();
          myLine.translate(0, 4.0);
          painter->drawLine(myLine);
          myLine.translate(0,-8.0);
          painter->drawLine(myLine);
      }    
    
}
////! [7]
void Arrow::setType(int mode)
{
    this->mode = mode;
}
