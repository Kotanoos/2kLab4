#pragma once
#include <string>

class Data_ {
private:
	std::string destination;
	int price;
	int discount;

public:

	Data_();
	Data_(std::string destination_, int price_, int disc_);
	~Data_();

	std::string GetDest() const { return destination; };
	int GetPrice() const { return price; };
	int GetDisc() const { return discount; }

};



public ref class ManagedData {
private:
	System::String^ destination;
	int price;
	int discount;

public:
	ManagedData(System::String^ destination_, int price_, int disc_)
	{
		/*destination = gcnew System::String(destination_.c_str());*/
		destination = destination_;
		price = price_;
		discount = disc_;
	}
	
	//ManagedData(System::String destination_, int price_)
	//{
	//	/*destination = gcnew System::String(destination_.c_str());*/
	//	destination = destination_;
	//	/*price = price_;*/
	//}

	property System::String^ Destination {
		System::String^ get() { return destination; }
	}

	property int Price {
		int get() { return price; }
	}

	property int Discount {
		int get() { return discount; }
	}
	System::String^ GetDestination() { return destination; };
	int GetPrice() { return price; };
	int GetDiscount() { return discount; };
};
