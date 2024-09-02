template<typename T>
bool equals(T a, T b)
{
    constexpr double EPS { 1e-9 };

    return std::is_floating_point<T>::value ?  fabs(a - b) < EPS : a == b;
}

template<typename T>
struct Point {
    T x = 0, y = 0;

    Point() {}
    Point(T _x, T _y): x(_x), y(_y) {}

    bool operator==(const Point<T>& p) const noexcept {
        return equals(x, p.x) && equals(y, p.y);
    }

    bool operator <( const Point & p ) const noexcept {
        return equals(x , p.x ) ? y < p . y : x < p . x ;
    }
};
