#pragma once
#include<vector>
#include<iostream>
/**
 * @brief グラフテンプレート
 */

using graph=std::vector<std::vector<int>>;
template<typename T>
using graph_w=std::vector<std::vector<std::pair<int,T>>;

graph load_graph(int n,int m){
    graph g(n);
    for(int i=0;i<m;++i){
        int s,t;
        std::cin>>s>>t;
        --s;--t;
        g[s].push_back(t);
        g[t].push_back(s);
    }
}
graph load_digraph(int n,int m){
    graph g(n);
    for(int i=0;i<m;++i){
        int s,t;
        std::cin>>s>>t;
        --s;--t;
        g[s].push_back(t);
    }
}
graph load_graph0(int n,int m){
    graph g(n);
    for(int i=0;i<m;++i){
        int s,t;
        std::cin>>s>>t;
        g[s].push_back(t);
        g[t].push_back(s);
    }
}
graph load_digraph0(int n,int m){
    graph g(n);
    for(int i=0;i<m;++i){
        int s,t;
        std::cin>>s>>t;
        g[s].push_back(t);
    }
}
graph load_tree(int n){
    graph g(n);
    for(int i=0;i<n-1;++i){
        int s,t;
        std::cin>>s>>t;
        --s;--t;
        g[s].push_back(t);
        g[t].push_back(s);
    }
}
graph load_tree1(int n){
    graph g(n);
    for(int i=0;i<n-1;++i){
        int s,t;
        std::cin>>s>>t;
        --s;--t;
        g[s].push_back(t);
        g[t].push_back(s);
    }
}
graph load_treep(int n){
    graph g(n);
    for(int i=0;i<n-1;++i){
        int t;
        std::cin>>t;
        g[i+1].push_back(t);
        g[t].push_back(i+1);
    }
}

template<typename T>
graph_w<T> load_graph_weight(int n,int m){
    graph_w<T> g(n);
    for(int i=0;i<m;++i){
        int s,t;
        T u;
        std::cin>>s>>t>>u;
        --s;--t;
        g[s].emplace_back(t,u);
        g[t].emplace_back(s,u);
    }
}
template<typename T>
graph_w<T> load_digraph_weight(int n,int m){
    graph_w<T> g(n);
    for(int i=0;i<m;++i){
        int s,t;
        T u;
        std::cin>>s>>t>>u;
        --s;--t;
        g[s].emplace_back(t,u);
    }
}
template<typename T>
graph_w<T> load_graph0_weight(int n,int m){
    graph_w<T> g(n);
    for(int i=0;i<m;++i){
        int s,t;
        T u;
        std::cin>>s>>t>>u;
        g[s].emplace_back(t,u);
        g[t].emplace_back(s,u);
    }
}
template<typename T>
graph_w<T> load_digraph0_weight(int n,int m){
    graph_w<T> g(n);
    for(int i=0;i<m;++i){
        int s,t;
        T u;
        std::cin>>s>>t>>u;
        g[s].emplace_back(t,u);
    }
}
template<typename T>
graph_w<T> load_tree_weight(int n){
    graph_w<T> g(n);
    for(int i=0;i<n-1;++i){
        int s,t;
        T u;
        std::cin>>s>>t>>u;
        --s;--t;
        g[s].emplace_back(t,u);
        g[t].emplace_back(s,u);
    }
}
template<typename T>
graph_w<T> load_tree1_weight(int n){
    graph_w<T> g(n);
    for(int i=0;i<n-1;++i){
        int s,t;
        T u;
        std::cin>>s>>t>>u;
        --s;--t;
        g[s].emplace_back(t,u);
        g[t].emplace_back(s,u);
    }
}
template<typename T>
graph_w<T> load_treep_weight(int n){
    graph_w<T> g(n);
    for(int i=0;i<n-1;++i){
        int t;
        T u;
        std::cin>>t>>u;
        g[i+1].emplace_back(t,u);
        g[t].emplace_back(i+1,u);
    }
}