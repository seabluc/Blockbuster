#ifndef DRAMA_H
#define DRAMA_H
#include "movie.h"

class Drama : public Movie {
public:
  Drama(char movieGenre, char mediaType, int stock, string director,
        string title, int yearReleased);
  virtual ~Drama();

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