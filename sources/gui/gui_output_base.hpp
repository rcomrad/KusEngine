#ifndef GUI_OUTPUT_BASE_H
#define GUI_OUTPUT_BASE_H

#include <vector>

#include "domain/dom_type.hpp"
#include "domain/dom_pair.hpp"
#include "domain/dom_string.hpp"
#include "domain/dom_error_message.hpp"

#include "gui_types.hpp"

namespace gui
{
	class GuiOutputBase
	{
		struct PositionUnion;

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

		PositionUnion getPosition();

		void centrateViewOnObject(str_const_ref aViewName = "");

		bool operator<(const GuiOutputBase& aOther) const;

		static void addLayer(const dom::Pair<str_val, layer_type>& aLayer);
		static void addLayer(const std::vector<dom::Pair<str_val, layer_type>>& aLayerArray);

	protected:
		void setType	(GuiObjectType aType);
		void setLayer	(str_const_ref aLayerName);
		// void setTag		(str_const_ref aTagName);
		void setView	(str_const_ref aViewName);

	private:
		GuiObjectType	mType;
		layer_type			mLayer;
		// uint_8			mTag;
		view_type			mViewNumber;

		static std::map<str_val, layer_type> globalLayerNumbers;
		// static std::map<str_val, uint_16> globalTagNumbers;

		struct PositionUnion
		{
			sf_2f_val sfmlPos;
			// dom::Pair<float> domPos;

			// PositionUnion(sf_2f_val aSfmlPos);
			// PositionUnion(dom::Pair<float> aDomPos);

			operator sf_2f_val();
			operator dom::Pair<float>();
		};	

		static void addComponentToDictionary
		(
			std::map<str_val, layer_type>& aDictionary,
			const std::vector<dom::Pair<str_val, layer_type>>& aComponentArray
		);

		static layer_type getComponentNumber
		(
			const std::map<str_val, layer_type>& aDictionary,
			str_const_ref aComponentName
		);
	};
	
	struct GuiOutputBaseComparator {
		bool operator() (GuiOutputBase* a, GuiOutputBase* b) const;
	};
}

#endif // !GUI_OUTPUT_BASE_H