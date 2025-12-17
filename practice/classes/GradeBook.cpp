#include "GradeBook.h"

#include <iostream>

const int GradeBook::MAX_GRADES;

GradeBook::GradeBook( const std::string &name ) : courseName(name) {}

//default constructor
GradeBook::GradeBook(  ) : courseName(""), gradeCount(0) {}


bool GradeBook::setCourseName(const std::string& name) {
    if(!name.empty()) {
        courseName = name;
        return true;
    }
    return false;
}

int GradeBook::getGradeCount() const {
    return gradeCount;
}

bool GradeBook::addGrade(int val) {
    if(val >= 0 && val <= 100) {
        grades[gradeCount] = val;
        ++gradeCount;
        return true;
    }
    return false;
}

double GradeBook::getAverage() const {
    int total = 0;

    for(auto& score : grades) {
        total += score;
    }
    
    return (double)total / getGradeCount();

}

int GradeBook::getMin() const {
    int curMin = 0;

    for(auto& score : grades) {
        if (score < curMin) {
            curMin = score;
        }
    }
    return curMin;
}

int GradeBook::getMax() const {
    int curMax = 0;

    for(auto& score : grades) {
        if (score > curMax) {
            curMax = score;
        }
    }
    return curMax;
}

// Print report: course name, number of grades, min, max, avg
void GradeBook::printReport() const {
    std::cout << "Course: " << courseName << std::endl;
    std::cout << "Number of grades: " << gradeCount << std::endl;
    std::cout << "Min grade: " << getMin() << std::endl;
    std::cout << "Max grade: " << getMax() << std::endl;
    std::cout << "Average grade: " << getAverage() << std::endl;
}

// Friend function to print the first two grades
void debugShowFirstTwo(const GradeBook& gb) {
    std::cout << "First two grades: ";
    if (gb.gradeCount > 0)
        std::cout << gb.grades[0];
    if (gb.gradeCount > 1)
        std::cout << ", " << gb.grades[1];
    if (gb.gradeCount == 0)
        std::cout << "No grades";
    std::cout << std::endl;
}