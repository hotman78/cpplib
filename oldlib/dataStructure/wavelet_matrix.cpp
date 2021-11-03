
class bitvec{
	using u32=unsigned int;
	using u8=unsigned char;
    using lint=long long;
	//4*10^6対応
	//ブロック幅8,チャンク幅256
	const int bw=8,cw=256;
	const int len=15625,sz=4000000;
	bool data[4000000]={0};
	u32 chunk[15626];
	u8 block[15625][33];
	public:
	bitvec(){}
	void build(){
		chunk[0]=0;
		for(int i=0;i<15625;i++){
			block[i][0]=0;
			for(int j=0;j<31;j++){
				block[i][j+1]=block[i][j];
				for(int k=0;k<8;k++)block[i][j+1]+=data[i*cw+j*bw+k];
			}
			chunk[i+1]=chunk[i]+block[i][31];
			for(int k=0;k<8;k++)chunk[i+1]+=data[i*cw+31*bw+k];
		}
	}
	inline void set(int idx,bool b){data[idx]=b;}
	inline bool get(int idx){return data[idx];}
    inline int rank(int idx,bool b)const{
        if(b)return rank1(idx);
        else return idx-rank1(idx);
	}
	inline int rank1(int idx)const{
		int a=idx/cw,b=idx%cw/bw,c=idx%bw;
		int res=chunk[a]+block[a][b];
		for(int i=1;i<c+1;i++)res+=data[idx-i];
		return res;
	}
	inline int select(int num){
		if (num==0)return 0;
        if (rank1(sz)<num)return -1;
        int ok=sz,ng=0;
		while (ok-ng>1) {
			int mid=(ok+ng)/2;
			if (rank1(mid)>=num)ok =mid;
			else ng=mid;
		}
		return ok;
	}
};

class wavelet_matrix{
    using lint=long long;
    const lint MAXLOG=32;
	vector<bitvec> matrix;
    lint sz;
	public:
	wavelet_matrix(vector<lint> data){
        sz=data.size();
		matrix.resize(MAXLOG);
		for(int i=MAXLOG-1;i>=0;i--){
			for(int j=0;j<(int)data.size();j++){
				matrix[i].set(j,data[j]&(1LL<<i));
			}
			matrix[i].build();
			stable_sort(all(data),[&](auto s,auto t){return (s&(1LL<<i))<(t&(1LL<<i));});
		}
	}
    lint rank(lint pos,lint x){
        lint s=0,e=pos;
        for(int i=MAXLOG-1;i>=0;i--){
            bool b=x&(1LL<<i);
            s=matrix[i].rank(s,b);
            e=matrix[i].rank(e,b);
            if(b==1){
                lint l=matrix[i].rank(sz,0);
                s+=l;
                e+=l;
            }
        }
        return e-s;
    }
	void select(){
		for(int i=MAXLOG;i>=0;i--){

		}
	}
    lint kth_element(lint l,lint r,lint k){
        lint ans=0;
        for(int i=MAXLOG-1;i>=0;i--){
            lint cnt=matrix[i].rank(r,0)-matrix[i].rank(l,0);
            lint b=cnt<=k;
            ans+=b<<i;
            l=matrix[i].rank(l,b);
            r=matrix[i].rank(r,b);
            if(b==1){
                lint t=matrix[i].rank(sz,0);
                k-=cnt;
                l+=t;
                r+=t;
            }
        }
        return ans;
    }
};
