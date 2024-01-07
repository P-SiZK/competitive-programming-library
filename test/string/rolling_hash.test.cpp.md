---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/rolling_hash.hpp
    title: Rolling Hash
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B
  bundledCode: "#line 1 \"test/string/rolling_hash.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B\n\
    \n#line 1 \"src/string/rolling_hash.hpp\"\n\n\n\n#include <chrono>\n#include <cstdint>\n\
    #include <random>\n#include <string>\n#include <vector>\n\nclass RollingHash {\n\
    private:\n\tstatic std::uint64_t const MOD = (1ULL << 61) - 1;\n\n\tstatic std::uint64_t\
    \ generate_base() noexcept {\n\t\tstd::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());\n\
    \t\tstd::uniform_int_distribution<std::uint64_t> rand(1, MOD - 1);\n\t\treturn\
    \ rand(mt);\n\t}\n\n\tstatic inline std::uint64_t base = generate_base();\n\t\
    static inline std::vector<std::uint64_t> power;\n\n\tstatic void extend_power(int\
    \ n) {\n\t\tif ((int)power.size() >= n + 1) return;\n\t\tif (power.empty()) power.assign({1});\n\
    \t\tint prev_n = power.size();\n\t\tpower.resize(n + 1, 1);\n\t\tfor (int i =\
    \ prev_n - 1; i < n; ++i) power[i + 1] = mul(power[i], base);\n\t}\n\n\tstatic\
    \ std::uint64_t add(std::uint64_t a, std::uint64_t b) {\n\t\ta += b;\n\t\tif (a\
    \ >= MOD) a -= MOD;\n\t\treturn a;\n\t}\n\n\tstatic std::uint64_t mul(std::uint64_t\
    \ a, std::uint64_t b) {\n\t\tstd::uint64_t au = a >> 31;\n\t\tstd::uint64_t al\
    \ = a & ((1ULL << 31) - 1);\n\t\tstd::uint64_t bu = b >> 31;\n\t\tstd::uint64_t\
    \ bl = b & ((1ULL << 31) - 1);\n\t\tstd::uint64_t ul = al * bu + au * bl;\n\n\t\
    \tstd::uint64_t res = au * bu * 2;\n\t\tres += ul >> 30;\n\t\tres += (ul & ((1ULL\
    \ << 30) - 1)) << 31;\n\t\tres += al * bl;\n\t\treturn add(res >> 61, res & MOD);\n\
    \t}\n\n\tstd::vector<std::uint64_t> hash;\n\npublic:\n\tRollingHash() = default;\n\
    \n\tvoid build(std::string const &s) {\n\t\tint n = s.size();\n\t\textend_power(n);\n\
    \t\thash.assign(n + 1, 0);\n\t\tfor (int i = 0; i < n; ++i) hash[i + 1] = add(mul(hash[i],\
    \ base), s[i]);\n\t}\n\n\tstd::uint64_t find(int l, int r) {\n\t\treturn add(hash[r],\
    \ MOD - mul(hash[l], power[r - l]));\n\t}\n};\n\n\n#line 4 \"test/string/rolling_hash.test.cpp\"\
    \n\n#include <iostream>\n#line 7 \"test/string/rolling_hash.test.cpp\"\n\nusing\
    \ namespace std;\n\nint main() {\n\tstring t, p;\n\tcin >> t >> p;\n\tint n =\
    \ p.size();\n\n\tRollingHash rht, rhp;\n\trht.build(t);\n\trhp.build(p);\n\tfor\
    \ (int i = 0; i <= (int)t.size() - n; ++i)\n\t\tif (rht.find(i, i + n) == rhp.find(0,\
    \ n)) cout << i << endl;\n\n\treturn 0;\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B\n\
    \n#include \"src/string/rolling_hash.hpp\"\n\n#include <iostream>\n#include <string>\n\
    \nusing namespace std;\n\nint main() {\n\tstring t, p;\n\tcin >> t >> p;\n\tint\
    \ n = p.size();\n\n\tRollingHash rht, rhp;\n\trht.build(t);\n\trhp.build(p);\n\
    \tfor (int i = 0; i <= (int)t.size() - n; ++i)\n\t\tif (rht.find(i, i + n) ==\
    \ rhp.find(0, n)) cout << i << endl;\n\n\treturn 0;\n}\n"
  dependsOn:
  - src/string/rolling_hash.hpp
  isVerificationFile: true
  path: test/string/rolling_hash.test.cpp
  requiredBy: []
  timestamp: '2024-01-07 18:17:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/rolling_hash.test.cpp
layout: document
redirect_from:
- /verify/test/string/rolling_hash.test.cpp
- /verify/test/string/rolling_hash.test.cpp.html
title: test/string/rolling_hash.test.cpp
---
