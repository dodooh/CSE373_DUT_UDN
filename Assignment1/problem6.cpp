/***************************************
        Problem 6: PERSONDATA &
            CUSTOMERDATA CLASSES
    @NGUYEN_TRAN_THANH_NGHIA-15ECE2
****************************************/
#include <iostream>
#include "PersonData.h"
#include "CustomerData.h"

using namespace std;

void display(CustomerData c)
{
   cout << "Last Name: " << c.getLastName() << endl
        << "First Name: " << c.getFirstName() << endl
        << "Address: " << c.getAddress() << endl
        << "City: " << c.getCity() << endl
        << "State: " << c.getState() << endl
        << "ZIP: " << c.getZip() << endl
        << "Phone Number: " << c.getPhone() << endl
        << "Customer Number: "
        << c.getCustomerNumber() << endl
        << "Mailing List? " << ((c.getMailingList()) ? "Yes\n\n" : "No\n\n");
}

int main()
{
    //Using default constructor
    CustomerData c1;
    display(c1);
    //Using mutator and accessor
    c1.setLastName("Rose");
    c1.setFirstName("Jacksmith");
    c1.setAddress("112 Boulervrd");
    c1.setCity("San Francisco");
    c1.setState("NY");
    c1.setZip("65665");
    c1.setPhone("897 980 7869");
    c1.setCustomerNumber(12345);
    c1.setMailingList(false);
    display(c1);
    //Using constructor
    CustomerData c2("Jade","Stansmith","011 First","SantaAnna","LA","100100","982 413 5555",34334,true);
    display(c2);

    return 0;
}
