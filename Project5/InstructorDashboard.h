#pragma once
#include "DatabaseHelper.h"
#include "AssignResultForm.h"

namespace Project5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	// InstructorDashboard class for instructor-specific operations
	public ref class InstructorDashboard : public System::Windows::Forms::Form
	{
	private:
		// Database helper for database operations
		DatabaseHelper^ dbHelper;
		// Current instructor user ID
		int userId;
		// Instructor name to display
		String^ instructorName;

	public:
		InstructorDashboard(int id, DatabaseHelper^ helper)
		{
			InitializeComponent();
			
			// Store user ID and database helper
			userId = id;
			dbHelper = helper;
			
			// Get instructor details
			DataRow^ instructorDetails = dbHelper->GetUserDetails(userId);
			if (instructorDetails != nullptr) {
				instructorName = instructorDetails["Name"]->ToString();
				labelWelcome->Text = "Welcome, " + instructorName + "!";
			}
		}

	protected:
		~InstructorDashboard()
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
	private: System::Windows::Forms::ComboBox^ comboBoxCourses;
	private: System::Windows::Forms::Label^ labelCourses;
	private: System::Windows::Forms::DataGridView^ dataGridViewStudents;
	private: System::Windows::Forms::Button^ buttonAssignResult;
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
			this->buttonRefresh = (gcnew System::Windows::Forms::Button());
			this->buttonAssignResult = (gcnew System::Windows::Forms::Button());
			this->dataGridViewStudents = (gcnew System::Windows::Forms::DataGridView());
			this->labelCourses = (gcnew System::Windows::Forms::Label());
			this->comboBoxCourses = (gcnew System::Windows::Forms::ComboBox());
			this->panelTop->SuspendLayout();
			this->panelMain->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewStudents))->BeginInit();
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
			this->buttonLogout->Click += gcnew System::EventHandler(this, &InstructorDashboard::buttonLogout_Click);
			// 
			// labelWelcome
			// 
			this->labelWelcome->AutoSize = true;
			this->labelWelcome->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelWelcome->ForeColor = System::Drawing::Color::White;
			this->labelWelcome->Location = System::Drawing::Point(242, 20);
			this->labelWelcome->Name = L"labelWelcome";
			this->labelWelcome->Size = System::Drawing::Size(97, 19);
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
			this->labelTitle->Size = System::Drawing::Size(212, 25);
			this->labelTitle->TabIndex = 0;
			this->labelTitle->Text = L"Instructor Dashboard";
			// 
			// panelMain
			// 
			this->panelMain->BackColor = System::Drawing::Color::WhiteSmoke;
			this->panelMain->Controls->Add(this->buttonRefresh);
			this->panelMain->Controls->Add(this->buttonAssignResult);
			this->panelMain->Controls->Add(this->dataGridViewStudents);
			this->panelMain->Controls->Add(this->labelCourses);
			this->panelMain->Controls->Add(this->comboBoxCourses);
			this->panelMain->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelMain->Location = System::Drawing::Point(0, 60);
			this->panelMain->Name = L"panelMain";
			this->panelMain->Padding = System::Windows::Forms::Padding(20);
			this->panelMain->Size = System::Drawing::Size(800, 440);
			this->panelMain->TabIndex = 1;
			// 
			// buttonRefresh
			// 
			this->buttonRefresh->BackColor = System::Drawing::Color::LightSeaGreen;
			this->buttonRefresh->FlatAppearance->BorderSize = 0;
			this->buttonRefresh->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonRefresh->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonRefresh->ForeColor = System::Drawing::Color::White;
			this->buttonRefresh->Location = System::Drawing::Point(439, 49);
			this->buttonRefresh->Name = L"buttonRefresh";
			this->buttonRefresh->Size = System::Drawing::Size(100, 30);
			this->buttonRefresh->TabIndex = 5;
			this->buttonRefresh->Text = L"Refresh";
			this->buttonRefresh->UseVisualStyleBackColor = false;
			this->buttonRefresh->Click += gcnew System::EventHandler(this, &InstructorDashboard::buttonRefresh_Click);
			// 
			// buttonAssignResult
			// 
			this->buttonAssignResult->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->buttonAssignResult->BackColor = System::Drawing::Color::DodgerBlue;
			this->buttonAssignResult->FlatAppearance->BorderSize = 0;
			this->buttonAssignResult->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonAssignResult->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonAssignResult->ForeColor = System::Drawing::Color::White;
			this->buttonAssignResult->Location = System::Drawing::Point(545, 49);
			this->buttonAssignResult->Name = L"buttonAssignResult";
			this->buttonAssignResult->Size = System::Drawing::Size(110, 30);
			this->buttonAssignResult->TabIndex = 4;
			this->buttonAssignResult->Text = L"Assign Result";
			this->buttonAssignResult->UseVisualStyleBackColor = false;
			this->buttonAssignResult->Click += gcnew System::EventHandler(this, &InstructorDashboard::buttonAssignResult_Click);
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
			this->dataGridViewStudents->Location = System::Drawing::Point(20, 90);
			this->dataGridViewStudents->Name = L"dataGridViewStudents";
			this->dataGridViewStudents->ReadOnly = true;
			this->dataGridViewStudents->RowHeadersWidth = 51;
			this->dataGridViewStudents->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridViewStudents->Size = System::Drawing::Size(760, 330);
			this->dataGridViewStudents->TabIndex = 3;
			// 
			// labelCourses
			// 
			this->labelCourses->AutoSize = true;
			this->labelCourses->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelCourses->Location = System::Drawing::Point(23, 52);
			this->labelCourses->Name = L"labelCourses";
			this->labelCourses->Size = System::Drawing::Size(112, 20);
			this->labelCourses->TabIndex = 2;
			this->labelCourses->Text = L"Select a Course:";
			// 
			// comboBoxCourses
			// 
			this->comboBoxCourses->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxCourses->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBoxCourses->FormattingEnabled = true;
			this->comboBoxCourses->Location = System::Drawing::Point(141, 49);
			this->comboBoxCourses->Name = L"comboBoxCourses";
			this->comboBoxCourses->Size = System::Drawing::Size(270, 28);
			this->comboBoxCourses->TabIndex = 0;
			this->comboBoxCourses->SelectedIndexChanged += gcnew System::EventHandler(this, &InstructorDashboard::comboBoxCourses_SelectedIndexChanged);
			// 
			// InstructorDashboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(800, 500);
			this->Controls->Add(this->panelMain);
			this->Controls->Add(this->panelTop);
			this->Name = L"InstructorDashboard";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Instructor Dashboard - Student Results App";
			this->Load += gcnew System::EventHandler(this, &InstructorDashboard::InstructorDashboard_Load);
			this->panelTop->ResumeLayout(false);
			this->panelTop->PerformLayout();
			this->panelMain->ResumeLayout(false);
			this->panelMain->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewStudents))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void InstructorDashboard_Load(System::Object^ sender, System::EventArgs^ e) {
		// Load instructor's courses
		LoadCourses();
	}

	private: System::Void comboBoxCourses_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		// When a course is selected, load students for that course
		if (comboBoxCourses->SelectedIndex != -1) {
			// Get selected course ID from tag
			int courseId = Convert::ToInt32(comboBoxCourses->SelectedItem->ToString()->Split(' ')[0]);
			LoadStudentsForCourse(courseId);
		}
	}

	private: System::Void buttonRefresh_Click(System::Object^ sender, System::EventArgs^ e) {
		// Refresh data
		if (comboBoxCourses->SelectedIndex != -1) {
			int courseId = Convert::ToInt32(comboBoxCourses->SelectedItem->ToString()->Split(' ')[0]);
			LoadStudentsForCourse(courseId);
		}
	}

	private: System::Void buttonAssignResult_Click(System::Object^ sender, System::EventArgs^ e) {
		// Check if a course is selected
		if (comboBoxCourses->SelectedIndex == -1) {
			MessageBox::Show("Please select a course first", "No Course Selected", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		// Check if a student is selected
		if (dataGridViewStudents->SelectedRows->Count == 0) {
			MessageBox::Show("Please select a student first", "No Student Selected", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		// Get course and student IDs
		int courseId = Convert::ToInt32(comboBoxCourses->SelectedItem->ToString()->Split(' ')[0]);
		String^ courseName = comboBoxCourses->SelectedItem->ToString()->Substring(comboBoxCourses->SelectedItem->ToString()->IndexOf(" - ") + 3);
		int studentId = Convert::ToInt32(dataGridViewStudents->SelectedRows[0]->Cells["UserID"]->Value);
		String^ studentName = dataGridViewStudents->SelectedRows[0]->Cells["Name"]->Value->ToString();
		double currentResult = 0;

		// If result already exists, get current value
		if (dataGridViewStudents->SelectedRows[0]->Cells["Result"]->Value != DBNull::Value) {
			currentResult = Convert::ToDouble(dataGridViewStudents->SelectedRows[0]->Cells["Result"]->Value);
		}

		// Show assign result form
		AssignResultForm^ assignResultForm = gcnew AssignResultForm(dbHelper, courseId, courseName, studentId, studentName, currentResult);
		assignResultForm->FormClosed += gcnew FormClosedEventHandler(this, &InstructorDashboard::assignResultForm_FormClosed);
		assignResultForm->ShowDialog();
	}

	private: System::Void buttonLogout_Click(System::Object^ sender, System::EventArgs^ e) {
		// Close this form - will return to login
		this->Close();
	}

	private: System::Void assignResultForm_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
		// Refresh student data after assigning result
		if (comboBoxCourses->SelectedIndex != -1) {
			int courseId = Convert::ToInt32(comboBoxCourses->SelectedItem->ToString()->Split(' ')[0]);
			LoadStudentsForCourse(courseId);
		}
	}

	// Load instructor's courses into combo box
	private: void LoadCourses() {
		DataTable^ courses = dbHelper->GetInstructorCourses(userId);
		
		if (courses != nullptr && courses->Rows->Count > 0) {
			comboBoxCourses->Items->Clear();
			
			for each (DataRow^ row in courses->Rows) {
				// Format: "CourseID - CourseName (CourseCode)"
				String^ courseText = row["CourseID"]->ToString() + " - " + 
					row["CourseName"]->ToString() + " (" + row["CourseCode"]->ToString() + ")";
				comboBoxCourses->Items->Add(courseText);
			}
			
			// Select first course by default
			if (comboBoxCourses->Items->Count > 0) {
				comboBoxCourses->SelectedIndex = 0;
			}
		}
	}

	// Load students for selected course
	private: void LoadStudentsForCourse(int courseId) {
		DataTable^ students = dbHelper->GetStudentsForCourse(courseId);
		dataGridViewStudents->DataSource = students;
	}
	};
} 