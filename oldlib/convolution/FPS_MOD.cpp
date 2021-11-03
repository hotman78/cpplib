//2.5x10^5 
template<typename Mint>
struct _FPS_FFT_MOD{
    template<typename P>
    P operator()(P s,P t){
        vector<double> s1(s.size()),s2(s.size());
        vector<double> t1(t.size()),t2(t.size());
        vector<double> u1(s.size()),u2(t.size());
        for(int i=0;i<(int)s.size();++i){
            s1[i]=s[i].value()&((1<<15)-1);
            s2[i]=s[i].value()>>15;
            u1[i]=s1[i]+s2[i];
        }
        for(int i=0;i<(int)t.size();++i){
            t1[i]=t[i].value()&((1<<16)-1);
            t2[i]=t[i].value()>>15;
            u2[i]=t1[i]+t2[i];
        }
        vector<double> a=mul(s1,t1);
        vector<double> c=mul(s2,t2);
        vector<double> b=mul(u1,u2);
        const int n=s.size()+t.size()-1;
        P res(n);
        Mint x=Mint(2).pow(15);
        for(int i=0;i<n;++i){
            res[i]=(Mint(round(c[i]))*x+Mint(round(b[i])-round(a[i])-round(c[i])))*x+Mint(round(a[i]));
        }
        return res;
    }
    vector<double> mul(vector<double> s,vector<double> t){
        const int n=s.size()+t.size()-1;
        int sz=1;
        while(sz<n)sz<<=1;
        complex<double>* a=new complex<double>[sz]();
        complex<double>* b=new complex<double>[sz];
        decltype(s) res(n);
        for(int i=0;i<(int)s.size();i++)a[i].real(s[i]);
        for(int i=0;i<(int)t.size();i++)a[i].imag(t[i]);
        fft(sz,a);
        for(int i=0;i<sz;i++){
            int j=i==0?0:sz-i;
            b[i]=(a[i]+conj(a[j]))*(a[i]-conj(a[j]))*complex<double>(0,-.25);
        }
        ifft(sz,b);
        for(int i=0;i<n;i++){
            res[i]=b[i].real();
        }
        return res;
    }
    struct complex_t { double Re, Im; };
    __m256d mulpz2(const __m256d ab, const __m256d xy){
        const __m256d aa = _mm256_unpacklo_pd(ab, ab);
        const __m256d bb = _mm256_unpackhi_pd(ab, ab);
        const __m256d yx = _mm256_shuffle_pd(xy, xy, 5);
        return _mm256_addsub_pd(_mm256_mul_pd(aa, xy), _mm256_mul_pd(bb, yx));
    }

    void fft0(int n, int s, bool eo, complex_t* x, complex_t* y){
        const int m = n/2;
        const double theta0 = 2*M_PI/n;

        if (n == 2) {
            complex_t* z = eo ? y : x;
            if (s == 1) {
                double* xd = &x->Re;
                double* zd = &z->Re;
                const __m128d a = _mm_load_pd(xd + 2*0);
                const __m128d b = _mm_load_pd(xd + 2*1);
                _mm_store_pd(zd + 2*0, _mm_add_pd(a, b));
                _mm_store_pd(zd + 2*1, _mm_sub_pd(a, b));
            }
            else {
                for (int q = 0; q < s; q += 2) {
                    double* xd = &(x + q)->Re;
                    double* zd = &(z + q)->Re;
                    const __m256d a = _mm256_load_pd(xd + 2*0);
                    const __m256d b = _mm256_load_pd(xd + 2*s);
                    _mm256_store_pd(zd + 2*0, _mm256_add_pd(a, b));
                    _mm256_store_pd(zd + 2*s, _mm256_sub_pd(a, b));
                }
            }
        }
        else if (n >= 4) {
            if (s == 1) {
                for (int p = 0; p < m; p += 2) {
                    const double cs0 = cos((p+0)*theta0);
                    const double sn0 = sin((p+0)*theta0);
                    const double cs1 = cos((p+1)*theta0);
                    const double sn1 = sin((p+1)*theta0);
                    const __m256d wp = _mm256_setr_pd(cs0, -sn0, cs1, -sn1);
                    double* xd = &(x + p)->Re;
                    double* yd = &(y + 2*p)->Re;
                    const __m256d a = _mm256_load_pd(xd + 2*0);
                    const __m256d b = _mm256_load_pd(xd + 2*m);
                    const __m256d aA =            _mm256_add_pd(a, b);
                    const __m256d bB = mulpz2(wp, _mm256_sub_pd(a, b));
                    const __m256d ab = _mm256_permute2f128_pd(aA, bB, 0x20);
                    const __m256d AB = _mm256_permute2f128_pd(aA, bB, 0x31);
                    _mm256_store_pd(yd + 2*0, ab);
                    _mm256_store_pd(yd + 2*2, AB);
                }
            }
            else {
                for (int p = 0; p < m; p++) {
                    const double cs = cos(p*theta0);
                    const double sn = sin(p*theta0);
                    const __m256d wp = _mm256_setr_pd(cs, -sn, cs, -sn);
                    for (int q = 0; q < s; q += 2) {
                        double* xd = &(x + q)->Re;
                        double* yd = &(y + q)->Re;
                        const __m256d a = _mm256_load_pd(xd + 2*s*(p + 0));
                        const __m256d b = _mm256_load_pd(xd + 2*s*(p + m));
                        _mm256_store_pd(yd + 2*s*(2*p + 0),            _mm256_add_pd(a, b));
                        _mm256_store_pd(yd + 2*s*(2*p + 1), mulpz2(wp, _mm256_sub_pd(a, b)));
                    }
                }
            }
            fft0(n/2, 2*s, !eo, y, x);
        }
    }
    void fft(int N, std::complex<double>* x){
        complex_t* y = (complex_t*) _mm_malloc(N*sizeof(complex_t), 32);
        complex_t* z = (complex_t*) _mm_malloc(N*sizeof(complex_t), 32);
        for (int p = 0; p < N; p++) {
            y[p].Re = x[p].real();
            y[p].Im = x[p].imag();
        }
        fft0(N, 1, 0, y, z);
        for(int k = 0; k < N; k++)x[k] = std::complex<double>(y[k].Re, y[k].Im);
        _mm_free(z);
        _mm_free(y);
    }

    void ifft(int N, std::complex<double>* x){
        complex_t* y = (complex_t*) _mm_malloc(N*sizeof(complex_t), 32);
        complex_t* z = (complex_t*) _mm_malloc(N*sizeof(complex_t), 32);
        for (int p = 0; p < N; p++) {
            y[p].Re =  x[p].real();
            y[p].Im = -x[p].imag();
        }
        fft0(N, 1, 0, y, z);
        for (int k = 0; k < N; k++)x[k] = std::complex<double>(y[k].Re/N, -y[k].Im/N);
        _mm_free(z);
        _mm_free(y);
    }
};
template<typename Mint>using fps=FPS_BASE<Mint,_FPS_FFT_MOD<Mint>>;