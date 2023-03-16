// ---------------------------------movie.cpp----------------------------------
// Group 9 CSS343D
// Created 3/01/23
// Date of Last Modification: 3/14/23
// ----------------------------------------------------------------------------
/* Purpose - Base movie class that will have its derived classes implement
   methods depending on their genre. This base class contains general
   attributes that all movies have: movie's genre, media type, stock, director,
   title, and the movies release date (year).
*/

#include "movie.h"

// ----------------------------Default Constructor-----------------------------
// Constructs an empty Movie object.
// Precondition: None.
// Postcondition: Empty Movie object is created.
// ----------------------------------------------------------------------------
Movie::Movie() {
  this->movieGenre = '\0';
  this->mediaType = '\0';
  this->stock = -1;
  this->director = "";
  this->title = "";
  this->yearReleased = -1;
}

// --------------------------------Constructor---------------------------------
// Constructs a Movie object with general attributes assigned.
// Precondition: None.
// Postcondition: Movie object with general attributes is created.
// ----------------------------------------------------------------------------
Movie::Movie(char movieGenre, char mediaType, int stock, string director,
             string title, int yearReleased) {
  this->movieGenre = movieGenre;
  this->mediaType = mediaType;
  this->stock = stock;
  this->director = director;
  this->title = title;
  this->yearReleased = yearReleased;
}

// --------------------------------Destructor---------------------------------
// Virtual destructor to properly deallocate memory in derived then base class. 
// Precondition: None.
// Postcondition: Movie object will be deleted.
// ----------------------------------------------------------------------------
Movie::~Movie() {}

// --------------------------------borrowStock---------------------------------
// Decrements this movie's stock by 1 when a customer borrows it.
// Precondition: None.
// Postcondition: Movie's stock is decremented by 1.
// ----------------------------------------------------------------------------
void Movie::borrowStock() {
  this->stock--;
}

// --------------------------------returnStock---------------------------------
// Increments this movie's stock by 1 when a customer returns it.
// Precondition: None.
// Postcondition: Movie's stock is incremented by 1.
// ----------------------------------------------------------------------------
void Movie::returnStock() {
  this->stock++;
}

// --------------------------------displayMovie--------------------------------
// Displays all attributes this Movie contains.
// Precondition: None.
// Postcondition: All of the Movie's attributes are displayed. 
// ----------------------------------------------------------------------------
void Movie::displayMovie() {
  cout << "Genre: " << this->movieGenre << "\t Media: " << this->mediaType << 
  "\t Stock: " << getStock() << "\t Director: " << this->director << 
  "\t Title: " << this->title << "\t Year released: " << this->yearReleased 
    << endl;
}

// -------------------------------getMovieGenre--------------------------------
// Returns this movie's genre represented as a single char.
// Precondition: None.
// Postcondition: Movie's genre represented as a char is returned.
// ----------------------------------------------------------------------------
char Movie::getMovieGenre() const { 
  return movieGenre; 
}

// -------------------------------getMediaGenre--------------------------------
// Returns this movie's type of Media, which is represented by a single char.
// Precondition: None.
// Postcondition: Movie's type of media is returned (char).
// ----------------------------------------------------------------------------
char Movie::getMediaType() const { 
  return mediaType; 
}

// ----------------------------------getStock----------------------------------
// Returns how many copies of this movie are left as an int number.
// Precondition: None.
// Postcondition: Movie's stock count is returned.
// ----------------------------------------------------------------------------
int Movie::getStock() const { 
  return stock;
}

// --------------------------------getDirector---------------------------------
// Returns this movie's director (first then last name).
// Precondition: None.
// Postcondition: This director's full name is returned as a single string.
// ----------------------------------------------------------------------------
string Movie::getDirector() const { 
  return director; 
}

// ---------------------------------getTitle-----------------------------------
// Returns this movie's title.
// Precondition: None.
// Postcondition: The movie's title is returned as a single string.
// ----------------------------------------------------------------------------
string Movie::getTitle() const { 
  return title; 
}

// ------------------------------getYearReleased-------------------------------
// Returns the year this movie was released.
// Precondition: None.
// Postcondition: The movie's release date (year) is returned.
// ----------------------------------------------------------------------------
int Movie::getYearReleased() const { 
  return yearReleased; 
}

// ------------------------------getMonthReleased------------------------------
// Returns the month this movie was released.
// Precondition: None.
// Postcondition: Returns -1, will be fully implemented in a derived class.
// ----------------------------------------------------------------------------
int Movie::getMonthReleased() const {
  return -1; // Implemented in Classics
}

// -------------------------------getMajorActor--------------------------------
// Returns this movie's major actor (first name then last name).
// Precondition: None.
// Postcondition: Returns an empty string because it will be fully implemented 
// in a derived class.
// ----------------------------------------------------------------------------
string Movie::getMajorActor() const {
  return ""; // Implemented in Classics
}

// ---------------------------------operator==---------------------------------
// Overloaded operator to see if this movie equals another movie.
// Precondition: None.
// Postcondition: Returns false, will be implemented in derived classes.
// ----------------------------------------------------------------------------
bool Movie::operator==(const Movie &rhs) const {
  return false; // Implemented in derived classes
}

// ---------------------------------operator!=---------------------------------
// Overloaded operator to see if this movie does not equal another movie.
// Precondition: None.
// Postcondition: Returns false, will be implemented in derived classes.
// ----------------------------------------------------------------------------
bool Movie::operator!=(const Movie &rhs) const {
  return false; // Implemented in derived classes
}

// ---------------------------------operator<=---------------------------------
// Overloaded operator to see if this movie is less than or equal to another
// movie.
// Precondition: None.
// Postcondition: Returns false, will be implemented in derived classes.
// ----------------------------------------------------------------------------
bool Movie::operator<=(const Movie &rhs) const {
  return false; // Implemented in derived classes
}

// ---------------------------------operator<----------------------------------
// Overloaded operator that compares if this movie less than another movie.
// Precondition: None.
// Postcondition: Returns false, will be implemented in derived classes.
// ----------------------------------------------------------------------------
bool Movie::operator<(const Movie &rhs) const {
  return false; // Implemented in derived classes
}

// ---------------------------------operator>=---------------------------------
// Overloaded operator that compares if this movie greater than or equal 
// another movie.
// Precondition: None.
// Postcondition: Returns false, will be implemented in derived classes.
// ----------------------------------------------------------------------------
bool Movie::operator>=(const Movie &rhs) const {
  return false; // Implemented in derived classes
}

// ---------------------------------operator>----------------------------------
// Overloaded operator to see if this movie is greater than another movie.
// Precondition: None.
// Postcondition: Returns false, will be implemented in derived classes.
// ----------------------------------------------------------------------------
bool Movie::operator>(const Movie &rhs) const {
  return false; // Implemented in derived classes
}
