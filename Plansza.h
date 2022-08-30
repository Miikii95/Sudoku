#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Plansza
{
public:
	vector<vector<char>> plansza;

	Plansza(void);
	~Plansza(void);
	void insert(vector<char> w);
	void show();
	void hide(int ile);
	void change(char k, int wier,char x);
	bool check ();
	bool ending();

};

