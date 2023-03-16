// ----------------------------------comedy.h----------------------------------
// Group 9 CSS343D
// Created 3/01/23
// Date of Last Modification: 3/15/23
// ----------------------------------------------------------------------------
/* Purpose - Header file for Comedy movies in Blockbuster. Class derives from
   Movie.
*/
#ifndef COMEDY_H
#define COMEDY_H
#include "movie.h"

class Comedy : public Movie {
public:
  Comedy(char movieGenre, char mediaType, int stock, string director,
        string title, int yearReleased);
  ~Comedy();

  // Methods
  void borrowStock();
  void returnStock();
  void displayMovie();

  // Operator overload to compare comedies by title, then release date (year).
  bool operator==(const Movie& rhs) const;
  bool operator!=(const Movie& rhs) const;
  bool operator<=(const Movie& rhs) const;
  bool operator<(const Movie& rhs) const;
  bool operator>=(const Movie& rhs) const;
  bool operator>(const Movie& rhs) const;
};
#endif