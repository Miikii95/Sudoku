#include "stdafx.h"
#include "Plansza.h"
#include <iostream>
#include <algorithm>



Plansza::Plansza(void)
{
}

Plansza::~Plansza(void)
{
}

void Plansza ::insert(vector<char> w)
{
	plansza.push_back(w);
}

void Plansza ::show()
{
	//wektor wewnetrzny jest poziomy
	int dlug= 28;
	vector<char> kolumny(dlug);
	fill(kolumny.begin(),kolumny.end(),' ');
	kolumny[4]='A';
	kolumny[6]='B';
	kolumny[8]='C';
	kolumny[12]='D';
	kolumny[14]='E';
	kolumny[16]='F';
	kolumny[20]='G';
	kolumny[22]='H';
	kolumny[24]='I';

	for(char el:kolumny)
		cout<<el;
	cout<<endl;
	for(int i =0;i<dlug;i++)
			cout<<"-";
	for(int i=0;i<3;i++)
	{
		
		cout<<endl;
		cout<<i+1<<" | ";
		for(int j=0;j<3;j++)
			cout<<plansza[i][j]<<" ";
		cout<<"| ";
		for(int j=3;j<6;j++)
			cout<<plansza[i][j]<<" ";
		cout<<"| ";
		for(int j=6;j<9;j++)
			cout<<plansza[i][j]<<" ";
		cout<<"| ";
		cout<<endl;

	}
	for(int i =0;i<dlug;i++)
			cout<<"-";

	for(int i=3;i<6;i++)
	{
		
		cout<<endl;
		cout<<i+1<<" | ";
		for(int j=0;j<3;j++)
			cout<<plansza[i][j]<<" ";
		cout<<"| ";
		for(int j=3;j<6;j++)
			cout<<plansza[i][j]<<" ";
		cout<<"| ";
		for(int j=6;j<9;j++)
			cout<<plansza[i][j]<<" ";
		cout<<"| ";
		cout<<endl;

	}
	for(int i =0;i<dlug;i++)
			cout<<"-";

	for(int i=6;i<9;i++)
	{
		
		cout<<endl;
		cout<<i+1<<" | ";
		for(int j=0;j<3;j++)
			cout<<plansza[i][j]<<" ";
		cout<<"| ";
		for(int j=3;j<6;j++)
			cout<<plansza[i][j]<<" ";
		cout<<"| ";
		for(int j=6;j<9;j++)
			cout<<plansza[i][j]<<" ";
		cout<<"| ";
		cout<<endl;

	}
	for(int i =0;i<dlug;i++)
			cout<<"-";
	cout<<endl;
}

void Plansza::hide(int ile)
{
	int a=81;
	while (a>=ile)
	{
		int w,k;
		w=rand()%9;
		k=rand()%9;
		if(plansza[k][w]!=' ')
		{
			plansza[k][w]=' ';
			a--;
		}
	}
}

void Plansza::change(char k, int w,char x)
{
	int kol=k-65;
	int wier=w-1;
	plansza[wier][kol]=x;
}

bool Plansza:: check ()
{
	for (int k=0;k<9;k++)
	{

	for (int i=0;i<9;i++)
	{
		int ile=0;
		for(int j=0;j<9;j++)
			if (plansza[k][i]==plansza[k][j])
				ile++;
		if (ile>1)
			return 0;
	}
	}
	for (int k=0;k<9;k++)
	{

	for (int i=0;i<9;i++)
	{
		int ile=0;
		for(int j=0;j<9;j++)
			if (plansza[i][k]==plansza[j][k])
				ile++;
		if (ile>1)
			return 0;
	}
	}


	return 1;
}

bool Plansza::ending()
{
	for(int i=0;i<plansza.size();i++)
	{
		for(int j=0;j<plansza[i].size();j++)
		{
		if (plansza[i][j]==' ')
			return false;
		}
	}
	return true;
}

