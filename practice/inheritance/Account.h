#ifndef BANKACCOUNT_ACCOUNT_H
#define BANKACCOUNT_ACCOUNT_H

#include <string>
class Account {
private:
    std::string owner;
    int id;
    double balance;


protected:
    // Allow derived classes to safely access/modify balance if needed
    double& balanceRef() { return balance; }
    const double& balanceRef() const { return balance; }


public:
    Account(std::string accOwner, int accId, double initialBalance);

    void deposit(double amount); // add amount if > 0, else print error
    bool withdraw(double amount); // subtract if amount > 0 and <= balance

    // Getters
    std::string getOwner() const;
    int getId() const;
    double getBalance() const;
};

#endif //BANKACCOUNT_ACCOUNT_H