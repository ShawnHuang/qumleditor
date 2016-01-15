#include "Mode.h"
class AssLineMode : public Mode
{
public:
  AssLineMode (Canvas* canvas);
  virtual ~AssLineMode ();
protected:
  void mouseMoveEvent(QGraphicsSceneMouseEvent * event);
  void mousePressEvent(QGraphicsSceneMouseEvent * event);
  void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
private:
  
};
