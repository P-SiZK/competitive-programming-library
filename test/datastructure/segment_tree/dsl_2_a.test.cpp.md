---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/datastructure/segment_tree.hpp
    title: Segment tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
  bundledCode: "#line 1 \"test/datastructure/segment_tree/dsl_2_a.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\n\n\
    #line 1 \"src/datastructure/segment_tree.hpp\"\n\n\n\n#include <vector>\n\ntemplate<class\
    \ T, class F>\nclass SegmentTree { // 0-indexed\nprivate:\n\tint n_{};\n\tstd::vector<T>\
    \ tree;\n\tF f; // function<T(T, T)>\n\tT ti;\n\npublic:\n\tSegmentTree(F f, T\
    \ ti) : f(f), ti(ti) {}\n\n\tvoid init(int n) {\n\t\tn_ = 1;\n\t\twhile (n_ <\
    \ n) n_ *= 2;\n\t\ttree.assign(2 * n_, ti);\n\t}\n\n\tvoid build(std::vector<T>\
    \ const &v) {\n\t\tint const N = v.size();\n\t\tinit(N);\n\t\tfor (int i = 0;\
    \ i < N; ++i) tree[n_ + i] = v[i];\n\t\tfor (int i = n_ - 1; i > 0; --i) tree[i]\
    \ = f(tree[2 * i], tree[2 * i + 1]);\n\t}\n\n\tvoid update(int i, T const &x)\
    \ {\n\t\ti += n_;\n\t\ttree[i] = x;\n\t\twhile (i >>= 1) tree[i] = f(tree[2 *\
    \ i], tree[2 * i + 1]);\n\t}\n\n\tT find(int l, int r) { // [l, r)\n\t\tl += n_,\
    \ r += n_;\n\t\tT ll = ti, rr = ti;\n\t\twhile (l < r) {\n\t\t\tif (l & 1) ll\
    \ = f(ll, tree[l++]);\n\t\t\tif (r & 1) rr = f(rr, tree[--r]);\n\t\t\tl >>= 1,\
    \ r >>= 1;\n\t\t}\n\t\treturn f(ll, rr);\n\t}\n\n\tT at(int i) { return tree[i\
    \ + n_]; }\n};\n\n\n#line 4 \"test/datastructure/segment_tree/dsl_2_a.test.cpp\"\
    \n\n#include <iostream>\n#include <limits>\n\nusing namespace std;\n\nint main()\
    \ {\n\tint n, q;\n\tcin >> n >> q;\n\tSegmentTree seg([](int a, int b) { return\
    \ min(a, b); }, numeric_limits<int>::max());\n\tseg.init(n);\n\twhile (q--) {\n\
    \t\tint com, x, y;\n\t\tcin >> com >> x >> y;\n\t\tif (com) cout << seg.find(x,\
    \ y + 1) << endl;\n\t\telse seg.update(x, y);\n\t}\n\n\treturn 0;\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\n\
    \n#include \"src/datastructure/segment_tree.hpp\"\n\n#include <iostream>\n#include\
    \ <limits>\n\nusing namespace std;\n\nint main() {\n\tint n, q;\n\tcin >> n >>\
    \ q;\n\tSegmentTree seg([](int a, int b) { return min(a, b); }, numeric_limits<int>::max());\n\
    \tseg.init(n);\n\twhile (q--) {\n\t\tint com, x, y;\n\t\tcin >> com >> x >> y;\n\
    \t\tif (com) cout << seg.find(x, y + 1) << endl;\n\t\telse seg.update(x, y);\n\
    \t}\n\n\treturn 0;\n}\n"
  dependsOn:
  - src/datastructure/segment_tree.hpp
  isVerificationFile: true
  path: test/datastructure/segment_tree/dsl_2_a.test.cpp
  requiredBy: []
  timestamp: '2023-09-02 10:46:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/datastructure/segment_tree/dsl_2_a.test.cpp
layout: document
redirect_from:
- /verify/test/datastructure/segment_tree/dsl_2_a.test.cpp
- /verify/test/datastructure/segment_tree/dsl_2_a.test.cpp.html
title: test/datastructure/segment_tree/dsl_2_a.test.cpp
---
