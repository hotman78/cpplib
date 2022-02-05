template<typename F,typename G>
void make_case(string name,lint num,F in,G out){
    for(int i=0;i<num;++i){
        string s=to_string(i);
        while(s.size()<2)s="0"+s;
        ofstream input("in/"+name+s+".txt");
        in(input,i);
        input<<flush;
        ifstream input2("in/"+name+s+".txt");
        ofstream output("out/"+name+s+".txt");
        out(input2,output);
        output<<flush;
    }
}

void reset_case(){
    namespace fs = std::filesystem;
    fs::remove_all("in");
    fs::remove_all("out");
    fs::create_directory("in");
    fs::create_directory("out");
}