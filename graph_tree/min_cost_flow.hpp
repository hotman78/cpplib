#pragma once
#include<vector>
#include<queue>
#include<cmath>
#include"max_flow.hpp"
#include"../alga/maybe.hpp"

/**
 * @brief 最小費用流(CostScaling)
 */

//Resは答えがlong longの最大値を超える時用
template<typename T,typename Res=T>
struct min_cost_flow{
    int v;
    constexpr static T inf=1LL<<60;
    Res ans=0;
    struct edge{
        int to;
        T cap,cost,st;
        int rev;
        bool is_rev,edge_rev;
        int id;
    };
    max_flow<T> mf;
    std::vector<T>p;
    std::vector<vector<edge*>>e;//辺のキャパシティ
    std::vector<T>d;//頂点のキャパシティ
    std::queue<int>active;
    T eps=1;
    int idx=0;
    std::vector<T>res;
    min_cost_flow(int v):v(v),mf(v+2),p(v,0),e(v),d(v,0){}
    void add_edge(int from,int to,T mn,T mx,T cost){
        res.push_back(0);
        if(from==to){
            if(cost<0)res[idx++]=mx,ans+=mx*cost;
            else res[idx++]=mn,ans+=mn*cost;
            return;
        }
        if(cost>=0){
            e[from].push_back(new edge{to,mx-mn,cost*v,mn,(int)e[to].size(),0,0,idx});
            e[to].push_back(new edge{from,0,-cost*v,mn,(int)e[from].size()-1,1,0,idx++});
            ans+=mn*cost;
            d[from]-=mn;d[to]+=mn;
            eps=max(eps,cost*v*v);
            mf.add_edge(from,to,mx-mn);
        }
        else{
            e[to].push_back(new edge{from,mx-mn,-cost*v,mx,(int)e[from].size(),0,1,idx});
            e[from].push_back(new edge{to,0,cost*v,mx,(int)e[to].size()-1,1,1,idx++});
            ans+=mx*cost;
            d[from]-=mx;d[to]+=mx;
            eps=max(eps,-cost*v*v);
            mf.add_edge(to,from,mx-mn);
        }
    }
    void add_edge(int from,int to,T cap,T cost){
        add_edge(from,to,T(),cap,cost);
    }

    Res flow(){
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
                        auto f=std::min(d[node],ed->cap);
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
            ans+=e[ed->to][ed->rev]->cap*(ed->cost/v);
        }
        return ans;
    }
    bool ok(vector<T>b){
        T tmp=0,tmp2=0;
        for(int i=0;i<v;++i){
            if(d[i]+b[i]>=0){
                mf.add_edge(v,i,d[i]+b[i]);
                tmp2+=d[i]+b[i];
            }
            else{
                mf.add_edge(i,v+1,-(d[i]+b[i]));
                tmp+=-(d[i]+b[i]);
            }
        }
        return tmp==tmp2&&mf.run(v,v+1)==tmp;
    }
    maybe<Res> run(int s,int t,T f){
        d[s]+=f;
        d[t]-=f;
        if(ok(d))return maybe<Res>(flow());
        else maybe<Res>();
    }
    maybe<Res> run(vector<T>b){
        for(int i=0;i<v;++i)d[i]+=b[i];
        if(ok(d))return maybe<Res>(flow());
        else maybe<Res>();
    }
    vector<T> flow_result(){
        for(int i=0;i<v;i++)for(auto ed:e[i]){
            if(ed->is_rev)continue;
            res[ed->id]=ed->st+e[ed->to][ed->rev]->cap*(ed->edge_rev?-1:1);
        }
        return res;
    }
};