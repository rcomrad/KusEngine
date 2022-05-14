#ifndef GUI_OUTPUT_BASE_H
#define GUI_OUTPUT_BASE_H

#include "domain/dom_type.hpp"
#include "domain/dom_pair.hpp"
#include "domain/dom_string.hpp"

namespace gui
{
	class GuiOutputBase
	{
	public:
		enum class GuiObjectType
		{
			NUN = 0,
			SPRITE = 1,
			TEXT = 2,
			SPRITE_AND_TEXT = 3
		};

		GuiOutputBase();
		virtual ~GuiOutputBase();

		void draw();

		void move			(dom::Pair<float> aCoord);
		void resetPosition	(dom::Pair<float> aCoord);
		void setScale		(dom::Pair<float> aCoord);

		void centrateViewOnObject(str_const_ref aViewName = "");

		bool operator<(const GuiOutputBase& aOther) const;

	protected:
		void setType	(GuiObjectType aType);
		void setLayer	(str_const_ref aLayerName);
		void setTag		(str_const_ref aTagName);
		void setView	(str_const_ref aViewName);

	private:
		GuiObjectType	mType;
		uint_8			mLayer;
		uint_8			mViewNumber;

		static std::map<std::string, uint_16> globalLayerNumbers;
		static std::map<std::string, uint_16> globalTagNumbers;
	};
	
	struct GuiOutputBaseComparator {
		bool operator() (GuiOutputBase* a, GuiOutputBase* b) const;
	};
}

#endif // !GUI_OUTPUT_BASE_H