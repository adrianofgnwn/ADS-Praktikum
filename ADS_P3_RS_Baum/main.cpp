/*************************************************
* ADS Praktikum 3
* main.cpp
*
*************************************************/
#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "Tree.h"
#include "catch.h"

using namespace std;

void mainscreen_addTreeCSV(Tree*& ref)
{
	char j;
	cout << "+ Moechten Sie die Daten aus der Datei ExportZielanalyse.csv "
		"importieren(j / n) ? >";
	cin >> j;
	if (j == 'j')
	{
		ifstream csvread;
		csvread.open("ExportZielanalyse.csv", ios::in);
		if (!csvread.is_open())
		{
			cout << "Fehler beim Lesen!" << endl;
			return;
		}
		else
		{
			string name, age, postcode, income;

			while (!csvread.eof())
			{
				getline(csvread, name, ';');
				getline(csvread, age, ';');
				getline(csvread, income, ';');
				getline(csvread, postcode, '\n');
				if (name == "" || age == "" || income == "" || postcode == "") {
					continue;
				}
				ref->addNode(name, stoi(age), stod(income), stoi(postcode));
			}
			csvread.close();
		}
		cout << "+ Daten wurden dem Baum hinzugefuegt." << endl;
	}
}

int main() {

	int result = Catch::Session().run();

	///////////////////////////////////////
	// Ihr Code hier:
	Tree* tree = new Tree();
	int choice, age, postcode;
	int niv;
	std::string name;
	double income;

	do{
		std::cout<<"=============================\n"
				 <<"ADS-Rot-Schwarz-Baum Praktikum\n"
				 <<"=============================\n"
				 <<"1) Datensatz einfuegen, manuell\n"
				 <<"2) Datensatz einfuegen, CSV Datei\n"
				 <<"3) Suchen\n"
				 <<"4) Ausgabe in Levelorder\n"
				 <<"5) Ausgabe in Levelorder (mit Niveauauswahl)\n"
				 <<"6) Beenden\n"
				 <<"?> ";
		
		std::cin>>choice;
		switch (choice)
		{
		case 1:{
			cin.ignore();
			std::cout<<"+ Bitte geben Sie die den Datensatz ein:\n"
			<<"Name?> ";
			getline(cin,name);
			std::cout<<"Alter ?>";
			std::cin>>age;
			std::cout<<"Einkommen ?>";
			std::cin>>income;
			std::cout<<"PLZ ?>";
			std::cin>>postcode;
			tree->addNode(name, age, income, postcode);
			std::cout<<"+Ihr Datensatz wure eingefuegt"<<std::endl;
			break;
			
		}
		case 2:{
			mainscreen_addTreeCSV(tree);
			break;
		}

		case 3:{
			cin.ignore();
			std::cout<<"bitte geben Sie den zu suchenden Datensatz ein"<<std::endl;
			std::cout<<"Name?> ";
			getline(cin,name);
			tree->searchNode(name);
			break;
		}
		
		case 4:{
			std::cout<<"Ausgabe in Levelorderals binaerer Suchbaum: \n\n";
			tree->printLvlOrder();
			std::cout<<"Ausgabe in levelorder als 234Baum:\n";
			tree->printLevelOrder();

			break;

		}

		case 5:{
			cin.ignore();
			std::cout<<"+ Bitte geben Sie ein Niveau ein:\n"
			<<"Niveau ?> ";
			cin>>niv;
			tree->printLevelOrder(niv);
			break;
		}

		case 6:{
			std::cout<<"+ Programm wurde beendet.\n\n";
			break;
		}

		default:{
			std::cout<<"unbekannte Eingabe, bitte (1-6) waehlen\n";
			break;
		}
		
		}

	}while(choice!=6);

    
	//
	///////////////////////////////////////
	system("PAUSE");

	return result;
}
