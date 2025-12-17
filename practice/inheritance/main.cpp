/* Your task:
 * 1. Modify the class definition files to include helpful print statements in each method so that program output clearly shows what happens during each operation
 * 2. Add more tests for invalid inputs
 */

#include <iostream>
#include <iomanip>
#include "SavingsAccount.h"
#include "CheckingAccount.h"

int main() {
    std::cout << std::fixed << std::setprecision(2);

    SavingsAccount sa("Alice", 101, 1000.0, 0.02);
    sa.deposit(200); // 1200
    sa.applyInterest(); // +2% => 1224
    sa.withdraw(300); // 924

    CheckingAccount ca("Bob", 202, 500.0, 0.50);
    ca.withdrawWithFee(100); // 399.50
    ca.withdrawWithFee(450); // should fail (prints message)

    std::cout << "Savings(" << sa.getOwner() << ") $" << sa.getBalance() << "\n";
    std::cout << "Checking(" << ca.getOwner() << ") $" << ca.getBalance() << "\n";

    return 0;
}