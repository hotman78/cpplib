/**
 * @brief 重心分解
 * 構築:O(NlogN)
 * get_root()           :出来上がった木の根を返す O(1)
 * operator[](int i)    :出来上がった木の子を返す
 * get_euler_tour(int i):出来上がった木のdfs順を返す
 * 
 * ・全てのパスについて調べる方法
 * dfs順を取得してループを回し、
 * パス上にあり、dfs順で最小となる頂点がiであるようなパスをなめていく
 * 
 * verified with    :https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
 * submission       :https://judge.yosupo.jp/submission/28303
 */

class centroid_decomposition{
    using graph=vector<vector<int>>;
    graph g;
    vector<int>used;
    vector<int>v;
    graph ch;
    int s;
    int dfs(int n,int p,int sz,int root){
        if(used[n])return 0;
        bool b=1;
        int res=1;
        for(auto e:g[n]){
            if(p==e)continue;
            auto t=dfs(e,n,sz,root);
            res+=t;
            if(t>sz/2)b=0;
        }
        if(!b||sz-res>sz/2)return res;
        if(root!=-1)ch[root].push_back(n);
        else s=n;
        v.push_back(n);
        used[n]=1;
        for(auto e:g[n]){
            dfs(e,n,dfs(e,n,g.size()*2,n),n);
        }
        return g.size()*2;
    }
    public:
    centroid_decomposition(const graph&g):g(g){
        int n=g.size();
        used.resize(n);
        ch.resize(n);
        dfs(0,-1,n,-1);
    }

    int get_root(){return s;}
    vector<int> operator[](int i){return ch[i];}
    vector<int> get_euler_tour(){return v;}
};