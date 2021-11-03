#pragma once
#include<stack>
#include<tuple>
#include<cmath>
#include"../alga/maybe.hpp"
/**
 * @brief SWAG(Queue)
 */

template<typename T,typename F>
class swag{
    std::stack<std::pair<T,T>>front,back;
    F f;
    public:
    swag(F f=F()):f(f){}
    inline int size(){
        return front.size()+back.size();
    }
    inline int empty(){
        return front.empty()&&back.empty();
    }
    void push(T val){
        if(back.empty()){
            back.emplace(val,val);
        }else{
            back.emplace(val,f(back.top().second,val));
        }
    }
    void pop(){
        if(front.empty()){
            while(!back.empty()){
                const T val=back.top().first;
                back.pop();
                if(front.empty())front.emplace(val,val);
                else front.emplace(val,f(val,front.top().second));
            }
        }
        front.pop();
    }
    maybe<T> fold(){
        if(front.empty()&&back.empty())return maybe<T>();
        else if(front.empty()||back.empty())return front.empty()?back.top().second:front.top().second;
        return f(front.top().second,back.top().second);
    }
};