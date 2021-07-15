//0が日曜日
auto day_of_week(auto y,auto m,auto d){
    assert(y>=1582);
    if(m<3){y--;m+=12;}
    return (d+26*(m+1)/10+y%100+y%100/4+y/100*5+y/400+6)%7;
}