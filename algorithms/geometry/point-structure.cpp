template <typename T>
bool equals(T a, T b) {
  constexpr double EPS{1e-9};

  return std::is_floating_point<T>::value ? fabs(a - b) < EPS : a == b;
}

template <typename T>
struct Point {
  T x = 0, y = 0;

  Point() {}
  Point(T _x, T _y) : x(_x), y(_y) {}

  bool operator==(const Point<T>& p) const noexcept {
    return equals(x, p.x) && equals(y, p.y);
  }

  bool operator<(const Point& p) const noexcept {
    return equals(x, p.x) ? y < p.y : x < p.x;
  }
};


// D = 0: R pertence a reta PQ
// D > 0: R à esquerda da reta PQ
// D < 0: R à direita da reta PQ
template<typename T>
T D(const Point<T>& P, const Point<T>& Q, const Point<T>& R)
{
    return (P.x * Q.y + P.y * R.x + Q.x * R.y) - (R.x * Q.y + R.y * P.x + Q.x * P.y);
}
