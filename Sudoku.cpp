// Sudoku.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Plansza.h"
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>
#include<fstream>
#include <string>
#include <sstream>
#include <time.h>


using namespace std;

bool correct (char kol, int wier)
{
	
	if (kol>64||kol<74)
		return 0;
	if(wier>10||wier<0)
		return 0;
	return 1;
}

void gra(Plansza & pl,Plansza ready)
{

	system("cls");
	
	char kol=0;
	int wier=0;
	int x=0;
	while(1)
	{
	pl.show();
	cout<<"zaznacz miejsce: (np. A1) "<<endl;
	cin>>kol;
	cin>>wier;
	system("cls");

	if((kol<='I'&&kol>='A')&&(wier<10&&wier>0))
		break;
	else
		cout<<"Blad! Sprawdz czy napewno uzyles wielkiej litery."<<endl;
	}
	pl.change(kol,wier,'X');
	pl.show();
	cout<<"cofnij : 0"<<endl;
	while(1)
	{
		cin>>x;
		if(x==5013)
		{
		pl=ready;
		pl.show();
		break;
		}
		
		if(x>=1&&x<=9)
		{
			char x_c=x+48;
			pl.change(kol,wier,x_c);
			break;
		}
		if (x==0)
		{pl.change(kol,wier,' ');break;}
		else
			cout<<"Mozesz wpisac tylko liczby z przedzialu 1-9"<<endl;
	}
	}

Plansza load(int a)
{
	Plansza pl;
	fstream plik;
	stringstream ss;
	ss<<"plansze\\"<<a<<".txt";
	plik.open(ss.str(),ios::in);
	if (plik.good())
	{
	for(int i=0;i<10;i++)
	{
	vector<char>v;
	string s;
	getline(plik,s);
	for (int j=0;j<s.size();j++)
		v.push_back(s[j]);
	pl.insert(v);
	}
	return pl;
	}
	else {cout<<"Blad wczytywania pliku."<<endl; return pl;}
	//C:\Users\Krzysiu\Documents\visual studio 2012\Projects\Sudoku\Sudoku
}

void szybka_gra()
{
	cout<<"           !!!SUDOKU MASTERS!!!\n\n\n";
	Plansza pl=load(rand()%15+1);
	Plansza ready=pl;
	pl.hide(rand()%10+31);
	time_t start,koniec;
	time(&start);
	do
	{
		gra(pl,ready);
	}while((!pl.check())||(!pl.ending()));
	system("cls");
	pl.show();
	time(&koniec);
	int czas=difftime(koniec, start);
	cout<<"Brawo!\nUdalo Ci sie!\nTwoj czas to: "<<czas<<endl;
	cout<<"Podaj imie:\n";
	string imie;
	cin>>imie;
	fstream plik;
	plik.open("statystyki\\5.txt", ios::out|ios::app);
	plik<<imie<<endl<<czas<<endl;
	plik.close();
	system("pause");
}

void nowa_gra()
{
	system("cls");
	cout<<"           !!!SUDOKU MASTERS!!!\n\n\n";
	int plansza;
	while(1)
	{
	cout<<"Wybierz plansze: \n (domyslnie 1-15)\n";
	cin>>plansza;
	if(plansza>15)
	{
	{cout<<"PLANSZA NIE JEST DOMYSLNA!\nChcesz kontynuowac? (t/n)"<<endl;
	char t;
	cin>>t;
	if (t=='t')
		break;
	}
	}
	else break;
	}
	cout<<endl;
	int trudnosc;
	do{
	cout<<"Wybierz poziom trudnosci: "<<endl;
	cout<<"MASTER - - - - 1"<<endl;
	cout<<"Trudny - - - - 2"<<endl;
	cout<<"Sredni - - - - 3"<<endl;
	cout<<"Latwy - - - -  4"<<endl;
	cin>>trudnosc;
	}while(trudnosc>4||trudnosc<0);
	int pt;
	switch (trudnosc)
	{
	case 1:
		pt=20;
		break;
	case 2:
		pt=30;
		break;
	case 3:
		pt=40;
		break;
	case 4:
		pt=50;
		break;
	case 0:
		pt=80;
		break;
	}
	Plansza pl,ready;
	pl=load(plansza);
	ready=pl;
	pl.hide(pt);
	time_t start,koniec;
	time(&start);
	do
	{
		gra(pl,ready);
	}while((!pl.check())||(!pl.ending()));
	system("cls");
	pl.show();
	time(&koniec);
	int czas =difftime(koniec, start);
	cout<<"Brawo!\nUdalo Ci sie!\nTwoj czas to: "<<czas<<endl;
	if(trudnosc!=0)
	{
	
	cout<<"Podaj imie:\n";
	string imie;
	cin>>imie;
	fstream plik;
	stringstream ss;
	ss<<"statystyki\\"<<trudnosc<<".txt";
	plik.open(ss.str(), ios::out|ios::app);
	plik<<imie<<endl<<czas<<endl;
	plik.close();
	}
	system("pause");
}

void pokaz_statystyki()
{
	int wybor=1;
	while(1)
	{
cout<<"           !!!SUDOKU MASTERS!!!\n\n\n";

	cout<<"Wszystkie - -  0"<<endl;
	cout<<"MASTER - - - - 1"<<endl;
	cout<<"Trudny - - - - 2"<<endl;
	cout<<"Sredni - - - - 3"<<endl;
	cout<<"Latwy - - - -  4"<<endl;
	cout<<"Szybka gra - - 5"<<endl;
	
	cin>>wybor;

	if(wybor>=0&&wybor<6)
	{
		break;
	}
	else
	{
		system("cls");
		cout<<"Nie znaleziono"<<endl;
	}
	}
	if(wybor==0)
	{
		system("cls");
		for(int j=1;j<=5;j++)
	{
			stringstream ss;
	ss<<"statystyki\\"<<j<<".txt";
	fstream plik;
	plik.open(ss.str(),ios::in);
	if(plik.good()==0)
	{cout<<"Nie znaleziono\n";system("pause");return;}
	string linia;
	int i=1;
	string imie;
	int czas;
	vector<pair<int,string>>wyniki;
	while(getline(plik,linia))
	{
		if(i%2==1)
		{
		imie=linia;
		}
		if(i%2==0)
		{
			czas=atoi(linia.c_str());
			wyniki.push_back(make_pair(czas,imie));
		}
		i++;
	}
	sort(wyniki.begin(),wyniki.end());

	switch (j)
	{
	case 1:
		cout<<"Master:\n";
		break;
	case 2:
		cout<<"Trudny:\n";
		break;
	case 3:
		cout<<"Sredni:\n";
		break;
	case 4:
		cout<<"Latwy:\n";
		break;
	case 5:
		cout<<"Szybka gra:\n";
		break;
	}
	for(pair<int,string>el:wyniki)
		cout<<el.second<<" - "<<el.first<<endl;

	cout<<endl;
	}
	}
	else{
	stringstream ss;
	ss<<"statystyki\\"<<wybor<<".txt";
	fstream plik;
	plik.open(ss.str(),ios::in);
	if(plik.good()==0)
	{cout<<"Nie znaleziono\n";system("pause");return;}
	string linia;
	int i=1;
	string imie;
	int czas;
	vector<pair<int,string>>wyniki;
	while(getline(plik,linia))
	{
		if(i%2==1)
		{
		imie=linia;
		}
		if(i%2==0)
		{
			czas=atoi(linia.c_str());
			wyniki.push_back(make_pair(czas,imie));
		}
		i++;
	}
	sort(wyniki.begin(),wyniki.end());
	system("cls");
	switch (wybor)
	{
	case 1:
		cout<<"Master:\n";
		break;
	case 2:
		cout<<"Trudny:\n";
		break;
	case 3:
		cout<<"Sredni:\n";
		break;
	case 4:
		cout<<"Latwy:\n";
		break;
	case 5:
		cout<<"Szybka gra:\n";
		break;
	}
	for(pair<int,string>el:wyniki)
		cout<<el.second<<" - "<<el.first<<endl;
	}
	system("pause");
	

}

void menu()
{
	system("cls");
	cout<<"           !!!SUDOKU MASTERS!!!\n\n\n";	cout<<"Witaj w SUDOKU MASTERS!!!"<<endl<<endl<<endl<<endl;
	cout<<"Szybka gra -  1"<<endl;
	cout<<"Nowa gra - -  2"<<endl;
	cout<<"Statystyki -  3"<<endl;//kiedys moze beda...
	cout<<"Wyjdz - - - - 4\n\n\n"<<endl;
	
}

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	

	while(1)
	{
	int wybor;
	menu();
	cin>>wybor;
	switch (wybor)
	{
	case 1:
		szybka_gra();
		break;
	case 2:
		nowa_gra();
		break;
	case 3:
		pokaz_statystyki();
		break;
	case 4:
		exit(0);
		break;
	}
	}
	
	system("pause");
	return 0;
}

