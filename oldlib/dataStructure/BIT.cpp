
struct rangeBIT{
    private:
    vector<lint> bit,bit2;
    lint n;
    public:
    BIT(lint n):n(n){
        bit.resize(n+1,0);
        bit2.resize(n+1,0);
    }
    //0-indexed [0,x)-sum
    lint sum(lint x){
        lint res=0;
        for(lint i=x;i>0;i-=i&-i)res+=bit[i];
        for(lint i=x;i>0;i-=i&-i)res+=x*bit2[i];
        return res;
    }
    //0-indexed [x,y)-sum
    lint sum(lint x,lint y){
        return sum(y)-sum(x);
    }
    //0-indexed [l,r)add
    void add(lint l,lint r,lint x){
        l++;r++;
        if(0>r||l>n)return;
        for(lint i=l;i<=n;i+=i&-i)bit[i]+=-x*(l-1);
        for(lint i=r;i<=n;i+=i&-i)bit[i]+=x*r;
        for(lint i=l;i<=n;i+=i&-i)bit2[i]+=x;
        for(lint i=r;i<=n;i+=i&-i)bit2[i]+=-x;
    }
};

// struct BIT{
//     public:
//     vector<lint> bit;
//     lint n;
//     BIT(lint _n){
//         n=_n;
//         bit.resize(n+1,0);
//     }
//     //1-indexed [1,x]-sum
//     lint sum(lint x){
//         if(!x)return 0;
//         return bit[i]+sum(i-(i&-i));
//     }
//     //1-indexed [1,x]-sum
//     lint sum(lint i){
//         if(!i)return 0;
//         return bit[i]+sum(i-(i&-i));
//     }
//     //1-indexed
//     void add(lint i,lint x){
//         if(i>n)return;
//         bit[i]+=x;
//         add(i-(i&-i),x);
//     }
// };
struct BIT{
    hash_map<lint,lint> bit;
    lint n;
    BIT(lint n):n(n){
        //bit.resize(n+1,0);
    }
    //1-indexed [1,x]-sum
    lint sum(lint x){
        lint res=0;
        for(lint i=x;i>0;i-=i&-i)res+=bit[i];
        return res;
    }
    //1-indexed [x,y]-sum
    lint sum(lint x,lint y){
        return sum(y)-sum(x);
    }
    //1-indexed
    void add(lint x,lint val){
        x++;
        if(x>n)return;
        for(lint i=x;i<=n;i+=i&-i)bit[i]+=val;
    }
};

// struct BIT{
//     public:
//     vector<lint> bit;
//     lint n;
//     BIT(lint _n){
//         n=_n;
//         bit.resize(n+1,0);
//     }
//     lint sum(lint i){
//         if(!i)return 0;
//         return bit[i]+sum(i-(i&-i));
//     }
//     lint sum(lint a,lint b){
//         return sum(b)-sum(a);
//     }
//     void add(lint i,lint x){
//         if(i>n)return;
//         bit[i]+=x;
//         add(i+(i&-i),x);
//     }
//     static lint inversion(vector<lint> v){
//         lint tmp=min(v);
//         rep(i,v.size())v[i]-=tmp-1;
//         BIT b(max(v));
//         lint ans = 0;
//         rep(i,v.size()){
//             ans+=i-b.sum(v[i]);
//             b.add(v[i],1);
//         }
//         return ans;
//     }
//     static lint inversion2(vector<lint> v){
//         lint tmp=min(v);
//         rep(i,v.size())v[i]-=tmp-1;
//         BIT b(max(v));
//         lint ans = 0;
//         rep(i,v.size()){
//             ans+=b.sum(v[i]);
//             b.add(v[i],1);
//         }
//         return ans;
//     }
// };

struct BIT2D{
    vector<vector<lint>> bit;
    lint n,m;
    BIT2D(lint n,lint m):n(n),m(m){
        bit.resize(n+1,vector<lint>(m+1,0));
    }
    //1-indexed ([1,x],[1,y])-sum
    lint get(lint x,lint y){
        lint res=0;
        for(lint i=x;i>0;i-=i&-i)for(lint j=y;j>0;j-=j&-j)res+=bit[i][j];
        return res;
    }
    lint get(lint x1,lint y1,lint x2,lint y2){
        return get(x2,y2)-get(x1-1,y2)-get(x2,y1-1)+get(x1-1,y1-1);
    }
    //1-indexed
    void add(lint x,lint y,lint val){
        if(x>n||y>m)return;
        for(lint i=x;i<=n;i+=i&-i)for(lint j=y;j<=n;j+=j&-j)bit[i][j]+=val;
    }
};