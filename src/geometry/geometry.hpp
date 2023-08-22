#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

double constexpr EPS = 1e-10;
double constexpr PI = 3.14159265358979323846;

inline bool equals(double a, double b) { return fabs(a - b) < EPS; }

static int const COUNTER_CLOCKWISE = 1;
static int const CLOCKWISE = -1;
static int const ONLINE_BACK = 2;
static int const ONLINE_FRONT = -2;
static int const ON_SEGMENT = 0;

struct Point {
	double x, y;

	Point() = default;

	Point(double x, double y) : x(x), y(y) {}

	Point operator+(Point const &p) const { return {x + p.x, y + p.y}; }

	Point operator-(Point const &p) const { return {x - p.x, y - p.y}; }

	Point operator*(double const &k) const { return {x * k, y * k}; }

	Point operator/(double const &k) const { return {x / k, y / k}; }

	friend istream &operator>>(istream &is, Point &p) {
		is >> p.x >> p.y;
		return is;
	}

	bool operator==(Point const &p) const {
		return (fabs(x - p.x) < EPS && fabs(y - p.y) < EPS);
	}

	bool operator<(Point const &p) const {
		return (x != p.x ? x < p.x : y < p.y);
	}

	[[nodiscard]] double norm() const { return x * x + y * y; }

	[[nodiscard]] double abs() const { return sqrt(norm()); }
};

using Vector = Point;

inline double norm(Vector a) { return a.x * a.x + a.y * a.y; }

inline double abs(Vector a) { return sqrt(norm(a)); }

inline double dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }

inline double cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }

inline bool is_parallel(Vector a, Vector b) { return equals(cross(a, b), 0.0); }

inline bool is_orthogonal(Vector a, Vector b) { return equals(dot(a, b), 0.0); }

struct EndPoint {
	Point p;
	int seg, st;

	EndPoint() = default;

	EndPoint(Point p, int seg, int st) : p(p), seg(seg), st(st) {}

	bool operator<(EndPoint const &ep) const {
		if (p.y == ep.p.y) return st < ep.st;
		return p.y < ep.p.y;
	}
};

struct Segment {
	Point p1, p2;

	Segment() = default;

	Segment(Point p1, Point p2) : p1(p1), p2(p2) {}

	friend istream &operator>>(istream &is, Segment &s) {
		is >> s.p1 >> s.p2;
		return is;
	}
};

using Line = Segment;

inline Point project(Segment s, Point p) {
	Vector base = s.p2 - s.p1;
	double r = dot(p - s.p1, base) / base.norm();
	return s.p1 + base * r;
}

inline Point reflect(Segment s, Point p) {
	return p + (project(s, p) - p) * 2.0;
}

struct Circle {
	Point c;
	double r;

	Circle() = default;

	Circle(Point c, double r) : c(c), r(r) {}
};

using Polygon = vector<Point>;

inline int ccw(Point p0, Point p1, Point p2) {
	Vector a = p1 - p0, b = p2 - p0;
	if (cross(a, b) > EPS) return COUNTER_CLOCKWISE;
	if (cross(a, b) < -EPS) return CLOCKWISE;
	if (dot(a, b) < -EPS) return ONLINE_BACK;
	if (a.norm() < b.norm()) return ONLINE_FRONT;
	return ON_SEGMENT;
}

inline bool intersect_ss(Point p1, Point p2, Point p3, Point p4) {
	return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
			ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

inline bool intersect_ss(Segment s1, Segment s2) {
	return intersect_ss(s1.p1, s1.p2, s2.p1, s2.p2);
}

inline int intersect_cs(Circle c, Segment s) {
	if (norm(project(s, c.c) - c.c) - c.r * c.r > EPS) return 0;
	double d1 = abs(c.c - s.p1), d2 = abs(c.c - s.p2);
	if (d1 < c.r + EPS && d2 < c.r + EPS) return 0;
	if ((d1 < c.r - EPS && d2 > c.r + EPS) ||
		(d1 > c.r + EPS && d2 < c.r - EPS))
		return 1;
	Point h = project(s, c.c);
	if (dot(s.p1 - h, s.p2 - h) < 0) return 2;
	return 0;
}

inline int intersect_cc(Circle c1, Circle c2) {
	if (c1.r < c2.r) swap(c1, c2);
	double d = abs(c1.c - c2.c);
	double r = c1.r + c2.r;
	if (equals(d, r)) return 3;
	if (d > r) return 4;
	if (equals(d + c2.r, c1.r)) return 1;
	if (d + c2.r < c1.r) return 0;
	return 2;
}

inline double get_distance_lp(Line l, Point p) {
	return abs(cross(l.p2 - l.p1, p - l.p1) / abs(l.p2 - l.p1));
}

inline double get_distance_sp(Segment s, Point p) {
	if (dot(s.p2 - s.p1, p - s.p1) < 0.0) return abs(p - s.p1);
	if (dot(s.p1 - s.p2, p - s.p2) < 0.0) return abs(p - s.p2);
	return get_distance_lp(s, p);
}

inline double get_distance_ss(Segment s1, Segment s2) {
	if (intersect_ss(s1, s2)) return 0.0;
	return min({get_distance_sp(s1, s2.p1),
				get_distance_sp(s1, s2.p2),
				get_distance_sp(s2, s1.p1),
				get_distance_sp(s2, s1.p2)});
}

inline Point get_cross_point_ll(Line l1, Line l2) {
	double a = cross(l1.p2 - l1.p1, l2.p2 - l2.p1);
	double b = cross(l1.p2 - l1.p1, l1.p2 - l2.p1);
	if (abs(a) < EPS && abs(b) < EPS) return l2.p1;
	return l2.p1 + (l2.p2 - l2.p1) * (b / a);
}

inline Point get_cross_point_ss(Segment s1, Segment s2) {
	Vector base = s2.p2 - s2.p1;
	double d1 = abs(cross(base, s1.p1 - s2.p1));
	double d2 = abs(cross(base, s1.p2 - s2.p1));
	return s1.p1 + (s1.p2 - s1.p1) * (d1 / (d1 + d2));
}

inline vector<Point> get_cross_point_cl(Circle c, Line l) {
	vector<Point> ps;
	Vector pr = project(l, c.c);
	Vector e = (l.p2 - l.p1) / abs(l.p2 - l.p1);
	if (equals(get_distance_lp(l, c.c), c.r)) return vector<Point>{pr, pr};
	double base = sqrt(c.r * c.r - norm(pr - c.c));
	ps.push_back(pr + e * base);
	ps.push_back(pr - e * base);
	return ps;
}

inline vector<Point> get_cross_point_cs(Circle c, Segment s) {
	Line l(s);
	vector<Point> ps = get_cross_point_cl(c, l);
	if (intersect_cs(c, s) == 2) return ps;
	if (dot(l.p1 - ps[0], l.p2 - ps[0]) < 0) ps[1] = ps[0];
	else ps[0] = ps[1];
	return ps;
}

inline double arg(Vector p) { return atan2(p.y, p.x); }

inline Point polar(double r, double a) { return {cos(a) * r, sin(a) * r}; }

inline vector<Point> get_cross_point_cc(Circle c1, Circle c2) {
	double d = abs(c1.c - c2.c);
	double a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
	double t = arg(c2.c - c1.c);
	vector<Point> ps;
	ps.push_back(c1.c + polar(c1.r, t + a));
	ps.push_back(c1.c + polar(c1.r, t - a));
	return ps;
}

inline vector<Point> tangent_cp(Circle c, Point p) {
	return get_cross_point_cc(c, Circle(p, sqrt(norm(c.c - p) - c.r * c.r)));
}

inline vector<Line> tangent_cc(Circle c1, Circle c2) {
	vector<Line> ls;
	if (c1.r < c2.r) swap(c1, c2);
	double g = abs(c1.c - c2.c);
	if (equals(g, 0)) return ls;
	Point u = (c2.c - c1.c) / g;
	Point v = Point(-u.y, u.x);
	for (int s = 1; s >= -1; s -= 2) {
		double h = (c1.r + s * c2.r) / g;
		if (equals(1, h * h))
			ls.emplace_back(c1.c + u * c1.r, c1.c + (u + v) * c1.r);
		else if (1 - h * h > 0) {
			Point uu = u * h, vv = v * sqrt(1 - h * h);
			ls.emplace_back(c1.c + (uu + vv) * c1.r,
							c2.c - (uu + vv) * c2.r * s);
			ls.emplace_back(c1.c + (uu - vv) * c1.r,
							c2.c - (uu - vv) * c2.r * s);
		}
	}
	return ls;
}

inline Circle get_inscribed_circle(Point p1, Point p2, Point p3) {
	Circle ca{};
	double a = abs(p2 - p3), b = abs(p3 - p1), c = abs(p1 - p2);
	ca.c = (p1 * a + p2 * b + p3 * c) / (a + b + c);
	ca.r = get_distance_lp(Line(p1, p2), ca.c);
	return ca;
}

inline Circle get_circumscribed_circle(Point p1, Point p2, Point p3) {
	Circle ca{};
	Point m = (p1 + p2) / 2, n = (p2 + p3) / 2;
	ca.c = get_cross_point_ll(Line(m, m + Point((p2 - p1).y, (p1 - p2).x)),
							  Line(n, n + Point((p3 - p2).y, (p2 - p3).x)));
	ca.r = abs(ca.c - p1);
	return ca;
}

// IN:2,ON:1,OUT:0
inline int contains(Polygon g, Point p) {
	int const N = g.size();
	bool x = false;
	for (int i = 0; i < N; ++i) {
		Point a = g[i] - p, b = g[(i + 1) % N] - p;
		if (abs(cross(a, b)) < EPS && dot(a, b) < EPS) return 1;
		if (a.y > b.y) swap(a, b);
		if (a.y < EPS && EPS < b.y && cross(a, b) > EPS) x = !x;
	}
	return (x ? 2 : 0);
}

inline bool is_convex(Polygon p) {
	int const N = p.size();
	for (int i = 0; i < N; ++i)
		if (ccw(p[(i - 1 + N) % N], p[i], p[(i + 1) % N]) == CLOCKWISE)
			return false;
	return true;
}

inline Polygon convex_hull(Polygon p) {
	int const N = p.size();
	sort(p.begin(), p.end(), [](Point const &a, Point const &b) {
		return (a.y != b.y ? a.y < b.y : a.x < b.x);
	});
	Polygon a(2UL * N);
	int k = 0;
	for (int i = 0; i < N; ++i) {
		while (k > 1 && cross(a[k - 1] - a[k - 2], p[i] - a[k - 1]) < 0) k--;
		a[k++] = p[i];
	}
	for (int i = N - 2, t = k; i >= 0; --i) {
		while (k > t && cross(a[k - 1] - a[k - 2], p[i] - a[k - 1]) < 0) k--;
		a[k++] = p[i];
	}
	a.resize(k - 1);
	return a;
}

inline double area(Polygon p) {
	double res = 0;
	for (int i = 0; i < (int)p.size(); ++i)
		res += cross(p[i], p[(i + 1) % p.size()]) / 2.0;
	return res;
}

inline double area(Circle c1, Circle c2) {
	if (c1.r < c2.r) swap(c1, c2);
	int num = intersect_cc(c1, c2);
	if (num >= 3) return 0;
	if (num <= 1) return c2.r * c2.r * PI;
	double d = abs(c1.c - c2.c);
	double res = 0;
	for (int i = 0; i < 2; ++i) {
		double th =
			2 * acos((d * d + c1.r * c1.r - c2.r * c2.r) / (2 * d * c1.r));
		res += (th - sin(th)) * c1.r * c1.r / 2;
		swap(c1, c2);
	}
	return res;
}

inline double area(Polygon p, Circle c) {
	if (p.size() < 3) return 0;
	auto dfs = [&](auto self, Circle c, Point a, Point b) {
		Vector va = c.c - a, vb = c.c - b;
		double f = cross(va, vb), res = 0;
		if (equals(f, 0.0)) return res;
		if (max(abs(va), abs(vb)) < c.r + EPS) return f;
		Vector d(dot(va, vb), cross(va, vb));
		if (get_distance_sp(Segment(a, b), c.c) > c.r - EPS)
			return c.r * c.r * arg(d);
		auto u = get_cross_point_cs(c, Segment(a, b));
		if (u.empty()) return res;
		if (u.size() > 1 && dot(u[1] - u[0], a - u[0]) > 0) swap(u[0], u[1]);
		u.emplace(u.begin(), a);
		u.emplace_back(b);
		for (int i = 1; i < (int)u.size(); ++i)
			res += self(self, c, u[i - 1], u[i]);
		return res;
	};
	double res = 0;
	for (int i = 0; i < (int)p.size(); ++i)
		res += dfs(dfs, c, p[i], p[(i + 1) % p.size()]);
	return res / 2;
}

inline double convex_diameter(Polygon p) {
	int const N = p.size();
	if (N == 2) return abs(p[0] - p[1]);
	int i = 0, j = 0;
	for (int k = 0; k < N; ++k) {
		if (p[i] < p[k]) i = k;
		if (!(p[j] < p[k])) j = k;
	}
	double res = 0;
	int ti = i, tj = j;
	while (i != tj || j != ti) {
		res = max(res, abs(p[i] - p[j]));
		if (cross(p[(i + 1) % N] - p[i], p[(j + 1) % N] - p[j]) < 0.0)
			i = (i + 1) % N;
		else j = (j + 1) % N;
	}
	return res;
}

inline Polygon convex_cut(Polygon p, Line l) {
	Polygon q;
	for (int i = 0; i < (int)p.size(); ++i) {
		Point a = p[i], b = p[(i + 1) % p.size()];
		if (ccw(l.p1, l.p2, a) != CLOCKWISE) q.push_back(a);
		if (ccw(l.p1, l.p2, a) * ccw(l.p1, l.p2, b) < 0)
			q.push_back(get_cross_point_ll(Line(a, b), l));
	}
	return q;
}

inline double closest_pair(vector<Point> ps) {
	sort(ps.begin(), ps.end());
	vector<Point> a(ps.size());
	auto solve = [&](auto self, int l, int r) {
		if (r - l < 2) return 1e18;
		int mid = (l + r) >> 1;
		double x = ps[mid].x;
		double d = min(self(self, l, mid), self(self, mid, r));
		inplace_merge(ps.begin() + l,
					  ps.begin() + mid,
					  ps.begin() + r,
					  [](const Point &a, const Point &b) { return a.y < b.y; });
		int ptr = 0;
		for (int i = l; i < r; ++i) {
			if (abs(ps[i].x - x) >= d) continue;
			for (int j = 0; j < ptr; ++j) {
				Point luz = ps[i] - a[ptr - j - 1];
				if (luz.y >= d) break;
				d = min(d, abs(luz));
			}
			a[ptr++] = ps[i];
		}
		return d;
	};
	return solve(solve, 0, ps.size());
}

inline int manhattan_intersection(vector<Segment> ss) {
	int constexpr INF = numeric_limits<int>::max();
	int constexpr BOTTOM = 0, LEFT = 1, RIGHT = 2, TOP = 3;
	int const N = ss.size();
	vector<EndPoint> ep;
	for (int i = 0; i < N; ++i) {
		if (ss[i].p1.y == ss[i].p2.y) {
			if (ss[i].p1.x > ss[i].p2.x) swap(ss[i].p1, ss[i].p2);
			ep.emplace_back(ss[i].p1, i, LEFT);
			ep.emplace_back(ss[i].p2, i, RIGHT);
		} else {
			if (ss[i].p1.y > ss[i].p2.y) swap(ss[i].p1, ss[i].p2);
			ep.emplace_back(ss[i].p1, i, BOTTOM);
			ep.emplace_back(ss[i].p2, i, TOP);
		}
	}
	sort(ep.begin(), ep.end());
	set<int> st;
	st.insert(INF);
	int cnt = 0;
	for (int i = 0; i < 2 * N; ++i) {
		if (ep[i].st == TOP) st.erase(ep[i].p.x);
		else if (ep[i].st == BOTTOM) st.insert(ep[i].p.x);
		else if (ep[i].st == LEFT) {
			auto b = st.lower_bound(ss[ep[i].seg].p1.x);
			auto e = st.upper_bound(ss[ep[i].seg].p2.x);
			cnt += distance(b, e);
		}
	}
	return cnt;
}
