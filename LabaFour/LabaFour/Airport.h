//#pragma once
//#include "Tariff.h"
//#include "IStrategy.h"
//#include <vector>
//#include <string>
//
//class Airport {
//private:
//    std::vector<Tariff> tariffs;
//
//public:
//    void addTariff(int price, const std::string& destination, const IStrategy& strategy);
//    void editTariff(int index, int newPrice, const std::string& newDestination, int newDiscount);
//    void removeTariff(int index);
//    const std::vector<Tariff>& getTariffs() const;
//    std::string findMostExpensive() const;
//    void sortTariffsByPrice(bool ascending);
//    void loadFromFile(const std::string& filename);
//    void saveToFile(const std::string& filename);
//};