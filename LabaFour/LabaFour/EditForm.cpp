#include "EditForm.h"
//#include "Data.h"
#include "LoadData.h"
#include "MainForm.h"
using namespace System::IO;


using namespace System;
using namespace System::Windows::Forms;



System::Void LabaFour::EditForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	System::String^ destination;
	System::String^ price_;
	System::String^ disc_;
	int price, discount;
	destination = textBox1->Text;
	if (System::String::IsNullOrWhiteSpace(destination)) destination = "default";
	price_ = textBox2->Text;
	if (System::Text::RegularExpressions::Regex::IsMatch(price_, "^[0-9]+$") && price_->Length < 8)
	{
		price = System::Int32::Parse(price_);
	}
	else price = 0;
	disc_ = textBox3->Text;
	if (System::Text::RegularExpressions::Regex::IsMatch(disc_, "^[0-9]+$") && price_->Length < 8)
	{
		discount = System::Int32::Parse(disc_);
	}
	else discount = 0;
	if (price > discount) price = price - discount;
	listData2->Add(gcnew ManagedData(destination, price, discount));
	textBox1->Clear();
	textBox2->Clear();
	textBox3->Clear();
}

System::Void LabaFour::EditForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	int selectedIndex = comboBox1->SelectedIndex;

	if (selectedIndex < 0 || selectedIndex >= listData2->Count)
	{
		MessageBox::Show("Please select a valid item to edit.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	System::String^ destination;
	System::String^ price_;
	System::String^ disc_;
	int price, discount;
	destination = textBox1->Text;
	if (System::String::IsNullOrWhiteSpace(destination)) destination = "default";
	price_ = textBox2->Text;
	if (System::Text::RegularExpressions::Regex::IsMatch(price_, "^[0-9]+$") && price_->Length < 8)
	{
		price = System::Int32::Parse(price_);
	}
	else price = 0;
	disc_ = textBox3->Text;
	if (System::Text::RegularExpressions::Regex::IsMatch(disc_, "^[0-9]+$") && price_->Length < 8)
	{
		discount = System::Int32::Parse(disc_);
	}
	else discount = 0;
	if (price > discount) price = price - discount;
	listData2[selectedIndex] = gcnew ManagedData(destination, price, discount);
	textBox1->Clear();
	textBox2->Clear();
	textBox3->Clear();
}

System::Void LabaFour::EditForm::comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	int selectedIndex = comboBox1->SelectedIndex;

	if (selectedIndex < 0 || selectedIndex >= listData2->Count)
	{
		MessageBox::Show("No valid item selected.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	ManagedData^ selectedPerson = listData2[selectedIndex];
	
}

System::Void LabaFour::EditForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	int selectedIndex = comboBox1->SelectedIndex;
	if (selectedIndex >= 0) {
		// Remove from std::vector<Data_>
		listData2->RemoveAt(selectedIndex);
	}
}
