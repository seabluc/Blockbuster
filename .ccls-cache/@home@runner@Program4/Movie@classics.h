#ifndef CLASSICS_H
#define CLASSICS_H
// ---------------------------------classics.h---------------------------------
// Group 9 CSS343D
// Created 3/01/23
// Date of Last Modification: 3/15/23
// ----------------------------------------------------------------------------
/* Purpose - Header file for Classics movies in Blockbuster. Class derives from
   Movie.
*/
#include "movie.h"

class Classics : public Movie {
public:
  Classics(char movieGenre, char mediaType, int stock, string director,
           string title, string majorActor, int monthReleased, int yearReleased); 
  ~Classics();

  // Methods
  void borrowStock();
  void returnStock();
  void displayMovie();

  // Getters
  int getMonthReleased() const;
  string getMajorActor() const;

  // Operator overload to compare classicals by release date, then major Actor.
  bool operator==(const Movie& rhs) const;
  bool operator!=(const Movie& rhs) const;
  bool operator<=(const Movie& rhs) const;
  bool operator<(const Movie& rhs) const;
  bool operator>=(const Movie& rhs) const;
  bool operator>(const Movie& rhs) const;
protected:
  int monthReleased; // 1-12
  string majorActor;
};
#endif