---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/datastructure/binary_indexed_tree.hpp
    title: Binary Indexed Tree (Fenwick Tree)
  - icon: ':heavy_check_mark:'
    path: src/vector/coordinate_compression.hpp
    title: "\u5EA7\u6A19\u5727\u7E2E"
  - icon: ':heavy_check_mark:'
    path: src/vector/inversion_number.hpp
    title: "\u8EE2\u5012\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D
  bundledCode: "#line 1 \"test/vector/inversion_number/aoj_alds1_5_d.test.cpp\"\n\
    // verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D\n\
    \n#line 1 \"src/vector/inversion_number.hpp\"\n\n\n\n#line 1 \"src/datastructure/binary_indexed_tree.hpp\"\
    \n\n\n\n#include <vector>\n\ntemplate<class T>\nclass BinaryIndexedTree {\nprivate:\n\
    \tint n;\n\tstd::vector<T> tree; // 1-indexed\n\npublic:\n\tBinaryIndexedTree(int\
    \ n) : n(n), tree(n + 1) {}\n\n\tvoid add(int i, T x) {\n\t\twhile (i <= n) {\n\
    \t\t\ttree[i] += x;\n\t\t\ti += i & -i;\n\t\t}\n\t}\n\n\tT sum(int i) {\n\t\t\
    T s(0);\n\t\twhile (i > 0) {\n\t\t\ts += tree[i];\n\t\t\ti -= i & -i;\n\t\t}\n\
    \t\treturn s;\n\t}\n\n\tT find(int l, int r) { // [l, r)\n\t\treturn sum(r - 1)\
    \ - sum(l - 1);\n\t}\n};\n\n\n#line 1 \"src/vector/coordinate_compression.hpp\"\
    \n\n\n\n#include <algorithm>\n#line 6 \"src/vector/coordinate_compression.hpp\"\
    \n\ntemplate<class T>\nclass CoordinateCompression {\nprivate:\n\tstd::vector<T>\
    \ x;\n\npublic:\n\tCoordinateCompression(std::vector<T> const &v) : x(v.size())\
    \ {\n\t\tstd::partial_sort_copy(v.begin(), v.end(), x.begin(), x.end());\n\t\t\
    x.erase(std::unique(x.begin(), x.end()), x.end());\n\t}\n\n\t[[nodiscard]] int\
    \ size() const { return x.size(); }\n\n\tT operator[](int k) { return x[k]; }\n\
    \n\t[[nodiscard]] int get(T const &v) const {\n\t\treturn std::lower_bound(x.begin(),\
    \ x.end(), v) - x.begin();\n\t}\n};\n\n\n#line 6 \"src/vector/inversion_number.hpp\"\
    \n\n#include <iostream>\n#line 9 \"src/vector/inversion_number.hpp\"\n\ntemplate<class\
    \ T>\nlong long inversion_number(std::vector<T> const &v) {\n\tint const N = v.size();\n\
    \tBinaryIndexedTree<int> bit(N);\n\tCoordinateCompression cc(v);\n\tlong long\
    \ res = 0;\n\tfor (int i = 0; i < N; ++i) {\n\t\tint idx = cc.get(v[i]) + 1;\n\
    \t\tres += i - bit.sum(idx);\n\t\tbit.add(idx, 1);\n\t}\n\treturn res;\n}\n\n\n\
    #line 4 \"test/vector/inversion_number/aoj_alds1_5_d.test.cpp\"\n\n#line 7 \"\
    test/vector/inversion_number/aoj_alds1_5_d.test.cpp\"\n\nusing namespace std;\n\
    \nint main() {\n\tint n;\n\tcin >> n;\n\tvector<int> a(n);\n\tfor (int &e : a)\
    \ cin >> e;\n\tcout << inversion_number(a) << endl;\n\n\treturn 0;\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D\n\
    \n#include \"src/vector/inversion_number.hpp\"\n\n#include <iostream>\n#include\
    \ <vector>\n\nusing namespace std;\n\nint main() {\n\tint n;\n\tcin >> n;\n\t\
    vector<int> a(n);\n\tfor (int &e : a) cin >> e;\n\tcout << inversion_number(a)\
    \ << endl;\n\n\treturn 0;\n}\n"
  dependsOn:
  - src/vector/inversion_number.hpp
  - src/datastructure/binary_indexed_tree.hpp
  - src/vector/coordinate_compression.hpp
  isVerificationFile: true
  path: test/vector/inversion_number/aoj_alds1_5_d.test.cpp
  requiredBy: []
  timestamp: '2023-09-06 15:21:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/vector/inversion_number/aoj_alds1_5_d.test.cpp
layout: document
redirect_from:
- /verify/test/vector/inversion_number/aoj_alds1_5_d.test.cpp
- /verify/test/vector/inversion_number/aoj_alds1_5_d.test.cpp.html
title: test/vector/inversion_number/aoj_alds1_5_d.test.cpp
---
