#include <QGraphicsItem>
#include <QBrush>
#include <QPainter>
class BasicBox;
class UseCaseBox : public BasicBox
{
public:
  UseCaseBox ();
  virtual ~UseCaseBox ();
  virtual QRectF boundingRect() const;
  virtual QPainterPath shape() const;
  virtual void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );
protected:

private:
  
};
