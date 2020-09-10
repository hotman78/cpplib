## Operations

モノイド$M$の列$(a_1,a_2,\dots,a_n)$を扱う。
1添加を行う為、単位元を渡す必要はない。
空間計算量$\Theta(n)$

## how to use
```cpp:segment_tree.test.cpp
int main(){
    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    rep(i,n){
        cin>>v[i];
    }
    auto seg=make_segment_tree(v,plus<lint>());
    rep(i,q){
        lint c,s,t;
        cin>>c>>s>>t;
        if(c==0){
            seg.apply(s,t);
        }else{
            cout<<seg.get(s,t).unwrap()<<endl;
        }
    }
}
```
