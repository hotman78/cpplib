#pragma once

template<typename T>
auto divisor_list(T n){
    vector<T>res;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i)continue;
        res.push_back(i);
        if(i*i!=n)res.push_back(n/i);
    }
    sort(res.begin(),res.end());
    return res;
}