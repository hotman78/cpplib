template<typename T>
struct sqrtd{
    vector<T>v;
    int n,b,geta;
    sqrtd(vector<T>v):v(v),n(v.size()),b(sqrt(n)),geta(n),val(v),bukket((n+b)/b),sum((n+b)/b),cnt((n+b)/b),cnt2((n+b)/b,vector<int>(2*n)){
        for(int i=0;i<n;i++){
            cnt2[i/b][v[i]+geta]++;
            if(v[i]<0)continue;
            sum[i/b]+=v[i];
            cnt[i/b]++;
        }
    }
    vector<T>val;
    vector<T>bukket,sum,cnt;
    vector<vector<int>>cnt2;
    void add(int l,int r){
        if(l/b==r/b){
            for(int i=l;i<r;i++){
                cnt2[i/b][val[i]+geta]--;
                val[i]++;
                cnt2[i/b][val[i]+geta]++;
                if(val[i]+bukket[i/b]>0)sum[i/b]++;
                if(val[i]+bukket[i/b]==0)cnt[i/b]++;
            }
            return;
        }
        for(int i=l;i<l/b*b+b;i++){
            cnt2[i/b][val[i]+geta]--;
            val[i]++;
            cnt2[i/b][val[i]+geta]++;
            if(val[i]+bukket[i/b]>0)sum[i/b]++;
            if(val[i]+bukket[i/b]==0)cnt[i/b]++;
        }
        for(int i=l/b+1;i<r/b;i++){
            bukket[i]++;
            sum[i]+=cnt[i];
            cnt[i]+=cnt2[i][-bukket[i]+geta];
        }
        for(int i=r/b*b;i<r;i++){
            cnt2[i/b][val[i]+geta]--;
            val[i]++;
            cnt2[i/b][val[i]+geta]++;
            if(val[i]+bukket[i/b]>0)sum[i/b]++;
            if(val[i]+bukket[i/b]==0)cnt[i/b]++;
        }
    }
    void sub(int l,int r){
        if(l/b==r/b){
            for(int i=l;i<r;i++){
                cnt2[i/b][val[i]+geta]--;
                val[i]--;
                cnt2[i/b][val[i]+geta]++;
                if(val[i]+bukket[i/b]>-1)sum[i/b]--;
                if(val[i]+bukket[i/b]==-1)cnt[i/b]--;
            }
            return;
        }
        for(int i=l;i<l/b*b+b;i++){
            cnt2[i/b][val[i]+geta]--;
            val[i]--;
            cnt2[i/b][val[i]+geta]++;
            if(val[i]+bukket[i/b]>-1)sum[i/b]--;
            if(val[i]+bukket[i/b]==-1)cnt[i/b]--;
        }
        for(int i=l/b+1;i<r/b;i++){
            cnt[i]-=cnt2[i][-bukket[i]+geta];
            bukket[i]--;
            sum[i]-=cnt[i];
        }
        for(int i=r/b*b;i<r;i++){
            cnt2[i/b][val[i]+geta]--;
            val[i]--;
            cnt2[i/b][val[i]+geta]++;
            if(val[i]+bukket[i/b]>-1)sum[i/b]--;
            if(val[i]+bukket[i/b]==-1)cnt[i/b]--;
        }
    }
    T query(int l,int r){
        T res=T();
        if(l/b==r/b){
            for(int i=l;i<r;i++){
                if(val[i]+bukket[i/b]>0)res+=val[i]+bukket[i/b];
            }
            return res;
        }
        for(int i=l;i<l/b*b+b;i++){
            if(val[i]+bukket[i/b]>0)res+=val[i]+bukket[i/b];
        }
        for(int i=l/b+1;i<r/b;i++){
            res+=sum[i];
        }
        for(int i=r/b*b;i<r;i++){
            if(val[i]+bukket[i/b]>0)res+=val[i]+bukket[i/b];
        }
        return res;
    }
};