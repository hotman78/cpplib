// template <class Head,class... Args>
// std::ostream& output(std::ostream& out,const Head& head,const Args&... args){
//     out>>head;
//     return output(head,args...);
// }
// template <class Head>
// std::ostream& output(std::ostream& out,const Head& head){
//     out>>head;
//     return out;
// }

template<typename T,typename E>
std::ostream& operator<<(std::ostream& out,std::pair<T,E>v){
    out<<"("<<v.first<<","<<v.second<<")";return out;
}

// template <class... Args>
// ostream& operator<<(ostream& out,std::tuple<Args...>v){
//     std::apply(output,v);
//     return out;
// }