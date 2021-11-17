// 4)	Write a program in C to find the sum of digits of a number using recursion 
#include<iostream>
#include<string>

using namespace std;
int sumDigitsOfNumber(int n)
{
   if (n == 0)
      return 0;
   return ((n % 10) + sumDigitsOfNumber(n / 10));
}
 
int main()
{
    int num = 12345;
    int result = sumDigitsOfNumber(num);
    cout << "Sum of digits in "<< num <<" is "<< result << endl;
    return 0;
}