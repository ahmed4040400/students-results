#pragma once
#include "DatabaseHelper.h"

namespace Project5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	// AssignResultForm class for assigning exam results to students
	public ref class AssignResultForm : public System::Windows::Forms::Form
	{
	private:
		// Database helper for database operations
		DatabaseHelper^ dbHelper;
		// Course ID for this result
		int courseId;
		// Course name for display
		String^ courseName;
		// Student ID for this result
		int studentId;
		// Student name for display
		String^ studentName;
		// Current result if any
		double currentResult;

	public:
		AssignResultForm(DatabaseHelper^ helper, int cid, String^ cname, int sid, String^ sname, double result)
		{
			InitializeComponent();
			
			// Store parameters
			dbHelper = helper;
			courseId = cid;
			courseName = cname;
			studentId = sid;
			studentName = sname;
			currentResult = result;
			
			// Set display values
			labelCourseName->Text = courseName;
			labelStudentName->Text = studentName;
			numericUpDownResult->Value = Convert::ToDecimal(currentResult);
		}

	protected:
		~AssignResultForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ labelFormTitle;
	private: System::Windows::Forms::Label^ labelCourseTitle;
	private: System::Windows::Forms::Label^ labelCourseName;
	private: System::Windows::Forms::Label^ labelStudentTitle;
	private: System::Windows::Forms::Label^ labelStudentName;
	private: System::Windows::Forms::Label^ labelResult;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownResult;
	private: System::Windows::Forms::Button^ buttonSave;
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
			this->labelStudentTitle = (gcnew System::Windows::Forms::Label());
			this->labelStudentName = (gcnew System::Windows::Forms::Label());
			this->labelResult = (gcnew System::Windows::Forms::Label());
			this->numericUpDownResult = (gcnew System::Windows::Forms::NumericUpDown());
			this->buttonSave = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->labelStatus = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownResult))->BeginInit();
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
			this->labelFormTitle->Size = System::Drawing::Size(135, 25);
			this->labelFormTitle->TabIndex = 0;
			this->labelFormTitle->Text = L"Assign Result";
			// 
			// labelCourseTitle
			// 
			this->labelCourseTitle->AutoSize = true;
			this->labelCourseTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelCourseTitle->Location = System::Drawing::Point(30, 70);
			this->labelCourseTitle->Name = L"labelCourseTitle";
			this->labelCourseTitle->Size = System::Drawing::Size(58, 19);
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
			this->labelCourseName->Size = System::Drawing::Size(93, 19);
			this->labelCourseName->TabIndex = 2;
			this->labelCourseName->Text = L"Course Name";
			// 
			// labelStudentTitle
			// 
			this->labelStudentTitle->AutoSize = true;
			this->labelStudentTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelStudentTitle->Location = System::Drawing::Point(30, 100);
			this->labelStudentTitle->Name = L"labelStudentTitle";
			this->labelStudentTitle->Size = System::Drawing::Size(65, 19);
			this->labelStudentTitle->TabIndex = 3;
			this->labelStudentTitle->Text = L"Student:";
			// 
			// labelStudentName
			// 
			this->labelStudentName->AutoSize = true;
			this->labelStudentName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelStudentName->Location = System::Drawing::Point(94, 100);
			this->labelStudentName->Name = L"labelStudentName";
			this->labelStudentName->Size = System::Drawing::Size(100, 19);
			this->labelStudentName->TabIndex = 4;
			this->labelStudentName->Text = L"Student Name";
			// 
			// labelResult
			// 
			this->labelResult->AutoSize = true;
			this->labelResult->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelResult->Location = System::Drawing::Point(30, 140);
			this->labelResult->Name = L"labelResult";
			this->labelResult->Size = System::Drawing::Size(56, 19);
			this->labelResult->TabIndex = 5;
			this->labelResult->Text = L"Result:";
			// 
			// numericUpDownResult
			// 
			this->numericUpDownResult->DecimalPlaces = 2;
			this->numericUpDownResult->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->numericUpDownResult->Location = System::Drawing::Point(98, 138);
			this->numericUpDownResult->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->numericUpDownResult->Name = L"numericUpDownResult";
			this->numericUpDownResult->Size = System::Drawing::Size(80, 25);
			this->numericUpDownResult->TabIndex = 6;
			this->numericUpDownResult->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 70, 0, 0, 0 });
			// 
			// buttonSave
			// 
			this->buttonSave->BackColor = System::Drawing::Color::DodgerBlue;
			this->buttonSave->FlatAppearance->BorderSize = 0;
			this->buttonSave->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonSave->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonSave->ForeColor = System::Drawing::Color::White;
			this->buttonSave->Location = System::Drawing::Point(98, 180);
			this->buttonSave->Name = L"buttonSave";
			this->buttonSave->Size = System::Drawing::Size(100, 30);
			this->buttonSave->TabIndex = 7;
			this->buttonSave->Text = L"Save";
			this->buttonSave->UseVisualStyleBackColor = false;
			this->buttonSave->Click += gcnew System::EventHandler(this, &AssignResultForm::buttonSave_Click);
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
			this->buttonCancel->Location = System::Drawing::Point(208, 180);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(90, 30);
			this->buttonCancel->TabIndex = 8;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = false;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &AssignResultForm::buttonCancel_Click);
			// 
			// labelStatus
			// 
			this->labelStatus->AutoSize = true;
			this->labelStatus->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelStatus->ForeColor = System::Drawing::Color::Red;
			this->labelStatus->Location = System::Drawing::Point(98, 215);
			this->labelStatus->Name = L"labelStatus";
			this->labelStatus->Size = System::Drawing::Size(0, 15);
			this->labelStatus->TabIndex = 9;
			// 
			// AssignResultForm
			// 
			this->AcceptButton = this->buttonSave;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->CancelButton = this->buttonCancel;
			this->ClientSize = System::Drawing::Size(334, 250);
			this->Controls->Add(this->labelStatus);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->buttonSave);
			this->Controls->Add(this->numericUpDownResult);
			this->Controls->Add(this->labelResult);
			this->Controls->Add(this->labelStudentName);
			this->Controls->Add(this->labelStudentTitle);
			this->Controls->Add(this->labelCourseName);
			this->Controls->Add(this->labelCourseTitle);
			this->Controls->Add(this->labelFormTitle);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"AssignResultForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Assign Result to Student";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownResult))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void buttonSave_Click(System::Object^ sender, System::EventArgs^ e) {
		// Get result value
		double result = Convert::ToDouble(numericUpDownResult->Value);

		// Save result
		bool success = dbHelper->SaveStudentResult(studentId, courseId, result);

		if (success) {
			// Close the form
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		} else {
			labelStatus->Text = "Failed to save result. Please try again.";
		}
	}

	private: System::Void buttonCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		// Close the form
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
		this->Close();
	}
	};
} 