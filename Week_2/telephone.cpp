#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct contact 
{
   string *name;
   string *number;
   string *address;
}

struct telephone_book
{
   vector<contact> contacts;
   
}