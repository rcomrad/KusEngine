#ifndef GUI_OUTPUT_BASE_H
#define GUI_OUTPUT_BASE_H

#include "domain/dom_type.hpp"
#include "domain/dom_pair.hpp"

namespace gui
{
	class GuiOutputBase
	{
	public:
		enum class GuiOutputType
		{
			NUN = 0,
			SPRITE = 1,
			TEXT = 2,
			SPRITE_AND_TEXT = 3
		};

		GuiOutputBase(uint_8 aLayer);
		virtual ~GuiOutputBase();
		void draw();

		void move(dom::Pair<float> aCoord);
		void resetPosition(dom::Pair<float> aCoord);
		void setScale(dom::Pair<float> aCoord);

		bool operator<(const GuiOutputBase& aOther) const;

	protected:
		void setType(GuiOutputType aType);

	private:
		GuiOutputType mType;
		uint_8 mLayer;
	};
	
	struct GuiOutputBaseComparator {
		bool operator() (GuiOutputBase* a, GuiOutputBase* b) const;
	};
}

#endif // !GUI_OUTPUT_BASE_H