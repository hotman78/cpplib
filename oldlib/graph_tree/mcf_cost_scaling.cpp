template<typename T>
struct min_cost_flow{
    int v;
    constexpr static T inf=1LL<<60;
    T ans=0;
    struct edge{
        int to;
        T cap,cost;
        int rev;
        bool is_rev;
    };
    vector<T>p;
    vector<vector<edge*>>e;//辺のキャパシティ
    vector<T>d;//頂点のキャパシティ
    queue<int>active;
    T eps=inf;
    min_cost_flow(int v):v(v){
        p.resize(v);
        e.resize(v);
        d.resize(v,0);
    }
    void add_edge(int from,int to,T cap,T cost){
        if(cost>=0){
            e[from].push_back(new edge{to,cap,cost*2,(int)e[to].size(),0});
            e[to].push_back(new edge{from,0,-cost*2,(int)e[from].size()-1,1});
            eps=max(eps,cost*2*v);
        }
        else{
            e[to].push_back(new edge{from,cap,-cost*2,(int)e[from].size(),0});
            e[from].push_back(new edge{to,0,cost*2,(int)e[to].size()-1,1});
            ans+=cap*cost;
            d[from]-=cap;d[to]+=cap;
            eps=max(eps,-cost*2*v);
        }
    }
    T flow(){
        vector<T>p(v,0);
        for(;eps;eps>>=1){
            for(int i=0;i<v;i++){
                for(auto ed:e[i]){
                    if(ed->is_rev)continue;
                    if(ed->cost-p[i]+p[ed->to]<0){
                        T f=ed->cap;
                        ed->cap-=f;
                        d[i]-=f;
                        d[ed->to]+=f;
                        e[ed->to][ed->rev]->cap+=f;
                    }
                    if(ed->cost-p[i]+p[ed->to]>0){
                        T f=-e[ed->to][ed->rev]->cap;
                        ed->cap-=f;
                        d[i]-=f;
                        d[ed->to]+=f;
                        e[ed->to][ed->rev]->cap+=f;
                    }
                }
            }
            for(int i=0;i<v;i++)if(d[i]>0){active.emplace(i);}
            while(!active.empty()){
                int node=active.front();
                active.pop();
                if(d[node]<=0)continue;
                bool b=0;
                for(auto ed:e[node]){
                    if(!d[node])break;
                    if(-eps<=ed->cost-p[node]+p[ed->to]&&ed->cost-p[node]+p[ed->to]<0){
                        auto f=min(d[node],ed->cap);
                        if(!f)continue;
                        ed->cap-=f;
                        d[node]-=f;
                        d[ed->to]+=f;
                        e[ed->to][ed->rev]->cap+=f;
                        if(d[ed->to]>0)active.emplace(ed->to);
                        b=1;
                    }
                }
                if(d[node]>0)active.emplace(node);
                if(!b)p[node]+=eps;
            }
        }
        for(int i=0;i<v;i++)for(auto ed:e[i]){
            if(ed->is_rev)continue;
            ans+=e[ed->to][ed->rev]->cap*ed->cost/2;
        }
        return ans;
    }
    T run(int s,int t,T f){
        d[s]+=f;
        d[t]-=f;
        return flow();
    }
};