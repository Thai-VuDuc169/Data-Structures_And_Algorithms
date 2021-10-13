#include <iostream>
// #include <stdio.h>
using namespace std;

int main()

{
   int input[] = {2, 5, 3, 7, 8, 1, 9};
   int num = sizeof(input)/sizeof(input[0]);
   int output[num];
   // int output[num] = {-1, -1,-1,-1,-1,-1,-1};
   for (int i = 0; i < num; i++)
   {
      output[i] = -1;
   }
   // for (int in: output)
   // {
   //    in = -1;
   // }
   for (int j: output)
   {
      cout << j << " " ;
   }
   for (int i = 1; i < num; i++)
   {
      for (int j = i-1; j >= 0; j--)
      {
         if (input[j] < input[i])
         {
            output[i] = input[j];
            break;
         }
      }
   }
   for (int j: output)
   {
      cout << j << " " ;
   }
   return 0;
}