template<typename T>
class pqueue{
    pvector<T> v;
    int s,e;
    public:
    pqueue():s(0),e(0){}
    T front(){
        return v.get(s);
    }
    pqueue pop(){
        auto res=pqueue(*this);
        res.s++;
        return res;
    }
    pqueue insert(T x){
        auto res=pqueue(*this);
        res.v=res.v.set(e,x);
        res.e++;
        return res;
    }
};
