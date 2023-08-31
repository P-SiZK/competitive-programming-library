---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/segtree/lazy_segment_tree/dsl_2_f.test.cpp
    title: test/segtree/lazy_segment_tree/dsl_2_f.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/segtree/lazy_segment_tree.hpp\"\n#include <vector>\n\
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
    \ & 1) ll = f(ll, reflect(l++));\n\t\t\tif (r & 1) rr = f(rr, reflect(--r));\n\
    \t\t\tl >>= 1, r >>= 1;\n\t\t}\n\t\treturn f(ll, rr);\n\t}\n\n\tT at(int i) {\
    \ return find(i, i + 1); }\n};\n"
  code: "#include <vector>\n\ntemplate<class T, class E, class F, class G, class H>\n\
    class LazySegmentTree { // 0-indexed\nprivate:\n\tint n_{}, height{};\n\tstd::vector<T>\
    \ tree;\n\tstd::vector<E> lazy;\n\tF f; // function<T(T, T)>\n\tG g; // function<T(T,\
    \ E)>\n\tH h; // function<E(E, E)>\n\tT ti;\n\tE ei;\n\npublic:\n\tLazySegmentTree(F\
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
    \ & 1) ll = f(ll, reflect(l++));\n\t\t\tif (r & 1) rr = f(rr, reflect(--r));\n\
    \t\t\tl >>= 1, r >>= 1;\n\t\t}\n\t\treturn f(ll, rr);\n\t}\n\n\tT at(int i) {\
    \ return find(i, i + 1); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/segtree/lazy_segment_tree.hpp
  requiredBy: []
  timestamp: '2023-08-31 13:01:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/segtree/lazy_segment_tree/dsl_2_f.test.cpp
documentation_of: src/segtree/lazy_segment_tree.hpp
layout: document
redirect_from:
- /library/src/segtree/lazy_segment_tree.hpp
- /library/src/segtree/lazy_segment_tree.hpp.html
title: src/segtree/lazy_segment_tree.hpp
---
