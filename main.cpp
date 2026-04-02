// COMSC-210 | Lab 23 | Johnathan Perez Baltazar

#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again = true;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    // Loops until user chooses to quit from menu
    while(again){
        int c = main_menu();

        if (c == 1){
            // add_goat();
            cout << "Adding goat..." << endl;
        } else if (c == 2){
            // delete_goat();
            cout << "Deleting goat..." << endl;
        } else if (c == 3){
            // display goats
            cout << "Displaying goats..." << endl;
        } else if (c == 4){
            cout << "Goodbye!" << endl;
            again = false;
        }
    }

    return 0;
}

int main_menu() {
    int choice;

    // Print out the menu for the user
    cout << "*** Goata Manager 3001 ***" << endl;
    cout << "[1] Add a goat" << endl;
    cout << "[2] Delete a Goat" << endl;
    cout << "[3] List goats" << endl;
    cout << "[4] quit" << endl;
    cout << "Choice --> ";
    cin >> choice;

    // Make sure user's choice is on the menu
    while(choice > 4 || choice < 1){
        cout << "\nInvalid choice try again --> ";
        cin >> choice;
    }

    // Return the option the user chose
    return choice;
}
// Pausing