#ifndef DOM_MATH_H
#define DOM_MATH_H

#include "dom_type.hpp"
#include "dom_string.hpp"

namespace dom
{
	class Math
	{
	public:
		static uint_64 getHash(std_const_ref aStr);
	};
}

#endif // !DOM_MATH_H