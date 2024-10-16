#include <stdint.h>

class Parallelogram {
  public:
    enum class Kind : uint8_t {
      PARALLELOGRAM, // A quadrilateral with equal opposing sides
      RECTANGLE,     // A parallelogram with all angles equal
      EQUILATERAL,       // A parallelogram with all sides equal
      SQUARE,        // A parallelogram with both equal angles and equal sides
    };
      // Constructs a new parallelogram from the side lengths and angle passed in.
    Parallelogram(int side1, int side2, double interior);

    // Return the sum of all sides of the parallelogram
    int getPerimeter() const;

    // Return the area of the parallelogram
    double getArea() const;

    // Return the most specific kind or classification of the parallelogram
    // as determined by its sides and angle.
    Kind getKind() const;

    // Return true if this parallelogram is a rectangle.
    bool isRectangle() const;

    // Return true if this parallelogram is a rhombus.
    bool isEquilateral() const;

    // Return true if this parallelogram is a square.
    bool isSquare() const;

  private:
    const int side1;
    const int side2;
    const double interior;
};



