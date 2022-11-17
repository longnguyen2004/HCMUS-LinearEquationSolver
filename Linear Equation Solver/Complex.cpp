struct Complex {
	double _real, _imag;
	Complex(double real, double imag) : _real(real), _imag(imag)
	{

	}
	Complex operator+(const Complex& rhs) {
		return Complex(this->_real + rhs._real, this->_imag + rhs._imag);
	}
	Complex operator-(const Complex& rhs) {
		return Complex(this->_real + rhs._real, this->_imag + rhs._imag);
	}
	Complex operator*(const Complex& rhs) {
		return Complex(
			this->_real * rhs._real - this->_imag * rhs._imag,
			this->_real * rhs._imag - this->_imag * rhs._real
		);
	}
	Complex operator/(const Complex& rhs) {
		return Complex(
			(this->_real * rhs._real - this->_imag * rhs._imag)/(this->_real * this->_real + this->_imag * this->_imag),
			(this->_real * rhs._imag + this->_imag * rhs._real)/(this->_real * this->_real + this->_imag * this->_imag)
		);
	}
};