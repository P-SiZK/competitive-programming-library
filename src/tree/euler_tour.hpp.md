---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/datastructure/sparse_table.hpp
    title: Sparse Table
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
  bundledCode: "#line 1 \"src/tree/euler_tour.hpp\"\n\n\n\n#line 1 \"src/datastructure/sparse_table.hpp\"\
    \n\n\n\n#include <vector>\n\ntemplate<class T, class F>\nclass SparseTable {\n\
    private:\n\tstd::vector<std::vector<T>> table;\n\tstd::vector<int> log_table;\n\
    \tF f;\n\npublic:\n\tSparseTable(std::vector<T> const &v, F f) : f(f) {\n\t\t\
    int n = v.size();\n\t\tint h = 1;\n\t\twhile ((1 << h) <= n) ++h;\n\t\ttable.assign(h,\
    \ std::vector<T>(n));\n\t\tlog_table.assign(n + 1, 0);\n\t\tfor (int i = 2; i\
    \ <= n; ++i) log_table[i] = log_table[i >> 1] + 1;\n\n\t\tfor (int i = 0; i <\
    \ n; ++i) table[0][i] = v[i];\n\t\tfor (int i = 1, k = 1; i < h; ++i, k <<= 1)\n\
    \t\t\tfor (int j = 0; j < n; ++j)\n\t\t\t\ttable[i][j] = f(table[i - 1][j], table[i\
    \ - 1][std::min(j + k, n - 1)]);\n\t}\n\n\tT query(int l, int r) { // [l, r)\n\
    \t\tint k = log_table[r - l];\n\t\treturn f(table[k][l], table[k][r - (1 << k)]);\n\
    \t}\n};\n\n\n#line 5 \"src/tree/euler_tour.hpp\"\n\n#include <optional>\n#line\
    \ 8 \"src/tree/euler_tour.hpp\"\n\nclass EulerTour {\nprivate:\n\tstd::vector<int>\
    \ down, up, depth, terminal;\n\tstd::optional<\n\t\tSparseTable<std::pair<int,\
    \ int>, decltype(&std::min<std::pair<int, int>>)>>\n\t\tst;\n\tstd::vector<std::vector<int>>\
    \ G;\n\n\tvoid dfs(int v, int p, int d) {\n\t\tdepth[terminal.size()] = d;\n\t\
    \tdown[v] = terminal.size();\n\t\tterminal.emplace_back(v);\n\t\tfor (int u :\
    \ G[v]) {\n\t\t\tif (u == p) continue;\n\t\t\tdfs(u, v, d + 1);\n\t\t}\n\t\tdepth[terminal.size()]\
    \ = d - 1;\n\t\tup[v] = terminal.size();\n\t\tterminal.emplace_back(p);\n\t}\n\
    \npublic:\n\tEulerTour(int n) : down(n), up(n), depth(n << 1), G(n) {}\n\n\tvoid\
    \ add_edge(int u, int v) {\n\t\tG[u].emplace_back(v);\n\t\tG[v].emplace_back(u);\n\
    \t}\n\n\tvoid build(int root = 0) {\n\t\tterminal.clear();\n\t\tdfs(root, -1,\
    \ 0);\n\t\tstd::vector<std::pair<int, int>> dep(terminal.size());\n\t\tfor (int\
    \ i = 0; i < (int)terminal.size(); ++i) dep[i] = {depth[i], terminal[i]};\n\t\t\
    st = SparseTable(dep, std::min<std::pair<int, int>>);\n\t}\n\n\tstd::pair<int,\
    \ int> index(int v) { return {down[v], up[v]}; };\n\n\tint parent(int u, int v)\
    \ { return depth[down[u]] < depth[down[v]] ? u : v; }\n\n\tint child(int u, int\
    \ v) { return depth[down[u]] < depth[down[v]] ? v : u; }\n\n\tint lca(int u, int\
    \ v) {\n\t\tif (down[u] > down[v]) std::swap(u, v);\n\t\treturn st.value().query(down[u],\
    \ down[v] + 1).second;\n\t}\n\n\ttemplate<class F>\n\tvoid query_vertex(int u,\
    \ int v, F f) {\n\t\tint a = lca(u, v);\n\t\tf(down[a], down[u] + 1);\n\t\tf(down[a]\
    \ + 1, down[v] + 1);\n\t}\n\n\ttemplate<class F>\n\tvoid query_edge(int u, int\
    \ v, F f) {\n\t\tint a = lca(u, v);\n\t\tf(down[a] + 1, down[u] + 1);\n\t\tf(down[a]\
    \ + 1, down[v] + 1);\n\t}\n\n\ttemplate<class T, class F>\n\tvoid update_vertex(int\
    \ v, T x, F f) {\n\t\tf(down[v], x);\n\t\tf(up[v], -x);\n\t}\n\n\ttemplate<class\
    \ T, class F>\n\tvoid update_edge(int u, int v, T x, F f) {\n\t\tupdate_vertex(child(u,\
    \ v), x, f);\n\t}\n};\n\n\n"
  code: "#ifndef TREE_EULER_TOUR_HPP\n#define TREE_EULER_TOUR_HPP\n\n#include \"src/datastructure/sparse_table.hpp\"\
    \n\n#include <optional>\n#include <vector>\n\nclass EulerTour {\nprivate:\n\t\
    std::vector<int> down, up, depth, terminal;\n\tstd::optional<\n\t\tSparseTable<std::pair<int,\
    \ int>, decltype(&std::min<std::pair<int, int>>)>>\n\t\tst;\n\tstd::vector<std::vector<int>>\
    \ G;\n\n\tvoid dfs(int v, int p, int d) {\n\t\tdepth[terminal.size()] = d;\n\t\
    \tdown[v] = terminal.size();\n\t\tterminal.emplace_back(v);\n\t\tfor (int u :\
    \ G[v]) {\n\t\t\tif (u == p) continue;\n\t\t\tdfs(u, v, d + 1);\n\t\t}\n\t\tdepth[terminal.size()]\
    \ = d - 1;\n\t\tup[v] = terminal.size();\n\t\tterminal.emplace_back(p);\n\t}\n\
    \npublic:\n\tEulerTour(int n) : down(n), up(n), depth(n << 1), G(n) {}\n\n\tvoid\
    \ add_edge(int u, int v) {\n\t\tG[u].emplace_back(v);\n\t\tG[v].emplace_back(u);\n\
    \t}\n\n\tvoid build(int root = 0) {\n\t\tterminal.clear();\n\t\tdfs(root, -1,\
    \ 0);\n\t\tstd::vector<std::pair<int, int>> dep(terminal.size());\n\t\tfor (int\
    \ i = 0; i < (int)terminal.size(); ++i) dep[i] = {depth[i], terminal[i]};\n\t\t\
    st = SparseTable(dep, std::min<std::pair<int, int>>);\n\t}\n\n\tstd::pair<int,\
    \ int> index(int v) { return {down[v], up[v]}; };\n\n\tint parent(int u, int v)\
    \ { return depth[down[u]] < depth[down[v]] ? u : v; }\n\n\tint child(int u, int\
    \ v) { return depth[down[u]] < depth[down[v]] ? v : u; }\n\n\tint lca(int u, int\
    \ v) {\n\t\tif (down[u] > down[v]) std::swap(u, v);\n\t\treturn st.value().query(down[u],\
    \ down[v] + 1).second;\n\t}\n\n\ttemplate<class F>\n\tvoid query_vertex(int u,\
    \ int v, F f) {\n\t\tint a = lca(u, v);\n\t\tf(down[a], down[u] + 1);\n\t\tf(down[a]\
    \ + 1, down[v] + 1);\n\t}\n\n\ttemplate<class F>\n\tvoid query_edge(int u, int\
    \ v, F f) {\n\t\tint a = lca(u, v);\n\t\tf(down[a] + 1, down[u] + 1);\n\t\tf(down[a]\
    \ + 1, down[v] + 1);\n\t}\n\n\ttemplate<class T, class F>\n\tvoid update_vertex(int\
    \ v, T x, F f) {\n\t\tf(down[v], x);\n\t\tf(up[v], -x);\n\t}\n\n\ttemplate<class\
    \ T, class F>\n\tvoid update_edge(int u, int v, T x, F f) {\n\t\tupdate_vertex(child(u,\
    \ v), x, f);\n\t}\n};\n\n#endif // TREE_EULER_TOUR_HPP\n"
  dependsOn:
  - src/datastructure/sparse_table.hpp
  isVerificationFile: false
  path: src/tree/euler_tour.hpp
  requiredBy: []
  timestamp: '2023-08-31 15:37:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/euler_tour/aoj_grl_5_d.test.cpp
  - test/tree/euler_tour/yosupo_vertex_add_path_sum.test.cpp
  - test/tree/euler_tour/aoj_grl_5_c.test.cpp
  - test/tree/euler_tour/atcoder_abc294_g.test.cpp
documentation_of: src/tree/euler_tour.hpp
layout: document
title: Euler Tour
---
