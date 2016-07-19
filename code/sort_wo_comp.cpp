#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>
 
using namespace std;

int main(int c, char **v)
{    
  while (--c > 1 && !fork());  
  sleep(c = atoi(v[c]));
  // printf("%d\n", c);
  cout<< c << "\n";
  wait(0);
  return 0;
}
// g++ filename.cpp
// ./a.out 5 1 3 2 11 6 4

// ========================================================
// C code
// ========================================================
// #include <stdlib.h>
// #include <unistd.h>
// #include <sys/types.h>
// #include <sys/wait.h>
// #include <stdio.h>
// // 
// // using namespace std;
// 
// int main(int c, char **v)
// {    
//   while (--c > 1 && !fork());  
//   sleep(c = atoi(v[c]));
//   printf("%d\n", c);
//   // cout<< c << "\n";
//   wait(0);
//   return 0;
// }
// // g++ filename.cpp
// // ./a.out 5 1 3 2 11 6 4