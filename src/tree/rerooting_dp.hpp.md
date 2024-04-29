---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/tree/rerooting_dp/aoj_1595.test.cpp
    title: test/tree/rerooting_dp/aoj_1595.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/rerooting_dp/aoj_grl_5_a.test.cpp
    title: test/tree/rerooting_dp/aoj_grl_5_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/rerooting_dp/aoj_grl_5_b.test.cpp
    title: test/tree/rerooting_dp/aoj_grl_5_b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/tree/rerooting_dp.hpp\"\n\n\n\n#include <utility>\n\
    #include <vector>\n\ntemplate<class T, class E, class F, class G>\nclass RerootingDP\
    \ {\nprivate:\n\tstd::vector<std::vector<std::pair<int, E>>> graph;\n\tstd::vector<T>\
    \ dp1, dp2;\n\tF f; // function<T(T, T)>\n\tG g; // function<T(T, E)>\n\tT ti;\n\
    \n\tvoid dfs(int v, int p) {\n\t\tfor (auto const &[nv, e] : graph[v]) {\n\t\t\
    \tif (nv == p) continue;\n\t\t\tdfs(nv, v);\n\t\t\tdp1[v] = f(dp1[v], g(dp1[nv],\
    \ e));\n\t\t}\n\t}\n\n\tvoid dfs2(int v, int p, T ndp) {\n\t\tint size = graph[v].size();\n\
    \t\tstd::vector<T> lcum(size + 1, ti), rcum(size + 1, ti);\n\n\t\tfor (int i =\
    \ 0; i < size; ++i) {\n\t\t\tauto const &[nv, e] = graph[v][i];\n\t\t\tif (nv\
    \ == p) lcum[i + 1] = f(lcum[i], g(ndp, e));\n\t\t\telse lcum[i + 1] = f(lcum[i],\
    \ g(dp1[nv], e));\n\t\t}\n\t\tfor (int i = size - 1; i >= 0; --i) {\n\t\t\tauto\
    \ const &[nv, e] = graph[v][i];\n\t\t\tif (nv == p) rcum[i] = f(g(ndp, e), rcum[i\
    \ + 1]);\n\t\t\telse rcum[i] = f(g(dp1[nv], e), rcum[i + 1]);\n\t\t}\n\n\t\tdp2[v]\
    \ = lcum.back();\n\t\tfor (int i = 0; i < size; ++i) {\n\t\t\tauto const &[nv,\
    \ e] = graph[v][i];\n\t\t\tif (nv == p) continue;\n\t\t\tdfs2(nv, v, f(lcum[i],\
    \ rcum[i + 1]));\n\t\t}\n\t}\n\npublic:\n\tRerootingDP(int n, F f, G g, T ti)\
    \ :\n\t\tgraph(n), dp1(n), dp2(n), f(f), g(g), ti(std::move(ti)) {}\n\n\tvoid\
    \ add_edge(int u, int v, E const &e) {\n\t\tgraph[u].emplace_back(v, e);\n\t\t\
    graph[v].emplace_back(u, e);\n\t}\n\n\tstd::vector<T> build(int v = 0, int p =\
    \ -1) {\n\t\tdfs(v, p);\n\t\treturn dp1;\n\t}\n\n\tstd::vector<T> reroot(int v\
    \ = 0, int p = -1) { return reroot(v, p, ti); }\n\n\tstd::vector<T> reroot(int\
    \ v, int p, T ndp) {\n\t\tdfs2(v, p, ndp);\n\t\treturn dp2;\n\t}\n};\n\n\n"
  code: "#ifndef TREE_REROOTING_DP\n#define TREE_REROOTING_DP\n\n#include <utility>\n\
    #include <vector>\n\ntemplate<class T, class E, class F, class G>\nclass RerootingDP\
    \ {\nprivate:\n\tstd::vector<std::vector<std::pair<int, E>>> graph;\n\tstd::vector<T>\
    \ dp1, dp2;\n\tF f; // function<T(T, T)>\n\tG g; // function<T(T, E)>\n\tT ti;\n\
    \n\tvoid dfs(int v, int p) {\n\t\tfor (auto const &[nv, e] : graph[v]) {\n\t\t\
    \tif (nv == p) continue;\n\t\t\tdfs(nv, v);\n\t\t\tdp1[v] = f(dp1[v], g(dp1[nv],\
    \ e));\n\t\t}\n\t}\n\n\tvoid dfs2(int v, int p, T ndp) {\n\t\tint size = graph[v].size();\n\
    \t\tstd::vector<T> lcum(size + 1, ti), rcum(size + 1, ti);\n\n\t\tfor (int i =\
    \ 0; i < size; ++i) {\n\t\t\tauto const &[nv, e] = graph[v][i];\n\t\t\tif (nv\
    \ == p) lcum[i + 1] = f(lcum[i], g(ndp, e));\n\t\t\telse lcum[i + 1] = f(lcum[i],\
    \ g(dp1[nv], e));\n\t\t}\n\t\tfor (int i = size - 1; i >= 0; --i) {\n\t\t\tauto\
    \ const &[nv, e] = graph[v][i];\n\t\t\tif (nv == p) rcum[i] = f(g(ndp, e), rcum[i\
    \ + 1]);\n\t\t\telse rcum[i] = f(g(dp1[nv], e), rcum[i + 1]);\n\t\t}\n\n\t\tdp2[v]\
    \ = lcum.back();\n\t\tfor (int i = 0; i < size; ++i) {\n\t\t\tauto const &[nv,\
    \ e] = graph[v][i];\n\t\t\tif (nv == p) continue;\n\t\t\tdfs2(nv, v, f(lcum[i],\
    \ rcum[i + 1]));\n\t\t}\n\t}\n\npublic:\n\tRerootingDP(int n, F f, G g, T ti)\
    \ :\n\t\tgraph(n), dp1(n), dp2(n), f(f), g(g), ti(std::move(ti)) {}\n\n\tvoid\
    \ add_edge(int u, int v, E const &e) {\n\t\tgraph[u].emplace_back(v, e);\n\t\t\
    graph[v].emplace_back(u, e);\n\t}\n\n\tstd::vector<T> build(int v = 0, int p =\
    \ -1) {\n\t\tdfs(v, p);\n\t\treturn dp1;\n\t}\n\n\tstd::vector<T> reroot(int v\
    \ = 0, int p = -1) { return reroot(v, p, ti); }\n\n\tstd::vector<T> reroot(int\
    \ v, int p, T ndp) {\n\t\tdfs2(v, p, ndp);\n\t\treturn dp2;\n\t}\n};\n\n#endif\
    \ // TREE_REROOTING_DP\n"
  dependsOn: []
  isVerificationFile: false
  path: src/tree/rerooting_dp.hpp
  requiredBy: []
  timestamp: '2024-04-29 16:58:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/rerooting_dp/aoj_grl_5_b.test.cpp
  - test/tree/rerooting_dp/aoj_1595.test.cpp
  - test/tree/rerooting_dp/aoj_grl_5_a.test.cpp
documentation_of: src/tree/rerooting_dp.hpp
layout: document
title: Rerooting DP
---
