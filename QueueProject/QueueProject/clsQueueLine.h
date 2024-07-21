#pragma once
#include <iostream>
#include <queue>
#include "clsTicket.h"
#include <string>
#include <iomanip>
#include <stack>

using namespace std;

class clsQueueLine
{

private:

	string _Prefix = "";
	int _TotalTickets = 0;

	int _ServeTime = 0;



	queue < clsTicket> _queTickets;



public:



	clsQueueLine(string Prefix, int ServeTime)
	{
		_Prefix = Prefix;
		_ServeTime = ServeTime;
	}

	void IssueTicket()
	{
		clsTicket _Ticket(_Prefix, _queTickets.size(), _ServeTime);
		_queTickets.push(_Ticket);
		_TotalTickets++;
		//_WaitingClients = _queTickets.size();

	}

	void ServeNextClient()
	{
		if (!_queTickets.empty())
		{
			_queTickets.pop();
			//_WaitingClients = _queTickets.size();
			//_ServedClients = _TotalTickets - _WaitingClients;
		}
	}


	short WaitingClients()
	{
		return _queTickets.size();
	}

	short ServedClients()
	{
		return (_TotalTickets - WaitingClients());
	}

	void PrintInfo()
	{
		cout << "\n\t\t\t\t____________________________";
		cout << "\n\t\t\t\t    Prefix          = " << _Prefix;
		cout << "\n\t\t\t\t    Total Tickets   = " << _TotalTickets;
		cout << "\n\t\t\t\t    Served Clients  = " << ServedClients();
		cout << "\n\t\t\t\t    Waiting Clients = " << WaitingClients();
		cout << "\n\t\t\t\t____________________________\n\n";
	}

	void PrintTickets()
	{
		queue < clsTicket> TempqueTickets = _queTickets;
		while (!_queTickets.empty())
		{

			_queTickets.front().Print();
			_queTickets.pop();

		}
		_queTickets = TempqueTickets;
	}

	void PrintTicketsRTL()
	{
		
		queue < clsTicket> TempqueTickets = _queTickets;
			cout << "\n\t\t\tTickets : ";
		while (!_queTickets.empty())
		{

			cout << _queTickets.front().Name() << " <-- ";
			_queTickets.pop();

		}
		cout << "\n";
		_queTickets = TempqueTickets;
	}

	void PrintTicketsLTR()
	{
		queue < clsTicket> TempqueTickets = _queTickets;
		stack <string> Names;
		cout << "\n\t\t\tTickets : ";
		while (!_queTickets.empty())
		{

			Names.push(_queTickets.front().Name());
			_queTickets.pop();

		}
		while (!Names.empty())
		{

			cout << Names.top() << " --> ";
			Names.pop();

		}





		cout << "\n";
		_queTickets = TempqueTickets;
	}

	
};




