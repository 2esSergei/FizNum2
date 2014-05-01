#ifndef SS_GYURU
#define SS_GYURU

#include<iostream>

class ss_gyuru{
  public:
    virtual const ss_gyuru& operator+(const ss_gyuru&) const = 0;
    virtual const ss_gyuru& operator-(const ss_gyuru&) const = 0;
    virtual const ss_gyuru& operator*(const ss_gyuru&) const = 0;
};
#endif
