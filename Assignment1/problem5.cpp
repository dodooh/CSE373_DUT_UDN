/***************************************
        Problem 5: MONTH CLASS
    @NGUYEN_TRAN_THANH_NGHIA-15ECE2
****************************************/
#include <iostream>

using namespace std;

class Month{
    private:
        string monthName;
        int monthNumber;
    public:
        const string FULLNAME_OF_MONTH[12] = {"January","February","March","April",
                                    "May","June","July","August",
                                    "September","October","November","December"};
        //CONSTRUCTOR
        Month()
        {
            monthName = "January";
            monthNumber = 1;
        }
        Month(string inp_name)
        {
            monthName = inp_name;
            setMonthNumber(inp_name);
        }
        Month(int inp_monthNumber)
        {
            setMonthName(inp_monthNumber);
            monthNumber = inp_monthNumber;
        }
        friend ostream & operator << (ostream &out, const Month &obj);
        friend istream & operator >> (istream &in, Month &obj);
        //GETTER
        string getMonthName()
        {
            return monthName;
        }
        int getMonthNumber()
        {
            return monthNumber;
        }
        void setMonthNumber(string );
        void setMonthName(int );
        Month operator++();
        Month operator++(int);
        Month operator--();
        Month operator--(int);
};
        //SETTER
        //Set month number by month name
        void Month::setMonthNumber(string inp_name)
        {
            monthName = inp_name;
            bool isValid = false;
            for (int i = 0; i < 12; i++)
                if (inp_name == FULLNAME_OF_MONTH[i])
                {
                    monthNumber = i+1;
                    isValid = true;
                    break;
                }
            if (!isValid)
            {
                monthNumber = 1; //INVALID INPUT RETURN JANUARY AND NUMBER 1
                monthName = FULLNAME_OF_MONTH[0];
            }

        }
        //Set month name by month number
        void Month::setMonthName(int inp_monthNumber)
        {
            if (inp_monthNumber<1 || inp_monthNumber>12)
            {
                monthName = FULLNAME_OF_MONTH[0];
                monthNumber = 1;
            }
            else
            {
                monthName = FULLNAME_OF_MONTH[inp_monthNumber-1]; //INVALID INPUT WILL RETURN JANUARY AND NUMBER 1
                monthNumber = inp_monthNumber;
            }

        }
        //OVERLOAD OUTPUT OPERATOR
        ostream & operator << (ostream &out, const Month &obj)
        {
            return out << obj.monthName << " (" <<obj.monthNumber<<")"<<endl;
        }
        //OVERLOAD INPUT OPERATOR
        istream & operator >> (istream &in, Month &obj)
        {
            string mName;
            cout << "\nEnter the month name: ";
            in >> mName;
            obj.setMonthNumber(mName);
            return in;
        }
        //PREFIX AND POSTFIX ++ OPERATOR
        Month Month::operator++()
        {
            if (monthNumber == 12) monthNumber = 1;
            else ++monthNumber;
            setMonthName(monthNumber);
            return *this;
        }

        Month Month::operator++(int)
        {
            Month temp(monthNumber);
            setMonthName(++monthNumber);
            //if (monthNumber == 12) monthNumber = 1;
            return temp;
        }
        //PREFIX AND POSTFIX -- OPERATOR
        Month Month::operator--()
        {
            if (monthNumber == 1) monthNumber = 12;
            else --monthNumber;
            setMonthName(monthNumber);
            return *this;
        }

        Month Month::operator--(int)
        {
            Month temp(monthNumber);
            setMonthName(--monthNumber);
            //if (monthNumber == 1) monthNumber = 12;
            return temp;
        }



int main()
{
    //testing constructors
    Month monthTest;
    Month month12(12);
    Month month8("August");
    string newName  = "May";
    int newNum = 4;

    //testing getters and setters
    cout << "\n---------------------------------------------" << endl;
    cout << "Testing Constructors, Mutator & Accessor" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "monthTest.getMonthName() returns:  " <<  monthTest.getMonthName() << endl;
    cout << "monthTest.getMonthNumber() returns:  " << monthTest.getMonthNumber() << endl;
    cout << "monthTest.getMonthName() returns:  " <<  month12.getMonthName() << endl;
    cout << "month12.getMonthNumber() returns:  " << month12.getMonthNumber() << endl;
    cout << "month8.getMonthName() returns:  " <<  month8.getMonthName() << endl;
    cout << "month8.getMonthNumber() returns:  " << month8.getMonthNumber() << endl;

    cout << endl << "Setting number to " << newNum  << endl;
    monthTest.setMonthName(newNum);
    cout << "Now monthTest.getMonthName() returns:  " << monthTest.getMonthName() << endl;
    cout << "And monthTest.getMonthNumber() returns:  " << monthTest.getMonthNumber() << endl;

    cout << endl << "Setting number to 13 (invalid) " <<  endl;
    monthTest.setMonthName(13);
    cout << "Now monthTest.getMonthName() returns:  " << monthTest.getMonthName() << endl;
    cout << "And monthTest.getMonthNumber() returns:  " << monthTest.getMonthNumber() << endl;

    cout << endl <<  "Setting name to " << newName << endl;
    monthTest.setMonthNumber(newName);
    cout << "Now monthTest.getMonthName() returns:  " << monthTest.getMonthName() << endl;
    cout << "And monthTest.getMonthNumber() returns:  " << monthTest.getMonthNumber() << endl;

    cout << endl << "Setting name to ABC (invalid) "<< endl;
    monthTest.setMonthNumber("ABC");
    cout << "Now monthTest.getMonthName() returns:  " << monthTest.getMonthName() << endl;
    cout << "And monthTest.getMonthNumber() returns:  " << monthTest.getMonthNumber() << endl;

    //testing cin, cout, increments and decrements
    cout << "\n---------------------------------------------" << endl;
    cout << "Testing cin, cout, increments and decrements" << endl;
    cout << "---------------------------------------------" << endl;

    cout << "month12 is " << month12<< endl;
    cout << "month12++ returns "<< month12++ << endl;
    cout << "But month12 is now " << month12 << endl;
    cout << "++month12 returns "<< ++month12 << endl;

    cout << "month12--  returns "<< month12-- << endl;
    cout << "But month12 is now " << month12 << endl;
    cout << "--month12 returns "<< --month12 << endl;

    Month inputMonth;
    cin >> inputMonth;
    cout << "inputMonth is set to "<< inputMonth << endl;

    cout << "Press Enter to quit." << endl;
    cin.ignore();
    cin.get();

    return 0;
}
