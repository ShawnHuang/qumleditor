#include <QGraphicsItem>
#include <QBrush>
#include <QPainter>
class Shape : public QGraphicsItem
{
public:
  Shape ();
  virtual ~Shape ();
  virtual QRectF boundingRect() const = 0; // this function will not change any member variables' value
  virtual QPainterPath shape() const = 0;
  virtual void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget ) = 0;
  virtual void updatePosition();
protected:
  void mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event);
  void mouseMoveEvent(QGraphicsSceneMouseEvent * event);
  void mousePressEvent(QGraphicsSceneMouseEvent * event);
  void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
  bool isClicked(QPointF pos);
  //bool isSelected;
  //int depth;

private:
  
};
