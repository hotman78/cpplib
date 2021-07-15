
//WIP (verify してない！注意)
template<typename T>
struct slope_trick{
    T mn,add_L,add_R,inf;
    priority_queue<T>L;
    priority_queue<T,vector<T>,greater<T>>R;
    slope_trick(T inf):mn(0),add_L(0),add_R(0),inf(inf){
        L.emplace(-inf);
        R.emplace(inf);
    }
    T min(){return mn;}
    T operator+=(T x){return mn+=x;}
    T operator-=(T x){return mn-=x;}
    //add max(0,x-a)
    void add_r(T a){
        mn+=std::max(T(),L.top()+add_L-a);
        L.emplace(a);
        R.emplace(L.top()+add_L-add_R);
        L.pop();
    }
    //add max(0,a-x)
    void add_l(T a){
        mn+=std::max(T(),a-(R.top()+add_R));
        R.emplace(a);
        L.emplace(R.top()+add_R-add_L);
        R.pop();
    }

    void add_abs(T a){
        add_r(a);add_l(a);
    }
    void cum_min(){
        R.clear();
        R.emplace(inf);
    }
    void cum_min_r(){
        L.clear();
        L.emplace(-inf);
    }
    void slide(T a){
        add_L+=a;add_R+=a;
    }
    void sliding_window(T a,T b){
        add_L+=a;add_R+=b;
    }
    T eval(T x){
        T res=mn;
        stack<T>tmp;
        T now=L.top()+add_L,d=T();
        while(x<L.top()+add_L){
            res+=d*(now-(L.top()+add_L));
            now=L.top()+add_L;
            tmp.emplace(L.top());
            L.pop();
            d--;
        }
        if(x<now){
            res+=d*(now-x);
        }
        while(!tmp.empty())L.emplace(tmp.top()),tmp.pop();

        now=R.top()+add_R,d=T();
        while(x>R.top()+add_R){
            res+=d*(R.top()+add_R-now);
            now=R.top()+add_R;
            tmp.emplace(R.top());
            R.pop();
            d++;
        }
        if(x>now){
            res+=d*(x-now);
        }
        while(!tmp.empty())R.emplace(tmp.top()),tmp.pop();
        return res;
    }
};