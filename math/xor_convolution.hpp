template <typename T>
vector<T>xor_conv(vector<T> s,vector<T> t){
    auto fwt=[](vector<T>& f){
        int n = f.size();
        for (int i = 1; i < n; i <<= 1) {
            for (int j = 0; j < n; j++) {
                if ((j & i) == 0) {
                    T x = f[j], y = f[j | i];
                    f[j] = x + y, f[j | i] = x - y;
                }
            }
        }
    };
    auto ifwt=[](vector<T>& f){
        int n = f.size();
        for (int i = 1; i < n; i <<= 1) {
            for (int j = 0; j < n; j++) {
                if ((j & i) == 0) {
                    T x = f[j], y = f[j | i];
                    f[j] = (x + y) / 2, f[j | i] = (x - y) / 2;
                }
            }
        }
    };
    fwt(s);
    fwt(t);
    for(int i=0;i<(int)s.size();i++){
        s[i]*=t[i];
    }
    ifwt(s);
    return s;
}