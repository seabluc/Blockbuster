#ifndef CLASSICS_H
#define CLASSICS_H
#include "movie.h"

// Classics have additional attributes. Comedy and Drama are kinda the same as Movie.
class Classics : public Movie {
public:
  Classics(char movieGenre, char mediaType, int stock, string director,
        string title, string majorActor, int monthReleased, int yearReleased); 
  virtual ~Classics();

  // Getters
  virtual int getStock();
  virtual int getMonthReleased() const;
  virtual string getMajorActor() const;

  // Operator overload
  virtual bool operator==(const Movie& rhs) const;
  virtual bool operator!=(const Movie& rhs) const;
  virtual bool operator<=(const Movie& rhs) const;
  virtual bool operator<(const Movie& rhs) const;
  virtual bool operator>=(const Movie& rhs) const;
  virtual bool operator>(const Movie& rhs) const;
protected:
  int stock;
  int monthReleased; // 1-12
  string majorActor; // First name then last name;
};
#endif