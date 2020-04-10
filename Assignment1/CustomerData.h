#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H

#include "PersonData.h"

class CustomerData : public PersonData
{
    private:
        int customerNumber;
        bool mailingList;
    public:
        //CONSTRUCTOR
        CustomerData(string ln, string fn, string ad,
                   string ct, string st, string zp, string ph, int cn, bool ml)
        : PersonData(ln, fn, ad, ct, st, zp,ph)
        {
            customerNumber = cn;
            mailingList = ml;
        }
        //DEFAULT CONSTRUCTOR
        CustomerData() : PersonData()
        {
        customerNumber = 0;
        mailingList = false;
        }
        //MUTATOR
        void setCustomerNumber(int inp_CN)
        {
            customerNumber = inp_CN;
        }
        void setMailingList(bool inp_ML)
        {
            mailingList = inp_ML;
        }
        //ACCESSOR
        int getCustomerNumber()
        {
            return customerNumber;
        }
        bool getMailingList()
        {
            return mailingList;
        }
};

#endif // CUSTOMERDATA_H
