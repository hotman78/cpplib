template<typename T>
struct binary_heap{
	int idx=1;
	struct node{
		int idx;
		T val;
		node(int idx,T val):idx(idx),val(val){}
	};
	using np=node*;
	vector<np>v;
	binary_heap():v(2,0){}
	void __swap(np& s,np& t){
		swap(s,t);
		swap(s->idx,t->idx);
	}
	void up(int k){
		while(k>1&&comp(v[k]->val,v[k/2]->val)){
			__swap(v[k],v[k/2]);
			k/=2;
		}
	}
	void down(int k){
		while(1){
			if(k*2+1<idx&&(comp(v[k*2]->val,v[k]->val)||comp(v[k*2+1]->val,v[k]->val))){
				if(comp(v[k*2]->val,v[k*2+1]->val)){
					__swap(v[k],v[k*2]);
					k=k*2;
				}else{
					__swap(v[k],v[k*2+1]);
					k=k*2+1;
				}
			}else if(k*2<idx&&comp(v[k*2]->val,v[k]->val)){
				__swap(v[k],v[k*2]);
				k=k*2;
			}else{
				break;
			}
		}
	}
	np insert(T val){
		if((int)v.size()<=idx+1)v.resize(v.size()*2,0);
		np res=new node(idx,val);
		v[idx]=res;
		up(idx++);
		return res;
	}
	T top(){
		return v[1]->val;
	}
	void pop(){
		__swap(v[1],v[--idx]);
		down(1);
	}
	int size(){
		return idx-1;
	}
	bool empty(){
		return idx==1;
	}
	void modify(np t,T val){
		t->val=val;
		up(t->idx);
		down(t->idx);
	}
	bool comp(T s,T t){
		return s<t;
	}
};