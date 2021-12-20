/*******************************************************************************
**                                                                            **
**  Patrick D. Pattison                                                       **
**  CS-300 - Data Structures and Algorithms                                   **
**  Southern Hew Hampshire University                                         **
**  Module 6:  Project Two                                                    **
**                                                                            **
********************************************************************************
**                                                                            **
**  File Name  :  BST.h                                                       **
**  Description:  Declaration of BST class                                    **
**                BST class is an implementation of the BinarySearchTree.     **
**                                                                            **
********************************************************************************
**                                                                            **
**  REVISION HISTORY                                                          **
**  06 Dec  2021 - Initial Coding.                                            **
**  11 Dec  2021 - Code cleanup and commenting for turning in.                **
*******************************************************************************/

#ifndef __CS_300_PROJECT_TWO__BST_H__
   #define __CS_300_PROJECT_TWO__BST_H__
   
   //  System includes...
   #include <fstream>
   #include <sstream>

   //  Project includes...
   #include "Course.h"
   #include "BSTNode.h"

   class BST
   {

      public:

         //  Default constructor.
         BST();

         //  Functions to insert a course into the tree...
         void insert(BSTNode** current, Course new_course);
         void insert(Course new_course);

         //  Function to read a csv file and populate the tree...
         void populate(std::string filename);

         //  Function to print a particular course...
         void printCourse(std::string course_id);

         //  Function to print all courses...
         void printAll();
         void printAll(BSTNode* current);


      private:

         //  BSTNode to be the root node.
         BSTNode* root;

   };



#endif

