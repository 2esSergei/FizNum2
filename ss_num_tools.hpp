#ifndef SS_NUM_T
#define SS_NUM_T

#include"ss_matrix.hpp"

bool lin_of(ss_matrix&);

void ss_gauss(ss_matrix& M)
{
  double g;
  for (int k=1; k < M.get_row()+1; k++)
  {
    if (lin_of(M))
    {
      std::cout << "GAUSS: Nulla determinansu matrix!" << std::endl;
      return;
    }
    for (int i=1;  i < M.get_row()+1; i++)
    {
      if (i != k)
      {
        g = M(i,k)/M(k,k);
        for (int j=1; j < M.get_col()+1; j++)
          M(i,j) = M(i,j) - g * M(k,j);
        std::cout << M;
      }
    }
  }
}

bool lin_of(ss_matrix& M)
{
  for (int i = M.get_row(); 0<i; i--)
    for (int j = M.get_col(); 0<j; j--)
    {
      if (M(i,j) != 0)
        break;
      if (j == 1)
        return true;
    }
  return false;
}



ss_matrix ss_inverz(ss_matrix& M)
{//invertalas negyzetes matrixra
  //ha nem negyzetes visszater a NULL-matrixszal
  if (M.get_row() != M.get_col())
  {
    std::cout << "INVERZ: Nem negyzetes matrix!" << std::endl;
    ss_matrix X(M.get_row(), M.get_row());
    return X;
  }
  ss_matrix G(M.get_row(), 2*M.get_col());

  //hianyzik az optimalas-normalas lepes

  //letrehozzuk az egyesitett matrixot, kihasznaljuk hogy az alapertelmezett
  //matrix a Nulla-matrix
  for (int i = 1; i < M.get_row()+1; i++)
    for (int j = 1; j < M.get_col()+1; j++)
      G(i,j) = M(i,j);
  for (int i = G.get_row()+1; i < 2*G.get_col()+1; i++)
    G(i-G.get_col(),i) = 1;

  ss_gauss(G);
  ss_matrix Y(M.get_row(), M.get_col());

  //kinyerjuk az inverzmatrixot
  for (int i = 1; i < Y.get_row()+1; i++)
    for (int j = 1; j < Y.get_col()+1; j++)
      Y(i,j) = G(i,j+Y.get_col());
  return Y;
}



#endif
