#include "LoadData.h"
Data_::Data_() {
    destination = "";
    price = 0;
    discount = 0;
}
Data_::Data_(std::string destination_, int price_, int disc_) {
    destination = destination_;
    price = price_;
    discount = disc_;
}
Data_::~Data_() {}
