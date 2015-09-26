#include <ostream>
#include <cmath>
#include <iomanip>


class taylor {
	friend std::istream &operator>> (std::istream &in, taylor &t) {
		in >> t.x;
		return in;
	}

	friend std::ostream &operator<< (std::ostream &out, const taylor &t) {

		if (t.x == 0 || t.n == 0)
			return out;
		for (int i = 0; i < t.n; i++) {
			out << std::setw(7) << t.func(i) << ' ';
		}
		out << "\n";
		return out;
	}

public:
	taylor() {
		n = 2;
		x = 0;
	}

	void setn(int n) {
		this->n = n;
	}
private:
	int factorial(int n) const // скопировано с википедии
	{
		return (n < 2) ? 1 : n * factorial(n - 1);
	}

	double func(int i) const {
		double ret = pow(-1,i);
		ret /= factorial(2*n);
		ret *= pow(2 * x, 2*i); // 2х из-за тгго, чтоу нас квадрат косинуса
		return ret;
	}

	int n;
	double x;
};
