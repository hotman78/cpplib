namespace FastFourierTransform {
    using real = double;

    struct C {
        real x, y;

        C() : x(0), y(0) {}

        C(real x, real y) : x(x), y(y) {}

        inline C operator+(const C &c) const { return C(x + c.x, y + c.y); }

        inline C operator-(const C &c) const { return C(x - c.x, y - c.y); }

        inline C operator*(const C &c) const { return C(x * c.x - y * c.y, x * c.y + y * c.x); }

        inline C conj() const { return C(x, -y); }
    };

    const real PI = acosl(-1);
    int base = 1;
    vector< C > rts = { {0, 0},
                        {1, 0} };
    vector< int > rev = {0, 1};


    void ensure_base(int nbase) {
        if(nbase <= base) return;
        rev.resize(1 << nbase);
        rts.resize(1 << nbase);
        for(int i = 0; i < (1 << nbase); i++) {
        rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
        }
        while(base < nbase) {
        real angle = PI * 2.0 / (1 << (base + 1));
        for(int i = 1 << (base - 1); i < (1 << base); i++) {
            rts[i << 1] = rts[i];
            real angle_i = angle * (2 * i + 1 - (1 << base));
            rts[(i << 1) + 1] = C(cos(angle_i), sin(angle_i));
        }
        ++base;
        }
    }

    void fft(vector< C > &a, int n) {
        assert((n & (n - 1)) == 0);
        int zeros = __builtin_ctz(n);
        ensure_base(zeros);
        int shift = base - zeros;
        for(int i = 0; i < n; i++) {
        if(i < (rev[i] >> shift)) {
            swap(a[i], a[rev[i] >> shift]);
        }
        }
        for(int k = 1; k < n; k <<= 1) {
        for(int i = 0; i < n; i += 2 * k) {
            for(int j = 0; j < k; j++) {
            C z = a[i + j + k] * rts[j + k];
            a[i + j + k] = a[i + j] - z;
            a[i + j] = a[i + j] + z;
            }
        }
        }
    }

    vector< int64_t > multiply(const vector< int > &a, const vector< int > &b) {
        int need = (int) a.size() + (int) b.size() - 1;
        int nbase = 1;
        while((1 << nbase) < need) nbase++;
        ensure_base(nbase);
        int sz = 1 << nbase;
        vector< C > fa(sz);
        for(int i = 0; i < sz; i++) {
        int x = (i < (int) a.size() ? a[i] : 0);
        int y = (i < (int) b.size() ? b[i] : 0);
        fa[i] = C(x, y);
        }
        fft(fa, sz);
        C r(0, -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);
        for(int i = 0; i <= (sz >> 1); i++) {
        int j = (sz - i) & (sz - 1);
        C z = (fa[j] * fa[j] - (fa[i] * fa[i]).conj()) * r;
        fa[j] = (fa[i] * fa[i] - (fa[j] * fa[j]).conj()) * r;
        fa[i] = z;
        }
        for(int i = 0; i < (sz >> 1); i++) {
        C A0 = (fa[i] + fa[i + (sz >> 1)]) * t;
        C A1 = (fa[i] - fa[i + (sz >> 1)]) * t * rts[(sz >> 1) + i];
        fa[i] = A0 + A1 * s;
        }
        fft(fa, sz >> 1);
        vector< int64_t > ret(need);
        for(int i = 0; i < need; i++) {
        ret[i] = llround(i & 1 ? fa[i >> 1].y : fa[i >> 1].x);
        }
        return ret;
    }
};
template<typename T,typename P=vector<T>>
struct ArbitraryModConvolution {
    using real = FastFourierTransform::real;
    using C = FastFourierTransform::C;

    ArbitraryModConvolution() = default;

    P multiply(const P &a, const P &b, int need = -1) {
        if(need == -1) need = a.size() + b.size() - 1;
        int nbase = 0;
        while((1 << nbase) < need) nbase++;
        FastFourierTransform::ensure_base(nbase);
        int sz = 1 << nbase;
        vector< C > fa(sz);
        for(int i = 0; i<(int)a.size(); i++) {
            fa[i] = C(a[i].x & ((1 << 15) - 1), a[i].x >> 15);
        }
        fft(fa, sz);
        vector< C > fb(sz);
        if(a == b) {
            fb = fa;
        } else {
            for(int i = 0; i <(int)b.size(); i++) {
                fb[i] = C(b[i].x & ((1 << 15) - 1), b[i].x >> 15);
            }
            fft(fb, sz);
        }
        real ratio = 0.25 / sz;
        C r2(0, -1), r3(ratio, 0), r4(0, -ratio), r5(0, 1);
        for(int i = 0; i <= (sz >> 1); i++) {
            int j = (sz - i) & (sz - 1);
            C a1 = (fa[i] + fa[j].conj());
            C a2 = (fa[i] - fa[j].conj()) * r2;
            C b1 = (fb[i] + fb[j].conj()) * r3;
            C b2 = (fb[i] - fb[j].conj()) * r4;
            if(i != j) {
                C c1 = (fa[j] + fa[i].conj());
                C c2 = (fa[j] - fa[i].conj()) * r2;
                C d1 = (fb[j] + fb[i].conj()) * r3;
                C d2 = (fb[j] - fb[i].conj()) * r4;
                fa[i] = c1 * d1 + c2 * d2 * r5;
                fb[i] = c1 * d2 + c2 * d1;
            }
            fa[j] = a1 * b1 + a2 * b2 * r5;
            fb[j] = a1 * b2 + a2 * b1;
        }
        fft(fa, sz);
        fft(fb, sz);
        P ret(need);
        for(int i = 0; i < need; i++) {
            int64_t aa = llround(fa[i].x);
            int64_t bb = llround(fb[i].x);
            int64_t cc = llround(fa[i].y);
            aa = T(aa).x, bb = T(bb).x, cc = T(cc).x;
            ret[i] = aa + (bb << 15) + (cc << 30);
        }
        return ret;
    }
};

template< typename T >
struct FPS : vector< T > {
    using vector< T >::vector;
    using P = FPS;

    using MULT = function< P(P, P) >;

    static MULT &get_mult() {
        static MULT mult = nullptr;
        return mult;
    }

    static void set_fft(MULT f) {
        get_mult() = f;
    }

    void shrink() {
        while(this->size() && this->back() == T(0)) this->pop_back();
    }

    P operator+(const P &r) const { return P(*this) += r; }

    P operator+(const T &v) const { return P(*this) += v; }

    P operator-(const P &r) const { return P(*this) -= r; }

    P operator-(const T &v) const { return P(*this) -= v; }

    P operator*(const P &r) const { return P(*this) *= r; }

    P operator*(const T &v) const { return P(*this) *= v; }

    P operator/(const P &r) const { return P(*this) /= r; }

    P operator%(const P &r) const { return P(*this) %= r; }

    P &operator+=(const P &r) {
        if(r.size() > this->size()) this->resize(r.size());
        for(int i = 0; i <(int)r.size(); i++) (*this)[i] += r[i];
        return *this;
    }

    P &operator+=(const T &r) {
        if(this->empty()) this->resize(1);
        (*this)[0] += r;
        return *this;
    }

    P &operator-=(const P &r) {
        if(r.size() > this->size()) this->resize(r.size());
        for(int i = 0; i <(int)r.size(); i++) (*this)[i] -= r[i];
        shrink();
        return *this;
    }

    P &operator-=(const T &r) {
        if(this->empty()) this->resize(1);
        (*this)[0] -= r;
        shrink();
        return *this;
    }

    P &operator*=(const T &v) {
        const int n = (int) this->size();
        for(int k = 0; k < n; k++) (*this)[k] *= v;
        return *this;
    }

    P &operator*=(const P &r) {
        if(this->empty() || r.empty()) {
        this->clear();
        return *this;
        }
        assert(get_mult() != nullptr);
        return *this = get_mult()(*this, r);
    }

    P &operator%=(const P &r) {
        return *this -= *this / r * r;
    }

    P operator-() const {
        P ret(this->size());
        for(int i = 0; i < this->size(); i++) ret[i] = -(*this)[i];
        return ret;
    }

    P &operator/=(const P &r) {
        if(this->size() < r.size()) {
            this->clear();
            return *this;
        }
        int n = this->size() - r.size() + 1;
        return *this = (rev().pre(n) * r.rev().inv(n)).pre(n).rev(n);
    }

    P pre(int sz) const {
        return P(begin(*this), begin(*this) + min((int) this->size(), sz));
    }

    P operator>>(int sz) const {
        if(this->size() <= sz) return {};
        P ret(*this);
        ret.erase(ret.begin(), ret.begin() + sz);
        return ret;
    }

    P operator<<(int sz) const {
        P ret(*this);
        ret.insert(ret.begin(), sz, T(0));
        return ret;
    }

    P rev(int deg = -1) const {
        P ret(*this);
        if(deg != -1) ret.resize(deg, T(0));
        reverse(begin(ret), end(ret));
        return ret;
    }

    P diff() const {
        const int n = (int) this->size();
        P ret(max(0, n - 1));
        for(int i = 1; i < n; i++) ret[i - 1] = (*this)[i] * T(i);
        return ret;
    }

    P integral() const {
        const int n = (int) this->size();
        P ret(n + 1);
        ret[0] = T(0);
        for(int i = 0; i < n; i++) ret[i + 1] = (*this)[i] / T(i + 1);
        return ret;
    }

    // F(0) must not be 0
    P inv(int deg = -1) const {
        assert(((*this)[0]) != T(0));
        const int n = (int) this->size();
        if(deg == -1) deg = n;
        P ret({T(1) / (*this)[0]});
        for(int i = 1; i < deg; i <<= 1) {
            ret = (ret + ret - ret * ret * pre(i << 1)).pre(i << 1);
        }
        return ret.pre(deg);
    }

    // F(0) must be 1
    P log(int deg = -1) const {
        assert((*this)[0] == 1);
        const int n = (int) this->size();
        if(deg == -1) deg = n;
        return (this->diff() * this->inv(deg)).pre(deg - 1).integral();
    }

    P sqrt(int deg = -1) const {
        const int n = (int) this->size();
        if(deg == -1) deg = n;

        if((*this)[0] == T(0)) {
        for(int i = 1; i < n; i++) {
            if((*this)[i] != T(0)) {
                if(i & 1) return {};
                if(deg - i / 2 <= 0) break;
                auto ret = (*this >> i).sqrt(deg - i / 2) << (i / 2);
                if(ret.size() < deg) ret.resize(deg, T(0));
                    return ret;
                }
            }
            return P(deg, 0);
        }
        P ret({T(1)});
        T inv2 = T(1) / T(2);
        for(int i = 1; i < deg; i <<= 1) {
            ret = (ret + pre(i << 1) * ret.inv(i << 1)) * inv2;
        }
        return ret.pre(deg);
    }

    // F(0) must be 0
    P exp(int deg = -1) const {
        assert((*this)[0] == T(0));
        const int n = (int) this->size();
        if(deg == -1) deg = n;
        P ret({T(1)});
        for(int i = 1; i < deg; i <<= 1) {
            ret = (ret * (pre(i << 1) + T(1) - ret.log(i << 1))).pre(i << 1);
        }
        return ret.pre(deg);
    }

    P pow(int64_t k, int deg = -1) const {
        const int n = (int) this->size();
        if(deg == -1) deg = n;
        for(int i = 0; i < n; i++) {
        if((*this)[i] != T(0)) {
            T rev = T(1) / (*this)[i];
            P C(*this * rev);
            P D(n - i);
            for(int j = i; j < n; j++) D[j - i] = C[j];
                D = (D.log() * k).exp() * (*this)[i].pow(k);
                P E(deg);
                if(i * k > deg) return E;
                auto S = i * k;
                for(int j = 0; j + S < deg && j < D.size(); j++) E[j + S] = D[j];
                return E;
            }
        }
        return *this;
    }
    T eval(T x) const {
        T r = 0, w = 1;
        for(auto &v : *this) {
            r += w * v;
            w *= x;
        }
        return r;
    }
};

template< int mod >
struct ModInt {
    int x;

    ModInt() : x(0) {}

    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    ModInt &operator+=(const ModInt &p) {
        if((x += p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt &operator-=(const ModInt &p) {
        if((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt &operator*=(const ModInt &p) {
        x = (int) (1LL * x * p.x % mod);
        return *this;
    }

    ModInt &operator/=(const ModInt &p) {
        *this *= p.inverse();
        return *this;
    }

    ModInt operator-() const { return ModInt(-x); }

    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

    bool operator==(const ModInt &p) const { return x == p.x; }

    bool operator!=(const ModInt &p) const { return x != p.x; }

    ModInt inverse() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while(b > 0) {
        t = a / b;
        swap(a -= t * b, b);
        swap(u -= t * v, v);
        }
        return ModInt(u);
    }

    ModInt pow(int64_t n) const {
        ModInt ret(1), mul(x);
        while(n > 0) {
        if(n & 1) ret *= mul;
        mul *= mul;
        n >>= 1;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const ModInt &p) {
        return os << p.x;
    }

    friend istream &operator>>(istream &is, ModInt &a) {
        int64_t t;
        is >> t;
        a = ModInt< mod >(t);
        return (is);
    }
    static int get_mod() { return mod; }
};
using mint = ModInt<MOD>;
inline mint fact(lint a){return a?fact(a-1)*a:1;}

template< typename Mint,typename P=vector<Mint>>
struct NumberTheoreticTransformFriendlyModInt {
    int base, max_base;
    vector<int> rev;
    vector< Mint > rts;
    Mint root;

    NumberTheoreticTransformFriendlyModInt() : base(1), rev{0, 1}, rts{0, 1} {
        const int mod = Mint::get_mod();
        assert(mod >= 3 && mod % 2 == 1);
        auto tmp = mod - 1;
        max_base = 0;
        while(tmp % 2 == 0) tmp >>= 1, max_base++;
        root = 2;
        while(root.pow((mod - 1) >> 1) == 1) root += 1;
        assert(root.pow(mod - 1) == 1);
        root = root.pow((mod - 1) >> max_base);
    }

    void ensure_base(int nbase) {
        if(nbase <= base) return;
        rev.resize(1 << nbase);
        rts.resize(1 << nbase);
        for(int i = 0; i < (1 << nbase); i++) {
            rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
        }
        assert(nbase <= max_base);
        while(base < nbase) {
        Mint z = root.pow(1 << (max_base - 1 - base));
        for(int i = 1 << (base - 1); i < (1 << base); i++) {
            rts[i << 1] = rts[i];
            rts[(i << 1) + 1] = rts[i] * z;
        }
        ++base;
        }
    }


    void ntt(P&a) {
        const int n = (int) a.size();
        assert((n & (n - 1)) == 0);
        int zeros = __builtin_ctz(n);
        ensure_base(zeros);
        int shift = base - zeros;
        for(int i = 0; i < n; i++) {
            if(i < (rev[i] >> shift)) {
                swap(a[i], a[rev[i] >> shift]);
            }
        }
        for(int k = 1; k < n; k <<= 1) {
        for(int i = 0; i < n; i += 2 * k) {
            for(int j = 0; j < k; j++) {
                Mint z = a[i + j + k] * rts[j + k];
                a[i + j + k] = a[i + j] - z;
                a[i + j] = a[i + j] + z;
            }
        }
        }
    }


    void intt(P &a) {
        const int n = (int) a.size();
        ntt(a);
        reverse(a.begin() + 1, a.end());
        Mint inv_sz = Mint(1) / n;
        for(int i = 0; i < n; i++) a[i] *= inv_sz;
    }

    P multiply(P a,P b) {
        const int need = a.size() + b.size() - 1;
        int nbase = 1;
        while((1 << nbase) < need) nbase++;
        ensure_base(nbase);
        int sz = 1 << nbase;
        a.resize(sz, 0);
        b.resize(sz, 0);
        ntt(a);
        ntt(b);
        Mint inv_sz = Mint(1) / sz;
        for(int i = 0; i < sz; i++) {
            a[i] *= b[i] * inv_sz;
        }
        reverse(a.begin() + 1, a.end());
        ntt(a);
        a.resize(need);
        return a;
    }
};

NumberTheoreticTransformFriendlyModInt<mint,FPS<mint>::P>ntt;
ArbitraryModConvolution<mint,FPS<mint>::P> fft;

__attribute__((constructor))void fft_init(){
    FPS<mint>::set_fft([&](const FPS<mint>::P& s,const FPS<mint>::P& t){
        return ntt.multiply(s,t);
    });
}