// ---------------------------------drama.cpp----------------------------------
// Group 9 CSS343D
// Created 3/01/23
// Date of Last Modification: 3/15/23
// ----------------------------------------------------------------------------
/* Purpose - Derived class of Movie, Drama Movies have the movieGenre char
   set to 'D' and is sorted by director, then title.
*/
#include "drama.h"

// --------------------------------Constructor---------------------------------
// Constructs a Drama object with the following attributes.
// Precondition: None.
// Postcondition: Drama object with attributes is created.
// ----------------------------------------------------------------------------
Drama::Drama(char movieGenre, char mediaType, int stock, string director, 
               string title, int yearReleased) {
  this->movieGenre = movieGenre;
  this->mediaType = mediaType;
  this->stock = stock;
  this->director = director;
  this->title = title;
  this->yearReleased = yearReleased;
}

// --------------------------------Destructor---------------------------------
// Destructor to properly deallocate memory in derived then base class.
// Precondition: None.
// Postcondition: Drama object will be deleted.
// ----------------------------------------------------------------------------
Drama::~Drama() {}

// --------------------------------borrowStock---------------------------------
// Decrements this movie's stock by 1 when a customer borrows it.
// Precondition: None.
// Postcondition: Movie's stock is decremented by 1.
// ----------------------------------------------------------------------------
void Drama::borrowStock() {
  this->stock--;
}

// --------------------------------returnStock---------------------------------
// Increments this movie's stock by 1 when a customer returns it.
// Precondition: None.
// Postcondition: Movie's stock is incremented by 1.
// ----------------------------------------------------------------------------
void Drama::returnStock() {
  this->stock++;
}

// --------------------------------displayMovie--------------------------------
// Displays all attributes this Drama movie contains.
// Precondition: None.
// Postcondition: All of the Drama movie's attributes are displayed.
// ----------------------------------------------------------------------------
void Drama::displayMovie() {
  cout << "Genre: " << this->movieGenre << "\t Media: " << this->mediaType << 
  "\t Stock: " << getStock() << "\t Director: " << this->director << 
  "\t Title: " << this->title << "\t Year released: " << this->yearReleased 
    << endl;
}

// ---------------------------------operator==---------------------------------
// Overloaded operator to see if this Drama movie equals another Drama movie.
// It first compares the Director, then the title.
// Precondition: None.
// Postcondition: Returns true if the Drama movies are equal, false if not.
// ----------------------------------------------------------------------------
bool Drama::operator==(const Movie& rhs) const {
  if (this->movieGenre == rhs.getMovieGenre() && this->director == 
  rhs.getDirector() && this->title == rhs.getTitle()) {
    return true;
  }
  else {
    return false;
  }
}

// ---------------------------------operator!=---------------------------------
// Overloaded operator to see if this Drama movie does not equal  another Drama
// movie. It first compares the Director, then the title.
// Precondition: None.
// Postcondition: Returns true if the Drama movies are unequal, false if not.
// ----------------------------------------------------------------------------
bool Drama::operator!=(const Movie& rhs) const {
  return !(*this == rhs);
}

// ---------------------------------operator<=---------------------------------
// Overloaded operator that checks if this Drama movie is less than or equal to
// another Drama movie. It first compares the Director, then the title.
// Precondition: None.
// Postcondition: Returns true if this Drama is less than or equal to another
// Drama. False if not.
// ----------------------------------------------------------------------------
bool Drama::operator<=(const Movie& rhs) const {
  if (this->director < rhs.getDirector()) {
      return true;
    } 
  else if (this->director == rhs.getDirector()) {
    if (this->title < rhs.getTitle()) {
      return true;
    }
    if (this->title == rhs.getTitle()) {
      return true;
    }
    return false;
  }
  else {
    return false;
  }
}

// ---------------------------------operator<----------------------------------
// Overloaded operator that checks if this Drama movie is less than another
// Drama movie. It first compares the Director, then the title.
// Precondition: None.
// Postcondition: Returns true if this Drama is less than another Drama. False
// if not.
// ----------------------------------------------------------------------------
bool Drama::operator<(const Movie& rhs) const {
    if (this->director < rhs.getDirector()) {
    return true;
  }
  // If the director is the same, check the title.
  else if (this->director == rhs.getDirector()) {
    if (this->title < rhs.getTitle()) {
      return true;
    }
    else {
      return false;
    }
  }
  else {
    return false;
  }
}

// ---------------------------------operator>=---------------------------------
// Overloaded operator that checks if this Drama movie is greater than or equal
// to another Drama movie. It first compares the Director, then the title.
// Precondition: None.
// Postcondition: Returns true if this Drama is greater than or equal to 
// another Drama. False if not.
// ----------------------------------------------------------------------------
bool Drama::operator>=(const Movie& rhs) const {
  if (this->director > rhs.getDirector()) {
      return true;
    } 
  else if (this->director == rhs.getDirector()) {
    if (this->title > rhs.getTitle()) {
      return true;
    }
    if (this->title == rhs.getTitle()) {
      return true;
    }
    return false;
  }
  else {
    return false;
  }
}

// ---------------------------------operator>----------------------------------
// Overloaded operator that checks if this Drama movie is greater than another
// Drama movie. It first compares the Director, then the title.
// Precondition: None.
// Postcondition: Returns true if this Drama is greater than another Drama. 
// False if not.
// ----------------------------------------------------------------------------
bool Drama::operator>(const Movie& rhs) const {
  if (this->director > rhs.getDirector()) {
      return true;
    } 
  else if (this->director == rhs.getDirector()) {
    if (this->title > rhs.getTitle()) {
      return true;
    }
    else {
      return false;
    }
  }
  else {
    return false;
  }
}