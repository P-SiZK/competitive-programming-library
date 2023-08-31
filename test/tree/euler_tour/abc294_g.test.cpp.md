---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/segtree/segment_tree.hpp
    title: src/segtree/segment_tree.hpp
  - icon: ':question:'
    path: src/tree/euler_tour.hpp
    title: src/tree/euler_tour.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    PROBLEM: https://atcoder.jp/contests/abc294/tasks/abc294_g
    links:
    - https://atcoder.jp/contests/abc294/tasks/abc294_g
  bundledCode: "#line 1 \"test/tree/euler_tour/abc294_g.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://atcoder.jp/contests/abc294/tasks/abc294_g\n\n#line 1 \"src/segtree/segment_tree.hpp\"\
    \n#include <vector>\n\ntemplate<class T, class F>\nclass SegmentTree { // 0-indexed\n\
    private:\n\tint n_{};\n\tstd::vector<T> tree;\n\tF f; // function<T(T, T)>\n\t\
    T ti;\n\npublic:\n\tSegmentTree(F f, T ti) : f(f), ti(ti) {}\n\n\tvoid init(int\
    \ n) {\n\t\tn_ = 1;\n\t\twhile (n_ < n) n_ *= 2;\n\t\ttree.assign(2 * n_, ti);\n\
    \t}\n\n\tvoid build(std::vector<T> const &v) {\n\t\tint const N = v.size();\n\t\
    \tinit(N);\n\t\tfor (int i = 0; i < N; ++i) tree[n_ + i] = v[i];\n\t\tfor (int\
    \ i = n_ - 1; i > 0; --i) tree[i] = f(tree[2 * i], tree[2 * i + 1]);\n\t}\n\n\t\
    void update(int i, T const &x) {\n\t\ti += n_;\n\t\ttree[i] = x;\n\t\twhile (i\
    \ >>= 1) tree[i] = f(tree[2 * i], tree[2 * i + 1]);\n\t}\n\n\tT find(int l, int\
    \ r) { // [l, r)\n\t\tl += n_, r += n_;\n\t\tT ll = ti, rr = ti;\n\t\twhile (l\
    \ < r) {\n\t\t\tif (l & 1) ll = f(ll, tree[l++]);\n\t\t\tif (r & 1) rr = f(rr,\
    \ tree[--r]);\n\t\t\tl >>= 1, r >>= 1;\n\t\t}\n\t\treturn f(ll, rr);\n\t}\n\n\t\
    T at(int i) { return tree[i + n_]; }\n};\n#line 1 \"src/tree/euler_tour.hpp\"\n\
    #include <optional>\n#line 3 \"src/tree/euler_tour.hpp\"\n\nclass SparseTable\
    \ {\nprivate:\n\tstd::vector<std::vector<std::pair<int, int>>> table;\n\tstd::vector<int>\
    \ log_table;\n\npublic:\n\tSparseTable(std::vector<std::pair<int, int>> const\
    \ &v) {\n\t\tint const N = v.size();\n\t\tint h = 1;\n\t\twhile ((1 << h) <= N)\
    \ ++h;\n\t\ttable.assign(h, std::vector<std::pair<int, int>>(N));\n\t\tlog_table.assign(N\
    \ + 1, 0);\n\t\tfor (int i = 2; i <= N; ++i) log_table[i] = log_table[i >> 1]\
    \ + 1;\n\n\t\tfor (int i = 0; i < N; ++i) table[0][i] = v[i];\n\t\tfor (int i\
    \ = 1, k = 1; i < h; ++i, k <<= 1)\n\t\t\tfor (int j = 0; j < N; ++j)\n\t\t\t\t\
    table[i][j] = std::min(table[i - 1][j],\n\t\t\t\t\t\t\t\t\t   table[i - 1][std::min(j\
    \ + k, N - 1)]);\n\t}\n\n\tstd::pair<int, int> query(int l, int r) { // [l, r)\n\
    \t\tint k = log_table[r - l];\n\t\treturn std::min(table[k][l], table[k][r - (1\
    \ << k)]);\n\t}\n};\n\nclass EulerTour {\nprivate:\n\tstd::vector<int> down, up,\
    \ depth, terminal;\n\tstd::optional<SparseTable> st;\n\tstd::vector<std::vector<int>>\
    \ G;\n\n\tvoid dfs(int v, int p, int d) {\n\t\tdepth[terminal.size()] = d;\n\t\
    \tdown[v] = terminal.size();\n\t\tterminal.emplace_back(v);\n\t\tfor (int u :\
    \ G[v]) {\n\t\t\tif (u == p) continue;\n\t\t\tdfs(u, v, d + 1);\n\t\t}\n\t\tdepth[terminal.size()]\
    \ = d - 1;\n\t\tup[v] = terminal.size();\n\t\tterminal.emplace_back(p);\n\t}\n\
    \npublic:\n\tEulerTour(int n) : down(n), up(n), depth(n << 1), G(n) {}\n\n\tvoid\
    \ add_edge(int u, int v) {\n\t\tG[u].emplace_back(v);\n\t\tG[v].emplace_back(u);\n\
    \t}\n\n\tvoid build(int root = 0) {\n\t\tterminal.clear();\n\t\tdfs(root, -1,\
    \ 0);\n\t\tstd::vector<std::pair<int, int>> dep(terminal.size());\n\t\tfor (int\
    \ i = 0; i < (int)terminal.size(); ++i)\n\t\t\tdep[i] = {depth[i], terminal[i]};\n\
    \t\tst = SparseTable(dep);\n\t}\n\n\tstd::pair<int, int> index(int v) { return\
    \ {down[v], up[v]}; };\n\n\tint parent(int u, int v) { return depth[down[u]] <\
    \ depth[down[v]] ? u : v; }\n\n\tint child(int u, int v) { return depth[down[u]]\
    \ < depth[down[v]] ? v : u; }\n\n\tint lca(int u, int v) {\n\t\tif (down[u] >\
    \ down[v]) std::swap(u, v);\n\t\treturn st.value().query(down[u], down[v] + 1).second;\n\
    \t}\n\n\ttemplate<class F>\n\tvoid query_vertex(int u, int v, F f) {\n\t\tint\
    \ a = lca(u, v);\n\t\tf(down[a], down[u] + 1);\n\t\tf(down[a] + 1, down[v] + 1);\n\
    \t}\n\n\ttemplate<class F>\n\tvoid query_edge(int u, int v, F f) {\n\t\tint a\
    \ = lca(u, v);\n\t\tf(down[a] + 1, down[u] + 1);\n\t\tf(down[a] + 1, down[v] +\
    \ 1);\n\t}\n\n\ttemplate<class T, class F>\n\tvoid update_vertex(int v, T x, F\
    \ f) {\n\t\tf(down[v], x);\n\t\tf(up[v], -x);\n\t}\n\n\ttemplate<class T, class\
    \ F>\n\tvoid update_edge(int u, int v, T x, F f) {\n\t\tupdate_vertex(child(u,\
    \ v), x, f);\n\t}\n};\n#line 5 \"test/tree/euler_tour/abc294_g.test.cpp\"\n\n\
    #include <iostream>\n#include <tuple>\n#line 9 \"test/tree/euler_tour/abc294_g.test.cpp\"\
    \n\nusing namespace std;\n\nint main() {\n\tint n;\n\tcin >> n;\n\tvector<tuple<int,\
    \ int, long long>> uvw(n - 1);\n\tEulerTour et(n);\n\tfor (int i = 0; i < n -\
    \ 1; ++i) {\n\t\tauto &[u, v, w] = uvw[i];\n\t\tcin >> u >> v >> w;\n\t\t--u,\
    \ --v;\n\t\tet.add_edge(u, v);\n\t}\n\tet.build();\n\tSegmentTree st([](long long\
    \ a, long long b) { return a + b; }, 0LL);\n\tvector<long long> weight(2UL * n);\n\
    \tfor (int i = 1; i < n; ++i) {\n\t\tauto [u, v, w] = uvw[i - 1];\n\t\tauto [down,\
    \ up] = et.index(et.child(u, v));\n\t\tweight[down] = w;\n\t\tweight[up] = -w;\n\
    \t}\n\tst.build(weight);\n\n\tint q;\n\tcin >> q;\n\twhile (q--) {\n\t\tint c;\n\
    \t\tcin >> c;\n\t\tif (c == 1) {\n\t\t\tint i;\n\t\t\tlong long w;\n\t\t\tcin\
    \ >> i >> w;\n\t\t\tauto [u, v, _] = uvw[i - 1];\n\t\t\tauto update = [&](int\
    \ i, long long x) { st.update(i, x); };\n\t\t\tet.update_edge(u, v, w, update);\n\
    \t\t} else {\n\t\t\tint u, v;\n\t\t\tcin >> u >> v;\n\t\t\tlong long res = 0;\n\
    \t\t\tauto query = [&](int l, int r) { res += st.find(l, r); };\n\t\t\tet.query_edge(u\
    \ - 1, v - 1, query);\n\t\t\tcout << res << endl;\n\t\t}\n\t}\n\n\treturn 0;\n\
    }\n"
  code: "// verification-helper: PROBLEM https://atcoder.jp/contests/abc294/tasks/abc294_g\n\
    \n#include \"src/segtree/segment_tree.hpp\"\n#include \"src/tree/euler_tour.hpp\"\
    \n\n#include <iostream>\n#include <tuple>\n#include <vector>\n\nusing namespace\
    \ std;\n\nint main() {\n\tint n;\n\tcin >> n;\n\tvector<tuple<int, int, long long>>\
    \ uvw(n - 1);\n\tEulerTour et(n);\n\tfor (int i = 0; i < n - 1; ++i) {\n\t\tauto\
    \ &[u, v, w] = uvw[i];\n\t\tcin >> u >> v >> w;\n\t\t--u, --v;\n\t\tet.add_edge(u,\
    \ v);\n\t}\n\tet.build();\n\tSegmentTree st([](long long a, long long b) { return\
    \ a + b; }, 0LL);\n\tvector<long long> weight(2UL * n);\n\tfor (int i = 1; i <\
    \ n; ++i) {\n\t\tauto [u, v, w] = uvw[i - 1];\n\t\tauto [down, up] = et.index(et.child(u,\
    \ v));\n\t\tweight[down] = w;\n\t\tweight[up] = -w;\n\t}\n\tst.build(weight);\n\
    \n\tint q;\n\tcin >> q;\n\twhile (q--) {\n\t\tint c;\n\t\tcin >> c;\n\t\tif (c\
    \ == 1) {\n\t\t\tint i;\n\t\t\tlong long w;\n\t\t\tcin >> i >> w;\n\t\t\tauto\
    \ [u, v, _] = uvw[i - 1];\n\t\t\tauto update = [&](int i, long long x) { st.update(i,\
    \ x); };\n\t\t\tet.update_edge(u, v, w, update);\n\t\t} else {\n\t\t\tint u, v;\n\
    \t\t\tcin >> u >> v;\n\t\t\tlong long res = 0;\n\t\t\tauto query = [&](int l,\
    \ int r) { res += st.find(l, r); };\n\t\t\tet.query_edge(u - 1, v - 1, query);\n\
    \t\t\tcout << res << endl;\n\t\t}\n\t}\n\n\treturn 0;\n}\n"
  dependsOn:
  - src/segtree/segment_tree.hpp
  - src/tree/euler_tour.hpp
  isVerificationFile: true
  path: test/tree/euler_tour/abc294_g.test.cpp
  requiredBy: []
  timestamp: '2023-08-31 13:01:25+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/tree/euler_tour/abc294_g.test.cpp
layout: document
redirect_from:
- /verify/test/tree/euler_tour/abc294_g.test.cpp
- /verify/test/tree/euler_tour/abc294_g.test.cpp.html
title: test/tree/euler_tour/abc294_g.test.cpp
---
