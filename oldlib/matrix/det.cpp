template<typename T>
T LU_decomposition(vector<vector<T>>g){
	int n=g.size();
	T res=T(1);
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++)if(g[i][i]<g[j][i]){
			swap(g[i],g[j]);
			res*=-1;
		}
		if(g[i][i]==0)return T();
		for(int j=i+1;j<n;j++){
			g[j][i]/=g[i][i];
		}
		for(int j=i+1;j<n;j++){
			for(int k=i+1;k<n;k++){
				g[j][k]-=g[j][i]*g[i][k];
			}
		}
	}
	for(int i=0;i<n;i++)res*=g[i][i];
	return res;
}