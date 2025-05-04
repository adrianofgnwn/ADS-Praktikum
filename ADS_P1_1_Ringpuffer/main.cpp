/*************************************************
* ADS Praktikum 1.1
* main.cpp
* 
*************************************************/
#define CATCH_CONFIG_RUNNER

#include <iostream>
#include <string>
#include "Ring.h"
#include "catch.h"

using namespace std;

void print_menu()
{
    cout << "====================================" << endl
        << " SuperBackUp-Organizer over 9000, by. Son Goku" << endl
        << "====================================" << endl
        << "1) Backup anlegen" << endl
        << "2) Backup suchen" << endl
        << "3) Alle Backups ausgeben" << endl
        << "4) Programm beenden" << endl
        << "?> ";
}

int main() {   
	int result = Catch::Session().run();
	// Ihr Code hier:
    int input = 0;
    string description;
    string data;

    Ring MyRing;

    while (input !=4) {
        print_menu();
        cin >> input;
        cout << endl;


        switch (input) {
        case 1:
            cout << "+Neuen Datensatz anlegen" << endl
                << "Beschreibung  ?> ";
            getline(cin>>ws, description);
            
            cout << "Daten ?> ";
            cin >> data;

            MyRing.addNewNode(description, data);
            cout << "+Ihr Datensatz wurde hinzugefuegt." << endl << endl;

            break;
      
        case 2:
            cout << "+Nach welchen Daten soll gesucht werden?" << endl
                << "?> ";
            cin >> data;


            MyRing.search(data);
            cout << endl;
            
            break;
      
        case 3:
            MyRing.print();
            cout << endl;
            
            break;
        }


    }
	//
	///////////////////////////////////////
	system("Pause");
	return result;
}