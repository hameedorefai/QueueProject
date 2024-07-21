#include <iostream>
#include "clsQueueLine.h"
using namespace std;

int main()
{
	clsQueueLine PayBillQueue("A0", 5);

	PayBillQueue.IssueTicket();
	PayBillQueue.IssueTicket();
	PayBillQueue.IssueTicket();
	PayBillQueue.IssueTicket();
	PayBillQueue.IssueTicket();

	
	cout << "\n\t\t\t\t_______Pay Bill Queue_______";
	PayBillQueue.PrintInfo();
	
	PayBillQueue.PrintTicketsRTL();
	PayBillQueue.PrintTicketsLTR();


	
	cout << "\n\t\t\t\t________Tickets List________";
	PayBillQueue.PrintTickets();
	

	PayBillQueue.ServeNextClient();

	cout << "\n\t\t\t\t________Tickets List________";
	PayBillQueue.PrintTickets();

	return 0;
}

