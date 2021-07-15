template<typename T>
struct min_cost_flow{
    int v;
    constexpr static T inf=1LL<<60;
    T ans=0;
    struct edge{
        int to;
        T cap,cost;
        int rev;
    };
    vector<T>p;
    vector<vector<edge*>>e;//辺のキャパシティ
    vector<T>d;//頂点のキャパシティ
    min_cost_flow(int v):v(v){
        p.resize(v+2);
        e.resize(v+2);
        d.resize(v,0);
    }
    void add_edge(int from,int to,T cap,T cost){
        if(cost>=0){
            e[from].push_back(new edge{to,cap,cost,(int)e[to].size()});
            e[to].push_back(new edge{from,0,-cost,(int)e[from].size()-1});
        }
        else{
            e[to].push_back(new edge{from,cap,-cost,(int)e[from].size()});
            e[from].push_back(new edge{to,0,cost,(int)e[to].size()-1});
            ans+=cap*cost;
            d[from]-=cap;d[to]+=cap;
        }
    }
    T flow(){
        int s=v,t=v+1;
        vector<int>prev(v+2),pree(v+2);
        T f=T();
        for(int i=0;i<v;i++){
            if(d[i]>0)add_edge(s,i,d[i],0),f+=d[i];
            if(d[i]<0)add_edge(i,t,-d[i],0);
        }
        d.resize(v,0);
        while(f){
            priority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>>que;
            que.emplace(0,s);
            vector<T>di(v+2,inf);
            vector<T>prev(v+2),pree(v+2);
            di[s]=0;
            while(!que.empty()){
                T c;int now;
                tie(c,now)=que.top();
                que.pop();
                int idx=0;
                for(auto d:e[now]){
                    if(d->cap&&di[d->to]>c+d->cost+p[now]-p[d->to]){
                        di[d->to]=c+d->cost+p[now]-p[d->to];
                        prev[d->to]=now;
                        pree[d->to]=idx;
                        que.emplace(di[d->to],d->to);
                    }
                    ++idx;
                }
            }
            if(di[t]==inf)return -1;
            for(int i=0;i<v+2;i++)p[i]+=di[i];
            T k=f;
            for(int i=t;i!=s;i=prev[i]){
                k=min(k,e[prev[i]][pree[i]]->cap);
            }
            f-=k;
            ans+=k*p[t];
            for(int i=t;i!=s;i=prev[i]){
                auto pre=e[prev[i]][pree[i]];
                pre->cap-=k;
                e[i][pre->rev]->cap+=k;
            }
        }
        return ans;
    }
    T run(int s,int t,T f){
        d[s]+=f;
        d[t]-=f;
        return flow();
    }
};


// typedef pair<lint,lint>P;
// struct edge{
//     lint to,cap;
//     lint cost;
//     lint rev;
// };

// #define max_v 1919
// lint V=0;
// vector<edge>g[max_v];
// lint h[max_v];
// lint dist[max_v];
// lint prevv[max_v],preve[max_v];
// void add_edge(lint from,lint to,lint cap,lint cost){
// 	V=max(V,from+1);
// 	V=max(V,to+1);
//     g[from].push_back((edge){to,cap,cost,(lint)g[to].size()});
//     g[to].push_back((edge){from,0,-cost,(lint)g[from].size()-1});
// }
// lint min_cost_flow(lint s,lint t,lint f){
//     lint res=0;
//     fill(h,h+V,0);
//     while(f>0){
//         priority_queue<P,vector<P>,greater<P>>que;
//         fill(dist,dist+V,INF);
//         dist[s]=0;
//         que.push(P(0,s));
//         while(!que.empty()){
//             P p=que.top();que.pop();
//             lint v=p.second;
//             if(dist[v]<p.first)continue;
//             for(lint i=0;i<(lint)g[v].size();i++){
//                 edge &e=g[v][i];
//                 if(e.cap>0&&dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){
//                     dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
//                     prevv[e.to]=v;
//                     preve[e.to]=i;
//                     que.push(P(dist[e.to],e.to));
//                 }
//             }
//         }
//         if(dist[t]==INF){
//             return -1;
//         }
//         for(lint v=0;v<V;v++)h[v]+=dist[v];
//         lint d=f;
//         for(lint v=t;v!=s;v=prevv[v]){
//             d=min(d,g[prevv[v]][preve[v]].cap);
//         }
//         f-=d;
//         res+=d*h[t];
//         for(lint v=t;v!=s;v=prevv[v]){
//             edge &e=g[prevv[v]][preve[v]];
//             e.cap-=d;
//             g[v][e.rev].cap+=d;
//         }
//     }
//     return res;
// }