template<typename T>
T sparse_det(vector<vector<T>>g){
	int n=g.size();
	T res=T(1);
    vector<bitset<10001>>nonzero_x(n);
    vector<bitset<10001>>nonzero_y(n);
    // vector<pair<int,vector<T>>>rev(n,make_pair(0,vector<T>(n,0)));
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         rev[i].second[j]=g[j][i];
    //     }
    //     rev[i].first=count(rev[i].second.begin(),rev[i].second.end(),T());
    // }
    // int cnt=0;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         if(rev[i].first<rev[j].first){
    //             swap(rev[i],rev[j]);
    //             cnt^=1;
    //         }
    //     }
    // }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         g[j][i]=rev[i].second[j];
    //     }
    // }
    // res*=1-2*cnt;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        if(g[i][j]!=T())nonzero_x[i][j]=1;
        if(g[i][j]!=T())nonzero_y[j][i]=1;
    }
	for(int i=0;i<n;i++){
        if(g[i][i]==0){
            for(int j=i+1;j<n;j++)if(g[j][i]!=T()){
                swap(g[i],g[j]);
                swap(nonzero_x[i],nonzero_x[j]);
                for(int k=0;k<n;k++){
                    if(nonzero_y[k][i]&&!nonzero_y[k][j]){
                        nonzero_y[k][i]=0;
                        nonzero_y[k][j]=1;
                    }else if(nonzero_y[k][j]&&!nonzero_y[k][i]){
                        nonzero_y[k][j]=0;
                        nonzero_y[k][i]=1;
                    }
                }
                res*=-1;
                break;
            }
        }
		if(g[i][i]==0)return T();
		for(int j=i+1;j<n;j++){
			g[j][i]/=g[i][i];
		}
		for(int j=nonzero_y[i]._Find_next(i);j<n;j=nonzero_y[i]._Find_next(j)){
			for(int k=nonzero_x[i]._Find_next(i);k<n;k=nonzero_x[i]._Find_next(k)){
				g[j][k]-=g[j][i]*g[i][k];
                if(g[j][k]!=T())nonzero_y[k][j]=1;
                else nonzero_y[k][j]=0;
                if(g[j][k]!=T())nonzero_x[j][k]=1;
                else nonzero_x[j][k]=0;
			}
		}
	}
	for(int i=0;i<n;i++)res*=g[i][i];
	return res;
}