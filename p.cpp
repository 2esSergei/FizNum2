#include<iostream>
#include<fstream>
#include"ss_matrix.hpp"
#include"ss_num_tools.hpp"

int main()
{
  /*
  ss_matrix M(4,4);

  double k = 1;
  for (int i = 1; i<5; i++)
    for (int j = 1; j<5; j++)
    {
      M(i,j) = k;
      k+=5;
    }

  ss_matrix N(4,4);
  for (int i = 1; i<5; i++)
    for (int j = 1; j<5; j++)
      if(i=j)
        N(i,j) = 1;

  ss_matrix O(2,2);
  //O = (M*N);
  int l=0;
  for (int i=1; i<3; i++)
  {
    k++;
    for (int j=1; j<3; j++)
      O(i,j) = k;
  }
  ss_gauss(O);
//
  for (int i = 1; i<6; i++)
    for (int j = 1; j<7; j++)
      std::cout << N(i,j) << " ";
  std::cout << std::endl << std::endl;
  M(1,1) = M(1,1)+M(1,2);
  std::cout << M(1,1) << " " << M(4,5) << " " << M(1,5) << std::endl;
//  M.~ss_matrix();
// 
  for (int i = 1; i<3; i++)
  {
    std::cout << std::endl;
    for (int j = 1; j<3; j++)
    {
      std::cout << O(i,j) << " ";
    }
  }
  std::cout << std::endl << std::endl << "VEGE!" << std::endl;
*/





  ss_matrix M(3,6);
  std::ifstream file;
  file.open("O.txt");
  file >> M;
  file.close();
  std::cout << M;
  ss_gauss(M);
  std::cout << M;
  return 0;
}
