#ifndef PERSONDATA_H
#define PERSONDATA_H

#include <string>
using namespace std;

class PersonData
{
    private:
        string lastName;
        string firstName;
        string address;
        string city;
        string state;
        string zip;
        string phone;

    public:
        //DEFAULT CONSTRUCTOR
        PersonData(){
            lastName = "";
            firstName = "";
            address = "";
            city = "";
            state = "";
            zip = "";
            phone = "";
        }
        //CONSTRUCTOR
        PersonData(string ln, string fn, string ad,
                   string ct, string st, string zp, string ph){
            lastName = ln;
            firstName = fn;
            address = ad;
            city = ct;
            state = st;
            zip = zp;
            phone = ph;
        }
        //MUTATOR
        void setLastName(string ln)
            { lastName = ln; }

        void setFirstName(string fn)
            { firstName = fn; }

        void setAddress(string ad)
            { address = ad; }

        void setCity(string ct)
            { city = ct; }

        void setState(string st)
            { state = st; }

        void setZip(string zp)
            { zip = zp; }
        void setPhone(string ph)
            { phone = ph; }
        //ACCESSOR
        string getLastName() const
            { return lastName; }

        string getFirstName() const
            { return firstName; }

        string getAddress() const
            { return address; }

        string getCity() const
            { return city; }

        string getState() const
            { return state; }

        string getZip() const
            { return zip; }
        string getPhone() const
            { return phone; }
};

#endif // PERSONDATA_H
