class bitvec{
	using u32=unsigned int;
	using u8=unsigned char;
	//4*10^6対応
	//ブロック幅8,チャンク幅256
	constexpr static int bw=8,cw=256;
	constexpr static int len=15625,sz=4000000;
	constexpr static bool data[4000000]={0};
	constexpr static u32 chunk[15626];
	constexpr static u32 block[15625][33];
	public:
	bitvec(){}
	inline void set(int idx,bool b){
		data[idx]=b;
	}
	void build(){
		chunk[0]=0;
		for(int i=0;i<15625;i++){
			block[i][0]=0;
			for(int j=0;j<32;j++){
				block[i][j+1]=block[i][j];
				for(int k=0;k<8;k++){
					block[i][j+1]+=data[i*cw+j*bw+k];
				}
			}
			chunk[i+1]=chunk[i]+block[i][32];
		}
	}
	inline int rank(int idx)const{
		int a=idx/cw,b=idx%cw/bw,c=idx%bw;
		int res=chunk[a]+block[a][b];
		for(int i=1;i<c+1;i++)res+=data[idx-i];
		return res;
	}
	inline int select(int num){
		if (num==0)return 0;
        if (rank(sz)<num)return -1;
        int ok=sz,ng=0;
		while (ok-ng>1) {
			int mid=(ok+ng)/2;
			if (rank(mid)>=num)ok =mid;
			else ng=mid;
		}
		return ok;
	}
};