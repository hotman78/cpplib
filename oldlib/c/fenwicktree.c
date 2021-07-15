typedef struct fenwick_tree{
    int n;
    void* data;
}fenwick_tree;

fenwick_tree* init_fenwick_tree(int n,int data_size){
    fenwick_tree* ret=malloc(sizeof(fenwick_tree));
    ret->n=n;

}

#define 