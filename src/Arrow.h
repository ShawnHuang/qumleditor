#ifndef ARROW_H
#define ARROW_H

#include <QGraphicsLineItem>

class DiagramClass;
class Arrow : public QGraphicsLineItem
{
public:
    //enum { Type = UserType + 4 };

    Arrow(DiagramClass *startItem, DiagramClass *endItem, QPointF *begin, QPointF *end,
      QGraphicsItem *parent = 0);

    //int type() const Q_DECL_OVERRIDE { return Type; }
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;
    void setColor(const QColor &color) { myColor = color; }
    DiagramClass *startItem() const { return myStartItem; }
    DiagramClass *endItem() const { return myEndItem; }
    void setType(int mode);

    void updatePosition();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) Q_DECL_OVERRIDE;

private:
    DiagramClass *myStartItem;
    DiagramClass *myEndItem;
    QColor myColor;
    QPolygonF arrowHead;
    QPointF begin,end;
    QPointF port_begin,port_end;
    int mode;
};

#endif // ARROW_H
