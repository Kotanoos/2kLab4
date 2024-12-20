//#include "Airport.h"
//#include <fstream>
//#include <stdexcept>
//#include <algorithm>
//
//void Airport::addTariff(int price, const std::string& destination, const IStrategy& strategy) {
//    tariffs.push_back(strategy.doAlgorithm(price, destination));
//}
//
//void Airport::editTariff(int index, int newPrice, const std::string& newDestination, int newDiscount) {
//    if (index < 0 || index >= tariffs.size())
//        throw std::out_of_range("Invalid index.");
//    tariffs[index].setPrice(newPrice);
//    tariffs[index].setDestination(newDestination);
//    tariffs[index].setDiscount(newDiscount);
//}
//
//void Airport::removeTariff(int index) {
//    if (index < 0 || index >= tariffs.size())
//        throw std::out_of_range("Invalid index.");
//    tariffs.erase(tariffs.begin() + index);
//}
//
//const std::vector<Tariff>& Airport::getTariffs() const {
//    return tariffs;
//}
//
//std::string Airport::findMostExpensive() const {
//    if (tariffs.empty()) return "No tariffs available.";
//    const auto& maxTariff = *std::max_element(tariffs.begin(), tariffs.end(),
//        [](const Tariff& a, const Tariff& b) { return a.getPrice() < b.getPrice(); });
//    return "Destination: " + maxTariff.getDestination() + ", Price: " + std::to_string(maxTariff.getPrice());
//}
//
//void Airport::sortTariffsByPrice(bool ascending) {
//    std::sort(tariffs.begin(), tariffs.end(), [ascending](const Tariff& a, const Tariff& b) {
//        return ascending ? a.getPrice() < b.getPrice() : a.getPrice() > b.getPrice();
//        });
//}
//
//void Airport::loadFromFile(const std::string& filename) {
//    std::ifstream file(filename);
//    if (!file.is_open())
//        throw std::runtime_error("Unable to open file.");
//    tariffs.clear();
//    int price, discount;
//    std::string destination;
//    while (file >> price >> discount >> std::ws && std::getline(file, destination)) {
//        tariffs.emplace_back(price, destination, discount);
//    }
//}
//
//void Airport::saveToFile(const std::string& filename) {
//    std::ofstream file(filename);
//    if (!file.is_open())
//        throw std::runtime_error("Unable to open file.");
//    for (const auto& tariff : tariffs) {
//        file << tariff.getPrice() << " " << tariff.getDiscount() << " " << tariff.getDestination() << "\n";
//    }
//}