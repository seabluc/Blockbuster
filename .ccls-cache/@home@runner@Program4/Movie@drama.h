// ----------------------------------drama.h-----------------------------------
// Group 9 CSS343D
// Created 3/01/23
// Date of Last Modification: 3/15/23
// ----------------------------------------------------------------------------
/* Purpose - Header file for Drama movies in Blockbuster. Class derives from
   Movie.
*/
#ifndef DRAMA_H
#define DRAMA_H
#include "movie.h"

class Drama : public Movie {
public:
  Drama(char movieGenre, char mediaType, int stock, string director,
        string title, int yearReleased);
  ~Drama();

  // Methods
  void borrowStock();
  void returnStock();
  void displayMovie();

  // Operator overload to compare drama movies by director, then title.
  bool operator==(const Movie& rhs) const;
  bool operator!=(const Movie& rhs) const;
  bool operator<=(const Movie& rhs) const;
  bool operator<(const Movie& rhs) const;
  bool operator>=(const Movie& rhs) const;
  bool operator>(const Movie& rhs) const;
};
#endif