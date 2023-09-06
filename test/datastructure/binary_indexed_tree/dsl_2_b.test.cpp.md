---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/datastructure/binary_indexed_tree.hpp
    title: Binary Indexed Tree (Fenwick Tree)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
  bundledCode: "#line 1 \"test/datastructure/binary_indexed_tree/dsl_2_b.test.cpp\"\
    \n// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\n\
    \n#line 1 \"src/datastructure/binary_indexed_tree.hpp\"\n\n\n\n#include <vector>\n\
    \ntemplate<class T>\nclass BinaryIndexedTree {\nprivate:\n\tint n;\n\tstd::vector<T>\
    \ tree; // 1-indexed\n\npublic:\n\tBinaryIndexedTree(int n) : n(n), tree(n + 1)\
    \ {}\n\n\tvoid add(int i, T x) {\n\t\twhile (i <= n) {\n\t\t\ttree[i] += x;\n\t\
    \t\ti += i & -i;\n\t\t}\n\t}\n\n\tT sum(int i) {\n\t\tT s(0);\n\t\twhile (i >\
    \ 0) {\n\t\t\ts += tree[i];\n\t\t\ti -= i & -i;\n\t\t}\n\t\treturn s;\n\t}\n\n\
    \tT find(int l, int r) { // [l, r)\n\t\treturn sum(r - 1) - sum(l - 1);\n\t}\n\
    };\n\n\n#line 4 \"test/datastructure/binary_indexed_tree/dsl_2_b.test.cpp\"\n\n\
    #include <iostream>\n\nusing namespace std;\n\nint main() {\n\tint n, q;\n\tcin\
    \ >> n >> q;\n\tBinaryIndexedTree<int> bit(n);\n\twhile (q--) {\n\t\tint com,\
    \ x, y;\n\t\tcin >> com >> x >> y;\n\t\tif (com) cout << bit.find(x, y + 1) <<\
    \ endl;\n\t\telse bit.add(x, y);\n\t}\n\n\treturn 0;\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\n\
    \n#include \"src/datastructure/binary_indexed_tree.hpp\"\n\n#include <iostream>\n\
    \nusing namespace std;\n\nint main() {\n\tint n, q;\n\tcin >> n >> q;\n\tBinaryIndexedTree<int>\
    \ bit(n);\n\twhile (q--) {\n\t\tint com, x, y;\n\t\tcin >> com >> x >> y;\n\t\t\
    if (com) cout << bit.find(x, y + 1) << endl;\n\t\telse bit.add(x, y);\n\t}\n\n\
    \treturn 0;\n}\n"
  dependsOn:
  - src/datastructure/binary_indexed_tree.hpp
  isVerificationFile: true
  path: test/datastructure/binary_indexed_tree/dsl_2_b.test.cpp
  requiredBy: []
  timestamp: '2023-09-06 14:54:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/datastructure/binary_indexed_tree/dsl_2_b.test.cpp
layout: document
redirect_from:
- /verify/test/datastructure/binary_indexed_tree/dsl_2_b.test.cpp
- /verify/test/datastructure/binary_indexed_tree/dsl_2_b.test.cpp.html
title: test/datastructure/binary_indexed_tree/dsl_2_b.test.cpp
---
