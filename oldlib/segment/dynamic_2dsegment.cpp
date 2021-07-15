template<typename T>
struct segment2d{
    dynamic_segment<dynamic_segment<T,T,T>,T,T> seg;
    void update(int64_t x,int64_t y,T val){
        auto f=[&](auto& s,auto t){
            s.update(0,1LL<<30,y,t,0,[](auto& s,auto t){s+=t;});
        };
        seg.update(0,1LL<<30,x,val,dynamic_segment<T,T,T>(),f);
    }
    T get(int64_t lx,int64_t ly,int64_t rx,int64_t ry){
        auto f=[&](auto s){
            return s.get(0,1LL<<30,ly,ry,0,[](auto s,auto t){return s+t;},[](auto s){return s;});
        };
        return seg.get(0,1LL<<30,lx,rx,0,[](auto s,auto t){return s+t;},f);
    }
};