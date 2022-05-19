#ifndef BASIC_OBJECT_HPP
#define BASIC_OBJECT_HPP

#include <vector>
#include <set>

#include "domain/dom_string.hpp"

#include "object_types.hpp"

namespace lgc
{
    class BasicObject
    {
	public:
		BasicObject() = default;
		virtual ~BasicObject();
		void addTag(str_const_ref aTag);
		void addTag(std::vector<str_val> aTags);

	private:
		//std::vector<tag_type> mTags;
		std::set<tag_type> mTags;
    };
}

#endif // !BASIC_OBJECT_HPP