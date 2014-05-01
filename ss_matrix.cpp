#include"ss_matrix.hpp"

ss_matrix::ss_matrix(int m, int n) : _m(m) , _n(n)
{
  for(int i = 0; i<(_m*_n); i++)
      v.push_back(0.0);
}

ss_matrix::ss_matrix(ss_matrix& ss_temp)
{
  for (int i = 0; i< _m; i++)
    for (int j = 0; j<_n; j++)
      ((*this)(i,j)) = ss_temp(i,j);
}

ss_matrix::~ss_matrix()
{
  v.clear();
}

double& ss_matrix::operator()(int i,int j)
{
  return this->v[(i-1)*_n+(j-1)];
}

bool ss_matrix::operator==(ss_matrix& ss_temp)
{
  for (int i=1; i<_m; i++)
    for(int j=1; j<_n; j++)
      if ((*this)(i,j) != ss_temp(i,j))
        return false;
  return true;
}

const ss_matrix ss_matrix::operator+(ss_matrix& ss_temp) const
{
  ss_matrix TEMP(this->get_row(), this->get_col());
  for (int i = 1; i<(_m+1); i++)
    for (int j = 1; j<(_n+1); j++)
      TEMP(i,j) = this->v[(i-1)*_n+(j-1)] + ss_temp(i,j);
  return TEMP;
}

const ss_matrix ss_matrix::operator-(ss_matrix& ss_temp) const
{
  ss_matrix TEMP(this->get_row(), this->get_col());
  for (int i = 1; i<(_m+1); i++)
    for (int j = 1; j<(_n+1); j++)
      TEMP(i,j) = this->v[(i-1)*_n+(j-1)] - ss_temp(i,j);
  return TEMP;
}

const ss_matrix ss_matrix::operator*(ss_matrix& ss_temp) const
{
  ss_matrix TEMP(this->get_row(), ss_temp.get_col());
  for (int i = 1; i<(TEMP.get_row())+1; i++)
    for (int j = 1; j<(TEMP.get_col())+1; j++)
      for (int k = 1; k<(this->_n)+1; k++)
        TEMP(i,j) = TEMP(i,j) + (this->v[(i-1)*_n+(k-1)]) * ss_temp(k,j);
  return TEMP;
}

std::istream& operator>>(std::istream& S, ss_matrix& ss_temp)
{
  for (int i=1; i<ss_temp.get_row()+1; i++)
    for (int j=1; j<ss_temp.get_col()+1; j++)
      S >> ss_temp(i,j);
}

std::ostream& operator<<(std::ostream& S, ss_matrix& ss_temp)
{
  for (int i=1; i<ss_temp.get_row()+1; i++)
  {
    for (int j=1; j<ss_temp.get_col()+1; j++)
      S << ss_temp(i,j) << '\t';
    S << std::endl;
  }
}
