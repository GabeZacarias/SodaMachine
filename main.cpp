#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <windows.h>
#include <string>


using namespace std;

struct machine
{
	string drinkName;
	double drinkCost;
	int numberOfDrinks;
};

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
	p[0].drinkName = "Pepsi     ";
	p[0].drinkCost = 2.00;
	p[0].numberOfDrinks = 10;

	p[1].drinkName = "Mtn Dew   ";
	p[1].drinkCost = 2.00;
	p[1].numberOfDrinks = 10;

	p[2].drinkName = "Sprite    ";
	p[2].drinkCost = 2.00;
	p[2].numberOfDrinks = 10;

	p[3].drinkName = "Red Bull  ";
	p[3].drinkCost = 3.00;
	p[3].numberOfDrinks = 10;

	p[4].drinkName = "Water     ";
	p[4].drinkCost = 1.50;
	p[4].numberOfDrinks = 10;
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
			cout << setw(8) << i + 1 << ")" << setw(11) << p[i].drinkName << setw(12) << "$ " << p[i].drinkCost;
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
	boolean remaining = false;

	while (remaining == false)
	{
		cout << endl << setw(34) << "Enter an amount of money: $";
		cin >> pay;

		if (pay > 10)
		{
			cout << endl << setw(72) << "Machine only accepts maximum $10. Please enter lower bill amount." << endl;
			Sleep(5000);
		}

		if (pay < p)
		{
			cout << endl << setw(44) << "Not enough funds, insert money again." << endl;
			Sleep(4000);
		}

		else if (pay >= p && pay <= 10)
		{
			cout << endl << setw(29) << "*soda being dispensed*";
			Sleep(2000);
			cout << endl << setw(27) << "Change calculated: $" << pay - p << endl;
			Sleep(3500);
			system("CLS");
			remaining = true;
		}
	}
}
