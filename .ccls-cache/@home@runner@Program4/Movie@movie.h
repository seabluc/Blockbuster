// ---------------------------------movie.h---------------------------------
// Group 9 CSS343D
// Created 3/01/23
// Date of Last Modification: 3/15/23
// ----------------------------------------------------------------------------
/* Purpose - Header file for all movies in Blockbuster. Serves as a base class
   for movie genres: Classics, Drama, and Comedy.
*/
#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <list>
using namespace std;

class Movie {
public:
  // Constructors & Destructor
  Movie();
  // For our commands to properly work, every movie must have these parameters:
  Movie(char movieGenre, char mediaType, int stock, string director,
        string title, int yearReleased);
  virtual ~Movie(); // Deallocate derived classes first.

  // Virtual methods for derived movies to implement
  virtual void borrowStock();  // Remove stock via borrow command
  virtual void returnStock();  // Add stock via return command
  virtual void displayMovie(); // Display information about this movie

  // Getters 
  char getMovieGenre() const;
  char getMediaType() const;
//  virtual int getStock() const;  
  int getStock() const;
  string getDirector() const;
  string getTitle() const;
  int getYearReleased() const;
  virtual int getMonthReleased() const;
  virtual string getMajorActor() const;

  // Virtual overloaded operators
  virtual bool operator==(const Movie &rhs) const;
  virtual bool operator!=(const Movie &rhs) const;
  virtual bool operator<=(const Movie &rhs) const;
  virtual bool operator<(const Movie &rhs) const;
  virtual bool operator>=(const Movie &rhs) const;
  virtual bool operator>(const Movie &rhs) const;

protected:
  // Data members that all movies must contain
  char movieGenre;  // Expected 'F', 'C', 'D'
  char mediaType;   // Expected to only be 'D' due to only selling DVD's
  int stock;
  string director;  // First name then last name of director
  string title;     // Title of movie
  int yearReleased; 
};
#endif