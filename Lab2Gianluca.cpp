#include <iostream>

#include "Rational.h"


int main() {

	//facciamo una prova se funziona l'operatore +

	Rational a = Rational(5, 2);
	Rational b = Rational(2, 3);

	Rational c = a + b;
	double s = c.to_double();

	std::cout << s << " :mi aspetto che il risultato sia 3.1666" << "\n";
	std::cout << c << " :mi aspetto che il risultato sia 19/6" << "\n";
	std::cout << a * b << " :mi aspetto che il risultato sia 5/3" << "\n";
	std::cout << a / b << " :mi aspetto che il risultato sia 15/4" << "\n";

	c = Rational(15, 5);
	std::cout << c << " :mi aspetto che il risultato sia 3" << "\n";

	c = Rational(5, 15);
	std::cout << c << " :mi aspetto che il risultato sia 3" << "\n";

	if (a > b) 
		std::cout << "a > b risultato corretto" << "\n";

	else
		std::cout << "a !> b ho sbgliato qualcosa :)";

	if (b < a)
		std::cout << "a < b risultato corretto" << "\n";

	else
		std::cout << "a !< b ho sbgliato qualcosa :)";

	Rational d = Rational(5, 2);

	if (a == d)
		std::cout << "a == b risultato corretto" << "\n";

	else
		std::cout << "a != b ho sbgliato qualcosa :)";


	Rational e = a;


	std::cout << e << " :mi aspetto che il risultato sia 5/2" << "\n";

}