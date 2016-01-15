#include "Mode.h"
#include <QGraphicsItem>
class SelectMode : public Mode
{
public:
  SelectMode (Canvas* canvas);
  virtual ~SelectMode ();
protected:
  void mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event);
  void mouseMoveEvent(QGraphicsSceneMouseEvent * event);
  void mousePressEvent(QGraphicsSceneMouseEvent * event);
  void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
private:
  void unselectAll();
  int moveState;
  int selectState;
  int pressState;
};
