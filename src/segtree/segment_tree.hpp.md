---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/segtree/segment_tree/dsl_2_a.test.cpp
    title: test/segtree/segment_tree/dsl_2_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segtree/segment_tree/dsl_2_b.test.cpp
    title: test/segtree/segment_tree/dsl_2_b.test.cpp
  - icon: ':x:'
    path: test/tree/euler_tour/abc294_g.test.cpp
    title: test/tree/euler_tour/abc294_g.test.cpp
  - icon: ':x:'
    path: test/tree/euler_tour/grl_5_d.test.cpp
    title: test/tree/euler_tour/grl_5_d.test.cpp
  - icon: ':x:'
    path: test/tree/euler_tour/vertex_add_path_sum.test.cpp
    title: test/tree/euler_tour/vertex_add_path_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/segtree/segment_tree.hpp\"\n#include <vector>\n\ntemplate<class\
    \ T, class F>\nclass SegmentTree { // 0-indexed\nprivate:\n\tint n_{};\n\tstd::vector<T>\
    \ tree;\n\tF f; // function<T(T, T)>\n\tT ti;\n\npublic:\n\tSegmentTree(F f, T\
    \ ti) : f(f), ti(ti) {}\n\n\tvoid init(int n) {\n\t\tn_ = 1;\n\t\twhile (n_ <\
    \ n) n_ *= 2;\n\t\ttree.assign(2 * n_, ti);\n\t}\n\n\tvoid build(std::vector<T>\
    \ const &v) {\n\t\tint const N = v.size();\n\t\tinit(N);\n\t\tfor (int i = 0;\
    \ i < N; ++i) tree[n_ + i] = v[i];\n\t\tfor (int i = n_ - 1; i > 0; --i) tree[i]\
    \ = f(tree[2 * i], tree[2 * i + 1]);\n\t}\n\n\tvoid update(int i, T const &x)\
    \ {\n\t\ti += n_;\n\t\ttree[i] = x;\n\t\twhile (i >>= 1) tree[i] = f(tree[2 *\
    \ i], tree[2 * i + 1]);\n\t}\n\n\tT find(int l, int r) { // [l, r)\n\t\tl += n_,\
    \ r += n_;\n\t\tT ll = ti, rr = ti;\n\t\twhile (l < r) {\n\t\t\tif (l & 1) ll\
    \ = f(ll, tree[l++]);\n\t\t\tif (r & 1) rr = f(rr, tree[--r]);\n\t\t\tl >>= 1,\
    \ r >>= 1;\n\t\t}\n\t\treturn f(ll, rr);\n\t}\n\n\tT at(int i) { return tree[i\
    \ + n_]; }\n};\n"
  code: "#include <vector>\n\ntemplate<class T, class F>\nclass SegmentTree { // 0-indexed\n\
    private:\n\tint n_{};\n\tstd::vector<T> tree;\n\tF f; // function<T(T, T)>\n\t\
    T ti;\n\npublic:\n\tSegmentTree(F f, T ti) : f(f), ti(ti) {}\n\n\tvoid init(int\
    \ n) {\n\t\tn_ = 1;\n\t\twhile (n_ < n) n_ *= 2;\n\t\ttree.assign(2 * n_, ti);\n\
    \t}\n\n\tvoid build(std::vector<T> const &v) {\n\t\tint const N = v.size();\n\t\
    \tinit(N);\n\t\tfor (int i = 0; i < N; ++i) tree[n_ + i] = v[i];\n\t\tfor (int\
    \ i = n_ - 1; i > 0; --i) tree[i] = f(tree[2 * i], tree[2 * i + 1]);\n\t}\n\n\t\
    void update(int i, T const &x) {\n\t\ti += n_;\n\t\ttree[i] = x;\n\t\twhile (i\
    \ >>= 1) tree[i] = f(tree[2 * i], tree[2 * i + 1]);\n\t}\n\n\tT find(int l, int\
    \ r) { // [l, r)\n\t\tl += n_, r += n_;\n\t\tT ll = ti, rr = ti;\n\t\twhile (l\
    \ < r) {\n\t\t\tif (l & 1) ll = f(ll, tree[l++]);\n\t\t\tif (r & 1) rr = f(rr,\
    \ tree[--r]);\n\t\t\tl >>= 1, r >>= 1;\n\t\t}\n\t\treturn f(ll, rr);\n\t}\n\n\t\
    T at(int i) { return tree[i + n_]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/segtree/segment_tree.hpp
  requiredBy: []
  timestamp: '2023-08-31 13:01:25+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/tree/euler_tour/grl_5_d.test.cpp
  - test/tree/euler_tour/vertex_add_path_sum.test.cpp
  - test/tree/euler_tour/abc294_g.test.cpp
  - test/segtree/segment_tree/dsl_2_a.test.cpp
  - test/segtree/segment_tree/dsl_2_b.test.cpp
documentation_of: src/segtree/segment_tree.hpp
layout: document
redirect_from:
- /library/src/segtree/segment_tree.hpp
- /library/src/segtree/segment_tree.hpp.html
title: src/segtree/segment_tree.hpp
---
