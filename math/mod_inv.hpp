#pragma once
long long mod_inv(x,m){return x==1?1:m+(-m*mod_inv(m%a,a)+1);}