#include <QGraphicsItem>
#include <QBrush>
#include <QPainter>
class Line;
class ComLine : public Line
{
public:
  ComLine ();
  virtual ~ComLine ();
  QRectF boundingRect() const;
  QPainterPath shape() const;
  virtual void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );
  void updatePosition();
protected:
  QBrush arrowBrush;
  QPainterPath arrowPath;

private:
  
};
