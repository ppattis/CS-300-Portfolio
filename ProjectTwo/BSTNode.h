/*******************************************************************************
**                                                                            **
**  Patrick D. Pattison                                                       **
**  CS-300 - Data Structures and Algorithms                                   **
**  Southern Hew Hampshire University                                         **
**  Module 6:  Project Two                                                    **
**                                                                            **
********************************************************************************
**                                                                            **
**  File Name  :  BSTNode.h                                                   **
**  Description:  Declaration of BSTNode class                                **
**                BSTNode class is a node to be added to the BST class.       **
**                                                                            **
********************************************************************************
**                                                                            **
**  REVISION HISTORY                                                          **
**  06 Dec  2021 - Initial Coding.                                            **
**  10 Dec  2021 - Made the decision to change the implementation of          **
**                 this class.  This class is only used internally to the     **
**                 BST class so the internal variables of this class were     **
**                 changed to public.                                         **
**  11 Dec  2021 - Code cleanup and commenting for turn in.                   **
*******************************************************************************/

#ifndef __CS_300_PROJECT_TWO__BST_NODE_H__
   #define __CS_300_PROJECT_TWO__BST_NODE_H__

   //  Project includes...
   #include "Course.h"

   class BSTNode
   {

      public:

         //  Default constructor.
         BSTNode();
         //  Custom constructor
         BSTNode(Course course);

         //  Variables to store the course information of this node,
         //  as well as the left and right child node of this node...
         Course   course;
         BSTNode* left;
         BSTNode* right;

   };

#endif

