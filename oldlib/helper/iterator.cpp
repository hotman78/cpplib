    template<typename Getter>
    class iterator{
        int i;
        Getter getter;
        public:
        iterator(const int& i,const Getter& getter):i(i),getter(getter){}
        inline constexpr auto operator*()noexcept{return getter(i);}
        inline constexpr iterator operator++()noexcept{++i;return *this;}
        inline constexpr iterator operator--()noexcept{--i;return *this;}
        inline constexpr iterator operator++(int n)noexcept{++i;return *this;}
        inline constexpr iterator operator--(int n)noexcept{--i;return *this;}
        inline constexpr iterator operator+=(const int& rhs)noexcept{i+=rhs;return *this;}
        inline constexpr iterator operator-=(const int& rhs)noexcept{i-=rhs;return *this;}
        inline constexpr iterator operator+(const int& rhs)const noexcept{return iterator(*this)+=rhs;}
        inline constexpr iterator operator-(const int& rhs)const noexcept{return iterator(*this)-=rhs;}
        inline constexpr bool operator!=(const iterator& rhs)const noexcept{return i!=rhs.i;}
        inline constexpr bool operator==(const iterator& rhs)const noexcept{return i==rhs.i;}
    };
    inline auto make_iterator(const int& i)noexcept{
        static auto getter=[this](const int& i){return get(i,i+1);};
        return iterator<decltype(getter)>(i,getter);
    }