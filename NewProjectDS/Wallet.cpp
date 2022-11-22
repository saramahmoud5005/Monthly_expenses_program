#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>

#include "Wallet.h"



Wallet::Wallet(){}

void Wallet::enterData(fstream& myFile, string filename)
{
	myFile.open(filename, ios::app | ios::in | ios::out);

	int t;
	cout << "How many entries ? \n";
	cin >> t;
	while (t--)
	{
		cout << '\n' << "Day : ";
		cin >> date.day;
		myFile << date.day << ",";

		cout << "Month : ";
		cin >> date.month;
		myFile << date.month << ",";


		string category;
		cout << "Category : ";
		cin >> category;
		myFile << category << ",";

		double amount;
		cout << "Amount : ";
		cin >> amount;
		myFile << amount << ",";

		myFile << "\n";

	}
	//myFile.close();
}

void Wallet::get_allData(fstream& myFile, string filename)
{
	if (!myFile.is_open())
		myFile.open(filename);

	if (!myFile.good())
		myFile.clear();

	// insert data from file to string
	while (myFile.good())
	{
		string line;
		getline(myFile, line, '\n');
		string_Data += line;
	}

	///insert data from string to vector
	for (int i = 0; i < string_Data.size(); i++)
	{
		while (true)
		{
			new_S += string_Data[i];
			i++;

			if (string_Data[i] == ',')
			{
				temp.push_back(new_S);
				break;
			}
		}
		new_S.clear();
	}
	string_Data.clear();

	////insert data from vector  to map
	int count = 0;
	while (count < temp.size())
	{
		int da = stoi(temp[count]);
		int mo = stoi(temp[count + 1]);
		double am = stod(temp[count + 3]);
		
		/////////day//////month////////////cat///////amount
		all_Data[{da, mo}].first = temp[count + 2];
		all_Data[{ da, mo}].second = am;
		count += 4;
	}
	temp.clear();

	myFile.close();
}

void  Wallet::display_allData(fstream& myFile, string filename)
{
	get_allData(myFile, filename);

	if (!myFile.is_open())
		myFile.open(filename);


	if (!myFile.good())
		myFile.clear();

	cout << "--------------Display ALL DATA-------------" << endl;
	for (itr = all_Data.begin(); itr != all_Data.end(); ++itr)
	{
			cout << "DAY : " << itr->first.first << "\t";
			cout << "Month : " << itr->first.second << "\t";
			cout << "CATEGORY : " << itr->second.first << "\t";
			cout<< "AMOUNT : " << itr->second.second << "\t";
			cout << '\n';
	}

	myFile.close();
}

void Wallet::Filter_Date_Category(int Day, int Month, string Categroy, fstream& myFile, string filename)
{
	
	if (!myFile.is_open())
		myFile.open(filename);

	if (!myFile.good())
		myFile.clear();

	string day;
	string month;
	string category;
	string amount;

	string dd = " *Day :";
	string mm = " *Month:";
	string cc = " *Category:";
	string aa = " *Amount:";

	while (myFile.good()) {

		getline(myFile, day, ',');
		vector <string> v;
		vector <string> s;
		v.push_back(day);
		int d = atoi(day.c_str());
		getline(myFile, month, ',');
		v.push_back(month);
		int m = atoi(month.c_str());
		getline(myFile, category, ',');
		v.push_back(category);
		string  c = category;
		getline(myFile, amount, '\n');
		v.push_back(amount);

		s.push_back(dd);
		s.push_back(mm);
		s.push_back(cc);
		s.push_back(aa);

		isFound = false;
		for (int i = 0; i < v.size(); i++)
		{
			if (Day == d && Month == m && Categroy == c)
			{
				cout << s[i] << " ";
				cout << v[i] << endl;
				isFound = true;
			}
		}
	}
	if (isFound)
	{
		cout << "------Not Found in Your Expenses-----" << endl;
	}
	myFile.close();
}


void Wallet::Filter_Date_amount(int Day, int Month, int Amount, fstream& myFile, string filename)
{
	
	if (!myFile.is_open())
		myFile.open(filename);

	if (!myFile.good())
		myFile.clear();

	string day;
	string month;
	string category;
	string amount;

	string dd = " *Day :";
	string mm = " *Month:";
	string cc = " *Category:";
	string aa = " *Amount:";

	while (myFile.good()) {

		getline(myFile, day, ',');
		vector <string> v;
		vector<string> s;
		v.push_back(day);
		int d = atoi(day.c_str());
		getline(myFile, month, ',');
		v.push_back(month);
		int m = atoi(month.c_str());
		getline(myFile, category, ',');
		v.push_back(category);
		string  c = category;
		getline(myFile, amount, '\n');
		v.push_back(amount);
		int a = atoi(amount.c_str());

		s.push_back(dd);
		s.push_back(mm);
		s.push_back(cc);
		s.push_back(aa);


		isFound = false;
		for (int i = 0; i < v.size(); i++)
		{

			if (Day == d && Month == m && Amount == a)
			{

				cout << s[i] << "";

				cout << v[i] << endl;
				isFound = true;
			}
		}

	}
	if (isFound)
	{
		cout << "------Not Found in Your Expenses-----" << endl;
	}

	myFile.close();

}


void Wallet::Filter_Category_amount(string Categroy, int Amount, fstream& myFile, string filename)
{
	
	if (!myFile.is_open())
		myFile.open(filename);

	if (!myFile.good())
		myFile.clear();

	string day;
	string month;
	string category;
	string amount;



	string dd = " *Day :";
	string mm = " *Month:";
	string cc = " *Category:";
	string aa = " *Amount:";

	while (myFile.good()) {

		getline(myFile, day, ',');
		vector <string> v;
		vector<string>s;
		v.push_back(day);
		int d = atoi(day.c_str());
		getline(myFile, month, ',');
		v.push_back(month);
		int m = atoi(month.c_str());
		getline(myFile, category, ',');
		v.push_back(category);
		string  c = category;
		getline(myFile, amount, '\n');
		v.push_back(amount);
		int a = atoi(amount.c_str());

		s.push_back(dd);
		s.push_back(mm);
		s.push_back(cc);
		s.push_back(aa);

		isFound = false;
		for (int i = 0; i < v.size(); i++)
		{
			if (Amount == a && Categroy == c)
			{

				cout << s[i] << " ";
				cout << v[i] << endl;
				isFound = true;
			}
		}

	}
	if (isFound)
	{
		cout << "------Not Found in Your Expenses-----" << endl;
	}
	myFile.close();
}


void Wallet::filterrby4(int dayy, int monthh, string categoryy, int amountt, fstream& myFile, string filename)
{
	
	if (!myFile.is_open())
		myFile.open(filename);

	if (!myFile.good())
		myFile.clear();

	string day;
	string month;
	string category;
	string amount;

	string dd = " *Day :";
	string mm = " *Month:";
	string cc = " *Category:";
	string aa = " *Amount:";

	while (myFile.good()) {

		getline(myFile, day, ',');
		vector <string> v;
		vector <string>s;
		v.push_back(day);
		int d = atoi(day.c_str());
		getline(myFile, month, ',');
		v.push_back(month);
		int m = atoi(month.c_str());
		getline(myFile, category, ',');
		v.push_back(category);
		string  c = category;
		getline(myFile, amount, '\n');
		v.push_back(amount);
		int a = atoi(amount.c_str());

		s.push_back(dd);
		s.push_back(mm);
		s.push_back(cc);
		s.push_back(aa);

		isFound = false;
		for (int i = 0; i < v.size(); i++)
		{
			if (dayy == d && monthh == m && categoryy == c && amountt == a)
			{
				cout << s[i] << " ";
				cout << v[i] << endl;
				isFound = true;
			}
		}


	}
	if (isFound)
	{
		cout << "------Not Found in Your Expenses-----" << endl;
	}
	myFile.close();
}

void Wallet::filter_Date(int day, int mymonth, fstream& myFile, string filename)
{
	



	get_allData(myFile, filename);

	if (!myFile.is_open())
		myFile.open(filename);

	if (!myFile.good())
		myFile.clear();

	for_day.mymonth.clear();
	for_day.day.clear();
	for_day.category.clear();
	for_day.amount.clear();

	for (itr = all_Data.begin(); itr != all_Data.end(); ++itr)
	{
		for_day.day.push_back(itr->first.first);
		for_day.mymonth.push_back(itr->first.second);
		for_day.category.push_back(itr->second.first);
		for_day.amount.push_back(itr->second.second);
	}


	
	isFound = false;
	cout << "--------------Filter By Date--------------\n";
	for (int i = 0; i < for_day.day.size(); i++)
	{
		if (day == for_day.day[i] && mymonth == for_day.mymonth[i])
		{
			cout << "\nDay: " << for_day.day[i];
			cout << "\tMonth:" << for_day.mymonth[i];
			cout << "\tCategory: " << for_day.category[i];
			cout << "\tAmount: " << for_day.amount[i] << "\n";
		
			isFound = true;
		}
	}
	if (!isFound)
	{
		cout << "------Not Found in Your Expenses-----" << endl;
	}
	myFile.close();
}

void Wallet::filter_Category(string category, fstream& myFile, string filename)
{
	get_allData(myFile, filename);

	if (!myFile.is_open())
		myFile.open(filename);

	if (!myFile.good())
		myFile.clear();

	for_day.mymonth.clear();
	for_day.day.clear();
	for_day.category.clear();
	for_day.amount.clear();

	for (itr = all_Data.begin(); itr != all_Data.end(); ++itr)
	{
		for_day.day.push_back(itr->first.first);
		for_day.mymonth.push_back(itr->first.second);
		for_day.category.push_back(itr->second.first);
		for_day.amount.push_back(itr->second.second);
	}

	isFound = false;
	cout << "--------------Filter By Category--------------\n";
	for (int i = 0; i < for_day.category.size(); i++)
	{
		if (category == for_day.category[i])
		{
			cout << "\nday: " << for_day.day[i] << "\nmonth:" << for_day.mymonth[i];
			cout << "\ncategory: " << for_day.category[i];
			cout << "\namount: " << for_day.amount[i] << "\n";
			isFound = true;
		}
	}
	if (!isFound)
	{
		cout << "------Not Found in Your Expenses-----" << endl;
	}
	myFile.close();
}

void Wallet::filter_Amount(double amount, fstream& myFile, string filename)
{
	get_allData(myFile, filename);

	if (!myFile.is_open())
		myFile.open(filename);

	if (!myFile.good())
		myFile.clear();

	for_day.mymonth.clear();
	for_day.day.clear();
	for_day.category.clear();
	for_day.amount.clear();

	for (itr = all_Data.begin(); itr != all_Data.end(); ++itr)
	{
		for_day.day.push_back(itr->first.first);
		for_day.mymonth.push_back(itr->first.second);
		for_day.category.push_back(itr->second.first);
		for_day.amount.push_back(itr->second.second);
	}
	isFound = false;

	cout << "--------------Filter By Amount--------------\n";
	for (int i = 0; i < for_day.amount.size(); i++)
	{
		if (amount == for_day.amount[i])
		{
			cout << "\nday: " << for_day.day[i] << "\nmonth:" << for_day.mymonth[i];
			cout << "\ncategory: " << for_day.category[i];
			cout << "\namount: " << for_day.amount[i] << "\n";
			isFound = true;
		}
	}

	if (!isFound)
	{
		cout << "------Not Found in Your Expenses-----" << endl;
	}
	myFile.close();
}

void Wallet::filter_Day(int day, fstream& myFile, string filename)
{

	get_allData(myFile, filename);

	if (!myFile.is_open())
		myFile.open(filename);

	if (!myFile.good())
		myFile.clear();

	for_day.mymonth.clear();
	for_day.day.clear();
	for_day.category.clear();
	for_day.amount.clear();

	for (itr = all_Data.begin(); itr != all_Data.end(); ++itr)
	{
	     	for_day.day.push_back(itr->first.first);
			for_day.mymonth.push_back(itr->first.second);
			for_day.category.push_back(itr->second.first);
			for_day.amount.push_back(itr->second.second);
	}

	cout << "--------------Filter By Day--------------\n";
	isFound = false;
	for (int i = 0; i < for_day.day.size(); i++)
	{
		if (day == for_day.day[i])
		{
			cout << "\nDay: " << for_day.day[i];
			cout << "\tMonth:" << for_day.mymonth[i];
			cout << "\tCategory: " << for_day.category[i];
			cout << "\tAmount: " << for_day.amount[i] << "\n";

			isFound = true;

		}

	}

	if (!isFound)
	{
		cout << "------Not Found in Your Expenses-----" << endl;
	}
	myFile.close();
}

void Wallet::filter_Month(int month, fstream& myFile, string filename)
{

	get_allData(myFile, filename);

	if (!myFile.is_open())
		myFile.open(filename);

	if (!myFile.good())
		myFile.clear();

	for_day.mymonth.clear();
	for_day.day.clear();
	for_day.category.clear();
	for_day.amount.clear();

	for (itr = all_Data.begin(); itr != all_Data.end(); ++itr)
	{
		for_day.day.push_back(itr->first.first);
		for_day.mymonth.push_back(itr->first.second);
		for_day.category.push_back(itr->second.first);
		for_day.amount.push_back(itr->second.second);
	}

	cout << "--------------Filter By Month--------------\n";
	isFound = false;
	for (int i = 0; i < for_day.day.size(); i++)
	{
		if (month == for_day.mymonth[i])
		{
			cout << "\nDay: " << for_day.day[i];
			cout << "\tMonth:" << for_day.mymonth[i];
			cout << "\tCategory: " << for_day.category[i];
			cout << "\tAmount: " << for_day.amount[i] << "\n";
			isFound = true;
		}

	}
	if (!isFound)
	{
		cout << "------Not Found in Your Expenses-----" << endl;
	}
	myFile.close();
}
	void Wallet::monthltExpenses(fstream & myFile, string filename)
	{
		get_allData(myFile, filename);

		amounts_every_month[1] = { "Jan",0 };
		amounts_every_month[2] = { "Feb",0 };
		amounts_every_month[3] = { "Mar",0 };
		amounts_every_month[4] = { "Apr",0 };
		amounts_every_month[5] = { "May",0 };
		amounts_every_month[6] = { "Jun",0 };
		amounts_every_month[7] = { "Jul",0 };
		amounts_every_month[8] = { "Aug",0 };
		amounts_every_month[9] = { "Sep",0 };
		amounts_every_month[10] = { "Oct",0 };
		amounts_every_month[11] = { "Nov",0 };
		amounts_every_month[12] = { "Dec",0 };



		for (itr = all_Data.begin(); itr != all_Data.end(); ++itr)
		{
			int tmp = itr->first.second;
			amounts_every_month[tmp].second += itr->second.second;
		}

		for (auto i : amounts_every_month)
		{
			cout << i.second.first << " : " << i.second.second << '\n';
		}
		myFile.close();
	}

	double Wallet::sumAmount(fstream & myFile, string filename)
	{
		get_allData(myFile, filename);

		if (!myFile.is_open())
			myFile.open(filename);

		if (!myFile.good())
			myFile.clear();


		for (itr = all_Data.begin(); itr != all_Data.end(); ++itr)
		{
			sum_amount += itr->second.second;
		}

		myFile.close();
		return sum_amount;
	}

Wallet :: ~Wallet()
{
	myFile.close();
}



