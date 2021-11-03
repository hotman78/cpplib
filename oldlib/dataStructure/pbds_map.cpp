template<typename Node_CItr, typename Node_Itr, typename Cmp_Fn, typename _Alloc>
struct range_sum_node_update{
    virtual Node_CItr node_begin()const=0;
    virtual Node_CItr node_end()const=0;
    struct node{
        mutable int l=0,r=0,sum=0,val=0,key=0,sz=1;
    };
    typedef node metadata_type;
    inline void operator()(Node_Itr itr,Node_CItr null){
        auto lt=itr.get_l_child();
        auto rt=itr.get_r_child();
        auto& t=itr.get_metadata();
        const auto& l=lt.get_metadata();
        const auto& r=rt.get_metadata();
        t.sz=(lt==null?0:l.sz)+1+(rt==null?0:r.sz);
        t.key=(*itr)->first;
        t.val=(*itr)->second;
        t.l=(lt==null?t.key:l.l);
        t.r=(rt==null?t.key:r.r);
        t.sum=0;
        if(lt!=null)t.sum+=l.sum;
        t.sum+=t.val;
        if(rt!=null)t.sum+=r.sum;
    }
    constexpr static int e=0;
    int sum(int l,int r,Node_CItr itr){
        if(itr==node_end())return e;
        auto t=itr.get_metadata();
        auto lt=itr.get_l_child();
        auto rt=itr.get_r_child();
        if(r<=t.l||t.r<=l)return e;
        if(l<=t.l&&t.r<=r)return t.sum;
        return sum(l,r,lt)+(l<=t.key&&t.key<r?t.val:e)+sum(l,r,rt);
    }
    int sum(int l,int r){return sum(l,r,node_begin());}
};
template<typename T>using rb_set=__gnu_pbds::tree<T,T,less<T>,__gnu_pbds::rb_tree_tag,range_sum_node_update>;
