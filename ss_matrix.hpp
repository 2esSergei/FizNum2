#ifndef SS_MATRIX
#define SS_MATRIX

#include<iostream>
#include<vector>
#include"ss_gyuru.hpp"

class ss_matrix : public ss_gyuru
{
  protected:
    int _m, _n;
    std::vector<double> v;
  public:
    ss_matrix(int, int);
    ss_matrix(ss_matrix&);
    ~ss_matrix();

    //for simple use
    const int get_row() const {return _m;}
    const int get_col() const {return _n;}
    double& operator()(const int,const int);
    bool operator==(ss_matrix&);

    //for structure
    const ss_gyuru& operator+(const ss_gyuru&) const{};
    const ss_matrix operator+(ss_matrix&) const;
    const ss_gyuru& operator-(const ss_gyuru&) const{};
    const ss_matrix operator-(ss_matrix&) const;
    const ss_gyuru& operator*(const ss_gyuru&) const{};
    const ss_matrix operator*(ss_matrix&) const;

    //for simple I/O
    friend std::istream& operator>>(std::istream&, ss_matrix&);
    friend std::ostream& operator<<(std::ostream&, ss_matrix&);

};
#endif
