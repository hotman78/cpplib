#pragma once
template<typename T>
struct sum_of_sum{
    using M=sum_of_sum<T>;
    T cnt,sum;
    sum_of_sum(T cnt=0,T sum=0):cnt(cnt),sum(sum){}
    M& operator+=(const M& x){
        return *this=M(cnt+x.cnt,sum+x.sum);
    }
    M operator+(const M& x){
        return M(*this)+=x;
    }
    M& operator*=(const M& x){
        return *this=M(cnt*x.cnt,sum*x.cnt+cnt*x.sum);
    }
    M operator*(const M& x){
        return M(*this)*=x;
    }
    friend ostream& operator<<(ostream& ouf,const M& x){
        ouf<<"("<<x.cnt<<","<<x.sum<<")";
        return ouf;
    }
};
