template<typename T,typename F>class segment_tree{
    template<typename Getter>
    class iterator{
        int i;
        Getter getter;
        public:
        iterator(const int& i,const Getter& getter):i(i),getter(getter){}
        inline auto operator*()noexcept{return getter(i);}
        inline constexpr iterator operator++()noexcept{++i;return *this;}
        inline constexpr iterator operator--()noexcept{--i;return *this;}
        inline constexpr iterator operator++(int n)noexcept{++i;return *this;}
        inline constexpr iterator operator--(int n)noexcept{--i;return *this;}
        inline constexpr iterator operator+=(const int& rhs)noexcept{i+=rhs;return *this;}
        inline constexpr iterator operator-=(const int& rhs)noexcept{i-=rhs;return *this;}
        inline constexpr iterator operator+(const int& rhs)const noexcept{return iterator(*this)+=rhs;}
        inline constexpr iterator operator-(const int& rhs)const noexcept{return iterator(*this)-=rhs;}
        inline constexpr bool operator!=(const iterator& rhs)const noexcept{return i!=rhs.i;}
        inline constexpr bool operator==(const iterator& rhs)const noexcept{return i==rhs.i;}
    };
    inline auto make_iterator(const int& i)noexcept{
        static auto getter=[this](const int& i){return get(i,i+1);};
        return iterator<decltype(getter)>(i,getter);
    }
    int n=1,sz;
    vector<T> node;
    T e;
	F f;
	public:
    segment_tree(const vector<T>& v,const T& e):sz(v.size()),e(e){
        while(n<v.size())n<<=1;
        node.resize((n<<1)-1,e);
        rep(i,v.size())node[i+n-1] = v[i];
        rrep(i,n-1)node[i]=f(node[(i<<1)+1],node[(i<<1)+2]);
    }
    segment_tree(const int& sz,const T& e,const F& f):sz(sz),e(e),f(f){
        while(n<sz)n*=2;
        node.resize(n*2-1,e);
    }
    constexpr void update(int x,T val)noexcept{
        x+=(n-1);
        node[x]=f(node[x],val);
        while(x>0){
            x=(x-1)>>1;
            node[x]=f(node[(x<<1)+1],node[(x<<1)+2]);
        }
    }
    T get(int l,int r){
        l+=n;r+=n;
        T res=e;
        while(l<r){
            if(l&1)res=f(res,node[l++-1]);
            if(r&1)res=f(res,node[--r-1]);
            l>>=1;r>>=1;
        }
        return res;
    }
    inline auto begin()noexcept{return make_iterator(0);}
    inline auto end()noexcept{return make_iterator(sz);}
};
template<typename T,typename F>inline auto make_segment(const int& size,const T& e,const F& f){return segment_tree<T,F>(size,e,f);}
template<typename T,typename F>inline auto make_segment(const vector<T>& v,const T& e,const F& f){return segment_tree<T,F>(v,e,f);}
