---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/datastructure/disjoint_set.hpp
    title: Disjoint Set (Union-find)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_A
  bundledCode: "#line 1 \"test/datastructure/disjoint_set/dsl_1_a.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_A\n\
    \n#line 1 \"src/datastructure/disjoint_set.hpp\"\n\n\n\n#include <vector>\n\n\
    class DisjointSet {\nprivate:\n\tstd::vector<int> rank, size, p;\n\tint num =\
    \ 0;\n\npublic:\n\tDisjointSet(int n) : rank(n), size(n, 1), p(n), num(n) {\n\t\
    \tfor (int i = 0; i < n; i++) p[i] = i;\n\t}\n\n\tbool same(int x, int y) { return\
    \ root(x) == root(y); }\n\n\tvoid unite(int x, int y) {\n\t\tx = root(x), y =\
    \ root(y);\n\t\tif (x == y) return;\n\t\tnum--;\n\t\tif (rank[x] > rank[y]) {\n\
    \t\t\tp[y] = x;\n\t\t\tsize[x] += size[y];\n\t\t} else {\n\t\t\tp[x] = y;\n\t\t\
    \tsize[y] += size[x];\n\t\t\tif (rank[x] == rank[y]) rank[y]++;\n\t\t}\n\t}\n\n\
    \tint root(int x) { return p[x] == x ? x : p[x] = root(p[x]); }\n\n\tint get_size(int\
    \ x) { return size[root(x)]; }\n\n\t[[nodiscard]] int forest_size() const { return\
    \ num; }\n};\n\n\n#line 4 \"test/datastructure/disjoint_set/dsl_1_a.test.cpp\"\
    \n\n#include <iostream>\n\nusing namespace std;\n\nint main() {\n\tint n, q;\n\
    \tcin >> n >> q;\n\tDisjointSet ds(n);\n\tfor (int i = 0; i < q; ++i) {\n\t\t\
    int t, a, b;\n\t\tcin >> t >> a >> b;\n\t\tif (t == 0) ds.unite(a, b);\n\t\telse\
    \ if (t == 1) {\n\t\t\tif (ds.same(a, b)) cout << 1 << endl;\n\t\t\telse cout\
    \ << 0 << endl;\n\t\t}\n\t}\n\n\treturn 0;\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_A\n\
    \n#include \"src/datastructure/disjoint_set.hpp\"\n\n#include <iostream>\n\nusing\
    \ namespace std;\n\nint main() {\n\tint n, q;\n\tcin >> n >> q;\n\tDisjointSet\
    \ ds(n);\n\tfor (int i = 0; i < q; ++i) {\n\t\tint t, a, b;\n\t\tcin >> t >> a\
    \ >> b;\n\t\tif (t == 0) ds.unite(a, b);\n\t\telse if (t == 1) {\n\t\t\tif (ds.same(a,\
    \ b)) cout << 1 << endl;\n\t\t\telse cout << 0 << endl;\n\t\t}\n\t}\n\n\treturn\
    \ 0;\n}\n"
  dependsOn:
  - src/datastructure/disjoint_set.hpp
  isVerificationFile: true
  path: test/datastructure/disjoint_set/dsl_1_a.test.cpp
  requiredBy: []
  timestamp: '2023-08-31 15:37:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/datastructure/disjoint_set/dsl_1_a.test.cpp
layout: document
redirect_from:
- /verify/test/datastructure/disjoint_set/dsl_1_a.test.cpp
- /verify/test/datastructure/disjoint_set/dsl_1_a.test.cpp.html
title: test/datastructure/disjoint_set/dsl_1_a.test.cpp
---
