---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/tree/euler_tour/abc294_g.test.cpp
    title: test/tree/euler_tour/abc294_g.test.cpp
  - icon: ':x:'
    path: test/tree/euler_tour/grl_5_c.test.cpp
    title: test/tree/euler_tour/grl_5_c.test.cpp
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
  bundledCode: "#line 1 \"src/tree/euler_tour.cpp\"\n#include <optional>\n#include\
    \ <vector>\n\nusing namespace std;\n\nclass SparseTable {\nprivate:\n\tvector<vector<pair<int,\
    \ int>>> table;\n\tvector<int> log_table;\n\npublic:\n\tSparseTable(const vector<pair<int,\
    \ int>> &v) {\n\t\tint n = v.size(), h = 1;\n\t\twhile ((1 << h) <= n) ++h;\n\t\
    \ttable.assign(h, vector<pair<int, int>>(n));\n\t\tlog_table.assign(n + 1, 0);\n\
    \t\tfor (int i = 2; i <= n; ++i) log_table[i] = log_table[i >> 1] + 1;\n\n\t\t\
    for (int i = 0; i < n; ++i) table[0][i] = v[i];\n\t\tfor (int i = 1, k = 1; i\
    \ < h; ++i, k <<= 1)\n\t\t\tfor (int j = 0; j < n; ++j)\n\t\t\t\ttable[i][j] =\n\
    \t\t\t\t\tmin(table[i - 1][j], table[i - 1][min(j + k, n - 1)]);\n\t}\n\n\tpair<int,\
    \ int> query(int l, int r) { // [l, r)\n\t\tint k = log_table[r - l];\n\t\treturn\
    \ min(table[k][l], table[k][r - (1 << k)]);\n\t}\n};\n\nclass EulerTour {\nprivate:\n\
    \tvector<int> down, up, depth, terminal;\n\toptional<SparseTable> st;\n\n\tvoid\
    \ dfs(int v, int p, int d) {\n\t\tdepth[terminal.size()] = d;\n\t\tdown[v] = terminal.size();\n\
    \t\tterminal.emplace_back(v);\n\t\tfor (int u : G[v]) {\n\t\t\tif (u == p) continue;\n\
    \t\t\tdfs(u, v, d + 1);\n\t\t}\n\t\tdepth[terminal.size()] = d - 1;\n\t\tup[v]\
    \ = terminal.size();\n\t\tterminal.emplace_back(p);\n\t}\n\npublic:\n\tvector<vector<int>>\
    \ G;\n\n\tEulerTour(int n) : down(n), up(n), depth(n << 1), G(n) {}\n\n\tvoid\
    \ add_edge(int u, int v) {\n\t\tG[u].emplace_back(v);\n\t\tG[v].emplace_back(u);\n\
    \t}\n\n\tvoid build(int root = 0) {\n\t\tterminal.clear();\n\t\tdfs(root, -1,\
    \ 0);\n\t\tvector<pair<int, int>> dep(terminal.size());\n\t\tfor (int i = 0; i\
    \ < (int)terminal.size(); ++i)\n\t\t\tdep[i] = {depth[i], terminal[i]};\n\t\t\
    st = SparseTable(dep);\n\t}\n\n\tpair<int, int> index(int v) { return {down[v],\
    \ up[v]}; };\n\n\tint parent(int u, int v) { return depth[down[u]] < depth[down[v]]\
    \ ? u : v; }\n\n\tint child(int u, int v) { return depth[down[u]] < depth[down[v]]\
    \ ? v : u; }\n\n\tint lca(int u, int v) {\n\t\tif (down[u] > down[v]) swap(u,\
    \ v);\n\t\treturn st.value().query(down[u], down[v] + 1).second;\n\t}\n\n\ttemplate<class\
    \ F>\n\tvoid query_vertex(int u, int v, F f) {\n\t\tint a = lca(u, v);\n\t\tf(down[a],\
    \ down[u] + 1);\n\t\tf(down[a] + 1, down[v] + 1);\n\t}\n\n\ttemplate<class F>\n\
    \tvoid query_edge(int u, int v, F f) {\n\t\tint a = lca(u, v);\n\t\tf(down[a]\
    \ + 1, down[u] + 1);\n\t\tf(down[a] + 1, down[v] + 1);\n\t}\n\n\ttemplate<class\
    \ T, class F>\n\tvoid update_vertex(int v, T x, F f) {\n\t\tf(down[v], x);\n\t\
    \tf(up[v], -x);\n\t}\n\n\ttemplate<class T, class F>\n\tvoid update_edge(int u,\
    \ int v, T x, F f) {\n\t\tupdate_vertex(child(u, v), x, f);\n\t}\n};\n"
  code: "#include <optional>\n#include <vector>\n\nusing namespace std;\n\nclass SparseTable\
    \ {\nprivate:\n\tvector<vector<pair<int, int>>> table;\n\tvector<int> log_table;\n\
    \npublic:\n\tSparseTable(const vector<pair<int, int>> &v) {\n\t\tint n = v.size(),\
    \ h = 1;\n\t\twhile ((1 << h) <= n) ++h;\n\t\ttable.assign(h, vector<pair<int,\
    \ int>>(n));\n\t\tlog_table.assign(n + 1, 0);\n\t\tfor (int i = 2; i <= n; ++i)\
    \ log_table[i] = log_table[i >> 1] + 1;\n\n\t\tfor (int i = 0; i < n; ++i) table[0][i]\
    \ = v[i];\n\t\tfor (int i = 1, k = 1; i < h; ++i, k <<= 1)\n\t\t\tfor (int j =\
    \ 0; j < n; ++j)\n\t\t\t\ttable[i][j] =\n\t\t\t\t\tmin(table[i - 1][j], table[i\
    \ - 1][min(j + k, n - 1)]);\n\t}\n\n\tpair<int, int> query(int l, int r) { //\
    \ [l, r)\n\t\tint k = log_table[r - l];\n\t\treturn min(table[k][l], table[k][r\
    \ - (1 << k)]);\n\t}\n};\n\nclass EulerTour {\nprivate:\n\tvector<int> down, up,\
    \ depth, terminal;\n\toptional<SparseTable> st;\n\n\tvoid dfs(int v, int p, int\
    \ d) {\n\t\tdepth[terminal.size()] = d;\n\t\tdown[v] = terminal.size();\n\t\t\
    terminal.emplace_back(v);\n\t\tfor (int u : G[v]) {\n\t\t\tif (u == p) continue;\n\
    \t\t\tdfs(u, v, d + 1);\n\t\t}\n\t\tdepth[terminal.size()] = d - 1;\n\t\tup[v]\
    \ = terminal.size();\n\t\tterminal.emplace_back(p);\n\t}\n\npublic:\n\tvector<vector<int>>\
    \ G;\n\n\tEulerTour(int n) : down(n), up(n), depth(n << 1), G(n) {}\n\n\tvoid\
    \ add_edge(int u, int v) {\n\t\tG[u].emplace_back(v);\n\t\tG[v].emplace_back(u);\n\
    \t}\n\n\tvoid build(int root = 0) {\n\t\tterminal.clear();\n\t\tdfs(root, -1,\
    \ 0);\n\t\tvector<pair<int, int>> dep(terminal.size());\n\t\tfor (int i = 0; i\
    \ < (int)terminal.size(); ++i)\n\t\t\tdep[i] = {depth[i], terminal[i]};\n\t\t\
    st = SparseTable(dep);\n\t}\n\n\tpair<int, int> index(int v) { return {down[v],\
    \ up[v]}; };\n\n\tint parent(int u, int v) { return depth[down[u]] < depth[down[v]]\
    \ ? u : v; }\n\n\tint child(int u, int v) { return depth[down[u]] < depth[down[v]]\
    \ ? v : u; }\n\n\tint lca(int u, int v) {\n\t\tif (down[u] > down[v]) swap(u,\
    \ v);\n\t\treturn st.value().query(down[u], down[v] + 1).second;\n\t}\n\n\ttemplate<class\
    \ F>\n\tvoid query_vertex(int u, int v, F f) {\n\t\tint a = lca(u, v);\n\t\tf(down[a],\
    \ down[u] + 1);\n\t\tf(down[a] + 1, down[v] + 1);\n\t}\n\n\ttemplate<class F>\n\
    \tvoid query_edge(int u, int v, F f) {\n\t\tint a = lca(u, v);\n\t\tf(down[a]\
    \ + 1, down[u] + 1);\n\t\tf(down[a] + 1, down[v] + 1);\n\t}\n\n\ttemplate<class\
    \ T, class F>\n\tvoid update_vertex(int v, T x, F f) {\n\t\tf(down[v], x);\n\t\
    \tf(up[v], -x);\n\t}\n\n\ttemplate<class T, class F>\n\tvoid update_edge(int u,\
    \ int v, T x, F f) {\n\t\tupdate_vertex(child(u, v), x, f);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/tree/euler_tour.cpp
  requiredBy: []
  timestamp: '2023-08-20 06:31:19+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/tree/euler_tour/grl_5_d.test.cpp
  - test/tree/euler_tour/grl_5_c.test.cpp
  - test/tree/euler_tour/vertex_add_path_sum.test.cpp
  - test/tree/euler_tour/abc294_g.test.cpp
documentation_of: src/tree/euler_tour.cpp
layout: document
redirect_from:
- /library/src/tree/euler_tour.cpp
- /library/src/tree/euler_tour.cpp.html
title: src/tree/euler_tour.cpp
---
