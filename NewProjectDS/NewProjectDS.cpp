#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include "Wallet.cpp"

using namespace std;




using namespace std;
int main()
{

    double sumCash = 0, sumCredit = 0;
    int num_wallet;
    int option;
    Wallet cash;
    Wallet credit_card;

    while (true)
    {
		



        cout << "----------------------------------------------------------------------\n";
        cout << "\t\t\tType of the Wallet \n\n";
        cout << "(1) Cash \n(2) credit card \n";

        cin >> num_wallet;

        system("cls");
        cout << "\n----------------------------------------------------------------------\n";
        cout << "\t\t\t Menu\n\n";
        cout << "(1) Add new Data " << endl;
        cout << "(2) View All Data " << endl;
        cout << "(3) Filter " << endl;
        cout << "(4) View saving & dept " << endl;
        cout << "(5) Expenses for each month " << endl;
        cout << "(6) Exit " << endl;

        cin >> option;

        if (option == 1)
        {
            if (num_wallet == 1)
            {
                cash.enterData(cash.myFile, "cash.csv");
            }

            else if (num_wallet == 2)
            {
                credit_card.enterData(credit_card.myFile, "credit card.csv");
            }

            break;
        }

        else if (option == 2)
        {
			system("cls");
            if (num_wallet == 1)
                cash.display_allData(cash.myFile, "cash.csv");

            else if (num_wallet == 2)
                credit_card.display_allData(credit_card.myFile, "credit card.csv");
        }

        else if (option == 3)
        {
			system("cls");
			cout << "1-Filter by One " << endl;
			cout << "2-Filter by Two " << endl;
			cout << "3-Filter by Three" << endl;

			cout << " Enter Your Option:  " << endl;
			int typeFilter;
			cin >> typeFilter;

			if (typeFilter == 1)
			{
		

				cout << "1- Filter by Date" << endl;
				cout << "2- Filter by Categroy" << endl;
				cout << "3- Filter by Amount" << endl;

				cout << "Enter Your Option:  " << endl;
				int number;
				cin >> number;

				if (number == 1)
				{
					int dayy; int mon;
					int op;
					cout << "1- Filter by Day" << endl;
					cout << "2- Filter by Month" << endl;
					cout << "3- Filter by Day & Month" << endl;
					cin >> op;

					if (op == 1)
					{
						cout << "Day : ";
						cin >> dayy;

						if (num_wallet == 1)
						{
							cash.filter_Day(dayy,cash.myFile, "cash.csv");
						}

						else if (num_wallet == 2)
						{
							credit_card.filter_Day(dayy, credit_card.myFile, "credit card.csv");
						}

					}
					else if (op == 2)
					{
						cout << "Month : ";
						cin >> mon;

						if (num_wallet == 1)
						{
							cash.filter_Month( mon, cash.myFile, "cash.csv");
						}

						else if (num_wallet == 2)
						{
							credit_card.filter_Month(mon, credit_card.myFile, "credit card.csv");
						}

					}
					else if (op == 3)
					{
						
						cout << "Date :-\n";
						cout << "Day : ";
						cin >> dayy;
						cout << "Month : ";
						cin >> mon;


						if (num_wallet == 1)
						{
							cash.filter_Date(dayy, mon, cash.myFile, "cash.csv");
						}

						else if (num_wallet == 2)
						{
							credit_card.filter_Date(dayy, mon, credit_card.myFile, "credit card.csv");
						}

					}

						

				}

				else if (number == 2)
				{
					string category;
					cout << "Enter Category : ";
					cin >> category;

					if (num_wallet == 1)
					{
				      cash.filter_Category( category, cash.myFile, "cash.csv");
					}

					else if (num_wallet == 2)
					{
						credit_card.filter_Category(category,  credit_card.myFile, "credit card.csv");
					}

				}
				else if (number == 3)
				{
					double amount;
					cout << "enter the amount: ";
					cin >> amount;


					if (num_wallet == 1)
					{
						cash.filter_Amount(amount, cash.myFile, "cash.csv");
					}

					else if (num_wallet == 2)
					{
						credit_card.filter_Amount(amount, credit_card.myFile, "credit card.csv");
					}
				}

			}
			else if (typeFilter == 2)
			{
				
				cout << "1- Filter by Date and Amount" << endl;
				cout << "2- Filter by Date and Categroy" << endl;
				cout << "3- Filter by Category and Amount" << endl;

				cout << "Enter Your Option:  " << endl;
				int number;
				cin >> number;

				if (number == 1)
				{
					int day;
					cout << "Day : ";
					cin >> day;
					int month;
					cout << "Month : ";
					cin >> month;
					int amount;
					cout << "Amount : ";
					cin >> amount;

					if (num_wallet == 1)
					{
						cash.Filter_Date_amount(day, month, amount, cash.myFile, "cash.csv");

					}

					else if (num_wallet == 2)
					{
						credit_card.Filter_Date_amount(day, month, amount, credit_card.myFile, "credit card.csv");

					}



				}
				else if (number == 2)
				{
					int day;
					cout << "Day : ";
					cin >> day;
					int month;
					cout << "Month : ";
					cin >> month;
					string category;
					cout << "Category : ";
					cin >> category;

					if (num_wallet == 1)
					{
						cash.Filter_Date_Category(day, month, category, cash.myFile, "cash.csv");

				
					}

					else if (num_wallet == 2)
					{
						credit_card.Filter_Date_Category(day, month, category, credit_card.myFile, "credit card.csv");

					}

				}
				else if (number == 3)
				{
					string category;
					cout << "Category : ";
					cin >> category;
					int amount;
					cout << "Amount : ";
					cin >> amount;

					if (num_wallet == 1)
					{
						cash.Filter_Category_amount(category, amount, cash.myFile, "cash.csv");

					}

					else if (num_wallet == 2)
					{
						credit_card.Filter_Category_amount(category, amount, credit_card.myFile, "credit card.csv");

					}

				}
				
			}
			else if (typeFilter == 3)
			{
			   
				int day;
				cout << "Day : ";
				cin >> day;
				int month;
				cout << "Month : ";
				cin >> month;
				string category;
				cout << "Category : ";
				cin >> category;
				int amount;
				cout << "Amount: ";
				cin >> amount;


				if (num_wallet == 1)
				{
					cash.filterrby4(day, month, category, amount, cash.myFile, "cash.csv");

				}

				else if (num_wallet == 2)
				{
					credit_card.filterrby4(day, month, category, amount, credit_card.myFile, "credit card.csv");

				}

			}

        }
		
        else if (option == 4)
		{
		system("cls");
			if (num_wallet == 1)
			{
				sumCash = cash.sumAmount(cash.myFile, "cash.csv");
				double saving = 0, dept = 0;

				if (cash.monthly_income - sumCash < 0)
					dept = abs(cash.monthly_income - sumCash);

				else if (cash.monthly_income - sumCash >= 0)
					saving = abs(cash.monthly_income - sumCash);

				cout << "Saving: " << saving << "\n";
				cout << "Dept: " << dept << '\n';

			}

			else if (num_wallet == 2)
			{
				sumCredit = credit_card.sumAmount(credit_card.myFile, "credit card.csv");

				double saving = 0, dept = 0;

				if (credit_card.monthly_income - sumCredit < 0)
					dept = abs(credit_card.monthly_income - sumCredit);

				else if (credit_card.monthly_income - sumCredit >= 0)
					saving = abs(credit_card.monthly_income - sumCredit);


				cout << "Saving: " << saving << "\n";
				cout << "Dept: " << dept << '\n';


			}
		}

        else if (option == 5)
        {
		system("cls");
		cout << "Your Expences \n";

		if (num_wallet == 1)
		{
			cash.monthltExpenses(cash.myFile, "cash.csv");
		}

		else if (num_wallet == 2)
		{
			credit_card.monthltExpenses(credit_card.myFile, "credit card.csv");
		}

        }

		else if (option == 6)
        {
		break;
        }
      

    }
    
    return 0;
}



