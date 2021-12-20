/*******************************************************************************
**                                                                            **
**  Patrick D. Pattison                                                       **
**  CS-300 - Data Structures and Algorithms                                   **
**  Southern Hew Hampshire University                                         **
**  Module 6:  Project Two                                                    **
**                                                                            **
********************************************************************************
**                                                                            **
**  File Name  :  BSTNode.cpp                                                 **
**  Description:  Implementation of BSTNode class                             **
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


//  Project includes...
#include "BSTNode.h"


//
//  Function   :  BSTNode
//  Return Type:  none
//  Paramaters :  none
//  Description:  Default constructor
//
BSTNode::BSTNode()
{

   //  Initialize the left and right child pointers to null.
   left = nullptr;
   right = nullptr;

}


//
//  Function   :  BSTNode
//  Return Type:  none
//  Paramaters :  Course course
//  Description:  Custom constructor.  Calls the default constructor
//                and then sets the nodes course object to the course 
//                object passed in.
//
BSTNode::BSTNode(Course course) : BSTNode()
{

   this->course = course;

}
