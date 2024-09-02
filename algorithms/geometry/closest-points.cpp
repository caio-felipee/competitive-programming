template<typename T>
double dist(Point<T>& P, Point<T>& Q)
{
    return hypot(P.x - Q.x, P.y - Q.y);
}

template<typename T>
pair<Point<T>, Point<T>> closest_pair(int N, vector<Point<T>> &ps)
{
    using ii = pair<T, T>;

    sort(ps.begin(), ps.end());

    // Este código assume que N > 1
    auto d = dist(ps[0], ps[1]);
    auto closest = make_pair(ps[0], ps[1]);

    set<ii> S;
    S.insert(ii(ps[0].y, ps[0].x));
    S.insert(ii(ps[1].y, ps[1].x));

    for (int i = 2; i < N; ++i)
    {
        auto P = ps[i];
        auto it = S.lower_bound(ii(P.y - d, 0));

        while (it != S.end())
        {
            auto Q = Point<T>(it->second, it->first);

            if (Q.x < P.x - d)
            {
                it = S.erase(it);
                continue;
            }

            if (Q.y > P.y + d)
                break;

            auto t = dist(P, Q);

            if (t < d)
            {
                d = t;
                closest = make_pair(P, Q);
            }

            ++it;
        }

        S.insert(ii(P.y, P.x));
    }

    return closest;
}
