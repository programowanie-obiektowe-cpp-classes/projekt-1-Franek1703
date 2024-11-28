#ifndef LOAN_HPP
#define LOAN_HPP

class Loan {
private:
    double amount;
    int remainingInstallments;
    double interestRate;

public:
    Loan(double amount, int term);

    double getMonthlyPayment() const;
    void reduceInstallment();
    bool isPaidOff() const;
    double getRemainingAmount() const;

    int getRemainingInstallments() const;
};

#endif // LOAN_HPP
