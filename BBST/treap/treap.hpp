// template<typename T,typename F>
// struct treap{
//     int pri,sz;
//     using np=treap*;
//     np ch[2]={};
//     F rnd;
//     treap(F rnd=F())pri(rnd()),sz(1){

//     }
//     size_t size(np t){
//         return t?t->sz:0;
//     }
//     void update(){
//         sz=size(ch[0])+1+size(ch[1]);
//     }
//     np merge(np t){
//         if(pri>t->pri){
//             ch[1]=ch[1]->merge(t);
//             update();
//             return this;
//         }else{
//             t->ch[0]=t->ch[0]->merge(this);
//             t->update();
//             return t;
//         }
//     }
//     pair<np,np> split(int idx){
//         if(idx<=size(ch[0])){
//             auto [s,t]=split(ch[1]);
//             ch[1]=s;
//             return make_pair(this,t);
//         }else{
//             auto [s,t]=split(ch[0]);
//             ch[0]=t;
//             return make_pair(s,this);
//         }
//     }
// };