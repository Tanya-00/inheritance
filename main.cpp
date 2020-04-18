#include <iostream>
#include <string>
using namespace std;

enum GENDER {
    U , M, F
};

enum GROUPOFBLOOD {
    O , A , B , AB
};

enum RHFACTOR {
    POSITIVE , NEGATIVE
};

class Human {
    int age;
    string fio;
    GENDER gender;
public:
    Human(int age, GENDER gender, string fio) {
        this->  gender = gender;
        this-> fio = fio ;
        this-> age = age;
    }

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        this->age = age;
    }

    GENDER getGender() const {
        return gender;
    }

    void setGender(GENDER gender) {
        this->gender = gender;
    }

    string getFio() const {
        return fio;
    }

    void setFio(string fio) {
        this->fio = fio;
    }
};

class BloodDonor : public Human {
    int amountOfBlood;
public:
    BloodDonor(int age, GENDER gender, string fio, int amountOfBlood) : Human(age, gender,fio) {
        this->amountOfBlood = amountOfBlood;
    }

    int getAmountOfBlood()  {
        return amountOfBlood;
    }

    void setAmountOfBlood(int amountOfBlood) {
        this->amountOfBlood = amountOfBlood;
    }
};

class Donor: public BloodDonor {
public:
    Donor(int age, GENDER gender, string fio, int amountOfBlood) : BloodDonor(age, gender, fio, amountOfBlood) {
    }
};

class Blood: public Donor {
    GROUPOFBLOOD groupOfBlood;
    RHFACTOR RHFactor;
public:
    Blood(int age, GENDER gender, string fio, int amountOfBlood, GROUPOFBLOOD groupOfBlood, RHFACTOR RHFactor) :
    Donor(age, gender, fio, amountOfBlood) {
        this->groupOfBlood = groupOfBlood;
        this->RHFactor = RHFactor;
    }

    GROUPOFBLOOD getGroupOfBlood() const {
        return groupOfBlood;
    }

    void setGroupOfBlood(GROUPOFBLOOD GroupOfBlood) {
        this->groupOfBlood = groupOfBlood;
    }

    RHFACTOR getRHFactor() const {
        return RHFactor;
    }

    void setRHFactor(RHFACTOR RHFactor) {
        this->RHFactor = RHFactor;
    }

};

class Re: public Blood {

};

class ill: public Human {

};

int main() {
    Human adam(24, GENDER::M,"fg");
    Human ric(19,GENDER::F,"DFGS" );
    BloodDonor helga(25, GENDER::F, "ADA", 1 );

    cout << ric.getAge() << endl;
    cout << adam.getFio() << endl;

    cout << helga.getAge() << endl;
    cout << helga.getGender() << endl;
    cout << helga.getAmountOfBlood() << endl;

    return 0;
}
