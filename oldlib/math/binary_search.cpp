lint bs(lint mn,lint mx,auto func){
    mn--;
    mx++;
	while(mx-mn>1){
		lint mid=(mn+mx)/2;
		if(!func(mid))mx=mid;
		else mn=mid;
	}
    return mn;
}


lint bs(lint ok,lint ng,function<bool(lint)> func) {
    if(ok>ng){ok++;ng--;}
    else {ok--;ng++;}
	while(abs(ok-ng)>1){
		lint mid=(ng+ok)/2;
		if(func(mid))ok=mid;
		else ng=mid;
	}
    return ok;
}