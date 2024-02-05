//  main.cpp
//
//  Created by Filiz İpek Oktay on 28.03.2023.
//

#include <iostream>
using namespace std;

// Inputcheck
bool inputCheck(int int_value, string ser_type) {
    return (int_value >= 0);
}
// Taking Input
bool getInputs(string type_ph, int &min, int &sms, int &mb, int &call_pack, int &sms_pack, int &int_pack) {
    cout << "Please enter how many minutes you used this month " << type_ph << ": " ;
    cin >> min;
    if (!inputCheck( min, "minutes")) {
        cout << "Number of minutes cannot be smaller than 0." ;
        return 0;
    } else {
        cout << "Please enter how many SMSs you sent this month " << type_ph << ": ";
        cin >> sms;
    }
    if (!inputCheck(sms, "SMSs")) {
        cout << "Number of SMSs cannot be smaller than 0." ;
        return 0;
    } else {
        cout << "Please enter how many MBs you used this month " << type_ph << ": " ;
        cin >> mb;
    }
    if (!inputCheck( mb, "MBs")) {
        cout << "Number of MBs cannot be smaller than 0." ;
        return 0;
    } else {
        cout << "Please specify how many additional packages you bought for calls, SMS and internet in this order: " ;
        cin >> call_pack >> sms_pack >> int_pack; // input check
        if (!inputCheck( call_pack, "callpack")) {
            cout << "Number of additional minutes packages cannot be smaller than 0." ;
            return 0;
        }
        //cin >> sms_pack;
        if (!inputCheck( sms_pack, "smspack")) {
            cout << "Number of additional SMSs packages cannot be smaller than 0." ;
            return 0;
        }
        //cin >> int_pack;
        if (!inputCheck( int_pack, "intpack")) {
            cout << "Number of additional internet packages cannot be smaller than 0." ;
            return 0;
        } else {
            return true;
        }
    }
}

// Cost Calculation
double costCalculate (int min, int sms, int mb, int call_pack, int sms_pack, int int_pack, int price, int min_no, int sms_no, int mb_no, int addprice_pack, int add_min_no, int add_sms_no, int add_mb_no, int call_rate, int sms_rate, int int_rate) {
    int total_min = 0, total_sms = 0, total_mb = 0;
    double cost = 0;
    mb = mb * 1024;
    if ((min <= min_no) && (sms <= sms_no) && (mb <= mb_no)) { // not exceeding
        cost = price;
        return cost;
    } else {
        total_min = min_no + call_pack * add_min_no;
        total_sms = sms_no + sms_pack * add_sms_no;
        total_mb = (mb_no + (int_pack * add_mb_no)) * (1024 * 1024);
    } if (min < total_min) {
        total_min = min;
    } if (sms < total_sms) {
        total_sms = sms;
    } if (mb < total_mb) {
        total_mb = mb;
    }
    cost = price + addprice_pack * (call_pack + sms_pack + int_pack) + (min - total_min) * call_rate + (sms - total_sms) * sms_rate + ((mb - total_mb)/100) * int_rate;
    return cost;
}


// Displaying Results
void displayResults (int price , string type_ph , double cost) {
    cout << "Total cost of your phone usage "<< type_ph << " is " << cost << " TL. ";
    if (cost == price) {
        cout << "You did not exceed your package." << endl;
    } else if (( cost < (price * 2)) && (cost > price)) {
        cout << "You exceeded your package." << endl;
    } else if (cost >= (price * 2)) {
        cout << "You exceeded your package too much. We suggest you to change your package." << endl;
    }
}

int main() {
    int min = 0, sms = 0, mb = 0, call_pack = 0, sms_pack = 0, int_pack = 0, imin = 0, isms = 0, imb = 0, icall_pack = 0, isms_pack = 0, iint_pack = 0;

    //Local Bill
    if(getInputs ("in Turkey", min, sms, mb, call_pack, sms_pack, int_pack)){
        costCalculate ( min,  sms,  mb,  call_pack,  sms_pack,  int_pack,  120,  250,  1000,  5,  30,  250,  250,  1,  2,  1,  2);
        displayResults (120 , "in Turkey" , costCalculate ( min,  sms,  mb,  call_pack,  sms_pack,  int_pack,  120,  250,  1000,  5,  30,  250,  250,  1,  2,  1,  2));

        //International Bill
        if (getInputs ("Internationally", imin, isms, imb, icall_pack, isms_pack, iint_pack)) {
            costCalculate ( imin,  isms,  imb,  icall_pack, isms_pack,  iint_pack,  300,  100,  200,  2,  100,  50,  100,  1,  15,  3,  5);
            displayResults (300 , "Internationally", costCalculate( imin,  isms,  imb,  icall_pack,  isms_pack,  iint_pack,  300,  100,  200,  2,  100,  50,  100,  1,  15,  3,  5));
        }
    }
    return 0;
}

