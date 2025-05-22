#include "LoginForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Project5;

[STAThread]
int main(array<String^>^ args) {
    // Enable visual styles for modern UI appearance
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
	
    // Create and run the login form
    Application::Run(gcnew LoginForm());
    
    return 0;
}
