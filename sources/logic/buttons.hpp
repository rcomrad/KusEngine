#ifndef BUTTONS_HPP
#define BUTTONS_HPP

//--------------------------------------------------------------------------------

#include "domain/dom_string.hpp"
#include "domain/dom_pair.hpp"

#include "gui/gui_mouse_event.hpp"
#include "gui/gui_drawable_and_writable.hpp"

#include "program_state.hpp"
#include "objects_storage.hpp"
#include "logic_object.hpp"

namespace lgc
{
	class Buttons : public LogicObject, public gui::DrawableAndWritable
	{
	public:
		Buttons
		(
			str_const_ref aTexturePath, 
			std::vector<str_val> aButtonsNames,
			dom::Pair<float> aStartPosition,
			dom::Pair<float> mPositionChange = {0, 0}
		);
		virtual ~Buttons() = default;

		void setButtonNames(const std::vector<str_val>& aButtonsNames);
		void setStartPosition(dom::Pair<float> aStartPosition);
		void setButtonSize(dom::Pair<float> aButtonSize);
		void setPositionChange(dom::Pair<float> aPositionChange);
            
		virtual void draw();

		std::optional<uint_16> processEvent(gui::Event* aEvent) override;
		virtual void update(float adTime);

	private:
		std::vector<str_val> mButtonNames;
		dom::Pair<float> mStartPosition;
		dom::Pair<float> mButtonSize;
		dom::Pair<float> mPositionChange;
	};
}

//--------------------------------------------------------------------------------

#endif // !BUTTON_HPP