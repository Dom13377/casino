#include <iostream>
#include <random>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <stdio.h>
#include <windows.h>
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int balance = 200;
int chips = 0;
int betamount = 0;

void signal_callback_handler(int signum){
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        cout << "\n\nHave a nice day!" << endl << endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        exit(signum);
    }

int bet(){
    cout << "Seclect amount of chips to bet: ";
    cin >> betamount;
    cout << endl;
    if (!cin){
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        cout << "\nIncorrect Value!\n" << endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    else if (betamount > chips || betamount <= 0){
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        cout << "\nInsufficient funds!\n" << endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }

    else {
        int roll = 0;
        int again = 0;
        cout << "Rolling..." << endl;
        system("sleep 1");
        roll = (rand() % 2) + 1;
        if (roll == 1){
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            cout << "\nYou lose\n" << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            chips = chips - betamount;
            if (chips < 0){
                chips = 0;
            }
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);    
            cout << "\nBalance: " << "$" << balance << "   Chips: " << chips << endl << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
        else if (roll == 2){
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            cout << "\nYou win\n" << endl;
            chips = chips + (betamount * 2);       
            cout << "\nBalance: " << "$" << balance << "   Chips: " << chips << endl << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
        cout << "\nWould you like to play again?[0/1]: ";
        cin >> again;
        cout << endl;
        if (!cin || again > 1 || again < 0){
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            cout << "\nIncorrect Value!\n" << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
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
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    cout << "-------------" << endl;
    cout << "Casino Gamble" << endl;
    cout << "-------------\n" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    return 0;
}

int casino(){
    srand(time(0));
    int choice;
    cout << "Welcome to Casino Gamble. You can bet, buy chips, or check your balance:\n" << endl;
    cout << "1 bet" << endl;
    cout << "2 games" << endl;
    cout << "3 buy chips" << endl;
    cout << "4 check balance" << endl;
    cout << "5 sell chips" << endl;
    cout << "6 obtain key" << endl;
    cout << "7 exit" << endl << endl;
    cout << "Select: ";
    cin >> choice;
    if (choice == 1){
        bet();
        casino();
    }

    if (choice == 2){
        cout << "\n1 slot machine" << endl;
        cout << "2 russian roulette" << endl << endl;
        cout << "Select: ";
        cin >> choice;
        cout << endl;
        if (!cin){
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            cout << "\nIncorrect Value!\n" << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (choice == 1){
            cout << "Select the amount of chips to bet 30 or higher: ";
            cin >> betamount;
            cout << endl;
            if (betamount >= 30){
                if (!cin || betamount > chips || betamount <= 0){
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    cout << "\nIncorrect Value!\n" << endl;
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
        
                else {
                    char a = 'a' + rand()%10;
                    char b = 'a' + rand()%10;
                    char c = 'a' + rand()%10;
                    cout << "\n";
                    cout << "---" << endl;
                    cout << a;
                    system("sleep 1");
                    cout << b;
                    system("sleep 1");
                    cout << c << endl;
                    cout << "---" << endl << endl;

                    if (a == b || a == c || c == b){
                        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                        cout << "You win!" << endl;
                        chips = chips + (betamount);
                        cout << "\nBalance: " << "$" << balance << "   Chips: " << chips << endl << endl;
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    }

                    else if (a == b && b == c && a == c){
                        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                        cout << "Jackpot!" << endl;
                        chips = chips + (betamount * 3);
                        cout << "\nBalance: " << "$" << balance << "   Chips: " << chips << endl << endl;
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    }

                    else {
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        cout << "\nYou lose!\n" << endl;
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        chips = chips - betamount;
                        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);    
                        cout << "\nBalance: " << "$" << balance << "   Chips: " << chips << endl << endl;
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    }
                }
            }
            else {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                cout << "\nBet amount must be 100 or greater!\n" << endl;
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
        }

        else if (choice == 2){
            
        }
        else {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            cout << "Invalid Option!" <<endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            casino();
        }
    }

    else if (choice == 3){
        int amount = 0;
        if (balance == 0){
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            cout << "\nI see you have no balance. Here is $10. Consider it a gift.\n" << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            balance = balance + 10;
            casino();
        }
        else if (amount <= balance){
            cout << "\nSelect the amount of chips you would like to purchase: ";
            cin >> amount;
            cout << endl;
            if (!cin){
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                cout << "\nIncorrect Value!\n" << endl;
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                balance = balance - amount;
                chips = chips + amount;
                if (balance < 0 || amount < 0 || chips < 0){
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    cout << "\nYou do not have sufficient funds to purchase chips!" << endl;
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    balance = balance + amount;
                    chips = chips - amount;
                }
            }
        }
        else {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            cout << "\nYou do not have sufficient funds to purchase chips!\n" << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }

        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);       
        cout << "\nBalance: " << "$" << balance << "   Chips: " << chips << endl << endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }

    else if (choice == 4){
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);       
        cout << "\nBalance: " << "$" << balance << "   Chips: " << chips << endl << endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }

    else if (choice == 5){
        int amount = 0;
        cout << "\nSelect the amount of chips you would like to sell: ";
        cin >> amount;
        cout << endl;
        if (!cin || amount == 1){
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            cout << "\nIncorrect Value!\n" << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (amount <= chips && chips != 0 && chips > 0){
            chips = chips - amount;
            balance = balance + (amount / 2);
            if (chips < 0){
                chips = chips + amount;
                balance = balance - (amount /2);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                cout << "Insufficient Chips!" << endl;
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
        }

        else {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            cout << "Insufficient Chips!" << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }

        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);       
        cout << "\nBalance: " << "$" << balance << "   Chips: " << chips << endl << endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }


    else if (choice == 6){
        int key2 = 5;
        int key1 = 6;
        int key5 = 2;
        int key3 = 0;
        int key4 = 9;
        int key_or_not = 0;
        if (balance >= 2999){
            cout << "Congratulations, you have enough money to purchase the key" << endl;
            cout << "Purchase now?[0/1]: ";
            cin >> key_or_not;
            cout << endl;
            if (!cin || key_or_not > 1 || key_or_not < 0){
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                cout << "\nNot an option\n" << endl;
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            else if (key_or_not == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                cout << "The key is: " << key1 << key2 << key3 << key4 << key5 << endl << endl;
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                balance = balance - 3000;
                casino();
            }

            else if (key_or_not == 0){
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
                cout << "No worries, come back later when you are ready\n" << endl;
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                casino();
            }
        }

        else {
            cout << "You do not have the balance to purchase a key, you need $3000\n" << endl;
            casino();
        }
    }

    else if (choice == 7){
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        cout << "\nHave a nice day!\n" << endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        exit(0);
    }
    else if (!cin){
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        cout << "\nNot an option\n" << endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    
    else {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        cout << "\nNot an option\n" << endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
    casino();
    return 0;
}

int main(){
    signal(SIGINT, signal_callback_handler);
    banner();
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    casino();

    return 0;
}