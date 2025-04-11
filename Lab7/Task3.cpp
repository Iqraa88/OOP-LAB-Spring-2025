#include<iostream>
using namespace std;

class Ticket{

    protected:
    string ticketID;
    string pName;
    double price;
    string date;
    string dest;

    public:

    Ticket(string ticketID, string pName, double price, string date, string dest ): ticketID(ticketID), pName(pName), price(price), date(date), dest(dest){}

    virtual void reserve(){

        cout<< "FLight has been reserved for " << pName<< " "<< endl;
    
    }
    virtual void cancel(){
        cout<< "Flight has been cancelled for "<< pName<< " "<< endl;
    }
    virtual void displayTicketInfo(){
        cout<<"----------------------------"<< endl;
        cout<<" TicketID: "<< ticketID<< " "<< endl;
        cout<< endl;
        cout<<" Passenger Name: "<< pName<< " "<< endl;
        cout<< endl;
        cout<<" Ticket Price: "<< price<< " "<< endl;
        cout<< endl;
        cout<<" Date of Flight: "<< date<< " "<< endl;
        cout<< endl;
        cout<<" Destination: "<< dest<< " "<< endl;
        cout<< endl;

    }


};

class FlightTicket: public Ticket{

    string airlineName;
    int flightNo;
    string seatClass;

    public:
    FlightTicket(string ticketID, string pName, double price, string date, string dest , string airlineName, int flightNo, string seatClass): Ticket(ticketID, pName, price, date, dest), airlineName(airlineName), flightNo(flightNo), seatClass(seatClass){}

    void displayTicketInfo()override{
        Ticket::displayTicketInfo();
        cout<< "AirLine: "<< airlineName<< " "<< endl;
        cout<< endl;
        cout<< "Flight#: "<< flightNo<< " "<< endl;
        cout<< endl;
        cout<< "Seat-Class: "<< seatClass<< " "<< endl;
        cout<< endl;

    }

};

class TrainTicket: public Ticket{

    int trainNo;
    string coachType;
    string departureTime;

    public:
    TrainTicket(string ticketID, string pName, double price, string date, string dest , int trainNo, string coachType, string departureTime): Ticket(ticketID, pName, price, date, dest), trainNo(trainNo), coachType(coachType), departureTime(departureTime){}

    void reserve()override{
        int seatNo= rand()% 150+1;
        cout<< "Seat# "<< seatNo<< " has been assigned! " << endl;
        Ticket::reserve();
    }



};

class BusTicket: public Ticket{

    string busCompany;
    int seatNo;

    public:

    BusTicket(string ticketID, string pName, double price, string date, string dest, string busCompany, int seatNo): Ticket(ticketID, pName, price, date, dest), busCompany(busCompany), seatNo(seatNo){}

    void cancel()override{
        Ticket::cancel();
        cout<<"---------------------"<< endl;
        cout<< " "<< price<< " PKR is being refunded..."<< endl;
        cout<< "Refund Successful!"<< endl;
    }

};
class ConcertTicket: public Ticket{

    string artistName;
    string venue;
    string seatType;

    public:

    ConcertTicket(string ticketID, string pName, double price, string date, string dest, string artistName, string venue, string seatType): Ticket(ticketID, pName, price, date, dest), artistName(artistName), venue(venue), seatType(seatType){}

    void displayTicketInfo()override{
        Ticket::displayTicketInfo();

        cout<< "Artist Name: "<< artistName<< " "<< endl;
        cout<< endl;
        cout<< "Venue: "<< venue<< " "<< endl;
        cout<< endl;
        cout<< "Seat Type: "<< seatType<< " "<< endl;
        cout<< endl;

    }

};



int main()
{

    Ticket *ptr;
    FlightTicket flight("A07", "Amna", 25000, "07-05-2025", "Quetta", "Jinnah Airlines", 4, "VIP");
    ptr= &flight;
    ptr->displayTicketInfo();
    TrainTicket train("B65", "Jaweria", 7000, "22-05-2025", "Islamabad", 2, "Economy Class", "8PM");
    ptr= &train;
    ptr->reserve();
    BusTicket bus("6F2", "Tayyaba", 10000, "09-09-2025", "Peshawar", "SadaBahar Travels", 44);
    ptr= &bus;
    ptr->cancel();
    ConcertTicket concert("HAVI99", "Noor", 2000, "17-05-2025", "Karachi", "HAVI", "Fast-NUCES", "VIP");
    ptr= &concert;
    ptr->displayTicketInfo();
  
 return 0;
}