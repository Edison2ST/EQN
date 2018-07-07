# EQN

This project was called EQN in reference to the ability of the program to solve systems of equations nxn, but it is now possible to solve any Gauss-Jordan elimination (not necessarily nxn) with this program. It is available in javascript at [https://edison2st.github.io/EQN/](https://edison2st.github.io/EQN/) with a limit of 420 rows with columns. If you want to solve larger matrices, you could [download the program in c++ here (Windows only)](https://github.com/Edison2ST/EQN/releases/download/v1.1.0/EQN.exe).

# How to use

Javascript (website):

- Add the number of rows and columns that you want to use (Ex: 2 rows and 3 columns), it must be less or equal than 420 rows with columns, then press "Send".
- x1-1 means first row and first column, x1-2 means first row and second column, x1-n means first row and nth column, x2-1 means second row and first column, xn-1 means nth row and first column, xn-n means nth row and nth column. Fill all those entries with your values. Negative numbers are valid. **NOTE: Put 0.25 instead of 1/4. This program does not work with fractions of numbers.**
- Press "Send" and take a look to the answer and the step-by-step of the program!

C++ (Windows application):

- Add the number of rows that you want to use, press "ENTER", and then add the number of columns that you want to use, press "ENTER".
- x1-1 means first row and first column, x1-2 means first row and second column, x1-n means first row and nth column, x2-1 means second row and first column, xn-1 means nth row and first column, xn-n means nth row and nth column. Fill all those entries with your values, and press "ENTER" for each value. Negative numbers are valid. **NOTE: Put 0.25 instead of 1/4. This program does not work with fractions of numbers.**
- Take a look to the answer and the step-by-step of the program!

# License

This project is released under the MIT License.
