#pragma once
#include<vector>
#include<algorithm>
#include"bit_vector.hpp"

/**
 * @brief WaveletMatrix(WIP)
 */

class wavelet_matrix{
    using lint=long long;
    const lint MAXLOG=32;
	std::vector<bitvec> matrix;
    lint sz;
	public:
	wavelet_matrix(std::vector<lint> data){
        sz=data.size();
		matrix.resize(MAXLOG);
		for(int i=MAXLOG-1;i>=0;i--){
			for(int j=0;j<(int)data.size();j++){
				matrix[i].set(j,data[j]&(1LL<<i));
			}
			matrix[i].build();
			std::stable_sort(data.begin(),data.end(),[&](auto s,auto t){return (s&(1LL<<i))<(t&(1LL<<i));});
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
