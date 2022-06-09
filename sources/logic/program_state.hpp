#ifndef PROGRAM_STATE_H
#define PROGRAM_STATE_H

//--------------------------------------------------------------------------------

#include <set>
#include <optional>

#include <boost/property_tree/ptree.hpp>
#include <boost/lexical_cast/lexical_cast_old.hpp>

#include "gui/event.hpp"
#include "gui/gui.hpp"

#include "type.hpp"
#include "objects_storage.hpp"
#include "logic_object.hpp"
//#include "program_states_data.hpp"

namespace lgc
{
	class ProgramState
	{
	public:
		enum class ProgramStateName {Nun, Menu, Game};

		ProgramState();
		virtual ~ProgramState();

		//virtual bool run(std::vector<gui::Event*> aEvents) = 0;
		//virtual const SetDrawebleType* getPresentation() const = 0;
		virtual void processEvents(EventArray aEvents) = 0;
		virtual void update() = 0;
		virtual std::optional<ProgramStateName> getNextStateName() = 0;
		void timeUpdate();
		
		bool isClosed();

		void stateSetup(boost::property_tree::ptree& aSettings);

	protected:
		void close();

	private:
		bool mIsClosed;

		void layerSetup(boost::property_tree::ptree& aSettings);
		//static Time mTime;
	};
}
	
//--------------------------------------------------------------------------------

#endif // !PROGRAM_STATE_H