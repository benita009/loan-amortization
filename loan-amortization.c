#include <stdio.h>

int main(void)
{
    double principal, annual_rate, monthly_payment;
    double monthly_rate, interest, principal_paid, balance;
    int month = 0;

    printf("Enter loan principal: $");
    scanf("%lf", &principal);

    printf("Enter annual interest rate (%%): ");
    scanf("%lf", &annual_rate);

    printf("Enter monthly payment: $");
    scanf("%lf", &monthly_payment);

    monthly_rate = annual_rate / 100.0 / 12.0;

    if (monthly_rate > 0 && monthly_payment <= principal * monthly_rate)
    {
        printf("\nError: The monthly payment is not sufficient to reduce the loan.\n");
        return 1;
    }

    if (principal <= 0 || annual_rate < 0 || monthly_payment <= 0)
    {
        printf("\nError: Please enter valid positive values.\n");
        return 1;
    }

    balance = principal;

    printf("\nAmortization Schedule\n");
    printf("------------------------------------------------------------\n");
    printf("%-8s %-15s %-15s %-15s\n",
           "Month", "Payment", "Interest", "Principal");
    printf("------------------------------------------------------------\n");

    while (balance > 0.0)
    {
        month++;

        interest = balance * monthly_rate;

        
        if (monthly_payment > balance + interest)
            monthly_payment = balance + interest;

        principal_paid = monthly_payment - interest;
        balance -= principal_paid;

        if (balance < 0.0)
            balance = 0.0;

        printf("%-8d $%-14.2f $%-14.2f $%-14.2f\n",
               month, monthly_payment, interest, principal_paid);
    }

    printf("------------------------------------------------------------\n");
    printf("Loan paid off in %d months.\n", month);

    return 0;
}