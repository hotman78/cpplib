---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"data_structure/hash_map.hpp\"\n// template<typename T,typename\
    \ E>\n// class hash_map{\n//     T* table;\n//     E* value;\n//     int* used;\n\
    //     int sz=0;\n//     int mx=1;\n//     public:\n//     hash_map(){\n//   \
    \      table=new T[1]();\n//         value=new E[1]();\n//         used=new int[1]();\n\
    //         for(int i=0;i<mx;i++)used[i]=-1;\n//     }\n//     void resize(int\
    \ sz){\n//         T* old_table=new T[sz]();\n//         E* old_value=new E[sz]();\n\
    //         int* old_used=new int[sz]();\n//         for(int i=0;i<sz;++i)old_used[i]=-1;\n\
    //         swap(table,old_table);\n//         swap(value,old_value);\n//     \
    \    swap(used,old_used);\n//         this->sz=0;\n//         mx=sz;\n//     \
    \    for(int i=0;i<mx>>2;++i){\n//             if(old_used[i]!=-1){\n//      \
    \           emplace(old_table[i],old_value[i]);\n//             }\n//        \
    \ }\n//     }\n//     void emplace(T key,E val)noexcept{\n//         if(sz==mx)resize(sz<<2);\n\
    //         ++sz;\n//         int hash=hashing(key);\n//         for(int i=hash;;i=(i==mx-1?0:i+1)){\n\
    //             if(used[i]!=-1){\n//                 if(abs(used[i]-i)>abs(hash-i)){\n\
    //                     swap(used[i],hash);\n//                     swap(table[i],key);\n\
    //                     swap(value[i],val);\n//                 }\n//         \
    \    }else{\n//                 used[i]=hash;\n//                 table[i]=key;\n\
    //                 value[i]=val;\n//                 return;\n//             }\n\
    //         }\n//     }\n    \n//     E& operator[](T key){\n//         const int\
    \ hash=hashing(key);\n//         for(int i=hash;;i=(i==mx-1?0:i+1)){\n//     \
    \        if(used[i]==-1){\n//                 used[i]=hash;\n//              \
    \   table[i]=key;\n//                 value[i]=E();\n//                 return\
    \ value[i];\n//             }else if(key==table[i]){\n//                 return\
    \ value[i];   \n//             }\n//         }\n//     }\n//     bool count(T\
    \ key){\n//         const int hash=hashing(key);\n//         for(int i=hash;;i=(i==mx-1?0:i+1)){\n\
    //             if(used[i]==-1){\n//                 return 0;\n//            \
    \ }else if(key==table[i]){\n//                 return 1;   \n//             }\n\
    //         }\n//     }\n//     bool erase(T key)noexcept{\n//         const int\
    \ hash=hashing(key);\n//         for(int i=hash;;i=(i==mx-1?0:i+1)){\n//     \
    \        if(used[i]==-1){\n//                 return 0;\n//             }else\
    \ if(key==table[i]){\n//                 used[i]=-1;\n//                 table[i]=T();\n\
    //                 value[i]=E();\n//                 --sz;\n//               \
    \  return 1;\n//             }\n//         }\n//     }\n//     inline int hashing(const\
    \ T& val){\n//         return val&(mx-1);\n//     }\n// };\n"
  code: "// template<typename T,typename E>\n// class hash_map{\n//     T* table;\n\
    //     E* value;\n//     int* used;\n//     int sz=0;\n//     int mx=1;\n//  \
    \   public:\n//     hash_map(){\n//         table=new T[1]();\n//         value=new\
    \ E[1]();\n//         used=new int[1]();\n//         for(int i=0;i<mx;i++)used[i]=-1;\n\
    //     }\n//     void resize(int sz){\n//         T* old_table=new T[sz]();\n\
    //         E* old_value=new E[sz]();\n//         int* old_used=new int[sz]();\n\
    //         for(int i=0;i<sz;++i)old_used[i]=-1;\n//         swap(table,old_table);\n\
    //         swap(value,old_value);\n//         swap(used,old_used);\n//       \
    \  this->sz=0;\n//         mx=sz;\n//         for(int i=0;i<mx>>2;++i){\n//  \
    \           if(old_used[i]!=-1){\n//                 emplace(old_table[i],old_value[i]);\n\
    //             }\n//         }\n//     }\n//     void emplace(T key,E val)noexcept{\n\
    //         if(sz==mx)resize(sz<<2);\n//         ++sz;\n//         int hash=hashing(key);\n\
    //         for(int i=hash;;i=(i==mx-1?0:i+1)){\n//             if(used[i]!=-1){\n\
    //                 if(abs(used[i]-i)>abs(hash-i)){\n//                     swap(used[i],hash);\n\
    //                     swap(table[i],key);\n//                     swap(value[i],val);\n\
    //                 }\n//             }else{\n//                 used[i]=hash;\n\
    //                 table[i]=key;\n//                 value[i]=val;\n//       \
    \          return;\n//             }\n//         }\n//     }\n    \n//     E&\
    \ operator[](T key){\n//         const int hash=hashing(key);\n//         for(int\
    \ i=hash;;i=(i==mx-1?0:i+1)){\n//             if(used[i]==-1){\n//           \
    \      used[i]=hash;\n//                 table[i]=key;\n//                 value[i]=E();\n\
    //                 return value[i];\n//             }else if(key==table[i]){\n\
    //                 return value[i];   \n//             }\n//         }\n//   \
    \  }\n//     bool count(T key){\n//         const int hash=hashing(key);\n// \
    \        for(int i=hash;;i=(i==mx-1?0:i+1)){\n//             if(used[i]==-1){\n\
    //                 return 0;\n//             }else if(key==table[i]){\n//    \
    \             return 1;   \n//             }\n//         }\n//     }\n//     bool\
    \ erase(T key)noexcept{\n//         const int hash=hashing(key);\n//         for(int\
    \ i=hash;;i=(i==mx-1?0:i+1)){\n//             if(used[i]==-1){\n//           \
    \      return 0;\n//             }else if(key==table[i]){\n//                \
    \ used[i]=-1;\n//                 table[i]=T();\n//                 value[i]=E();\n\
    //                 --sz;\n//                 return 1;\n//             }\n// \
    \        }\n//     }\n//     inline int hashing(const T& val){\n//         return\
    \ val&(mx-1);\n//     }\n// };"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/hash_map.hpp
  requiredBy: []
  timestamp: '2020-09-17 09:30:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/hash_map.hpp
layout: document
redirect_from:
- /library/data_structure/hash_map.hpp
- /library/data_structure/hash_map.hpp.html
title: data_structure/hash_map.hpp
---
