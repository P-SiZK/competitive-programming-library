#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstdio>

using namespace std;

//BEGIN
#define EPS 1e-10
#define equals(a, b) (fabs(a - b) < EPS)
#define Pi 3.141592653589793238

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

struct Point {
	double x, y;

	Point() {}
	Point(double x, double y) :x(x), y(y) {}

	Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
	Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
	Point operator*(const double& k) const { return Point(x * k, y * k); }
	Point operator/(const double& k) const { return Point(x / k, y / k); }

	bool operator==(const Point& p) const { return (fabs(x - p.x) < EPS && fabs(y - p.y) < EPS); }
	bool operator<(const Point& p) const { return (x != p.x ? x < p.x : y < p.y); }

	double norm() { return x * x + y * y; }
	double abs() { return sqrt(norm()); }
};

typedef Point Vector;

double norm(Vector a) { return a.x * a.x + a.y * a.y; }
double abs(Vector a) { return sqrt(norm(a)); }
double dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
double cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }

bool isParallel(Vector a, Vector b) { return equals(cross(a, b), 0.0); }
bool isOrthogonal(Vector a, Vector b) { return equals(dot(a, b), 0.0); }

struct EndPoint {
	Point p;
	int seg, st;

	EndPoint() {}
	EndPoint(Point p, int seg, int st) :p(p), seg(seg), st(st) {}

	bool operator<(const EndPoint& ep) const {
		if (p.y == ep.p.y) return st < ep.st;
		return p.y < ep.p.y;
	}
};

struct Segment {
	Point p1, p2;

	Segment() {}
	Segment(Point p1, Point p2) :p1(p1), p2(p2) {}
};

typedef Segment Line;

Point project(Segment s, Point p) {
	Vector base = s.p2 - s.p1;
	double r = dot(p - s.p1, base) / base.norm();
	return s.p1 + base * r;
}
Point reflect(Segment s, Point p) {
	return p + (project(s, p) - p) * 2.0;
}

struct Circle {
	Point c;
	double r;

	Circle() {}
	Circle(Point c, double r) :c(c), r(r) {}
};

typedef vector<Point> Polygon;

int ccw(Point p0, Point p1, Point p2) {
	Vector a = p1 - p0, b = p2 - p0;
	if (cross(a, b) > EPS) return COUNTER_CLOCKWISE;
	if (cross(a, b) < -EPS) return CLOCKWISE;
	if (dot(a, b) < -EPS) return ONLINE_BACK;
	if (a.norm() < b.norm()) return ONLINE_FRONT;
	return ON_SEGMENT;
}

bool intersectSS(Point p1, Point p2, Point p3, Point p4) {
	return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
			ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}
bool intersectSS(Segment s1, Segment s2) {
	return intersectSS(s1.p1, s1.p2, s2.p1, s2.p2);
}

double getDistanceLP(Line l, Point p) {
	return abs(cross(l.p2 - l.p1, p - l.p1) / abs(l.p2 - l.p1));
}

double getDistanceSP(Segment s, Point p) {
	if (dot(s.p2 - s.p1, p - s.p1) < 0.0) return abs(p - s.p1);
	if (dot(s.p1 - s.p2, p - s.p2) < 0.0) return abs(p - s.p2);
	return getDistanceLP(s, p);
}

double getDistanceSS(Segment s1, Segment s2) {
	if (intersectSS(s1, s2)) return 0.0;
	return min({ getDistanceSP(s1, s2.p1), getDistanceSP(s1, s2.p2),
			   getDistanceSP(s2, s1.p1), getDistanceSP(s2, s1.p2) });
}

Point getCrossPointLL(Line l1, Line l2) {
	double a = cross(l1.p2 - l1.p1, l2.p2 - l2.p1);
	double b = cross(l1.p2 - l1.p1, l1.p2 - l2.p1);
	if (abs(a) < EPS && abs(b) < EPS) return l2.p1;
	return l2.p1 + (l2.p2 - l2.p1) * (b / a);
}

Point getCrossPointSS(Segment s1, Segment s2) {
	Vector base = s2.p2 - s2.p1;
	double d1 = abs(cross(base, s1.p1 - s2.p1));
	double d2 = abs(cross(base, s1.p2 - s2.p1));
	return s1.p1 + (s1.p2 - s1.p1) * (d1 / (d1 + d2));
}

pair<Point, Point> getCrossPointCL(Circle c, Line l) {
	Vector pr = project(l, c.c);
	Vector e = (l.p2 - l.p1) / abs(l.p2 - l.p1);
	double base = sqrt(c.r * c.r - norm(pr - c.c));
	return make_pair(pr + e * base, pr - e * base);
}

double arg(Vector p) { return atan2(p.y, p.x); }
Point polar(double a, double r) { return Point(cos(r) * a, sin(r) * a); }

pair<Point, Point> getCrossPointCC(Circle c1, Circle c2) {
	double d = abs(c1.c - c2.c);
	double a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
	double t = arg(c2.c - c1.c);
	return make_pair(c1.c + polar(c1.r, t + a), c1.c + polar(c1.r, t - a));
}

// IN:2,ON:1,OUT:0
int contains(Polygon g, Point p) {
	int n = g.size();
	bool x = false;
	for (int i = 0; i < n; ++i) {
		Point a = g[i] - p, b = g[(i + 1) % n] - p;
		if (abs(cross(a, b)) < EPS && dot(a, b) < EPS) return 1;
		if (a.y > b.y) swap(a, b);
		if (a.y < EPS && EPS < b.y && cross(a, b) > EPS) x = !x;
	}
	return (x ? 2 : 0);
}

bool isConvex(Polygon p) {
	int n = p.size();
	for (int i = 0; i < n; ++i)
		if (ccw(p[(i - 1 + n) % n], p[i], p[(i + 1) % n]) == CLOCKWISE) return false;
	return true;
}

Polygon convexHull(Polygon p) {
	Polygon u, l;
	if (p.size() < 3) return p;
	sort(p.begin(), p.end());
	u.push_back(p[0]); u.push_back(p[1]);
	l.push_back(p[p.size() - 1]); l.push_back(p[p.size() - 2]);
	for (int i = 2; i < (int)p.size(); ++i) {
		for (int n = u.size(); n >= 2 && ccw(u[n - 2], u[n - 1], p[i]) == COUNTER_CLOCKWISE; --n)
			u.pop_back();
		u.push_back(p[i]);
	}
	for (int i = p.size() - 3; i >= 0; --i) {
		for (int n = l.size(); n >= 2 && ccw(l[n - 2], l[n - 1], p[i]) == COUNTER_CLOCKWISE; --n)
			l.pop_back();
		l.push_back(p[i]);
	}
	reverse(l.begin(), l.end());
	for (int i = u.size() - 2; i >= 1; --i) l.push_back(u[i]);
	return l;
}

double area(Polygon p) {
	double res = 0;
	for (int i = 0; i < (int)p.size(); ++i)
		res += cross(p[i], p[(i + 1) % p.size()]) / 2.0;
	return res;
}

double convexDiameter(Polygon p) {
	int n = p.size();
	if (n == 2) return abs(p[0] - p[1]);
	int i = 0, j = 0;
	for (int k = 0; k < n; ++k) {
		if (p[i] < p[k]) i = k;
		if (!(p[j] < p[k])) j = k;
	}
	double res = 0;
	int ti = i, tj = j;
	while (i != tj || j != ti) {
		res = max(res, abs(p[i] - p[j]));
		if (cross(p[(i + 1) % n] - p[i], p[(j + 1) % n] - p[j]) < 0.0)
			i = (i + 1) % n;
		else j = (j + 1) % n;
	}
	return res;
}

Polygon convexCut(Polygon p, Line l) {
	Polygon q;
	for (int i = 0; i < (int)p.size(); ++i) {
		Point a = p[i], b = p[(i + 1) % p.size()];
		if (ccw(l.p1, l.p2, a) != CLOCKWISE) q.push_back(a);
		if (ccw(l.p1, l.p2, a) * ccw(l.p1, l.p2, b) < 0)
			q.push_back(getCrossPointLL(Line(a, b), l));
	}
	return q;
}
//END

void CGL1A() {
	Segment s; cin >> s.p1.x >> s.p1.y >> s.p2.x >> s.p2.y;
	int q; cin >> q;
	while (q--) {
		Point p; cin >> p.x >> p.y;
		Point a = project(s, p);
		printf("%.10f %.10f\n", a.x, a.y);
	}
}
/*
	created: 2019-09-12
	https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_A
*/
void CGL1B() {
	Segment s; cin >> s.p1.x >> s.p1.y >> s.p2.x >> s.p2.y;
	int q; cin >> q;
	while (q--) {
		Point p; cin >> p.x >> p.y;
		Point a = reflect(s, p);
		printf("%.10f %.10f\n", a.x, a.y);
	}
}
/*
	created: 2019-09-12
	https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B
*/
void CGL1C() {
	Point p0, p1, p2; cin >> p0.x >> p0.y >> p1.x >> p1.y;
	int q; cin >> q;
	while (q--) {
		cin >> p2.x >> p2.y;
		int a = ccw(p0, p1, p2);
		if (a == COUNTER_CLOCKWISE) cout << "COUNTER_CLOCKWISE";
		else if (a == CLOCKWISE) cout << "CLOCKWISE";
		else if (a == ONLINE_BACK) cout << "ONLINE_BACK";
		else if (a == ONLINE_FRONT) cout << "ONLINE_FRONT";
		else cout << "ON_SEGMENT";
		cout << endl;
	}
}
/*
	created: 2019-09-12
	https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C
*/
void CGL2A() {
	int q; cin >> q;
	while (q--) {
		Point p0, p1, p2, p3;
		cin >> p0.x >> p0.y >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
		if (isParallel(p1 - p0, p3 - p2)) cout << 2;
		else if (isOrthogonal(p1 - p0, p3 - p2)) cout << 1;
		else cout << 0;
		cout << endl;
	}
}
/*
	created: 2019-09-12
	https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_A
*/
void CGL2B() {
	int q; cin >> q;
	while (q--) {
		Point p0, p1, p2, p3;
		cin >> p0.x >> p0.y >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
		cout << (intersectSS(p0, p1, p2, p3) ? 1 : 0) << endl;
	}
}/*
	created: 2019-09-12
	https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_B
*/
void CGL2C() {
	int q; cin >> q;
	while (q--) {
		Point p0, p1, p2, p3;
		cin >> p0.x >> p0.y >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
		Point a = getCrossPointLL(Segment(p0, p1), Segment(p2, p3));
		printf("%.10f %.10f\n", a.x, a.y);
	}
}
/*
	created: 2019-09-12
	https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_C
*/
void CGL2D() {
	int q; cin >> q;
	while (q--) {
		Point p0, p1, p2, p3;
		cin >> p0.x >> p0.y >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
		printf("%.10f\n", getDistanceSS(Segment(p0, p1), Segment(p2, p3)));
	}
}
/*
	created: 2019-09-12
	https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_D
*/
void CGL3A() {
	int n; cin >> n;
	Polygon p(n);
	for (auto& a : p) cin >> a.x >> a.y;
	printf("%.1f\n", area(p));
}
/*
	created: 2019-09-12
	https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_A
*/
void CGL3B() {
	int n; cin >> n;
	Polygon p(n);
	for (auto& a : p) cin >> a.x >> a.y;
	cout << (isConvex(p) ? 1 : 0) << endl;
}
/*
	created: 2019-09-12
	https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_B
*/
void CGL3C() {
	int n; cin >> n;
	Polygon g(n);
	for (auto& a : g) cin >> a.x >> a.y;
	int q; cin >> q;
	while (q--) {
		Point p; cin >> p.x >> p.y;
		cout << contains(g, p) << endl;
	}
}/*
	created: 2019-09-12
	https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_C
*/
void CGL4A() {
	int n; cin >> n;
	Polygon p(n);
	for (auto& a : p) cin >> a.x >> a.y;
	Polygon t = convexHull(p);
	cout << t.size() << endl;
	for (auto a : t) cout << a.x << " " << a.y << endl;
}
/*
	created: 2019-09-12
	https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_A
*/
void CGL4B() {
	int n; cin >> n;
	Polygon p(n);
	for (auto& a : p) cin >> a.x >> a.y;
	printf("%.10f\n", convexDiameter(p));
}
/*
	created: 2019-09-12
	https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_B
*/
void CGL4C() {
	int n; cin >> n;
	Polygon p(n);
	for (auto& a : p) cin >> a.x >> a.y;
	int q; cin >> q;
	while (q--) {
		Line l; cin >> l.p1.x >> l.p1.y >> l.p2.x >> l.p2.y;
		printf("%.10f\n", area(convexCut(p, l)));
	}
}
/*
	created: 2019-09-12
	https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_C
*/
void CGL5A() {

}
void CGL6A() {

}
void CGL7A() {

}
/*void CGL7B() {
	
}*/
/*void CGL7C() {
	
}*/
void CGL7D() {
	Circle c; cin >> c.c.x >> c.c.y >> c.r;
	int q; cin >> q;
	while (q--) {
		Line l; cin >> l.p1.x >> l.p1.y >> l.p2.x >> l.p2.y;
		auto a = getCrossPointCL(c, l);
		if (!(a.first < a.second)) swap(a.first, a.second);
		printf("%.10f %.10f %.10f %.10f\n", a.first.x, a.first.y, a.second.x, a.second.y);
	}
}
/*
	created: 2019-09-12
	https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_D
*/
void CGL7E() {
	Circle c1; cin >> c1.c.x >> c1.c.y >> c1.r;
	Circle c2; cin >> c2.c.x >> c2.c.y >> c2.r;
	auto a = getCrossPointCC(c1, c2);
	if (!(a.first < a.second)) swap(a.first, a.second);
	printf("%.10f %.10f %.10f %.10f\n", a.first.x, a.first.y, a.second.x, a.second.y);
}
/*
	created: 2019-09-12
	https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_E
*/
void CGL7F() {

}
void CGL7G() {

}
void CGL7H() {

}

int main() {
	//CGL1A();
	//CGL1B();
	//CGL1C();
	//CGL2A();
	//CGL2B();
	//CGL2C();
	//CGL2D();
	//CGL3A();
	//CGL3B();
	//CGL3C();
	//CGL4A();
	//CGL4B();
	//CGL4C();
	//CGL5A();
	//CGL6A();
	//CGL7A();
	//CGL7B();
	//CGL7C();
	//CGL7D();
	//CGL7E();
	//CGL7F();
	//CGL7G();
	//CGL7H();

	return 0;
}
