// template<typename T,typename E>
// class hash_map{
//     T* table;
//     E* value;
//     int* used;
//     int sz=0;
//     int mx=1;
//     public:
//     hash_map(){
//         table=new T[1]();
//         value=new E[1]();
//         used=new int[1]();
//         for(int i=0;i<mx;i++)used[i]=-1;
//     }
//     void resize(int sz){
//         T* old_table=new T[sz]();
//         E* old_value=new E[sz]();
//         int* old_used=new int[sz]();
//         for(int i=0;i<sz;++i)old_used[i]=-1;
//         swap(table,old_table);
//         swap(value,old_value);
//         swap(used,old_used);
//         this->sz=0;
//         mx=sz;
//         for(int i=0;i<mx>>2;++i){
//             if(old_used[i]!=-1){
//                 emplace(old_table[i],old_value[i]);
//             }
//         }
//     }
//     void emplace(T key,E val)noexcept{
//         if(sz==mx)resize(sz<<2);
//         ++sz;
//         int hash=hashing(key);
//         for(int i=hash;;i=(i==mx-1?0:i+1)){
//             if(used[i]!=-1){
//                 if(abs(used[i]-i)>abs(hash-i)){
//                     swap(used[i],hash);
//                     swap(table[i],key);
//                     swap(value[i],val);
//                 }
//             }else{
//                 used[i]=hash;
//                 table[i]=key;
//                 value[i]=val;
//                 return;
//             }
//         }
//     }
    
//     E& operator[](T key){
//         const int hash=hashing(key);
//         for(int i=hash;;i=(i==mx-1?0:i+1)){
//             if(used[i]==-1){
//                 used[i]=hash;
//                 table[i]=key;
//                 value[i]=E();
//                 return value[i];
//             }else if(key==table[i]){
//                 return value[i];   
//             }
//         }
//     }
//     bool count(T key){
//         const int hash=hashing(key);
//         for(int i=hash;;i=(i==mx-1?0:i+1)){
//             if(used[i]==-1){
//                 return 0;
//             }else if(key==table[i]){
//                 return 1;   
//             }
//         }
//     }
//     bool erase(T key)noexcept{
//         const int hash=hashing(key);
//         for(int i=hash;;i=(i==mx-1?0:i+1)){
//             if(used[i]==-1){
//                 return 0;
//             }else if(key==table[i]){
//                 used[i]=-1;
//                 table[i]=T();
//                 value[i]=E();
//                 --sz;
//                 return 1;
//             }
//         }
//     }
//     inline int hashing(const T& val){
//         return val&(mx-1);
//     }
// };