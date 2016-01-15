#include "Mode.h"
class GenLineMode : public Mode
{
public:
  GenLineMode (Canvas* canvas);
  virtual ~GenLineMode ();
protected:
  void mouseMoveEvent(QGraphicsSceneMouseEvent * event);
  void mousePressEvent(QGraphicsSceneMouseEvent * event);
  void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
private:
  
};
