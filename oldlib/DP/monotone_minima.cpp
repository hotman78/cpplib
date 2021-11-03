//monotoneな二変数関数に対して各行の最小値を求める
template<typename T>
vector<int> monotone_minima(int h,int w,T inf,auto f){
    vector<int>ret(h);
    auto g=[&](auto g,int a,int b,int c,int d,T inf,auto f)->void{
        int e=(a+b)/2,idx=0;
        T mn=inf;
        for(int i=c;i<d;++i){
            if(mn>f(e,i))mn=f(e,i),idx=i;
        }
        ret[e]=idx;
        if(b>a+1){
            g(g,a,e,c,idx+1,inf,f);
            g(g,e,b,idx,d,inf,f);
        }
    };
    g(g,0,h,0,w,inf,f);
    return ret;
}