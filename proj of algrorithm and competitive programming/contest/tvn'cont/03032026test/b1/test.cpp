namespace soup2 {
    const long double eps = 1e-12L;

    long double cross(const vect &a, const vect &b) {
        return a.x * b.y - a.y * b.x;
    }

    int side(const point &a, const point &b, const point &c) {
        vect ab{b.x - a.x, b.y - a.y};
        vect ac{c.x - a.x, c.y - a.y};
        long double s = cross(ab, ac);
        if (fabsl(s) < eps) return 0;
        return (s > 0 ? 1 : -1);
    }

    inline bool inside(const vector<point> &poly, const point &pt) {
        // polygon vertices are given CCW; point on boundary counts as inside
        int sz = (int)poly.size();
        for (int i = 0; i < sz; ++i) {
            int j = (i + 1) % sz;
            if (side(poly[i], poly[j], pt) == -1) return false; // strictly to the right -> outside
        }
        return true;
    }

    inline bool check(const point &spe) {
        for (int i = 0; i < m; ++i) {
            vector<point> poly;
            long double tx = v[i].x, ty = v[i].y;
            poly.reserve(p.size());
            for (const auto &pt : p) poly.emplace_back(point{pt.x + tx, pt.y + ty});
            if (!inside(poly, spe)) return false;
        }
        return true;
    }

    void solve() {
        cin >> q;
        while (q--) {
            point t; cin >> t.x >> t.y;
            if (check(t)) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}
