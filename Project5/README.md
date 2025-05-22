# Student Results Management System

A Windows Forms application for managing student exam results with three user roles: admin, instructor, and student.

## Features

### Admin Features
- Create and manage instructor accounts
- Create and manage student accounts
- Create new courses
- Assign instructors to courses
- View all users and courses in the system

### Instructor Features
- View assigned courses
- Manage student results for assigned courses
- View list of students for each course

### Student Features
- View their own exam results for all courses

## Getting Started

### Prerequisites
- Visual Studio with C++ and Windows Forms support
- Microsoft Access database engine

### Database Setup

1. **Create Microsoft Access Database**:
   - Install Microsoft Access (part of Microsoft Office) if not already installed
   - Open Microsoft Access and create a new blank database
   - Name it "StudentResults.accdb" and save it in the same directory as your application executable
   - If running from Visual Studio, place it in your `Project5/x64/Debug` or `Project5/x64/Release` directory

2. **Prepare SQL Script**:
   - Locate the `DatabaseSetup.sql` file included in the project
   - Open it with any text editor to review the SQL statements

3. **Execute SQL Statements**:
   - In Microsoft Access, go to "Create" tab → "Query Design"
   - Close the "Show Table" dialog that appears
   - Go to "Design" tab → "SQL View"
   - Copy each SQL statement (separated by semicolons) from the DatabaseSetup.sql file
   - Paste one statement at a time into the SQL View window
   - Click "Run" (the red exclamation mark button) for each statement
   - Important: Execute the CREATE TABLE statements in the order they appear before executing the INSERT statements

4. **Verify Database Setup**:
   - In Microsoft Access, check the "Tables" section in the left panel
   - You should see tables for Users, Courses, InstructorCourses, and Results
   - Open the Users table to verify the default admin account is available (username: admin, password: admin123)

### Running the Application
1. Open the solution in Visual Studio
2. Build the solution
3. Run the application
4. Login with one of the default accounts (see below)

## Default Accounts

### Admin Account
- Username: admin
- Password: admin123

### Instructor Accounts
- Username: instructor1
- Password: inst123
- Assigned Courses: Introduction to Programming, Database Systems

- Username: instructor2
- Password: inst123
- Assigned Courses: Data Structures and Algorithms

### Student Accounts
- Username: student1
- Password: stud123
- Name: Michael Brown

- Username: student2
- Password: stud123
- Name: Emily Davis

- Username: student3
- Password: stud123
- Name: David Wilson

## Project Structure

- `main.cpp` - Application entry point
- `LoginForm` - User authentication
- `AdminDashboard` - Admin functionality
- `InstructorDashboard` - Instructor functionality
- `StudentDashboard` - Student functionality
- `DatabaseHelper` - Database operations
- Support forms:
  - `AddUserForm` - For adding new users
  - `AddCourseForm` - For adding new courses
  - `AssignInstructorForm` - For assigning instructors to courses
  - `AssignResultForm` - For recording student results

## Database Schema

### Users Table
- UserID (Primary Key)
- Username
- Password
- Name
- Age
- Role (0=Admin, 1=Instructor, 2=Student)

### Courses Table
- CourseID (Primary Key)
- CourseName
- CourseCode

### InstructorCourses Table
- ICID (Primary Key)
- InstructorID
- CourseID

### Results Table
- ResultID (Primary Key)
- StudentID
- CourseID
- Result 