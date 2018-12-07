class Rectangle {
public:
    Rectangle(double l, double w):_l(l), _w(w){}
    double area() const
    {
        return _l * _w;
    }
    double perimeter() const
    {
        return (_l + _w) * 2;
    }
private:
    double _l,_w;
};