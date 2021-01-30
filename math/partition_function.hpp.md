---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/partition_function.hpp\"\n//n\u3092k\u500B\u4EE5\u4E0B\
    \u81EA\u7136\u6570\u306E\u548C\u3067\u8868\u3059\ntemplate<typename T>\nvector<vector<T>>\
    \ partition_function(int n){\n    vector<vector<T>> dp(n+1,vector<T>(n+1,0));\n\
    \    dp[0][0]=1;\n    for(int i=0;i<=n;++i)for(int j=1;j<=n;++j){\n        if(i-j>=0)dp[i][j]=dp[i][j-1]+dp[i-j][j];\n\
    \        else dp[i][j]=dp[i][j-1];\n    }\n    return dp;\n}\n"
  code: "//n\u3092k\u500B\u4EE5\u4E0B\u81EA\u7136\u6570\u306E\u548C\u3067\u8868\u3059\
    \ntemplate<typename T>\nvector<vector<T>> partition_function(int n){\n    vector<vector<T>>\
    \ dp(n+1,vector<T>(n+1,0));\n    dp[0][0]=1;\n    for(int i=0;i<=n;++i)for(int\
    \ j=1;j<=n;++j){\n        if(i-j>=0)dp[i][j]=dp[i][j-1]+dp[i-j][j];\n        else\
    \ dp[i][j]=dp[i][j-1];\n    }\n    return dp;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/partition_function.hpp
  requiredBy: []
  timestamp: '2021-01-30 10:06:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/partition_function.hpp
layout: document
redirect_from:
- /library/math/partition_function.hpp
- /library/math/partition_function.hpp.html
title: math/partition_function.hpp
---
