#include <iostream>
#include <memory>
#include <vector>

#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

class Test
{
private:
    int data;
public:
    Test () : data {0} {std::cout << "Test constructor (" << data << ")" << std::endl; }
    Test (int data) : data {data} {std::cout << "Test constructor (" << data << ")" << std::endl;}
    
    int get_data () const {return data;}
    ~Test () {std::cout << "Test destructor (" << data << ")" << std::endl;}
};

void func (std::shared_ptr <Test> p)
{
    std::cout << "Use count: " << p.use_count() << std::endl;   //since p is a copy of ptr, use_count is 2
}


int main()
{
    std::unique_ptr <Account> moes_account;
    std::unique_ptr <Account> larrys_account;
    
    try
    {
        larrys_account = std::make_unique <Savings_Account> ("Larry", -2000.0);
        std::cout << *larrys_account << std::endl;
    }
    catch (const IllegalBalanceException &ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    
    try
    {
        moes_account = std::make_unique <Savings_Account> ("Moe", 1000.0);
        std::cout << *moes_account << std::endl;
        moes_account ->withdraw (500.0);
        std::cout << *moes_account << std::endl;
        moes_account ->withdraw (1000.0);
        std::cout << *moes_account << std::endl;
    }
    
    catch (const IllegalBalanceException &ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    
    catch (const InsufficientFundsException &ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    
    std::cout << "Program completed successfully" << std::endl;
    
    
	return 0;
}
