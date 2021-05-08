// Name: Yongtak Jun
// Seneca Student ID: 137350195
// Seneca email: yjun4@myseneca.ca
// Date of completion: Apr/09/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "LineManager.h"

namespace sdds
{
	LineManager::LineManager() {};

	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
	{
		if (file.empty())
			throw string("ERROR: No filename provided.");
		
		ifstream f(file);
		if (!f)
			throw string("Unable to open [") + file + "] file.";

		Utilities myUtil;

		string record{};
		string CurrentStation{};
		string NextStation{};
		size_t next_pos{};
		bool more;

		std::for_each(stations.begin(), stations.end(), [](Workstation* theStation) {theStation->setNextStation(); });

		//configure the assembly line
		while (!f.eof())
		{
			std::getline(f, record);

			next_pos = 0;

			CurrentStation = myUtil.extractToken(record, next_pos, more);

			auto currentStation = find_if(stations.begin(), stations.end(),
				[&](const Workstation* theStation)
				{
					return theStation->getItemName() == CurrentStation;
				}
			);

			if (currentStation == stations.end())
				throw string("ERROR: Current Station name not found  [" + CurrentStation + "] \n");

			activeLine.push_back(*currentStation);


			if (more) //if there is a next Workstation
			{
				NextStation = myUtil.extractToken(record, next_pos, more);

				auto nextStation = find_if(stations.begin(), stations.end(),
					[&](const Workstation* theStation)
					{
						return theStation->getItemName() == NextStation;
					}
				);


				if(nextStation == stations.end())
					throw string("ERROR: Next Station name not found  [" + NextStation + "] \n");

				if (nextStation == currentStation)
					throw string("ERROR: Next Station [" + NextStation + "] is the current station [" + CurrentStation + "] \n");

				(*currentStation)->setNextStation(*nextStation);
			}
		}
		f.close();


		//identify the first station in the assembly line and stores its address in the m_firstStation attribute.
		std::for_each(activeLine.begin(), activeLine.end(),
			[&](Workstation* theStation1)
			{
				bool isFirst = true;

				std::for_each(activeLine.begin(), activeLine.end(),
					[&](Workstation* theStation2)
					{
						if (theStation1 == theStation2->getNextStation())
							isFirst = false;
					}
				);

				if (isFirst)
				{
					if (m_firstStation)
						throw string("ERROR: First station is ambiguous\n");
					else
						m_firstStation = theStation1;
				}
					
			}
		);

		if (!m_firstStation)
			throw string("ERROR: First station is not found\n");


		//remember the number of orders to be filled
		m_cntCustomerOrder = pending.size();

	}

	void LineManager::linkStations()
	{
		std::vector<Workstation*> orderedActiveLine{};

		auto iter = m_firstStation;

		while (iter)
		{
			orderedActiveLine.push_back(iter);
			iter = iter->getNextStation();
		}

		activeLine = orderedActiveLine;
	}

	bool LineManager::run(std::ostream& os)
	{
		static int numberOfCall = 0;
		++numberOfCall;

		os << "Line Manager Iteration: " << numberOfCall << endl;

		//if the pending queue has a CustomerOrder object, moves the order at the front of the queue to the m_firstStation
		if (!pending.empty())
		{
			//*m_firstStation += move(pending[0]);
			*m_firstStation += move(pending.front());

			pending.pop_front(); //a deque object has member function, pop_front()
		}

		//for each station on the line, executes one fill operation
		for (auto &e : activeLine)
			e->fill(os);


		//for each station on the line, attempts to move a CustomerOrder down the line
		for (auto& e : activeLine)
			e->attemptToMoveOrder();


		//return true if all customer orders (m_cntCustomerOrder) have been filled, otherwise returns false.
		return m_cntCustomerOrder == completed.size();
	}

	void LineManager::display(std::ostream& os) const
	{
		for (const auto& e : activeLine)
			e->display(os);
	}
}
