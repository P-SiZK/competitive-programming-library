---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/geometry/geometry.cpp
    title: src/geometry/geometry.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_B
  bundledCode: "#line 1 \"test/geometry/geometry/cgl_2_b.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_B\n\n\
    #line 1 \"src/geometry/geometry.cpp\"\n#include <algorithm>\n#include <cmath>\n\
    #include <iostream>\n#include <set>\n#include <vector>\n\nusing namespace std;\n\
    \nconst double EPS = 1e-10;\nconst double PI = acos(-1);\n\nbool equals(double\
    \ a, double b) { return fabs(a - b) < EPS; }\n\nstatic const int COUNTER_CLOCKWISE\
    \ = 1;\nstatic const int CLOCKWISE = -1;\nstatic const int ONLINE_BACK = 2;\n\
    static const int ONLINE_FRONT = -2;\nstatic const int ON_SEGMENT = 0;\n\nstruct\
    \ Point {\n\tdouble x, y;\n\n\tPoint() = default;\n\n\tPoint(double x, double\
    \ y) : x(x), y(y) {}\n\n\tPoint operator+(const Point &p) const { return {x +\
    \ p.x, y + p.y}; }\n\n\tPoint operator-(const Point &p) const { return {x - p.x,\
    \ y - p.y}; }\n\n\tPoint operator*(const double &k) const { return {x * k, y *\
    \ k}; }\n\n\tPoint operator/(const double &k) const { return {x / k, y / k}; }\n\
    \n\tfriend istream &operator>>(istream &is, Point &p) {\n\t\tis >> p.x >> p.y;\n\
    \t\treturn is;\n\t}\n\n\tbool operator==(const Point &p) const {\n\t\treturn (fabs(x\
    \ - p.x) < EPS && fabs(y - p.y) < EPS);\n\t}\n\n\tbool operator<(const Point &p)\
    \ const {\n\t\treturn (x != p.x ? x < p.x : y < p.y);\n\t}\n\n\tdouble norm()\
    \ { return x * x + y * y; }\n\n\tdouble abs() { return sqrt(norm()); }\n};\n\n\
    using Vector = Point;\n\ndouble norm(Vector a) { return a.x * a.x + a.y * a.y;\
    \ }\n\ndouble abs(Vector a) { return sqrt(norm(a)); }\n\ndouble dot(Vector a,\
    \ Vector b) { return a.x * b.x + a.y * b.y; }\n\ndouble cross(Vector a, Vector\
    \ b) { return a.x * b.y - a.y * b.x; }\n\nbool isParallel(Vector a, Vector b)\
    \ { return equals(cross(a, b), 0.0); }\n\nbool isOrthogonal(Vector a, Vector b)\
    \ { return equals(dot(a, b), 0.0); }\n\nstruct EndPoint {\n\tPoint p;\n\tint seg,\
    \ st;\n\n\tEndPoint() = default;\n\n\tEndPoint(Point p, int seg, int st) : p(p),\
    \ seg(seg), st(st) {}\n\n\tbool operator<(const EndPoint &ep) const {\n\t\tif\
    \ (p.y == ep.p.y) return st < ep.st;\n\t\treturn p.y < ep.p.y;\n\t}\n};\n\nstruct\
    \ Segment {\n\tPoint p1, p2;\n\n\tSegment() = default;\n\n\tSegment(Point p1,\
    \ Point p2) : p1(p1), p2(p2) {}\n\n\tfriend istream &operator>>(istream &is, Segment\
    \ &s) {\n\t\tis >> s.p1 >> s.p2;\n\t\treturn is;\n\t}\n};\n\nusing Line = Segment;\n\
    \nPoint project(Segment s, Point p) {\n\tVector base = s.p2 - s.p1;\n\tdouble\
    \ r = dot(p - s.p1, base) / base.norm();\n\treturn s.p1 + base * r;\n}\n\nPoint\
    \ reflect(Segment s, Point p) { return p + (project(s, p) - p) * 2.0; }\n\nstruct\
    \ Circle {\n\tPoint c;\n\tdouble r;\n\n\tCircle() = default;\n\n\tCircle(Point\
    \ c, double r) : c(c), r(r) {}\n};\n\nusing Polygon = vector<Point>;\n\nint ccw(Point\
    \ p0, Point p1, Point p2) {\n\tVector a = p1 - p0, b = p2 - p0;\n\tif (cross(a,\
    \ b) > EPS) return COUNTER_CLOCKWISE;\n\tif (cross(a, b) < -EPS) return CLOCKWISE;\n\
    \tif (dot(a, b) < -EPS) return ONLINE_BACK;\n\tif (a.norm() < b.norm()) return\
    \ ONLINE_FRONT;\n\treturn ON_SEGMENT;\n}\n\nbool intersectSS(Point p1, Point p2,\
    \ Point p3, Point p4) {\n\treturn (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&\n\
    \t\t\tccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);\n}\n\nbool intersectSS(Segment\
    \ s1, Segment s2) {\n\treturn intersectSS(s1.p1, s1.p2, s2.p1, s2.p2);\n}\n\n\
    int intersectCS(Circle c, Segment s) {\n\tif (norm(project(s, c.c) - c.c) - c.r\
    \ * c.r > EPS) return 0;\n\tdouble d1 = abs(c.c - s.p1), d2 = abs(c.c - s.p2);\n\
    \tif (d1 < c.r + EPS && d2 < c.r + EPS) return 0;\n\tif ((d1 < c.r - EPS && d2\
    \ > c.r + EPS) ||\n\t\t(d1 > c.r + EPS && d2 < c.r - EPS))\n\t\treturn 1;\n\t\
    Point h = project(s, c.c);\n\tif (dot(s.p1 - h, s.p2 - h) < 0) return 2;\n\treturn\
    \ 0;\n}\n\nint intersectCC(Circle c1, Circle c2) {\n\tif (c1.r < c2.r) swap(c1,\
    \ c2);\n\tdouble d = abs(c1.c - c2.c);\n\tdouble r = c1.r + c2.r;\n\tif (equals(d,\
    \ r)) return 3;\n\tif (d > r) return 4;\n\tif (equals(d + c2.r, c1.r)) return\
    \ 1;\n\tif (d + c2.r < c1.r) return 0;\n\treturn 2;\n}\n\ndouble getDistanceLP(Line\
    \ l, Point p) {\n\treturn abs(cross(l.p2 - l.p1, p - l.p1) / abs(l.p2 - l.p1));\n\
    }\n\ndouble getDistanceSP(Segment s, Point p) {\n\tif (dot(s.p2 - s.p1, p - s.p1)\
    \ < 0.0) return abs(p - s.p1);\n\tif (dot(s.p1 - s.p2, p - s.p2) < 0.0) return\
    \ abs(p - s.p2);\n\treturn getDistanceLP(s, p);\n}\n\ndouble getDistanceSS(Segment\
    \ s1, Segment s2) {\n\tif (intersectSS(s1, s2)) return 0.0;\n\treturn min({getDistanceSP(s1,\
    \ s2.p1),\n\t\t\t\tgetDistanceSP(s1, s2.p2),\n\t\t\t\tgetDistanceSP(s2, s1.p1),\n\
    \t\t\t\tgetDistanceSP(s2, s1.p2)});\n}\n\nPoint getCrossPointLL(Line l1, Line\
    \ l2) {\n\tdouble a = cross(l1.p2 - l1.p1, l2.p2 - l2.p1);\n\tdouble b = cross(l1.p2\
    \ - l1.p1, l1.p2 - l2.p1);\n\tif (abs(a) < EPS && abs(b) < EPS) return l2.p1;\n\
    \treturn l2.p1 + (l2.p2 - l2.p1) * (b / a);\n}\n\nPoint getCrossPointSS(Segment\
    \ s1, Segment s2) {\n\tVector base = s2.p2 - s2.p1;\n\tdouble d1 = abs(cross(base,\
    \ s1.p1 - s2.p1));\n\tdouble d2 = abs(cross(base, s1.p2 - s2.p1));\n\treturn s1.p1\
    \ + (s1.p2 - s1.p1) * (d1 / (d1 + d2));\n}\n\nvector<Point> getCrossPointCL(Circle\
    \ c, Line l) {\n\tvector<Point> ps;\n\tVector pr = project(l, c.c);\n\tVector\
    \ e = (l.p2 - l.p1) / abs(l.p2 - l.p1);\n\tif (equals(getDistanceLP(l, c.c), c.r))\
    \ return vector<Point>{pr, pr};\n\tdouble base = sqrt(c.r * c.r - norm(pr - c.c));\n\
    \tps.push_back(pr + e * base);\n\tps.push_back(pr - e * base);\n\treturn ps;\n\
    }\n\nvector<Point> getCrossPointCS(Circle c, Segment s) {\n\tLine l(s);\n\tvector<Point>\
    \ ps = getCrossPointCL(c, l);\n\tif (intersectCS(c, s) == 2) return ps;\n\tif\
    \ (dot(l.p1 - ps[0], l.p2 - ps[0]) < 0) ps[1] = ps[0];\n\telse ps[0] = ps[1];\n\
    \treturn ps;\n}\n\ndouble arg(Vector p) { return atan2(p.y, p.x); }\n\nPoint polar(double\
    \ r, double a) { return {cos(a) * r, sin(a) * r}; }\n\nvector<Point> getCrossPointCC(Circle\
    \ c1, Circle c2) {\n\tdouble d = abs(c1.c - c2.c);\n\tdouble a = acos((c1.r *\
    \ c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));\n\tdouble t = arg(c2.c - c1.c);\n\
    \tvector<Point> ps;\n\tps.push_back(c1.c + polar(c1.r, t + a));\n\tps.push_back(c1.c\
    \ + polar(c1.r, t - a));\n\treturn ps;\n}\n\nvector<Point> tangentCP(Circle c,\
    \ Point p) {\n\treturn getCrossPointCC(c, Circle(p, sqrt(norm(c.c - p) - c.r *\
    \ c.r)));\n}\n\nvector<Line> tangentCC(Circle c1, Circle c2) {\n\tvector<Line>\
    \ ls;\n\tif (c1.r < c2.r) swap(c1, c2);\n\tdouble g = abs(c1.c - c2.c);\n\tif\
    \ (equals(g, 0)) return ls;\n\tPoint u = (c2.c - c1.c) / g;\n\tPoint v = Point(-u.y,\
    \ u.x);\n\tfor (int s = 1; s >= -1; s -= 2) {\n\t\tdouble h = (c1.r + s * c2.r)\
    \ / g;\n\t\tif (equals(1, h * h))\n\t\t\tls.emplace_back(c1.c + u * c1.r, c1.c\
    \ + (u + v) * c1.r);\n\t\telse if (1 - h * h > 0) {\n\t\t\tPoint uu = u * h, vv\
    \ = v * sqrt(1 - h * h);\n\t\t\tls.emplace_back(c1.c + (uu + vv) * c1.r,\n\t\t\
    \t\t\t\t\tc2.c - (uu + vv) * c2.r * s);\n\t\t\tls.emplace_back(c1.c + (uu - vv)\
    \ * c1.r,\n\t\t\t\t\t\t\tc2.c - (uu - vv) * c2.r * s);\n\t\t}\n\t}\n\treturn ls;\n\
    }\n\nCircle getInscribedCircle(Point p1, Point p2, Point p3) {\n\tCircle ca;\n\
    \tdouble a = abs(p2 - p3), b = abs(p3 - p1), c = abs(p1 - p2);\n\tca.c = (p1 *\
    \ a + p2 * b + p3 * c) / (a + b + c);\n\tca.r = getDistanceLP(Line(p1, p2), ca.c);\n\
    \treturn ca;\n}\n\nCircle getCircumscribedCircle(Point p1, Point p2, Point p3)\
    \ {\n\tCircle ca;\n\tPoint m = (p1 + p2) / 2, n = (p2 + p3) / 2;\n\tca.c = getCrossPointLL(Line(m,\
    \ m + Point((p2 - p1).y, (p1 - p2).x)),\n\t\t\t\t\t\t   Line(n, n + Point((p3\
    \ - p2).y, (p2 - p3).x)));\n\tca.r = abs(ca.c - p1);\n\treturn ca;\n}\n\n// IN:2,ON:1,OUT:0\n\
    int contains(Polygon g, Point p) {\n\tint n = g.size();\n\tbool x = false;\n\t\
    for (int i = 0; i < n; ++i) {\n\t\tPoint a = g[i] - p, b = g[(i + 1) % n] - p;\n\
    \t\tif (abs(cross(a, b)) < EPS && dot(a, b) < EPS) return 1;\n\t\tif (a.y > b.y)\
    \ swap(a, b);\n\t\tif (a.y < EPS && EPS < b.y && cross(a, b) > EPS) x = !x;\n\t\
    }\n\treturn (x ? 2 : 0);\n}\n\nbool isConvex(Polygon p) {\n\tint n = p.size();\n\
    \tfor (int i = 0; i < n; ++i)\n\t\tif (ccw(p[(i - 1 + n) % n], p[i], p[(i + 1)\
    \ % n]) == CLOCKWISE)\n\t\t\treturn false;\n\treturn true;\n}\n\nPolygon convexHull(Polygon\
    \ p) {\n\tint n = p.size();\n\tsort(p.begin(), p.end(), [](const Point &a, const\
    \ Point &b) {\n\t\treturn (a.y != b.y ? a.y < b.y : a.x < b.x);\n\t});\n\tPolygon\
    \ a(2 * n);\n\tint k = 0;\n\tfor (int i = 0; i < n; ++i) {\n\t\twhile (k > 1 &&\
    \ cross(a[k - 1] - a[k - 2], p[i] - a[k - 1]) < 0) k--;\n\t\ta[k++] = p[i];\n\t\
    }\n\tfor (int i = n - 2, t = k; i >= 0; --i) {\n\t\twhile (k > t && cross(a[k\
    \ - 1] - a[k - 2], p[i] - a[k - 1]) < 0) k--;\n\t\ta[k++] = p[i];\n\t}\n\ta.resize(k\
    \ - 1);\n\treturn a;\n}\n\ndouble area(Polygon p) {\n\tdouble res = 0;\n\tfor\
    \ (int i = 0; i < (int)p.size(); ++i)\n\t\tres += cross(p[i], p[(i + 1) % p.size()])\
    \ / 2.0;\n\treturn res;\n}\n\ndouble area(Circle c1, Circle c2) {\n\tif (c1.r\
    \ < c2.r) swap(c1, c2);\n\tint num = intersectCC(c1, c2);\n\tif (num >= 3) return\
    \ 0;\n\tif (num <= 1) return c2.r * c2.r * PI;\n\tdouble d = abs(c1.c - c2.c);\n\
    \tdouble res = 0;\n\tfor (int i = 0; i < 2; ++i) {\n\t\tdouble th =\n\t\t\t2 *\
    \ acos((d * d + c1.r * c1.r - c2.r * c2.r) / (2 * d * c1.r));\n\t\tres += (th\
    \ - sin(th)) * c1.r * c1.r / 2;\n\t\tswap(c1, c2);\n\t}\n\treturn res;\n}\n\n\
    double area(Polygon p, Circle c) {\n\tif (p.size() < 3) return 0;\n\tauto dfs\
    \ = [&](auto self, Circle c, Point a, Point b) {\n\t\tVector va = c.c - a, vb\
    \ = c.c - b;\n\t\tdouble f = cross(va, vb), res = 0;\n\t\tif (equals(f, 0.0))\
    \ return res;\n\t\tif (max(abs(va), abs(vb)) < c.r + EPS) return f;\n\t\tVector\
    \ d(dot(va, vb), cross(va, vb));\n\t\tif (getDistanceSP(Segment(a, b), c.c) >\
    \ c.r - EPS)\n\t\t\treturn c.r * c.r * arg(d);\n\t\tauto u = getCrossPointCS(c,\
    \ Segment(a, b));\n\t\tif (u.empty()) return res;\n\t\tif (u.size() > 1 && dot(u[1]\
    \ - u[0], a - u[0]) > 0) swap(u[0], u[1]);\n\t\tu.emplace(u.begin(), a);\n\t\t\
    u.emplace_back(b);\n\t\tfor (int i = 1; i < (int)u.size(); ++i)\n\t\t\tres +=\
    \ self(self, c, u[i - 1], u[i]);\n\t\treturn res;\n\t};\n\tdouble res = 0;\n\t\
    for (int i = 0; i < (int)p.size(); ++i)\n\t\tres += dfs(dfs, c, p[i], p[(i + 1)\
    \ % p.size()]);\n\treturn res / 2;\n}\n\ndouble convexDiameter(Polygon p) {\n\t\
    int n = p.size();\n\tif (n == 2) return abs(p[0] - p[1]);\n\tint i = 0, j = 0;\n\
    \tfor (int k = 0; k < n; ++k) {\n\t\tif (p[i] < p[k]) i = k;\n\t\tif (!(p[j] <\
    \ p[k])) j = k;\n\t}\n\tdouble res = 0;\n\tint ti = i, tj = j;\n\twhile (i !=\
    \ tj || j != ti) {\n\t\tres = max(res, abs(p[i] - p[j]));\n\t\tif (cross(p[(i\
    \ + 1) % n] - p[i], p[(j + 1) % n] - p[j]) < 0.0)\n\t\t\ti = (i + 1) % n;\n\t\t\
    else j = (j + 1) % n;\n\t}\n\treturn res;\n}\n\nPolygon convexCut(Polygon p, Line\
    \ l) {\n\tPolygon q;\n\tfor (int i = 0; i < (int)p.size(); ++i) {\n\t\tPoint a\
    \ = p[i], b = p[(i + 1) % p.size()];\n\t\tif (ccw(l.p1, l.p2, a) != CLOCKWISE)\
    \ q.push_back(a);\n\t\tif (ccw(l.p1, l.p2, a) * ccw(l.p1, l.p2, b) < 0)\n\t\t\t\
    q.push_back(getCrossPointLL(Line(a, b), l));\n\t}\n\treturn q;\n}\n\ndouble closestPair(vector<Point>\
    \ ps) {\n\tsort(ps.begin(), ps.end());\n\tvector<Point> a(ps.size());\n\tauto\
    \ solve = [&](auto self, int l, int r) {\n\t\tif (r - l < 2) return 1e18;\n\t\t\
    int mid = (l + r) >> 1;\n\t\tdouble x = ps[mid].x;\n\t\tdouble d = min(self(self,\
    \ l, mid), self(self, mid, r));\n\t\tinplace_merge(ps.begin() + l,\n\t\t\t\t\t\
    \  ps.begin() + mid,\n\t\t\t\t\t  ps.begin() + r,\n\t\t\t\t\t  [](const Point\
    \ &a, const Point &b) { return a.y < b.y; });\n\t\tint ptr = 0;\n\t\tfor (int\
    \ i = l; i < r; ++i) {\n\t\t\tif (abs(ps[i].x - x) >= d) continue;\n\t\t\tfor\
    \ (int j = 0; j < ptr; ++j) {\n\t\t\t\tPoint luz = ps[i] - a[ptr - j - 1];\n\t\
    \t\t\tif (luz.y >= d) break;\n\t\t\t\td = min(d, abs(luz));\n\t\t\t}\n\t\t\ta[ptr++]\
    \ = ps[i];\n\t\t}\n\t\treturn d;\n\t};\n\treturn solve(solve, 0, ps.size());\n\
    }\n\nint manhattanIntersection(vector<Segment> ss) {\n\tconst int INF = numeric_limits<int>::max();\n\
    \tconst int BOTTOM = 0, LEFT = 1, RIGHT = 2, TOP = 3;\n\tint n = ss.size();\n\t\
    vector<EndPoint> ep;\n\tfor (int i = 0; i < n; ++i) {\n\t\tif (ss[i].p1.y == ss[i].p2.y)\
    \ {\n\t\t\tif (ss[i].p1.x > ss[i].p2.x) swap(ss[i].p1, ss[i].p2);\n\t\t\tep.emplace_back(ss[i].p1,\
    \ i, LEFT);\n\t\t\tep.emplace_back(ss[i].p2, i, RIGHT);\n\t\t} else {\n\t\t\t\
    if (ss[i].p1.y > ss[i].p2.y) swap(ss[i].p1, ss[i].p2);\n\t\t\tep.emplace_back(ss[i].p1,\
    \ i, BOTTOM);\n\t\t\tep.emplace_back(ss[i].p2, i, TOP);\n\t\t}\n\t}\n\tsort(ep.begin(),\
    \ ep.end());\n\tset<int> st;\n\tst.insert(INF);\n\tint cnt = 0;\n\tfor (int i\
    \ = 0; i < 2 * n; ++i) {\n\t\tif (ep[i].st == TOP) st.erase(ep[i].p.x);\n\t\t\
    else if (ep[i].st == BOTTOM) st.insert(ep[i].p.x);\n\t\telse if (ep[i].st == LEFT)\
    \ {\n\t\t\tauto b = st.lower_bound(ss[ep[i].seg].p1.x);\n\t\t\tauto e = st.upper_bound(ss[ep[i].seg].p2.x);\n\
    \t\t\tcnt += distance(b, e);\n\t\t}\n\t}\n\treturn cnt;\n}\n#line 4 \"test/geometry/geometry/cgl_2_b.test.cpp\"\
    \n\n#line 6 \"test/geometry/geometry/cgl_2_b.test.cpp\"\n\nint main() {\n\tint\
    \ q;\n\tcin >> q;\n\twhile (q--) {\n\t\tSegment s1, s2;\n\t\tcin >> s1 >> s2;\n\
    \t\tcout << (intersectSS(s1, s2) ? 1 : 0) << endl;\n\t}\n\n\treturn 0;\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_B\n\
    \n#include \"src/geometry/geometry.cpp\"\n\n#include <iostream>\n\nint main()\
    \ {\n\tint q;\n\tcin >> q;\n\twhile (q--) {\n\t\tSegment s1, s2;\n\t\tcin >> s1\
    \ >> s2;\n\t\tcout << (intersectSS(s1, s2) ? 1 : 0) << endl;\n\t}\n\n\treturn\
    \ 0;\n}\n"
  dependsOn:
  - src/geometry/geometry.cpp
  isVerificationFile: true
  path: test/geometry/geometry/cgl_2_b.test.cpp
  requiredBy: []
  timestamp: '2023-08-20 06:31:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/geometry/cgl_2_b.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/geometry/cgl_2_b.test.cpp
- /verify/test/geometry/geometry/cgl_2_b.test.cpp.html
title: test/geometry/geometry/cgl_2_b.test.cpp
---
