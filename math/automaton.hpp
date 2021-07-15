template<int base=10>
struct digit_automaton{
    using u64=unsigned long long;
    string n;
    u64 max_digit;
    digit_automaton(string _n):n(_n),max_digit(_n.size()){
        reverse(n.begin(),n.end());
    }
    static int init(){return 0;}
    int next(int id,int c){
        const u64 now_digit=id/2;
        const bool flag=id%2;
        if(now_digit>=max_digit){
            if(c){
                return (now_digit+1)*2+1;
            }else{
                return (now_digit+1)*2+flag;
            }
        }else{
            if(c<n[now_digit]-'0'){
                return (now_digit+1)*2+0;
            }else if(c>n[now_digit]-'0'){
                return (now_digit+1)*2+1;
            }else{
                return (now_digit+1)*2+flag;
            }
        }
    }
    bool ok(int id){
        return id%2==0;
    }
};

struct having_zero_automaton{
    int next(int id,int c){
        if(id==0&&c==0)return 1;
        if(id==1&&c!=0)return 2;
        return id;
    }
    int ok(int id){
        return id==2;
    }
};