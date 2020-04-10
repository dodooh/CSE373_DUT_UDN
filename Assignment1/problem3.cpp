/***************************************
        Problem 3: CIRCLE CLASS
    @NGUYEN_TRAN_THANH_NGHIA-15ECE2
****************************************/
#include <iostream>
using namespace std;

class Circle{
    private:
        double radius;
        const double PI = 3.14159;
    public:
        //Constructor
        Circle(){
            radius = 0.0;
        }
        Circle(double inp_radius){
            radius = inp_radius;
        }
        //Accesstor
        double getRadius(){
            return radius;
        }
        //Mutator
        void setRadius(double inp_radius){
            radius = inp_radius;
        }
        double getArea(){
            return radius*PI;
        }
        double getDiameter(){
            return radius*2;
        }
        double getCircumference(){
            return 2*PI*radius;
        }
};

int main(){
    double radius;
    cout <<"Enter the radius: ";
    cin >> radius;
    Circle obj(radius);
    cout <<"The circle's area is: "<<obj.getArea()<<endl;
    cout <<"The diameter is: "<<obj.getDiameter()<<endl;
    cout <<"The radius is: "<<obj.getCircumference()<<endl;
    return 0;
}
