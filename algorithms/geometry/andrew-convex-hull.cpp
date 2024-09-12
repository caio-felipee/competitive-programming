template <typename T>
vector<Point<T>> make_hull(const vector<Point<T>>& points,
                           vector<Point<T>>& hull) {
  for (const auto& p : points) {
    auto size = hull.size();

    while (size >= 2 and D(hull[size - 2], hull[size - 1], p) <= 0) {
      hull.pop_back();
      size = hull.size();
    }

    hull.push_back(p);
  }

  return hull;
}

template <typename T>
vector<Point<T>> monotone_chain(const vector<Point<T>>& points) {
  vector<Point<T>> P(points);

  sort(P.begin(), P.end());

  vector<Point<T>> lower, upper;

  lower = make_hull(P, lower);

  reverse(P.begin(), P.end());

  upper = make_hull(P, upper);

  lower.pop_back();
  lower.insert(lower.end(), upper.begin(), upper.end());

  return lower;
}
