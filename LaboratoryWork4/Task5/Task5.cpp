#include <iostream>

/// Точка.
struct Point {
  int x;
  int y;
};

/// Висоти трикутника.
struct TriangleHeignts {
  double heignts1;
  double heignts2;
  double heignts3;
};

/// Отримати довжину між двома точками.
double getLenght(const Point &point1, const Point &point2) {
  return abs(sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2)));
}

/// Отримати периметр трикутника.
double getPerimeter(const double &side1, const double &side2,
                    const double &side3) {
  return side1 + side2 + side3;
}

/// Отримати площу трикутника.
double getArea(const double &side1, const double &side2, const double &side3,
               const double &semiperimeter) {
  return sqrt(semiperimeter * (semiperimeter - side1) *
              (semiperimeter - side2) * (semiperimeter - side3));
}

/// Отримати відстань від точки до сторони.
double getDistance(const Point &point, const double &side,
                   const double &areaTriangle) {
  return 2 * areaTriangle / side;
}

/// Отримати висоти трикутника.
TriangleHeignts getTriangleHeignts(const Point &point1, const double &side1,
                                   const Point &point2, const double &side2,
                                   const Point &point3, const double &side3,
                                   const double &areaTriangle) {
  return {getDistance(point1, side1, areaTriangle),
          getDistance(point2, side2, areaTriangle),
          getDistance(point3, side3, areaTriangle)};
}

/// Надрукувати висоти трикутника.
void printTriangleHeignts(const TriangleHeignts &triangleHeignts,
                          const std::string &name) {
  std::cout << "Heights " << name << ":\n"
            << "  Height 1: " << triangleHeignts.heignts1 << '\n'
            << "  Height 2: " << triangleHeignts.heignts2 << '\n'
            << "  Height 3: " << triangleHeignts.heignts3 << "\n\n";
}

int main() {
  const Point a{-5, -5};
  const Point b{-5, 5};
  const Point c{5, 5};
  const Point d{5, -5};

  const double ab = getLenght(a, b);
  const double ac = getLenght(a, c);
  const double ad = getLenght(a, d);

  std::cout << "AB: " << ab << '\n'
            << "AC: " << ac << '\n'
            << "AD: " << ad << "\n\n";

  const double bc = getLenght(b, c);
  const double bd = getLenght(b, d);
  const double cd = getLenght(c, d);

  const double perimeterABC = getPerimeter(ab, bc, ac);
  const double perimeterABD = getPerimeter(ab, bd, ad);
  const double perimeterACD = getPerimeter(ac, cd, ad);

  std::cout << "Perimeter ABC: " << perimeterABC << '\n'
            << "Perimeter ABD: " << perimeterABD << '\n'
            << "Perimeter ABD: " << perimeterACD << "\n\n";

  const double areaABC = getArea(ab, bc, ac, perimeterABC / 2);
  const double areaABD = getArea(ab, bd, ad, perimeterABD / 2);
  const double areaACD = getArea(ac, cd, ad, perimeterACD / 2);

  std::cout << "Area ABC: " << areaABC << '\n'
            << "Area ABD: " << areaABD << '\n'
            << "Area ABD: " << areaACD << "\n\n";

  const Point p{0, 0};

  const double pa = getLenght(p, a);
  const double pb = getLenght(p, b);
  const double pc = getLenght(p, c);

  const double distancePAB =
      getDistance(p, ab, getArea(pa, ab, pb, getPerimeter(pa, ab, pb) / 2));
  const double distancePAC =
      getDistance(p, ac, getArea(pa, ac, pc, getPerimeter(pa, ac, pc) / 2));
  const double distancePBC =
      getDistance(p, bc, getArea(pb, bc, pc, getPerimeter(pb, bc, pc) / 2));

  std::cout << "Distance PAB: " << distancePAB << '\n'
            << "Distance PAC: " << distancePAC << '\n'
            << "Distance PBC: " << distancePBC << "\n\n";

  const TriangleHeignts abc{getTriangleHeignts(a, bc, b, ac, c, ab, areaABC)};
  printTriangleHeignts(abc, "ABC");

  const TriangleHeignts abd{getTriangleHeignts(a, bd, b, ad, d, ab, areaABD)};
  printTriangleHeignts(abd, "ABD");

  const TriangleHeignts acd{getTriangleHeignts(a, cd, c, ad, d, ac, areaACD)};
  printTriangleHeignts(acd, "ACD");
  return 0;
}