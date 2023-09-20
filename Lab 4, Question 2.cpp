// Lab 4, Question 2
//

#include <iostream>
#include <fstream>
using namespace std;

class Car {
private:
    string m_make;
    string m_owner;
    int m_yearModel;
    int m_speed;

public:
    void setOwner(string owner) { m_owner = owner; }
    void setYearModel(int yearModel) { m_yearModel = yearModel; }
    void setMake(string make) { m_make = make; }
    void setSpeed(int speed)
    {
        if (speed < 0) {
            m_speed = 0;
        }
        else {
            m_speed = speed;
        }
    }

    string getOwner() { return m_owner; }
    int getYearModel() { return m_yearModel; }
    string getMake() { return m_make; }
    int getSpeed() { return m_speed; }

    Car();

    Car(string name, int yearModel, string make);
    
    ~Car();

    void Accelerate();

    void Brake();

    void UpdateStatus();

};

int main()
{
    srand((unsigned int)time(NULL));

    Car myCars[5];

    fstream infile;
    infile.open("Cars.txt");
    string name;
    int year;
    string make;

    for (int index = 0; index < 5; index++) {
        
        infile >> name >> year >> make;

        myCars[index].setOwner(name);
        myCars[index].setYearModel(year);
        myCars[index].setMake(make);

        cout << "Owner: " << myCars[index].getOwner() << endl << "Year: " << myCars[index].getYearModel() << endl << "Make: " << myCars[index].getMake() << endl << endl;

    }

    for (int count = 0; count < 10; count++) {

        for (int carIndex = 0; carIndex < 5; carIndex++) {
            myCars[carIndex].UpdateStatus();

            cout << "Owner: " << myCars[carIndex].getOwner() << endl << "Year: " << myCars[carIndex].getYearModel() << endl << "Make: " << myCars[carIndex].getMake() << endl << "Speed: " << myCars[carIndex].getSpeed() << endl << endl;
        }
    }

    infile.close();

    system("pause>0");
}

//Default consturctor
Car::Car() {

    m_speed = 0;
    m_make = "";
    m_owner = "";
    m_yearModel = 0;

}

Car::Car(string name, int yearModel, string make) {

    m_owner = name;
    m_yearModel = yearModel;
    m_make = make;

    m_speed = rand() % 101 + 100;
}

Car::~Car() {

    m_speed = 0;
    m_make = "";
    m_owner = "";
    m_yearModel = 0;

}

void Car::Accelerate() {

    m_speed += 5;

}

void Car::Brake() {
    m_speed -= 5;

    if (m_speed < 0) {
        m_speed = 0;
    }

}

void Car::UpdateStatus() {

    if (rand() % 2 == 1) {
        Car::Accelerate();
    }

    else {
        Car::Brake();
    }

}


