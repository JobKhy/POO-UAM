#include <iostream>
#include <numeric>

struct fraccion {
   int num, den;
};

fraccion irreducible(fraccion fr){
   int d = std::gcd(fr.num, fr.den);
   return {fr.num / d, fr.den / d};
}

fraccion operator+(fraccion a, fraccion b){
   return irreducible({a.num * b.den + a.den * b.num, a.den * b.den});
}

fraccion operator-(fraccion a, fraccion b){
   return irreducible({a.num * b.den - a.den * b.num, a.den * b.den});
}

fraccion operator*(fraccion a, fraccion b){
   return irreducible({a.num * b.num, a.den * b.den});
}

fraccion operator/(fraccion a, fraccion b){
   return irreducible({a.num * b.den, a.den * b.num});
}

fraccion operator+(fraccion fr){
   return fr;
}

fraccion operator-(fraccion fr){
   return {-fr.num, fr.den};
}

fraccion operator~(fraccion fr){
   return {fr.den, fr.num};
}

double flotante(fraccion fr)
{
   return double(fr.num) / fr.den;
}

bool operator<(fraccion a, fraccion b){
   return a.num * b.den < b.num * a.den;
}

bool operator<=(fraccion a, fraccion b){
   return a.num * b.den <= b.num * a.den;
}

bool operator>(fraccion a, fraccion b){
   return a.num * b.den > b.num * a.den;
}

bool operator>=(fraccion a, fraccion b){
   return a.num * b.den >= b.num * a.den;
}

bool operator==(fraccion a, fraccion b){
   fraccion minA = irreducible(a);
   fraccion minB = irreducible(b);
   return minA.num == minB.num && minA.den == minB.den;
}

bool operator!=(fraccion a, fraccion b){
   fraccion minA = irreducible(a);
   fraccion minB = irreducible(b);
   return minA.num != minB.num || minA.den != minB.den;
}

std::istream &operator>>(std::istream &in, fraccion &f){
   in >> f.num;
   in.ignore();
   in >> f.den;
   return in;
}

std::ostream &operator<<(std::ostream &out, fraccion f){
   out << f.num << "/" << f.den;
   return out;
}

int main()
{
   fraccion f1;
   std::cin >> f1;

   std::cout << "Float: " << flotante(f1) << "\n";
   return 0;
}