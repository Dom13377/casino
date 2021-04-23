#include <iostream>
#include <random>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
using namespace std;

int balance = 200;
int chips = 0;
int betamount = 0;

void signal_callback_handler(int signum){
        system("tput setaf 2");
        cout << "\n\nHave a nice day!" << endl << endl;
        system("tput sgr0");
        exit(signum);
    }

int bet(){
    cout << "Seclect amount of chips to bet: ";
    cin >> betamount;
    cout << endl;
    if (!cin || betamount > chips || betamount <= 0){
        system("tput setaf 1");
        cout << "\nIncorrect Value!\n" << endl;
        system("tput sgr0");
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else {
        int roll = 0;
        int again = 0;
        cout << "Rolling..." << endl;
        system("sleep 1");
        roll = (rand() % 5) + 1;
        if (roll == 1 || roll == 3 || roll == 4 || roll == 5){
            system("tput setaf 1");
            cout << "\nYou lose\n" << endl;
            system("tput sgr0");
            chips = chips - betamount;
            if (chips < 0){
                chips = 0;
            }
            system("tput setaf 2");       
            cout << "\nBalance: " << balance << "$" << "   Chips: " << chips << endl << endl;
            system("tput sgr0");
        }
        else if (roll == 2){
            system("tput setaf 2");
            cout << "\nYou win\n" << endl;
            system("tput sgr0");
            chips = chips + (betamount * 2);
            system("tput setaf 2");       
            cout << "\nBalance: " << balance << "$" << "   Chips: " << chips << endl << endl;
            system("tput sgr0");
        }
        cout << "\nWould you like to play again?[0/1]: ";
        cin >> again;
        cout << endl;
        if (!cin || again > 1 || again < 0){
            system("tput setaf 1");
            cout << "\nIncorrect Value!\n" << endl;
            system("tput sgr0");
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        else if (again == 1){
            bet();
        }

        else if (again == 0){
            return 0;
        }
    }

    return 0;
}

int banner(){
    system("tput setaf 1");
    cout << "⁎⁎⁎⁎⁎⁎⁎⁎⁎⁎⁎⁎⁎" << endl;
    cout << "Casino Gamble" << endl;
    cout << "*************\n" << endl;
    system("tput sgr0");
    return 0;
}

int casino(){
    int choice;
    cout << "Welcome to Casino Gamble. You can bet, buy chips, or check your balance:\n" << endl;
    cout << "1 bet" << endl;
    cout << "2 buy chips" << endl;
    cout << "3 check balance" << endl;
    cout << "4 sell chips" << endl;
    cout << "5 obtain key" << endl;
    cout << "6 exit" << endl << endl;
    cout << "Select: ";
    cin >> choice;
    if (choice == 1){
        bet();
        casino();
    }

    else if (choice == 2){
        int amount = 0;
        if (balance == 0){
            system("tput setaf 2");
            cout << "\nI see you have no balance. Here is 2$. Consider it a gift.\n" << endl;
            system("tput sgr0");
            balance = balance + 2;
            casino();
        }
        else if (amount <= balance){
            cout << "\nSelect the amount of chips you would like to purchase: ";
            cin >> amount;
            cout << endl;
            if (!cin){
                system("tput setaf 1");
                cout << "\nIncorrect Value!\n" << endl;
                system("tput sgr0");
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                balance = balance - amount;
                chips = chips + amount;
                if (balance < 0 || amount < 0 || chips < 0){
                    system("tput setaf 1");
                    cout << "\nYou do not have sufficient funds to purchase chips!" << endl;
                    system("tput sgr0");
                    balance = balance + amount;
                    chips = chips - amount;
                }
            }
        }
        else {
            system("tput setaf 1");
            cout << "\nYou do not have sufficient funds to purchase chips!\n" << endl;
            system("tput sgr0");
        }

        system("tput setaf 2");       
        cout << "\nBalance: " << balance << "$" << "   Chips: " << chips << endl << endl;
        system("tput sgr0");
    }

    else if (choice == 3){
        system("tput setaf 2");       
        cout << "\nBalance: " << balance << "$" << "   Chips: " << chips << endl << endl;
        system("tput sgr0");
    }

    else if (choice == 4){
        int amount = 0;
        cout << "\nSelect the amount of chips you would like to sell: ";
        cin >> amount;
        cout << endl;
        if (!cin){
            system("tput setaf 1");
            cout << "\nIncorrect Value!\n" << endl;
            system("tput sgr0");
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (amount <= chips && chips != 0 && chips > 0){
            chips = chips - amount;
            balance = balance + (amount / 2);
            if (chips < 0){
                chips = chips + amount;
                balance = balance - (amount /2);
                system("tput setaf 1");
                cout << "Insufficient Chips!" << endl;
                system("tput sgr0");
            }
        }

        else {
            system("tput setaf 1");
            cout << "Insufficient Chips!" << endl;
            system("tput sgr0");
        }

        system("tput setaf 2");       
        cout << "\nBalance: " << balance << "$" << "   Chips: " << chips << endl << endl;
        system("tput sgr0");
    }


    else if (choice == 5){
        int key = 18237;
        int key_or_not = 0;
        if (balance >= 9999){
            cout << "Congratulations, you have enough money to purchase the key" << endl;
            cout << "Purchase now?[0/1]: ";
            cin >> key_or_not;
            cout << endl;
            if (!cin || key_or_not > 1 || key_or_not < 0){
                system("tput setaf 1");
                cout << "\nNot an option\n" << endl;
                system("tput sgr0");
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            else if (key_or_not == 1){
                system("tput setaf 2");
                cout << "The key is: " << key << endl << endl;
                system("tput sgr0");
                balance = balance - 10000;
                casino();
            }

            else if (key_or_not == 0){
                system("tput setaf 3");
                cout << "No worries, come back later when you are ready\n" << endl;
                system("tput sgr0");
                casino();
            }
        }

        else {
            cout << "You do not have the balance to purchase a key\n" << endl;
            casino();
        }
    }

    else if (choice == 6){
        system("tput setaf 2");
        cout << "\nHave a nice day!\n" << endl;
        system("tput sgr0");
        exit(0);
    }
    else if (!cin){
        system("tput setaf 1");
        cout << "\nNot an option\n" << endl;
        system("tput sgr0");
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    
    else {
        system("tput setaf 1");
        cout << "\nNot an option\n" << endl;
        system("tput sgr0");
    }
    casino();
    return 0;
}

int main(){
    signal(SIGINT, signal_callback_handler);
    banner();
    casino();

    return 0;
}