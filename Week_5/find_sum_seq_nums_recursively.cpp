// 2)	Find the sum of a sequence of numbers recursively 
#include <iostream>
using namespace std;

int calSumSeqNums(int *arr, int len)
{
   if(len == 1)
      return *arr;
   else
   {
      int temp1 = *arr;
      return temp1 + calSumSeqNums(++arr, --len); 
   }
}
int main()
{
   int arr[] = {1,2,3,4,5,7,8,9}; // 39
   int len = sizeof(arr)/sizeof(arr[0]);
   cout << "Sum of the sequence of numbers recursively: " << calSumSeqNums(arr, len) << endl;
   return 0;
}