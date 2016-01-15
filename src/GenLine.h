#include <QGraphicsItem>
#include <QBrush>
#include <QPainter>
class Line;
class GenLine : public Line
{
public:
  GenLine ();
  virtual ~GenLine ();
  virtual QRectF boundingRect() const;
  virtual QPainterPath shape() const;
  virtual void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );
  virtual void updatePosition();
protected:
  QBrush arrowBrush;
  QPainterPath arrowPath;

private:
  
};
