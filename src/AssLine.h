#include <QGraphicsItem>
#include <QBrush>
#include <QPainter>
class Line;
class AssLine : public Line
{
public:
  AssLine ();
  virtual ~AssLine ();
  QRectF boundingRect() const;
  QPainterPath shape() const;
  virtual void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );
protected:
  QBrush arrowBrush;
  QPainterPath arrowPath;

private:
  
};
