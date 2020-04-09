#include <iostream>
#include <iomanip>
using namespace std;

class Car{
    private:
            int yearModel;
            string make;
            int speed;
    public:
        //Constructor
        Car(int y,string m){
            yearModel = y;
            make = m;
            speed = 0;
        }
        //Getter
        int getYearModel(){
            return yearModel;
        }
        string getMake(){
            return make;
        }
        int getSpeed(){
            return speed;
        }
        int accelerate(){
            return speed+=5;
        }
        int brake(){
            return speed-=5;
        }
};

int main()
{
    int yearModel;
    string make;
    cout << "Enter the car's making year: ";
    cin >> yearModel;
    cout << "Enter the car's model: ";
    cin >> make;
    Car car1(yearModel,make);
    cout << endl;
    cout << "The car " << car1.getMake() <<" "
         << car1.getYearModel() << " is on: " << endl;
    cout << endl;
    cout << "Acceleration: " << endl;
    for (int i = 0; i < 5 ; i++){
        car1.accelerate();
        cout << setw(4) << car1.getSpeed() << " km/h" << endl;
    }
    cout << "Braking: " << endl;
    for (int i = 0; i < 5; i++){
        car1.brake();
        cout << setw(4) << car1.getSpeed() << " km/h" << endl;
    }
    return 0;
}
