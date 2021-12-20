/*******************************************************************************
**                                                                            **
**  Patrick D. Pattison                                                       **
**  CS-300 - Data Structures and Algorithms                                   **
**  Southern Hew Hampshire University                                         **
**  Module 6:  Project Two                                                    **
**                                                                            **
********************************************************************************
**                                                                            **
**  File Name  :  BST.cpp                                                     **
**  Description:  Implementation of BST class                                 **
**                BST class is an implementation of the BinarySearchTree.     **
**                                                                            **
********************************************************************************
**                                                                            **
**  REVISION HISTORY                                                          **
**  06 Dec  2021 - Initial Coding.                                            **
**  11 Dec  2021 - Converted insertion operation into a recursive operation.  **
**                 Cleaned up code and commented for turning in.              **
*******************************************************************************/


//  System includes...
#include <iostream>

//  Project includes...
#include "BST.h"


//
//  Function   :  BST
//  Return Type:  None
//  Paramaters :  None
//  Description:  Default constructor
//
BST::BST()
{

   //  Initialize root pointer to null.
   this->root = nullptr;

}


//
//  Function   :  insert
//  Return Type:  void
//  Paramaters :  BSTNode** current, Course new_course
//  Description:  Inserts new_course recursively.
//
void BST::insert(BSTNode** current, Course new_course)
{

   //  First if the current pointer is null, create a new node and insert
   //  the course.
   if (*current == nullptr)
   {

      *current = new BSTNode(new_course);

   }
   //  Current pointer is not null.  If new_course is less than
   //  the current course, we go left, otherwise we go right.
   else if (new_course.getId() <= (*current)->course.getId())
   {

     this->insert(&(*current)->left, new_course);

   }
   else
   {

      this->insert(&(*current)->right, new_course);

   }

}


//
//  Function   :  insert
//  Return Type:  void
//  Paramaters :  Course new_course
//  Description:  inserts new_course.  Calls the other insert.
//
void BST::insert(Course new_course)
{

   //  Calling the other insert with the root node.  The other
   //  insert will check for root being null.
   insert(&root, new_course);

}


//
//  Function   :  populate
//  Return Type:  void
//  Paramaters :  std::string filename
//  Description:  Reads in a csv file of course information
//                and populates the BST with all course data
//                sorted correctly.
//
void BST::populate(std::string filename)
{

   //  First off, initialize filestream object and pass in filename.
   std::ifstream in_file;
   in_file.open(filename);

   //  Verify that the file was opened correctly, and that file exists.
   if (in_file.is_open())
   {

      //  Read the file line by line.
      std::string line;
      while (std::getline(in_file, line))
      {

         //  Convert the line just read in from the file into a std::vector
         //  of std::strings splitting the line on commas, thus csv...
         std::stringstream tokenizer = std::stringstream(line);
         std::vector<std::string> token;
         while (tokenizer.good())
         {

            std::string word;
            std::getline(tokenizer, word, ',');
            token.push_back(word);

         }

         //  A valid course should have at the least 2 tokens.
         //  2 tokens is a course with no prerequisites, and 
         //  all tokens after the first two are prerequisites.
         if (token.size() >= 2)
         {

            //  Build a new course object based on the tokens read in
            //  from the file.
            Course new_course = Course();
            new_course.setId(token.at(0));
            new_course.setTitle(token.at(1));
            for (int index = 2; index < token.size(); index++)
            {

               new_course.addPreReq(token.at(index));

            }

            //  Insert the new course into the tree.
            this->insert(new_course);

         }

      }

   }

}


//
//  Function   :  printCourse
//  Return Type:  void
//  Paramaters :  std::string course_id
//  Description:  Searches the tree for a course matching the course_id
//                and if found, print it out, otherwise print out an
//                error message.
//
void BST::printCourse(std::string course_id)
{

   //  Initialize the current node to the root node.
   BSTNode* current = root;

   //  Keep looking for the course until either we find it, or 
   //  we hit a null node, meaning we didn't find it.
   while (current != nullptr)
   {

      //  Test if currently pointed at course is the one we are looking for.
      if (current->course.getId() == course_id)
      {

         //  It was.  Print it.
         current->course.print();

         //  Return now because we found what we are looking for,
         //  so we can stop looking.
         return;

      }
      //  It wasn't.  If the course we are looking for is 
      //  less than the currently pointed at course, go left
      else if (course_id <= current->course.getId())
      {

         current = current->left;

      }
      //  otherwise go right.
      else
      {

         current = current->right;

      }

   }

   //  Print error message, course wasn't found.
   std::cout << "No course found.\n";

}


//
//  Function   :  printAll
//  Return Type:  void
//  Paramaters :  none
//  Description:  Prints out all courses.
//
void BST::printAll()
{

   //  Call the other print all with the root node.
   this->printAll(this->root);

}


//
//  Function   :  printAll
//  Return Type:  void
//  Paramaters :  BSTNode* current
//  Description:  Takes a BSTNode and in order traverses
//                the tree printing all nodes in the tree.
//
void BST::printAll(BSTNode* current)
{

   //  As long as current pointer isn't null, carry on.
   if (current != nullptr)
   {

      //  Traverse left.
      this->printAll(current->left);
      //  Print course currently pointed at.
      current->course.print();
      //  Traverse right.
      this->printAll(current->right);

   }

}