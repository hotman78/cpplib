## Operations

モノイド$M$の列$(a_1,a_2,\dots,a_n)$を扱う。
1添加を行う為、単位元を渡す必要はない。
空間計算量$\Theta(n)$

## How to use
```cpp
auto seg=make_segment_tree(vector<T>(n),plus<lint>());//+ monoid
auto seg=make_segment_tree(vector<T>(n),min<lint>);//min monoid
```
で初期化

``seg.apply(s,t)``で$a_s \leftarrow a_s \dot t$

``seg.apply_left(s,t)``で$a_s \leftarrow t \dot a_s

``seg.change(s,t)``で$a_s \leftarrow	 t$
``seg.get(s,t)``で$a_s \dot a_{s+1} \dot \dots \dot a_{t-1}$をmaybe<T>型で取得
