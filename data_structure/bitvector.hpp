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