vector<lint>prime_factor(lint n){
    auto is_prime=[](lint n){
        if(n<=1)return 0;
        if(n==2)return 1;
        if(n%2==0)return 0;
        lint s=0,d=n-1;
        while(d%2)d/=2,s++;
        auto mod_pow=[](__int128_t a,__int128_t b,__int128_t n){
            lint res=1;
            while(b){
                if(b%2)res=res*a%n;
                a=a*a%n;
                b/=2;
            }
            return lint(res);
        };
        for(lint e:{2,3,5,7,11,13,17,19,23,29,31,37}){
            if(n<=e)break;
            lint ap=mod_pow(e,d,n);
            if(ap==1||ap==n-1)continue;
            bool b=1;
            for(int i=0;i<s;i++){
                if((ap=(__int128_t)ap*ap%n)==n-1){
                    b=0;
                    break;
                }
            }
            if(b)return 0;
        }
        return 1;
    };
    vector<lint>v;
    function<void(lint,lint&)> f=[&](lint n,lint& c)->void{
        if(n==1)return;
        if(n%2==0){
            v.emplace_back(2);f(n/2,c);
            return;
        }
        if(is_prime(n)){
            v.emplace_back(n);
            return;
        }
        while(1){
            lint x=2,y=2,d=1;
            while(d==1){
                x=((__int128_t)x*x+c)%n;
                y=((__int128_t)y*y%n+c)%n;
                y=((__int128_t)y*y%n+c)%n;
                d=gcd(abs(x-y),n);
            }
            if(d==n){
                c++;
                continue;
            }
            f(d,c);
            f(n/d,c);
            return;
        }
    };
    lint c=1;
    f(n,c);
    return v;
}

unordered_map<lint,lint> prime_factor(lint n) {
    unordered_map<lint,lint>ret;
    for(lint i=2;i*i<=n;i++){
        while(n%i==0){
            ret[i]++;
            n/=i;
        }
    }
    if(n!=1)ret[n]=1;
    return ret;
}