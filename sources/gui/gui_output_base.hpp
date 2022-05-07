#ifndef GUI_OUTPUT_BASE_H
#define GUI_OUTPUT_BASE_H

#include "gui/window.hpp"
#include "core/domain.hpp"

#include "gui/drawable_and_writable.hpp"

namespace sr
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

		GuiOutputBase(uint_8 aLayer, Pair<float> aCoordOffset);
		virtual ~GuiOutputBase();
		void draw();

		bool operator<(const GuiOutputBase& aOther) const;

	protected:
		void setType(GuiOutputType aType);

	private:
		GuiOutputType mType;
		uint_8 mLayer;

		Pair<float> mCoordOffset;
	};
	
	struct GuiOutputBaseComparator {
		bool operator() (GuiOutputBase* a, GuiOutputBase* b) const;
	};
}

#endif // !GUI_OUTPUT_BASE_H