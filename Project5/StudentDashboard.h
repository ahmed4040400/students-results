#pragma once
#include "DatabaseHelper.h"

namespace Project5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	// StudentDashboard class for student-specific operations
	public ref class StudentDashboard : public System::Windows::Forms::Form
	{
	private:
		// Database helper for database operations
		DatabaseHelper^ dbHelper;
		// Current student user ID
		int userId;
		// Student name to display
		String^ studentName;

	public:
		StudentDashboard(int id, DatabaseHelper^ helper)
		{
			InitializeComponent();
			
			// Store user ID and database helper
			userId = id;
			dbHelper = helper;
			
			// Get student details
			DataRow^ studentDetails = dbHelper->GetUserDetails(userId);
			if (studentDetails != nullptr) {
				studentName = studentDetails["Name"]->ToString();
				labelWelcome->Text = "Welcome, " + studentName + "!";
			}
		}

	protected:
		~StudentDashboard()
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
	private: System::Windows::Forms::DataGridView^ dataGridViewResults;
	private: System::Windows::Forms::Label^ labelResults;
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
			this->labelResults = (gcnew System::Windows::Forms::Label());
			this->dataGridViewResults = (gcnew System::Windows::Forms::DataGridView());
			this->panelTop->SuspendLayout();
			this->panelMain->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewResults))->BeginInit();
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
			this->panelTop->Size = System::Drawing::Size(700, 60);
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
			this->buttonLogout->Location = System::Drawing::Point(613, 15);
			this->buttonLogout->Name = L"buttonLogout";
			this->buttonLogout->Size = System::Drawing::Size(75, 30);
			this->buttonLogout->TabIndex = 2;
			this->buttonLogout->Text = L"Logout";
			this->buttonLogout->UseVisualStyleBackColor = false;
			this->buttonLogout->Click += gcnew System::EventHandler(this, &StudentDashboard::buttonLogout_Click);
			// 
			// labelWelcome
			// 
			this->labelWelcome->AutoSize = true;
			this->labelWelcome->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelWelcome->ForeColor = System::Drawing::Color::White;
			this->labelWelcome->Location = System::Drawing::Point(219, 20);
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
			this->labelTitle->Size = System::Drawing::Size(189, 25);
			this->labelTitle->TabIndex = 0;
			this->labelTitle->Text = L"Student Dashboard";
			// 
			// panelMain
			// 
			this->panelMain->BackColor = System::Drawing::Color::WhiteSmoke;
			this->panelMain->Controls->Add(this->buttonRefresh);
			this->panelMain->Controls->Add(this->labelResults);
			this->panelMain->Controls->Add(this->dataGridViewResults);
			this->panelMain->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelMain->Location = System::Drawing::Point(0, 60);
			this->panelMain->Name = L"panelMain";
			this->panelMain->Padding = System::Windows::Forms::Padding(20);
			this->panelMain->Size = System::Drawing::Size(700, 390);
			this->panelMain->TabIndex = 1;
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
			this->buttonRefresh->Location = System::Drawing::Point(570, 40);
			this->buttonRefresh->Name = L"buttonRefresh";
			this->buttonRefresh->Size = System::Drawing::Size(100, 30);
			this->buttonRefresh->TabIndex = 2;
			this->buttonRefresh->Text = L"Refresh";
			this->buttonRefresh->UseVisualStyleBackColor = false;
			this->buttonRefresh->Click += gcnew System::EventHandler(this, &StudentDashboard::buttonRefresh_Click);
			// 
			// labelResults
			// 
			this->labelResults->AutoSize = true;
			this->labelResults->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelResults->Location = System::Drawing::Point(20, 40);
			this->labelResults->Name = L"labelResults";
			this->labelResults->Size = System::Drawing::Size(123, 25);
			this->labelResults->TabIndex = 1;
			this->labelResults->Text = L"Your Results:";
			// 
			// dataGridViewResults
			// 
			this->dataGridViewResults->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridViewResults->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewResults->BackgroundColor = System::Drawing::Color::White;
			this->dataGridViewResults->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridViewResults->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewResults->Location = System::Drawing::Point(20, 80);
			this->dataGridViewResults->Name = L"dataGridViewResults";
			this->dataGridViewResults->ReadOnly = true;
			this->dataGridViewResults->RowHeadersWidth = 51;
			this->dataGridViewResults->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridViewResults->Size = System::Drawing::Size(650, 290);
			this->dataGridViewResults->TabIndex = 0;
			// 
			// StudentDashboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(700, 450);
			this->Controls->Add(this->panelMain);
			this->Controls->Add(this->panelTop);
			this->Name = L"StudentDashboard";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Student Dashboard - Student Results App";
			this->Load += gcnew System::EventHandler(this, &StudentDashboard::StudentDashboard_Load);
			this->panelTop->ResumeLayout(false);
			this->panelTop->PerformLayout();
			this->panelMain->ResumeLayout(false);
			this->panelMain->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewResults))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void StudentDashboard_Load(System::Object^ sender, System::EventArgs^ e) {
		// Load student results
		LoadResults();
	}

	private: System::Void buttonRefresh_Click(System::Object^ sender, System::EventArgs^ e) {
		// Refresh results
		LoadResults();
	}

	private: System::Void buttonLogout_Click(System::Object^ sender, System::EventArgs^ e) {
		// Close this form - will return to login
		this->Close();
	}

	// Load student results
	private: void LoadResults() {
		DataTable^ results = dbHelper->GetStudentResults(userId);
		dataGridViewResults->DataSource = results;
	}
	};
} 