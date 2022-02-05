#pragma once
#include"binary_indexed_tree.hpp"
template<typename X=long long,typename Y=X,typename T=long long,typename F=std::plus<T>,typename Inv=minus<T>>
std::vector<T> static_rectangle_sum(const vector<tuple<X,Y,T>>& p,const vector<tuple<X,Y,X,Y>>&query,T zero=T(),F f=F(),Inv inv=Inv()){
    std::vector<T>ans(query.size(),zero);
    const int n=p.size(),q=query.size();
    using Point=std::tuple<int,T>;
    using Query=std::tuple<int,int,int>;
    std::vector<std::pair<std::pair<X,int>,std::variant<Point,Query>>>event;
    std::vector<Y>idx;
    for(int i=0;i<n;++i){
        idx.emplace_back(get<1>(p[i]));
    }
    for(int i=0;i<q;++i){
        idx.emplace_back(get<1>(query[i]));
        idx.emplace_back(get<3>(query[i]));
    }
    sort(idx.begin(),idx.end());
    for(int i=0;i<n;++i){
        auto y=std::lower_bound(idx.begin(),idx.end(),std::get<1>(p[i]))-idx.begin();
        event.emplace_back(std::make_pair(get<0>(p[i]),2),Point{y,get<2>(p[i])});
    }
    for(int i=0;i<q;++i){
        auto l=std::lower_bound(idx.begin(),idx.end(),std::get<1>(query[i]))-idx.begin();
        auto r=std::lower_bound(idx.begin(),idx.end(),std::get<3>(query[i]))-idx.begin();
        event.emplace_back(std::make_pair(get<0>(query[i]),0),Query{l,r,i});
        event.emplace_back(std::make_pair(get<2>(query[i]),1),Query{l,r,i+q});
    }
    sort(event.begin(),event.end(),[](const auto&s,const auto&t){return s.first<t.first;});
    BIT b(idx.size(),zero,f,inv);
    for(auto [x,e]:event){
        if(std::holds_alternative<Point>(e)){
            auto [y,val]=std::get<Point>(e);
            b.add(y,val);
        }else{
            auto [l,r,id]=std::get<Query>(e);
            if(id<q){
                ans[id]=inv(ans[id],b.sum(l,r));
            }else{
                id-=q;
                ans[id]=f(ans[id],b.sum(l,r));
            }
        }
    }
    return ans;
}