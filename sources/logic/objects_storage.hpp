#ifndef OBJECT_STORAGE_HPP
#define OBJECT_STORAGE_HPP

#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

#include "domain/dom_type.hpp"
#include "domain/dom_string.hpp"
#include "domain/dom_math.hpp"
#include "domain/dom_error_message.hpp"

#include "object_types.hpp"
#include "basic_object.hpp"

namespace lgc
{
    class ObjectStorage
    {
	public:
		static ObjectStorage globalObjecStorage;

		ObjectStorage() = default;
		//TODO delete all
		virtual ~ObjectStorage() = default;

		uint_64 getTagNumber(str_const_ref aName) const;
		//TODO str_val array?
		std::set<tag_type> addObject(BasicObject* aObject, std::vector<str_val> aTags);
		void removeObject(BasicObject* aObject, std::set<tag_type> aTags);

		//TODO C++23?
		//template <typename Self>
		//auto& operator[](this Self&& self, std::size_t idx) { return self.mVector[idx]; }

		std::set<BasicObject*>& operator[](str_const_ref aTag);
		const std::set<BasicObject*>& operator[](str_const_ref aTag) const;

		std::set<BasicObject*> operator[](std::vector<str_val> aTag);

	private:
		static std::map<uint_64, tag_type> mTagDictionary;
		static std::vector<std::set<BasicObject*>> mObjects;
    };
}

#endif // !OBJECT_HEAP_HPP