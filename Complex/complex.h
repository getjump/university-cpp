#ifndef COMPLEX_H
#define COMPLEX_H

#define M_PI 3.14159265358979323846

namespace getjump
{
	namespace Complex
	{
		template<typename T>
		class Complex
		{
		private:
			T real;
			T imaginary;
		public:
			~Complex<T>() 
			{
			}

			Complex<T>();

			Complex<T>(T real, T imaginary)
			{
				this->real = real;
				this->imaginary = imaginary;
			}

			template<typename L>
			void operator = (L a)
			{
				real = a;
			}

			void operator = (Complex a)
			{
				real = a.real;
				imaginary = a.imaginary;
			}

			bool operator == (Complex a) 
			{
				return a.real == this->real && a.imaginary == this->imaginary;
			}

			bool operator != (Complex a)
			{
				return !this->operator==(a);
			}

			operator double()
			{
				return ::abs(this->real*this->real + this->imaginary*this->imaginary);
			}

			bool operator > (Complex a)
			{
				return this->abs() > a.abs();
			}

			bool operator < (Complex a)
			{
				return this->abs() < a.abs();
			}

			bool operator < (double a)
			{
				return this->real < a && this->imaginary < a;
			}

			bool operator >= (Complex a)
			{
				return this->abs() >= a.abs();
			}

			bool operator <= (Complex a)
			{
				return this->abs() <= a.abs();
			}

			Complex operator += (Complex a)
			{
				this->imaginary += a.imaginary;
				this->real += a.imaginary;
				return *this;
			}

			Complex operator -= (Complex a)
			{
				this->imaginary -= a.imaginary;
				this->real -= a.imaginary;
				return *this;
			}

			Complex operator /= (Complex a)
			{
				return this->operator/(a);
			}

			Complex operator *= (Complex a)
			{
				return this->operator*(a);
			}

			Complex operator / (Complex a)
			{
				return Complex((this->real*a.real + this->imaginary*a.imaginary) / (a.real*a.real + a.imaginary*a.imaginary), (a.real*this->imaginary - a.imaginary*this->real) / (a.real*a.real + a.imaginary*a.imaginary));
			}

			Complex operator * (Complex a)
			{
				return Complex(this->real * a.real + this->imaginary * a.imaginary, this->real * a.imaginary + this->imaginary * a.real);
			}

			Complex operator + (Complex a)
			{
				return Complex(this->real + a.real, this->imaginary + a.imaginary);
			}

			Complex operator - (Complex a)
			{
				return Complex(this->real - a.real, this->imaginary - a.imaginary);
			}

			template <typename L>
			operator Complex<L>()
			{
				return Complex<L>((L)real, (L)imaginary);
			}

			double abs()
			{
				return sqrt(real*real + imaginary*imaginary);
			}

			Complex negatate()
			{
				return Complex(-this->real, -this->imaginary);
			}

			Complex conjugate()
			{
				return Complex(this->real, -this->imaginary);
			}

			double arg()
			{
				double theta = atan(real / imaginary);
				if (real == 0 && imaginary == 0)
					return 0;
				else if (real > 0)
					return theta;
				else if (real < 0 && imaginary >= 0)
					return theta + M_PI;
				else if (real < 0 && imaginary < 0)
					return theta - M_PI;
				else if (real == 0 && imaginary > 0)
					return M_PI / 2;
				else if (real == 0 && imaginary < 0)
					return -M_PI / 2;
				return 0;
			}

			Complex rotation(T angle)
			{
				// (Re + iIm) * e ** (i\theta) = (Re + iIm) * (sin\theta + icos\theta)

				T real = this->real*cos(angle) - this->imaginary*sin(angle);
				T imag = this->real*sin(angle) + cos(angle)*this->imaginary;
				return Complex(real, imag);
			}

			T getReal()
			{
				return real;
			}

			T getImaginary()
			{
				return imaginary;
			}
		};

		template<typename T>
		std::ostream& operator<<(std::ostream &output, Complex<T> &C)
		{
			output << C.getReal() << ' ' << (C.getImaginary() < 0 ? '-' : '+') << ' ' << abs(C.getImaginary()) << 'i';
			return output;
		}

		template<typename T>
		std::istream& operator>>(std::istream  &input, Complex<T> &C)
		{
			input >> C->real >> C->imaginary;
			return input;
		}

		template <typename T>
		Complex<T> operator * (int a, Complex<T> b)
		{
			return Complex<T>(a * b.getReal(), a * b.getImaginary());
		}

		Complex<double> operator + (double a, Complex<double> b)
		{
			return Complex<double>(a + b.getReal(), b.getImaginary());
		}

		template <typename T>
		Complex<T> operator + (T a, Complex<T> b)
		{
			return Complex<T>(a + b.getReal(), b.getImaginary());
		}

		namespace literals
		{
			struct ImaginaryUnit
			{
				ImaginaryUnit() {};
			};

			Complex<int> operator * (ImaginaryUnit a, ImaginaryUnit b)
			{
				return Complex<int>(-1, 0);
			}

			template<typename T>
			Complex<T> operator * (T a, ImaginaryUnit b)
			{
				return Complex<T>(0, a);
			}

			template<typename T>
			Complex<T> operator * (Complex<T> a, ImaginaryUnit b)
			{
				return Complex<T>(-a.getImaginary(), a.getReal());
			}

			ImaginaryUnit ii;
		}
	}
}

#endif