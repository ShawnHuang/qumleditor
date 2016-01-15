#include "Mode.h"
class UseCaseMode : public Mode
{
public:
  UseCaseMode (Canvas* canvas);
  virtual ~UseCaseMode ();
protected:
  void mouseMoveEvent(QGraphicsSceneMouseEvent * event);
  void mousePressEvent(QGraphicsSceneMouseEvent * event);
  void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
private:
  
};
