// Project8_QueueLine 
#include <iostream>
#include "clsQueueLine.h";
using namespace std;

int main()
{
	clsQueueLine PayBillsQueue("A0", 10);
	clsQueueLine SubscriptionsQueue("S0", 5);
	clsQueueLine VIPQueue("V0", 2);

	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();

	cout << "Pay Bills Queue Line Information: \n\n";
	PayBillsQueue.PrintInfo();
	
	cout << "Pay Bills Queue Line Information After Serving a Client: \n\n";
	PayBillsQueue.ServeNextClient();
	PayBillsQueue.PrintInfo();

	PayBillsQueue.PrintTicketsLineRTL();
	PayBillsQueue.PrintTicketsLineLTR();

	PayBillsQueue.PrintAllTickets();
	
	SubscriptionsQueue.IssueTicket();
	SubscriptionsQueue.IssueTicket();
	SubscriptionsQueue.IssueTicket();

	cout << "Subscriptions Queue Line Information: \n\n";
	SubscriptionsQueue.PrintInfo();

	SubscriptionsQueue.PrintTicketsLineRTL();
	SubscriptionsQueue.PrintTicketsLineLTR();

	SubscriptionsQueue.PrintAllTickets();
	
	VIPQueue.IssueTicket();
	VIPQueue.IssueTicket();
	VIPQueue.IssueTicket();

	cout << "VIP Queue Line Information: \n\n";
	VIPQueue.PrintInfo();

	VIPQueue.PrintTicketsLineRTL();
	VIPQueue.PrintTicketsLineLTR();

	VIPQueue.PrintAllTickets();

	system("pause>0");
	return 0;
}
