// 1)	Recursively find the greatest common divisor of a sequence of values 
// Rule 1: 

#include <iostream>

using namespace std;

int gcd(int a, int b)
{
   // Everything divides 0
   if (a == 0)
      return b;
   if (b == 0)
      return a;
   // base case
   if (a == b)
      return a;
   // a is greater
   if (a > b)
      return gcd(a-b, b);
   return gcd(a, b-a);
}
int findGcdASequenceValues(int* arr, int len)
{
   if (len == 2)
   {
      int a = *arr; arr++;
      int b = *arr;
      return gcd(a, b);
   }
   else
   {
      int temp = gcd(*arr, findGcdASequenceValues(++arr, --len));
      return temp;
   }
}
int main()
{
   int arr[] = {45,18,243,9,81};
   int len = sizeof(arr)/sizeof(arr[0]);
   int gcd_seq = findGcdASequenceValues(&arr[0], len);
   cout << "GCD of the sequence of values is: " << gcd_seq << endl;
   
   return 0;
}
