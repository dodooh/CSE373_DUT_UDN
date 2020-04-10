/***************************************
    Problem 4: FREEZING & BOILING POINT
    @NGUYEN_TRAN_THANH_NGHIA-15ECE2
****************************************/
#include <iostream>
using namespace std;

class Temperature{
    private:
        int temper;
    public:
        const int ETHYL_FP = -173, ETHYL_BP = 173,
                  OXYGEN_FP = -362, OXYGEN_BP = -306,
                  WATER_FP = 0, WATER_BP = 100;
        Temperature(){
            temper = -9999;}
        Temperature(int inp_temper){
            temper = inp_temper;
        }
        bool isEthylFreezing(){
            return (temper <= ETHYL_FP);
        }
        bool isEthylBoiling(){
            return (temper >= ETHYL_BP);
        }
        bool isOxygenFreezing(){
            return (temper <= OXYGEN_FP);
        }
        bool isOxygenBoiling(){
            return (temper >= OXYGEN_BP);
        }
        bool isWaterFreezing(){
            return (temper <= WATER_FP);
        }
        bool isWaterBoiling(){
            return (temper >= WATER_BP);
        }
};

int main()
{
    int temper;
    cout <<"Enter the temperature: ";
    cin >> temper;
    Temperature obj(temper);
    if (obj.isEthylFreezing())
        cout<<"Ethyl is Freezing \n" ;
    if (obj.isEthylBoiling())
        cout<<"Ethyl is Boiling \n" ;
    if (obj.isOxygenFreezing())
        cout<<"Oxygen is Freezing \n";
    if (obj.isOxygenBoiling())
        cout<<"Oxygen is Boiling \n";
    if (obj.isWaterFreezing())
        cout<<"Water is Freezing \n";
    if (obj.isWaterBoiling())
        cout<<"Water is Boiling \n";
    return 0;
}
