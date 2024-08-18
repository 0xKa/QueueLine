#pragma once
#include <iostream>
#include <queue>
#include <stack>
#include "clsDate.h";
using namespace std;

class clsQueueLine
{
private:

	short _TotalTickets = 0;
	short _AverageServeTime = 0;
	string _Prefix = "";
	
	class clsTicket
	{
	private:
		short _Number = 0;
		string _Prefix;
		string _TicketID;
		string _TicketDateAndTime;
		short _WaitingClients = 0;
		short _AverageServeTime = 0;
		short _ExpectedServeTime = 0;

	public:

		clsTicket(string Prefix, short Number, short WaitingClients, short AverageServeTime)
		{
			_Number = Number;
			_Prefix = Prefix;
			_TicketID = _Prefix + to_string(_Number);
			_WaitingClients = WaitingClients;
			_AverageServeTime = AverageServeTime;
			_ExpectedServeTime = AverageServeTime * WaitingClients;
			_TicketDateAndTime = clsDate::GetSystemDateTimeString();
		}

		string Prefix()
		{
			return _Prefix;
		}
		short Number()
		{
			return _Number;
		}
		string TicketID()
		{
			return _TicketID;
		}
		string TicketDateAndTime()
		{
			return _TicketDateAndTime;
		}
		short WaitingClients()
		{
			return _WaitingClients;
		}
		short ExpectedServeTime()
		{
			return _ExpectedServeTime;
		}

		void Print()
		{
			cout << "\n_______________________\n";

			cout << "\n          " << _TicketID;
			cout << "\n\n " << _TicketDateAndTime;
			cout << "\n Waiting Clients: " << _WaitingClients;
			cout << "\n Serve In : " << _ExpectedServeTime << " Minutes.";

			cout << "\n_______________________\n";
		}

	};

public:
	queue <clsTicket> QueueLine;

	clsQueueLine(string Prefix, short AverageServeTime)
	{
		_Prefix = Prefix;
		_AverageServeTime = AverageServeTime;
	}

	int WaitingClients()
	{
		return QueueLine.size();
	}

	void IssueTicket()
	{
		_TotalTickets++;
		clsTicket Ticket(_Prefix,_TotalTickets, WaitingClients(), _AverageServeTime);
		QueueLine.push(Ticket);
	}

	string WhoIsNext()
	{
		if (QueueLine.empty())
			return "No Clients Left.";
		else
			return QueueLine.front().TicketID();
	}

	bool ServeNextClient()
	{
		if (QueueLine.empty()) return false;
		
		QueueLine.pop();
		return true;
	}

	short ServedClients()
	{
		return _TotalTickets - WaitingClients();
	}

	void PrintInfo()
	{
		cout << "_____________________________________\n\n";
		cout << "              Queue Info\n";
		cout << "_____________________________________\n\n";
		cout << "    Prefix          : " << _Prefix << endl;
		cout << "    Total Tickets   : " << _TotalTickets<< endl;
		cout << "    Served Clients  : " << ServedClients() << endl;
		cout << "    Waiting Clients : " << WaitingClients() << endl;
		cout << "_____________________________________\n\n";
	}

	void PrintTicketsLineRTL()
	{
		if (QueueLine.empty()) {
			cout << "\nNo Tickets Available.\n"; 
			return;
		}
			
		cout << "\n\nTickets: ";

		//we copy the queue in order not to lose the original
		queue <clsTicket> temp = QueueLine;

		while (!temp.empty())
		{
			cout << temp.front().TicketID() << " <-- ";
			temp.pop();
		}
		cout << endl;
	}
	void PrintTicketsLineLTR()
	{
		if (QueueLine.empty()) {
			cout << "\nNo Tickets Available.\n";
			return;
		}

		cout << "\n\nTickets: ";
		//we will use the stack because it is the revese of a queue
		queue <clsTicket> tempQueue = QueueLine;
		stack <clsTicket> tempStack;

		while (!tempQueue.empty())
		{
			tempStack.push(tempQueue.front());
			tempQueue.pop();
		}

		while (!tempStack.empty())
		{
			cout << tempStack.top().TicketID() << " --> ";
			tempStack.pop();
		}

		cout << endl;
	}

	void PrintAllTickets()
	{
		if (QueueLine.empty())
		{
			cout << "\n---No Tickets---\n"; 
			return;
		}
		
		cout << "\n\n       ---Tickets---";
		queue <clsTicket> temp = QueueLine;

		while (!temp.empty())
		{
			temp.front().Print();
			temp.pop();
		}

	}

};

