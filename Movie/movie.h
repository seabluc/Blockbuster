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

  // Methods
  bool changeStock(int); // Add or remove stock via. Borrow or Return

  // Getters
  char getMovieGenre() const;
  char getMediaType() const;
  virtual int getStock() const;
  string getDirector() const;
  string getTitle() const;
  int getYearReleased() const;
  
  // Operator overload
  virtual bool operator==(const Movie& rhs) const;
  virtual bool operator!=(const Movie& rhs) const;
  virtual bool operator<=(const Movie& rhs) const;
  virtual bool operator<(const Movie& rhs) const;
  virtual bool operator>=(const Movie& rhs) const;
  virtual bool operator>(const Movie& rhs) const;
protected:
  struct MovieNode {
    MovieNode* left;
    MovieNode* right;
    Movie* movie;
  };
  list<Movie> movieList; // Linked list to store all movies
  char movieGenre;       // 'F', 'C', 'D' 
  const char mediaType;  // Always set to 'D' due to only selling DVD's
  int stock;
  string director;       // First name then last name of director
  string title;          // Title of movie
  int yearReleased;
};
#endif