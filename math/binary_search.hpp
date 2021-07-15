#pragma once
#include<functional>
/**
 * @brief 二分探索
 */
template<typename T=long long,typename F>
T bs(T mn,T mx,F func){
    mn--;
    mx++;
	while(mx-mn>1){
		T mid=(mn+mx)/2;
		if(!func(mid))mx=mid;
		else mn=mid;
	}
    return mn;
}