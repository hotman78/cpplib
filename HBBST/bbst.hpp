namespace hbbst{
    struct tag_interface{

    };
    struct rule_interface{

    };
    template<typename Key,typename Val,typename TAG,typename Rules,typename Alloc=std::allocator<char>>
    class bbst : public TAG,public Rules{
        bbst(){
            
        }
    };
}