struct suffix_automaton{
    struct node;
    using np=node*;
    struct node{
        int len,id;
        map<char,np> ch;
        np link=nullptr;
        node(int len,int id):len(len),id(id){}
    };
    vector<np>list;
    np root=new node(0,0);
    np t=root;
    suffix_automaton(string s){
        list.emplace_back(root);
        for(auto c:s)add(c);
        dfs(root);
        reverse(tsort.begin(),tsort.end());
    }
    void add(char c){
        np cur=new node(t->len+1,list.size());
        list.emplace_back(cur);
        for(;t&&!t->ch.count(c);t=t->link)t->ch[c]=cur;
        if(!t)cur->link=root;
        else{
            np p=t,q=p->ch[c];
            if(q->len==p->len+1)cur->link=q;
            else{
                np clone=new node(*q);
                clone->len=p->len+1;
                clone->id=list.size();
                list.emplace_back(clone);
                for(;p&&p->ch[c]==q;p=p->link)p->ch[c]=clone;
                q->link=cur->link=clone;
            }
        }
        t=cur;
    }
    vector<int>tsort;
    set<np>visited;
    void dfs(np cur){
        if(visited.count(cur))return;
        visited.insert(cur);
        for(auto e:cur->ch)dfs(e.second);
        tsort.emplace_back(cur->id);
    }
    lint size(){
        vector<lint>dp(list.size(),0);
        lint ret=0;
        dp[0]=1;
        for(int i:tsort){
            ret+=dp[i];
            for(auto e:list[i]->ch){
                dp[e.second->id]+=dp[i];
            }
        }
        return ret-1;
    }
};