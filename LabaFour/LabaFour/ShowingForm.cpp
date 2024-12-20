#include "ShowingForm.h"
#include "MainForm.h"
#include "LoadData.h"
#include <algorithm>


	using namespace System::IO;
	using namespace System;
	using namespace System::Windows::Forms;


	int CompareByDestination(ManagedData^ a, ManagedData^ b)
	{
		return String::Compare(a->Destination, b->Destination, StringComparison::OrdinalIgnoreCase);
	}

	int CompareByPrice(ManagedData^ a, ManagedData^ b)
	{
		return a->Price.CompareTo(b->Price);
	}

	int CompareByDiscount(ManagedData^ a, ManagedData^ b)
	{
		return a->Discount.CompareTo(b->Discount);
	}

	System::Void LabaFour::ShowingForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Sort by destination
		managedDataList->Sort(gcnew Comparison<ManagedData^>(CompareByDestination));

		// Update DataGridView
		dataGridView1->DataSource = nullptr;
		dataGridView1->DataSource = managedDataList;
	}

	System::Void LabaFour::ShowingForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Sort by price
		managedDataList->Sort(gcnew Comparison<ManagedData^>(CompareByPrice));

		// Update DataGridView
		dataGridView1->DataSource = nullptr;
		dataGridView1->DataSource = managedDataList;
	}

	System::Void LabaFour::ShowingForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Sort by discount
		managedDataList->Sort(gcnew Comparison<ManagedData^>(CompareByDiscount));

		// Update DataGridView
		dataGridView1->DataSource = nullptr;
		dataGridView1->DataSource = managedDataList;
	}
