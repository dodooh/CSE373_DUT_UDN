#include <iostream>
#include<iomanip>
using namespace std;

class Employee{
    private:
            string name;
            int idNumber;
            string department;
            string position;
    public:
        // Constructor
            Employee(string inp_name, int inp_idNumber, string inp_department, string inp_position){
                name = inp_name;
                idNumber = inp_idNumber;
                department = inp_department;
                position = inp_position;
            }
            Employee(string inp_name, int inp_idNumber){
                name = inp_name;
                idNumber = inp_idNumber;
                department = "";
                position = "";
            }
            Employee(){
                name = "";
                idNumber = 0;
                department = "";
                position = "";
            }
        //Accessor

        //Mutator
            string getName() const{
                return name;
            }
            int getIdNumber() const{
                return idNumber;
            }
            string getDepartment() const{
                return department;
            }
            string getPosition() const{
                return position;
            }
};

int main(){
    Employee employees[3] ={
		Employee("Susan Meyers", 47899, "Accounting", "Vice President"),
		Employee("Mark Jones", 39119, "IT", "Programmer"),
		Employee("Joy Rogers", 81774, "Manufacturing", "Engineer")};
    cout <<"           NAME	  ID NUMBER     DEPARTMENT	POSITION\n";
    for (int i = 0; i < 3; i++){
        cout << setw(15) << employees[i].getName();
        cout << setw(10)<< employees[i].getIdNumber();
        cout << setw(15)<< employees[i].getDepartment();
        cout << setw(18) << employees[i].getPosition() << endl;
    }
    return 0;
}
