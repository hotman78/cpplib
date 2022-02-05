vector<int> lex_bfs(graph g,int n,int m){
    list<list<int>>que;
    vector<list<list<int>>::iterator>pos1(n);
    vector<list<int>::iterator>pos2(n);
    list<int>s;
    rep(i,n)s.emplace_back(i);
    que.emplace_back(s);
    rep(i,n)pos1[i]=que.begin();
    {
        int idx=0;
        for(auto i=que.front().begin();i!=que.front().end();++i){
            pos2[idx++]=i;
        }
    }
    vector<int>used(n);
    vector<int>ans;
    while(!que.empty()){
        auto v=que.front().front();
        que.front().pop_front();
        if(que.front().empty())que.pop_front();
        ans.push_back(v);
        used[v]=1;
        for(auto e:g[v]){
            if(used[e])continue;
            if(pos1[e]==que.begin()||prev(pos1[e])->front()!=-1){
                que.insert(pos1[e],list<int>{-1});
            }
            prev(pos1[e])->push_back(e);
            auto tmp1=prev(pos1[e]);
            auto tmp2=prev(tmp1->end());
            pos1[e]->erase(pos2[e]);
            if(pos1[e]->empty())que.erase(pos1[e]);
            pos1[e]=tmp1;
            pos2[e]=tmp2;
        }
        for(auto e:g[v]){
            if(used[e])continue;
            if(pos1[e]->front()==-1){
                pos1[e]->pop_front();
            }
        }
    }
    return ans;
}