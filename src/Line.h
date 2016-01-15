#include <QGraphicsItem>
#include <QBrush>
#include <QPainter>
#include <QLine>
class Port;
class Shape;
class Line : public Shape
{
public:
  Line ();
  virtual ~Line ();
  virtual QRectF boundingRect() const;
  virtual QPainterPath shape() const;
  virtual void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );
  virtual void setPorts(Port* begin, Port* end);
  virtual void updatePosition();
protected:
  QBrush lineBrush;
  QPainterPath linePath;
  QLineF line;

private:
  Port* begin;
  Port* end;
  
};
