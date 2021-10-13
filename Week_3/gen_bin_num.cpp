// Generate binary numbers between 1 to n using a queue 
#include <iostream>
#include <string>
#include <queue>
using namespace std;

void genBinNums(int n)
{
   std::queue<string> q;
   q.push("1");
   for (int i = 1; i <= n; i++)
   {
      q.push(q.front() + "0");
      q.push(q.front() + "1");
      cout << q.front() << " " ;
      q.pop();
   }
};

int main()
{
   int n = 16;
   genBinNums(n);

   return 0;
}