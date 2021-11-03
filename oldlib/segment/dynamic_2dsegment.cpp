#include"./dynamic_segment.cpp"

template<typename T>
struct segment2d{

    dynamic_segment<dynamic_segment<T,T,T>,T,T> seg;
    lint n,sz=1;
    segment2d(lint n=1LL<<30):n(n){
        auto f=[](auto s,auto t){return min(s,t);};
        while(sz<=n)sz*=2;
    }
    void update(int64_t x,int64_t y,T val){
        auto f=[&](auto& s,auto t){
            s.update(0,sz,y,t,1LL<<30,[](auto& s,auto t){s=min(s,t);});
        };
        seg.update(0,sz,x,val,dynamic_segment<T,T,T>(),f);
    }
    T get(int64_t lx,int64_t ly,int64_t rx,int64_t ry){
        auto f=[&](auto s){
            return s.get(0,sz,ly,ry,1LL<<30,[](auto s){return s;});
        };
        return seg.get(0,sz,lx,rx,1LL<<30,[](auto s,auto t){return min(s,t);},f);
    }
};