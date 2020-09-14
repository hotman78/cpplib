#pragma once
#include<string>
#include<vector>
#include<algorithm>

/**
 * @brief Zアルゴリズム
 */

std::vector<int> Z_algorizm(const std::string& s){
    std::vector<int>res(s.size());
    res[0]=s.size();
    int i=1,j=0;
    while(i<(int)s.size()){
        while(i+j<(int)s.size()&&s[j]==s[i+j])++j;
        res[i]=j;
        if(j==0){++i;continue;}
        int k=1;
        while(i+k<(int)s.size()&&k+res[k]<j)res[i+k]=res[k],++k;
        i+=k;j-=k;
    }
    return res;
}
int find_first(const std::string& s,const std::string& t){
    auto d=Z_algorizm(s+"#"+t);
    auto itr=std::find(d.begin()+s.size(),d.end(),s.size());
    if(itr!=d.end())return itr-d.begin()-s.size();
    else return -1;
}
int count(const std::string& s,const std::string& t){
    auto d=Z_algorizm(s+"#"+t);
    return std::count(d.begin()+s.size(),d.end(),s.size());
}