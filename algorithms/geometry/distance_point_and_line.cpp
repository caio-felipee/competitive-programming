template<typename T>
double distance(Point<T>& p, Line<T>& l)
{
    return fabs(l.a*p.x + l.b*p.y)/hypot(l.a, l.b);
}
