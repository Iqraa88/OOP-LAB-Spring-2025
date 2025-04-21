#include<iostream>
using namespace std;

class Shipment{

    protected:
    string tNum;
    double weight;

    public:

    Shipment(string tNum, double weight): tNum(tNum), weight(weight){}

    virtual void estimateDeliveryTime()=0;
    virtual void showDetails()=0;
};

class AirFrieght: public Shipment{

    public:
    AirFrieght(string tNum, double weight): Shipment(tNum, weight){}

    void estimateDeliveryTime(){
    cout<<"--------------------"<<endl;
    cout<<"Estimating Delivery Time for AirFrieght having trackingNumber: "<< tNum<< " "<< endl;

    }

    void showDetails(){
        cout<<"--------------------"<<endl;
        cout<<" Tracking Number for AirFrieght: "<< tNum<< " "<< endl;
        cout<<" Weight for AirFrieght: "<< weight<< " "<< endl;
    }
};

class GroundShipment: public Shipment{
    public:
    GroundShipment(string tNum, double weight): Shipment(tNum, weight){}

    void estimateDeliveryTime(){
    cout<<"--------------------"<<endl;
    cout<<"Estimating Delivery Time for GroundShipment having trackingNumber: "<< tNum<< " "<< endl;

    }

    void showDetails(){
        cout<<"--------------------"<<endl;
        cout<<" Tracking Number for GroundShipment: "<< tNum<< " "<< endl;
        cout<<" Weight for GroundShipment: "<< weight<< " "<< endl;
    }};
int main()
{

    Shipment *temp;

    temp= new AirFrieght("2011111111111", 100);
    temp->estimateDeliveryTime();
    temp->showDetails();
    delete temp;

    temp= new GroundShipment("Z0922222222222", 50);
    temp->estimateDeliveryTime();
    temp->showDetails();
    delete temp;
    
  
 return 0;
}