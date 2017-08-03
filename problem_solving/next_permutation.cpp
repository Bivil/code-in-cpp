#include <iostream>
#include <stdlib.h>
#include <algorithm>  

using namespace std;

int main ()
{
  int my_int[] = { 1, 2, 3 };
  std::next_permutation(my_int, my_int+3);
  cout << my_int[0] << " " << my_int [1] << " " << my_int[2];
}