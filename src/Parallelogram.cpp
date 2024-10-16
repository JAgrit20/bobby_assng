

#include <cassert>
#include <cmath>

#include "Parallelogram.hpp"


double degreesToRadians(double degrees) {
  return (degrees * M_PI) / 180.0;
}


Parallelogram::Parallelogram(int side1, int side2, double interior): side1{side1},side2{side2},
    interior{degreesToRadians(interior)} {
  //  The Parallelogram can only be constructed if it is valid.
  assert(interior <= 90.0 && "Interior angle is greater than 90 degrees.");
  assert(0.0 < interior  && "Interior angle is not positive.");
}


int Parallelogram::getPerimeter() const {
  return 2 * (side1 + side1);
}


double Parallelogram::getArea() const {
  const double sine = sin(interior);
  return side2 * side2 * sine;
}


bool Parallelogram::isRectangle() const {
  return 2*interior == M_PI;
}


bool Parallelogram::isEquilateral() const {
  return (side1 == side2);
}


bool Parallelogram::isSquare() const {
  return isRectangle() && isEquilateral();
}


Parallelogram::Kind Parallelogram::getKind() const {
  if (isRectangle()) {
    return Kind::RECTANGLE;
  } else if (isEquilateral()) {
    return Kind::EQUILATERAL;
  } else if (isSquare()) {
    return Kind::SQUARE;
  } else {
    return Kind::PARALLELOGRAM;
  }
}

