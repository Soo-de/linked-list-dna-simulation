/*
* file			main.cpp
* description 	bağlı listelerle DNA manipülasyonu
* course		veri yapıları 1. öğretim B grubu
* assignment 	1. ödev
* date 			15.11.2024
* author		Sude ANDURMAN , sude.andurman@ogr.sakarya.edu.tr
*/

#include <iostream>
#include <cstdlib>

#include "geneoperator.hpp"
#include "linkedlist.hpp"

void	displayMenu();
void	createList(LinkedList& list);
void	performCrossover(GeneOperator& gopr, LinkedList& list);
void	performMutation(GeneOperator& gopr, LinkedList& list);
void	performTaskRunner(GeneOperator& gopr, LinkedList& list, const string& filename);
void	displayList(GeneOperator& gopr, LinkedList& list);

int main()
{
	LinkedList		list;
	GeneOperator	gopr;
	int				choice;
	bool			exit;
	
	exit = false;
	createList(list);
	while (!exit)
	{
		system("CLS");
		displayMenu();
		cout << "Seçiminiz: ";
		cin >> choice;
        switch (choice)
		{
			case 1:
				system("CLS");
				performCrossover(gopr, list);
				system("pause");
				break;
			case 2:
				system("CLS");
				performMutation(gopr, list);
				system("pause");
				break;
			case 3:
				system("CLS");
				performTaskRunner(gopr, list, "./src/autoprocesses.txt");
				system("pause");
				break;
			case 4:
				system("CLS");
				displayList(gopr, list);
				system("pause");
				break;
			case 5:
				system("CLS");
				cout << "<   Cikiliyor   >" << endl;
				exit = true;
				break;
			default:
				system("CLS");
				cout << "Gecersiz secenek! Tekrar deneyin." << endl;
				system("pause");
		}
	}
	return (0);
}

void	createList(LinkedList& list)
{
	try
	{
		list.getDatasFromFile("./src/datas.txt");
	}
	catch (const runtime_error& e) 
	{
		cerr << "Hata: " << e.what() << endl;
	}
}

void	displayMenu()
{
	cout << "\n*** Genetik İşlemler ***" << endl;
	cout << "   1- Caprazlama" << endl;
	cout << "   2- Mutasyon" << endl;
	cout << "   3- Otomatik İslemler" << endl;
	cout << "   4- Ekrana Yaz" << endl;
	cout << "   5- Cikis" << endl;
	cout << "************************" << endl;
}

void	performCrossover(GeneOperator& gopr, LinkedList& list)
{
	int	chr1;
	int	chr2;

	cout << "Çaprazlama için ilk kromozom numarasini girin: ";
	cin >> chr1;
	cout << endl;
	cout << "Çaprazlama için ikinci kromozom numarasini girin: ";
	cin >> chr2;
	cout << endl;
	try
	{
		gopr.crossOver(chr1, chr2, list);
		cout << "Çaprazlama işlemi tamamlandi." << endl;
	}
	catch (const char* e)
	{
		cerr << "Hata: " << e << endl;
	}
}

void	performMutation(GeneOperator& gopr, LinkedList& list)
{
	int	chrm;
	int	gene;

	cout << "Mutasyon için kromozom numarasi girin: ";
	cin >> chrm;
	cout << endl;
	cout << "Mutasyon için gen numarasi girin: ";
	cin >> gene;
	cout << endl;
	try
	{
		gopr.mutation(chrm, gene, list);
		cout << "Mutasyon işlemi tamamlandi." << endl;
	}
	catch (const char* e)
	{
		cerr << "Hata: " << e << endl;
	}
}

void	performTaskRunner(GeneOperator& gopr, LinkedList& list, const string& filename)
{
	try
	{
		gopr.taskRunner(filename, list);
		cout << "Otomatik işlemler tamamlandi." << endl;
	}
	catch (const char* e)
	{
		cerr << "Hata: " << e << endl;
	}
}

void	displayList(GeneOperator& gopr, LinkedList& list)
{
	try
	{
		gopr.getDisplayableGene(list);
	}
	catch (const char* e)
	{
		cerr << "Hata: " << e << endl;
	}
}