#ifndef SHAPE_H
#define SHAPE_H
class FindAreaVisitor;
class Shape
{
public:
  virtual double area() const = 0;
  virtual double perimeter() const = 0;

  virtual int numberOfChild()const;
  virtual Shape * getChild(int i)const;
  virtual void add(Shape *s);
  virtual void accept(FindAreaVisitor *fav)=0;
  virtual void acceptInner(FindAreaVisitor *fav)=0;
};
#endif