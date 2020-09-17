#pragma once
#include<vector>

template<typename T=long long,int sz=2>
struct kdtree{
    typedef array<T,sz> Point;
    Point point;
    //vector<Point> v;
	long long v_size;
    int axis,depth;
    kdtree *l=nullptr,*r=nullptr;
    kdtree(vector<Point> v=vector<Point>{},int depth=0):v_size(v.size()),depth(depth){
        build(v,depth);
    }
    inline bool comp(const Point& s,const Point& t){
        rep(i,sz)if(s[i]>t[i])return 0;
        return 1;
    }
    inline void build(vector<Point> v,const int& depth){
        if(v_size==0)return;
        axis=depth%tuple_size<Point>::value;
        sort(all(v),[this](const auto s,const auto t){return s[this->axis]<t[this->axis];});
        point=v[v.size()/2];
        vector<Point> lv(v.size()/2),rv(v.size()-v.size()/2);
        rep(i,lv.size())lv[i]=v[i];
    	rep(i,rv.size())rv[i]=v[i+lv.size()];
        if(lv.size()&&v.size()!=1)l=new kdtree(lv,depth+1);
        if(rv.size()&&v.size()!=1)r=new kdtree(rv,depth+1);
    }
	void insert(Point p){
		v_size++;
        if(v_size==1){
            return;
        }
        if(p[axis]<point[axis]){
            if(!l)l=new kdtree(vector<Point>{p},depth+1);
            else l->insert(p);
        }else{
            if(!r)r=new kdtree(vector<Point>{p},depth+1);
            else r->insert(p);
        }
    }
	vector<Point> search(const Point& lp,const Point& rp){
        if(v_size==1&&comp(lp,point)&&comp(point,rp))return vector<Point>{point};
        std::vector<Point> res;
        if(r&&point[axis]<=rp[axis]){
            res=r->search(lp,rp);
        }
        if(l&&lp[axis]<=point[axis]){
            vector<Point> tmp=l->search(lp,rp);
			res.insert(res.end(),all(tmp));
        }
        return res;
    }
};