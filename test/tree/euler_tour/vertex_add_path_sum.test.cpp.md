---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/segtree/segment_tree.cpp
    title: src/segtree/segment_tree.cpp
  - icon: ':heavy_check_mark:'
    path: src/tree/euler_tour.cpp
    title: src/tree/euler_tour.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"test/tree/euler_tour/vertex_add_path_sum.test.cpp\"\n//\
    \ verification-helper: PROBLEM https://judge.yosupo.jp/problem/vertex_add_path_sum\n\
    \n#line 1 \"src/segtree/segment_tree.cpp\"\n#include <vector>\n\nusing namespace\
    \ std;\n\ntemplate<class T, class F>\nstruct SegmentTree { // 0-indexed\n\tint\
    \ n;\n\tvector<T> tree;\n\tconst F f; // function<T(T, T)>\n\tconst T ti;\n\n\t\
    SegmentTree(F f, T ti) : f(f), ti(ti) {}\n\n\tvoid init(int n_) {\n\t\tn = 1;\n\
    \t\twhile (n < n_) n *= 2;\n\t\ttree.assign(2 * n, ti);\n\t}\n\n\tvoid build(const\
    \ vector<T> &v) {\n\t\tint n_ = v.size();\n\t\tinit(n_);\n\t\tfor (int i = 0;\
    \ i < n_; ++i) tree[n + i] = v[i];\n\t\tfor (int i = n - 1; i > 0; --i)\n\t\t\t\
    tree[i] = f(tree[2 * i], tree[2 * i + 1]);\n\t}\n\n\tvoid update(int i, const\
    \ T &x) {\n\t\ti += n;\n\t\ttree[i] = x;\n\t\twhile (i >>= 1) tree[i] = f(tree[2\
    \ * i], tree[2 * i + 1]);\n\t}\n\n\tT find(int l, int r) { // [l, r)\n\t\tl +=\
    \ n, r += n;\n\t\tT ll = ti, rr = ti;\n\t\twhile (l < r) {\n\t\t\tif (l & 1) ll\
    \ = f(ll, tree[l++]);\n\t\t\tif (r & 1) rr = f(rr, tree[--r]);\n\t\t\tl >>= 1,\
    \ r >>= 1;\n\t\t}\n\t\treturn f(ll, rr);\n\t}\n\n\tT at(int i) { return tree[i\
    \ + n]; }\n};\n#line 1 \"src/tree/euler_tour.cpp\"\n#include <optional>\n#line\
    \ 3 \"src/tree/euler_tour.cpp\"\n\nusing namespace std;\n\nclass SparseTable {\n\
    private:\n\tvector<vector<pair<int, int>>> table;\n\tvector<int> log_table;\n\n\
    public:\n\tSparseTable(const vector<pair<int, int>> &v) {\n\t\tint n = v.size(),\
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
    \ int v, T x, F f) {\n\t\tupdate_vertex(child(u, v), x, f);\n\t}\n};\n#line 5\
    \ \"test/tree/euler_tour/vertex_add_path_sum.test.cpp\"\n\n#include <iostream>\n\
    #line 8 \"test/tree/euler_tour/vertex_add_path_sum.test.cpp\"\n\nusing namespace\
    \ std;\n\nint main() {\n\tint n, q;\n\tcin >> n >> q;\n\tvector<int> a(n);\n\t\
    for (int &e : a) cin >> e;\n\tEulerTour et(n);\n\tfor (int i = 0; i < n - 1; ++i)\
    \ {\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\tet.add_edge(u, v);\n\t}\n\tet.build();\n\
    \tSegmentTree st([](long long a, long long b) { return a + b; }, 0LL);\n\tvector<long\
    \ long> weight(2 * n);\n\tfor (int v = 0; v < n; ++v) {\n\t\tlong long w = a[v];\n\
    \t\tauto [down, up] = et.index(v);\n\t\tweight[down] = w;\n\t\tweight[up] = -w;\n\
    \t}\n\tst.build(weight);\n\n\twhile (q--) {\n\t\tint c;\n\t\tcin >> c;\n\t\tif\
    \ (c == 0) {\n\t\t\tint p;\n\t\t\tlong long x;\n\t\t\tcin >> p >> x;\n\t\t\tauto\
    \ update = [&](int i, int val) { st.update(i, st.at(i) + val); };\n\t\t\tet.update_vertex(p,\
    \ x, update);\n\t\t} else {\n\t\t\tint u, v;\n\t\t\tcin >> u >> v;\n\t\t\tlong\
    \ long res = 0;\n\t\t\tauto query = [&](int l, int r) { res += st.find(l, r);\
    \ };\n\t\t\tet.query_vertex(u, v, query);\n\t\t\tcout << res << endl;\n\t\t}\n\
    \t}\n\n\treturn 0;\n}\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/vertex_add_path_sum\n\
    \n#include \"src/segtree/segment_tree.cpp\"\n#include \"src/tree/euler_tour.cpp\"\
    \n\n#include <iostream>\n#include <vector>\n\nusing namespace std;\n\nint main()\
    \ {\n\tint n, q;\n\tcin >> n >> q;\n\tvector<int> a(n);\n\tfor (int &e : a) cin\
    \ >> e;\n\tEulerTour et(n);\n\tfor (int i = 0; i < n - 1; ++i) {\n\t\tint u, v;\n\
    \t\tcin >> u >> v;\n\t\tet.add_edge(u, v);\n\t}\n\tet.build();\n\tSegmentTree\
    \ st([](long long a, long long b) { return a + b; }, 0LL);\n\tvector<long long>\
    \ weight(2 * n);\n\tfor (int v = 0; v < n; ++v) {\n\t\tlong long w = a[v];\n\t\
    \tauto [down, up] = et.index(v);\n\t\tweight[down] = w;\n\t\tweight[up] = -w;\n\
    \t}\n\tst.build(weight);\n\n\twhile (q--) {\n\t\tint c;\n\t\tcin >> c;\n\t\tif\
    \ (c == 0) {\n\t\t\tint p;\n\t\t\tlong long x;\n\t\t\tcin >> p >> x;\n\t\t\tauto\
    \ update = [&](int i, int val) { st.update(i, st.at(i) + val); };\n\t\t\tet.update_vertex(p,\
    \ x, update);\n\t\t} else {\n\t\t\tint u, v;\n\t\t\tcin >> u >> v;\n\t\t\tlong\
    \ long res = 0;\n\t\t\tauto query = [&](int l, int r) { res += st.find(l, r);\
    \ };\n\t\t\tet.query_vertex(u, v, query);\n\t\t\tcout << res << endl;\n\t\t}\n\
    \t}\n\n\treturn 0;\n}\n"
  dependsOn:
  - src/segtree/segment_tree.cpp
  - src/tree/euler_tour.cpp
  isVerificationFile: true
  path: test/tree/euler_tour/vertex_add_path_sum.test.cpp
  requiredBy: []
  timestamp: '2023-08-20 06:31:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree/euler_tour/vertex_add_path_sum.test.cpp
layout: document
redirect_from:
- /verify/test/tree/euler_tour/vertex_add_path_sum.test.cpp
- /verify/test/tree/euler_tour/vertex_add_path_sum.test.cpp.html
title: test/tree/euler_tour/vertex_add_path_sum.test.cpp
---
