template<typename T>
struct fpsd:FPS_BASE<T,fpsd<T>>{
    using FPS_BASE<T,fpsd<T>>::FPS_BASE;
    using P=fpsd<T>;
    struct complex_t{
		T re,im;
		using C=complex_t;
		complex_t(T x=0,T y=0):re(x),im(y){}
		inline C operator +(C x)const noexcept{return C(*this)+=x;}
		inline C operator -(C x)const noexcept{return C(*this)-=x;}
		inline C operator *(C x)const noexcept{return C(*this)*=x;}
		inline C operator /(C x)const noexcept{return C(*this)/=x;}
		inline C operator +=(C x)noexcept{
			re+=x.re;im+=x.im;
			return *this;
		}
		inline C operator -=(C x)noexcept{
			re-=x.re;im-=x.im;
			return *this;
		}
		inline C operator *=(C x)noexcept{
			return *this=complex_t{re*x.re-im*x.im,re*x.im+im*x.re};
		}
		inline C operator /=(C x)noexcept{
			return *this*=x.inv();
		}
		inline C inv()noexcept{
			return C{re/(re*re+im+im),-im/(re*re+im+im)};
		}
		inline T real()noexcept{
			return re;
		}
		inline T imag()noexcept{
			return im;
		}
	};
	complex_t conj(complex_t x){
		return complex_t{x.re,-x.im};
	}
	using real=T;
	using C=complex_t;
	P mul(P s,P t){
		const int n=s.size()+t.size()-1;
		int sz=1,h=0;
		while(sz<n)sz<<=1,h++;
		C* a=new C[sz]();
		for(int i=0;i<(int)s.size();i++)a[i].re=s[i];
		for(int i=0;i<(int)t.size();i++)a[i].im=t[i];
		a=fft(a,h);
		P res(n);
		for(int i=0;i<n;i++)res[i]=a[i].real();
		return res;
	}
	C* fft(C* a,int h){
		const int n=1<<h;
		C* b=new C[n]();
		for(short i=0;i<h;++i){
			const int s=1<<i,t=1<<(h-i-1);
			if(i*2<h-1){
				for(int k=0;k<s;++k){
					const C beta=C(cosl(2*M_PIl*t*k/n),sinl(2*M_PIl*t*k/n));
					const int idx1=k*t,idx2=k*2*t,idx3=(k+s)*t;
					for(int j=0;j<t;++j){
						b[idx1+j]=a[idx2+j]+a[idx2+j+t]*beta;
						b[idx3+j]=a[idx2+j]-a[idx2+j+t]*beta;
					}
				}
			}else{
				for(int j=0;j<t;++j){
					for(int k=0;k<s;++k){
						b[k*t+j]=a[k*2*t+j]+a[k*2*t+j+t]*C(cosl(2*M_PIl*t*k/n),sinl(2*M_PIl*t*k/n));
						b[(k+s)*t+j]=a[k*2*t+j]-a[k*2*t+j+t]*C(cosl(2*M_PIl*t*k/n),sinl(2*M_PIl*t*k/n));
					}
				}
			}
			swap(a,b);
		}
		for(int i=0;i<n;++i){
			const int j=i==0?0:n-i;
			b[i]=(a[i]+conj(a[j]))*(a[i]-conj(a[j]))*C(0,-.25);
		}
		swap(a,b);
		for(short i=0;i<h;++i){
			const int s=1<<i,t=1<<(h-i-1);
			if(i*2<h-1){
				for(int k=0;k<s;++k){
					const C beta=C(cosl(2*M_PIl*t*k/n),-sinl(2*M_PIl*t*k/n));
					const int idx1=k*t,idx2=k*2*t,idx3=(k+s)*t;
					for(int j=0;j<t;++j){
						b[idx1+j]=a[idx2+j]+a[idx2+j+t]*beta;
						b[idx3+j]=a[idx2+j]-a[idx2+j+t]*beta;
					}
				}
			}else{
				for(int j=0;j<t;++j){
					for(int k=0;k<s;++k){
						const C beta=C(cosl(2*M_PIl*t*k/n),-sinl(2*M_PIl*t*k/n));
						b[k*t+j]=a[k*2*t+j]+a[k*2*t+j+t]*beta;
						b[(k+s)*t+j]=a[k*2*t+j]-a[k*2*t+j+t]*beta;
					}
				}
			}
			swap(a,b);
		}
		for(int i=0;i<n;++i)a[i]/=n;
		return a;
	}
};