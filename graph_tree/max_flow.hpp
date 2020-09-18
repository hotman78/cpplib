#pragma once
#include<vector>
#include<queue>
#include<cmath>

/**
 * @brief max_flow(Dinic法)
 */

template<typename T>
struct max_flow {
    struct edge { T to, cap, rev; };
    int V;
    vector<vector<edge>> G;
    vector<int> itr, level;

    max_flow(int V) : V(V) { G.assign(V,vector<edge>()); }

    void add_edge(int from, int to, T cap) {
        G[from].push_back((edge) {to, cap, (int) G[to].size()});
        G[to].push_back((edge) {from, 0, (int) G[from].size()-1});
    }

    void bfs(int s) {
        level.assign(V,-1);
        std::queue<int> q;
        level[s] = 0; q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for(auto &e: G[v]){
                if (e.cap > 0 and level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
    }

    int dfs(int v, int t,T f) {
        if (v == t) return f;
        for (int& i = itr[v]; i < (int) G[v].size(); ++i) {
            edge& e = G[v][i];
            if (e.cap > 0 and level[v] < level[e.to]) {
                int d = dfs(e.to, t, std::min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    T run(int s, int t) {
        T ret = 0, f;
        while (bfs(s), level[t] >= 0) {
            itr.assign(V,0);
            while ((f = dfs(s, t, INF)) > 0) ret += f;
        }
        return ret;
    }
};