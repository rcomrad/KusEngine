#ifndef OBJECT_STORAGE_HPP
#define OBJECT_STORAGE_HPP

#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <memory>
#include <optional>

#include "domain/dom_type.hpp"
#include "domain/dom_string.hpp"
#include "domain/dom_math.hpp"
#include "domain/dom_error_message.hpp"

#include "gui/gui_output_base.hpp"

#include "object_types.hpp"
#include "basic_object.hpp"

namespace lgc
{
    class ObjectStorage
    {
	public:

		static ObjectStorage globalObjecStorage;

		uint_64 getTagNumber(str_const_ref aName) const;
		//TODO str_val array?
		std::set<tag_type> addObject(std::shared_ptr<BasicObject> aObject, std::vector<str_val> aTags);
		void removeObject(std::shared_ptr<BasicObject> aObject, std::set<tag_type> aTags);
		void clear();

		//TODO C++23?
		//template <typename Self>
		//auto& operator[](this Self&& self, std::size_t idx) { return self.mVector[idx]; }

		std::optional<std::set<std::shared_ptr<BasicObject>>&> operator[](str_const_ref aTag);
		const std::optional<std::set<std::shared_ptr<lgc::BasicObject>>&> operator[](str_const_ref aTag) const;

		std::set<std::shared_ptr<BasicObject>> operator[](std::vector<str_val> aTag);

		const gui::DraweblesSet& getSortedDrawables() const;

	private:
		ObjectStorage();
		~ObjectStorage() = default;

    	#ifdef _DBG_
		std::map<str_val, uint_64> mStringDictionary;
	    #endif
		std::map<uint_64, tag_type> mTagDictionary;
		std::vector<std::shared_ptr<std::set<std::shared_ptr<BasicObject>>>> mObjects;

		gui::DraweblesSet mDrawables;

		tag_type prepareStorage(str_const_ref aStr);
    };
}

#endif // !OBJECT_HEAP_HPP