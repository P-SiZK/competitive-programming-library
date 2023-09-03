---
title: Segment tree with lazy propagation
documentation_of: //src/datastructure/lazy_segment_tree.hpp
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
