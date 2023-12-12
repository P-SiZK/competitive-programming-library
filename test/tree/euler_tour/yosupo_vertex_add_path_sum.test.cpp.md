---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/datastructure/segment_tree.hpp
    title: Segment tree
  - icon: ':heavy_check_mark:'
    path: src/tree/euler_tour.hpp
    title: Euler Tour
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"test/tree/euler_tour/yosupo_vertex_add_path_sum.test.cpp\"\
    \n// verification-helper: PROBLEM https://judge.yosupo.jp/problem/vertex_add_path_sum\n\
    \n#line 1 \"src/datastructure/segment_tree.hpp\"\n\n\n\n#include <vector>\n\n\
    template<class T, class F>\nclass SegmentTree { // 0-indexed\nprivate:\n\tint\
    \ n_{};\n\tstd::vector<T> tree;\n\tF f; // function<T(T, T)>\n\tT ti;\n\npublic:\n\
    \tSegmentTree(F f, T ti) : f(f), ti(ti) {}\n\n\tvoid init(int n) {\n\t\tn_ = 1;\n\
    \t\twhile (n_ < n) n_ *= 2;\n\t\ttree.assign(2 * n_, ti);\n\t}\n\n\tvoid build(std::vector<T>\
    \ const &v) {\n\t\tint const N = v.size();\n\t\tinit(N);\n\t\tfor (int i = 0;\
    \ i < N; ++i) tree[n_ + i] = v[i];\n\t\tfor (int i = n_ - 1; i > 0; --i) tree[i]\
    \ = f(tree[2 * i], tree[2 * i + 1]);\n\t}\n\n\tvoid update(int i, T const &x)\
    \ {\n\t\ti += n_;\n\t\ttree[i] = x;\n\t\twhile (i >>= 1) tree[i] = f(tree[2 *\
    \ i], tree[2 * i + 1]);\n\t}\n\n\tT find(int l, int r) { // [l, r)\n\t\tl += n_,\
    \ r += n_;\n\t\tT ll = ti, rr = ti;\n\t\twhile (l < r) {\n\t\t\tif (l & 1) ll\
    \ = f(ll, tree[l++]);\n\t\t\tif (r & 1) rr = f(rr, tree[--r]);\n\t\t\tl >>= 1,\
    \ r >>= 1;\n\t\t}\n\t\treturn f(ll, rr);\n\t}\n\n\tT at(int i) { return tree[i\
    \ + n_]; }\n};\n\n\n#line 1 \"src/tree/euler_tour.hpp\"\n\n\n\n#line 5 \"src/tree/euler_tour.hpp\"\
    \n\n#include <algorithm>\n#include <utility>\n#line 9 \"src/tree/euler_tour.hpp\"\
    \n\nclass EulerTour {\nprivate:\n\tstatic std::pair<int, int> min(std::pair<int,\
    \ int> &a, std::pair<int, int> &b) {\n\t\treturn std::min(a, b);\n\t}\n\n\tstd::vector<int>\
    \ down, up, depth, terminal;\n\tSegmentTree<std::pair<int, int>, decltype(&min)>\
    \ st;\n\tstd::vector<std::vector<int>> G;\n\n\tvoid dfs(int v, int p, int d) {\n\
    \t\tdepth[terminal.size()] = d;\n\t\tdown[v] = terminal.size();\n\t\tterminal.emplace_back(v);\n\
    \t\tfor (int u : G[v]) {\n\t\t\tif (u == p) continue;\n\t\t\tdfs(u, v, d + 1);\n\
    \t\t}\n\t\tdepth[terminal.size()] = d - 1;\n\t\tup[v] = terminal.size();\n\t\t\
    terminal.emplace_back(p);\n\t}\n\npublic:\n\tEulerTour(int n) : down(n), up(n),\
    \ depth(n << 1), st(min, {1 << 30, -1}), G(n) {}\n\n\tvoid add_edge(int u, int\
    \ v) {\n\t\tG[u].emplace_back(v);\n\t\tG[v].emplace_back(u);\n\t}\n\n\tvoid build(int\
    \ root = 0) {\n\t\tterminal.clear();\n\t\tdfs(root, -1, 0);\n\t\tstd::vector<std::pair<int,\
    \ int>> dep(terminal.size());\n\t\tfor (int i = 0; i < (int)terminal.size(); ++i)\
    \ dep[i] = {depth[i], terminal[i]};\n\t\tst.build(dep);\n\t}\n\n\tstd::pair<int,\
    \ int> index(int v) { return {down[v], up[v]}; };\n\n\tint parent(int u, int v)\
    \ { return depth[down[u]] < depth[down[v]] ? u : v; }\n\n\tint child(int u, int\
    \ v) { return depth[down[u]] < depth[down[v]] ? v : u; }\n\n\tint lca(int u, int\
    \ v) {\n\t\tif (down[u] > down[v]) std::swap(u, v);\n\t\treturn st.find(down[u],\
    \ down[v] + 1).second;\n\t}\n\n\ttemplate<class F>\n\tvoid query_vertex(int u,\
    \ int v, F const &f) {\n\t\tint a = lca(u, v);\n\t\tf(down[a], down[u] + 1);\n\
    \t\tf(down[a] + 1, down[v] + 1);\n\t}\n\n\ttemplate<class F>\n\tvoid query_edge(int\
    \ u, int v, F const &f) {\n\t\tint a = lca(u, v);\n\t\tf(down[a] + 1, down[u]\
    \ + 1);\n\t\tf(down[a] + 1, down[v] + 1);\n\t}\n\n\ttemplate<class T, class F>\n\
    \tvoid update_vertex(int v, T x, F const &f) {\n\t\tf(down[v], x);\n\t\tf(up[v],\
    \ -x);\n\t}\n\n\ttemplate<class T, class F>\n\tvoid update_edge(int u, int v,\
    \ T x, F const &f) {\n\t\tupdate_vertex(child(u, v), x, f);\n\t}\n};\n\n\n#line\
    \ 5 \"test/tree/euler_tour/yosupo_vertex_add_path_sum.test.cpp\"\n\n#include <iostream>\n\
    #line 8 \"test/tree/euler_tour/yosupo_vertex_add_path_sum.test.cpp\"\n\nusing\
    \ namespace std;\n\nint main() {\n\tint n, q;\n\tcin >> n >> q;\n\tvector<int>\
    \ a(n);\n\tfor (int &e : a) cin >> e;\n\tEulerTour et(n);\n\tfor (int i = 0; i\
    \ < n - 1; ++i) {\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\tet.add_edge(u, v);\n\
    \t}\n\tet.build();\n\tSegmentTree st([](long long a, long long b) { return a +\
    \ b; }, 0LL);\n\tvector<long long> weight(2UL * n);\n\tfor (int v = 0; v < n;\
    \ ++v) {\n\t\tlong long w = a[v];\n\t\tauto [down, up] = et.index(v);\n\t\tweight[down]\
    \ = w;\n\t\tweight[up] = -w;\n\t}\n\tst.build(weight);\n\n\twhile (q--) {\n\t\t\
    int c;\n\t\tcin >> c;\n\t\tif (c == 0) {\n\t\t\tint p;\n\t\t\tlong long x;\n\t\
    \t\tcin >> p >> x;\n\t\t\tauto update = [&](int i, int val) { st.update(i, st.at(i)\
    \ + val); };\n\t\t\tet.update_vertex(p, x, update);\n\t\t} else {\n\t\t\tint u,\
    \ v;\n\t\t\tcin >> u >> v;\n\t\t\tlong long res = 0;\n\t\t\tauto query = [&](int\
    \ l, int r) { res += st.find(l, r); };\n\t\t\tet.query_vertex(u, v, query);\n\t\
    \t\tcout << res << endl;\n\t\t}\n\t}\n\n\treturn 0;\n}\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/vertex_add_path_sum\n\
    \n#include \"src/datastructure/segment_tree.hpp\"\n#include \"src/tree/euler_tour.hpp\"\
    \n\n#include <iostream>\n#include <vector>\n\nusing namespace std;\n\nint main()\
    \ {\n\tint n, q;\n\tcin >> n >> q;\n\tvector<int> a(n);\n\tfor (int &e : a) cin\
    \ >> e;\n\tEulerTour et(n);\n\tfor (int i = 0; i < n - 1; ++i) {\n\t\tint u, v;\n\
    \t\tcin >> u >> v;\n\t\tet.add_edge(u, v);\n\t}\n\tet.build();\n\tSegmentTree\
    \ st([](long long a, long long b) { return a + b; }, 0LL);\n\tvector<long long>\
    \ weight(2UL * n);\n\tfor (int v = 0; v < n; ++v) {\n\t\tlong long w = a[v];\n\
    \t\tauto [down, up] = et.index(v);\n\t\tweight[down] = w;\n\t\tweight[up] = -w;\n\
    \t}\n\tst.build(weight);\n\n\twhile (q--) {\n\t\tint c;\n\t\tcin >> c;\n\t\tif\
    \ (c == 0) {\n\t\t\tint p;\n\t\t\tlong long x;\n\t\t\tcin >> p >> x;\n\t\t\tauto\
    \ update = [&](int i, int val) { st.update(i, st.at(i) + val); };\n\t\t\tet.update_vertex(p,\
    \ x, update);\n\t\t} else {\n\t\t\tint u, v;\n\t\t\tcin >> u >> v;\n\t\t\tlong\
    \ long res = 0;\n\t\t\tauto query = [&](int l, int r) { res += st.find(l, r);\
    \ };\n\t\t\tet.query_vertex(u, v, query);\n\t\t\tcout << res << endl;\n\t\t}\n\
    \t}\n\n\treturn 0;\n}\n"
  dependsOn:
  - src/datastructure/segment_tree.hpp
  - src/tree/euler_tour.hpp
  isVerificationFile: true
  path: test/tree/euler_tour/yosupo_vertex_add_path_sum.test.cpp
  requiredBy: []
  timestamp: '2023-12-12 23:33:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree/euler_tour/yosupo_vertex_add_path_sum.test.cpp
layout: document
redirect_from:
- /verify/test/tree/euler_tour/yosupo_vertex_add_path_sum.test.cpp
- /verify/test/tree/euler_tour/yosupo_vertex_add_path_sum.test.cpp.html
title: test/tree/euler_tour/yosupo_vertex_add_path_sum.test.cpp
---
