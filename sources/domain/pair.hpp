#ifndef DOM_PAIR_HPP
#define DOM_PAIR_HPP

#include <utility>

namespace dom
{
	template<typename T1, typename T2 = T1>
	union Pair
	{
		struct
		{
			T1 i;
			T2 j;
		};
		struct
		{
			T1 x;
			T2 y;
		};
		struct
		{
			T1 key;
			T2 value;
		};
		struct
		{
			T1 first;
			T2 second;
		};

		Pair() :
			x(),
			y()
		{}

		// template <typename ARG>
		// Pair(ARG&& other) : 
		// 	x(std::forward<T1>(other.x)),
		// 	y(std::forward<T2>(other.y))
		// {}
		Pair(const Pair<T1, T2>& other) : 
			x(other.x),
			y(other.y)
		{}
		Pair(Pair<T1, T2>&& other) : 
			x(std::forward<T1>(other.x)),
			y(std::forward<T2>(other.y))
		{}

		template <typename ARG1, typename ARG2>
		Pair(ARG1&& xInit, ARG2&& yInit) :
			x(std::forward<T1>(xInit)),
			y(std::forward<T2>(yInit))
		{}

		~Pair() = default;

		void operator+= (const Pair& other)
		{
			x += other.x;
			y += other.y;
		}
		void operator-= (const Pair& other)
		{
			x -= other.x;
			y -= other.y;
		}

		// template <typename ARG>
		// Pair& operator=(ARG&& other)
		// {
		// 	x = std::forward<T1>(other.x);
		// 	y = std::forward<T2>(other.y);
		// 	return *this;
		// }
		Pair& operator=(const Pair<T1, T2>& other)
		{
			x = other.x;
			y = other.y;
			return *this;
		}
		Pair& operator=(Pair<T1, T2>&& other)
		{
			x = std::forward<T1>(other.x);
			y = std::forward<T2>(other.y);
			return *this;
		}

		friend Pair operator+ (const Pair& a1, const Pair& a2)
		{
			Pair<T1, T2> res{ a1.x + a2.x, a1.y + a2.y };
			return res;
		}
		friend Pair operator+ (const Pair& a1, Pair&& a2)
		{
			a2.x += a1.x;
			a2.y += a1.y;
			return a2;
		}
		friend Pair operator+ (Pair&& a1, const Pair& a2)
		{
			return a2 + std::move(a1);
		}
		friend Pair operator+ (Pair&& a1, Pair&& a2)
		{
			a1.x += a2.x;
			a1.y += a2.y;
			return a1;
		}

		friend Pair operator- (const Pair& a1, const Pair& a2)
		{
			Pair<T1, T2> res{ a1.x - a2.x, a1.y - a2.y };
			return res;
		}
		friend Pair operator- (const Pair& a1, Pair&& a2)
		{
			a2.x -= a1.x;
			a2.y -= a1.y;
			return a2;
		}
		friend Pair operator- (Pair&& a1, const Pair& a2)
		{
			return a2 - std::move(a1);
		}
		friend Pair operator- (Pair&& a1, Pair&& a2)
		{
			a1.x -= a2.x;
			a1.y -= a2.y;
			return a1;
		}

		bool operator< (const Pair& other) const
		{
			if (x != other.x) return y < other.y;
			return y < other.y;
		}
		bool operator>(const Pair& other) const
		{
			if (x != other.x) return y > other.y;
			return y > other.y;
		}
		bool operator== (const Pair& other) const
		{
			return x == other.x && y == other.y;
		}
		bool operator!= (const Pair& other) const
		{
			return x != other.x || y != other.y;
		}

		private:
		class PairBracketAccessResult
		{
			friend Pair;
		public:
			operator T1&()
			{
				if (mIndex != 0) exit(-1);
				return mRes.x;
			}

			operator T2&()
			{
				if (mIndex != 1) exit(-1);
				return mRes.y;
			}

		private:
			Pair& mRes;
			int mIndex;

			PairBracketAccessResult(Pair& aRes, int aIndex) :
				mRes	(aRes),
				mIndex	(aIndex)
			{}
		};

		public:
			PairBracketAccessResult operator[] (const int& aIndex)
			{
				return PairBracketAccessResult(*this, aIndex);
			}
	};
}

#endif // !DOM_PAIR_HPP