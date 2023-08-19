---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/datastructure/binary_indexed_tree.cpp
    title: src/datastructure/binary_indexed_tree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D
  bundledCode: "#line 1 \"test/datastructure/binary_indexed_tree/alds1_5_d.test.cpp\"\
    \n// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D\n\
    \n#line 1 \"src/datastructure/binary_indexed_tree.cpp\"\n#include <iostream>\n\
    #include <vector>\n\nusing namespace std;\n\ntemplate<class T>\nstruct BinaryIndexedTree\
    \ {\n\tint n;\n\tvector<T> tree; // 1-indexed\n\n\tBinaryIndexedTree(int n) :\
    \ n(n), tree(n + 1) {}\n\n\tvoid add(int i, T x) {\n\t\twhile (i <= n) {\n\t\t\
    \ttree[i] += x;\n\t\t\ti += i & -i;\n\t\t}\n\t}\n\n\tT sum(int i) {\n\t\tT s(0);\n\
    \t\twhile (i > 0) {\n\t\t\ts += tree[i];\n\t\t\ti -= i & -i;\n\t\t}\n\t\treturn\
    \ s;\n\t}\n\n\tT find(int l, int r) { // [l, r)\n\t\treturn sum(r - 1) - sum(l\
    \ - 1);\n\t}\n};\n\nlong long inversion_number(const vector<int> &v) {\n\tconst\
    \ int n = v.size();\n\tBinaryIndexedTree<int> bit(n);\n\tlong long res = 0;\n\t\
    for (int i = 0; i < n; ++i) {\n\t\tres += i - bit.sum(v[i]);\n\t\tbit.add(v[i],\
    \ 1);\n\t}\n\treturn res;\n}\n#line 4 \"test/datastructure/binary_indexed_tree/alds1_5_d.test.cpp\"\
    \n\n#include <algorithm>\n#line 7 \"test/datastructure/binary_indexed_tree/alds1_5_d.test.cpp\"\
    \n#include <map>\n#line 9 \"test/datastructure/binary_indexed_tree/alds1_5_d.test.cpp\"\
    \n\nint main() {\n\tint n;\n\tcin >> n;\n\tvector<int> a(n);\n\tfor (int &e :\
    \ a) cin >> e;\n\tvector<int> a_cp(a);\n\tsort(a_cp.begin(), a_cp.end());\n\t\
    map<int, int> mp;\n\tfor (int i = 0; i < n; ++i) mp[a_cp[i]] = i + 1;\n\tfor (int\
    \ &e : a) e = mp[e];\n\tcout << inversion_number(a) << endl;\n\n\treturn 0;\n\
    }\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D\n\
    \n#include \"src/datastructure/binary_indexed_tree.cpp\"\n\n#include <algorithm>\n\
    #include <iostream>\n#include <map>\n#include <vector>\n\nint main() {\n\tint\
    \ n;\n\tcin >> n;\n\tvector<int> a(n);\n\tfor (int &e : a) cin >> e;\n\tvector<int>\
    \ a_cp(a);\n\tsort(a_cp.begin(), a_cp.end());\n\tmap<int, int> mp;\n\tfor (int\
    \ i = 0; i < n; ++i) mp[a_cp[i]] = i + 1;\n\tfor (int &e : a) e = mp[e];\n\tcout\
    \ << inversion_number(a) << endl;\n\n\treturn 0;\n}\n"
  dependsOn:
  - src/datastructure/binary_indexed_tree.cpp
  isVerificationFile: true
  path: test/datastructure/binary_indexed_tree/alds1_5_d.test.cpp
  requiredBy: []
  timestamp: '2023-08-20 06:31:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/datastructure/binary_indexed_tree/alds1_5_d.test.cpp
layout: document
redirect_from:
- /verify/test/datastructure/binary_indexed_tree/alds1_5_d.test.cpp
- /verify/test/datastructure/binary_indexed_tree/alds1_5_d.test.cpp.html
title: test/datastructure/binary_indexed_tree/alds1_5_d.test.cpp
---
