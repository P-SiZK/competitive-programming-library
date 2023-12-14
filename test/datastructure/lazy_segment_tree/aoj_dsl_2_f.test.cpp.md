---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/datastructure/lazy_segment_tree.hpp
    title: Segment tree with lazy propagation
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F
  bundledCode: "#line 1 \"test/datastructure/lazy_segment_tree/aoj_dsl_2_f.test.cpp\"\
    \n// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F\n\
    \n#line 1 \"src/datastructure/lazy_segment_tree.hpp\"\n\n\n\n#include <vector>\n\
    \ntemplate<class T, class E, class F, class G, class H>\nclass LazySegmentTree\
    \ { // 0-indexed\nprivate:\n\tint n_{}, height{};\n\tstd::vector<T> tree;\n\t\
    std::vector<E> lazy;\n\tF f; // function<T(T, T)>\n\tG g; // function<T(T, E)>\n\
    \tH h; // function<E(E, E)>\n\tT ti;\n\tE ei;\n\npublic:\n\tLazySegmentTree(F\
    \ f, G g, H h, T ti, E ei) : f(f), g(g), h(h), ti(ti), ei(ei) {}\n\n\tvoid init(int\
    \ n) {\n\t\tn_ = 1, height = 0;\n\t\twhile (n_ < n) n_ *= 2, ++height;\n\t\ttree.assign(2\
    \ * n_, ti);\n\t\tlazy.assign(2 * n_, ei);\n\t}\n\n\tvoid build(std::vector<T>\
    \ const &v) {\n\t\tint const N = v.size();\n\t\tinit(N);\n\t\tfor (int i = 0;\
    \ i < N; ++i) tree[n_ + i] = v[i];\n\t\tfor (int i = n_ - 1; i > 0; --i) tree[i]\
    \ = f(tree[2 * i], tree[2 * i + 1]);\n\t}\n\n\tinline T reflect(int k) { return\
    \ (lazy[k] == ei ? tree[k] : g(tree[k], lazy[k])); }\n\n\tinline void eval(int\
    \ k) {\n\t\tif (lazy[k] == ei) return;\n\t\tlazy[2 * k] = h(lazy[2 * k], lazy[k]);\n\
    \t\tlazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);\n\t\ttree[k] = reflect(k);\n\
    \t\tlazy[k] = ei;\n\t}\n\n\tinline void thrust(int k) {\n\t\tfor (int i = height;\
    \ i > 0; --i) eval(k >> i);\n\t}\n\n\tinline void recalc(int k) {\n\t\twhile (k\
    \ >>= 1) tree[k] = f(reflect(2 * k), reflect(2 * k + 1));\n\t}\n\n\tvoid update(int\
    \ s, int t, E const &x) { // [l, r)\n\t\ts += n_, t += n_;\n\t\tthrust(s), thrust(t\
    \ - 1);\n\t\tint l = s, r = t;\n\t\twhile (l < r) {\n\t\t\tif (l & 1) lazy[l]\
    \ = h(lazy[l], x), ++l;\n\t\t\tif (r & 1) --r, lazy[r] = h(lazy[r], x);\n\t\t\t\
    l >>= 1, r >>= 1;\n\t\t}\n\t\trecalc(s), recalc(t - 1);\n\t}\n\n\tT find(int s,\
    \ int t) { // [l, r)\n\t\ts += n_, t += n_;\n\t\tthrust(s), thrust(t - 1);\n\t\
    \tint l = s, r = t;\n\t\tT ll = ti, rr = ti;\n\t\twhile (l < r) {\n\t\t\tif (l\
    \ & 1) ll = f(ll, reflect(l++));\n\t\t\tif (r & 1) rr = f(reflect(--r), rr);\n\
    \t\t\tl >>= 1, r >>= 1;\n\t\t}\n\t\treturn f(ll, rr);\n\t}\n\n\tT at(int i) {\n\
    \t\ti += n_;\n\t\tthrust(i);\n\t\treturn reflect(i);\n\t}\n};\n\n\n#line 4 \"\
    test/datastructure/lazy_segment_tree/aoj_dsl_2_f.test.cpp\"\n\n#include <algorithm>\n\
    #include <iostream>\n#include <limits>\n\nusing namespace std;\n\nint main() {\n\
    \tint n, q;\n\tcin >> n >> q;\n\tauto f = [](int a, int b) { return min(a, b);\
    \ };\n\tauto g = [](int, int b) { return b; };\n\tauto h = [](int, int b) { return\
    \ b; };\n\tLazySegmentTree seg(f, g, h, numeric_limits<int>::max(), -1);\n\tseg.init(n);\n\
    \twhile (q--) {\n\t\tint com, s, t;\n\t\tcin >> com >> s >> t;\n\t\tif (com) {\n\
    \t\t\tcout << seg.find(s, t + 1) << endl;\n\t\t} else {\n\t\t\tint x;\n\t\t\t\
    cin >> x;\n\t\t\tseg.update(s, t + 1, x);\n\t\t}\n\t}\n\n\treturn 0;\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F\n\
    \n#include \"src/datastructure/lazy_segment_tree.hpp\"\n\n#include <algorithm>\n\
    #include <iostream>\n#include <limits>\n\nusing namespace std;\n\nint main() {\n\
    \tint n, q;\n\tcin >> n >> q;\n\tauto f = [](int a, int b) { return min(a, b);\
    \ };\n\tauto g = [](int, int b) { return b; };\n\tauto h = [](int, int b) { return\
    \ b; };\n\tLazySegmentTree seg(f, g, h, numeric_limits<int>::max(), -1);\n\tseg.init(n);\n\
    \twhile (q--) {\n\t\tint com, s, t;\n\t\tcin >> com >> s >> t;\n\t\tif (com) {\n\
    \t\t\tcout << seg.find(s, t + 1) << endl;\n\t\t} else {\n\t\t\tint x;\n\t\t\t\
    cin >> x;\n\t\t\tseg.update(s, t + 1, x);\n\t\t}\n\t}\n\n\treturn 0;\n}\n"
  dependsOn:
  - src/datastructure/lazy_segment_tree.hpp
  isVerificationFile: true
  path: test/datastructure/lazy_segment_tree/aoj_dsl_2_f.test.cpp
  requiredBy: []
  timestamp: '2023-12-14 18:25:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/datastructure/lazy_segment_tree/aoj_dsl_2_f.test.cpp
layout: document
redirect_from:
- /verify/test/datastructure/lazy_segment_tree/aoj_dsl_2_f.test.cpp
- /verify/test/datastructure/lazy_segment_tree/aoj_dsl_2_f.test.cpp.html
title: test/datastructure/lazy_segment_tree/aoj_dsl_2_f.test.cpp
---
