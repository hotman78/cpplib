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
  bundledCode: '#line 1 "util/pbds.hpp"

    #include<ext/pb_ds/assoc_container.hpp>

    #include<ext/pb_ds/tree_policy.hpp>

    #include <ext/pb_ds/priority_queue.hpp>

    #include<ext/pb_ds/tag_and_trait.hpp>

    template<typename T>using pbds=__gnu_pbds::tree<T,__gnu_pbds::null_type,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;

    template<typename T>using pbds_map=__gnu_pbds::tree<T,T,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;

    template<typename T,typename E>using hash_map=__gnu_pbds::gp_hash_table<T,E>;

    template<typename T>using pqueue =__gnu_pbds::priority_queue<T, greater<T>,__gnu_pbds::rc_binomial_heap_tag>;

    '
  code: '#include<ext/pb_ds/assoc_container.hpp>

    #include<ext/pb_ds/tree_policy.hpp>

    #include <ext/pb_ds/priority_queue.hpp>

    #include<ext/pb_ds/tag_and_trait.hpp>

    template<typename T>using pbds=__gnu_pbds::tree<T,__gnu_pbds::null_type,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;

    template<typename T>using pbds_map=__gnu_pbds::tree<T,T,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;

    template<typename T,typename E>using hash_map=__gnu_pbds::gp_hash_table<T,E>;

    template<typename T>using pqueue =__gnu_pbds::priority_queue<T, greater<T>,__gnu_pbds::rc_binomial_heap_tag>;'
  dependsOn: []
  isVerificationFile: false
  path: util/pbds.hpp
  requiredBy: []
  timestamp: '2020-09-10 19:03:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: util/pbds.hpp
layout: document
redirect_from:
- /library/util/pbds.hpp
- /library/util/pbds.hpp.html
title: util/pbds.hpp
---
