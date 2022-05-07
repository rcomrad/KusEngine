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
		enum GuiOutputType
		{
			NUN = 0,
			SPRITE = 1,
			TEXT = 2,
			SPRITE_AND_TEXT = 3
		};

		GuiOutputBase(GuiOutputType aType, uint_8 aLayer);
		virtual ~GuiOutputBase();
		void draw();

		bool operator<(const GuiOutputBase& aOther) const;

	private:
		GuiOutputType mType;
		uint_8 mLayer;
	};

	//struct GuiOutputBaseComparator {
	//	bool operator() (void* a, void* b) const;
	//};

	struct GuiOutputBaseComparator {
		bool operator() (GuiOutputBase* a, GuiOutputBase* b) const;
	};
}

#endif // !GUI_OUTPUT_BASE_H