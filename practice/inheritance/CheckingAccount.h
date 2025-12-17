/* complete the header file for derived class "CheckingAccount"
* You need to:
 * Include a new data member called withdrawFee, e.g., 0.50 per withdrawal
 * Include a parameterized constructor
 * Declare a member function: bool withdrawWithFee(double amount);
*  Declare a setter for fee (non-negative): void setFee(double fee);
 */

#ifndef BANKACCOUNT_CHECKINGACCOUNT_H
#define BANKACCOUNT_CHECKINGACCOUNT_H


class CheckingAccount: public Account {
};


#endif //BANKACCOUNT_CHECKINGACCOUNT_H