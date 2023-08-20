---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/segtree/lazy_segment_tree/dsl_2_f.test.cpp
    title: test/segtree/lazy_segment_tree/dsl_2_f.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/segtree/lazy_segment_tree.cpp\"\n#include <vector>\n\
    \nusing namespace std;\n\ntemplate<class T, class E, class F, class G, class H>\n\
    struct LazySegmentTree { // 0-indexed\n\tint n, height;\n\tvector<T> tree;\n\t\
    vector<E> lazy;\n\tconst F f; // function<T(T, T)>\n\tconst G g; // function<T(T,\
    \ E)>\n\tconst H h; // function<E(E, E)>\n\tconst T ti;\n\tconst E ei;\n\n\tLazySegmentTree(F\
    \ f, G g, H h, T ti, E ei) :\n\t\tf(f), g(g), h(h), ti(ti), ei(ei) {}\n\n\tvoid\
    \ init(int n_) {\n\t\tn = 1, height = 0;\n\t\twhile (n < n_) n *= 2, ++height;\n\
    \t\ttree.assign(2 * n, ti);\n\t\tlazy.assign(2 * n, ei);\n\t}\n\n\tvoid build(const\
    \ vector<T> &v) {\n\t\tint n_ = v.size();\n\t\tinit(n_);\n\t\tfor (int i = 0;\
    \ i < n_; ++i) tree[n + i] = v[i];\n\t\tfor (int i = n - 1; i > 0; --i)\n\t\t\t\
    tree[i] = f(tree[2 * i], tree[2 * i + 1]);\n\t}\n\n\tinline T reflect(int k) {\n\
    \t\treturn (lazy[k] == ei ? tree[k] : g(tree[k], lazy[k]));\n\t}\n\n\tinline void\
    \ eval(int k) {\n\t\tif (lazy[k] == ei) return;\n\t\tlazy[2 * k] = h(lazy[2 *\
    \ k], lazy[k]);\n\t\tlazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);\n\t\ttree[k]\
    \ = reflect(k);\n\t\tlazy[k] = ei;\n\t}\n\n\tinline void thrust(int k) {\n\t\t\
    for (int i = height; i > 0; --i) eval(k >> i);\n\t}\n\n\tinline void recalc(int\
    \ k) {\n\t\twhile (k >>= 1) tree[k] = f(reflect(2 * k), reflect(2 * k + 1));\n\
    \t}\n\n\tvoid update(int s, int t, const E &x) { // [l, r)\n\t\ts += n, t += n;\n\
    \t\tthrust(s), thrust(t - 1);\n\t\tint l = s, r = t;\n\t\twhile (l < r) {\n\t\t\
    \tif (l & 1) lazy[l] = h(lazy[l], x), ++l;\n\t\t\tif (r & 1) --r, lazy[r] = h(lazy[r],\
    \ x);\n\t\t\tl >>= 1, r >>= 1;\n\t\t}\n\t\trecalc(s), recalc(t - 1);\n\t}\n\n\t\
    T find(int s, int t) { // [l, r)\n\t\ts += n, t += n;\n\t\tthrust(s), thrust(t\
    \ - 1);\n\t\tint l = s, r = t;\n\t\tT ll = ti, rr = ti;\n\t\twhile (l < r) {\n\
    \t\t\tif (l & 1) ll = f(ll, reflect(l++));\n\t\t\tif (r & 1) rr = f(rr, reflect(--r));\n\
    \t\t\tl >>= 1, r >>= 1;\n\t\t}\n\t\treturn f(ll, rr);\n\t}\n\n\tT at(int i) {\
    \ return find(i, i + 1); }\n};\n"
  code: "#include <vector>\n\nusing namespace std;\n\ntemplate<class T, class E, class\
    \ F, class G, class H>\nstruct LazySegmentTree { // 0-indexed\n\tint n, height;\n\
    \tvector<T> tree;\n\tvector<E> lazy;\n\tconst F f; // function<T(T, T)>\n\tconst\
    \ G g; // function<T(T, E)>\n\tconst H h; // function<E(E, E)>\n\tconst T ti;\n\
    \tconst E ei;\n\n\tLazySegmentTree(F f, G g, H h, T ti, E ei) :\n\t\tf(f), g(g),\
    \ h(h), ti(ti), ei(ei) {}\n\n\tvoid init(int n_) {\n\t\tn = 1, height = 0;\n\t\
    \twhile (n < n_) n *= 2, ++height;\n\t\ttree.assign(2 * n, ti);\n\t\tlazy.assign(2\
    \ * n, ei);\n\t}\n\n\tvoid build(const vector<T> &v) {\n\t\tint n_ = v.size();\n\
    \t\tinit(n_);\n\t\tfor (int i = 0; i < n_; ++i) tree[n + i] = v[i];\n\t\tfor (int\
    \ i = n - 1; i > 0; --i)\n\t\t\ttree[i] = f(tree[2 * i], tree[2 * i + 1]);\n\t\
    }\n\n\tinline T reflect(int k) {\n\t\treturn (lazy[k] == ei ? tree[k] : g(tree[k],\
    \ lazy[k]));\n\t}\n\n\tinline void eval(int k) {\n\t\tif (lazy[k] == ei) return;\n\
    \t\tlazy[2 * k] = h(lazy[2 * k], lazy[k]);\n\t\tlazy[2 * k + 1] = h(lazy[2 * k\
    \ + 1], lazy[k]);\n\t\ttree[k] = reflect(k);\n\t\tlazy[k] = ei;\n\t}\n\n\tinline\
    \ void thrust(int k) {\n\t\tfor (int i = height; i > 0; --i) eval(k >> i);\n\t\
    }\n\n\tinline void recalc(int k) {\n\t\twhile (k >>= 1) tree[k] = f(reflect(2\
    \ * k), reflect(2 * k + 1));\n\t}\n\n\tvoid update(int s, int t, const E &x) {\
    \ // [l, r)\n\t\ts += n, t += n;\n\t\tthrust(s), thrust(t - 1);\n\t\tint l = s,\
    \ r = t;\n\t\twhile (l < r) {\n\t\t\tif (l & 1) lazy[l] = h(lazy[l], x), ++l;\n\
    \t\t\tif (r & 1) --r, lazy[r] = h(lazy[r], x);\n\t\t\tl >>= 1, r >>= 1;\n\t\t\
    }\n\t\trecalc(s), recalc(t - 1);\n\t}\n\n\tT find(int s, int t) { // [l, r)\n\t\
    \ts += n, t += n;\n\t\tthrust(s), thrust(t - 1);\n\t\tint l = s, r = t;\n\t\t\
    T ll = ti, rr = ti;\n\t\twhile (l < r) {\n\t\t\tif (l & 1) ll = f(ll, reflect(l++));\n\
    \t\t\tif (r & 1) rr = f(rr, reflect(--r));\n\t\t\tl >>= 1, r >>= 1;\n\t\t}\n\t\
    \treturn f(ll, rr);\n\t}\n\n\tT at(int i) { return find(i, i + 1); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/segtree/lazy_segment_tree.cpp
  requiredBy: []
  timestamp: '2023-08-20 06:31:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/segtree/lazy_segment_tree/dsl_2_f.test.cpp
documentation_of: src/segtree/lazy_segment_tree.cpp
layout: document
redirect_from:
- /library/src/segtree/lazy_segment_tree.cpp
- /library/src/segtree/lazy_segment_tree.cpp.html
title: src/segtree/lazy_segment_tree.cpp
---
