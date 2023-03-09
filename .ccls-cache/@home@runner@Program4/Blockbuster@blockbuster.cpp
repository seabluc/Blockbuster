
#include "blockbuster.h"
#include "../Commands/borrow.h"
#include "../Commands/history.h"
#include "../Commands/inventory.h"
#include "../Commands/return.h"
#include "../Movie/classics.h"
#include "../Movie/comedy.h"
#include "../Movie/drama.h"

Blockbuster::Blockbuster() {}

Blockbuster::~Blockbuster() {
    // Free up dynamic memory
    for (auto& customer : customerDatabase) {
        customer.second.clearTransactions();
    }
}

bool Blockbuster::readMoviesFile(ifstream& file) {
    if (!file) {
        cerr << "Error: Could not open movies file." << endl;
        return false;
    }
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        char type;
        ss >> type;
        Movie* movie;
        switch (type) {
            case 'C': {
                int stock;
                string director, title, majorActor;
                int month, year;
                ss >> stock >> director >> title >> majorActor >> month >> year;
                movie = new Classics(stock, director, title, majorActor, month, year);
                break;
            }
            case 'D': {
                int stock, year;
                string director, title;
                ss >> stock >> director >> title >> year;
                movie = new Drama(stock, director, title, year);
                break;
            }
            case 'F': {
                int stock, year;
                string director, title;
                ss >> stock >> director >> title >> year;
                movie = new Comedy(stock, director, title, year);
                break;
            }
            default: {
                cerr << "Invalid movie type: " << type << endl;
                continue;
            }
        }
        movieList.push_back(*movie);
        delete movie;
    }
    return true;
}

bool Blockbuster::readCustomersFile(ifstream& file) {
    if (!file) {
        cerr << "Error: Could not open customers file." << endl;
        return false;
    }
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        int id;
        string lastName, firstName;
        ss >> id >> lastName >> firstName;
        customerDatabase.push_back(make_pair(id, Customer(id, lastName, firstName)));
    }
    return true;
}

bool Blockbuster::readCommandsFile(ifstream& file) {
    if (!file) {
        cerr << "Error: Could not open commands file." << endl;
        return false;
    }
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        char type;
        ss >> type;
        Commands* command;
        switch (type) {
            case 'B': {
                int customerId, year;
                char mediaType, movieType;
                string title, director, majorActor;
                int month;
                ss >> customerId >> mediaType >> movieType;
                if (movieType == 'C') {
                    ss >> month >> year >> majorActor;
                    getline(ss, title);
                    title = title.substr(1);
                } else {
                    getline(ss, director, ',');
                    director = director.substr(1);
                    getline(ss, title, ',');
                    title = title.substr(1);
                    ss >> year;
                }
                command = new Borrow(customerId, mediaType, movieType, title, director, majorActor, month, year);
                break;
            }
            case 'R': {
                int customerId, year;
                char mediaType, movieType;
                string title, director, majorActor;
                int month;
                ss >> customerId >> mediaType >> movieType;