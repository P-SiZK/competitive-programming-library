---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/datastructure/sparse_table.cpp
    title: src/datastructure/sparse_table.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/3/DSL_3_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/3/DSL_3_D
  bundledCode: "#line 1 \"test/datastructure/sparse_table/dsl_3_d.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/3/DSL_3_D\n\n\
    #line 1 \"src/datastructure/sparse_table.cpp\"\n#include <vector>\n\nusing namespace\
    \ std;\n\ntemplate<class T, class F>\nclass SparseTable {\nprivate:\n\tvector<vector<T>>\
    \ table;\n\tvector<int> log_table;\n\tF f;\n\npublic:\n\tSparseTable(const vector<T>\
    \ &v, F f) : f(f) {\n\t\tint n = v.size(), h = 1;\n\t\twhile ((1 << h) <= n) ++h;\n\
    \t\ttable.assign(h, vector<T>(n));\n\t\tlog_table.assign(n + 1, 0);\n\t\tfor (int\
    \ i = 2; i <= n; ++i) log_table[i] = log_table[i >> 1] + 1;\n\n\t\tfor (int i\
    \ = 0; i < n; ++i) table[0][i] = v[i];\n\t\tfor (int i = 1, k = 1; i < h; ++i,\
    \ k <<= 1)\n\t\t\tfor (int j = 0; j < n; ++j)\n\t\t\t\ttable[i][j] =\n\t\t\t\t\
    \tf(table[i - 1][j], table[i - 1][min(j + k, n - 1)]);\n\t}\n\n\tT query(int l,\
    \ int r) { // [l, r)\n\t\tint k = log_table[r - l];\n\t\treturn f(table[k][l],\
    \ table[k][r - (1 << k)]);\n\t}\n};\n#line 4 \"test/datastructure/sparse_table/dsl_3_d.test.cpp\"\
    \n\n#include <iostream>\n#line 7 \"test/datastructure/sparse_table/dsl_3_d.test.cpp\"\
    \n\nint main() {\n\tint n, l;\n\tcin >> n >> l;\n\tvector<int> a(n);\n\tfor (int\
    \ &e : a) cin >> e;\n\tSparseTable st(a, [](int a, int b) { return min(a, b);\
    \ });\n\tfor (int i = 0; i <= n - l; ++i) {\n\t\tif (i) cout << \" \";\n\t\tcout\
    \ << st.query(i, i + l);\n\t}\n\tcout << endl;\n\n\treturn 0;\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/3/DSL_3_D\n\
    \n#include \"src/datastructure/sparse_table.cpp\"\n\n#include <iostream>\n#include\
    \ <vector>\n\nint main() {\n\tint n, l;\n\tcin >> n >> l;\n\tvector<int> a(n);\n\
    \tfor (int &e : a) cin >> e;\n\tSparseTable st(a, [](int a, int b) { return min(a,\
    \ b); });\n\tfor (int i = 0; i <= n - l; ++i) {\n\t\tif (i) cout << \" \";\n\t\
    \tcout << st.query(i, i + l);\n\t}\n\tcout << endl;\n\n\treturn 0;\n}\n"
  dependsOn:
  - src/datastructure/sparse_table.cpp
  isVerificationFile: true
  path: test/datastructure/sparse_table/dsl_3_d.test.cpp
  requiredBy: []
  timestamp: '2023-08-20 06:31:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/datastructure/sparse_table/dsl_3_d.test.cpp
layout: document
redirect_from:
- /verify/test/datastructure/sparse_table/dsl_3_d.test.cpp
- /verify/test/datastructure/sparse_table/dsl_3_d.test.cpp.html
title: test/datastructure/sparse_table/dsl_3_d.test.cpp
---
