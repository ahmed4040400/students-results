#pragma once

namespace Project5 {
    using namespace System;
    using namespace System::Data;
    using namespace System::Data::OleDb;

    // User role enumeration
    public enum class UserRole {
        Admin = 0,
        Instructor = 1,
        Student = 2
    };

    // Class to manage all database operations
    public ref class DatabaseHelper
    {
    private:
        // Connection string for MS Access database
        String^ connectionString;

    public:
        // Constructor
        DatabaseHelper()
        {
            // Initialize connection string to MS Access database
            connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=StudentResults.accdb;";
        }

        // Method to verify user credentials and return user role
        bool VerifyLogin(String^ username, String^ password, UserRole% role, int% userId)
        {
            try {
                // Create connection and command
                OleDbConnection^ conn = gcnew OleDbConnection(connectionString);
                OleDbCommand^ cmd = gcnew OleDbCommand("SELECT UserID, Role FROM Users WHERE Username = ? AND Password = ?", conn);
                
                // Add parameters
                cmd->Parameters->Add(gcnew OleDbParameter("@p1", username));
                cmd->Parameters->Add(gcnew OleDbParameter("@p2", password));
                
                // Open connection
                conn->Open();
                
                // Execute and get result
                OleDbDataReader^ reader = cmd->ExecuteReader();
                
                if (reader->Read()) {
                    // User found - extract role and userId
                    userId = Convert::ToInt32(reader["UserID"]);
                    role = (UserRole)Convert::ToInt32(reader["Role"]);
                    conn->Close();
                    return true;
                }
                
                conn->Close();
                return false;
            }
            catch (Exception^ ex) {
                // Handle any errors
                System::Windows::Forms::MessageBox::Show("Database error: " + ex->Message);
                return false;
            }
        }

        // Get user details
        DataRow^ GetUserDetails(int userId) {
            try {
                OleDbConnection^ conn = gcnew OleDbConnection(connectionString);
                OleDbCommand^ cmd = gcnew OleDbCommand("SELECT * FROM Users WHERE UserID = ?", conn);
                cmd->Parameters->Add(gcnew OleDbParameter("@p1", userId));
                
                OleDbDataAdapter^ adapter = gcnew OleDbDataAdapter(cmd);
                DataTable^ table = gcnew DataTable();
                
                conn->Open();
                adapter->Fill(table);
                conn->Close();
                
                if (table->Rows->Count > 0) {
                    return table->Rows[0];
                }
                return nullptr;
            }
            catch (Exception^ ex) {
                System::Windows::Forms::MessageBox::Show("Error getting user details: " + ex->Message);
                return nullptr;
            }
        }

        // Get all users of a specific role
        DataTable^ GetUsersByRole(UserRole role) {
            try {
                OleDbConnection^ conn = gcnew OleDbConnection(connectionString);
                OleDbCommand^ cmd = gcnew OleDbCommand("SELECT * FROM Users WHERE Role = ?", conn);
                cmd->Parameters->Add(gcnew OleDbParameter("@p1", (int)role));
                
                OleDbDataAdapter^ adapter = gcnew OleDbDataAdapter(cmd);
                DataTable^ table = gcnew DataTable();
                
                conn->Open();
                adapter->Fill(table);
                conn->Close();
                
                return table;
            }
            catch (Exception^ ex) {
                System::Windows::Forms::MessageBox::Show("Error getting users: " + ex->Message);
                return nullptr;
            }
        }

        // Add new user
        bool AddUser(String^ username, String^ password, String^ name, int age, UserRole role) {
            try {
                // Remove any special characters that might cause SQL issues
                String^ sanitizedName = name->Replace("'", "''");
                String^ sanitizedUsername = username->Replace("'", "''");
                String^ sanitizedPassword = password->Replace("'", "''");
                
                OleDbConnection^ conn = gcnew OleDbConnection(connectionString);
                
                // Use named parameters to be explicit
                String^ sql = "INSERT INTO Users ([Username], [Password], [Name], [Age], [Role]) VALUES (?, ?, ?, ?, ?)";
                OleDbCommand^ cmd = gcnew OleDbCommand(sql, conn);
                
                // Set parameter types explicitly
                OleDbParameter^ p1 = gcnew OleDbParameter("@p1", OleDbType::VarChar);
                p1->Value = sanitizedUsername;
                cmd->Parameters->Add(p1);
                
                OleDbParameter^ p2 = gcnew OleDbParameter("@p2", OleDbType::VarChar);
                p2->Value = sanitizedPassword;
                cmd->Parameters->Add(p2);
                
                OleDbParameter^ p3 = gcnew OleDbParameter("@p3", OleDbType::VarChar);
                p3->Value = sanitizedName;
                cmd->Parameters->Add(p3);
                
                OleDbParameter^ p4 = gcnew OleDbParameter("@p4", OleDbType::Integer);
                p4->Value = age;
                cmd->Parameters->Add(p4);
                
                OleDbParameter^ p5 = gcnew OleDbParameter("@p5", OleDbType::Integer);
                p5->Value = (int)role;
                cmd->Parameters->Add(p5);
                
                conn->Open();
                int result = cmd->ExecuteNonQuery();
                conn->Close();
                
                return result > 0;
            }
            catch (Exception^ ex) {
                System::Windows::Forms::MessageBox::Show("Error adding user: " + ex->Message);
                return false;
            }
        }

        // Get all courses
        DataTable^ GetAllCourses() {
            try {
                OleDbConnection^ conn = gcnew OleDbConnection(connectionString);
                OleDbCommand^ cmd = gcnew OleDbCommand("SELECT * FROM Courses", conn);
                
                OleDbDataAdapter^ adapter = gcnew OleDbDataAdapter(cmd);
                DataTable^ table = gcnew DataTable();
                
                conn->Open();
                adapter->Fill(table);
                conn->Close();
                
                return table;
            }
            catch (Exception^ ex) {
                System::Windows::Forms::MessageBox::Show("Error getting courses: " + ex->Message);
                return nullptr;
            }
        }

        // Add new course
        bool AddCourse(String^ courseName, String^ courseCode) {
            try {
                OleDbConnection^ conn = gcnew OleDbConnection(connectionString);
                OleDbCommand^ cmd = gcnew OleDbCommand(
                    "INSERT INTO Courses (CourseName, CourseCode) VALUES (?, ?)", 
                    conn);
                
                cmd->Parameters->Add(gcnew OleDbParameter("@p1", courseName));
                cmd->Parameters->Add(gcnew OleDbParameter("@p2", courseCode));
                
                conn->Open();
                int result = cmd->ExecuteNonQuery();
                conn->Close();
                
                return result > 0;
            }
            catch (Exception^ ex) {
                System::Windows::Forms::MessageBox::Show("Error adding course: " + ex->Message);
                return false;
            }
        }

        // Assign instructor to course
        bool AssignInstructorToCourse(int instructorId, int courseId) {
            try {
                OleDbConnection^ conn = gcnew OleDbConnection(connectionString);
                OleDbCommand^ cmd = gcnew OleDbCommand(
                    "INSERT INTO InstructorCourses (InstructorID, CourseID) VALUES (?, ?)", 
                    conn);
                
                cmd->Parameters->Add(gcnew OleDbParameter("@p1", instructorId));
                cmd->Parameters->Add(gcnew OleDbParameter("@p2", courseId));
                
                conn->Open();
                int result = cmd->ExecuteNonQuery();
                conn->Close();
                
                return result > 0;
            }
            catch (Exception^ ex) {
                System::Windows::Forms::MessageBox::Show("Error assigning instructor: " + ex->Message);
                return false;
            }
        }

        // Get courses for an instructor
        DataTable^ GetInstructorCourses(int instructorId) {
            try {
                OleDbConnection^ conn = gcnew OleDbConnection(connectionString);
                
                // Create a custom data table with the same structure as Courses table
                DataTable^ table = gcnew DataTable();
                table->Columns->Add("CourseID", int::typeid);
                table->Columns->Add("CourseName", String::typeid);
                table->Columns->Add("CourseCode", String::typeid);
                
                // First, get all course IDs assigned to this instructor
                OleDbCommand^ cmdAssignments = gcnew OleDbCommand(
                    "SELECT CourseID FROM InstructorCourses WHERE InstructorID = ?", 
                    conn);
                cmdAssignments->Parameters->Add(gcnew OleDbParameter("@p1", instructorId));
                
                conn->Open();
                OleDbDataReader^ readerAssignments = cmdAssignments->ExecuteReader();
                
                // Process each assigned course
                while (readerAssignments->Read()) {
                    int courseId = Convert::ToInt32(readerAssignments["CourseID"]);
                    
                    // Get course details
                    OleDbCommand^ cmdCourse = gcnew OleDbCommand(
                        "SELECT CourseID, CourseName, CourseCode FROM Courses WHERE CourseID = ?", 
                        conn);
                    cmdCourse->Parameters->Add(gcnew OleDbParameter("@p1", courseId));
                    
                    OleDbDataReader^ readerCourse = cmdCourse->ExecuteReader();
                    
                    if (readerCourse->Read()) {
                        int id = Convert::ToInt32(readerCourse["CourseID"]);
                        String^ name = readerCourse["CourseName"]->ToString();
                        String^ code = readerCourse["CourseCode"]->ToString();
                        
                        // Add to table
                        table->Rows->Add(id, name, code);
                    }
                    
                    readerCourse->Close();
                }
                
                readerAssignments->Close();
                conn->Close();
                
                return table;
            }
            catch (Exception^ ex) {
                System::Windows::Forms::MessageBox::Show("Error getting instructor courses: " + ex->Message);
                return nullptr;
            }
        }

        // Get students for a course
        DataTable^ GetStudentsForCourse(int courseId) {
            try {
                OleDbConnection^ conn = gcnew OleDbConnection(connectionString);
                
                // Create a custom data table
                DataTable^ table = gcnew DataTable();
                table->Columns->Add("UserID", int::typeid);
                table->Columns->Add("Name", String::typeid);
                table->Columns->Add("Result", double::typeid);
                table->Columns->Add("ResultID", int::typeid);
                
                // First, get all students
                OleDbCommand^ cmdStudents = gcnew OleDbCommand(
                    "SELECT UserID, Name FROM Users WHERE Role = ?", 
                    conn);
                cmdStudents->Parameters->Add(gcnew OleDbParameter("@p1", (int)UserRole::Student));
                
                conn->Open();
                OleDbDataReader^ readerStudents = cmdStudents->ExecuteReader();
                
                // Process each student
                while (readerStudents->Read()) {
                    int studentId = Convert::ToInt32(readerStudents["UserID"]);
                    String^ studentName = readerStudents["Name"]->ToString();
                    
                    // For each student, check if they have a result for this course
                    OleDbCommand^ cmdResult = gcnew OleDbCommand(
                        "SELECT ResultID, Result FROM Results WHERE StudentID = ? AND CourseID = ?", 
                        conn);
                    cmdResult->Parameters->Add(gcnew OleDbParameter("@p1", studentId));
                    cmdResult->Parameters->Add(gcnew OleDbParameter("@p2", courseId));
                    
                    OleDbDataReader^ readerResult = cmdResult->ExecuteReader();
                    
                    if (readerResult->Read()) {
                        // Student has a result for this course
                        int resultId = Convert::ToInt32(readerResult["ResultID"]);
                        double result = Convert::ToDouble(readerResult["Result"]);
                        
                        // Add to table
                        table->Rows->Add(studentId, studentName, result, resultId);
                    } else {
                        // Student has no result for this course
                        table->Rows->Add(studentId, studentName, DBNull::Value, DBNull::Value);
                    }
                    
                    readerResult->Close();
                }
                
                readerStudents->Close();
                conn->Close();
                
                return table;
            }
            catch (Exception^ ex) {
                System::Windows::Forms::MessageBox::Show("Error getting students: " + ex->Message);
                return nullptr;
            }
        }

        // Add or update student result
        bool SaveStudentResult(int studentId, int courseId, double result) {
            try {
                OleDbConnection^ conn = gcnew OleDbConnection(connectionString);
                
                // Check if result already exists
                OleDbCommand^ checkCmd = gcnew OleDbCommand(
                    "SELECT ResultID FROM Results WHERE StudentID = ? AND CourseID = ?", 
                    conn);
                
                checkCmd->Parameters->Add(gcnew OleDbParameter("@p1", studentId));
                checkCmd->Parameters->Add(gcnew OleDbParameter("@p2", courseId));
                
                conn->Open();
                Object^ existingId = checkCmd->ExecuteScalar();
                
                OleDbCommand^ cmd;
                
                if (existingId != nullptr) {
                    // Update existing result
                    cmd = gcnew OleDbCommand(
                        "UPDATE Results SET Result = ? WHERE ResultID = ?", 
                        conn);
                    
                    cmd->Parameters->Add(gcnew OleDbParameter("@p1", result));
                    cmd->Parameters->Add(gcnew OleDbParameter("@p2", Convert::ToInt32(existingId)));
                } else {
                    // Insert new result
                    cmd = gcnew OleDbCommand(
                        "INSERT INTO Results (StudentID, CourseID, Result) VALUES (?, ?, ?)", 
                        conn);
                    
                    cmd->Parameters->Add(gcnew OleDbParameter("@p1", studentId));
                    cmd->Parameters->Add(gcnew OleDbParameter("@p2", courseId));
                    cmd->Parameters->Add(gcnew OleDbParameter("@p3", result));
                }
                
                int result2 = cmd->ExecuteNonQuery();
                conn->Close();
                
                return result2 > 0;
            }
            catch (Exception^ ex) {
                System::Windows::Forms::MessageBox::Show("Error saving result: " + ex->Message);
                return false;
            }
        }

        // Get results for a student
        DataTable^ GetStudentResults(int studentId) {
            try {
                OleDbConnection^ conn = gcnew OleDbConnection(connectionString);
                
                // Create a custom data table
                DataTable^ table = gcnew DataTable();
                table->Columns->Add("CourseName", String::typeid);
                table->Columns->Add("CourseCode", String::typeid);
                table->Columns->Add("Result", double::typeid);
                
                // Get all results for this student
                OleDbCommand^ cmdResults = gcnew OleDbCommand(
                    "SELECT CourseID, Result FROM Results WHERE StudentID = ?", 
                    conn);
                cmdResults->Parameters->Add(gcnew OleDbParameter("@p1", studentId));
                
                conn->Open();
                OleDbDataReader^ readerResults = cmdResults->ExecuteReader();
                
                // Process each result
                while (readerResults->Read()) {
                    int courseId = Convert::ToInt32(readerResults["CourseID"]);
                    double result = Convert::ToDouble(readerResults["Result"]);
                    
                    // Get course details
                    OleDbCommand^ cmdCourse = gcnew OleDbCommand(
                        "SELECT CourseName, CourseCode FROM Courses WHERE CourseID = ?", 
                        conn);
                    cmdCourse->Parameters->Add(gcnew OleDbParameter("@p1", courseId));
                    
                    OleDbDataReader^ readerCourse = cmdCourse->ExecuteReader();
                    
                    if (readerCourse->Read()) {
                        String^ courseName = readerCourse["CourseName"]->ToString();
                        String^ courseCode = readerCourse["CourseCode"]->ToString();
                        
                        // Add to table
                        table->Rows->Add(courseName, courseCode, result);
                    }
                    
                    readerCourse->Close();
                }
                
                readerResults->Close();
                conn->Close();
                
                return table;
            }
            catch (Exception^ ex) {
                System::Windows::Forms::MessageBox::Show("Error getting student results: " + ex->Message);
                return nullptr;
            }
        }
    };
} 