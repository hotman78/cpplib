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
        if(u<0)u=~u+1,*o++='-';
        if(u){
            auto be=o;
            while(u)*o++=u%10+'0',u/=10;
            auto en=o;
            while(be<en)swap(*--en,*be++);
        }else *o++='0';
        return *this;
    }
    fastO& operator<<(long long u){
        if(u<0)u=~u+1,*o++='-';
        if(u){
            auto be=o;
            while(u)*o++=u%10+'0',u/=10;
            auto en=o;
            while(be<en)swap(*--en,*be++);
        }else *o++='0';
        return *this;
    }
} fout;

// struct fastIO{
// #pragma GCC diagnostic ignored "-Wchar-subscripts"
// #pragma GCC diagnostic ignored "-Wunused-result"
// 	constexpr static unsigned short buf=-1;
// 	char in[1<<18],out[1<<18];
// 	unsigned short in_idx=-1,out_idx=-1;
// 	bool in_f=0;
// 	fastIO(){
// 		fread(in,1,buf+1,stdin);
// 	}
// 	inline void load(){
// 		while(in[++in_idx]==' '||in[in_idx]=='\n');
// 		--in_idx;
// 		if(in_f&&in_idx<buf/2-100){
// 			fread(in+buf/2,1,buf/2+2,stdin);
// 			in_f=0;
// 		}else if(!in_f&&in_idx>buf/2+100){
// 			fread(in,1,buf/2,stdin);
// 			in_f=1;
// 		}
// 		if(out_idx>=buf-20)flush();
// 	}
// 	inline void flush(){
// 		fwrite(out,1,++out_idx,stdout);
// 		out_idx=-1;
// 	}
// 	inline fastIO& operator >>(int& i){
// 		i=0;
// 		char c;
// 		while(48<=(c=in[++in_idx])&&c<58)i=move(i)*10+c-48;
// 		load();
// 		return *this;
// 	}
// 	inline fastIO& operator >>(long long& i){
// 		i=0;
// 		char c;
// 		while(48<=(c=in[++in_idx])&&c<58)i=move(i)*10+c-48;
// 		load();
// 		return *this;
// 	}
// 	inline fastIO& operator >>(string& i){
// 		char c;
// 		while((c=in[++in_idx])!=' ')putchar(c);
// 		load();
// 		return *this;
// 	}
// 	inline fastIO& operator <<(int i){
// 		char n[10];
// 		char idx=0;
// 		while(i)n[idx++]=i%10+48,i/=10;
// 		while(idx--)out[++out_idx]=n[idx];
// 		return *this;
// 	}
// 	inline fastIO& operator <<(long long i){
// 		char n[19];
// 		char idx=0;
// 		while(i)n[idx++]=i%10+48,i/=10;
// 		while(idx--)out[++out_idx]=n[idx];
// 		load();
// 		return *this;
// 	}
// 	inline fastIO& operator <<(char c){
// 		out[++out_idx]=c;
// 		load();
// 		return *this;
// 	}
// #pragma GCC diagnostic warning "-Wchar-subscripts"
// #pragma GCC diagnostic warning "-Wunused-result"
// } fio;