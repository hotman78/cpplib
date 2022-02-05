#pragma once
#include<functional>
#include<vector>

/**
 * @brief DisjointSparseTable
 */

template<typename T,typename F=std::plus<T>>
class disjoint_sparse_table{
	T** table;
	T* data;
	int n=1,cnt=0;
	public:
	F f;
	disjoint_sparse_table(const std::vector<T>& v,F f):f(f){init(v);}
	disjoint_sparse_table(const std::vector<T>& v):f(F()){init(v);}
	void init(const std::vector<T>& v){
		while(n<(int)v.size())n<<=1,cnt++;
		table=new T*[cnt];
		for(int i=0;i<cnt;i++){
			table[i]=new T[n]();
		}
		data =new T[n];
		for(int i=0;i<(int)v.size();i++)data[i]=v[i];
		for(int i=0;i<cnt;i++){
			for(int j=0;j<(n>>(i+1));j++){
				const int mid=(j<<(i+1))+(1<<i);
				for(int k=0;k<(1<<i);k++){
					if(k==0){
						if(0<=mid-1&&mid-1<(int)v.size())table[i][mid-1]=v[mid-1];
						if(0<=mid&&mid<(int)v.size())table[i][mid]=v[mid];
					}
					else{
						if(0<=mid-1-k&&mid-1-k<(int)v.size())table[i][mid-1-k]=f(table[i][mid-k],v[mid-1-k]);
						if(0<=mid+k&&mid+k<(int)v.size())table[i][mid+k]=f(table[i][mid+k-1],v[mid+k]);
					}
				}
			}
		}
	}
	T get(int l,int r){
		if(l==r)return T();
		r--;
		if(l==r)return data[l];
		const int t=31-__builtin_clz((int)(l^r));
		return f(table[t][l],table[t][r]);
	}
};