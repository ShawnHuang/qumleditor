#include <QWidget>
class QGraphicsSceneMouseEvent;
class Canvas;
class Mode : public QWidget
{
public:

  Mode (Canvas* canvas);
  virtual ~Mode ();
  virtual void mouseMoveEvent(QGraphicsSceneMouseEvent * event);
  virtual void mousePressEvent(QGraphicsSceneMouseEvent * event);
  virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
  Canvas* canvas;
private:

};
/* vim: set ft=cpp.qt: */
