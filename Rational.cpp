#include "Rational.h";
#include <iostream>

//costruttore base inizializza numeratore = 0 e denominatore = 1
Rational::Rational() : num{ 0 }, den{ 1 } {}

//costruttore base inizializza numeratore a n e denominatore = 1
Rational::Rational(int n) : num{ n }, den{ 1 } {}

//costruttore base inizializza numeratore a n e denominatore =d
Rational::Rational(int n, int d) : num{ n }, den{ d } {} 


int Rational::MCM(int a, int b) { //trova il minimo comune multiplo

	int mcm = a;

	//ciclo che trova il minimo comune multiplo e lo salva in una variabile chiamata mcm
	while (((mcm % a != 0) or (mcm % b != 0))) {
		mcm += a;
	}

	//std::cout << "minimo comune multiplo: " << mcm << "\n";

	return mcm;

}

int Rational::MCD(int a, int b) const { //trovo il minimo comune divisore
	
	if (a > b) { // se a è maggiore di b faccio lo swap così sono sicuro b sia maggiore
	
		int temp = b;

		b = a;
		a = temp;

	}

	int mcd = 1;

	//vado a trovare tutti i divisori dei due numeri numeri e salvo il più grande con resto 0
	for (int i = 2; i <= a; i++) {
		if ((a % i == 0) && (b % i == 0))
			mcd = i;
	}
	
	return mcd;

}

Rational Rational::operator+(Rational const& obj) { //overload dell'operatore +

	//trovo il massimo minimo comune multiplo
	int mcm = MCM(den, obj.den);

	//sommo i due numeratori dopo aver fatto il denominatore comune
	int numeratore = (num * (mcm/den)) + (obj.num * (mcm/obj.den));

	//std::cout << "numeratore: " << numeratore << "\n";

	//ritorno un Rational con la somma dei due
	return Rational(numeratore / MCD(numeratore, mcm), mcm / MCD(numeratore, mcm));

}

Rational Rational::operator-(Rational const& obj) {

	//trovo il massimo minimo comune multiplo
	int mcm = MCM(den, obj.den);

	//sottraggo i due numeratori dopo aver fatto il denominatore comune
	int numeratore = (num * (mcm / den)) - (obj.num * (mcm / obj.den));

	//std::cout << "numeratore: " << numeratore << "\n";

	//ritorno un Rational con la sottrazione dei due
	return Rational(numeratore / MCD(numeratore, mcm), mcm / MCD(numeratore, mcm));

}

Rational Rational::operator*(Rational const& obj) {
	
	//vado a moltiplicare i numeratori e i denominatori
	int numeratore = num * obj.num;
	int denominatore = den * obj.den;

	//restituisco un Rational semplificato
	return Rational(numeratore / MCD(numeratore, denominatore), denominatore / MCD(numeratore, denominatore));

}

Rational Rational::operator/(Rational const& obj) {
	
	//moltiplico numeratore con il denominatore del secondo rational e viceversa
	int numeratore = num * obj.den;
	int denominatore = den * obj.num;

	//retirno un Rational semplificato
	return Rational(numeratore / MCD(numeratore, denominatore), denominatore / MCD(numeratore, denominatore));

}

bool Rational::operator==(Rational const& obj) {
	
	//faccio un controllo se i due numeri sono uguali
	return (this->to_double() == obj.to_double());

}

bool Rational::operator>(Rational const& obj) {
	
	//faccio un controllo se il primo rational è maggiore del secondo
	return (this->to_double() > obj.to_double());

}

bool Rational::operator<(Rational const& obj) {
	
	//faccio un controllo se il primo rational è minore del secondo
	return (this->to_double() < obj.to_double());

}

std::ostream& operator<<(std::ostream& os, const Rational& obj) {

	//vado a stampare il rational

	//se il denominatore è = 1 non ha senso stamparlo stampo solo il numeratore
	if (obj.den / obj.MCD(obj.num, obj.den) == 1)
		os << obj.num / obj.MCD(obj.num, obj.den);

	//se il denomincatore è diverso allora stampo numertatore / denominatore
	else
		os << obj.num / obj.MCD(obj.num, obj.den) << "/" << obj.den / obj.MCD(obj.num, obj.den);

	return os;

}


double Rational::to_double() const {

	//vado a fare un cast a double e fare la divisione in modo da dare in output il valore di num/den
	double temp = static_cast<double>(num) / den;
	
	return temp;

} 