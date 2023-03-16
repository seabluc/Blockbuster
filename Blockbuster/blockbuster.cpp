// ------------------------------blockbuster.cpp-------------------------------
// Group 9 CSS343D
// Created 3/01/23
// Date of Last Modification: 3/15/23
// ----------------------------------------------------------------------------
/* Purpose - Reads from 3 text files. One text file will create Movies, another
   creates Customers, and the last one creates Commands. This class will then
   execute all of the Commands that Customers will perform on Movies.
*/

#include "blockbuster.h"

// ----------------------------Default Constructor-----------------------------
// Constructs a Blockbuster object.
// Precondition: None.
// Postcondition: Blockbuster object created.
// ----------------------------------------------------------------------------
Blockbuster::Blockbuster() {}

// --------------------------------Destructor---------------------------------
// Deallocates all movies.
// Precondition: None.
// Postcondition: Deletes movies of all genres.
// ----------------------------------------------------------------------------
Blockbuster::~Blockbuster() {
  for (Movie *movie : movieListComedy) {
    delete movie;
  }
  for (Movie *movie : movieListDrama) {
    delete movie;
  }
  for (Movie *movie : movieListClassics) {
    delete movie;
  }
}

// -------------------------------readMoviesFile-------------------------------
// Reads from the text file "data4movies.txt" to create and sort Movies by
// genre then storing the Movies into a list.
// Precondition: File must be properly formatted.
// Postcondition: 3 lists of Movies (Comedy, Classics, Drama) is created.
// ----------------------------------------------------------------------------
bool Blockbuster::readMoviesFile() {
  ifstream file("data4movies.txt");
  if (file) {
    string line;
    while (getline(file, line)) {
      istringstream iss(line);
      char movieGenre = 'X', mediaType = 'D';
      int stock = 0, movieYear = 0, movieMonth = 0;
      string movieDirector = "", movieTitle = "", movieMajorActor = "";

      string temp = ""; // getline outputs string so we need this temp as a
                        // middleman to convert

      getline(iss, temp, ',');
      iss.get(); // remove whitespace
      movieGenre = temp[0];

      getline(iss, temp, ',');
      iss.get(); // remove whitespace
      stock = stoi(temp);

      getline(iss, movieDirector, ',');
      iss.get(); // remove whitespace
      getline(iss, movieTitle, ',');
      iss.get(); // remove whitespace

      switch (movieGenre) {
      case 'F': {
        iss >> movieYear;
        Comedy *newMovie = new Comedy(movieGenre, mediaType, stock,
                                      movieDirector, movieTitle, movieYear);
        movieListComedy.push_back(newMovie);
        break;
      }
      case 'D': { // Drama
        iss >> movieYear;
        Drama *newMovie = new Drama(movieGenre, mediaType, stock, movieDirector,
                                    movieTitle, movieYear);
        movieListDrama.push_back(newMovie);
        break;
      }
      case 'C': { // Classics
        iss >> temp;
        movieMajorActor = temp;
        iss >> temp;
        movieMajorActor = movieMajorActor + " " + temp;
        iss >> movieMonth;
        iss >> movieYear;
        Classics *newMovie =
            new Classics(movieGenre, mediaType, stock, movieDirector,
                         movieTitle, movieMajorActor, movieMonth, movieYear);
        movieListClassics.push_back(newMovie);
        break;
      }
      default: {
        cerr << "ERROR: Movie genre: " << movieGenre << " DNE." << endl;
        break;
      }
      }
    }
    file.close();
    return true;
  } else {
    cerr << "ERROR: Could not open movies file." << endl;
    return false;
  }
}

// -----------------------------readCustomersFile------------------------------
// Reads from the text file "data4customers.txt" to create Customers and adding
// the Customers into a hash table.
// Precondition: File must be properly formatted.
// Postcondition: Customers are created and stored into a hash table.
// ----------------------------------------------------------------------------
bool Blockbuster::readCustomersFile() {
  ifstream file("data4customers.txt");
  if (file) {
    string line;
    while (getline(file, line)) {
      istringstream iss(line);
      int customerID = 0;
      string firstName = "", lastName = "";

      iss >> customerID >> lastName >> firstName;

      Customer *newCustomer = new Customer(customerID, lastName, firstName);

      customerTable.addCustomer(*newCustomer);
    }
    file.close();
    return true;
  } else {
    cerr << "ERROR: Could not open customers file." << endl;
    return false;
  }
}

// ------------------------------readCommandsFile------------------------------
// Reads from the text file "data4commands.txt" to create Commands and then
// stores the Commands into a queue.
// Precondition: File must be properly formatted.
// Postcondition: Commands are created and stored into a queue.
// ----------------------------------------------------------------------------
bool Blockbuster::readCommandsFile() {
  ifstream file("data4commands.txt");
  if (file) {
    string line;
    while (getline(file, line)) {
      istringstream iss(line);
      char commandType, mediaType, movieGenre = 'X';
      int customerID = 0, movieYear = 0, movieMonth = 0;
      string movieDirector = "", movieTitle = "", movieMajorActor = "";
      Movie *targetMovie;
      iss >> commandType;

      if (commandType == 'B' || commandType == 'R') { // Borrow and Return
        iss >> customerID >> mediaType >> movieGenre;
        iss.get(); // remove whitespace
        switch (movieGenre) {
        // while targetMovie might have some blank data, it should always have
        // the data required for comparison which is the only thing it will be
        // used for
        case 'F': { // Comedy
          getline(iss, movieTitle, ',');
          iss.get(); // remove whitespace
          iss >> movieYear;
          targetMovie = new Comedy(movieGenre, mediaType, 0, movieDirector,
                                   movieTitle, movieYear);
          break;
        }
        case 'D': { // Drama
          getline(iss, movieDirector, ',');
          iss.get(); // remove whitespace
          getline(iss, movieTitle, ',');
          iss.get(); // remove whitespace
          targetMovie = new Drama(movieGenre, mediaType, 0, movieDirector,
                                  movieTitle, movieYear);
          break;
        }
        case 'C': { // Classics
          iss >> movieMonth >> movieYear;
          string temp = "";
          iss >> temp;
          movieMajorActor = temp;
          iss >> temp;
          movieMajorActor = movieMajorActor + " " + temp;
          targetMovie =
              new Classics(movieGenre, mediaType, 0, movieDirector, movieTitle,
                           movieMajorActor, movieMonth, movieYear);
          break;
        }
        default: {
          cerr << "ERROR: Movie genre: " << movieGenre << " DNE." << endl;
          break;
        }
        }
      }
      switch (commandType) {
      case 'B': {
        Borrow *newCommand = new Borrow(customerID, targetMovie);
        commandsQueue.push(newCommand);
        break;
      }
      case 'R': {
        Return *newCommand = new Return(customerID, targetMovie);
        commandsQueue.push(newCommand);
        break;
      }
      case 'I': {
        Inventory *newCommand = new Inventory();
        commandsQueue.push(newCommand);
        break;
      }
      case 'H': {
        iss >> customerID;
        History *newCommand = new History(customerID);
        commandsQueue.push(newCommand);
        break;
      }
      default: {
        cerr << "ERROR: Command type: " << commandType << " DNE." << endl;
        break;
      }
      }
    }
    file.close();
    return true;
  } else {
    cerr << "ERROR: Could not open Command file." << endl;
    return false;
  }
}

// ------------------------------executeCommands-------------------------------
// Goes through the queue to execute stored commands sequentially.
// Precondition: File must be properly formatted.
// Postcondition: All commands are executed.
// ----------------------------------------------------------------------------
void Blockbuster::executeCommands() {
  while (!commandsQueue.empty()) {
    switch (commandsQueue.front()->getCommandType()) {
    case 'B': {
      Borrow *currentCommand = dynamic_cast<Borrow *>(commandsQueue.front());
      switch (currentCommand->getMovie()->getMovieGenre()) {
      case 'F': {
        currentCommand->action(movieListComedy, customerTable);
        break;
      }
      case 'D': {
        currentCommand->action(movieListDrama, customerTable);
        break;
      }
      case 'C': {
        currentCommand->action(movieListClassics, customerTable);
        break;
      }
      }
      break;
    }
    case 'R': {
      Return *currentCommand = dynamic_cast<Return *>(commandsQueue.front());
      switch (currentCommand->getMovie()->getMovieGenre()) {
      case 'F': {
        currentCommand->action(movieListComedy, customerTable);
        break;
      }
      case 'D': {
        currentCommand->action(movieListDrama, customerTable);
        break;
      }
      case 'C': {
        currentCommand->action(movieListClassics, customerTable);
        break;
      }
      }
      break;
    }
    case 'I': {
      Inventory *currentCommand =
          dynamic_cast<Inventory *>(commandsQueue.front());
      currentCommand->action(movieListComedy, movieListClassics,
                             movieListDrama);
      break;
    }
    case 'H': {
      History *currentCommand = dynamic_cast<History *>(commandsQueue.front());
      currentCommand->action(customerTable);
      break;
    }
    default: {
      cerr << "ERROR: Command type: " << commandsQueue.front()->getCommandType()
           << " DNE." << endl;
      break;
    }
    }
    commandsQueue.pop();
  }
}