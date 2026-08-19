# 🎓 CGPA Calculator

A console-based CGPA Calculator available in **C++** and **Python**. Calculates semester GPA and overall CGPA from user-entered grades and credit hours.

![C++](https://img.shields.io/badge/C%2B%2B-17-00599C?logo=c%2B%2B&logoColor=white)
![Python](https://img.shields.io/badge/Python-3.7%2B-3776AB?logo=python&logoColor=white)

## Features
- Takes input for the number of courses taken per semester
- Collects grade (`O, A+, A, B+, B, C, F`) and credit hours for each course
- Calculates total credits and total grade points (grade × credit hours)
- Computes semester GPA and overall CGPA across multiple semesters
- Displays a clean per-course summary table

## Tech Stack
- C++17 / Python 3.7+ (standard library only, no dependencies)

## How to Run

**C++:**
```bash
g++ -std=c++17 -o cgpa_calculator task1_cgpa_calculator.cpp
./cgpa_calculator
```

**Python:**
```bash
python3 task1_cgpa_calculator.py
```

## Grading Scale
| Grade | Points |
|-------|--------|
| O     | 10     |
| A+    | 9      |
| A     | 8      |
| B+    | 7      |
| B     | 6      |
| C     | 5      |
| F     | 0      |

Edit the `gradePoints` map (C++) / `GRADE_POINTS` dict (Python) at the top of the source file to match your institution's scale.

## License
Open-sourced for educational use.
