class Line;
class Shape;
class Port : public Shape
{
public:
  Port (QPointF pos, QGraphicsItem* parent);
  virtual ~Port ();
  virtual QRectF boundingRect() const;
  virtual QPainterPath shape() const;
  virtual void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );
  void addLine(Line* line);
  void updatePosition();
protected:
  std::vector<Line*> lines;

private:
  QPainterPath boundPath;
  QBrush boundBrush;
  
};
