#pragma once

template<typename T,typename E>
struct argmin{
    pair<T,E> operator()(const pair<T,E>& s,const pair<T,E>& t){
        return s.second<=t.second?s:t;
    }
};