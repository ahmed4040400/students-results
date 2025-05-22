#pragma once
#include "DatabaseHelper.h"
#include "AddUserForm.h"
#include "AddCourseForm.h"
#include "AssignInstructorForm.h"

namespace Project5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	// AdminDashboard class for admin-specific operations
	public ref class AdminDashboard : public System::Windows::Forms::Form
	{
	private:
		// Database helper for database operations
		DatabaseHelper^ dbHelper;
		// Current admin user ID
		int userId;
		// Admin name to display
		String^ adminName;

	public:
		AdminDashboard(int id, DatabaseHelper^ helper)
		{
			InitializeComponent();
			
			// Store user ID and database helper
			userId = id;
			dbHelper = helper;
			
			// Get admin details
			DataRow^ adminDetails = dbHelper->GetUserDetails(userId);
			if (adminDetails != nullptr) {
				adminName = adminDetails["Name"]->ToString();
				labelWelcome->Text = "Welcome, " + adminName + "!";
			}
		}

	protected:
		~AdminDashboard()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Panel^ panelTop;
	private: System::Windows::Forms::Label^ labelWelcome;
	private: System::Windows::Forms::Label^ labelTitle;
	private: System::Windows::Forms::Button^ buttonLogout;
	private: System::Windows::Forms::Panel^ panelMain;
	private: System::Windows::Forms::TabControl^ tabControlMain;
	private: System::Windows::Forms::TabPage^ tabPageInstructors;
	private: System::Windows::Forms::TabPage^ tabPageStudents;
	private: System::Windows::Forms::TabPage^ tabPageCourses;
	private: System::Windows::Forms::Button^ buttonAddInstructor;
	private: System::Windows::Forms::DataGridView^ dataGridViewInstructors;
	private: System::Windows::Forms::Button^ buttonAddStudent;
	private: System::Windows::Forms::DataGridView^ dataGridViewStudents;
	private: System::Windows::Forms::Button^ buttonAddCourse;
	private: System::Windows::Forms::DataGridView^ dataGridViewCourses;
	private: System::Windows::Forms::Button^ buttonAssignInstructor;
	private: System::Windows::Forms::Button^ buttonRefresh;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->panelTop = (gcnew System::Windows::Forms::Panel());
			this->buttonLogout = (gcnew System::Windows::Forms::Button());
			this->labelWelcome = (gcnew System::Windows::Forms::Label());
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->panelMain = (gcnew System::Windows::Forms::Panel());
			this->tabControlMain = (gcnew System::Windows::Forms::TabControl());
			this->tabPageInstructors = (gcnew System::Windows::Forms::TabPage());
			this->buttonRefresh = (gcnew System::Windows::Forms::Button());
			this->buttonAddInstructor = (gcnew System::Windows::Forms::Button());
			this->dataGridViewInstructors = (gcnew System::Windows::Forms::DataGridView());
			this->tabPageStudents = (gcnew System::Windows::Forms::TabPage());
			this->buttonAddStudent = (gcnew System::Windows::Forms::Button());
			this->dataGridViewStudents = (gcnew System::Windows::Forms::DataGridView());
			this->tabPageCourses = (gcnew System::Windows::Forms::TabPage());
			this->buttonAssignInstructor = (gcnew System::Windows::Forms::Button());
			this->buttonAddCourse = (gcnew System::Windows::Forms::Button());
			this->dataGridViewCourses = (gcnew System::Windows::Forms::DataGridView());
			this->panelTop->SuspendLayout();
			this->panelMain->SuspendLayout();
			this->tabControlMain->SuspendLayout();
			this->tabPageInstructors->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewInstructors))->BeginInit();
			this->tabPageStudents->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewStudents))->BeginInit();
			this->tabPageCourses->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewCourses))->BeginInit();
			this->SuspendLayout();
			// 
			// panelTop
			// 
			this->panelTop->BackColor = System::Drawing::Color::DodgerBlue;
			this->panelTop->Controls->Add(this->buttonLogout);
			this->panelTop->Controls->Add(this->labelWelcome);
			this->panelTop->Controls->Add(this->labelTitle);
			this->panelTop->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelTop->Location = System::Drawing::Point(0, 0);
			this->panelTop->Name = L"panelTop";
			this->panelTop->Size = System::Drawing::Size(800, 60);
			this->panelTop->TabIndex = 0;
			// 
			// buttonLogout
			// 
			this->buttonLogout->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->buttonLogout->BackColor = System::Drawing::Color::White;
			this->buttonLogout->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonLogout->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonLogout->ForeColor = System::Drawing::Color::DodgerBlue;
			this->buttonLogout->Location = System::Drawing::Point(713, 15);
			this->buttonLogout->Name = L"buttonLogout";
			this->buttonLogout->Size = System::Drawing::Size(75, 30);
			this->buttonLogout->TabIndex = 2;
			this->buttonLogout->Text = L"Logout";
			this->buttonLogout->UseVisualStyleBackColor = false;
			this->buttonLogout->Click += gcnew System::EventHandler(this, &AdminDashboard::buttonLogout_Click);
			// 
			// labelWelcome
			// 
			this->labelWelcome->AutoSize = true;
			this->labelWelcome->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelWelcome->ForeColor = System::Drawing::Color::White;
			this->labelWelcome->Location = System::Drawing::Point(223, 20);
			this->labelWelcome->Name = L"labelWelcome";
			this->labelWelcome->Size = System::Drawing::Size(99, 19);
			this->labelWelcome->TabIndex = 1;
			this->labelWelcome->Text = L"Welcome, User";
			// 
			// labelTitle
			// 
			this->labelTitle->AutoSize = true;
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTitle->ForeColor = System::Drawing::Color::White;
			this->labelTitle->Location = System::Drawing::Point(12, 15);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(173, 25);
			this->labelTitle->TabIndex = 0;
			this->labelTitle->Text = L"Admin Dashboard";
			// 
			// panelMain
			// 
			this->panelMain->BackColor = System::Drawing::Color::WhiteSmoke;
			this->panelMain->Controls->Add(this->tabControlMain);
			this->panelMain->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelMain->Location = System::Drawing::Point(0, 60);
			this->panelMain->Name = L"panelMain";
			this->panelMain->Padding = System::Windows::Forms::Padding(20);
			this->panelMain->Size = System::Drawing::Size(800, 440);
			this->panelMain->TabIndex = 1;
			// 
			// tabControlMain
			// 
			this->tabControlMain->Controls->Add(this->tabPageInstructors);
			this->tabControlMain->Controls->Add(this->tabPageStudents);
			this->tabControlMain->Controls->Add(this->tabPageCourses);
			this->tabControlMain->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControlMain->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tabControlMain->Location = System::Drawing::Point(20, 20);
			this->tabControlMain->Name = L"tabControlMain";
			this->tabControlMain->SelectedIndex = 0;
			this->tabControlMain->Size = System::Drawing::Size(760, 400);
			this->tabControlMain->TabIndex = 0;
			this->tabControlMain->SelectedIndexChanged += gcnew System::EventHandler(this, &AdminDashboard::tabControlMain_SelectedIndexChanged);
			// 
			// tabPageInstructors
			// 
			this->tabPageInstructors->Controls->Add(this->buttonRefresh);
			this->tabPageInstructors->Controls->Add(this->buttonAddInstructor);
			this->tabPageInstructors->Controls->Add(this->dataGridViewInstructors);
			this->tabPageInstructors->Location = System::Drawing::Point(4, 26);
			this->tabPageInstructors->Name = L"tabPageInstructors";
			this->tabPageInstructors->Padding = System::Windows::Forms::Padding(10);
			this->tabPageInstructors->Size = System::Drawing::Size(752, 370);
			this->tabPageInstructors->TabIndex = 0;
			this->tabPageInstructors->Text = L"Instructors";
			this->tabPageInstructors->UseVisualStyleBackColor = true;
			// 
			// buttonRefresh
			// 
			this->buttonRefresh->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->buttonRefresh->BackColor = System::Drawing::Color::LightSeaGreen;
			this->buttonRefresh->FlatAppearance->BorderSize = 0;
			this->buttonRefresh->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonRefresh->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonRefresh->ForeColor = System::Drawing::Color::White;
			this->buttonRefresh->Location = System::Drawing::Point(516, 10);
			this->buttonRefresh->Name = L"buttonRefresh";
			this->buttonRefresh->Size = System::Drawing::Size(100, 30);
			this->buttonRefresh->TabIndex = 2;
			this->buttonRefresh->Text = L"Refresh";
			this->buttonRefresh->UseVisualStyleBackColor = false;
			this->buttonRefresh->Click += gcnew System::EventHandler(this, &AdminDashboard::buttonRefresh_Click);
			// 
			// buttonAddInstructor
			// 
			this->buttonAddInstructor->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->buttonAddInstructor->BackColor = System::Drawing::Color::DodgerBlue;
			this->buttonAddInstructor->FlatAppearance->BorderSize = 0;
			this->buttonAddInstructor->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonAddInstructor->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonAddInstructor->ForeColor = System::Drawing::Color::White;
			this->buttonAddInstructor->Location = System::Drawing::Point(632, 10);
			this->buttonAddInstructor->Name = L"buttonAddInstructor";
			this->buttonAddInstructor->Size = System::Drawing::Size(110, 30);
			this->buttonAddInstructor->TabIndex = 1;
			this->buttonAddInstructor->Text = L"Add Instructor";
			this->buttonAddInstructor->UseVisualStyleBackColor = false;
			this->buttonAddInstructor->Click += gcnew System::EventHandler(this, &AdminDashboard::buttonAddInstructor_Click);
			// 
			// dataGridViewInstructors
			// 
			this->dataGridViewInstructors->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridViewInstructors->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewInstructors->BackgroundColor = System::Drawing::Color::White;
			this->dataGridViewInstructors->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridViewInstructors->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewInstructors->Location = System::Drawing::Point(10, 50);
			this->dataGridViewInstructors->Name = L"dataGridViewInstructors";
			this->dataGridViewInstructors->ReadOnly = true;
			this->dataGridViewInstructors->RowHeadersWidth = 51;
			this->dataGridViewInstructors->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridViewInstructors->Size = System::Drawing::Size(732, 308);
			this->dataGridViewInstructors->TabIndex = 0;
			this->dataGridViewInstructors->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &AdminDashboard::dataGridViewInstructors_CellContentClick);
			// 
			// tabPageStudents
			// 
			this->tabPageStudents->Controls->Add(this->buttonAddStudent);
			this->tabPageStudents->Controls->Add(this->dataGridViewStudents);
			this->tabPageStudents->Location = System::Drawing::Point(4, 26);
			this->tabPageStudents->Name = L"tabPageStudents";
			this->tabPageStudents->Padding = System::Windows::Forms::Padding(10);
			this->tabPageStudents->Size = System::Drawing::Size(752, 370);
			this->tabPageStudents->TabIndex = 1;
			this->tabPageStudents->Text = L"Students";
			this->tabPageStudents->UseVisualStyleBackColor = true;
			// 
			// buttonAddStudent
			// 
			this->buttonAddStudent->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->buttonAddStudent->BackColor = System::Drawing::Color::DodgerBlue;
			this->buttonAddStudent->FlatAppearance->BorderSize = 0;
			this->buttonAddStudent->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonAddStudent->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonAddStudent->ForeColor = System::Drawing::Color::White;
			this->buttonAddStudent->Location = System::Drawing::Point(632, 10);
			this->buttonAddStudent->Name = L"buttonAddStudent";
			this->buttonAddStudent->Size = System::Drawing::Size(110, 30);
			this->buttonAddStudent->TabIndex = 3;
			this->buttonAddStudent->Text = L"Add Student";
			this->buttonAddStudent->UseVisualStyleBackColor = false;
			this->buttonAddStudent->Click += gcnew System::EventHandler(this, &AdminDashboard::buttonAddStudent_Click);
			// 
			// dataGridViewStudents
			// 
			this->dataGridViewStudents->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridViewStudents->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewStudents->BackgroundColor = System::Drawing::Color::White;
			this->dataGridViewStudents->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridViewStudents->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewStudents->Location = System::Drawing::Point(10, 50);
			this->dataGridViewStudents->Name = L"dataGridViewStudents";
			this->dataGridViewStudents->ReadOnly = true;
			this->dataGridViewStudents->RowHeadersWidth = 51;
			this->dataGridViewStudents->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridViewStudents->Size = System::Drawing::Size(732, 308);
			this->dataGridViewStudents->TabIndex = 2;
			this->dataGridViewStudents->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &AdminDashboard::dataGridViewStudents_CellContentClick);
			// 
			// tabPageCourses
			// 
			this->tabPageCourses->Controls->Add(this->buttonAssignInstructor);
			this->tabPageCourses->Controls->Add(this->buttonAddCourse);
			this->tabPageCourses->Controls->Add(this->dataGridViewCourses);
			this->tabPageCourses->Location = System::Drawing::Point(4, 26);
			this->tabPageCourses->Name = L"tabPageCourses";
			this->tabPageCourses->Padding = System::Windows::Forms::Padding(10);
			this->tabPageCourses->Size = System::Drawing::Size(752, 370);
			this->tabPageCourses->TabIndex = 2;
			this->tabPageCourses->Text = L"Courses";
			this->tabPageCourses->UseVisualStyleBackColor = true;
			// 
			// buttonAssignInstructor
			// 
			this->buttonAssignInstructor->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->buttonAssignInstructor->BackColor = System::Drawing::Color::LightSeaGreen;
			this->buttonAssignInstructor->FlatAppearance->BorderSize = 0;
			this->buttonAssignInstructor->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonAssignInstructor->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonAssignInstructor->ForeColor = System::Drawing::Color::White;
			this->buttonAssignInstructor->Location = System::Drawing::Point(496, 10);
			this->buttonAssignInstructor->Name = L"buttonAssignInstructor";
			this->buttonAssignInstructor->Size = System::Drawing::Size(130, 30);
			this->buttonAssignInstructor->TabIndex = 5;
			this->buttonAssignInstructor->Text = L"Assign Instructor";
			this->buttonAssignInstructor->UseVisualStyleBackColor = false;
			this->buttonAssignInstructor->Click += gcnew System::EventHandler(this, &AdminDashboard::buttonAssignInstructor_Click);
			// 
			// buttonAddCourse
			// 
			this->buttonAddCourse->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->buttonAddCourse->BackColor = System::Drawing::Color::DodgerBlue;
			this->buttonAddCourse->FlatAppearance->BorderSize = 0;
			this->buttonAddCourse->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonAddCourse->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonAddCourse->ForeColor = System::Drawing::Color::White;
			this->buttonAddCourse->Location = System::Drawing::Point(632, 10);
			this->buttonAddCourse->Name = L"buttonAddCourse";
			this->buttonAddCourse->Size = System::Drawing::Size(110, 30);
			this->buttonAddCourse->TabIndex = 4;
			this->buttonAddCourse->Text = L"Add Course";
			this->buttonAddCourse->UseVisualStyleBackColor = false;
			this->buttonAddCourse->Click += gcnew System::EventHandler(this, &AdminDashboard::buttonAddCourse_Click);
			// 
			// dataGridViewCourses
			// 
			this->dataGridViewCourses->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridViewCourses->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewCourses->BackgroundColor = System::Drawing::Color::White;
			this->dataGridViewCourses->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridViewCourses->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewCourses->Location = System::Drawing::Point(10, 50);
			this->dataGridViewCourses->Name = L"dataGridViewCourses";
			this->dataGridViewCourses->ReadOnly = true;
			this->dataGridViewCourses->RowHeadersWidth = 51;
			this->dataGridViewCourses->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridViewCourses->Size = System::Drawing::Size(732, 308);
			this->dataGridViewCourses->TabIndex = 3;
			// 
			// AdminDashboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(800, 500);
			this->Controls->Add(this->panelMain);
			this->Controls->Add(this->panelTop);
			this->Name = L"AdminDashboard";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Admin Dashboard - Student Results App";
			this->Load += gcnew System::EventHandler(this, &AdminDashboard::AdminDashboard_Load);
			this->panelTop->ResumeLayout(false);
			this->panelTop->PerformLayout();
			this->panelMain->ResumeLayout(false);
			this->tabControlMain->ResumeLayout(false);
			this->tabPageInstructors->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewInstructors))->EndInit();
			this->tabPageStudents->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewStudents))->EndInit();
			this->tabPageCourses->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewCourses))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void AdminDashboard_Load(System::Object^ sender, System::EventArgs^ e) {
		// Load data on form load
		LoadInstructors();
	}

	private: System::Void tabControlMain_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		// Load data based on selected tab
		if (tabControlMain->SelectedIndex == 0) {
			// Instructors tab
			LoadInstructors();
		}
		else if (tabControlMain->SelectedIndex == 1) {
			// Students tab
			LoadStudents();
		}
		else if (tabControlMain->SelectedIndex == 2) {
			// Courses tab
			LoadCourses();
		}
	}

	private: System::Void buttonRefresh_Click(System::Object^ sender, System::EventArgs^ e) {
		// Refresh data in current tab
		if (tabControlMain->SelectedIndex == 0) {
			LoadInstructors();
		}
		else if (tabControlMain->SelectedIndex == 1) {
			LoadStudents();
		}
		else if (tabControlMain->SelectedIndex == 2) {
			LoadCourses();
		}
	}

	private: System::Void buttonAddInstructor_Click(System::Object^ sender, System::EventArgs^ e) {
		// Show add instructor form
		AddUserForm^ addInstructorForm = gcnew AddUserForm(dbHelper, UserRole::Instructor);
		addInstructorForm->FormClosed += gcnew FormClosedEventHandler(this, &AdminDashboard::addForm_FormClosed);
		addInstructorForm->ShowDialog();
	}

	private: System::Void buttonAddStudent_Click(System::Object^ sender, System::EventArgs^ e) {
		// Show add student form
		AddUserForm^ addStudentForm = gcnew AddUserForm(dbHelper, UserRole::Student);
		addStudentForm->FormClosed += gcnew FormClosedEventHandler(this, &AdminDashboard::addForm_FormClosed);
		addStudentForm->ShowDialog();
	}

	private: System::Void buttonAddCourse_Click(System::Object^ sender, System::EventArgs^ e) {
		// Show add course form
		AddCourseForm^ addCourseForm = gcnew AddCourseForm(dbHelper);
		addCourseForm->FormClosed += gcnew FormClosedEventHandler(this, &AdminDashboard::addForm_FormClosed);
		addCourseForm->ShowDialog();
	}

	private: System::Void buttonAssignInstructor_Click(System::Object^ sender, System::EventArgs^ e) {
		// Check if a course is selected
		if (dataGridViewCourses->SelectedRows->Count == 0) {
			MessageBox::Show("Please select a course first", "No Course Selected", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		// Get selected course ID
		int courseId = Convert::ToInt32(dataGridViewCourses->SelectedRows[0]->Cells["CourseID"]->Value);
		String^ courseName = dataGridViewCourses->SelectedRows[0]->Cells["CourseName"]->Value->ToString();

		// Show assign instructor form
		AssignInstructorForm^ assignForm = gcnew AssignInstructorForm(dbHelper, courseId, courseName);
		assignForm->FormClosed += gcnew FormClosedEventHandler(this, &AdminDashboard::addForm_FormClosed);
		assignForm->ShowDialog();
	}

	private: System::Void buttonLogout_Click(System::Object^ sender, System::EventArgs^ e) {
		// Close this form - will return to login
		this->Close();
	}

	private: System::Void addForm_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
		// Refresh data after add form is closed
		if (tabControlMain->SelectedIndex == 0) {
			LoadInstructors();
		}
		else if (tabControlMain->SelectedIndex == 1) {
			LoadStudents();
		}
		else if (tabControlMain->SelectedIndex == 2) {
			LoadCourses();
		}
	}

	// Loads instructor data
	private: void LoadInstructors() {
		DataTable^ instructors = dbHelper->GetUsersByRole(UserRole::Instructor);
		
		// Filter columns to display
		if (instructors != nullptr && instructors->Rows->Count > 0) {
			// Create a new DataTable with only the columns we want to display
			DataTable^ filteredTable = gcnew DataTable();
			filteredTable->Columns->Add("UserID", int::typeid);
			filteredTable->Columns->Add("Name", String::typeid);
			filteredTable->Columns->Add("Username", String::typeid);
			filteredTable->Columns->Add("Age", int::typeid);
			
			// Copy data from original table to filtered table
			for each (DataRow^ row in instructors->Rows) {
				filteredTable->Rows->Add(
					row["UserID"],
					row["Name"],
					row["Username"],
					row["Age"]
				);
			}
			
			dataGridViewInstructors->DataSource = filteredTable;
		} else {
			dataGridViewInstructors->DataSource = nullptr;
		}
	}

	// Loads student data
	private: void LoadStudents() {
		DataTable^ students = dbHelper->GetUsersByRole(UserRole::Student);
		
		// Filter columns to display
		if (students != nullptr && students->Rows->Count > 0) {
			// Create a new DataTable with only the columns we want to display
			DataTable^ filteredTable = gcnew DataTable();
			filteredTable->Columns->Add("UserID", int::typeid);
			filteredTable->Columns->Add("Name", String::typeid);
			filteredTable->Columns->Add("Username", String::typeid);
			filteredTable->Columns->Add("Age", int::typeid);
			
			// Copy data from original table to filtered table
			for each (DataRow^ row in students->Rows) {
				filteredTable->Rows->Add(
					row["UserID"],
					row["Name"],
					row["Username"],
					row["Age"]
				);
			}
			
			dataGridViewStudents->DataSource = filteredTable;
		} else {
			dataGridViewStudents->DataSource = nullptr;
		}
	}

	// Loads course data
	private: void LoadCourses() {
		DataTable^ courses = dbHelper->GetAllCourses();
		dataGridViewCourses->DataSource = courses;
	}
	private: System::Void dataGridViewInstructors_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
private: System::Void dataGridViewStudents_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
};
} 