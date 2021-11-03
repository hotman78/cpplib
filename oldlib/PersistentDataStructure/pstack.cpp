template<typename T>
struct pstack{
    pstack* pre;
    T val;
    int sz;
    pstack():pre(nullptr),val(T()),sz(0){}
    pstack(pstack* pre,T val):pre(pre),val(val),sz(pre->sz+1){}
    pstack pop(){return *pre;}
    T top(){return val;}
    pstack insert(T val){return pstack(new pstack(*this),val);}
    int size(){return sz;}
};