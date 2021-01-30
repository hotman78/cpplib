template<int B=18>
struct num:vector<bool>{
    using vector<bool>::vector;
    num(int x){
        this->resize(B,0);
        rep(i,B){
            (*this)[i]=(x>>(B-1-i))&1;
        }
    }
    int res(){
        int cnt=0;
        rep(i,B){
            cnt+=(*this)[i]<<(B-1-i);
        }
        return cnt;
    }
};