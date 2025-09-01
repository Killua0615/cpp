//main.cpp
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const p);

int main(){
  Point a(0.f,0.f), b(5.f,0.f), c(0.f,5.f);
  Point p1(1.f,1.f);
  Point p2(5.f,0.f);
  Point p3(2.5f,2.5f);
  std::cout << (bsp(a,b,c,p1) ? "inside" : "outside") << std::endl;
  std::cout << (bsp(a,b,c,p2) ? "inside" : "outside") << std::endl;
  std::cout << (bsp(a,b,c,p3) ? "inside" : "outside") << std::endl;
  return 0;
}
