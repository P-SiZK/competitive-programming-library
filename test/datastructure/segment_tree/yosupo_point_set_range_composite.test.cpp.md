---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/datastructure/segment_tree.hpp
    title: Segment tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/datastructure/segment_tree/yosupo_point_set_range_composite.test.cpp\"\
    \n// verification-helper: PROBLEM https://judge.yosupo.jp/problem/point_set_range_composite\n\
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
    \ = f(ll, tree[l++]);\n\t\t\tif (r & 1) rr = f(tree[--r], rr);\n\t\t\tl >>= 1,\
    \ r >>= 1;\n\t\t}\n\t\treturn f(ll, rr);\n\t}\n\n\tT at(int i) { return tree[i\
    \ + n_]; }\n};\n\n\n#line 4 \"test/datastructure/segment_tree/yosupo_point_set_range_composite.test.cpp\"\
    \n\n#include <iostream>\n#include <utility>\n#line 8 \"test/datastructure/segment_tree/yosupo_point_set_range_composite.test.cpp\"\
    \n\nusing namespace std;\n\nint const MOD = 998244353;\n\nint main() {\n\tint\
    \ n, q;\n\tcin >> n >> q;\n\tvector<pair<long long, long long>> ab(n);\n\tfor\
    \ (auto &[a, b] : ab) cin >> a >> b;\n\n\tauto f = [](pair<long long, long long>\
    \ a, pair<long long, long long> b) {\n\t\treturn pair(b.first * a.first % MOD,\n\
    \t\t\t\t\t(b.first * a.second % MOD + b.second) % MOD);\n\t};\n\tSegmentTree seg(f,\
    \ pair<long long, long long>{1LL, 0LL});\n\tseg.init(n);\n\tseg.build(ab);\n\n\
    \twhile (q--) {\n\t\tint com;\n\t\tcin >> com;\n\t\tif (com) {\n\t\t\tint l, r,\
    \ x;\n\t\t\tcin >> l >> r >> x;\n\t\t\tauto [a, b] = seg.find(l, r);\n\t\t\tcout\
    \ << (a * x % MOD + b) % MOD << endl;\n\t\t} else {\n\t\t\tint p, c, d;\n\t\t\t\
    cin >> p >> c >> d;\n\t\t\tseg.update(p, {c, d});\n\t\t}\n\t}\n\n\treturn 0;\n\
    }\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/point_set_range_composite\n\
    \n#include \"src/datastructure/segment_tree.hpp\"\n\n#include <iostream>\n#include\
    \ <utility>\n#include <vector>\n\nusing namespace std;\n\nint const MOD = 998244353;\n\
    \nint main() {\n\tint n, q;\n\tcin >> n >> q;\n\tvector<pair<long long, long long>>\
    \ ab(n);\n\tfor (auto &[a, b] : ab) cin >> a >> b;\n\n\tauto f = [](pair<long\
    \ long, long long> a, pair<long long, long long> b) {\n\t\treturn pair(b.first\
    \ * a.first % MOD,\n\t\t\t\t\t(b.first * a.second % MOD + b.second) % MOD);\n\t\
    };\n\tSegmentTree seg(f, pair<long long, long long>{1LL, 0LL});\n\tseg.init(n);\n\
    \tseg.build(ab);\n\n\twhile (q--) {\n\t\tint com;\n\t\tcin >> com;\n\t\tif (com)\
    \ {\n\t\t\tint l, r, x;\n\t\t\tcin >> l >> r >> x;\n\t\t\tauto [a, b] = seg.find(l,\
    \ r);\n\t\t\tcout << (a * x % MOD + b) % MOD << endl;\n\t\t} else {\n\t\t\tint\
    \ p, c, d;\n\t\t\tcin >> p >> c >> d;\n\t\t\tseg.update(p, {c, d});\n\t\t}\n\t\
    }\n\n\treturn 0;\n}\n"
  dependsOn:
  - src/datastructure/segment_tree.hpp
  isVerificationFile: true
  path: test/datastructure/segment_tree/yosupo_point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '2023-12-14 18:25:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/datastructure/segment_tree/yosupo_point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/test/datastructure/segment_tree/yosupo_point_set_range_composite.test.cpp
- /verify/test/datastructure/segment_tree/yosupo_point_set_range_composite.test.cpp.html
title: test/datastructure/segment_tree/yosupo_point_set_range_composite.test.cpp
---
