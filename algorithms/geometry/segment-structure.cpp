template <typename T>
class Segment {
 public:
  Point<T> A, B;

    // Verifica se o ponto P da reta r que contém A e B  pertence ao segmento
    bool contains(const Point<T>& P) const
    {
        return equals(A.x, B.x) ?  min(A.y, B.y) <= P.y and P.y <= max(A.y, B.y) 
            : min(A.x, B.x) <= P.x and P.x <= max(A.x, B.x);
    }

    // Esta abordagem não exige que P esteja sobre a reta AB
    bool contains2(const Point<T>& P) const
    {
        double dAB = dist(A, B), dAP = dist(A, P), dPB = dist(P, B);

        return equals(dAP + dPB, dAB);
    }

  bool intersect(const Segment<T>& s) const {
    auto d1 = D(A, B, s.A);
    auto d2 = D(A, B, s.B);

    if ((equals(d1, 0) && contains(s.A)) || (equals(d2, 0) && contains(s.B)))
      return true;

    auto d3 = D(s.A, s.B, A);
    auto d4 = D(s.A, s.B, B);

    if ((equals(d3, 0) && s.contains(A)) || (equals(d4, 0) && s.contains(B)))
      return true;

    // The original check is (d1 * d2 < 0) and (d3 * d4 < 0)
    // Thus, we want to avoid overflow
    bool fst = (d1 < 0 and d2 > 0) or (d1 > 0 and d2 < 0);
    bool snd = (d3 < 0 and d4 > 0) or (d3 > 0 and d4 < 0);

    return fst and snd; 
  }

    // Ponto mais próximo de P no segmento AB
    Point<T> closest(const Point<T>& P)
    {
        Line<T> r(A, B);
        auto Q = r.closest(P);

        if (this->contains(Q))
            return Q;

        auto distA = P.distanceTo(A);
        auto distB = P.distanceTo(B);

        if (distA <= distB)
            return A;
        else
            return B;
    }
};
