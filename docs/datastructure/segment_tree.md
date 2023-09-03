---
title: Segment tree
documentation_of: //src/datastructure/segment_tree.hpp
---

## 概要

一点更新・区間取得を $O(\log N)$ で行えます。

## 要求される性質

セグメント木で扱う要素は[モノイド](https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8E%E3%82%A4%E3%83%89)である必要があります[^1]。
モノイドとは、集合 $S$ と二項演算 $\cdot: S \times S \rightarrow S$ が与えられたときに、次の条件を満たすものです。

- 結合律: $(a \cdot b) \cdot c = a \cdot (b \cdot c) \quad (\forall a, b, c \in S)$ を満たす
- 単位元の存在: $e \cdot a = a \cdot e = a \quad (\forall a \in S)$ を満たす $e \in S$ が存在する

[^1]: 実際にはモノイドよりも条件を緩めることができます。
