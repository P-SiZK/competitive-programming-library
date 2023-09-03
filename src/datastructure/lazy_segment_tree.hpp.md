---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/datastructure/lazy_segment_tree/dsl_2_f.test.cpp
    title: test/datastructure/lazy_segment_tree/dsl_2_f.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/datastructure/lazy_segment_tree.hpp\"\n\n\n\n#include\
    \ <vector>\n\ntemplate<class T, class E, class F, class G, class H>\nclass LazySegmentTree\
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
    \ return find(i, i + 1); }\n};\n\n\n"
  code: "#ifndef SEGTREE_LAZY_SEGMENT_TREE_HPP\n#define SEGTREE_LAZY_SEGMENT_TREE_HPP\n\
    \n#include <vector>\n\ntemplate<class T, class E, class F, class G, class H>\n\
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
    \ return find(i, i + 1); }\n};\n\n#endif // SEGTREE_LAZY_SEGMENT_TREE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: src/datastructure/lazy_segment_tree.hpp
  requiredBy: []
  timestamp: '2023-09-02 10:46:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/datastructure/lazy_segment_tree/dsl_2_f.test.cpp
documentation_of: src/datastructure/lazy_segment_tree.hpp
layout: document
title: Segment tree with lazy propagation
---

## 概要

区間更新・区間取得を $O(\log N)$ で行えます。

## 要求される性質

遅延伝播セグメント木で区間取得の際に扱う要素と、それに対して作用を与える区間更新の際に扱う要素は、どちらも[モノイド](https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8E%E3%82%A4%E3%83%89)である必要があります[^1]。

区間取得の際に扱うモノイドを $(S, \cdot, e_S)$ とし、それに対して作用を与える区間更新の際に扱うモノイドを $(T, \circ, e_T)$ とします。そして $T$ の $S$ への作用を外部二項演算 $\ast: T \times S \rightarrow S$ とします。
このとき、外部二項演算 $\ast$ は準同型であり、モノイド作用である必要があります。
つまり、次の条件を満たす必要があります。

- モノイド作用
  - $e_T \ast s = s \quad (\forall s \in S)$ を満たす
  - $t_1 \ast (t_2 \ast s) = (t_1 \circ t_2) \ast s \quad (\forall s \in S, \forall t_1, t_2 \in T)$ を満たす
- 準同型
  - $t_1 \ast (s_1 \cdot s_2) = (t_1 \ast s_1) \cdot (t_1 \ast s_2) \quad (\forall s_1, s_2 \in S, \forall t \in T)$ を満たす[^2]

[^1]: 実際にはモノイドよりも条件を緩めることができます。
[^2]: $t \ast s = f_t(s)$ とすると $f_{t_1}(s_1 \cdot s_2) = f_{t_1}(s_1) \cdot f_{t_1}(s_2)$ となるので、準同型を表していることが分かりやすくなります。
