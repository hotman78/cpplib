struct MF {
    struct edge { lint to, cap, rev; };
    lint V;
    vector<vector<edge>> G;
    vector<lint> itr, level;

    MF(lint V) : V(V) { G.assign(V,vector<edge>()); }

    void add_edge(lint from, lint to, lint cap) {
        G[from].push_back((edge) {to, cap, (lint) G[to].size()});
        G[to].push_back((edge) {from, 0, (lint) G[from].size()-1});
    }

    void bfs(lint s) {
        level.assign(V,-1);
        queue<lint> q;
        level[s] = 0; q.push(s);
        while (!q.empty()) {
            lint v = q.front(); q.pop();
            for(auto &e: G[v]){
                if (e.cap > 0 and level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
    }

    lint dfs(lint v, lint t, lint f) {
        if (v == t) return f;
        for (lint& i = itr[v]; i < (lint) G[v].size(); ++i) {
            edge& e = G[v][i];
            if (e.cap > 0 and level[v] < level[e.to]) {
                lint d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    lint run(lint s, lint t) {
        lint ret = 0, f;
        while (bfs(s), level[t] >= 0) {
            itr.assign(V,0);
            while ((f = dfs(s, t, INF)) > 0) ret += f;
        }
        return ret;
    }
};