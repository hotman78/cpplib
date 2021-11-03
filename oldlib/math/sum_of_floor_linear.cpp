// \sum_{i=0}^{n-1}\floor(a*i+b/c)
lint sum_of_floor_linear(lint a,lint b,lint c,lint n){
    lint tmp=b/c*n+a/c*n*(n-1)/2;
    if(a%c==0){
        return tmp;
    }
    lint next=(c-b%c+a%c-1)/(a%c);
    if(next>=n){
        return tmp;
    }
    a%=c;
    b=b%c+a*next;
    n-=next;
    return tmp+sum_of_floor_linear(c,n*a-((b+a*(n-1))/c*c-b),a,(b+a*(n-1))/c);
}