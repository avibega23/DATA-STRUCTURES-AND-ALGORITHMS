#include <bits/stdc++.h>
using namespace std;

class Car{

        string type;
    public:
        Car()
        {
            type = "petrol";
        }
        Car(string inputValue)
        {
            type = inputValue;
        }
        void display()
        {
            cout << type;
        }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Car sunnyCar;
    Car aviCar("Electric");
    aviCar.display();
    

    return 0;
}