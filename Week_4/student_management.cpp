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

// Declare a course structure
struct Course
{
   string name;
   string code;
   int score;

   Course(string _name, string _code, int _score)
   {
      this->name = _name;
      this->code = _code;
      this->score = _score;
   }

   friend ostream& operator<< (ostream &os, Course &temp_course)
   { 
      os << "------------------------\n"
         << "--- name:" << temp_course.name << "\n"
         << "--- code:" << temp_course.code << "\n"
         << "--- score:" << temp_course.score << "\n"
         << "------------------------\n";
      return os;
   }
};

// Declare a student structure
struct Student
{
   string name;
   string date_of_birth;
   vector<Course> list_of_courses;
   Student(string _name, string _date_of_birth)
   {
      this->name = _name;
      this->date_of_birth = _date_of_birth;
   }

   float calAverageScore()
   {
      if (this->list_of_courses.empty())
      {
         return -1;
      }
      else
      {
         float sum = 0.0;
         float num_courses = this->list_of_courses.size();
         for (Course c : list_of_courses)
         {
            sum += c.score;
         }
         return (sum/num_courses);
      }
   }

   friend ostream& operator<< (ostream &os, Student &temp_student)
   {
      os << "========================\n"
         << "=== name: " << temp_student.name << "\n"
         << "=== code: " << temp_student.date_of_birth << "\n"
         << "=== list of courses: " << endl;
      if(temp_student.list_of_courses.empty())
      {
         os << "--- list os courses is empty! \n"
            << "========================\n";
         return os;     
      }

      for (Course c : temp_student.list_of_courses)
         os << c; 
      os << "========================\n";
      return os;
   }
};

// Define a student node structure
struct Student_Node
{
   Student *info;
   Student_Node *next;
   Student_Node(string _name, string _date_of_birth)
   {
      this->info = new Student(_name, _date_of_birth);
      this->next = NULL;
   }

   Student_Node(Student_Node *parent, string _name, string _date_of_birth)
   {
      this->info = new Student(_name, _date_of_birth);
      // cout << "parent add: " << parent->next <<endl;
      parent->next = this;
      this->next = NULL;
   }

   ~Student_Node()
   {
      delete this->info;
      delete this->next;
   }
};

Student_Node* insertStudentToHeadList(Student_Node *head, Student_Node *student_node)
{  
   student_node->next = head;
   head = student_node;
   return head;
}

void insertStudentWithAlphabeOrder(Student_Node *head, Student_Node *student_node)
{
   while(head != NULL)
   {
      if ((head->info->name < student_node->info->name) 
            && (head->next->info->name > student_node->info->name))
      {
         student_node->next = head->next;
         head->next = student_node;
         break;
      }
      head = head->next;
   }
}

// Print out the list of students
void printStudentList(Student_Node *head)
{
   cout << "~~~~~THE LIST OF STUDENTS~~~~~" << endl;
   while (head != NULL) 
   {
      cout << *head->info;
      head = head->next;
   }
}


int main()
{
   // Initialize the list as empty
   Student_Node *list_head = NULL;
   // Create a node student
   list_head = new Student_Node("bajine", "01/06/1999");
   list_head->info->list_of_courses.push_back(Course("math", "123", 9));
   list_head->info->list_of_courses.push_back(Course("phy", "234", 9));
   list_head->info->list_of_courses.push_back(Course("geo", "345", 9));
   
   // Insert a student at the tail of the list
   cout << "#####Insert a student at the tail of the list#####" << endl; 
   Student_Node *second_node = new Student_Node(list_head, "taylor", "23/04/2003");
   second_node->info->list_of_courses.push_back(Course("math", "123", 3));
   second_node->info->list_of_courses.push_back(Course("phy", "234", 5));
   second_node->info->list_of_courses.push_back(Course("geo", "345", 2));
   printStudentList(list_head);
   
   // Insert a student at the head of the list
   cout << "#####Insert a student at the head of the list#####" << endl;
   Student_Node *third_node = new Student_Node("abrian", "04/10/1997");
   third_node->info->list_of_courses.push_back(Course("math", "123", 8));
   third_node->info->list_of_courses.push_back(Course("phy", "234", 8));
   third_node->info->list_of_courses.push_back(Course("geo", "345", 8));
   list_head = insertStudentToHeadList(list_head, third_node);
   printStudentList(list_head);
   
   // Insert a student according to the alphabetical order  
   cout << "#####Insert a student according to the alphabetical order#####" << endl;
   Student_Node * fourth_node = new Student_Node("cigarette", "09/07/2002");
   insertStudentWithAlphabeOrder(list_head, fourth_node);
   printStudentList(list_head);

   // Search the student having highest average score.
   cout << "#####Search the student having highest average score#####" << endl;
   Student_Node *list_head_ptr = list_head;
   Student_Node *max_score_student = list_head;
   while (list_head_ptr != NULL)
   {
      if (list_head_ptr->info->calAverageScore() > max_score_student->info->calAverageScore())
         max_score_student = list_head_ptr;
      list_head_ptr = list_head_ptr->next;
   };
   cout << "Information of the student: " << endl;
   cout << *(max_score_student->info);

   // Count the number of students in the list
   cout << "#####Count the number of students in the list#####" << endl;
   list_head_ptr = list_head;
   int num_student_count = 0;
   while (list_head_ptr != NULL)
   {
      num_student_count++;
      list_head_ptr = list_head_ptr->next; 
   };
   cout << "The number of students in the list = " << num_student_count << endl;

   return 0;
}
