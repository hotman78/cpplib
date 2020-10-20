template<typename T>
struct my_deque{
    T* v;
    int l=0,r=0,sz=1;
    inline int mod(int x){
        if(x>=sz)return x-sz;
        else return x;
    }
    my_deque(){
        v=(T*)malloc(sizeof(T));
    }
    bool empty(){
        return l==r;
    }
    int size(){
        return mod(r-l+sz);
    }
    void resize(){
        T* nv=(T*)malloc(sizeof(T)*sz*2);
        int idx=l;
        for(int i=0;i<sz;++i){
            nv[i]=v[idx];
            idx=mod(idx+1);
        }
        l=0;
        r=sz;
        swap(v,nv);
        free(nv);
        sz*=2;
    }
    void pop_back(){
        r=mod(r-1+sz);
    }
    void pop_front(){
        l=mod(l+1);
    }
    void push_back(T x){
        v[r]=x;
        r=mod(r+1);
        if(l==r)resize();
    }
    void push_front(T x){
        l=mod(l-1+sz);
        v[l]=x;
        if(l==r)resize();
    }
    T& back(){
        return v[mod(r-1+sz)];
    }
    T& front(){
        return v[l];
    }
    T& operator[](size_t idx){
        assert(0<=idx&&idx<size());
        return v[mod(l+idx)];
    }
};