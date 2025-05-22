#pragma once
#include "DatabaseHelper.h"
#include "AdminDashboard.h" 
#include "InstructorDashboard.h"
#include "StudentDashboard.h"

namespace Project5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	private:
		// Database helper for database operations
		DatabaseHelper^ dbHelper;
        
	public:
		LoginForm(void)
		{
			InitializeComponent();
			// Initialize database helper
			dbHelper = gcnew DatabaseHelper();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		// LoginForm class to handle user authentication
		private: System::Windows::Forms::Panel^ panelMain;
		private: System::Windows::Forms::Label^ labelTitle;
		private: System::Windows::Forms::Label^ labelUsername;
		private: System::Windows::Forms::TextBox^ textBoxUsername;
		private: System::Windows::Forms::Label^ labelPassword;
		private: System::Windows::Forms::TextBox^ textBoxPassword;
		private: System::Windows::Forms::Button^ buttonLogin;
		private: System::Windows::Forms::Label^ labelStatus;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panelMain = (gcnew System::Windows::Forms::Panel());
			this->labelStatus = (gcnew System::Windows::Forms::Label());
			this->buttonLogin = (gcnew System::Windows::Forms::Button());
			this->textBoxPassword = (gcnew System::Windows::Forms::TextBox());
			this->labelPassword = (gcnew System::Windows::Forms::Label());
			this->textBoxUsername = (gcnew System::Windows::Forms::TextBox());
			this->labelUsername = (gcnew System::Windows::Forms::Label());
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->panelMain->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelMain
			// 
			this->panelMain->BackColor = System::Drawing::Color::WhiteSmoke;
			this->panelMain->Controls->Add(this->labelStatus);
			this->panelMain->Controls->Add(this->buttonLogin);
			this->panelMain->Controls->Add(this->textBoxPassword);
			this->panelMain->Controls->Add(this->labelPassword);
			this->panelMain->Controls->Add(this->textBoxUsername);
			this->panelMain->Controls->Add(this->labelUsername);
			this->panelMain->Controls->Add(this->labelTitle);
			this->panelMain->Location = System::Drawing::Point(50, 50);
			this->panelMain->Name = L"panelMain";
			this->panelMain->Size = System::Drawing::Size(400, 300);
			this->panelMain->TabIndex = 0;
			this->panelMain->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &LoginForm::panelMain_Paint);
			// 
			// labelStatus
			// 
			this->labelStatus->AutoSize = true;
			this->labelStatus->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelStatus->ForeColor = System::Drawing::Color::Red;
			this->labelStatus->Location = System::Drawing::Point(118, 255);
			this->labelStatus->Name = L"labelStatus";
			this->labelStatus->Size = System::Drawing::Size(0, 15);
			this->labelStatus->TabIndex = 6;
			// 
			// buttonLogin
			// 
			this->buttonLogin->BackColor = System::Drawing::Color::DodgerBlue;
			this->buttonLogin->FlatAppearance->BorderSize = 0;
			this->buttonLogin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonLogin->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonLogin->ForeColor = System::Drawing::Color::White;
			this->buttonLogin->Location = System::Drawing::Point(121, 212);
			this->buttonLogin->Name = L"buttonLogin";
			this->buttonLogin->Size = System::Drawing::Size(156, 40);
			this->buttonLogin->TabIndex = 5;
			this->buttonLogin->Text = L"Login";
			this->buttonLogin->UseVisualStyleBackColor = false;
			this->buttonLogin->Click += gcnew System::EventHandler(this, &LoginForm::buttonLogin_Click);
			// 
			// textBoxPassword
			// 
			this->textBoxPassword->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBoxPassword->Location = System::Drawing::Point(121, 168);
			this->textBoxPassword->Name = L"textBoxPassword";
			this->textBoxPassword->PasswordChar = '*';
			this->textBoxPassword->Size = System::Drawing::Size(232, 27);
			this->textBoxPassword->TabIndex = 4;
			// 
			// labelPassword
			// 
			this->labelPassword->AutoSize = true;
			this->labelPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelPassword->Location = System::Drawing::Point(36, 170);
			this->labelPassword->Name = L"labelPassword";
			this->labelPassword->Size = System::Drawing::Size(73, 20);
			this->labelPassword->TabIndex = 3;
			this->labelPassword->Text = L"Password:";
			// 
			// textBoxUsername
			// 
			this->textBoxUsername->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxUsername->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBoxUsername->Location = System::Drawing::Point(121, 123);
			this->textBoxUsername->Name = L"textBoxUsername";
			this->textBoxUsername->Size = System::Drawing::Size(232, 27);
			this->textBoxUsername->TabIndex = 2;
			// 
			// labelUsername
			// 
			this->labelUsername->AutoSize = true;
			this->labelUsername->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelUsername->Location = System::Drawing::Point(34, 125);
			this->labelUsername->Name = L"labelUsername";
			this->labelUsername->Size = System::Drawing::Size(78, 20);
			this->labelUsername->TabIndex = 1;
			this->labelUsername->Text = L"Username:";
			// 
			// labelTitle
			// 
			this->labelTitle->AutoSize = true;
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTitle->ForeColor = System::Drawing::Color::DodgerBlue;
			this->labelTitle->Location = System::Drawing::Point(82, 40);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(244, 32);
			this->labelTitle->TabIndex = 0;
			this->labelTitle->Text = L"Student Results App";
			// 
			// LoginForm
			// 
			this->AcceptButton = this->buttonLogin;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(500, 400);
			this->Controls->Add(this->panelMain);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"LoginForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Student Results App - Login";
			this->panelMain->ResumeLayout(false);
			this->panelMain->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void buttonLogin_Click(System::Object^ sender, System::EventArgs^ e) {
		// Get username and password from text boxes
		String^ username = textBoxUsername->Text->Trim();
		String^ password = textBoxPassword->Text->Trim();   
		
		// Validate input
		if (username->Length == 0 || password->Length == 0) {
			labelStatus->Text = "Please enter username and password";
			return;
		}
		
		// Verify login credentials
		UserRole role;
		int userId;
		
		if (dbHelper->VerifyLogin(username, password, role, userId)) {
			// Hide login form
			this->Hide();
			
			// Show appropriate dashboard based on user role
			switch (role) {
				case UserRole::Admin:
					{
						// Show admin dashboard
						AdminDashboard^ adminDashboard = gcnew AdminDashboard(userId, dbHelper);
						adminDashboard->FormClosed += gcnew FormClosedEventHandler(this, &LoginForm::dashboard_FormClosed);
						adminDashboard->Show();
						break;
					}
				case UserRole::Instructor:
					{
						// Show instructor dashboard
						InstructorDashboard^ instructorDashboard = gcnew InstructorDashboard(userId, dbHelper);
						instructorDashboard->FormClosed += gcnew FormClosedEventHandler(this, &LoginForm::dashboard_FormClosed);
						instructorDashboard->Show();
						break;
					}
				case UserRole::Student:
					{
						// Show student dashboard
						StudentDashboard^ studentDashboard = gcnew StudentDashboard(userId, dbHelper);
						studentDashboard->FormClosed += gcnew FormClosedEventHandler(this, &LoginForm::dashboard_FormClosed);
						studentDashboard->Show();
						break;
					}
			}
		} else {
			// Show error message
			labelStatus->Text = "Invalid username or password";
			textBoxPassword->Text = "";
		}
	}
	
	// Handle dashboard form closed event
	private: System::Void dashboard_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
		// Clear fields
		textBoxUsername->Text = "";
		textBoxPassword->Text = "";
		labelStatus->Text = "";
		
		// Show login form again
		this->Show();
	}
	private: System::Void panelMain_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
};
}
