---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/flow/ford_fulkerson/aoj_grl_6_a.test.cpp
    title: test/flow/ford_fulkerson/aoj_grl_6_a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/flow/ford_fulkerson.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <limits>\n#include <vector>\n\ntemplate<class T>\nclass FordFulkerson\
    \ {\nprivate:\n\tstruct Edge {\n\t\tint to, rev;\n\t\tT cap;\n\n\t\tEdge(int to,\
    \ int cap, int rev) : to(to), rev(rev), cap(cap) {}\n\t};\n\n\tstatic constexpr\
    \ T INF = std::numeric_limits<T>::max();\n\n\tstd::vector<std::vector<Edge>> g;\n\
    \tstd::vector<int> used;\n\npublic:\n\tFordFulkerson(int n) : g(n), used(n) {}\n\
    \n\tvoid add_edge(int from, int to, T cap, bool directed = true) {\n\t\tg[from].emplace_back(to,\
    \ cap, g[to].size());\n\t\tg[to].emplace_back(from, (directed ? 0 : cap), g[from].size()\
    \ - 1);\n\t}\n\n\tT dfs(int v, int t, T f) {\n\t\tif (v == t) return f;\n\t\t\
    used[v] = true;\n\t\tfor (auto &e : g[v]) {\n\t\t\tif (!used[e.to] && e.cap >\
    \ 0) {\n\t\t\t\tT d = dfs(e.to, t, std::min(f, e.cap));\n\t\t\t\tif (d > 0) {\n\
    \t\t\t\t\te.cap -= d;\n\t\t\t\t\tg[e.to][e.rev].cap += d;\n\t\t\t\t\treturn d;\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\t}\n\n\tT max_flow(int s, int t) {\n\
    \t\tT flow = 0;\n\t\twhile (true) {\n\t\t\tused.assign(g.size(), 0);\n\t\t\tT\
    \ f = dfs(s, t, INF);\n\t\t\tif (f == 0) break;\n\t\t\tflow += f;\n\t\t}\n\t\t\
    return flow;\n\t}\n};\n\n\n"
  code: "#ifndef FLOW_FORD_FULKERSON_HPP\n#define FLOW_FORD_FULKERSON_HPP\n\n#include\
    \ <algorithm>\n#include <limits>\n#include <vector>\n\ntemplate<class T>\nclass\
    \ FordFulkerson {\nprivate:\n\tstruct Edge {\n\t\tint to, rev;\n\t\tT cap;\n\n\
    \t\tEdge(int to, int cap, int rev) : to(to), rev(rev), cap(cap) {}\n\t};\n\n\t\
    static constexpr T INF = std::numeric_limits<T>::max();\n\n\tstd::vector<std::vector<Edge>>\
    \ g;\n\tstd::vector<int> used;\n\npublic:\n\tFordFulkerson(int n) : g(n), used(n)\
    \ {}\n\n\tvoid add_edge(int from, int to, T cap, bool directed = true) {\n\t\t\
    g[from].emplace_back(to, cap, g[to].size());\n\t\tg[to].emplace_back(from, (directed\
    \ ? 0 : cap), g[from].size() - 1);\n\t}\n\n\tT dfs(int v, int t, T f) {\n\t\t\
    if (v == t) return f;\n\t\tused[v] = true;\n\t\tfor (auto &e : g[v]) {\n\t\t\t\
    if (!used[e.to] && e.cap > 0) {\n\t\t\t\tT d = dfs(e.to, t, std::min(f, e.cap));\n\
    \t\t\t\tif (d > 0) {\n\t\t\t\t\te.cap -= d;\n\t\t\t\t\tg[e.to][e.rev].cap += d;\n\
    \t\t\t\t\treturn d;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\t}\n\n\tT max_flow(int\
    \ s, int t) {\n\t\tT flow = 0;\n\t\twhile (true) {\n\t\t\tused.assign(g.size(),\
    \ 0);\n\t\t\tT f = dfs(s, t, INF);\n\t\t\tif (f == 0) break;\n\t\t\tflow += f;\n\
    \t\t}\n\t\treturn flow;\n\t}\n};\n\n#endif // FLOW_FORD_FULKERSON_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: src/flow/ford_fulkerson.hpp
  requiredBy: []
  timestamp: '2023-12-12 23:23:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/flow/ford_fulkerson/aoj_grl_6_a.test.cpp
documentation_of: src/flow/ford_fulkerson.hpp
layout: document
title: Ford-Fulkerson
---
