#include<iostream>
#include"ss_group.hpp"

class ss_2dv : public ss_group{
  protected:
  double x,y;
  public:
  ss_2dv(double _x,double _y)
  : x(_x) , y(_y) {}
  ss_2dv(const ss_2dv& v){
    (*this).x = v.x;
    (*this).y = v.y;
  }
  //ss_2dv& operator+(const ss_2dv&, const ss_2dv&);
//};

ss_group& operator+(const ss_group& v){
  double x1 = v.x + ss_2dv::x;
  double x2 = v.y + ss_2dv::y;
  ss_2dv* z = new ss_2dv(x1, x2);
  return *z;
}
};

int main(){
  ss_2dv a(1.0, 2.0);
  //ss_2dv b = a;
  return 0;
}

