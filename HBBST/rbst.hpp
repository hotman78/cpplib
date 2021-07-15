#include<memory>

#define TEMPLATE template<typename Key,typename Val,typename Tag,typename Rules,typename Alloc>
#define CLASS_NAME rbst_set
#define CLASS_TYPE rbst_set<Key,Val,Tag,Rules,Alloc>

namespace hbbst{
    namespace details{
        TEMPLATE
        struct rbst_set{
            Rules rule;
            rbst_set():rule(Rules()){}
            struct node{};
            inline iterator insert(iterator);
            inline iterator erase(iterator);
            inline node merge (node);
        };
        TEMPLATE
        typename CLASS_TYPE::node CLASS_TYPE::insert(typename CLASS_TYPE::node itr){
            rule.Cmp(node )
        }
    }
}