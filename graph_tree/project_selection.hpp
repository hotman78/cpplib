#include<atcoder/maxflow.hpp>
#include<vector>
#include<map>
template<typename T>
struct project_selection{
    int n;
    atcoder::mf_graph<T>g;
    std::vector<T>a,b;
    std::map<pair<int,int>,T>m;
    project_selection(int n):n(n),g(n+2),a(n),b(n){}
    // i in set1 penalty
    void penalty1(int i,T x){
        assert(i<n);
        a[i]+=x;
    }
    // i in set2 penalty
    void penalty2(int i,T x){
        assert(i<n);
        b[i]+=x;
    }
    // i in set1, j in set2 penalty
    void penalty3(int i,int j,T x){
        assert(i<n);
        assert(j<n);
        m[make_pair(i,j)]+=x;
    }
    T min_penalty(){
        for(int i=0;i<n;++i)g.add_edge(n,i,a[i]);
        for(int i=0;i<n;++i)g.add_edge(i,n+1,b[i]);
        for(auto [s,t]:m)g.add_edge(s.first,s.second,t);
        return g.flow(n,n+1);
    }
};