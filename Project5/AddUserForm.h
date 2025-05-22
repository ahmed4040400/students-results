#pragma once
#include "DatabaseHelper.h"

namespace Project5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	// AddUserForm class for adding new users (instructors or students)
	public ref class AddUserForm : public System::Windows::Forms::Form
	{
	private:
		// Database helper for database operations
		DatabaseHelper^ dbHelper;
		// Role of the user being added
		UserRole userRole;

	public:
		AddUserForm(DatabaseHelper^ helper, UserRole role)
		{
			InitializeComponent();
			
			// Store database helper and user role
			dbHelper = helper;
			userRole = role;
			
			// Set form title based on role
			if (userRole == UserRole::Instructor) {
				this->Text = "Add New Instructor";
				labelFormTitle->Text = "Add New Instructor";
			} else {
				this->Text = "Add New Student";
				labelFormTitle->Text = "Add New Student";
			}
		}

	protected:
		~AddUserForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ labelFormTitle;
	private: System::Windows::Forms::Label^ labelName;
	private: System::Windows::Forms::TextBox^ textBoxName;
	private: System::Windows::Forms::Label^ labelAge;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownAge;
	private: System::Windows::Forms::Label^ labelUsername;
	private: System::Windows::Forms::TextBox^ textBoxUsername;
	private: System::Windows::Forms::Label^ labelPassword;
	private: System::Windows::Forms::TextBox^ textBoxPassword;
	private: System::Windows::Forms::Button^ buttonSave;
	private: System::Windows::Forms::Button^ buttonCancel;
	private: System::Windows::Forms::Label^ labelStatus;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->labelFormTitle = (gcnew System::Windows::Forms::Label());
			this->labelName = (gcnew System::Windows::Forms::Label());
			this->textBoxName = (gcnew System::Windows::Forms::TextBox());
			this->labelAge = (gcnew System::Windows::Forms::Label());
			this->numericUpDownAge = (gcnew System::Windows::Forms::NumericUpDown());
			this->labelUsername = (gcnew System::Windows::Forms::Label());
			this->textBoxUsername = (gcnew System::Windows::Forms::TextBox());
			this->labelPassword = (gcnew System::Windows::Forms::Label());
			this->textBoxPassword = (gcnew System::Windows::Forms::TextBox());
			this->buttonSave = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->labelStatus = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownAge))->BeginInit();
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
			this->labelFormTitle->Size = System::Drawing::Size(136, 25);
			this->labelFormTitle->TabIndex = 0;
			this->labelFormTitle->Text = L"Add New User";
			// 
			// labelName
			// 
			this->labelName->AutoSize = true;
			this->labelName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelName->Location = System::Drawing::Point(20, 70);
			this->labelName->Name = L"labelName";
			this->labelName->Size = System::Drawing::Size(48, 19);
			this->labelName->TabIndex = 1;
			this->labelName->Text = L"Name:";
			// 
			// textBoxName
			// 
			this->textBoxName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBoxName->Location = System::Drawing::Point(100, 67);
			this->textBoxName->Name = L"textBoxName";
			this->textBoxName->Size = System::Drawing::Size(200, 25);
			this->textBoxName->TabIndex = 2;
			// 
			// labelAge
			// 
			this->labelAge->AutoSize = true;
			this->labelAge->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelAge->Location = System::Drawing::Point(20, 110);
			this->labelAge->Name = L"labelAge";
			this->labelAge->Size = System::Drawing::Size(36, 19);
			this->labelAge->TabIndex = 3;
			this->labelAge->Text = L"Age:";
			// 
			// numericUpDownAge
			// 
			this->numericUpDownAge->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->numericUpDownAge->Location = System::Drawing::Point(100, 108);
			this->numericUpDownAge->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->numericUpDownAge->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 16, 0, 0, 0 });
			this->numericUpDownAge->Name = L"numericUpDownAge";
			this->numericUpDownAge->Size = System::Drawing::Size(80, 25);
			this->numericUpDownAge->TabIndex = 4;
			this->numericUpDownAge->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			// 
			// labelUsername
			// 
			this->labelUsername->AutoSize = true;
			this->labelUsername->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelUsername->Location = System::Drawing::Point(20, 150);
			this->labelUsername->Name = L"labelUsername";
			this->labelUsername->Size = System::Drawing::Size(74, 19);
			this->labelUsername->TabIndex = 5;
			this->labelUsername->Text = L"Username:";
			// 
			// textBoxUsername
			// 
			this->textBoxUsername->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBoxUsername->Location = System::Drawing::Point(100, 147);
			this->textBoxUsername->Name = L"textBoxUsername";
			this->textBoxUsername->Size = System::Drawing::Size(200, 25);
			this->textBoxUsername->TabIndex = 6;
			// 
			// labelPassword
			// 
			this->labelPassword->AutoSize = true;
			this->labelPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelPassword->Location = System::Drawing::Point(20, 190);
			this->labelPassword->Name = L"labelPassword";
			this->labelPassword->Size = System::Drawing::Size(71, 19);
			this->labelPassword->TabIndex = 7;
			this->labelPassword->Text = L"Password:";
			// 
			// textBoxPassword
			// 
			this->textBoxPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBoxPassword->Location = System::Drawing::Point(100, 187);
			this->textBoxPassword->Name = L"textBoxPassword";
			this->textBoxPassword->PasswordChar = '*';
			this->textBoxPassword->Size = System::Drawing::Size(200, 25);
			this->textBoxPassword->TabIndex = 8;
			// 
			// buttonSave
			// 
			this->buttonSave->BackColor = System::Drawing::Color::DodgerBlue;
			this->buttonSave->FlatAppearance->BorderSize = 0;
			this->buttonSave->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonSave->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonSave->ForeColor = System::Drawing::Color::White;
			this->buttonSave->Location = System::Drawing::Point(100, 230);
			this->buttonSave->Name = L"buttonSave";
			this->buttonSave->Size = System::Drawing::Size(100, 30);
			this->buttonSave->TabIndex = 9;
			this->buttonSave->Text = L"Save";
			this->buttonSave->UseVisualStyleBackColor = false;
			this->buttonSave->Click += gcnew System::EventHandler(this, &AddUserForm::buttonSave_Click);
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
			this->buttonCancel->Location = System::Drawing::Point(210, 230);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(90, 30);
			this->buttonCancel->TabIndex = 10;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = false;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &AddUserForm::buttonCancel_Click);
			// 
			// labelStatus
			// 
			this->labelStatus->AutoSize = true;
			this->labelStatus->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelStatus->ForeColor = System::Drawing::Color::Red;
			this->labelStatus->Location = System::Drawing::Point(97, 265);
			this->labelStatus->Name = L"labelStatus";
			this->labelStatus->Size = System::Drawing::Size(0, 15);
			this->labelStatus->TabIndex = 11;
			// 
			// AddUserForm
			// 
			this->AcceptButton = this->buttonSave;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->CancelButton = this->buttonCancel;
			this->ClientSize = System::Drawing::Size(334, 290);
			this->Controls->Add(this->labelStatus);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->buttonSave);
			this->Controls->Add(this->textBoxPassword);
			this->Controls->Add(this->labelPassword);
			this->Controls->Add(this->textBoxUsername);
			this->Controls->Add(this->labelUsername);
			this->Controls->Add(this->numericUpDownAge);
			this->Controls->Add(this->labelAge);
			this->Controls->Add(this->textBoxName);
			this->Controls->Add(this->labelName);
			this->Controls->Add(this->labelFormTitle);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"AddUserForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Add New User";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownAge))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void buttonSave_Click(System::Object^ sender, System::EventArgs^ e) {
		// Validate inputs
		if (textBoxName->Text->Trim()->Length == 0) {
			labelStatus->Text = "Please enter a name";
			textBoxName->Focus();
			return;
		}

		if (textBoxUsername->Text->Trim()->Length == 0) {
			labelStatus->Text = "Please enter a username";
			textBoxUsername->Focus();
			return;
		}

		if (textBoxPassword->Text->Trim()->Length == 0) {
			labelStatus->Text = "Please enter a password";
			textBoxPassword->Focus();
			return;
		}

		// Get values from input fields
		String^ name = textBoxName->Text->Trim();
		int age = Convert::ToInt32(numericUpDownAge->Value);
		String^ username = textBoxUsername->Text->Trim();
		String^ password = textBoxPassword->Text->Trim();

		// Add user to database
		bool success = dbHelper->AddUser(username, password, name, age, userRole);

		if (success) {
			// Close the form
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		} else {
			labelStatus->Text = "Failed to add user. Please try again.";
		}
	}

	private: System::Void buttonCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		// Close the form
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
		this->Close();
	}
	};
} 