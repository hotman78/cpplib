double timer(auto f){
    auto s=chrono::system_clock::now();
    f();
    auto e=chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(e-s).count(); 
}