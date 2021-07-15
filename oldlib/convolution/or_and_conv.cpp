template<typename T>
vector<T> and_conv(vector<T>s,vector<T>t,int n){
	auto zeta=[](vector<T>& f,int n){
		for(int i=0;i<n;++i){
			for(int j=0;j<(1<<n);++j){
				if((j&(1<<i))==0)f[j]+=f[j^(1<<i)];
			}
		}
	};
	auto mebius=[](vector<T>& f,int n){
		for(int i=0;i<n;++i){
			for(int j=0;j<(1<<n);++j){
				if((j&(1<<i))==0)f[j]-=f[j^(1<<i)];
			}
		}
	};
	zeta(s,n);
	zeta(t,n);
	for(int i=0;i<(1<<n);++i)s[i]*=t[i];
	mebius(s,n);
	return s;
}

template<typename T>
vector<T> or_conv(vector<T>s,vector<T>t,int n){
	auto zeta=[](vector<T>& f,int n){
		for(int i=0;i<n;++i){
			for(int j=0;j<(1<<n);++j){
				if((j&(1<<i))==0)f[j^(1<<i)]+=f[j];
			}
		}
	};
	auto mebius=[](vector<T>& f,int n){
		for(int i=0;i<n;++i){
			for(int j=0;j<(1<<n);++j){
				if((j&(1<<i))==0)f[j^(1<<i)]-=f[j];
			}
		}
	};
	zeta(s,n);
	zeta(t,n);
	for(int i=0;i<(1<<n);++i)s[i]*=t[i];
	mebius(s,n);
	return s;
}

template <typename T>
vector<T>xor_convolution(vector<T> s,vector<T> t){
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