/* Your Tasks:
1. Add a static const data member to define the maximum number of stored grades.
2. Add private data members: gradeCount (number of stored grades) and an array of grades
3. Add member funtions to achieve the following tasks:
    a. add a grade (0..100 and return true if successful)
    b. return the number of stored grades
    c. compute and return the average, min and max grades (return -1 if no grades)
4. Replace displayMessage() with printReport()to print the course name, number of grades, min, max, and avg grades.
5. Declare the friendship with a standalone function: void debugShowFirstTwo(const GradeBook& gb), which accesses private data members to print the first two grades
6. Seperate class declaration and definition into two files
*/
#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <iostream>
#include <string>

class GradeBook
{
public:
    static const int MAX_GRADES = 100; // 1. static const data member

    // Constructors
    GradeBook(const std::string& name);
    GradeBook();

    // Set and get course name
    bool setCourseName(const std::string& name);
    std::string getCourseName() const;

    // Add a grade (returns true if successful)
    bool addGrade(int grade);

    // Return the number of stored grades
    int getGradeCount() const;

    // Compute and return average, min, and max grades (return -1 if no grades)
    double getAverage() const;
    int getMin() const;
    int getMax() const;

    // Print report (course name, number of grades, min, max, avg)
    void printReport() const;

    // Friend function to print the first two grades
    friend void debugShowFirstTwo(const GradeBook& gb);

private:
    std::string courseName;
    int gradeCount; // 2. number of stored grades
    int grades[MAX_GRADES]; // 2. array of grades
};

#endif
