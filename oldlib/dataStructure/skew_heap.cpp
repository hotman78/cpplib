template<typename T>
class skew_heap{
	struct node;
	using np=node*;
	struct node{
		np ch[2]={nullptr,nullptr};
		T val;
		node(T val):val(val){}
	};
	np root=nullptr;
	np meld(np a,np b) {
		if(!a||!b)return a?a:b;
		if(a->val>b->val)swap(a,b);
		a->ch[1]=meld(a->ch[1],b);
		swap(a->ch[0],a->ch[1]);
		return a;
	}
	public:
	skew_heap(np root=nullptr):root(root){}
    bool empty(){return !root;}
	void insert(T val){root=meld(root,new node(val));}
	void pop(){root=meld(root->ch[0],root->ch[1]);}
	T top(){return root->val;}
	np meld(skew_heap s,skew_heap t){return new skew_heap(meld(s->root,t->root));}
};