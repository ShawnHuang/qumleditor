#include <QGraphicsItem>
#include <QBrush>
#include <QPainter>
class Shape;
class Group : public Shape
{
public:
  Group ();
  virtual ~Group ();
  QRectF boundingRect() const;
  QPainterPath shape() const;
  void add(Shape* item);
  virtual void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );
  void updatePosition(QPointF pos);
protected:
  QBrush groupBrush;
  QPainterPath groupPath;

private:
  std::vector<Shape*> list; 
};
