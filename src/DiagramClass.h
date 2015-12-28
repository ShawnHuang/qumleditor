#ifndef DIAGRAMCLASS
#define DIAGRAMCLASS
#include <QGraphicsPolygonItem>
#include <QPainter>

class CanvasScene;
class Arrow;
class DiagramClass : public QGraphicsPolygonItem
{
public:
  enum { Type = UserType + 15 };
  DiagramClass();
  virtual ~DiagramClass();
  void removeArrow(Arrow *arrow);
  void removeArrows();
  void addArrow(Arrow *arrow);
  void getPort(QPointF* point, QPointF* output);
  QPolygonF polygon() const { return myPolygon; }
  void setType(int mode);
  int mode;
  int type() const Q_DECL_OVERRIDE { return Type;}
  QString name;
protected:
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) Q_DECL_OVERRIDE;
private:
  QPolygonF myPolygon;
  QList<Arrow *> arrows;
};
#endif
