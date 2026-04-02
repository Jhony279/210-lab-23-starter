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
    list<Goat> trip;

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
        int selection;

        if (c == 1){
            add_goat(trip, names, colors);

        } else if (c == 2){
            delete_goat(trip);

        } else if (c == 3){
            display_trip(trip);
            selection = select_goat(trip);
            if (selection == -1) continue; // No goats to display

        } else if (c == 4){
            again = false;
            cout << "Goodbye!" << endl;
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

void display_trip(list<Goat> trip) {
    if (trip.empty()) {
        cout << "No goats in the trip to display." << endl;
        return; // Exit the function if there are no goats
    }

    int index = 1;
    for (const auto& goat : trip) {
        cout << "[" << index++ << "] " << goat.get_name() << " (Age: " 
            << goat.get_age() << ", Color: " << goat.get_color() << ")" << endl;
    }
}

void add_goat(list<Goat> &trip, string names[], string colors[]) {
    // Generate random name, age, and color for the goat
    string name = names[rand() % SZ_NAMES];
    int age = rand() % MAX_AGE + 1; // Age between 1 and MAX_AGE
    string color = colors[rand() % SZ_COLORS];

    // Create a new goat and add it to the trip
    Goat new_goat(name, age, color);
    trip.push_back(new_goat);
}

int select_goat(list<Goat> trip) {
    // Check if the trip is empty
    if (trip.empty()) {
        return -1; // Return -1 to indicate no selection
    }

    // Prompt user to select a goat by index
    int choice;
    cout << "Select a goat by number: ";
    cin >> choice;

    // Validate the user's choice
    while (choice < 1 || choice > trip.size()) {
        cout << "Invalid choice. Please select a valid goat number: ";
        cin >> choice;
    }

    // Return the index of the selected goat
    return choice - 1;
}

void delete_goat(list<Goat> &trip) {
    // Check if the trip is empty
    if (trip.empty()) {
        cout << "No goats in the trip to delete." << endl;
        return; // Exit the function if there are no goats
    }

    // Prompt user to select a goat to delete
    int choice;
    cout << "Select a goat to delete by number: ";
    cin >> choice;

    // Validate the user's choice
    while (choice < 1 || choice > trip.size()) {
        cout << "Invalid choice. Please select a valid goat number: ";
        cin >> choice;
    }

    // Delete the selected goat from the trip
    auto it = trip.begin();
    advance(it, choice - 1); // Move iterator to the selected goat
    trip.erase(it); // Remove the goat from the list
}