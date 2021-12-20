/*******************************************************************************
**                                                                            **
**  Patrick D. Pattison                                                       **
**  CS-300 - Data Structures and Algorithms                                   **
**  Southern Hew Hampshire University                                         **
**  Module 6:  Project Two                                                    **
**                                                                            **
********************************************************************************
**                                                                            **
**  File Name  :  Course.h                                                    **
**  Description:  Declaration of Course class                                 **
**                Course class is a representation of a course.               **
**                                                                            **
********************************************************************************
**                                                                            **
**  REVISION HISTORY                                                          **
**  06 Dec  2021 - Initial Coding.                                            **
**  11 Dec  2021 - Code cleanup and commenting for turning in.                **
*******************************************************************************/

#ifndef __CS_300_PROJECT_TWO__COURSE_H__
   #define __CS_300_PROJECT_TWO__COURSE_H__
   
   //  System includes...
   #include <iostream>
   #include <string>
   #include <vector>
   
   class Course
   {

      public:

         //  Default constructor.
         Course();

         //  Accessor methods...
         void        setId(std::string new_id);
         std::string getId();
         void        setTitle(std::string new_title);
         std::string getTitle();
         int         getNumberPreReqs();
         void        addPreReq(std::string new_req);
         std::string getPreReq(int index);
         void        print();

         //  Overloaded operators to make sorting into the BST easier...
         friend bool operator==(const Course& lh, const Course& rh);
         friend bool operator!=(const Course& lh, const Course& rh);
         friend bool operator<(const Course& lh, const Course& rh);
         friend bool operator<=(const Course& lh, const Course& rh);
         friend bool operator>(const Course& lh, const Course& rh);
         friend bool operator>=(const Course& lh, const Course& rh);

      private:

         std::string id;
         std::string title;
         std::vector<std::string> pre_reqs;

   };

#endif

