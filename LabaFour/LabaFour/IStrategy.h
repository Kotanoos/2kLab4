//#pragma once
//#include "Tariff.h"
//
//class IStrategy {
//public:
//    virtual ~IStrategy() = default;
//    virtual Tariff doAlgorithm(int price, const std::string& destination) const = 0;
//};
//
//class OriginalPrice : public IStrategy {
//public:
//    Tariff doAlgorithm(int price, const std::string& destination) const override;
//};
//
//class DiscountPrice : public IStrategy {
//private:
//    int discount;
//public:
//    DiscountPrice(int discount);
//    Tariff doAlgorithm(int price, const std::string& destination) const override;
//};