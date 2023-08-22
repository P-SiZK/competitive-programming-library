---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/segtree/lazy_segment_tree.hpp
    title: src/segtree/lazy_segment_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F
  bundledCode: "#line 1 \"test/segtree/lazy_segment_tree/dsl_2_f.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F\n\n\
    #line 1 \"src/segtree/lazy_segment_tree.hpp\"\n#include <vector>\n\nusing namespace\
    \ std;\n\ntemplate<class T, class E, class F, class G, class H>\nclass LazySegmentTree\
    \ { // 0-indexed\nprivate:\n\tint n_{}, height{};\n\tvector<T> tree;\n\tvector<E>\
    \ lazy;\n\tF f; // function<T(T, T)>\n\tG g; // function<T(T, E)>\n\tH h; // function<E(E,\
    \ E)>\n\tT ti;\n\tE ei;\n\npublic:\n\tLazySegmentTree(F f, G g, H h, T ti, E ei)\
    \ :\n\t\tf(f), g(g), h(h), ti(ti), ei(ei) {}\n\n\tvoid init(int n) {\n\t\tn_ =\
    \ 1, height = 0;\n\t\twhile (n_ < n) n_ *= 2, ++height;\n\t\ttree.assign(2 * n_,\
    \ ti);\n\t\tlazy.assign(2 * n_, ei);\n\t}\n\n\tvoid build(vector<T> const &v)\
    \ {\n\t\tint const N = v.size();\n\t\tinit(N);\n\t\tfor (int i = 0; i < N; ++i)\
    \ tree[n_ + i] = v[i];\n\t\tfor (int i = n_ - 1; i > 0; --i)\n\t\t\ttree[i] =\
    \ f(tree[2 * i], tree[2 * i + 1]);\n\t}\n\n\tinline T reflect(int k) {\n\t\treturn\
    \ (lazy[k] == ei ? tree[k] : g(tree[k], lazy[k]));\n\t}\n\n\tinline void eval(int\
    \ k) {\n\t\tif (lazy[k] == ei) return;\n\t\tlazy[2 * k] = h(lazy[2 * k], lazy[k]);\n\
    \t\tlazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);\n\t\ttree[k] = reflect(k);\n\
    \t\tlazy[k] = ei;\n\t}\n\n\tinline void thrust(int k) {\n\t\tfor (int i = height;\
    \ i > 0; --i) eval(k >> i);\n\t}\n\n\tinline void recalc(int k) {\n\t\twhile (k\
    \ >>= 1) tree[k] = f(reflect(2 * k), reflect(2 * k + 1));\n\t}\n\n\tvoid update(int\
    \ s, int t, E const &x) { // [l, r)\n\t\ts += n_, t += n_;\n\t\tthrust(s), thrust(t\
    \ - 1);\n\t\tint l = s, r = t;\n\t\twhile (l < r) {\n\t\t\tif (l & 1) lazy[l]\
    \ = h(lazy[l], x), ++l;\n\t\t\tif (r & 1) --r, lazy[r] = h(lazy[r], x);\n\t\t\t\
    l >>= 1, r >>= 1;\n\t\t}\n\t\trecalc(s), recalc(t - 1);\n\t}\n\n\tT find(int s,\
    \ int t) { // [l, r)\n\t\ts += n_, t += n_;\n\t\tthrust(s), thrust(t - 1);\n\t\
    \tint l = s, r = t;\n\t\tT ll = ti, rr = ti;\n\t\twhile (l < r) {\n\t\t\tif (l\
    \ & 1) ll = f(ll, reflect(l++));\n\t\t\tif (r & 1) rr = f(rr, reflect(--r));\n\
    \t\t\tl >>= 1, r >>= 1;\n\t\t}\n\t\treturn f(ll, rr);\n\t}\n\n\tT at(int i) {\
    \ return find(i, i + 1); }\n};\n#line 4 \"test/segtree/lazy_segment_tree/dsl_2_f.test.cpp\"\
    \n\n#include <iostream>\n#include <limits>\n\nusing namespace std;\n\nint main()\
    \ {\n\tint n, q;\n\tcin >> n >> q;\n\tauto f = [](int a, int b) { return min(a,\
    \ b); };\n\tauto g = []([[maybe_unused]] int a, int b) { return b; };\n\tLazySegmentTree\
    \ seg(f, g, g, numeric_limits<int>::max(), -1);\n\tseg.init(n);\n\twhile (q--)\
    \ {\n\t\tint com, s, t, x;\n\t\tcin >> com >> s >> t;\n\t\tif (com) cout << seg.find(s,\
    \ t + 1) << endl;\n\t\telse cin >> x, seg.update(s, t + 1, x);\n\t}\n\n\treturn\
    \ 0;\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F\n\
    \n#include \"src/segtree/lazy_segment_tree.hpp\"\n\n#include <iostream>\n#include\
    \ <limits>\n\nusing namespace std;\n\nint main() {\n\tint n, q;\n\tcin >> n >>\
    \ q;\n\tauto f = [](int a, int b) { return min(a, b); };\n\tauto g = []([[maybe_unused]]\
    \ int a, int b) { return b; };\n\tLazySegmentTree seg(f, g, g, numeric_limits<int>::max(),\
    \ -1);\n\tseg.init(n);\n\twhile (q--) {\n\t\tint com, s, t, x;\n\t\tcin >> com\
    \ >> s >> t;\n\t\tif (com) cout << seg.find(s, t + 1) << endl;\n\t\telse cin >>\
    \ x, seg.update(s, t + 1, x);\n\t}\n\n\treturn 0;\n}\n"
  dependsOn:
  - src/segtree/lazy_segment_tree.hpp
  isVerificationFile: true
  path: test/segtree/lazy_segment_tree/dsl_2_f.test.cpp
  requiredBy: []
  timestamp: '2023-08-22 14:56:56+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/segtree/lazy_segment_tree/dsl_2_f.test.cpp
layout: document
redirect_from:
- /verify/test/segtree/lazy_segment_tree/dsl_2_f.test.cpp
- /verify/test/segtree/lazy_segment_tree/dsl_2_f.test.cpp.html
title: test/segtree/lazy_segment_tree/dsl_2_f.test.cpp
---
