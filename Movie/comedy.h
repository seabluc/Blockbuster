#ifndef COMEDY_H
#define COMEDY_H
#include "movie.h"

class Comedy : public Movie {
public:
  Comedy(char movieGenre, char mediaType, int stock, string director,
        string title, int yearReleased);
  virtual ~Comedy();

  // Getter
  virtual int getStock();

  // Operator overload
  virtual bool operator==(const Movie& rhs) const;
  virtual bool operator!=(const Movie& rhs) const;
  virtual bool operator<=(const Movie& rhs) const;
  virtual bool operator<(const Movie& rhs) const;
  virtual bool operator>=(const Movie& rhs) const;
  virtual bool operator>(const Movie& rhs) const;
protected:
  int stock;
};
#endif