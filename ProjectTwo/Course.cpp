/*******************************************************************************
**                                                                            **
**  Patrick D. Pattison                                                       **
**  CS-300 - Data Structures and Algorithms                                   **
**  Southern Hew Hampshire University                                         **
**  Module 6:  Project Two                                                    **
**                                                                            **
********************************************************************************
**                                                                            **
**  File Name  :  Course.cpp                                                  **
**  Description:  Implementation of Course class                              **
**                Course class is a representation of a course.               **
**                                                                            **
********************************************************************************
**                                                                            **
**  REVISION HISTORY                                                          **
**  06 Dec  2021 - Initial Coding.                                            **
**  11 Dec  2021 - Updated the print function to make the course printout     **
**                 look a little better.  Also cleaned up and commented the   **
**                 code for turning in.                                       **
*******************************************************************************/


//  Project includes...
#include "Course.h"


//
//  Function   :  Course
//  Return Type:  none
//  Paramaters :  none
//  Description:  Default constructor.
//
Course::Course()
{

   //  Initialize courses id and title to an empty string.
   this->id = "";
   this->title = "";

}


//
//  Function   :  setId
//  Return Type:  void
//  Paramaters :  std::string new_id
//  Description:  Sets member variable id.
//
void Course::setId(std::string new_id)
{

   //  Set id to passed in new_id value.
   this->id = new_id;

}


//
//  Function   :  getId
//  Return Type:  std::string
//  Paramaters :  none
//  Description:  Returns the value of member variable id.
//
std::string Course::getId()
{

   //  Return my id.
   return id;

}


//
//  Function   :  setTitle
//  Return Type:  void
//  Paramaters :  std::string new_title
//  Description:  Sets member variable title.
//
void Course::setTitle(std::string new_title)
{

   //  Set title to passed in new_title value.
   this->title = new_title;

}


//
//  Function   :  getTitle
//  Return Type:  std::string
//  Paramaters :  none
//  Description:  Returns the value of member variable title.
//
std::string Course::getTitle()
{

   //  Return my title.
   return title;

}


//
//  Function   :  getNumberPreReqs
//  Return Type:  int
//  Paramaters :  none
//  Description:  Returns the number of prerequisites course has.
//
int Course::getNumberPreReqs()
{

   //Return my number of prerequisites
   return pre_reqs.size();

}


//
//  Function   :  addPreReq
//  Return Type:  void
//  Paramaters :  std::string new_req
//  Description:  Adds a new prerequisite to this course.
//
void Course::addPreReq(std::string new_req)
{

   //  Adds new_req passed in to my prerequisites.
   this->pre_reqs.push_back(new_req);

}


//
//  Function   :  getPreReq
//  Return Type:  std::string
//  Paramaters :  int index
//  Description:  Returns the prerequisite at a specific index.
//
std::string Course::getPreReq(int index)
{

   //  Start with an empty string.
   std::string ret_value = "";

   //  Validate that the index passed in is within the size
   //  constraints of our prerequisites.
   if ((index >= 0) && (index < pre_reqs.size()))
   {

      //  Set the return value equal to the prereq at the index.
      ret_value = pre_reqs.at(index);

   }

   //  Return either the prerequisite at the index passed in, or 
   //  return the empty string from earlier.
   return ret_value;

}


//
//  Function   :  print
//  Return Type:  void
//  Paramaters :  none
//  Description:  Prints out the course's details.
//
void Course::print()
{

   //  Print out the course ID and title...
   std::cout << "\n";
   std::cout <<  this->id << " -- " << this->title << "\n";
   std::cout << "\n";

   //  Print out the prerequisites, or none...
   std::cout << "pre_requisites:\n";
   if (this->pre_reqs.size() > 0)
   {

      for (int index  = 0; index < this->pre_reqs.size(); index++)
      {

         std::cout << "   " << this->pre_reqs.at(index) << "\n";

      }

   }
   else
   {

      std::cout << "   None\n";
   }
   //  Print out a dashed line to seperate courses.
   std::cout << "\n";
   for (int index = 0; index < 80; index++)
   {
      std::cout << "-";
   }
   std::cout << "\n";

}


//
//  Function   :  operator==
//  Return Type:  bool
//  Paramaters :  const Course& lh, const Course& rh
//  Description:  Operator to compare two course objects for equality
//                If two course objects have the same id value,
//                they are the same.
//
bool operator==(const Course& lh, const Course& rh)
{

   return lh.id == rh.id;

}


//
//  Function   :  operator!=
//  Return Type:  bool
//  Paramaters :  const Course& lh, const Course& rh
//  Description:  Operator to compare two course objects for inequality
//                If two course objects have different id values,
//                they are different.
//
bool operator!=(const Course& lh, const Course& rh)
{

   return lh.id != rh.id;

}


//
//  Function   :  operator<
//  Return Type:  bool
//  Paramaters :  const Course& lh, const Course& rh
//  Description:  Operator to compare two course objects for lesser than
//                The course id determines which course is less.
//
bool operator<(const Course& lh, const Course& rh)
{

   return lh.id < rh.id;

}


//
//  Function   :  operator<=
//  Return Type:  bool
//  Paramaters :  const Course& lh, const Course& rh
//  Description:  Operator to compare two course objects for lesser or equal
//                The course id determines which course is less or equal.
//
bool operator<=(const Course& lh, const Course& rh)
{

   return lh.id <= rh.id;

}


//
//  Function   :  operator>
//  Return Type:  bool
//  Paramaters :  const Course& lh, const Course& rh
//  Description:  Operator to compare two course objects for greater than
//                The course id determines which course is greater.
//
bool operator>(const Course& lh, const Course& rh)
{

   return lh.id > rh.id;

}


//
//  Function   :  operator>=
//  Return Type:  bool
//  Paramaters :  const Course& lh, const Course& rh
//  Description:  Operator to compare two course objects for greater or equal
//                The course id determines which course is greater or equal.
//
bool operator>=(const Course& lh, const Course& rh)
{

   return lh.id >= rh.id;

}


