// 3)	Write a recursive function that determines whether an array is a palindrome, 
// where the array and its size are given as parameters. 
#include<iostream>
#include<string>
using namespace std;

bool isSame(int *a, int *b)
{
   if (*a == *b)
      return true;
   return false;
}

bool checkPalindromeArray(int *arr, int len)
{
   if (len == 0 || len == 1)
      return true;
   else
   {
      int* ptr = arr;
      int *a = ptr;
      ptr += (len - 1);
      int *b = ptr;
      bool bool_temp = isSame(a, b);
      len -= 2;
      return (bool_temp & checkPalindromeArray(++arr, len));   
   }
}
 
int main()
{
   int a[] = { 9, 6, 0, 6, 9};
   int n = sizeof(a) / sizeof(a[0]);
   if (checkPalindromeArray(a, n))
      cout << "<<<Palindrome>>>" << endl;
   else
      cout << "<<<Not Palindrome>>>" << endl;
   return 0;
}