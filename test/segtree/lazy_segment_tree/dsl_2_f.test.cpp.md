---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/segtree/lazy_segment_tree.cpp
    title: src/segtree/lazy_segment_tree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F
  bundledCode: "#line 1 \"test/segtree/lazy_segment_tree/dsl_2_f.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F\n\n\
    #line 1 \"src/segtree/lazy_segment_tree.cpp\"\n#include <vector>\n\nusing namespace\
    \ std;\n\ntemplate<class T, class E, class F, class G, class H>\nstruct LazySegmentTree\
    \ { // 0-indexed\n\tint n, height;\n\tvector<T> tree;\n\tvector<E> lazy;\n\tconst\
    \ F f; // function<T(T, T)>\n\tconst G g; // function<T(T, E)>\n\tconst H h; //\
    \ function<E(E, E)>\n\tconst T ti;\n\tconst E ei;\n\n\tLazySegmentTree(F f, G\
    \ g, H h, T ti, E ei) :\n\t\tf(f), g(g), h(h), ti(ti), ei(ei) {}\n\n\tvoid init(int\
    \ n_) {\n\t\tn = 1, height = 0;\n\t\twhile (n < n_) n *= 2, ++height;\n\t\ttree.assign(2\
    \ * n, ti);\n\t\tlazy.assign(2 * n, ei);\n\t}\n\n\tvoid build(const vector<T>\
    \ &v) {\n\t\tint n_ = v.size();\n\t\tinit(n_);\n\t\tfor (int i = 0; i < n_; ++i)\
    \ tree[n + i] = v[i];\n\t\tfor (int i = n - 1; i > 0; --i)\n\t\t\ttree[i] = f(tree[2\
    \ * i], tree[2 * i + 1]);\n\t}\n\n\tinline T reflect(int k) {\n\t\treturn (lazy[k]\
    \ == ei ? tree[k] : g(tree[k], lazy[k]));\n\t}\n\n\tinline void eval(int k) {\n\
    \t\tif (lazy[k] == ei) return;\n\t\tlazy[2 * k] = h(lazy[2 * k], lazy[k]);\n\t\
    \tlazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);\n\t\ttree[k] = reflect(k);\n\t\
    \tlazy[k] = ei;\n\t}\n\n\tinline void thrust(int k) {\n\t\tfor (int i = height;\
    \ i > 0; --i) eval(k >> i);\n\t}\n\n\tinline void recalc(int k) {\n\t\twhile (k\
    \ >>= 1) tree[k] = f(reflect(2 * k), reflect(2 * k + 1));\n\t}\n\n\tvoid update(int\
    \ s, int t, const E &x) { // [l, r)\n\t\ts += n, t += n;\n\t\tthrust(s), thrust(t\
    \ - 1);\n\t\tint l = s, r = t;\n\t\twhile (l < r) {\n\t\t\tif (l & 1) lazy[l]\
    \ = h(lazy[l], x), ++l;\n\t\t\tif (r & 1) --r, lazy[r] = h(lazy[r], x);\n\t\t\t\
    l >>= 1, r >>= 1;\n\t\t}\n\t\trecalc(s), recalc(t - 1);\n\t}\n\n\tT find(int s,\
    \ int t) { // [l, r)\n\t\ts += n, t += n;\n\t\tthrust(s), thrust(t - 1);\n\t\t\
    int l = s, r = t;\n\t\tT ll = ti, rr = ti;\n\t\twhile (l < r) {\n\t\t\tif (l &\
    \ 1) ll = f(ll, reflect(l++));\n\t\t\tif (r & 1) rr = f(rr, reflect(--r));\n\t\
    \t\tl >>= 1, r >>= 1;\n\t\t}\n\t\treturn f(ll, rr);\n\t}\n\n\tT at(int i) { return\
    \ find(i, i + 1); }\n};\n#line 4 \"test/segtree/lazy_segment_tree/dsl_2_f.test.cpp\"\
    \n\n#include <iostream>\n#include <limits>\n\nusing namespace std;\n\nint main()\
    \ {\n\tint n, q;\n\tcin >> n >> q;\n\tauto f = [](int a, int b) { return min(a,\
    \ b); };\n\tauto g = [](int /* a */, int b) { return b; };\n\tLazySegmentTree\
    \ seg(f, g, g, numeric_limits<int>::max(), -1);\n\tseg.init(n);\n\twhile (q--)\
    \ {\n\t\tint com, s, t, x;\n\t\tcin >> com >> s >> t;\n\t\tif (com) cout << seg.find(s,\
    \ t + 1) << endl;\n\t\telse cin >> x, seg.update(s, t + 1, x);\n\t}\n\n\treturn\
    \ 0;\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F\n\
    \n#include \"src/segtree/lazy_segment_tree.cpp\"\n\n#include <iostream>\n#include\
    \ <limits>\n\nusing namespace std;\n\nint main() {\n\tint n, q;\n\tcin >> n >>\
    \ q;\n\tauto f = [](int a, int b) { return min(a, b); };\n\tauto g = [](int /*\
    \ a */, int b) { return b; };\n\tLazySegmentTree seg(f, g, g, numeric_limits<int>::max(),\
    \ -1);\n\tseg.init(n);\n\twhile (q--) {\n\t\tint com, s, t, x;\n\t\tcin >> com\
    \ >> s >> t;\n\t\tif (com) cout << seg.find(s, t + 1) << endl;\n\t\telse cin >>\
    \ x, seg.update(s, t + 1, x);\n\t}\n\n\treturn 0;\n}\n"
  dependsOn:
  - src/segtree/lazy_segment_tree.cpp
  isVerificationFile: true
  path: test/segtree/lazy_segment_tree/dsl_2_f.test.cpp
  requiredBy: []
  timestamp: '2023-08-20 13:03:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/segtree/lazy_segment_tree/dsl_2_f.test.cpp
layout: document
redirect_from:
- /verify/test/segtree/lazy_segment_tree/dsl_2_f.test.cpp
- /verify/test/segtree/lazy_segment_tree/dsl_2_f.test.cpp.html
title: test/segtree/lazy_segment_tree/dsl_2_f.test.cpp
---
