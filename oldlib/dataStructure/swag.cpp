template<typename T,typename E=T>
class swag{
    stack<pair<T,E>>front,back;
    public:
    inline int size(){
        return front.size()+back.size();
    }
    inline int empty(){
        return front.empty()&&back.empty();
    }
    void push(T val){
        if(back.empty()){
            back.emplace(val,f(e,val));
        }else{
            back.emplace(val,f(back.top().second,val));
        }
    }
    void pop(){
        if(front.empty()){
            while(!back.empty()){
                const T val=back.top().first;
                back.pop();
                if(front.empty())front.emplace(val,f(val,e));
                else front.emplace(val,f(val,front.top().second));
            }
        }
        front.pop();
    }
    E fold(){
        return f(front.empty()?e:front.top().second,back.empty()?e:back.top().second);
    }
    private:
    E f(const T& s,const T& t){
        return min(s,t);
    }
    E e=1LL<<60;
};