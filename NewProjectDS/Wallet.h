#pragma once
#include <vector>
#include <map>
#include <string>
#include <fstream>



using namespace std;

class Wallet
{
public :




	double monthly_income = 5000;
	double sum_amount = 0;
	map<int, pair<string, double>>amounts_every_month;

	bool isFound ;

	struct Date {
		int day;
		int month;
	}date;






	fstream myFile;

	vector < string > temp;
	string new_S;
	string string_Data;

	map < pair < int, int >,  pair < string, double > >  all_Data;
	map < pair < int, int >,  pair < string, double > > ::iterator  itr;
	
	struct daily_expenses
	{
		vector<int>day;
		vector<int>mymonth;
		vector<double> amount;
		vector<string>category;

	}for_day;

	inline Wallet();
	inline void enterData(fstream&, string);
	inline void get_allData(fstream&, string);
	inline void display_allData(fstream&, string);
	inline void Filter_Date_Category(int, int, string, fstream&, string);
	inline void Filter_Date_amount(int, int, int, fstream&, string);
	inline void Filter_Category_amount(string, int, fstream&, string);
	inline void filterrby4(int, int, string, int, fstream&, string);
	inline void filter_Date(int, int, fstream&, string);
	inline void filter_Category(string, fstream&, string);
	inline void filter_Amount(double, fstream&, string);
	inline void filter_Day(int, fstream&, string);
	inline void filter_Month(int, fstream&, string);
	inline void monthltExpenses(fstream&, string);
	inline double sumAmount(fstream&, string);
	
	inline ~Wallet();
};






