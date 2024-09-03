
template<typename T>
struct Line {
    T a, b, c;

    Line(const Point<T>& P, const Point<T>& Q)
        : a(P.y - Q.y), b (Q.x - P.x), c(P.x * Q.y - Q.x * P.y) { }

    bool operator==(const Line<T>& r) const
    {
        auto k = a ? a : b;
        auto s = r.a ? r.a : r.b;

        return equals(a*s, r.a*k) && equals(b*s, r.b*k) && equals(c*s, r.c*k);
    }

    bool parallel(const Line<T>& r) const
    {
        auto det = a*r.b - b*r.a;

        return det == 0 and !(*this == r);
    }

    bool contains(const Point<T>& P) const
    {
        return equals(a*P.x + b*P.y + c, 0);
    }
};
