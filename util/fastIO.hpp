/**
 * @brief 高速入出力(WIP)
 */

struct fastI{
    char in[1<<26];
    char const*o;
    fastI(){
        o = in; 
        in[fread(in,1,sizeof(in)-4,stdin)]=0;
    }
    fastI& operator>>(char& c){
        while(*o&&*o<=32)++o;
        c=*o++;
        return *this;
    }
    fastI& operator>>(int& u){
        u=0; 
        unsigned s=0;
        while(*o&&*o<=32)++o;
        if (*o == '-')s = ~s, ++o; else if (*o == '+')++o;
        while('0'<=*o && *o<='9')u = (u<<3) + (u << 1) + (*o++ - '0');
        (u^=s)+=!!s;
        return *this;
    }
    fastI& operator>>(long long& u){
        u=0;
        uint64_t s=0;
        while(*o&&*o<=32)++o;
        if (*o == '-')s = ~s, ++o; else if (*o == '+')++o;
        while('0'<=*o && *o<='9')u = (u<<3) + (u << 1) + (*o++ - '0');
        (u^=s)+=!!s;
        return *this;
    }
} fin;

struct fastO{
    char out[1<<26];
    char *o;
    fastO(){
        o=out;
    }
    ~fastO(){
        fwrite(out,1,o-out,stdout);
    }
    fastO& operator<<(const char& c){
        *o++=c;
        return *this;
    }
    fastO& operator<<(int u){
         if(u){
            auto be=o;
            while(u)*o++=u%10+'0',u/=10;
            auto en=o;
            while(be<en)std::swap(*--en,*be++);
        }else *o++='0';
        return *this;
    }
    fastO& operator<<(long long u){
        if(u){
            auto be=o;
            while(u)*o++=u%10+'0',u/=10;
            auto en=o;
            while(be<en)std::swap(*--en,*be++);
        }else *o++='0';
        return *this;
    }
} fout;