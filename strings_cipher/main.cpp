#include <iostream>
#include <string>

/*This task is a substitution cipher
 * The letters in a message is encrypted by the keychain
 * According to the serial of the alphabet
 * for example a is replace by X
 */

using namespace std;

int main(int argc, char **argv)
{
	string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key_chain {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};
    string user_message {};
    size_t position {};
    
    cout << "Enter your Sectret message:";
    getline(cin, user_message);
    
    cout <<"Encrypting message..." << endl;
    
    for (size_t i {0}; i < user_message.length(); ++i)
    {
        position = alphabet.find(user_message.at(i));
        if (position != string::npos)
        {
            user_message.at(i) = key_chain.at(position);
        }
    }
        
    cout << "Encrypted message:" << user_message << endl;
    
    cout << "Decrypting message..." << endl;
    
    for (size_t i {0}; i < user_message.length(); ++i)
    {
        position = key_chain.find(user_message.at(i));
        if (position != string::npos)
        {
            user_message.at(i) = alphabet.at(position);
        }
    }
    
    cout << "Decrypted message:" << user_message << endl;
    
	return 0;
}
