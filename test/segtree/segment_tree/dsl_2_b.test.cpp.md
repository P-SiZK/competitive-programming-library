---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/segtree/segment_tree.hpp
    title: src/segtree/segment_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
  bundledCode: "#line 1 \"test/segtree/segment_tree/dsl_2_b.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\n\n\
    #line 1 \"src/segtree/segment_tree.hpp\"\n\n\n\n#include <vector>\n\ntemplate<class\
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
    \ + n_]; }\n};\n\n\n#line 4 \"test/segtree/segment_tree/dsl_2_b.test.cpp\"\n\n\
    #include <iostream>\n\nusing namespace std;\n\nint main() {\n\tint n, q;\n\tcin\
    \ >> n >> q;\n\tSegmentTree seg([](long long a, long long b) { return a + b; },\
    \ 0LL);\n\tseg.init(n);\n\twhile (q--) {\n\t\tint com, x, y;\n\t\tcin >> com >>\
    \ x >> y;\n\t\t--x;\n\t\tif (com) --y, cout << seg.find(x, y + 1) << endl;\n\t\
    \telse seg.update(x, seg.at(x) + y);\n\t}\n\n\treturn 0;\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\n\
    \n#include \"src/segtree/segment_tree.hpp\"\n\n#include <iostream>\n\nusing namespace\
    \ std;\n\nint main() {\n\tint n, q;\n\tcin >> n >> q;\n\tSegmentTree seg([](long\
    \ long a, long long b) { return a + b; }, 0LL);\n\tseg.init(n);\n\twhile (q--)\
    \ {\n\t\tint com, x, y;\n\t\tcin >> com >> x >> y;\n\t\t--x;\n\t\tif (com) --y,\
    \ cout << seg.find(x, y + 1) << endl;\n\t\telse seg.update(x, seg.at(x) + y);\n\
    \t}\n\n\treturn 0;\n}\n"
  dependsOn:
  - src/segtree/segment_tree.hpp
  isVerificationFile: true
  path: test/segtree/segment_tree/dsl_2_b.test.cpp
  requiredBy: []
  timestamp: '2023-08-31 15:37:54+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/segtree/segment_tree/dsl_2_b.test.cpp
layout: document
redirect_from:
- /verify/test/segtree/segment_tree/dsl_2_b.test.cpp
- /verify/test/segtree/segment_tree/dsl_2_b.test.cpp.html
title: test/segtree/segment_tree/dsl_2_b.test.cpp
---
