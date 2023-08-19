---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/segtree/segment_tree.cpp
    title: src/segtree/segment_tree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
  bundledCode: "#line 1 \"test/segtree/segment_tree/dsl_2_a.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\n\n\
    #line 1 \"src/segtree/segment_tree.cpp\"\n#include <vector>\n\nusing namespace\
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
    \ + n]; }\n};\n#line 4 \"test/segtree/segment_tree/dsl_2_a.test.cpp\"\n\n#include\
    \ <iostream>\n#include <limits>\n\nusing namespace std;\n\nint main() {\n\tint\
    \ n, q;\n\tcin >> n >> q;\n\tSegmentTree seg([](int a, int b) { return min(a,\
    \ b); },\n\t\t\t\t\tnumeric_limits<int>::max());\n\tseg.init(n);\n\twhile (q--)\
    \ {\n\t\tint com, x, y;\n\t\tcin >> com >> x >> y;\n\t\tif (com) cout << seg.find(x,\
    \ y + 1) << endl;\n\t\telse seg.update(x, y);\n\t}\n\n\treturn 0;\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\n\
    \n#include \"src/segtree/segment_tree.cpp\"\n\n#include <iostream>\n#include <limits>\n\
    \nusing namespace std;\n\nint main() {\n\tint n, q;\n\tcin >> n >> q;\n\tSegmentTree\
    \ seg([](int a, int b) { return min(a, b); },\n\t\t\t\t\tnumeric_limits<int>::max());\n\
    \tseg.init(n);\n\twhile (q--) {\n\t\tint com, x, y;\n\t\tcin >> com >> x >> y;\n\
    \t\tif (com) cout << seg.find(x, y + 1) << endl;\n\t\telse seg.update(x, y);\n\
    \t}\n\n\treturn 0;\n}\n"
  dependsOn:
  - src/segtree/segment_tree.cpp
  isVerificationFile: true
  path: test/segtree/segment_tree/dsl_2_a.test.cpp
  requiredBy: []
  timestamp: '2023-08-20 06:31:19+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/segtree/segment_tree/dsl_2_a.test.cpp
layout: document
redirect_from:
- /verify/test/segtree/segment_tree/dsl_2_a.test.cpp
- /verify/test/segtree/segment_tree/dsl_2_a.test.cpp.html
title: test/segtree/segment_tree/dsl_2_a.test.cpp
---
