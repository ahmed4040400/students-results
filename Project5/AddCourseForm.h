#pragma once
#include "DatabaseHelper.h"

namespace Project5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	// AddCourseForm class for adding new courses
	public ref class AddCourseForm : public System::Windows::Forms::Form
	{
	private:
		// Database helper for database operations
		DatabaseHelper^ dbHelper;

	public:
		AddCourseForm(DatabaseHelper^ helper)
		{
			InitializeComponent();
			
			// Store database helper
			dbHelper = helper;
		}

	protected:
		~AddCourseForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ labelFormTitle;
	private: System::Windows::Forms::Label^ labelCourseName;
	private: System::Windows::Forms::TextBox^ textBoxCourseName;
	private: System::Windows::Forms::Label^ labelCourseCode;
	private: System::Windows::Forms::TextBox^ textBoxCourseCode;
	private: System::Windows::Forms::Button^ buttonSave;
	private: System::Windows::Forms::Button^ buttonCancel;
	private: System::Windows::Forms::Label^ labelStatus;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->labelFormTitle = (gcnew System::Windows::Forms::Label());
			this->labelCourseName = (gcnew System::Windows::Forms::Label());
			this->textBoxCourseName = (gcnew System::Windows::Forms::TextBox());
			this->labelCourseCode = (gcnew System::Windows::Forms::Label());
			this->textBoxCourseCode = (gcnew System::Windows::Forms::TextBox());
			this->buttonSave = (gcnew System::Windows::Forms::Button());
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
			this->labelFormTitle->Location = System::Drawing::Point(91, 20);
			this->labelFormTitle->Name = L"labelFormTitle";
			this->labelFormTitle->Size = System::Drawing::Size(153, 25);
			this->labelFormTitle->TabIndex = 0;
			this->labelFormTitle->Text = L"Add New Course";
			// 
			// labelCourseName
			// 
			this->labelCourseName->AutoSize = true;
			this->labelCourseName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelCourseName->Location = System::Drawing::Point(20, 70);
			this->labelCourseName->Name = L"labelCourseName";
			this->labelCourseName->Size = System::Drawing::Size(96, 19);
			this->labelCourseName->TabIndex = 1;
			this->labelCourseName->Text = L"Course Name:";
			// 
			// textBoxCourseName
			// 
			this->textBoxCourseName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBoxCourseName->Location = System::Drawing::Point(122, 67);
			this->textBoxCourseName->Name = L"textBoxCourseName";
			this->textBoxCourseName->Size = System::Drawing::Size(200, 25);
			this->textBoxCourseName->TabIndex = 2;
			// 
			// labelCourseCode
			// 
			this->labelCourseCode->AutoSize = true;
			this->labelCourseCode->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelCourseCode->Location = System::Drawing::Point(20, 110);
			this->labelCourseCode->Name = L"labelCourseCode";
			this->labelCourseCode->Size = System::Drawing::Size(92, 19);
			this->labelCourseCode->TabIndex = 3;
			this->labelCourseCode->Text = L"Course Code:";
			// 
			// textBoxCourseCode
			// 
			this->textBoxCourseCode->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBoxCourseCode->Location = System::Drawing::Point(122, 107);
			this->textBoxCourseCode->Name = L"textBoxCourseCode";
			this->textBoxCourseCode->Size = System::Drawing::Size(120, 25);
			this->textBoxCourseCode->TabIndex = 4;
			// 
			// buttonSave
			// 
			this->buttonSave->BackColor = System::Drawing::Color::DodgerBlue;
			this->buttonSave->FlatAppearance->BorderSize = 0;
			this->buttonSave->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonSave->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonSave->ForeColor = System::Drawing::Color::White;
			this->buttonSave->Location = System::Drawing::Point(122, 150);
			this->buttonSave->Name = L"buttonSave";
			this->buttonSave->Size = System::Drawing::Size(100, 30);
			this->buttonSave->TabIndex = 5;
			this->buttonSave->Text = L"Save";
			this->buttonSave->UseVisualStyleBackColor = false;
			this->buttonSave->Click += gcnew System::EventHandler(this, &AddCourseForm::buttonSave_Click);
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
			this->buttonCancel->Location = System::Drawing::Point(232, 150);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(90, 30);
			this->buttonCancel->TabIndex = 6;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = false;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &AddCourseForm::buttonCancel_Click);
			// 
			// labelStatus
			// 
			this->labelStatus->AutoSize = true;
			this->labelStatus->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelStatus->ForeColor = System::Drawing::Color::Red;
			this->labelStatus->Location = System::Drawing::Point(119, 185);
			this->labelStatus->Name = L"labelStatus";
			this->labelStatus->Size = System::Drawing::Size(0, 15);
			this->labelStatus->TabIndex = 7;
			// 
			// AddCourseForm
			// 
			this->AcceptButton = this->buttonSave;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->CancelButton = this->buttonCancel;
			this->ClientSize = System::Drawing::Size(334, 210);
			this->Controls->Add(this->labelStatus);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->buttonSave);
			this->Controls->Add(this->textBoxCourseCode);
			this->Controls->Add(this->labelCourseCode);
			this->Controls->Add(this->textBoxCourseName);
			this->Controls->Add(this->labelCourseName);
			this->Controls->Add(this->labelFormTitle);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"AddCourseForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Add New Course";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void buttonSave_Click(System::Object^ sender, System::EventArgs^ e) {
		// Validate inputs
		if (textBoxCourseName->Text->Trim()->Length == 0) {
			labelStatus->Text = "Please enter course name";
			textBoxCourseName->Focus();
			return;
		}

		if (textBoxCourseCode->Text->Trim()->Length == 0) {
			labelStatus->Text = "Please enter course code";
			textBoxCourseCode->Focus();
			return;
		}

		// Get values from input fields
		String^ courseName = textBoxCourseName->Text->Trim();
		String^ courseCode = textBoxCourseCode->Text->Trim();

		// Add course to database
		bool success = dbHelper->AddCourse(courseName, courseCode);

		if (success) {
			// Close the form
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		} else {
			labelStatus->Text = "Failed to add course. Please try again.";
		}
	}

	private: System::Void buttonCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		// Close the form
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
		this->Close();
	}
	};
} 