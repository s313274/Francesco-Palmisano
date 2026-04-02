#include <numeric>
#include <iostream>

template<typename I> requires std::integral<I>




class rational
{
	I num_;
	I den_;
	
	void semplificazione()
	{
		if (den_==0) return;
		I mcd= std::gcd(num_, den_);
		num_ = num_ / mcd;
		den_ = den_ / mcd;
	}
	public:
	
	//Costruttore di default, inizializza a 0 (sotto forma di 0/1)
	rational()
	: num_(0) , den_(1)
	{}
	
	rational (I n) //"Trasforma" un intero n in un razionale n/1 per semplificare le operazioni
	: num_(n) , den_(1)
	{}
	
	//Costruttore user defined
	rational(I n , I d)
	: num_(n) , den_(d)
	{
		if (den_!=0)
		{
			if (den_ < 0)
			{
				num_=-num_;
				den_=-den_;
			}
			semplificazione();
		}
	}
	
	
	//Metodi num() e den()
	I num() const { return num_; }
	I den() const { return den_; }
	
	//Operatore +=
	rational& operator+=(const rational& other)
	{
		if ( (num_==0 && den_==0) || (other.num_==0 && other.den_==0) )
		{
			num_=0;
			den_=0;
			return *this;
		} //Restitiuisce Nan nel caso in cui almeno uno fra i due numeri sia NaN
		
		if ( den_ == 0 || other.den_ == 0 )
		{
			if (den_==0 && other.den_==0)
			{
				if (num_ >0 && other.num_>0) 
				{
					num_=1;
					den_=0;
					return *this;
				} //Se sono entrambi +Inf allora la somma sarà +Inf
				if (num_<0 && other.num_<0)
				{
					num_=-1;
					den_=0;
					return *this;
				}//Se sono entrambi -Inf allora la somma sarà -Inf
				num_=0;
				den_=0;
				return *this;
				//Unico caso rimasto: gli Inf sono discordi, la somma sarà quindi NaN
			}
			if (den_==0)
			{
				return *this;
			}
			else
			{
				num_=other.num_;
				den_=0;
				return *this;
			}
		}
		//Somma e semplificazione
		num_ = num_ * other.den_ + other.num_ * den_;
		den_ = den_ * other.den_;
		semplificazione();
		return *this;
	}
	
	//Operatore +
	rational operator+(const rational& other) const
	{
		rational sum = *this;
		sum+=other;
		return sum;
	}
	
	//Operatore -=
	rational& operator-=(const rational& other)
	{
		if ( (num_==0 && den_==0) || (other.num_==0 && other.den_==0) )
		{
			num_=0;
			den_=0;
			return *this;
		} //Restituisce Nan nel caso in cui almeno uno fra i due numeri sia NaN
		
		if ( den_ == 0 || other.den_ == 0 )
		{
			if (den_==0 && other.den_==0)
			{
				if (num_ > 0 && other.num_ < 0) 
				{
					num_=1;
					den_=0;
					return *this;
				} // +Inf - (-Inf) = +Inf
				
				if (num_ < 0 && other.num_ > 0)
				{
					num_=-1;
					den_=0;
					return *this;
				} // -Inf - (+Inf) = -Inf
				
				num_=0;
				den_=0;
				return *this;
				// Unico caso rimasto: gli Inf sono concordi, la sottrazione sarà Nan
			}
			if (den_==0)
			{
				return *this;
			}
			else
			{
				num_=-other.num_; 
				den_=0;
				return *this;
			}
		}
		//Sottrazione e semplificazione
		num_ = num_ * other.den_ - other.num_ * den_;
		den_ = den_ * other.den_;
		semplificazione();
		return *this;
	}
	
	//Operatore -
	rational operator-(const rational& other) const
	{
		rational sub = *this;
		sub-=other;
		return sub;
	}
	
	//Operatore *=
	rational& operator*=(const rational& other)
	{
		if ( (num_==0 && den_==0) || (other.num_==0 && other.den_==0) )
		{
			num_=0;
			den_=0;
			return *this;
		} //Restituisce Nan nel caso in cui almeno uno fra i due numeri sia NaN
		
		if (den_==0 && other.den_==0)
			{
				if ( (num_ > 0 && other.num_ < 0) || (num_ < 0 && other.num_ > 0)) 
				{
					num_=-1;
					den_=0;
					return *this;
				} // +Inf * (-Inf) = -Inf (e viceversa)
				num_=1;
				den_=0;
				return *this;
				// Inf concordi risultano in +Inf
			}
		if (den_==0 || other.den_==0)
		{
			if (den_==0)
			{
				if (other.num_==0)
				{
					num_=0;
					den_=0;
					return *this;
				}//caso Inf*0
				
				num_=num_*other.num_;
				den_=0;
				return *this; //restituisce Inf di segno corretto
			}
			
			if (num_==0)
			{
				num_=0;
				den_=0;
				return *this;
			}//caso Inf*0
			num_=num_*other.num_;
			den_=0;
			return *this; //restituisce Inf di segno corretto
			
			
		}
		//Prodotto e semplificazione
		num_=num_*other.num_;
		den_=den_*other.den_;
		semplificazione();
		return *this;
		
	}
	
	//Operatore *
	rational operator*(const rational& other) const
	{
		rational prod = *this;
		prod*=other;
		return prod;
	}
	
	rational& operator/=(const rational& other)
	{
		rational rec(other.den_,other.num_);
		*this *= rec;
		return *this;
	} //definisco la divisione con prodotto per il reciproco del secondo termine
	
	rational operator/(const rational& other) const
	{
		rational div = *this;
		div/=other;
		return div;
	}
};

//Overload <<
template<typename I>
std::ostream&
operator<<(std::ostream& os, const rational<I>& r)
{
	if (r.den()!=0)
	{
		if (r.num()==0)
		{
			os << "0";
			return os;
		}
		os << r.num() << "/" << r.den();
		return os;
	}
	else
	{
		if (r.num()==0)
		{
			os << "NaN";
		}
		else
		{
			if (r.num()>0) 
			{
				os << "+Inf";
			}
			else 
			{
				os << "-Inf";
			}
		}
	}
	return os;
}
