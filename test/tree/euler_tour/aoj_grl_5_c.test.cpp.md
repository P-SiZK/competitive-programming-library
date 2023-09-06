---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/datastructure/sparse_table.hpp
    title: Sparse Table
  - icon: ':heavy_check_mark:'
    path: src/tree/euler_tour.hpp
    title: Euler Tour
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C
  bundledCode: "#line 1 \"test/tree/euler_tour/aoj_grl_5_c.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C\n\n\
    #line 1 \"src/tree/euler_tour.hpp\"\n\n\n\n#line 1 \"src/datastructure/sparse_table.hpp\"\
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
    \ v), x, f);\n\t}\n};\n\n\n#line 4 \"test/tree/euler_tour/aoj_grl_5_c.test.cpp\"\
    \n\n#include <iostream>\n\nusing namespace std;\n\nint main() {\n\tint n;\n\t\
    cin >> n;\n\tEulerTour et(n);\n\tfor (int i = 0; i < n; ++i) {\n\t\tint k;\n\t\
    \tcin >> k;\n\t\tfor (int j = 0; j < k; ++j) {\n\t\t\tint c;\n\t\t\tcin >> c;\n\
    \t\t\tet.add_edge(i, c);\n\t\t}\n\t}\n\tet.build();\n\n\tint q;\n\tcin >> q;\n\
    \twhile (q--) {\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\tcout << et.lca(u, v) <<\
    \ endl;\n\t}\n\n\treturn 0;\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C\n\
    \n#include \"src/tree/euler_tour.hpp\"\n\n#include <iostream>\n\nusing namespace\
    \ std;\n\nint main() {\n\tint n;\n\tcin >> n;\n\tEulerTour et(n);\n\tfor (int\
    \ i = 0; i < n; ++i) {\n\t\tint k;\n\t\tcin >> k;\n\t\tfor (int j = 0; j < k;\
    \ ++j) {\n\t\t\tint c;\n\t\t\tcin >> c;\n\t\t\tet.add_edge(i, c);\n\t\t}\n\t}\n\
    \tet.build();\n\n\tint q;\n\tcin >> q;\n\twhile (q--) {\n\t\tint u, v;\n\t\tcin\
    \ >> u >> v;\n\t\tcout << et.lca(u, v) << endl;\n\t}\n\n\treturn 0;\n}\n"
  dependsOn:
  - src/tree/euler_tour.hpp
  - src/datastructure/sparse_table.hpp
  isVerificationFile: true
  path: test/tree/euler_tour/aoj_grl_5_c.test.cpp
  requiredBy: []
  timestamp: '2023-09-06 15:21:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree/euler_tour/aoj_grl_5_c.test.cpp
layout: document
redirect_from:
- /verify/test/tree/euler_tour/aoj_grl_5_c.test.cpp
- /verify/test/tree/euler_tour/aoj_grl_5_c.test.cpp.html
title: test/tree/euler_tour/aoj_grl_5_c.test.cpp
---
