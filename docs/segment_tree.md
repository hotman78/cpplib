## Operations

モノイド$M$の列$(a_1,a_2,\dots,a_n)$を扱う。
1添加を行う為、単位元を渡す必要はない。
空間計算量$\Theta(n)$

## How to use

- 初期化

```cpp
auto seg=make_segment_tree(vector<T>(n),plus<lint>());//+ monoid
auto seg=make_segment_tree(vector<T>(n),min<lint>);//min monoid
```

- 更新

``seg.apply(s,t)``で$a_s \leftarrow a_s \dot t$と更新

``seg.apply_left(s,t)``で$a_s \leftarrow t \dot a_s$と更新

``seg.change(s,t)``で$a_s \leftarrow	 t$と更新

- 取得

``seg.get(s,t)``で$a_s \dot a_{s+1} \dot \dots \dot a_{t-1}$をmaybe<T>型で取得
