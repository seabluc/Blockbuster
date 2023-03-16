// ---------------------------------comedy.cpp---------------------------------
// Group 9 CSS343D
// Created 3/01/23
// Date of Last Modification: 3/15/23
// ----------------------------------------------------------------------------
/* Purpose - Derived class of Movie, Comedy Movies have the movieGenre char
   set to 'F' and is sorted by title, then year of release.
*/
#include "comedy.h"

// --------------------------------Constructor---------------------------------
// Constructs a Comedy object with the following attributes.
// Precondition: None.
// Postcondition: Comedy object with attributes is created.
// ----------------------------------------------------------------------------
Comedy::Comedy(char movieGenre, char mediaType, int stock, string director, 
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
// Postcondition: Comedy object will be deleted.
// ----------------------------------------------------------------------------
Comedy::~Comedy() {}

// --------------------------------borrowStock---------------------------------
// Decrements this movie's stock by 1 when a customer borrows it.
// Precondition: None.
// Postcondition: Movie's stock is decremented by 1.
// ----------------------------------------------------------------------------
void Comedy::borrowStock() {
  this->stock--;
}

// --------------------------------returnStock---------------------------------
// Increments this movie's stock by 1 when a customer returns it.
// Precondition: None.
// Postcondition: Movie's stock is incremented by 1.
// ----------------------------------------------------------------------------
void Comedy::returnStock() {
  this->stock++;
}

// --------------------------------displayMovie--------------------------------
// Displays all attributes this Comedy movie contains.
// Precondition: None.
// Postcondition: All of the Comedy movie's attributes are displayed.
// ----------------------------------------------------------------------------
void Comedy::displayMovie() {
  cout << "Genre: " << this->movieGenre << "\t Media: " << this->mediaType << 
  "\t Stock: " << getStock() << "\t Director: " << this->director << 
  "\t Title: " << this->title << "\t Year released: " << this->yearReleased 
    << endl;
}

// ---------------------------------operator==---------------------------------
// Overloaded operator to see if this Comedy movie equals another Comedy movie.
// It first compares the Title, then year of release.
// Precondition: None.
// Postcondition: Returns true if the Comedy movies are equal, false if not.
// ----------------------------------------------------------------------------
bool Comedy::operator==(const Movie& rhs) const {
  if (this->movieGenre == rhs.getMovieGenre() && this->title == rhs.getTitle()
      && this->yearReleased == rhs.getYearReleased()) {
    return true;
  }
    return false;
}

// ---------------------------------operator!=---------------------------------
// Overloaded operator to see if this Comedy movie does not equal another 
// Comedy movie. It first compares the Title, then year of release.
// Precondition: None.
// Postcondition: Returns true if the Comedy movies are unequal, false if not.
// ----------------------------------------------------------------------------
bool Comedy::operator!=(const Movie& rhs) const {
  return !(*this == rhs);
}

// ---------------------------------operator<=---------------------------------
// Overloaded operator that checks if this Comedy movie is less than or equal 
// to another Comedy movie. It first compares the Title, then year of release.
// Precondition: None.
// Postcondition: Returns true if this Comedy is less than or equal to another
// Comedy. False if not.
// ----------------------------------------------------------------------------
bool Comedy::operator<=(const Movie& rhs) const {
    // Checks if this title is less than the compared movie's title
    if (this->title < rhs.getTitle()) {
      return true;
    } 
    // Checks year of release if titles are the same.
    else if (this->title == rhs.getTitle()) {
      if (this->yearReleased < rhs.getYearReleased()) {
        return true;
      }
      if (this->yearReleased == rhs.getYearReleased()) {
        return true;
      }
      return false;
    }
  else {
    return false;
  }
}

// ---------------------------------operator<----------------------------------
// Overloaded operator that checks if this Comedy movie is less than another
// Comedy movie. It first compares the Title, then year of release.
// Precondition: None.
// Postcondition: Returns true if this Comedy is less than another Comedy. 
// False if not.
// ----------------------------------------------------------------------------
bool Comedy::operator<(const Movie& rhs) const {
  // Check if this title is less than the compared movie's title.
  if (this->title < rhs.getTitle()) {
    return true;
  }
  // If titles are the same, compare year of release.
  else if (this->title == rhs.getTitle()) {
      if (this->yearReleased < rhs.getYearReleased()) {
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
// Overloaded operator that checks if this Comedy movie is greater than or 
// equal to another Comedy movie. It first compares the Title, then year of 
// release.
// Precondition: None.
// Postcondition: Returns true if this Comedy is greater than or equal to 
// another Comedy. False if not.
// ----------------------------------------------------------------------------
bool Comedy::operator>=(const Movie& rhs) const {
    // Checks if this title is greater than the compared movie's title
    if (this->title > rhs.getTitle()) {
      return true;
    } 
    // Checks year of release if titles are the same.
    else if (this->title == rhs.getTitle()) {
      if (this->yearReleased > rhs.getYearReleased()) {
        return true;
      }
      if (this->yearReleased == rhs.getYearReleased()) {
        return true;
      }
      return false;
    }
    else {
      return false;
    }
}

// ---------------------------------operator>----------------------------------
// Overloaded operator that checks if this Comedy movie is greater than another
// Comedy movie. It first compares the Title, then year of release.
// Precondition: None.
// Postcondition: Returns true if this Comedy is greater than another Comedy. 
// False if not.
// ----------------------------------------------------------------------------
bool Comedy::operator>(const Movie& rhs) const {
  // Check if this title is greater than the compared movie's title.
  if (this->title > rhs.getTitle()) {
    return true;
  }
  // If titles are the same, compare year of release.
  else if (this->title == rhs.getTitle()) {
      if (this->yearReleased > rhs.getYearReleased()) {
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
