#include <iostream>
#include "GradeBook.h" // include definition of class GradeBook
using namespace std;

int main()
{
   GradeBook* gbPtr= new GradeBook[5];
   cout << "Initialized Gradebook course names:\n";
   for (int i=0;i<5;i++){
      cout<<"Gradebook course name " << i << ": ";
      gbPtr[i].printReport();
   }

   for (int i=0;i<5;i++){
      gbPtr[i].setCourseName("CS" + std::to_string(i+1));
      // Add some grades for testing
      gbPtr[i].addGrade(80 + i); // e.g., 80, 81, 82, 83, 84
      gbPtr[i].addGrade(90 - i); // e.g., 90, 89, 88, 87, 86
      gbPtr[i].addGrade(70 + 2*i); // e.g., 70, 72, 74, 76, 78
   }

   cout << "Modified Gradebook course names and grades:\n";
   for (int i=0;i<5;i++){
      cout<<"Gradebook course name " << i << ": ";
      gbPtr[i].printReport();
   }
   delete [] gbPtr;
   return 0;
}