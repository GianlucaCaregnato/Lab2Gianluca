#include <ostream>

class Rational
{
public:

	//costruttore che genera un Rational = 0, non accetta argomenti
	Rational();

	//costruttore che genera un Rational = int/1, Come argomento richiede un int
	Rational(int);

	//costruttore che genera un Rational int/int , richiede un int che sarà il numeratore e uno che sarà il denominatore
	Rational(int, int);


	//funzione che trova il minimo comune divisore
	int MCM(int, int);

	int MCD(int, int) const;

	//overload di addizione
	Rational operator + (Rational const& obj);

	//overload di sottrazione
	Rational operator - (Rational const& obj);

	//overload di moltiplicazione
	Rational operator * (Rational const& obj);

	//overload di divisione
	Rational operator / (Rational const& obj);

	//overload operatore di equality
	bool operator == (Rational const& obj);

	//overload operatore di >
	bool operator > (Rational const& obj);

	//overload operatore di <
	bool operator < (Rational const& obj);

	//overload della funzione di stampa
	friend std::ostream& operator << (std::ostream& os, const Rational& obj);

	//funzione che ti converte il tuo oggetto in un double
	double to_double() const;



private:

	int num;
	int den;

};

