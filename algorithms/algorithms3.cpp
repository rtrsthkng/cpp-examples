#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


typedef struct student_record {
    std::string name;
    std::vector<int> marks;
} STUDENT_RECORD;

double grade(STUDENT_RECORD& record);

double grade(STUDENT_RECORD& record) 
{
    double total = 0;
    double counter = 0;
    double result = 0;
    for (std::vector<int>::const_iterator it = record.marks.begin(); it != record.marks.end(); it++) {
        total += *it;
        counter++;
    }
    std::cout << "Total: " << total << " Counter: " << counter << std::endl;
    result = total / counter;
    return result;
}

int main()
{
    std::vector<STUDENT_RECORD> student_records;
    //https://stackoverflow.com/questions/18355533/initializing-struct-vector-with-brace-enclosed-initializer-list
    STUDENT_RECORD student1 = {"Arturo", {1, 2, 3, 4}};
    STUDENT_RECORD student2 = {"Alejandro", {5, 6, 7, 8}};
    student_records.push_back(student1);
    student_records.push_back(student2);

    std::vector<double> grades;

    // Apply operation 'grade' to elements from 'begin' to 'end', and put the results at the end of 'grades' (by using back_inserter)
    transform(student_records.begin(), student_records.end(), back_inserter(grades), grade);

    for (std::vector<double>::const_iterator it = grades.begin(); it != grades.end(); it++) {
        std::cout << "Grade: " << *it << std::endl;
    }
}