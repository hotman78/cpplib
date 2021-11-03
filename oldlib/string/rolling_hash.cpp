struct rolling_hash{
    using u64=uint64_t;
    constexpr static u64 mod=(1ULL<<61)-1;
    constexpr static u64 base=10007;
    int sz;
    u64 hash;
    constexpr rolling_hash():sz(0),hash(0){}
    constexpr rolling_hash(char c):sz(1),hash(c){}
    rolling_hash(string s):sz(0),hash(0){
        for(auto c:s)(*this)+=c;
    }
    constexpr u64 pow(u64 s,int t){
        u64 ret=1;
        while(t){
            if(t&1)ret=mul(ret,s);
            s=mul(s,s);
            t/=2;
        }
        return ret;
    }
    constexpr u64 add(u64 s,u64 t)noexcept{
        s+=t;
        return s>=mod?s-mod:s;
    }
    constexpr u64 sub(u64 s,u64 t)noexcept{
        if(s<t)s+=mod;
        return s-t;
    }
    constexpr u64 mul(u64 a,u64 b)noexcept{
        u64 au=a>>31,ad=a&((1ULL<<31)-1);
        u64 bu=b>>31,bd=b&((1ULL<<31)-1);
        u64 mid=au*bd+ad*bu;
        u64 ret=(au*bu*2+ad*bd+(mid>>30)+((mid&((1ULL<<30)-1))<<31));
        ret=(ret>>61)+(ret&mod);
        return ret>=mod?ret-mod:ret;
    }
    constexpr rolling_hash operator+(rolling_hash s)const noexcept{return rolling_hash(*this)+=s;}
    constexpr bool operator==(rolling_hash s)noexcept{return hash==s.hash&&sz==s.sz;}
    constexpr bool operator<(rolling_hash s)const noexcept{return make_pair(hash,sz)<make_pair(s.hash,s.sz);}
    constexpr bool operator>(rolling_hash s)const noexcept{return make_pair(hash,sz)>make_pair(s.hash,s.sz);}
    constexpr bool operator<=(rolling_hash s)const noexcept{return make_pair(hash,sz)<=make_pair(s.hash,s.sz);}
    constexpr bool operator>=(rolling_hash s)const noexcept{return make_pair(hash,sz)>=make_pair(s.hash,s.sz);}
    constexpr rolling_hash operator+=(rolling_hash s)noexcept{
        (*this).hash=add((*this).hash*pow(base,s.sz),s.hash);
        (*this).sz+=s.sz;
        return *this;
    }
    constexpr int size(){return sz;}
};


// struct rolling_hash{
//     using u64 = std::uint_fast64_t;
//     class hash_string{
//         public:
//         u64 digit;
//         vector<u64> hash;
//         rolling_hash* par;
//         u64 base,mod_num;
//         vector<u64> mod;
//         hash_string(){cerr<<"err"<<endl;}
//         hash_string(rolling_hash* par):digit(0),par(par),base(par->base),mod_num(par->mod_num),mod(par->mod){hash.resize(mod_num,0);}
//         hash_string(rolling_hash* par,u64 digit,vector<u64> hash):digit(digit),hash(hash),par(par),base(par->base),mod_num(par->mod_num),mod(par->mod){}
//         hash_string operator +(char c){
//             return hash_string(*this)+=c;
//         }
//         hash_string operator +=(char c){
//             vector<u64>hashTable(mod_num);
//             rep(i,mod_num)this->hash[i]=(hash[i]*base+u64(c))%mod[i];
//             this->digit++;
//             return *this;
//         }
//         hash_string operator +(hash_string s){
//             return hash_string(*this)+=s;
//         }
//         hash_string operator +=(hash_string s){
//             vector<u64>hashTable(mod_num);
//             rep(i,mod_num)this->hash[i]=(hash[i]*mod_pow(base,s.digit,mod[i])+s.hash[i])%mod[i];
//             this->digit+=s.digit;
//             return *this;
//         }
//         hash_string operator -(hash_string s){
//             vector<u64>hashTable(mod_num);
//             rep(i,mod_num)hashTable[i]=(hash[i]+mod[i]-(s.hash[i]*mod_pow(base,digit-s.digit,mod[i]))%mod[i])%mod[i];
//             return hash_string(par,digit-s.digit,hashTable);
//         }
//         hash_string operator -(char c){
//             vector<u64>hashTable(mod_num);
//             rep(i,mod_num)hashTable[i]=(hash[i]+mod[i]-(u64(c)*mod_pow(base,digit-1,mod[i]))%mod[i])%mod[i];
//             return hash_string(par,digit-1,hashTable);
//         }
//         hash_string operator *(u64 num){
//             u64 exp=num;
//             auto res=hash_string(par);
//             auto x=*this;
//             while(exp){
//                 if(exp%2)res=res+x;
//                 x=x+x;
//                 exp/=2;
//             }
//             return res;
//         }
//         bool operator ==(hash_string s){
//             return hash==s.hash;
//         }
//         private:
//         inline u64 mod_pow(u64 x,const u64& y,const u64& _mod){
//             if(par->cache[_mod].count(y)){return par->cache[_mod][y];}
//             u64 exp=y;
//             u64 res=1;
//             while(exp){
//                 if(exp%2){
//                     res*=x;
//                     res%=_mod;
//                 }
//                 x*=x;
//                 x%=_mod;
//                 exp/=2;
//             }
//             return par->cache[_mod][y]=res;
//         }
//     };
//     vector<hash_string>hash;
//     const u64 base=10007,mod_num=3;
//     const vector<u64> mod={1000000007,999999937,998244353};
//     unordered_map<u64,unordered_map<u64,u64>>cache;
//     rolling_hash(){
//         hash.resize(1,hash_string(this));
//     }
//     rolling_hash(string s){
//         hash.resize(s.size()+1,hash_string(this));
//         repi(i,1,s.size()+1)hash[i]=hash[i-1]+s[i-1];
//     }
//     hash_string operator()(int l,int len=-1){
//         if(len==-1)return hash[hash.size()-1]-hash[l];
//         else return hash[l+len]-hash[l];
//     }
//     hash_string operator()(){
//         return hash[hash.size()-1];
//     }
// };