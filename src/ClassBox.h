#include <QGraphicsItem>
#include <QBrush>
#include <QPainter>
class BasicBox;
class ClassBox : public BasicBox
{
public:
  ClassBox ();
  virtual ~ClassBox ();
  virtual QRectF boundingRect() const;
  virtual QPainterPath shape() const;
  virtual void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );
protected:

private:
  
};
