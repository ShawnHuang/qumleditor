#include <QGraphicsItem>
#include <QBrush>
#include <QPainter>
class Port;
class Shape;
class Line;
class BasicBox : public Shape
{
public:
  std::vector<Port*> ports;

  BasicBox ();
  virtual ~BasicBox ();
  virtual QRectF boundingRect() const;
  virtual QPainterPath shape() const;
  virtual void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget ) = 0;
  void updatePosition();
  Port* getPort(QPointF clicked);
  void setName(QString name);
protected:
  QPainterPath boundPath;
  QBrush boundBrush;
  QString name;

private:
  
};
