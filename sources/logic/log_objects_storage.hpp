#ifndef OBJECT_STORAGE_HPP
#define OBJECT_STORAGE_HPP

#include <map>
#include <vector>
#include <set>
#include <algorithm>

#include "domain/dom_type.hpp"
#include "domain/dom_string.hpp"
#include "domain/dom_math.hpp"

#include "log_types.hpp"
#include "logic_object.hpp"

namespace lgc
{
    class ObjecStorage
    {
	public:
		static ObjecStorage globalObjecStorage;

		ObjecStorage() = default;
		//TODO delete all
		virtual ~ObjecStorage() = default;

		tag_type getTagNumber(str_const_ref aName) const;
		//TODO str_val array?
		std::vector<tag_type> addObject(LogicObject* aObject, std::vector<str_val> aTags);
		void removeObject(LogicObject* aObject, std::vector<tag_type> aTags);

		//TODO C++23?
		//template <typename Self>
		//auto& operator[](this Self&& self, std::size_t idx) { return self.mVector[idx]; }

		std::set<LogicObject*>& operator[](str_const_ref aTag);
		const std::set<LogicObject*>& operator[](str_const_ref aTag) const;

		std::set<LogicObject*> operator[](std::vector<str_const_ref> aTag);

	private:
		static std::map<str_val, tag_type> mTagDictionary;
		static std::vector<std::set<LogicObject*>> mObjects;
    }
}

#endif // !OBJECT_HEAP_HPP