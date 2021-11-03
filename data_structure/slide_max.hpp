struct slide_max{
    my_deque<pair<unsigned,int>>deq;
    int l=0,r=0;
    bool empty(){
        return l==r;
    }
    int size(){
        return r-l;
    }
    void push(unsigned x){
        while(!deq.empty()&&deq.back().first<=x){
            deq.pop_back();
        }
        deq.push_back(make_pair(x,r++));
    }
    void pop(){
        if(!deq.empty()&&deq.front().second==l){
            deq.pop_front();
        }
        l++;
    }
    unsigned fold(){
        return deq.front().first;
    }
};