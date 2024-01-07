---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/rolling_hash.test.cpp
    title: test/string/rolling_hash.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/string/rolling_hash.hpp\"\n\n\n\n#include <chrono>\n\
    #include <cstdint>\n#include <random>\n#include <string>\n#include <vector>\n\n\
    class RollingHash {\nprivate:\n\tstatic std::uint64_t const MOD = (1ULL << 61)\
    \ - 1;\n\n\tstatic std::uint64_t generate_base() noexcept {\n\t\tstd::mt19937_64\
    \ mt(std::chrono::steady_clock::now().time_since_epoch().count());\n\t\tstd::uniform_int_distribution<std::uint64_t>\
    \ rand(1, MOD - 1);\n\t\treturn rand(mt);\n\t}\n\n\tstatic inline std::uint64_t\
    \ base = generate_base();\n\tstatic inline std::vector<std::uint64_t> power;\n\
    \n\tstatic void extend_power(int n) {\n\t\tif ((int)power.size() >= n + 1) return;\n\
    \t\tif (power.empty()) power.assign({1});\n\t\tint prev_n = power.size();\n\t\t\
    power.resize(n + 1, 1);\n\t\tfor (int i = prev_n - 1; i < n; ++i) power[i + 1]\
    \ = mul(power[i], base);\n\t}\n\n\tstatic std::uint64_t add(std::uint64_t a, std::uint64_t\
    \ b) {\n\t\ta += b;\n\t\tif (a >= MOD) a -= MOD;\n\t\treturn a;\n\t}\n\n\tstatic\
    \ std::uint64_t mul(std::uint64_t a, std::uint64_t b) {\n\t\tstd::uint64_t au\
    \ = a >> 31;\n\t\tstd::uint64_t al = a & ((1ULL << 31) - 1);\n\t\tstd::uint64_t\
    \ bu = b >> 31;\n\t\tstd::uint64_t bl = b & ((1ULL << 31) - 1);\n\t\tstd::uint64_t\
    \ ul = al * bu + au * bl;\n\n\t\tstd::uint64_t res = au * bu * 2;\n\t\tres +=\
    \ ul >> 30;\n\t\tres += (ul & ((1ULL << 30) - 1)) << 31;\n\t\tres += al * bl;\n\
    \t\treturn add(res >> 61, res & MOD);\n\t}\n\n\tstd::vector<std::uint64_t> hash;\n\
    \npublic:\n\tRollingHash() = default;\n\n\tvoid build(std::string const &s) {\n\
    \t\tint n = s.size();\n\t\textend_power(n);\n\t\thash.assign(n + 1, 0);\n\t\t\
    for (int i = 0; i < n; ++i) hash[i + 1] = add(mul(hash[i], base), s[i]);\n\t}\n\
    \n\tstd::uint64_t find(int l, int r) {\n\t\treturn add(hash[r], MOD - mul(hash[l],\
    \ power[r - l]));\n\t}\n};\n\n\n"
  code: "#ifndef STRING_ROLLING_HASH_HPP\n#define STRING_ROLLING_HASH_HPP\n\n#include\
    \ <chrono>\n#include <cstdint>\n#include <random>\n#include <string>\n#include\
    \ <vector>\n\nclass RollingHash {\nprivate:\n\tstatic std::uint64_t const MOD\
    \ = (1ULL << 61) - 1;\n\n\tstatic std::uint64_t generate_base() noexcept {\n\t\
    \tstd::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());\n\
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
    \ MOD - mul(hash[l], power[r - l]));\n\t}\n};\n\n#endif // STRING_ROLLING_HASH_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2024-01-07 18:17:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/rolling_hash.test.cpp
documentation_of: src/string/rolling_hash.hpp
layout: document
title: Rolling Hash
---
