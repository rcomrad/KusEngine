#ifndef DOM_MATH_H
#define DOM_MATH_H

#include "type.hpp"
#include "string.hpp"

namespace dom
{
	class Math
	{
	public:
		static uint_64 getHash(str_const_ref aStr);
	};
}

#endif // !DOM_MATH_H