template<typename T>
struct complex_t{
    T x,y;
    using C=complex_t;
    constexpr complex_t(T x=T(),T y=T()):x(x),y(y){}
    constexpr inline C operator +(C rhs)const noexcept{return C(*this)+=rhs;}
    constexpr inline C operator -(C rhs)const noexcept{return C(*this)-=rhs;}
    constexpr inline C operator *(C rhs)const noexcept{return C(*this)*=rhs;}
    constexpr inline C operator /(C rhs)const noexcept{return C(*this)/=rhs;}
    constexpr inline C& operator +=(C rhs){x+=rhs.x;y+=rhs.y;return *this;};
    constexpr inline C& operator -=(C rhs){x-=rhs.x;y-=rhs.y;return *this;};
    constexpr inline C& operator *=(C rhs){return *this={x*rhs.x-y*rhs.y,x*rhs.y+y*rhs.x};};
    constexpr inline C& operator /=(C rhs){return *this*=rhs.inv();};
    constexpr inline void inv(){*this={x/norm(*this),-y/norm(*this)};}
    constexpr inline T norm(){return x*x+y*y;}
    constexpr inline T abs(){return sqrt(norm(*this));}
};

template<typename T>
struct point:complex_t<T>{
    using complex_t<T>::complex_t;
    using C=point;
    constexpr static T EPS=1e-8;
    constexpr inline bool operator ==(C rhs){
        return (this->x-rhs.x)*(this->x-rhs.x)+(this->y-rhs.y)*(this->y-rhs.y)<=EPS;
    }
    constexpr inline bool operator !=(C rhs){
        return !(*this==rhs);
    }
    constexpr inline bool operator <(C rhs){
        return this->x==rhs.x?this->y<rhs.y:this->x<rhs.x;
    }
    T distance(C rhs){return abs(this->x-rhs.x,this->y-rhs.y);}
    T dot(C rhs){return (this->x*rhs.x)+(this->y*rhs.y);}
    T cross(C rhs){return (this->x*rhs.y)-(this->y*rhs.x);}
    T angle(){
        return atan2(this->y,this->x);
    }
};