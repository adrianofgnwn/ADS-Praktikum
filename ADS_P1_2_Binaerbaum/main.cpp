/*************************************************
 * ADS Praktikum 1.2
 * main.cpp
 *
 *************************************************/
#define CATCH_CONFIG_RUNNER
#include "Tree.h"
#include "catch.h"
#include <iostream>

using namespace std;

///////////////////////////////////////
// Hilfsmethoden fürs Menü hier:

/***************************
 ** Vorgegebene  Funktion **
 ***************************
   "mainscreen_addTreeCSV" 
 
Importiert CSV Datei in bestehenden Baum.
Bei Aufruf in der main() Methode, muss der Pointer auf den Anker des Baums, als Parameter übergeben werden.
Es wird die im gleichen Verzeichnis liegende Datei "ExportZielanalyse.csv" geladen.
****************************/

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
                ref->addNode(name, stoi(age), stod(income), stoi(postcode));
            }
            csvread.close();
        }
        cout << "+ Daten wurden dem Baum hinzugefuegt." << endl;
    }
}

//
///////////////////////////////////////
int main() {

    int result = Catch::Session().run();

    ///////////////////////////////////////
    // Ihr Code hier:
    int input = 0;
    string name = "";
    int alter = 0;
    double einkommen = 0;
    int plz = 0;
    int order_id = 0;
    string printmethod = "";


    Tree* MyTree = new Tree;


    while (input != 7) {
        cout << endl
             << "=========================================" << endl
             << "ADS - ELK - Stack v1.9, by 25th Bam" << endl
             << "=========================================" << endl
             << "1) Datensatz einfuegen, manuell" << endl
             << "2) Daten einfuegen, CSV Datei" << endl
             << "3) Datensatz loeschen" << endl
             << "4) Suchen" << endl
             << "5) Datenstruktur anzeigen" << endl
             << "6) Level-Order Ausgabe" << endl
             << "7) Beenden" << endl;

        cout << "?> ";
        cin >> input;
        
        cout << endl;

        switch (input) {
        case 1:
            cout << "+ Bitte geben Sie die den Datensatz ein" << endl;

            cout << " Name ?> ";
            cin >> name;

            cout << " Alter ?> ";
            cin >> alter;

            cout << " Einkommen ?> ";
            cin >> einkommen;

            cout << " PLZ ?> ";
            cin >> plz;

            MyTree->addNode(name, alter, einkommen, plz);
            cout << "+ Ihr Datensatz wurde eingefuegt." << endl;
           
            break;
      
        case 2:
            mainscreen_addTreeCSV(MyTree);
        
            break;

        case 3:
            cout << "+ Bitte geben Sie den zu loeschenden Datensatz an" << endl;
            cout << " OrderID ?> ";

            cin >> order_id;

            MyTree->deleteNode(order_id);
            cout << "+ Eintrag wurde geloescht." << endl;
           
            break;

        case 4:
            cout << "+ Bitte geben Sie den zu suchenden Datensatz an" << endl;
            cout << " Name ?> ";

            getline(cin, name);
            MyTree->searchNode(name);

            break;
      
        case 5:

            cout << "?> ";
            getline(cin, printmethod);

            MyTree->printAll();
        
            break;

        case 6:
            MyTree->levelOrder();
           
            break;
        }
    }    
    //
    ///////////////////////////////////////
    system("PAUSE");
    return 0;
}
