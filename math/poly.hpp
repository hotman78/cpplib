#pragma once

using poly=vector<mint>;
int size(const poly&x){return x.size();}
poly shrink(poly x){
    while(size(x)>=1&&x.back().val()==0)x.pop_back();
    return x;
}

poly pre(const poly&x,int n){
    auto res=x;
    res.resize(n);
    return res;
}
poly operator+(const poly& x,const poly& y){
    poly res(max(x.size(),y.size()));
    rep(i,0,x.size())res[i]+=x[i];
    rep(i,0,y.size())res[i]+=y[i];
    return res;
}
poly& operator*=(poly& x,const mint& y){
    rep(i,0,x.size())x[i]*=y;
    return x;
}
poly operator*(poly x,const mint& y){
    return x*=y;
}

poly operator-(const poly& x){
    poly res(x.size());
    rep(i,0,x.size())res[i]=-x[i];
    return res;
}
poly operator-(const poly&x,const poly&y){
    return x+(-y);
}


poly operator*(const poly&x,const poly&y){
    return atcoder::convolution(x,y);
}

// poly operator*(const poly&x,const poly&y){
//     return convolution(x,y);
// }

poly& operator+=(poly& x,const poly& y){
    return x=(x+y);
}
poly& operator-=(poly& x,const poly& y){
    return x=(x-y);
}
poly& operator*=(poly& x,const poly& y){
    return x=(x*y);
}
istream& operator>>(istream& in,poly& y){
    int n=size(y);
    rep(i,0,n)in>>y[i];
    return in;
}
ostream& operator<<(ostream& out,const poly& y){
    int n=size(y);
    rep(i,0,n){
        if(i)out<<' ';
        out<<y[i].val();
    }
    return out;
}
poly diff(const poly& x){
    int n=size(x);
    poly res(n-1);
    rep(i,0,n-1)res[i]=x[i+1]*(i+1);
    return res;
}
poly integrate(const poly& x){
    int n=size(x);
    poly res(n+1);
    rep(i,1,n+1)res[i]=x[i-1]/i;
    return res;
}

poly inv(const poly& x){
    int n=size(x);
    if(n==1)return poly{x[0].inv()};
    auto c=inv(pre(x,(n+1)/2));
    return pre(c*(poly{2}-c*x),n);
}

poly log(const poly& x){
    int n=size(x);
    assert(x[0].val()==1);
    return pre(integrate(diff(x)*inv(x)),n);
}

poly exp(const poly& x){
    assert(x[0].val()==0);
    int n=size(x);
    if(n==1)return poly{1};
    auto c=exp(pre(x,(n+1)/2));
    return pre(c*(poly{1}-log(pre(c,n))+x),n);
}

pair<poly,poly> divmod(const poly&a,const poly& b){
    assert(!b.empty());
    if(b.back().val()==0)return divmod(a,shrink(b));
    if(a.empty())return make_pair(poly{},poly{});
    if(a.back().val()==0)return divmod(shrink(a),b);
    int n=max(0,size(a)-size(b)+1);
    if(n==0)return make_pair(poly{},a);
    auto c=a;
    auto d=b;
    reverse(c.begin(),c.end());
    reverse(d.begin(),d.end());
    d.resize(n);
    c*=inv(d);
    c.resize(n);
    reverse(c.begin(),c.end());
    return make_pair(c,pre(a-c*b,(int)b.size()-1));
}

poly multipoint_evalution(const poly&a,const poly&b){
    int n=b.size();
    vector<poly>v(n*2);
    rep(i,0,n){
        v[i+n]=poly{-mint(b[i]),mint(1)};
    }
    for(int i=n-1;i>=1;--i){
        v[i]=v[i*2]*v[i*2+1];
    }
    poly ans(n);
    v[0]=a;
    rep(i,1,n*2){
        v[i]=divmod(v[i/2],v[i]).second;
        if(i>=n)ans[i-n]=v[i][0];
    }
    return ans;
}

vector<mint> composition(vector<mint>f,vector<mint>g){
    int n=f.size(),m=g.size();
    assert(n==m);
    vector<mint>res(n);
    int b=ceil(sqrt(n));
    vector<vector<mint>>g_pow(b+1);
    g_pow[0]=vector<mint>{1};
    for(int i=0;i<b;++i){
        g_pow[i+1]=g_pow[i]*g;
        g_pow[i+1].resize(n);
    }
    vector<mint>g_pow2=vector<mint>{1};
    for(int i=0;i<n;i+=b){
        vector<mint> tmp;
        for(int j=i;j<std::min(i+b,n);++j){
            tmp+=g_pow[j-i]*f[j];
        }
        res+=tmp*g_pow2;
        res.resize(n);
        g_pow2*=g_pow[b];
        g_pow2.resize(n);
    }
    return res;
}