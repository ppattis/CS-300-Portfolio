

#include <iostream>
#include "BST.h"
#include "Course.h"

void displayMenu()
{

   system("cls");
   std::cout << "Welcome to the course planner.\n";
   std::cout << "------------------------------\n";
   std::cout << "  (1) Load Data Structure.\n";
   std::cout << "  (2) Print Course List.\n";
   std::cout << "  (3) Print Course.\n";
   std::cout << "  (Q) Quit program\n";
   std::cout << "  Enter choice [1, 2, 3, or Q]: ";

}

void loadData(BST* bst)
{

   system("cls");
   std::cout << "\n\n";
   std::cout << "Please enter the filename containing course information: ";
   std::string filename;
   std::cin >> filename;
   bst->populate(filename);
   std::cout << "Data loaded.\n";
   system("pause");

}

void printCourse(BST* bst)
{

   system("cls");
   std::cout << "\n\n";
   std::cout << "Please enter the course ID you wish to print: ";
   std::string course_id;
   std::cin >> course_id;
   bst->printCourse(course_id);
   system("pause");

}

void printCourses(BST* bst)
{

   system("cls");
   bst->printAll();
   system("pause");

}

int main()
{

   std::cout << "Initializing course tree.\n";
   BST* course_tree = new BST();
   std::cout << "Starting main loop.\n";
   bool user_quit = false;
   while (!user_quit)
   {

      std::cout << "Inside main loop.\n";
      displayMenu();
      std::string user_input;
      std::cin >> user_input;
      
      if (user_input == "1")
      {

         loadData(course_tree);

      }
      else if (user_input == "2")
      {

         printCourses(course_tree);

      }
      else if (user_input == "3")
      {

         printCourse(course_tree);

      }
      else if ((user_input == "Q") || (user_input == "q"))
      {

         user_quit = true;

      }
      else
      {

         std::cout << "\n\n";
         std::cout << user_input << " is not a valid opetion.\n";
         system("pause");

      }

   }

   return (0);

}