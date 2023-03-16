// --------------------------------classics.cpp--------------------------------
// Group 9 CSS343D
// Created 3/01/23
// Date of Last Modification: 3/15/23
// ----------------------------------------------------------------------------
/* Purpose - Derived class of Movie, Classics Movies have the movieGenre char
   set to 'C' and is sorted by title, then year of release.
*/
#include "classics.h"

// --------------------------------Constructor---------------------------------
// Constructs a Classics object with the following attributes.
// Precondition: None.
// Postcondition: Classics object with attributes is created.
// ----------------------------------------------------------------------------
Classics::Classics(char movieGenre, char mediaType, int stock, string director,
                   string title, string majorActor, int monthReleased, 
                   int yearReleased) {
  this->movieGenre = movieGenre;
  this->mediaType = mediaType;
  this->stock = stock;
  this->director = director;
  this->title = title;
  this->majorActor = majorActor;
  this->monthReleased = monthReleased;
  this->yearReleased = yearReleased;
}

// --------------------------------Destructor---------------------------------
// Destructor to properly deallocate memory in derived then base class.
// Precondition: None.
// Postcondition: Classics object will be deleted.
// ----------------------------------------------------------------------------
Classics::~Classics() {}

// --------------------------------borrowStock---------------------------------
// Decrements this movie's stock by 1 when a customer borrows it.
// Precondition: None.
// Postcondition: Movie's stock is decremented by 1.
// ----------------------------------------------------------------------------
void Classics::borrowStock() {
  this->stock--;
}

// --------------------------------returnStock---------------------------------
// Increments this movie's stock by 1 when a customer returns it.
// Precondition: None.
// Postcondition: Movie's stock is incremented by 1.
// ----------------------------------------------------------------------------
void Classics::returnStock() {
  this->stock++;
}

// --------------------------------displayMovie--------------------------------
// Displays all attributes this Classics movie contains.
// Precondition: None.
// Postcondition: All of the Classics movie's attributes are displayed.
// ----------------------------------------------------------------------------
void Classics::displayMovie() {
  cout << "Genre: " << this->movieGenre << "\tMedia: " << this->mediaType << 
  "\tStock: " << getStock() << "\tDirector: " << this->director << 
  "\tTitle: " << this->title << "\t\tMajor Actor: " << this->majorActor << 
  "\t\tMonth released: " << this->monthReleased << "\tYear released: " 
  << this->yearReleased << endl;
}

// ------------------------------getMonthReleased------------------------------
// Returns the month this movie was released.
// Precondition: None.
// Postcondition: The movie's release date (month) is returned.
// ----------------------------------------------------------------------------
int Classics::getMonthReleased() const {
  return monthReleased;
}

// -------------------------------getMajorActor--------------------------------
// Returns this movie's major actor (first name then last name).
// Precondition: None.
// Postcondition: The movie's major actor's full name is returned as a string.
// ----------------------------------------------------------------------------
string Classics::getMajorActor() const {
  return majorActor;
}

// ---------------------------------operator==---------------------------------
// Overloaded operator to see if this Classics movie equals another Classics 
// movie. It first compares the month of release, then year of release, then
// the major actor.
// Precondition: None.
// Postcondition: Returns true if the Classics movies are equal, false if not.
// ----------------------------------------------------------------------------
bool Classics::operator==(const Movie& rhs) const {
  if (this->movieGenre == rhs.getMovieGenre() && this->monthReleased == 
      rhs.getMonthReleased() && this->yearReleased == rhs.getYearReleased() && 
      this->majorActor == rhs.getMajorActor()) {
    return true;
  } 
  else {
    return false;
  }
}

// ---------------------------------operator!=---------------------------------
// Overloaded operator to see if this Classics movie does not equal another 
// Classics movie. It first compares the month of release, then year of 
// release, then the major actor.
// Precondition: None.
// Postcondition: Returns true if the Classics movies are unequal, false if not
// ----------------------------------------------------------------------------
bool Classics::operator!=(const Movie& rhs) const {
  return !(*this == rhs);
}

// ---------------------------------operator<=---------------------------------
// Overloaded operator that checks if this Classics movie is less than or equal 
// to another Classics movie. It first compares the month of release, then year
// of release, then the major actor.
// Precondition: None.
// Postcondition: Returns true if this Classics is less than or equal to another
// Classics. False if not.
// ----------------------------------------------------------------------------
bool Classics::operator<=(const Movie& rhs) const {
  if (this->yearReleased < rhs.getYearReleased()) {
    return true;
  }
  else if (this->yearReleased == rhs.getYearReleased()) {
    if (this->monthReleased < rhs.getMonthReleased()) {
      return true;
    } 
    if (this->monthReleased == rhs.getMonthReleased()) {
      if (this->majorActor < rhs.getMajorActor() || 
          this->majorActor == rhs.getMajorActor()) {
        return true;
      }
      return false;
    }
    return false;
  }
  else {
    return false;
  }
}
// ---------------------------------operator<----------------------------------
// Overloaded operator that checks if this Classics movie is less than another
// Classics movie. It first compares the month of release, then year of 
// release, then the major actor.
// Precondition: None.
// Postcondition: Returns true if this Classics is less than another Classics.
// False if not.
// ----------------------------------------------------------------------------
bool Classics::operator<(const Movie& rhs) const {
  if (this->yearReleased < rhs.getYearReleased()) {
    return true;
  }
  else if (this->yearReleased == rhs.getYearReleased()) {
    if (this->monthReleased < rhs.getMonthReleased()) {
      return true;
    } 
    if (this->monthReleased == rhs.getMonthReleased()) {
      if (this->majorActor < rhs.getMajorActor()) {
        return true;
      }
      return false;
    }
    return false;
  }
  else {
    return false;
  }
}
// ---------------------------------operator>=---------------------------------
// Overloaded operator that checks if this Classics movie is greater than or 
// equal to another Classics movie. It first compares the month of release, 
// then year of release, then the major actor.
// Precondition: None.
// Postcondition: Returns true if this Classics is greater than or equal to 
// another Classics. False if not.
// ----------------------------------------------------------------------------
bool Classics::operator>=(const Movie& rhs) const {
  if (this->yearReleased > rhs.getYearReleased()) {
    return true;
  }
  else if (this->yearReleased == rhs.getYearReleased()) {
    if (this->monthReleased > rhs.getMonthReleased()) {
      return true;
    } 
    if (this->monthReleased == rhs.getMonthReleased()) {
      if (this->majorActor > rhs.getMajorActor() || 
          this->majorActor == rhs.getMajorActor()) {
        return true;
      }
      return false;
    }
    return false;
  }
  else {
    return false;
  }
}

// ---------------------------------operator>----------------------------------
// Overloaded operator that checks if this Classics movie is greater than 
// another Classics movie. It first compares the month of release, then year of
// release, then the major actor.
// Precondition: None.
// Postcondition: Returns true if this Classics is greater than another
// Classics. False if not.
// ----------------------------------------------------------------------------
bool Classics::operator>(const Movie& rhs) const {
  if (this->yearReleased > rhs.getYearReleased()) {
    return true;
  }
  else if (this->yearReleased == rhs.getYearReleased()) {
    if (this->monthReleased > rhs.getMonthReleased()) {
      return true;
    } 
    if (this->monthReleased == rhs.getMonthReleased()) {
      if (this->majorActor > rhs.getMajorActor()) {
        return true;
      }
      return false;
    }
    return false;
  }
  else {
    return false;
  }
}