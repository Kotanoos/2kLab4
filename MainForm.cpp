#include "MainForm.h"
//#include "Data.h"
#include "LoadData.h"
#include "EditForm.h"
#include "ShowingForm.h"
using namespace System::IO;


using namespace System; 
using namespace System::Windows::Forms;


[System::STAThread]


void main(cli::array<System::String^>^ args) {
	System::Windows::Forms::Application::EnableVisualStyles();
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);

	LabaFour::MainForm from;
	System::Windows::Forms::Application::Run(% from);
}
System::Void LabaFour::MainForm::ShowTariffs_Click(Object^ sender, EventArgs^ e) {
	ShowingForm^ formmm = gcnew ShowingForm(listData);
	formmm->ShowDialog();
}
System::Void LabaFour::MainForm::AddTariff_Click(Object^ sender, EventArgs^ e) {
	EditForm^ formac = gcnew EditForm(this,listData);
	formac->ShowDialog();
}

System::Void LabaFour::MainForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	EditForm^ formac = gcnew EditForm(this, listData, 1);
	formac->ShowDialog();
}

System::Void LabaFour::MainForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ fileName;
	OpenFileDialog^ openDlg = gcnew OpenFileDialog();
	openDlg = openFileDialog1;
	openDlg->Filter = "(*.txt)|*.txt";
	openDlg->ShowDialog();
	fileName = openDlg->FileName;

	String^ dataFrom;
	int n = 0, counter = 0;
	String^ destination;
	int price;
	int discount;

	StreamReader^ reader = File::OpenText(fileName);
	while ((dataFrom = reader->ReadLine()) != nullptr) {

		if (counter == 0) {
			n = Convert::ToInt32(Convert::ToString(dataFrom[0]));
			counter = 1;
			continue;
		}
		if (counter == 1) {
			array<String^>^ StringArray = dataFrom->Split(' ');
			destination = StringArray[0];
			counter++;
			continue;
		}
		if (counter == 2) {
			array<String^>^ StringArray = dataFrom->Split(' ');
			price = Convert::ToInt32(Convert::ToString(StringArray[0]));
			counter++;
			continue;
		}
		if (counter == 3) {
			array<String^>^ StringArray = dataFrom->Split(' ');
			discount = Convert::ToInt32(Convert::ToString(StringArray[0]));
			counter = 1;
			price = price - discount;
			listData->Add(gcnew ManagedData(destination, price, discount));// dataList->Add(gcnew Data_(initials,date,address))
			//listData -- global in header MainForm
			continue;
		}
	}//end while 
	reader->Close();

	//MessageBox::Show(Convert::ToString(listData[1]->GetInitials().name));
	/*dataGridView1->DataSource = listData;*/
}

System::Void LabaFour::MainForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	SaveFileDialog^ saveFdialog = gcnew SaveFileDialog();


	saveFdialog->Filter = "Text file (*.txt)|*.txt";
	saveFdialog->Title = "Save a text file";
	//saveFdialog->ShowDialog();
	int nn = listData->Count;
	int n = 0, counter = 0;
	if (saveFdialog->ShowDialog() == ::DialogResult::OK) {
		StreamWriter^ sw = gcnew StreamWriter(saveFdialog->FileName);


		while (counter <= nn) {

			if (counter == 0) {
				n = listData->Count;
				sw->WriteLine(n);
			}
			else {
				sw->WriteLine(listData[counter - 1]->GetDestination());
				sw->WriteLine(listData[counter - 1]->GetPrice());
				sw->WriteLine(listData[counter - 1]->GetDiscount());
			}

			counter++;
		}// end while 
		sw->Close();

	}


	return System::Void();
}

//System::Void LabaFour::MainForm::ExitApp(Object^ sender, EventArgs^ e) {
//	Application::Exit();
//}
// 
// 
// 
// 
// 
// 
// 
//Airport airport;
//System::Void LabaFour::MainForm::ShowTariffs_Click (System::Object^ sender, System::EventArgs^ e) {
//	
//	//EditForm editform;
//	//editform.ShowDialog();
//}
//System::Void LabaFour::MainForm::AddTariff_Click(System::Object^ sender, System::EventArgs^ e) {
//
//}