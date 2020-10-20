---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Kd\u6728(WIP)"
    links: []
  bundledCode: "#line 2 \"data_structure/kd_tree.hpp\"\n#include<vector>\n\n/**\n\
    \ * @brief Kd\u6728(WIP)\n */\n\ntemplate<typename T=long long,int sz=2>\nstruct\
    \ kd_tree{\n    typedef array<T,sz> Point;\n    Point point;\n    //vector<Point>\
    \ v;\n\tlong long v_size;\n    int axis,depth;\n    kd_tree *l=nullptr,*r=nullptr;\n\
    \    kd_tree(vector<Point> v=vector<Point>{},int depth=0):v_size(v.size()),depth(depth){\n\
    \        build(v,depth);\n    }\n    inline bool comp(const Point& s,const Point&\
    \ t){\n        rep(i,sz)if(s[i]>t[i])return 0;\n        return 1;\n    }\n   \
    \ inline void build(vector<Point> v,const int& depth){\n        if(v_size==0)return;\n\
    \        axis=depth%tuple_size<Point>::value;\n        sort(all(v),[this](const\
    \ auto s,const auto t){return s[this->axis]<t[this->axis];});\n        point=v[v.size()/2];\n\
    \        vector<Point> lv(v.size()/2),rv(v.size()-v.size()/2);\n        rep(i,lv.size())lv[i]=v[i];\n\
    \    \trep(i,rv.size())rv[i]=v[i+lv.size()];\n        if(lv.size()&&v.size()!=1)l=new\
    \ kdtree(lv,depth+1);\n        if(rv.size()&&v.size()!=1)r=new kdtree(rv,depth+1);\n\
    \    }\n\tvoid insert(Point p){\n\t\tv_size++;\n        if(v_size==1){\n     \
    \       return;\n        }\n        if(p[axis]<point[axis]){\n            if(!l)l=new\
    \ kdtree(vector<Point>{p},depth+1);\n            else l->insert(p);\n        }else{\n\
    \            if(!r)r=new kdtree(vector<Point>{p},depth+1);\n            else r->insert(p);\n\
    \        }\n    }\n\tvector<Point> search(const Point& lp,const Point& rp){\n\
    \        if(v_size==1&&comp(lp,point)&&comp(point,rp))return vector<Point>{point};\n\
    \        std::vector<Point> res;\n        if(r&&point[axis]<=rp[axis]){\n    \
    \        res=r->search(lp,rp);\n        }\n        if(l&&lp[axis]<=point[axis]){\n\
    \            vector<Point> tmp=l->search(lp,rp);\n\t\t\tres.insert(res.end(),all(tmp));\n\
    \        }\n        return res;\n    }\n};\n"
  code: "#pragma once\n#include<vector>\n\n/**\n * @brief Kd\u6728(WIP)\n */\n\ntemplate<typename\
    \ T=long long,int sz=2>\nstruct kd_tree{\n    typedef array<T,sz> Point;\n   \
    \ Point point;\n    //vector<Point> v;\n\tlong long v_size;\n    int axis,depth;\n\
    \    kd_tree *l=nullptr,*r=nullptr;\n    kd_tree(vector<Point> v=vector<Point>{},int\
    \ depth=0):v_size(v.size()),depth(depth){\n        build(v,depth);\n    }\n  \
    \  inline bool comp(const Point& s,const Point& t){\n        rep(i,sz)if(s[i]>t[i])return\
    \ 0;\n        return 1;\n    }\n    inline void build(vector<Point> v,const int&\
    \ depth){\n        if(v_size==0)return;\n        axis=depth%tuple_size<Point>::value;\n\
    \        sort(all(v),[this](const auto s,const auto t){return s[this->axis]<t[this->axis];});\n\
    \        point=v[v.size()/2];\n        vector<Point> lv(v.size()/2),rv(v.size()-v.size()/2);\n\
    \        rep(i,lv.size())lv[i]=v[i];\n    \trep(i,rv.size())rv[i]=v[i+lv.size()];\n\
    \        if(lv.size()&&v.size()!=1)l=new kdtree(lv,depth+1);\n        if(rv.size()&&v.size()!=1)r=new\
    \ kdtree(rv,depth+1);\n    }\n\tvoid insert(Point p){\n\t\tv_size++;\n       \
    \ if(v_size==1){\n            return;\n        }\n        if(p[axis]<point[axis]){\n\
    \            if(!l)l=new kdtree(vector<Point>{p},depth+1);\n            else l->insert(p);\n\
    \        }else{\n            if(!r)r=new kdtree(vector<Point>{p},depth+1);\n \
    \           else r->insert(p);\n        }\n    }\n\tvector<Point> search(const\
    \ Point& lp,const Point& rp){\n        if(v_size==1&&comp(lp,point)&&comp(point,rp))return\
    \ vector<Point>{point};\n        std::vector<Point> res;\n        if(r&&point[axis]<=rp[axis]){\n\
    \            res=r->search(lp,rp);\n        }\n        if(l&&lp[axis]<=point[axis]){\n\
    \            vector<Point> tmp=l->search(lp,rp);\n\t\t\tres.insert(res.end(),all(tmp));\n\
    \        }\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/kd_tree.hpp
  requiredBy: []
  timestamp: '2020-09-18 12:01:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/kd_tree.hpp
layout: document
redirect_from:
- /library/data_structure/kd_tree.hpp
- /library/data_structure/kd_tree.hpp.html
title: "Kd\u6728(WIP)"
---
