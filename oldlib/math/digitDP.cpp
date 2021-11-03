//注意 map使ってるので遅い
template<typename E,typename... T>
E digitDP(const string& s,int mx_num=9,int digit=0,bool b=0,T... state){
	tuple<T...> args(state...);
	static map<tuple<int,bool,T...>,E>memo;
	if(digit==(int)s.size()){
		//ここに終了時処理
		return get<0>(args)?0:1;
	}
	if(memo.count(make_tuple(digit,b,state...)))return memo[make_tuple(digit,b,state...)];
	const int mx=b?mx_num:s[digit]-'0';
	E res=E();
	for(int i=0;i<=mx;i++){
		//遷移先を書く
		res+=digitDP<E,T...>(s,mx_num,digit+1,b|(i<mx),(get<0>(args)+i)%get<1>(args),get<1>(args));
	}
	return memo[make_tuple(digit,b,state...)]=res;
}