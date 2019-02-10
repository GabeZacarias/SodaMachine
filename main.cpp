#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <windows.h>


using namespace std;

struct machine
{
    string drinkName;
    double drinkCost;
    int numberOfDrinks;
};

void selectionHeader();
void insideMachine(machine[]);
int menuList(machine p[]);
void userPayment(double, int);


int main()
{

    machine drinkList[5];

    int choice;
    double made = 0;

    insideMachine(drinkList);
    choice = menuList(drinkList);

    while (choice != 5) //will add 1 to what ever number user put to match console screen (5 will be 6 in console)
        {

            if (choice != 5 && drinkList[choice].numberOfDrinks > 0)
                {
                    userPayment(drinkList[choice].drinkCost, drinkList[choice].numberOfDrinks);
                    made += drinkList[choice].drinkCost;
                    drinkList[choice].numberOfDrinks--;
                    choice = menuList(drinkList);
                }
            else
                {
                    Sleep(1500);
                    system("CLS");
                    choice = menuList(drinkList);
                }
        }


	return 0;
}


void insideMachine(machine p[])
{
    p[0].drinkName = "Coke      ";
    p[0].drinkCost = 0.75;
    p[0].numberOfDrinks = 20;

    p[1].drinkName = "Root Beer ";
    p[1].drinkCost = 0.75;
    p[1].numberOfDrinks = 20;

    p[2].drinkName = "Lemon-Lime";
    p[2].drinkCost = 0.75;
    p[2].numberOfDrinks = 20;

    p[3].drinkName = "Grape Soda";
    p[3].drinkCost = 0.80;
    p[3].numberOfDrinks = 20;

    p[4].drinkName = "Cream Soda";
    p[4].drinkCost = 0.80;
    p[4].numberOfDrinks = 20;
}

int menuList(machine p[])
{
    int i;
    int choice = 8;
    bool soldOut = true;

    while ((choice < 1) || (choice > 6) || soldOut)
        {
           soldOut = false;

           cout << endl;
           cout << setw(66) << "_____________________________________________________________" << endl << endl;
           cout << setw(20) << "Drink Name" << setw(15) << "Cost" << setw(25) << "Number in Machine" << endl;
           cout << setw(66) << "_____________________________________________________________" << endl << endl;

           for (i = 0; i < 5; i++)
                {
                    cout << fixed << showpoint << setprecision(2);
                    cout << setw(8) << i + 1 << ")" << setw(11) <<p[i].drinkName << setw(12) << "$ " << p[i].drinkCost;
                    cout << setw(10) << "(" << p[i].numberOfDrinks << ") " << "remaining" << endl;
                }

           cout << setw(33) << "6) Leave the drink machine" << endl << endl;
           cout << setw(19) << "Choose One: ";
           cin >> choice;

            if ((choice < 1) || (choice > 6))
                {
                    cout << endl << setw(60) << "An error has occurred, please try again." << endl << endl;
                    Sleep(2000);
                    system("CLS");
                }

            if (choice == 6)
                break;
        }

             if (p[choice - 1].numberOfDrinks == 0)
                {
                    cout << endl << setw(15) << "Sold Out" << endl;
                }

    return choice - 1;
}

void userPayment(double p, int n)
{
    double pay;

    cout << endl << setw(34) << "Enter an amount of money: $";
    cin >> pay;

    while (pay < p)
        {
            cout << endl << setw(48) << "Not enough funds, restarting transaction." << endl;
            Sleep(4000);
            system("CLS");
            return;
        }

    cout << endl << setw(34) << "Thump, thump, thump, splat!" << endl;
    cout << setw(27) << "Enjoy your beverage!" << endl << endl;
    Sleep(2500);
    cout << setw(27) << "Change calculated: $" << pay - p << endl;
    cout << setw(21) << "Your change: $" << pay - p << setw(30) << " has just dropped into the Change Dispenser." << endl;
    cout << endl << setw(17) << "There are " << n - 1 << " drinks of that type left." << endl;
    Sleep(5500);
    system("CLS");

    return;
}
