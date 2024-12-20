#pragma once
#include <vector>
#include <string>

class Tariff {
private:
    int price;
    std::string destination;
    int discount;

public:
    Tariff(int prc, const std::string& dest, int disc = 0);
    int getPrice() const;
    std::string getDestination() const;
    int getDiscount() const;
    void setPrice(int newPrice);
    void setDestination(const std::string& newDestination);
    void setDiscount(int newDiscount);
};

class IStrategy {
public:
    virtual ~IStrategy() = default;
    virtual Tariff doAlgorithm(int price, const std::string& destination) const = 0;
};

class OriginalPrice : public IStrategy {
public:
    Tariff doAlgorithm(int price, const std::string& destination) const override;
};

class DiscountPrice : public IStrategy {
private:
    int discount;
public:
    DiscountPrice(int discount);
    Tariff doAlgorithm(int price, const std::string& destination) const override;
};

class Airport {
private:
    std::vector<Tariff> tariffs;

public:
    void addTariff(int price, const std::string& destination, const IStrategy& strategy);
    void editTariff(int index, int newPrice, const std::string& newDestination, int newDiscount);
    void removeTariff(int index);
    const std::vector<Tariff>& getTariffs() const;
    std::string findMostExpensive() const;
    void sortTariffsByPrice(bool ascending);
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename);
};
