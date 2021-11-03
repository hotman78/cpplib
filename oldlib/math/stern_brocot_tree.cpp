//分母がm以下のk番目の数
lint m;
void bs(lint a,lint b,lint c,lint d,lint& k){
    if(b+d>m)return;
    bs(a,b,a+c,b+d,k);
    k--;
    if(k==0){
        cout<<a+c<<" "<<b+d<<endl;
        exit(0);
    }
    bs(a+c,b+d,c,d,k); 
}