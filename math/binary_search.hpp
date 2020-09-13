#pragma once
#include<functional>

template<typename F>
long long bs(long long mn,long long mx,F func){
    mn--;
    mx++;
	while(mx-mn>1){
		long long mid=(mn+mx)/2;
		if(!func(mid))mx=mid;
		else mn=mid;
	}
    return mn;
}