int64_t counting_primes(int64_t n){
	static bitset<1'000'000'000>b;
	vector<int64_t>p;
	int a=0,c=0;
	for(int64_t i=2;__int128_t(i)*i*i<=__int128_t(n)*n;++i){
		if(b[i])continue;
		p.push_back(i);
		if(__int128_t(i)*i*i<=n)a=p.size();
		if(i*i<=n)c=p.size();
		for(int64_t j=i*2;__int128_t(j)*j*j<=__int128_t(n)*n;j+=i){
			b[j]=1;
		}
	}
	map<pair<int64_t,int64_t>,int64_t>memo;
	auto pi=[&](int64_t x){
		return upper_bound(p.begin(),p.end(),x)-p.begin();
	};
	auto phi=[&](auto f,int64_t x,int64_t a){
		if(a==1)return (x+1)/2;
		if(memo.count(make_pair(x,a)))return memo[make_pair(x,a)];
		if(x<p[a-1]*p[a-1])return memo[make_pair(x,a)]=pi(x)-a+1;
		return memo[make_pair(x,a)]=f(f,x,a-1)-f(f,x/p[a-1],a-1);
	};
	auto p2=[&](int64_t x,int64_t a){
		int64_t ans=0;
		for(int i=a+1;i<=(int)c;++i){
			ans+=pi(x/p[i-1])-(i-1);
		}
		return ans;
	};
	return a+phi(phi,n,a)-1-p2(n,a);
}