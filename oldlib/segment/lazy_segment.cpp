// template<typename T,typename E>
// class lazy_segment_tree{
//     template<typename Getter>
//     class iterator{
//         int i;
//         Getter getter;
//         public:
//         iterator(const int& i,const Getter& getter):i(i),getter(getter){}
//         inline auto operator*()noexcept{return getter(i);}
//         inline constexpr iterator operator++()noexcept{++i;return *this;}
//         inline constexpr iterator operator--()noexcept{--i;return *this;}
//         inline constexpr iterator operator++(int n)noexcept{++i;return *this;}
//         inline constexpr iterator operator--(int n)noexcept{--i;return *this;}
//         inline constexpr iterator operator+=(const int& rhs)noexcept{i+=rhs;return *this;}
//         inline constexpr iterator operator-=(const int& rhs)noexcept{i-=rhs;return *this;}
//         inline constexpr iterator operator+(const int& rhs)const noexcept{return iterator(*this)+=rhs;}
//         inline constexpr iterator operator-(const int& rhs)const noexcept{return iterator(*this)-=rhs;}
//         inline constexpr bool operator!=(const iterator& rhs)const noexcept{return i!=rhs.i;}
//         inline constexpr bool operator==(const iterator& rhs)const noexcept{return i==rhs.i;}
//     };
//     inline auto make_iterator(const int& i)noexcept{
//         static auto getter=[this](const int& i){return get(i,i+1);};
//         return iterator<decltype(getter)>(i,getter);
//     }
//     int n=1,sz;
//     T* node;
//     E* lazy;
//     int ids[64];
//     int idx;
//     T et;E ee;
//     void eval(const auto& t)noexcept{
//         if(lazy[t]==ee)return;
//         node[t]=h(node[t],lazy[t],n>>(int)(log2(t+1)));
//         if(t<n-1){
//             lazy[(t<<1)+1]=g(lazy[(t<<1)+1],lazy[t]);
//             lazy[(t<<1)+2]=g(lazy[(t<<1)+2],lazy[t]);
//         }
//         lazy[t]=ee;
//     }
//     void get_eval(auto l,auto r)noexcept{
//         l+=n;r+=n;
//         const int lm=(l/(l&-l))>>1;
//         const int rm=(r/(r&-r))>>1;
//         idx=0;
//         while(r>l){
//             if(r<=rm&&r)ids[idx++]=r-1;
//             if(l<=lm&&l)ids[idx++]=l-1;
//             l>>=1;r>>=1;
//         }
//         while(l){
//             ids[idx++]=l-1;
//             l>>=1;
//         }
//     }
// 	public:
//     lazy_segment_tree(const vector<T>& v,const T& et,const E& ee):sz(v.size()),et(et),ee(ee){
//         while(n<v.size())n<<=1;
//         node=new T[(n<<1)-1];
//         lazy=new E[(n<<1)-1];
//         for(int i=(int)v.size()+n-1;i<(n<<1)-1;i++)node[i]=et;
//         for(int i=0;i<(n<<1)-1;i++)lazy[i]=ee;
//         for(int i=0;i<(int)v.size();i++)node[i+n-1]=v[i];
//         for(int i=n-2;i>=0;i--)node[i]=f(node[(i<<1)+1],node[(i<<1)+2]);
//     }
//     lazy_segment_tree(const auto& sz,const T& et,const E& ee):sz(sz),et(et),ee(ee){
//         while(n<sz)n<<=1;
//         node=new T[(n<<1)-1];
//         lazy=new E[(n<<1)-1];
//         for(int i=0;i<(n<<1)-1;i++)node[i]=et;
//         for(int i=0;i<(n<<1)-1;i++)lazy[i]=ee;
//     }
//     constexpr void update(auto l,auto r,E val)noexcept{
//         get_eval(l,r);
//         for(int i=idx-1;i>=0;i--)eval(ids[i]);
//         l+=n;r+=n;
//         while(l<r){
//             if(l&1){lazy[l-1]=g(lazy[l-1],val);eval(l-1);++l;}
//             if(r&1){--r;lazy[r-1]=g(lazy[r-1],val);eval(r-1);}
//             l>>=1;r>>=1;
//         }
//         for(int i=0;i<idx;i++){
//             eval((ids[i]<<1)+1);
//             eval((ids[i]<<1)+2);
//             node[ids[i]]=f(node[(ids[i]<<1)+1],node[(ids[i]<<1)+2]);
//         }
//     }
//     T get(auto l,auto r){
//         get_eval(l,r);
//         for(int i=idx-1;i>=0;i--)eval(ids[i]);
//         l+=n;r+=n;
//         T res=et;
//         while(l<r){
//             if(l&1){eval(l-1);res=f(res,node[l-1]);l++;}
//             if(r&1){--r;eval(r-1);res=f(res,node[r-1]);}
//             l>>=1;r>>=1;
//         }
//         return res;
//     }
//     inline auto begin()noexcept{return make_iterator(0);}
//     inline auto end()noexcept{return make_iterator(sz);}
// 	private:
// 	T f(const T& a,const T& b){
// 		return update(a,b);
// 	}
// 	T h(const T& a,const E& b,const auto& sz){
// 		return update(a,b);
// 	}
// 	E g(const E& a,const E& b){
// 		return update(a,b);
// 	}
// 	auto update(auto a,auto b){return b==ee?a:b;}
// };

// template<typename T,typename E,typename F,typename G,typename H>class lazy_segment_tree{
//     template<typename Getter>
//     class iterator{
//         int i;
//         Getter getter;
//         public:
//         iterator(const int& i,const Getter& getter):i(i),getter(getter){}
//         inline auto operator*()noexcept{return getter(i);}
//         inline constexpr iterator operator++()noexcept{++i;return *this;}
//         inline constexpr iterator operator--()noexcept{--i;return *this;}
//         inline constexpr iterator operator++(int n)noexcept{++i;return *this;}
//         inline constexpr iterator operator--(int n)noexcept{--i;return *this;}
//         inline constexpr iterator operator+=(const int& rhs)noexcept{i+=rhs;return *this;}
//         inline constexpr iterator operator-=(const int& rhs)noexcept{i-=rhs;return *this;}
//         inline constexpr iterator operator+(const int& rhs)const noexcept{return iterator(*this)+=rhs;}
//         inline constexpr iterator operator-(const int& rhs)const noexcept{return iterator(*this)-=rhs;}
//         inline constexpr bool operator!=(const iterator& rhs)const noexcept{return i!=rhs.i;}
//         inline constexpr bool operator==(const iterator& rhs)const noexcept{return i==rhs.i;}
//     };
//     inline auto make_iterator(const int& i)noexcept{
//         static auto getter=[this](const int& i){return get(i,i+1);};
//         return iterator<decltype(getter)>(i,getter);
//     }
//     int n=1,sz;
//     T* node;
//     E* lazy;
//     int ids[64];
//     int idx;
//     T et;E ee;F f;G g;H h;
//     void eval(const int& t)noexcept{
//         if(lazy[t]==ee)return;
//         node[t]=h(node[t],lazy[t],n>>(int)(log2(t+1)));
//         if(t<n-1){
//             lazy[(t<<1)+1]=g(lazy[(t<<1)+1],lazy[t]);
//             lazy[(t<<1)+2]=g(lazy[(t<<1)+2],lazy[t]);
//         }
//         lazy[t]=ee;
//     }
//     void get_eval(int l,int r)noexcept{
//         l+=n;r+=n;
//         const int lm=(l/(l&-l))>>1;
//         const int rm=(r/(r&-r))>>1;
//         idx=0;
//         while(r>l){
//             if(r<=rm&&r)ids[idx++]=r-1;
//             if(l<=lm&&l)ids[idx++]=l-1;
//             l>>=1;r>>=1;
//         }
//         while(l){
//             ids[idx++]=l-1;
//             l>>=1;
//         }
//     }
// 	public:
//     lazy_segment_tree(const vector<T>& v,const T& et,const E& ee,const F& f,const G& g,const H& h):sz(v.size()),et(et),ee(ee),f(f),g(g),h(h){
//         while(n<v.size())n<<=1;
//         node=new T[(n<<1)-1];
//         lazy=new E[(n<<1)-1];
//         for(int i=(int)v.size()+n-1;i<(n<<1)-1;i++)node[i]=et;
//         for(int i=0;i<(n<<1)-1;i++)lazy[i]=ee;
//         for(int i=0;i<(int)v.size();i++)node[i+n-1]=v[i];
//         for(int i=n;i>=0;i--)node[i]=f(node[(i<<1)+1],node[(i<<1)+2]);
//     }
//     lazy_segment_tree(const int& sz,const T& et,const E& ee,const F& f,const G& g,const H& h):sz(sz),et(et),ee(ee),f(f),g(g),h(h){
//         while(n<sz)n<<=1;
//         node=new T[(n<<1)-1];
//         lazy=new E[(n<<1)-1];
//         for(int i=0;i<(n<<1)-1;i++)node[i]=et;
//         for(int i=0;i<(n<<1)-1;i++)lazy[i]=ee;
//     }
//     constexpr void update(int l,int r,E val)noexcept{
//         get_eval(l,r);
//         for(int i=idx-1;i>=0;i--)eval(ids[i]);
//         l+=n;r+=n;
//         while(l<r){
//             if(l&1){lazy[l-1]=g(lazy[l-1],val);eval(l-1);++l;}
//             if(r&1){--r;lazy[r-1]=g(lazy[r-1],val);eval(r-1);}
//             l>>=1;r>>=1;
//         }
//         for(int i=0;i<idx;i++){
//             eval((ids[i]<<1)+1);
//             eval((ids[i]<<1)+2);
//             node[ids[i]]=f(node[(ids[i]<<1)+1],node[(ids[i]<<1)+2]);
//         }
//     }
//     T get(int l,int r){
//         get_eval(l,r);
//         for(int i=idx-1;i>=0;i--)eval(ids[i]);
//         l+=n;r+=n;
//         T res=et;
//         while(l<r){
//             if(l&1){eval(l-1);res=f(res,node[l-1]);l++;}
//             if(r&1){--r;eval(r-1);res=f(res,node[r-1]);}
//             l>>=1;r>>=1;
//         }
//         return res;
//     }
//     inline auto begin()noexcept{return make_iterator(0);}
//     inline auto end()noexcept{return make_iterator(sz);}
// };
// template<typename T,typename E,typename F,typename G,typename H>inline auto make_segment(const int& size,const T& et,const E& ee,const F& f,const G& g,const H& h){
//     return lazy_segment_tree<T,E,F,G,H>(size,et,ee,f,g,h);
// }
// template<typename T,typename E,typename F,typename G,typename H>inline auto make_segment(const vector<T>& v,const T& et,const E& ee,const F& f,const G& g,const H& h){
//     return lazy_segment_tree<T,E,F,G,H>(v,et,ee,f,g,h);
// }