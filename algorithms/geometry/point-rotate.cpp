const double PI = acos(-1.0);

template<typename T>
Point<T> rotate_point(Point<T> &P, double a) {
    return Point<T>(P.x * cos(a) - P.y * sin(a),
                    P.x * sin(a) + P.y * cos(a));
}

double radians(double angle)
{
    return (PI * angle) / 180.0;
}
