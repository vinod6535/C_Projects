`# 📜 Marksheet Generation Project 📊

Welcome to the Marksheet Generation Project, a simple C program that generates a marksheet for students based on their subject marks. This program calculates the total marks, percentage, and result classification based on the percentage obtained.

## Sample Output 📝

The generated marksheet will resemble the following format:

---

Your name: [Student Name]    Class: [Class]    Roll Number: [Roll Number]
Father name: [Father's Name]
Mother name: [Mother's Name]
Date of birth: [Date of Birth]
School name: [School Name]

|   SUBJECTS     | MAX MARKS | MIN MARKS | THEORY MARKS |
|----------------|-----------|-----------|--------------|
|   HINDI        |   100     |    33     |     [Hindi Marks]   |
|   ENGLISH      |   100     |    33     |     [English Marks] |
|   SANSKRIT     |   100     |    33     |     [Sanskrit Marks]|
|   MATHEMATICS  |   100     |    33     |     [Mathematics Marks]|
|   SCIENCE      |   100     |    33     |     [Science Marks] |
|   SOCIAL SCIENCE|  100     |    33     |     [Social Science Marks] |
|                |   600     | GRAND TOTAL |     [Grand Total]   |

RESULT : [Result Classification]
GRADE  : [Grade]

---

## How to Use 🚀

1. **Compile the Code:** Before running the program, ensure you have a C compiler installed (e.g., GCC). Compile the code using the following command:

   ```shell
   gcc -o marksheet_generator marksheet_generator.c `

1.  Run the Program: Execute the compiled program:

    `./marksheet_generator`

Usage Instructions 📝
---------------------

1.  When prompted, provide the required student information and subject marks.
2.  The program will calculate the total marks, percentage, and result classification.
3.  The generated marksheet will be displayed.

Important Notes 📌
------------------

-   The program is designed to handle marks for six subjects.
-   Ensure that you enter valid marks within the range of 1 to 100.
-   The result classification and grade will be based on the percentage obtained.

Thank you for using the Marksheet Generation Project! 🎓
