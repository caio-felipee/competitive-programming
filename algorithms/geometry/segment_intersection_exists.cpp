template<typename T>
T Segment<T>::sweep_x;

template<typename T>
bool shamos_hoey(const vector<Segment<T>>& segments)
{
    struct Event
    {
        Point<T> P;
        size_t i;

        bool operator<(const Event& e) const { return P < e.P; }
    };

    vector<Event> events;

    for (size_t i = 0; i < segments.size(); ++i)
    {
        events.push_back({ segments[i].A, i });
        events.push_back({ segments[i].B, i });
    }

    sort(events.begin(), events.end());
    set<Segment<T>> sl;

    for (const auto& e : events)
    {
        auto s = segments[e.i];
        Segment<T>::sweep_x = e.P.x;

        if (e.P == s.A)
        {
            sl.insert(s);

            auto it = sl.find(s);

            if (it != sl.begin())
            {
                auto L = *prev(it);

                if (s.intersect(L)) return true;
            } 

            if (next(it) != sl.end())
            {
                auto U = *next(it);

                if (s.intersect(U)) return true;
            } 
        } else
        {
            auto it = sl.find(s);

            if (it != sl.begin() and it != sl.end())
            {
                auto L = *prev(it);
                auto U = *next(it);

                if (L.intersect(U)) return true;
            }

            sl.erase(it);
        }
    }

    return false;
}
