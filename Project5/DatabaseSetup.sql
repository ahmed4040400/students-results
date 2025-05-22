/* 
 * Database Setup Script for Student Results Application
 * This script creates the necessary tables and inserts initial seed data.
 * 
 * To use this script:
 * 1. Create a new Microsoft Access database named "StudentResults.accdb"
 * 2. Run each SQL statement separately through the Access SQL view
 */

-- Create Users Table
CREATE TABLE Users (
    UserID AUTOINCREMENT PRIMARY KEY,
    Username TEXT NOT NULL,
    Password TEXT NOT NULL,
    Name TEXT NOT NULL,
    Age INT NOT NULL,
    Role INT NOT NULL
);

-- Create Courses Table
CREATE TABLE Courses (
    CourseID AUTOINCREMENT PRIMARY KEY,
    CourseName TEXT NOT NULL,
    CourseCode TEXT NOT NULL
);

-- Create InstructorCourses Table (association between instructors and courses)
CREATE TABLE InstructorCourses (
    ICID AUTOINCREMENT PRIMARY KEY,
    InstructorID INT NOT NULL,
    CourseID INT NOT NULL
);

-- Create Results Table
CREATE TABLE Results (
    ResultID AUTOINCREMENT PRIMARY KEY,
    StudentID INT NOT NULL,
    CourseID INT NOT NULL,
    Result DOUBLE NOT NULL
);

-- Insert Admin User
INSERT INTO Users (Username, Password, Name, Age, Role)
VALUES ('admin', 'admin123', 'Administrator', 35, 0);

-- Insert Instructor Users
INSERT INTO Users (Username, Password, Name, Age, Role)
VALUES ('instructor1', 'inst123', 'John Smith', 45, 1);

INSERT INTO Users (Username, Password, Name, Age, Role)
VALUES ('instructor2', 'inst123', 'Jane Johnson', 38, 1);

-- Insert Student Users
INSERT INTO Users (Username, Password, Name, Age, Role)
VALUES ('student1', 'stud123', 'Michael Brown', 20, 2);

INSERT INTO Users (Username, Password, Name, Age, Role)
VALUES ('student2', 'stud123', 'Emily Davis', 21, 2);

INSERT INTO Users (Username, Password, Name, Age, Role)
VALUES ('student3', 'stud123', 'David Wilson', 19, 2);

-- Insert Courses
INSERT INTO Courses (CourseName, CourseCode)
VALUES ('Introduction to Programming', 'CS101');

INSERT INTO Courses (CourseName, CourseCode)
VALUES ('Data Structures and Algorithms', 'CS201');

INSERT INTO Courses (CourseName, CourseCode)
VALUES ('Database Systems', 'CS301');

-- Assign Instructors to Courses
INSERT INTO InstructorCourses (InstructorID, CourseID)
VALUES (2, 1); -- John Smith teaches Intro to Programming

INSERT INTO InstructorCourses (InstructorID, CourseID)
VALUES (3, 2); -- Jane Johnson teaches Data Structures

INSERT INTO InstructorCourses (InstructorID, CourseID)
VALUES (2, 3); -- John Smith also teaches Databases

-- Insert Initial Results
INSERT INTO Results (StudentID, CourseID, Result)
VALUES (4, 1, 85.5); -- Michael's result for Intro to Programming

INSERT INTO Results (StudentID, CourseID, Result)
VALUES (5, 1, 92.0); -- Emily's result for Intro to Programming

INSERT INTO Results (StudentID, CourseID, Result)
VALUES (6, 1, 78.5); -- David's result for Intro to Programming

INSERT INTO Results (StudentID, CourseID, Result)
VALUES (4, 2, 90.0); -- Michael's result for Data Structures 