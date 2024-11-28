#ifndef LOAN_HPP
#define LOAN_HPP

class Loan {
    double amount;
    int remainingInstallments;
    double interestRate;

public:
    Loan(double amount, int term);

    double getMonthlyPayment() const;
    void reduceInstallment();
    bool isPaidOff() const;
    double getRemainingAmount() const;
};

#endif // LOAN_HPP
