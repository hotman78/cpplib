struct Tree{
    n:usize,
    g:Vec<Vec<usize>>,
}
impl Tree{
    fn new(n:usize)->Self{
        Self{
            n:n,
            g:vec![Vec::new();n],
        }
    }
    fn add_edge(&mut self,s:usize,t:usize){
        self.g[s].push(t);
        self.g[t].push(s);
    }
    fn dfs<F:FnMut(usize,usize)>(&mut self,n:usize,p:usize,f:&mut F){
        for e in mem::take(&mut self.g[n]){
            if e==p{
                continue;
            }
            f(e,n);
            self.dfs(e,n,f);
        }
    }
}