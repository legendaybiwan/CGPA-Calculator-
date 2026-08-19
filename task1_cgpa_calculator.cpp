/*
 * TASK 1: CGPA Calculator
 * ------------------------
 * - Takes input for the number of courses taken by the student.
 * - For each course, inputs the grade and credit hours.
 * - Calculates total credits and total grade points (grade x credit hours).
 * - Computes GPA for the semester and CGPA across all semesters entered.
 * - Displays individual course grades and the final CGPA to the user.
 *
 * Grading scale used (10-point scale, common in many universities):
 *   O  (Outstanding)   -> 10
 *   A+ (Excellent)     -> 9
 *   A  (Very Good)     -> 8
 *   B+ (Good)          -> 7
 *   B  (Above Average) -> 6
 *   C  (Average)       -> 5
 *   F  (Fail)          -> 0
 *
 * Edit the gradePoints map below if your institution uses a different scale.
 */

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

map<string, int> gradePoints = {
    {"O", 10}, {"A+", 9}, {"A", 8},
    {"B+", 7}, {"B", 6}, {"C", 5}, {"F", 0}
};

struct CourseRecord {
    int courseNo;
    string grade;
    double creditHours;
    double gradePointsEarned;
};

void clearInputError() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

string getValidGrade() {
    string grade;
    while (true) {
        cout << "    Enter grade (O, A+, A, B+, B, C, F): ";
        cin >> grade;
        for (auto &c : grade) c = toupper(c);
        if (gradePoints.count(grade)) return grade;
        cout << "    Invalid grade. Please choose from: O, A+, A, B+, B, C, F\n";
    }
}

double getValidCreditHours() {
    double credits;
    while (true) {
        cout << "    Enter credit hours for this course: ";
        cin >> credits;
        if (cin.fail() || credits <= 0) {
            clearInputError();
            cout << "    Invalid input. Credit hours must be a positive number.\n";
            continue;
        }
        return credits;
    }
}

int getValidCourseCount() {
    int n;
    while (true) {
        cout << "Enter number of courses taken: ";
        cin >> n;
        if (cin.fail() || n <= 0) {
            clearInputError();
            cout << "Invalid input. Number of courses must be a positive integer.\n";
            continue;
        }
        return n;
    }
}

// Returns totalCredits, totalGradePoints, gpa via reference parameters
void calculateSemesterGPA(int semesterNumber, double &totalCredits, double &totalGradePoints, double &gpa) {
    cout << "\n--- Semester " << semesterNumber << " ---\n";
    int numCourses = getValidCourseCount();

    totalCredits = 0.0;
    totalGradePoints = 0.0;
    vector<CourseRecord> records;

    for (int i = 1; i <= numCourses; i++) {
        cout << "\n  Course " << i << ":\n";
        string grade = getValidGrade();
        double creditHours = getValidCreditHours();

        double coursePoints = gradePoints[grade] * creditHours;
        totalCredits += creditHours;
        totalGradePoints += coursePoints;

        records.push_back({i, grade, creditHours, coursePoints});
    }

    gpa = (totalCredits > 0) ? (totalGradePoints / totalCredits) : 0.0;

    cout << "\n  Course Summary - Semester " << semesterNumber << "\n";
    cout << "  " << string(45, '-') << "\n";
    cout << "  " << left << setw(8) << "Course" << setw(8) << "Grade"
         << setw(10) << "Credits" << setw(10) << "GradePts" << "\n";
    for (auto &r : records) {
        cout << "  " << left << setw(8) << r.courseNo << setw(8) << r.grade
             << setw(10) << r.creditHours << fixed << setprecision(2)
             << setw(10) << r.gradePointsEarned << "\n";
    }
    cout << "  " << string(45, '-') << "\n";
    cout << fixed << setprecision(2);
    cout << "  Total Credits      : " << totalCredits << "\n";
    cout << "  Total Grade Points : " << totalGradePoints << "\n";
    cout << "  Semester GPA       : " << gpa << "\n";
}

int main() {
    cout << string(50, '=') << "\n";
    cout << "           CGPA CALCULATOR\n";
    cout << string(50, '=') << "\n";

    int numSemesters;
    while (true) {
        cout << "\nEnter number of semesters to calculate CGPA for: ";
        cin >> numSemesters;
        if (cin.fail() || numSemesters <= 0) {
            clearInputError();
            cout << "Invalid input. Number of semesters must be positive.\n";
            continue;
        }
        break;
    }

    double overallCredits = 0.0;
    double overallGradePoints = 0.0;

    for (int sem = 1; sem <= numSemesters; sem++) {
        double credits, gradePointsEarned, gpa;
        calculateSemesterGPA(sem, credits, gradePointsEarned, gpa);
        overallCredits += credits;
        overallGradePoints += gradePointsEarned;
    }

    double cgpa = (overallCredits > 0) ? (overallGradePoints / overallCredits) : 0.0;

    cout << "\n" << string(50, '=') << "\n";
    cout << "                 FINAL RESULT\n";
    cout << string(50, '=') << "\n";
    cout << fixed << setprecision(2);
    cout << "Total Credits (all semesters)     : " << overallCredits << "\n";
    cout << "Total Grade Points (all semesters): " << overallGradePoints << "\n";
    cout << "FINAL CGPA                        : " << cgpa << "\n";
    cout << string(50, '=') << "\n";

    return 0;
}
