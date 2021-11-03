//有向グラフ
vec bellmanFord(lint V,lint E,vec from,vec to,vec cost){
    vec diff(V,INF);
    diff[0]=0;
    rep(j,V-1)rep(i,E){
        if(diff[from[i]]!=INF)diff[to[i]]=min(diff[to[i]],diff[from[i]]+cost[i]);
    }
    rep(j,V)rep(i,E){
        if(diff[from[i]]!=INF && diff[from[i]]+cost[i]<diff[to[i]])diff[to[i]]=-INF;
    }
    return diff;
}