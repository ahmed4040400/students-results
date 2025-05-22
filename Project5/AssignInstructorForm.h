#pragma once
#include "DatabaseHelper.h"

namespace Project5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	// AssignInstructorForm class for assigning instructors to courses
	public ref class AssignInstructorForm : public System::Windows::Forms::Form
	{
	private:
		// Database helper for database operations
		DatabaseHelper^ dbHelper;
		// Course ID to which instructor will be assigned
		int courseId;
		// Course name for display
		String^ courseName;

	public:
		AssignInstructorForm(DatabaseHelper^ helper, int id, String^ name)
		{
			InitializeComponent();
			
			// Store database helper and course details
			dbHelper = helper;
			courseId = id;
			courseName = name;
			
			// Set course name in title
			labelCourseName->Text = courseName;
		}

	protected:
		~AssignInstructorForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ labelFormTitle;
	private: System::Windows::Forms::Label^ labelCourseTitle;
	private: System::Windows::Forms::Label^ labelCourseName;
	private: System::Windows::Forms::Label^ labelSelectInstructor;
	private: System::Windows::Forms::ComboBox^ comboBoxInstructors;
	private: System::Windows::Forms::Button^ buttonAssign;
	private: System::Windows::Forms::Button^ buttonCancel;
	private: System::Windows::Forms::Label^ labelStatus;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->labelFormTitle = (gcnew System::Windows::Forms::Label());
			this->labelCourseTitle = (gcnew System::Windows::Forms::Label());
			this->labelCourseName = (gcnew System::Windows::Forms::Label());
			this->labelSelectInstructor = (gcnew System::Windows::Forms::Label());
			this->comboBoxInstructors = (gcnew System::Windows::Forms::ComboBox());
			this->buttonAssign = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->labelStatus = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// labelFormTitle
			// 
			this->labelFormTitle->AutoSize = true;
			this->labelFormTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelFormTitle->ForeColor = System::Drawing::Color::DodgerBlue;
			this->labelFormTitle->Location = System::Drawing::Point(119, 20);
			this->labelFormTitle->Name = L"labelFormTitle";
			this->labelFormTitle->Size = System::Drawing::Size(164, 25);
			this->labelFormTitle->TabIndex = 0;
			this->labelFormTitle->Text = L"Assign Instructor";
			// 
			// labelCourseTitle
			// 
			this->labelCourseTitle->AutoSize = true;
			this->labelCourseTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelCourseTitle->Location = System::Drawing::Point(30, 70);
			this->labelCourseTitle->Name = L"labelCourseTitle";
			this->labelCourseTitle->Size = System::Drawing::Size(59, 19);
			this->labelCourseTitle->TabIndex = 1;
			this->labelCourseTitle->Text = L"Course:";
			// 
			// labelCourseName
			// 
			this->labelCourseName->AutoSize = true;
			this->labelCourseName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelCourseName->Location = System::Drawing::Point(94, 70);
			this->labelCourseName->Name = L"labelCourseName";
			this->labelCourseName->Size = System::Drawing::Size(92, 19);
			this->labelCourseName->TabIndex = 2;
			this->labelCourseName->Text = L"Course Name";
			// 
			// labelSelectInstructor
			// 
			this->labelSelectInstructor->AutoSize = true;
			this->labelSelectInstructor->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelSelectInstructor->Location = System::Drawing::Point(30, 110);
			this->labelSelectInstructor->Name = L"labelSelectInstructor";
			this->labelSelectInstructor->Size = System::Drawing::Size(122, 19);
			this->labelSelectInstructor->TabIndex = 3;
			this->labelSelectInstructor->Text = L"Select Instructor:";
			// 
			// comboBoxInstructors
			// 
			this->comboBoxInstructors->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxInstructors->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBoxInstructors->FormattingEnabled = true;
			this->comboBoxInstructors->Location = System::Drawing::Point(34, 140);
			this->comboBoxInstructors->Name = L"comboBoxInstructors";
			this->comboBoxInstructors->Size = System::Drawing::Size(320, 25);
			this->comboBoxInstructors->TabIndex = 4;
			this->comboBoxInstructors->SelectedIndexChanged += gcnew System::EventHandler(this, &AssignInstructorForm::comboBoxInstructors_SelectedIndexChanged);
			// 
			// buttonAssign
			// 
			this->buttonAssign->BackColor = System::Drawing::Color::DodgerBlue;
			this->buttonAssign->FlatAppearance->BorderSize = 0;
			this->buttonAssign->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonAssign->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonAssign->ForeColor = System::Drawing::Color::White;
			this->buttonAssign->Location = System::Drawing::Point(125, 185);
			this->buttonAssign->Name = L"buttonAssign";
			this->buttonAssign->Size = System::Drawing::Size(100, 30);
			this->buttonAssign->TabIndex = 5;
			this->buttonAssign->Text = L"Assign";
			this->buttonAssign->UseVisualStyleBackColor = false;
			this->buttonAssign->Click += gcnew System::EventHandler(this, &AssignInstructorForm::buttonAssign_Click);
			// 
			// buttonCancel
			// 
			this->buttonCancel->BackColor = System::Drawing::Color::Silver;
			this->buttonCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->buttonCancel->FlatAppearance->BorderSize = 0;
			this->buttonCancel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonCancel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonCancel->ForeColor = System::Drawing::Color::White;
			this->buttonCancel->Location = System::Drawing::Point(235, 185);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(90, 30);
			this->buttonCancel->TabIndex = 6;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = false;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &AssignInstructorForm::buttonCancel_Click);
			// 
			// labelStatus
			// 
			this->labelStatus->AutoSize = true;
			this->labelStatus->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelStatus->ForeColor = System::Drawing::Color::Red;
			this->labelStatus->Location = System::Drawing::Point(125, 220);
			this->labelStatus->Name = L"labelStatus";
			this->labelStatus->Size = System::Drawing::Size(0, 15);
			this->labelStatus->TabIndex = 7;
			// 
			// AssignInstructorForm
			// 
			this->AcceptButton = this->buttonAssign;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->CancelButton = this->buttonCancel;
			this->ClientSize = System::Drawing::Size(384, 250);
			this->Controls->Add(this->labelStatus);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->buttonAssign);
			this->Controls->Add(this->comboBoxInstructors);
			this->Controls->Add(this->labelSelectInstructor);
			this->Controls->Add(this->labelCourseName);
			this->Controls->Add(this->labelCourseTitle);
			this->Controls->Add(this->labelFormTitle);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"AssignInstructorForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Assign Instructor to Course";
			this->Load += gcnew System::EventHandler(this, &AssignInstructorForm::AssignInstructorForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void AssignInstructorForm_Load(System::Object^ sender, System::EventArgs^ e) {
		// Load instructors into combo box
		LoadInstructors();
	}

	private: System::Void buttonAssign_Click(System::Object^ sender, System::EventArgs^ e) {
		// Check if an instructor is selected
		if (comboBoxInstructors->SelectedIndex == -1) {
			labelStatus->Text = "Please select an instructor";
			return;
		}

		// Get selected instructor ID from tag
		int instructorId = Convert::ToInt32(comboBoxInstructors->SelectedValue);

		// Assign instructor to course
		bool success = dbHelper->AssignInstructorToCourse(instructorId, courseId);

		if (success) {
			// Close the form
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		} else {
			labelStatus->Text = "Failed to assign instructor. Please try again.";
		}
	}

	private: System::Void buttonCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		// Close the form
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
		this->Close();
	}

	// Load instructors into combo box
	private: void LoadInstructors() {
		DataTable^ instructors = dbHelper->GetUsersByRole(UserRole::Instructor);
		
		if (instructors != nullptr && instructors->Rows->Count > 0) {
			// Setup data source for combo box
			DataTable^ instructorTable = gcnew DataTable();
			instructorTable->Columns->Add("InstructorID", int::typeid);
			instructorTable->Columns->Add("InstructorName", String::typeid);
			
			// Fill table with instructor data
			for each (DataRow^ row in instructors->Rows) {
				instructorTable->Rows->Add(
					row["UserID"],
					row["Name"]->ToString()
				);
			}
			
			// Set up combo box
			comboBoxInstructors->DataSource = instructorTable;
			comboBoxInstructors->DisplayMember = "InstructorName";
			comboBoxInstructors->ValueMember = "InstructorID";
		}
	}
	private: System::Void comboBoxInstructors_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
} 