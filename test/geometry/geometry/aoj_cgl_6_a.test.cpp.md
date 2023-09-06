---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/geometry.hpp
    title: Geometry
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/6/CGL_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/6/CGL_6_A
  bundledCode: "#line 1 \"test/geometry/geometry/aoj_cgl_6_a.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/6/CGL_6_A\n\n\
    #line 1 \"src/geometry/geometry.hpp\"\n\n\n\n#include <algorithm>\n#include <cmath>\n\
    #include <iostream>\n#include <set>\n#include <vector>\n\ndouble constexpr EPS\
    \ = 1e-10;\ndouble constexpr PI = 3.14159265358979323846;\n\ninline bool equals(double\
    \ a, double b) { return std::abs(a - b) < EPS; }\n\nstatic int const COUNTER_CLOCKWISE\
    \ = 1;\nstatic int const CLOCKWISE = -1;\nstatic int const ONLINE_BACK = 2;\n\
    static int const ONLINE_FRONT = -2;\nstatic int const ON_SEGMENT = 0;\n\nstruct\
    \ Point {\n\tdouble x, y;\n\n\tPoint() = default;\n\n\tPoint(double x, double\
    \ y) : x(x), y(y) {}\n\n\tPoint operator+(Point const &p) const { return {x +\
    \ p.x, y + p.y}; }\n\n\tPoint operator-(Point const &p) const { return {x - p.x,\
    \ y - p.y}; }\n\n\tPoint operator*(double const &k) const { return {x * k, y *\
    \ k}; }\n\n\tPoint operator/(double const &k) const { return {x / k, y / k}; }\n\
    \n\tfriend std::istream &operator>>(std::istream &is, Point &p) {\n\t\tis >> p.x\
    \ >> p.y;\n\t\treturn is;\n\t}\n\n\tbool operator==(Point const &p) const {\n\t\
    \treturn (std::abs(x - p.x) < EPS && std::abs(y - p.y) < EPS);\n\t}\n\n\tbool\
    \ operator<(Point const &p) const { return (x != p.x ? x < p.x : y < p.y); }\n\
    \n\t[[nodiscard]] double norm() const { return x * x + y * y; }\n\n\t[[nodiscard]]\
    \ double abs() const { return std::sqrt(norm()); }\n};\n\nusing Vector = Point;\n\
    \ninline double dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }\n\n\
    inline double cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }\n\n\
    inline bool is_parallel(Vector a, Vector b) { return equals(cross(a, b), 0.0);\
    \ }\n\ninline bool is_orthogonal(Vector a, Vector b) { return equals(dot(a, b),\
    \ 0.0); }\n\nstruct EndPoint {\n\tPoint p;\n\tint seg, st;\n\n\tEndPoint() = default;\n\
    \n\tEndPoint(Point p, int seg, int st) : p(p), seg(seg), st(st) {}\n\n\tbool operator<(EndPoint\
    \ const &ep) const {\n\t\tif (p.y == ep.p.y) return st < ep.st;\n\t\treturn p.y\
    \ < ep.p.y;\n\t}\n};\n\nstruct Segment {\n\tPoint p1, p2;\n\n\tSegment() = default;\n\
    \n\tSegment(Point p1, Point p2) : p1(p1), p2(p2) {}\n\n\tfriend std::istream &operator>>(std::istream\
    \ &is, Segment &s) {\n\t\tis >> s.p1 >> s.p2;\n\t\treturn is;\n\t}\n};\n\nusing\
    \ Line = Segment;\n\ninline Point project(Segment s, Point p) {\n\tVector base\
    \ = s.p2 - s.p1;\n\tdouble r = dot(p - s.p1, base) / base.norm();\n\treturn s.p1\
    \ + base * r;\n}\n\ninline Point reflect(Segment s, Point p) { return p + (project(s,\
    \ p) - p) * 2.0; }\n\nstruct Circle {\n\tPoint c;\n\tdouble r;\n\n\tCircle() =\
    \ default;\n\n\tCircle(Point c, double r) : c(c), r(r) {}\n};\n\nusing Polygon\
    \ = std::vector<Point>;\n\ninline int ccw(Point p0, Point p1, Point p2) {\n\t\
    Vector a = p1 - p0, b = p2 - p0;\n\tif (cross(a, b) > EPS) return COUNTER_CLOCKWISE;\n\
    \tif (cross(a, b) < -EPS) return CLOCKWISE;\n\tif (dot(a, b) < -EPS) return ONLINE_BACK;\n\
    \tif (a.norm() < b.norm()) return ONLINE_FRONT;\n\treturn ON_SEGMENT;\n}\n\ninline\
    \ bool intersect_ss(Point p1, Point p2, Point p3, Point p4) {\n\treturn (ccw(p1,\
    \ p2, p3) * ccw(p1, p2, p4) <= 0 &&\n\t\t\tccw(p3, p4, p1) * ccw(p3, p4, p2) <=\
    \ 0);\n}\n\ninline bool intersect_ss(Segment s1, Segment s2) {\n\treturn intersect_ss(s1.p1,\
    \ s1.p2, s2.p1, s2.p2);\n}\n\ninline int intersect_cs(Circle c, Segment s) {\n\
    \tif ((project(s, c.c) - c.c).norm() - c.r * c.r > EPS) return 0;\n\tdouble d1\
    \ = (c.c - s.p1).abs(), d2 = (c.c - s.p2).abs();\n\tif (d1 < c.r + EPS && d2 <\
    \ c.r + EPS) return 0;\n\tif ((d1 < c.r - EPS && d2 > c.r + EPS) || (d1 > c.r\
    \ + EPS && d2 < c.r - EPS))\n\t\treturn 1;\n\tPoint h = project(s, c.c);\n\tif\
    \ (dot(s.p1 - h, s.p2 - h) < 0) return 2;\n\treturn 0;\n}\n\ninline int intersect_cc(Circle\
    \ c1, Circle c2) {\n\tif (c1.r < c2.r) std::swap(c1, c2);\n\tdouble d = (c1.c\
    \ - c2.c).abs();\n\tdouble r = c1.r + c2.r;\n\tif (equals(d, r)) return 3;\n\t\
    if (d > r) return 4;\n\tif (equals(d + c2.r, c1.r)) return 1;\n\tif (d + c2.r\
    \ < c1.r) return 0;\n\treturn 2;\n}\n\ninline double get_distance_lp(Line l, Point\
    \ p) {\n\treturn std::abs(cross(l.p2 - l.p1, p - l.p1) / (l.p2 - l.p1).abs());\n\
    }\n\ninline double get_distance_sp(Segment s, Point p) {\n\tif (dot(s.p2 - s.p1,\
    \ p - s.p1) < 0.0) return (p - s.p1).abs();\n\tif (dot(s.p1 - s.p2, p - s.p2)\
    \ < 0.0) return (p - s.p2).abs();\n\treturn get_distance_lp(s, p);\n}\n\ninline\
    \ double get_distance_ss(Segment s1, Segment s2) {\n\tif (intersect_ss(s1, s2))\
    \ return 0.0;\n\treturn std::min({get_distance_sp(s1, s2.p1),\n\t\t\t\t\t get_distance_sp(s1,\
    \ s2.p2),\n\t\t\t\t\t get_distance_sp(s2, s1.p1),\n\t\t\t\t\t get_distance_sp(s2,\
    \ s1.p2)});\n}\n\ninline Point get_cross_point_ll(Line l1, Line l2) {\n\tdouble\
    \ a = cross(l1.p2 - l1.p1, l2.p2 - l2.p1);\n\tdouble b = cross(l1.p2 - l1.p1,\
    \ l1.p2 - l2.p1);\n\tif (std::abs(a) < EPS && std::abs(b) < EPS) return l2.p1;\n\
    \treturn l2.p1 + (l2.p2 - l2.p1) * (b / a);\n}\n\ninline Point get_cross_point_ss(Segment\
    \ s1, Segment s2) {\n\tVector base = s2.p2 - s2.p1;\n\tdouble d1 = std::abs(cross(base,\
    \ s1.p1 - s2.p1));\n\tdouble d2 = std::abs(cross(base, s1.p2 - s2.p1));\n\treturn\
    \ s1.p1 + (s1.p2 - s1.p1) * (d1 / (d1 + d2));\n}\n\ninline std::vector<Point>\
    \ get_cross_point_cl(Circle c, Line l) {\n\tstd::vector<Point> ps;\n\tVector pr\
    \ = project(l, c.c);\n\tVector e = (l.p2 - l.p1) / (l.p2 - l.p1).abs();\n\tif\
    \ (equals(get_distance_lp(l, c.c), c.r)) return std::vector<Point>{pr, pr};\n\t\
    double base = std::sqrt(c.r * c.r - (pr - c.c).norm());\n\tps.push_back(pr + e\
    \ * base);\n\tps.push_back(pr - e * base);\n\treturn ps;\n}\n\ninline std::vector<Point>\
    \ get_cross_point_cs(Circle c, Segment s) {\n\tLine l(s);\n\tstd::vector<Point>\
    \ ps = get_cross_point_cl(c, l);\n\tif (intersect_cs(c, s) == 2) return ps;\n\t\
    if (dot(l.p1 - ps[0], l.p2 - ps[0]) < 0) ps[1] = ps[0];\n\telse ps[0] = ps[1];\n\
    \treturn ps;\n}\n\ninline double arg(Vector p) { return atan2(p.y, p.x); }\n\n\
    inline Point polar(double r, double a) { return {cos(a) * r, sin(a) * r}; }\n\n\
    inline std::vector<Point> get_cross_point_cc(Circle c1, Circle c2) {\n\tdouble\
    \ d = (c1.c - c2.c).abs();\n\tdouble a = acos((c1.r * c1.r + d * d - c2.r * c2.r)\
    \ / (2 * c1.r * d));\n\tdouble t = arg(c2.c - c1.c);\n\tstd::vector<Point> ps;\n\
    \tps.push_back(c1.c + polar(c1.r, t + a));\n\tps.push_back(c1.c + polar(c1.r,\
    \ t - a));\n\treturn ps;\n}\n\ninline std::vector<Point> tangent_cp(Circle c,\
    \ Point p) {\n\treturn get_cross_point_cc(c, Circle(p, std::sqrt((c.c - p).norm()\
    \ - c.r * c.r)));\n}\n\ninline std::vector<Line> tangent_cc(Circle c1, Circle\
    \ c2) {\n\tstd::vector<Line> ls;\n\tif (c1.r < c2.r) std::swap(c1, c2);\n\tdouble\
    \ g = (c1.c - c2.c).abs();\n\tif (equals(g, 0)) return ls;\n\tPoint u = (c2.c\
    \ - c1.c) / g;\n\tPoint v = Point(-u.y, u.x);\n\tfor (int s = 1; s >= -1; s -=\
    \ 2) {\n\t\tdouble h = (c1.r + s * c2.r) / g;\n\t\tif (equals(1, h * h)) ls.emplace_back(c1.c\
    \ + u * c1.r, c1.c + (u + v) * c1.r);\n\t\telse if (1 - h * h > 0) {\n\t\t\tPoint\
    \ uu = u * h, vv = v * std::sqrt(1 - h * h);\n\t\t\tls.emplace_back(c1.c + (uu\
    \ + vv) * c1.r, c2.c - (uu + vv) * c2.r * s);\n\t\t\tls.emplace_back(c1.c + (uu\
    \ - vv) * c1.r, c2.c - (uu - vv) * c2.r * s);\n\t\t}\n\t}\n\treturn ls;\n}\n\n\
    inline Circle get_inscribed_circle(Point p1, Point p2, Point p3) {\n\tCircle ca{};\n\
    \tdouble a = (p2 - p3).abs(), b = (p3 - p1).abs(), c = (p1 - p2).abs();\n\tca.c\
    \ = (p1 * a + p2 * b + p3 * c) / (a + b + c);\n\tca.r = get_distance_lp(Line(p1,\
    \ p2), ca.c);\n\treturn ca;\n}\n\ninline Circle get_circumscribed_circle(Point\
    \ p1, Point p2, Point p3) {\n\tCircle ca{};\n\tPoint m = (p1 + p2) / 2, n = (p2\
    \ + p3) / 2;\n\tca.c = get_cross_point_ll(Line(m, m + Point((p2 - p1).y, (p1 -\
    \ p2).x)),\n\t\t\t\t\t\t\t  Line(n, n + Point((p3 - p2).y, (p2 - p3).x)));\n\t\
    ca.r = (ca.c - p1).abs();\n\treturn ca;\n}\n\n// IN:2,ON:1,OUT:0\ninline int contains(Polygon\
    \ g, Point p) {\n\tint const N = g.size();\n\tbool x = false;\n\tfor (int i =\
    \ 0; i < N; ++i) {\n\t\tPoint a = g[i] - p, b = g[(i + 1) % N] - p;\n\t\tif (std::abs(cross(a,\
    \ b)) < EPS && dot(a, b) < EPS) return 1;\n\t\tif (a.y > b.y) std::swap(a, b);\n\
    \t\tif (a.y < EPS && EPS < b.y && cross(a, b) > EPS) x = !x;\n\t}\n\treturn (x\
    \ ? 2 : 0);\n}\n\ninline bool is_convex(Polygon p) {\n\tint const N = p.size();\n\
    \tfor (int i = 0; i < N; ++i)\n\t\tif (ccw(p[(i - 1 + N) % N], p[i], p[(i + 1)\
    \ % N]) == CLOCKWISE) return false;\n\treturn true;\n}\n\ninline Polygon convex_hull(Polygon\
    \ p) {\n\tint const N = p.size();\n\tstd::sort(p.begin(), p.end(), [](Point const\
    \ &a, Point const &b) {\n\t\treturn (a.y != b.y ? a.y < b.y : a.x < b.x);\n\t\
    });\n\tPolygon a(2UL * N);\n\tint k = 0;\n\tfor (int i = 0; i < N; ++i) {\n\t\t\
    while (k > 1 && cross(a[k - 1] - a[k - 2], p[i] - a[k - 1]) < 0) k--;\n\t\ta[k++]\
    \ = p[i];\n\t}\n\tfor (int i = N - 2, t = k; i >= 0; --i) {\n\t\twhile (k > t\
    \ && cross(a[k - 1] - a[k - 2], p[i] - a[k - 1]) < 0) k--;\n\t\ta[k++] = p[i];\n\
    \t}\n\ta.resize(k - 1);\n\treturn a;\n}\n\ninline double area(Polygon p) {\n\t\
    double res = 0;\n\tfor (int i = 0; i < (int)p.size(); ++i)\n\t\tres += cross(p[i],\
    \ p[(i + 1) % p.size()]) / 2.0;\n\treturn res;\n}\n\ninline double area(Circle\
    \ c1, Circle c2) {\n\tif (c1.r < c2.r) std::swap(c1, c2);\n\tint num = intersect_cc(c1,\
    \ c2);\n\tif (num >= 3) return 0;\n\tif (num <= 1) return c2.r * c2.r * PI;\n\t\
    double d = (c1.c - c2.c).abs();\n\tdouble res = 0;\n\tfor (int i = 0; i < 2; ++i)\
    \ {\n\t\tdouble th = 2 * acos((d * d + c1.r * c1.r - c2.r * c2.r) / (2 * d * c1.r));\n\
    \t\tres += (th - sin(th)) * c1.r * c1.r / 2;\n\t\tstd::swap(c1, c2);\n\t}\n\t\
    return res;\n}\n\ninline double area(Polygon p, Circle c) {\n\tif (p.size() <\
    \ 3) return 0;\n\tauto dfs = [&](auto self, Circle c, Point a, Point b) {\n\t\t\
    Vector va = c.c - a, vb = c.c - b;\n\t\tdouble f = cross(va, vb), res = 0;\n\t\
    \tif (equals(f, 0.0)) return res;\n\t\tif (std::max(va.abs(), vb.abs()) < c.r\
    \ + EPS) return f;\n\t\tVector d(dot(va, vb), cross(va, vb));\n\t\tif (get_distance_sp(Segment(a,\
    \ b), c.c) > c.r - EPS) return c.r * c.r * arg(d);\n\t\tauto u = get_cross_point_cs(c,\
    \ Segment(a, b));\n\t\tif (u.empty()) return res;\n\t\tif (u.size() > 1 && dot(u[1]\
    \ - u[0], a - u[0]) > 0) std::swap(u[0], u[1]);\n\t\tu.emplace(u.begin(), a);\n\
    \t\tu.emplace_back(b);\n\t\tfor (int i = 1; i < (int)u.size(); ++i) res += self(self,\
    \ c, u[i - 1], u[i]);\n\t\treturn res;\n\t};\n\tdouble res = 0;\n\tfor (int i\
    \ = 0; i < (int)p.size(); ++i)\n\t\tres += dfs(dfs, c, p[i], p[(i + 1) % p.size()]);\n\
    \treturn res / 2;\n}\n\ninline double convex_diameter(Polygon p) {\n\tint const\
    \ N = p.size();\n\tif (N == 2) return (p[0] - p[1]).abs();\n\tint i = 0, j = 0;\n\
    \tfor (int k = 0; k < N; ++k) {\n\t\tif (p[i] < p[k]) i = k;\n\t\tif (!(p[j] <\
    \ p[k])) j = k;\n\t}\n\tdouble res = 0;\n\tint ti = i, tj = j;\n\twhile (i !=\
    \ tj || j != ti) {\n\t\tres = std::max(res, (p[i] - p[j]).abs());\n\t\tif (cross(p[(i\
    \ + 1) % N] - p[i], p[(j + 1) % N] - p[j]) < 0.0) i = (i + 1) % N;\n\t\telse j\
    \ = (j + 1) % N;\n\t}\n\treturn res;\n}\n\ninline Polygon convex_cut(Polygon p,\
    \ Line l) {\n\tPolygon q;\n\tfor (int i = 0; i < (int)p.size(); ++i) {\n\t\tPoint\
    \ a = p[i], b = p[(i + 1) % p.size()];\n\t\tif (ccw(l.p1, l.p2, a) != CLOCKWISE)\
    \ q.push_back(a);\n\t\tif (ccw(l.p1, l.p2, a) * ccw(l.p1, l.p2, b) < 0)\n\t\t\t\
    q.push_back(get_cross_point_ll(Line(a, b), l));\n\t}\n\treturn q;\n}\n\ninline\
    \ double closest_pair(std::vector<Point> ps) {\n\tstd::sort(ps.begin(), ps.end());\n\
    \tstd::vector<Point> a(ps.size());\n\tauto solve = [&](auto self, int l, int r)\
    \ {\n\t\tif (r - l < 2) return 1e18;\n\t\tint mid = (l + r) >> 1;\n\t\tdouble\
    \ x = ps[mid].x;\n\t\tdouble d = std::min(self(self, l, mid), self(self, mid,\
    \ r));\n\t\tinplace_merge(ps.begin() + l,\n\t\t\t\t\t  ps.begin() + mid,\n\t\t\
    \t\t\t  ps.begin() + r,\n\t\t\t\t\t  [](const Point &a, const Point &b) { return\
    \ a.y < b.y; });\n\t\tint ptr = 0;\n\t\tfor (int i = l; i < r; ++i) {\n\t\t\t\
    if (std::abs(ps[i].x - x) >= d) continue;\n\t\t\tfor (int j = 0; j < ptr; ++j)\
    \ {\n\t\t\t\tPoint luz = ps[i] - a[ptr - j - 1];\n\t\t\t\tif (luz.y >= d) break;\n\
    \t\t\t\td = std::min(d, luz.abs());\n\t\t\t}\n\t\t\ta[ptr++] = ps[i];\n\t\t}\n\
    \t\treturn d;\n\t};\n\treturn solve(solve, 0, ps.size());\n}\n\ninline int manhattan_intersection(std::vector<Segment>\
    \ ss) {\n\tint constexpr INF = std::numeric_limits<int>::max();\n\tint constexpr\
    \ BOTTOM = 0, LEFT = 1, RIGHT = 2, TOP = 3;\n\tint const N = ss.size();\n\tstd::vector<EndPoint>\
    \ ep;\n\tfor (int i = 0; i < N; ++i) {\n\t\tif (ss[i].p1.y == ss[i].p2.y) {\n\t\
    \t\tif (ss[i].p1.x > ss[i].p2.x) std::swap(ss[i].p1, ss[i].p2);\n\t\t\tep.emplace_back(ss[i].p1,\
    \ i, LEFT);\n\t\t\tep.emplace_back(ss[i].p2, i, RIGHT);\n\t\t} else {\n\t\t\t\
    if (ss[i].p1.y > ss[i].p2.y) std::swap(ss[i].p1, ss[i].p2);\n\t\t\tep.emplace_back(ss[i].p1,\
    \ i, BOTTOM);\n\t\t\tep.emplace_back(ss[i].p2, i, TOP);\n\t\t}\n\t}\n\tstd::sort(ep.begin(),\
    \ ep.end());\n\tstd::set<int> st;\n\tst.insert(INF);\n\tint cnt = 0;\n\tfor (int\
    \ i = 0; i < 2 * N; ++i) {\n\t\tif (ep[i].st == TOP) st.erase(ep[i].p.x);\n\t\t\
    else if (ep[i].st == BOTTOM) st.insert(ep[i].p.x);\n\t\telse if (ep[i].st == LEFT)\
    \ {\n\t\t\tauto b = st.lower_bound(ss[ep[i].seg].p1.x);\n\t\t\tauto e = st.upper_bound(ss[ep[i].seg].p2.x);\n\
    \t\t\tcnt += std::distance(b, e);\n\t\t}\n\t}\n\treturn cnt;\n}\n\n\n#line 4 \"\
    test/geometry/geometry/aoj_cgl_6_a.test.cpp\"\n\n#line 7 \"test/geometry/geometry/aoj_cgl_6_a.test.cpp\"\
    \n\nusing namespace std;\n\nint main() {\n\tint n;\n\tcin >> n;\n\tvector<Segment>\
    \ ss(n);\n\tfor (auto &a : ss) cin >> a;\n\tcout << manhattan_intersection(ss)\
    \ << endl;\n\n\treturn 0;\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/6/CGL_6_A\n\
    \n#include \"src/geometry/geometry.hpp\"\n\n#include <iostream>\n#include <vector>\n\
    \nusing namespace std;\n\nint main() {\n\tint n;\n\tcin >> n;\n\tvector<Segment>\
    \ ss(n);\n\tfor (auto &a : ss) cin >> a;\n\tcout << manhattan_intersection(ss)\
    \ << endl;\n\n\treturn 0;\n}\n"
  dependsOn:
  - src/geometry/geometry.hpp
  isVerificationFile: true
  path: test/geometry/geometry/aoj_cgl_6_a.test.cpp
  requiredBy: []
  timestamp: '2023-09-06 15:21:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/geometry/aoj_cgl_6_a.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/geometry/aoj_cgl_6_a.test.cpp
- /verify/test/geometry/geometry/aoj_cgl_6_a.test.cpp.html
title: test/geometry/geometry/aoj_cgl_6_a.test.cpp
---
