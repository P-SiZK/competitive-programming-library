---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/tree/euler_tour.hpp
    title: Euler Tour
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/datastructure/segment_tree/aoj_dsl_2_a.test.cpp
    title: test/datastructure/segment_tree/aoj_dsl_2_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/datastructure/segment_tree/aoj_dsl_2_b.test.cpp
    title: test/datastructure/segment_tree/aoj_dsl_2_b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/datastructure/segment_tree/yosupo_point_set_range_composite.test.cpp
    title: test/datastructure/segment_tree/yosupo_point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/euler_tour/aoj_grl_5_c.test.cpp
    title: test/tree/euler_tour/aoj_grl_5_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/euler_tour/aoj_grl_5_d.test.cpp
    title: test/tree/euler_tour/aoj_grl_5_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/euler_tour/atcoder_abc294_g.test.cpp
    title: test/tree/euler_tour/atcoder_abc294_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/euler_tour/yosupo_vertex_add_path_sum.test.cpp
    title: test/tree/euler_tour/yosupo_vertex_add_path_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/datastructure/segment_tree.hpp\"\n\n\n\n#include <vector>\n\
    \ntemplate<class T, class F>\nclass SegmentTree { // 0-indexed\nprivate:\n\tint\
    \ n_{};\n\tstd::vector<T> tree;\n\tF f; // function<T(T, T)>\n\tT ti;\n\npublic:\n\
    \tSegmentTree(F f, T ti) : f(f), ti(ti) {}\n\n\tvoid init(int n) {\n\t\tn_ = 1;\n\
    \t\twhile (n_ < n) n_ *= 2;\n\t\ttree.assign(2 * n_, ti);\n\t}\n\n\tvoid build(std::vector<T>\
    \ const &v) {\n\t\tint const N = v.size();\n\t\tinit(N);\n\t\tfor (int i = 0;\
    \ i < N; ++i) tree[n_ + i] = v[i];\n\t\tfor (int i = n_ - 1; i > 0; --i) tree[i]\
    \ = f(tree[2 * i], tree[2 * i + 1]);\n\t}\n\n\tvoid update(int i, T const &x)\
    \ {\n\t\ti += n_;\n\t\ttree[i] = x;\n\t\twhile (i >>= 1) tree[i] = f(tree[2 *\
    \ i], tree[2 * i + 1]);\n\t}\n\n\tT find(int l, int r) { // [l, r)\n\t\tl += n_,\
    \ r += n_;\n\t\tT ll = ti, rr = ti;\n\t\twhile (l < r) {\n\t\t\tif (l & 1) ll\
    \ = f(ll, tree[l++]);\n\t\t\tif (r & 1) rr = f(tree[--r], rr);\n\t\t\tl >>= 1,\
    \ r >>= 1;\n\t\t}\n\t\treturn f(ll, rr);\n\t}\n\n\tT at(int i) { return tree[i\
    \ + n_]; }\n};\n\n\n"
  code: "#ifndef SEGTREE_SEGMENT_TREE_HPP\n#define SEGTREE_SEGMENT_TREE_HPP\n\n#include\
    \ <vector>\n\ntemplate<class T, class F>\nclass SegmentTree { // 0-indexed\nprivate:\n\
    \tint n_{};\n\tstd::vector<T> tree;\n\tF f; // function<T(T, T)>\n\tT ti;\n\n\
    public:\n\tSegmentTree(F f, T ti) : f(f), ti(ti) {}\n\n\tvoid init(int n) {\n\t\
    \tn_ = 1;\n\t\twhile (n_ < n) n_ *= 2;\n\t\ttree.assign(2 * n_, ti);\n\t}\n\n\t\
    void build(std::vector<T> const &v) {\n\t\tint const N = v.size();\n\t\tinit(N);\n\
    \t\tfor (int i = 0; i < N; ++i) tree[n_ + i] = v[i];\n\t\tfor (int i = n_ - 1;\
    \ i > 0; --i) tree[i] = f(tree[2 * i], tree[2 * i + 1]);\n\t}\n\n\tvoid update(int\
    \ i, T const &x) {\n\t\ti += n_;\n\t\ttree[i] = x;\n\t\twhile (i >>= 1) tree[i]\
    \ = f(tree[2 * i], tree[2 * i + 1]);\n\t}\n\n\tT find(int l, int r) { // [l, r)\n\
    \t\tl += n_, r += n_;\n\t\tT ll = ti, rr = ti;\n\t\twhile (l < r) {\n\t\t\tif\
    \ (l & 1) ll = f(ll, tree[l++]);\n\t\t\tif (r & 1) rr = f(tree[--r], rr);\n\t\t\
    \tl >>= 1, r >>= 1;\n\t\t}\n\t\treturn f(ll, rr);\n\t}\n\n\tT at(int i) { return\
    \ tree[i + n_]; }\n};\n\n#endif // SEGTREE_SEGMENT_TREE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: src/datastructure/segment_tree.hpp
  requiredBy:
  - src/tree/euler_tour.hpp
  timestamp: '2023-12-14 18:25:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/datastructure/segment_tree/aoj_dsl_2_a.test.cpp
  - test/datastructure/segment_tree/aoj_dsl_2_b.test.cpp
  - test/datastructure/segment_tree/yosupo_point_set_range_composite.test.cpp
  - test/tree/euler_tour/aoj_grl_5_d.test.cpp
  - test/tree/euler_tour/aoj_grl_5_c.test.cpp
  - test/tree/euler_tour/atcoder_abc294_g.test.cpp
  - test/tree/euler_tour/yosupo_vertex_add_path_sum.test.cpp
documentation_of: src/datastructure/segment_tree.hpp
layout: document
title: Segment tree
---

## 概要

一点更新・区間取得を $O(\log N)$ で行えます。

## 要求される性質

セグメント木で扱う要素は[モノイド](https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8E%E3%82%A4%E3%83%89)である必要があります[^1]。
モノイドとは、集合 $S$ と二項演算 $\cdot: S \times S \rightarrow S$ が与えられたときに、次の条件を満たすものです。

- 結合律: $(a \cdot b) \cdot c = a \cdot (b \cdot c) \quad (\forall a, b, c \in S)$ を満たす
- 単位元の存在: $e \cdot a = a \cdot e = a \quad (\forall a \in S)$ を満たす $e \in S$ が存在する

[^1]: 実際にはモノイドよりも条件を緩めることができます。
