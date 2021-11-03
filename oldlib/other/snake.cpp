void snake(auto& r,auto& c,auto h,auto w){
    if(c==0&&r!=0)r--;
    else if((c==w-1&&r%4<2)||(c==((r==h-1)?0:2)&&r%4>1))r++;
    else if(r%4<2)c++;
    else if(r%4>1)c--;
}