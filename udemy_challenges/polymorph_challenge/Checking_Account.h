#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H
#include "Account.h"

class Checking_Account : public Account
{
private:
    static constexpr const char *def_name = "Unnammed Checking Account";
    static constexpr double def_balance = 0.0;
    static constexpr double fee = 1.50;
    
public:
    Checking_Account (std::string name = def_name, double balance = def_balance);
    virtual bool withdraw(double amount) override;
    virtual bool deposit (double amount) override;
    
    virtual void print (std::ostream &os) const override;
    
    virtual ~Checking_Account () = default;
};

#endif // CHECKING_ACCOUNT_H
