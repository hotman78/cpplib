#pragma once
#include<string>
#include<vector>

std::vector<int> manacher(std::string S){
    int i = 0, j = 0;
    std::string s;
    for(int i=0;i<(int)S.size();i++){
        if(i)s+='$';
        s+=S[i];
    }
    int n=s.size();
    std::vector<int>res(n,0);
    while (i<n) {
        while(i-j>=0&&i+j<n&&s[i-j]==s[i+j])++j;
        res[i]=j;
        int k=1;
        while (i-k >= 0 && k+res[i-k]<j)res[i+k]=res[i-k],++k;
        i+=k;j-=k;
    }
    for(int i=0;i<n;++i){
        if(i%2)res[i]=res[i]/2;
        else res[i]=(res[i]+1)/2;
    }
    return res;
}