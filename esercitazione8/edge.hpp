#pragma once
#include <iostream>
#include <algorithm>

template <typename T> requires std::integral<T>

class edge
{
	private:
	T from_;
	T to_;
	
	public:
	
	//costruttore
	edge(T a, T b)
	{
		from_=std::min(a,b);
		to_=std::max(a,b);
	}
	
	//metodi from() e to():
	T from() const
	{
		return from_;
	}
	
	T to() const
	{
		return to_;
	}
	
	//operator<
	bool operator<(const edge& other) const
	{
		if(from_ < other.from_)
		{
			return true;
		}
		else if ((from_==other.from_) && (to_ < other.to_))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	//operator ==
	bool operator==(const edge& other) const
	{
		if(from_==other.from_ && to_==other.to_)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

//operator <<
template<typename T>
std::ostream& operator<<(std::ostream& os, const edge<T>& e)
{
	os << "(" << e.from() << "," << e.to() << ")";
	return os;
}
