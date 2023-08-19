---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/segtree/segment_tree/dsl_2_a.test.cpp
    title: test/segtree/segment_tree/dsl_2_a.test.cpp
  - icon: ':x:'
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
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/segtree/segment_tree.cpp\"\n#include <vector>\n\nusing\
    \ namespace std;\n\ntemplate<class T, class F>\nstruct SegmentTree { // 0-indexed\n\
    \tint n;\n\tvector<T> tree;\n\tconst F f; // function<T(T, T)>\n\tconst T ti;\n\
    \n\tSegmentTree(F f, T ti) : f(f), ti(ti) {}\n\n\tvoid init(int n_) {\n\t\tn =\
    \ 1;\n\t\twhile (n < n_) n *= 2;\n\t\ttree.assign(2 * n, ti);\n\t}\n\n\tvoid build(const\
    \ vector<T> &v) {\n\t\tint n_ = v.size();\n\t\tinit(n_);\n\t\tfor (int i = 0;\
    \ i < n_; ++i) tree[n + i] = v[i];\n\t\tfor (int i = n - 1; i > 0; --i)\n\t\t\t\
    tree[i] = f(tree[2 * i], tree[2 * i + 1]);\n\t}\n\n\tvoid update(int i, const\
    \ T &x) {\n\t\ti += n;\n\t\ttree[i] = x;\n\t\twhile (i >>= 1) tree[i] = f(tree[2\
    \ * i], tree[2 * i + 1]);\n\t}\n\n\tT find(int l, int r) { // [l, r)\n\t\tl +=\
    \ n, r += n;\n\t\tT ll = ti, rr = ti;\n\t\twhile (l < r) {\n\t\t\tif (l & 1) ll\
    \ = f(ll, tree[l++]);\n\t\t\tif (r & 1) rr = f(rr, tree[--r]);\n\t\t\tl >>= 1,\
    \ r >>= 1;\n\t\t}\n\t\treturn f(ll, rr);\n\t}\n\n\tT at(int i) { return tree[i\
    \ + n]; }\n};\n"
  code: "#include <vector>\n\nusing namespace std;\n\ntemplate<class T, class F>\n\
    struct SegmentTree { // 0-indexed\n\tint n;\n\tvector<T> tree;\n\tconst F f; //\
    \ function<T(T, T)>\n\tconst T ti;\n\n\tSegmentTree(F f, T ti) : f(f), ti(ti)\
    \ {}\n\n\tvoid init(int n_) {\n\t\tn = 1;\n\t\twhile (n < n_) n *= 2;\n\t\ttree.assign(2\
    \ * n, ti);\n\t}\n\n\tvoid build(const vector<T> &v) {\n\t\tint n_ = v.size();\n\
    \t\tinit(n_);\n\t\tfor (int i = 0; i < n_; ++i) tree[n + i] = v[i];\n\t\tfor (int\
    \ i = n - 1; i > 0; --i)\n\t\t\ttree[i] = f(tree[2 * i], tree[2 * i + 1]);\n\t\
    }\n\n\tvoid update(int i, const T &x) {\n\t\ti += n;\n\t\ttree[i] = x;\n\t\twhile\
    \ (i >>= 1) tree[i] = f(tree[2 * i], tree[2 * i + 1]);\n\t}\n\n\tT find(int l,\
    \ int r) { // [l, r)\n\t\tl += n, r += n;\n\t\tT ll = ti, rr = ti;\n\t\twhile\
    \ (l < r) {\n\t\t\tif (l & 1) ll = f(ll, tree[l++]);\n\t\t\tif (r & 1) rr = f(rr,\
    \ tree[--r]);\n\t\t\tl >>= 1, r >>= 1;\n\t\t}\n\t\treturn f(ll, rr);\n\t}\n\n\t\
    T at(int i) { return tree[i + n]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/segtree/segment_tree.cpp
  requiredBy: []
  timestamp: '2023-08-20 06:31:19+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/segtree/segment_tree/dsl_2_b.test.cpp
  - test/segtree/segment_tree/dsl_2_a.test.cpp
  - test/tree/euler_tour/grl_5_d.test.cpp
  - test/tree/euler_tour/vertex_add_path_sum.test.cpp
  - test/tree/euler_tour/abc294_g.test.cpp
documentation_of: src/segtree/segment_tree.cpp
layout: document
redirect_from:
- /library/src/segtree/segment_tree.cpp
- /library/src/segtree/segment_tree.cpp.html
title: src/segtree/segment_tree.cpp
---
