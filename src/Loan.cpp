#include "Loan.hpp"

Loan::Loan(double amount, int term)
    : amount(amount), remainingInstallments(term), interestRate(0.05 + 0.01 * term) {}

double Loan::getMonthlyPayment() const {
    return (amount * (1 + interestRate)) / remainingInstallments;
}

void Loan::reduceInstallment() {
    if (remainingInstallments > 0) {
        remainingInstallments--;
    }
}

bool Loan::isPaidOff() const {
    return remainingInstallments <= 0;
}

double Loan::getRemainingAmount() const {
    return remainingInstallments * getMonthlyPayment();
}
