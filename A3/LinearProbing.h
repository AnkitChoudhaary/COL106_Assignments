#ifndef LINEARPROBING_H
#define LINEARPROBING_H

#include "BaseClass.h"
#include <iostream>

class LinearProbing : public BaseClass
{
public:
    void createAccount(std::string id, int count) override;
    std::vector<int> getTopK(int k) override;
    int getBalance(std::string id) override;
    void addTransaction(std::string id, int count) override;
    bool doesExist(std::string id) override;
    bool deleteAccount(std::string id) override;
    int databaseSize() override;
    int hash(std::string id) override;

private:
    std::vector<int> Sort_Balance;
    int size = 0;
    std::vector<int> merge(std::vector<int> a, std::vector<int> b);
    std::vector<int> sort(std::vector<int> a);
};

#endif // LINEARPROBING_H
