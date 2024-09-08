template <typename T>
Circle<T> welzl(vector<Point<T>> &points, vector<Point<T>> r, int n) {
  if (n == 0 || r.size() == 3) {
    if (r.size() == 0) return {{0, 0}, 0};
    if (r.size() == 1) return {r[0], 0};
    if (r.size() == 2) return Circle<T>::from_2_points(r[0], r[1]);
    return Circle<T>::from_3_points(r[0], r[1], r[2]);
  }

  Point<T> p = points[n - 1];
  Circle<T> d = welzl(points, r, n - 1);

  if (d.contains(p)) return d;

  r.push_back(p);
  return welzl(points, r, n - 1);
}

template <typename T>
Circle<T> minimum_enclosing_circle(vector<Point<T>> &points) {
  random_shuffle(points.begin(), points.end());
  return welzl(points, {}, points.size());
}
