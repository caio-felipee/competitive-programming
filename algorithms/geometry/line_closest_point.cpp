template<typename T>
Point<T> closest(Point<T>& p, Line<T> l)
{
    auto den = (l.a*l.a + l.b*l.b);

    auto x = (l.b*(l.b*p.x - l.a*p.y) - l.a*l.c)/den;
    auto y = (l.a*(-l.b*p.x + l.a*p.y) - l.b*l.c)/den;

    return Point<T>(x, y);
}
