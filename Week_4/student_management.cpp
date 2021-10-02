/*
                              Array, Pointer
1)	Declare a student structure with main information (name, dob, array of courses). 
Each course is a structure with name, code, score 
2)	Define a student list as single linked list 
3)	Initialize the list as empty 
4)	Create a node student  
5)	Insert a student at the head of the list  
6)	Insert a student at the tail of the list 
7)	Insert a student according to the alphabetical order  

8)	Search the student having highest average score.  
9)	Count the number of students in the list 
10)	Print out the list of students   
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct courses
{
   string name;
   string code;
   int score;
   courses(string _name, string _code, int _score)
   {
      this->name = _name;
      this->code = _code;
      this->score = _score;
   }
};

struct student
{
   string name;
   string date_of_birth;
   vector<courses> list_of_courses;
   student(string _name, string _date_of_birth, vector<courses> _list = NULL)
   {
      this->name = _name;
      this->date_of_birth = _date_of_birth;
      this->list_of_courses = _list;
   }
};


int main()
{

   return 0;
}
