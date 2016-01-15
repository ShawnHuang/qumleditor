#include "Mode.h"
class ComLineMode : public Mode
{
public:
  ComLineMode (Canvas* canvas);
  virtual ~ComLineMode ();
protected:
  void mouseMoveEvent(QGraphicsSceneMouseEvent * event);
  void mousePressEvent(QGraphicsSceneMouseEvent * event);
  void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
private:
  
};
