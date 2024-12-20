//#include "IStrategy.h"
//#include <stdexcept>
//
//Tariff OriginalPrice::doAlgorithm(int price, const std::string& destination) const {
//    return Tariff(price, destination);
//}
//
//DiscountPrice::DiscountPrice(int discount) : discount(discount) {}
//
//Tariff DiscountPrice::doAlgorithm(int price, const std::string& destination) const {
//    int discountedPrice = price - discount;
//    if (discountedPrice < 0)
//        throw std::invalid_argument("Discount cannot exceed the price.");
//    return Tariff(discountedPrice, destination, discount);
//}