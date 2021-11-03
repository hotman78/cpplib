n=int(input())
d=list(map(int,input().split()))
g=[[]for i in range(n)]
for i in range(n-1):
    s,t=list(map(int,input().split()))
    s-=1
    t-=1
    g[s].append(t)
    g[t].append(s)

class reroot:
    def __init__(self,g):
        self.e=(0,0)
        self.g =g
        self.p_list=[-1]*len(g)
        self.p_checked=[0]*len(g)
        self.table=[map()for i in range(len(g))]
        self.p_table=[self.e]*len(g)
        self.ans=[self.e]*len(g)
        self.dfs1(0,-1)
        for i in range(len(g)):
            self.ans[i]=self.dfs2(i,-1)

    def dfs1(self,n,p):
        self.p_list[n]=p
        tmp1,tmp2=self.e
        tmp=[self.e]*len(self.g[n])
        for i in range(len(self.g[n])):
            t=self.g[n][i]
            if t==p:
                continue
            self.table[n][t]=tmp1
            tmp[i]=self.dfs1(t,n)
            tmp1=self.f(tmp1,tmp[i])
        for i in reversed(range(len(self.g[n]))):
            t=self.g[n][i]
            if t==p:
                continue
            self.table[n][t]=self.f(self.table[n][t],tmp2)
            tmp2=self.f(tmp[i],tmp2)
        self.table[n][p]=tmp1
        return self.fix(self.table[n][p],n,p)
    def dfs2(self,n,p):
        if n==-1:
            return self.e
        if self.p_checked[n]==0:
            self.p_checked[n]=1
            self.p_table[n]=self.dfs2(self.p_list[n],n)
        if p==-1:
            return self.f(self.table[n][self.p_list[n]],self.p_table[n])
        else:
            return self.fix(self.f(self.table[n][p],self.p_table[n]),n,p)
    def query(self):
        return self.ans
    def f(self,s,t):
        return (s[0]+t[0],s[1]+t[1])
    def fix(self,s,n,p):
        return (s[0]+s[1]+d[n],s[1]+d[n])
e=reroot(g).query()
for d in e:
    print(d[0])
