#include <iostream>
#include <iomanip>

using namespace std;

// DIY 5.2: Friend comparison
// Write a Time class (hh:mm) and a friend function laterOf(Time, Time)
// returning the later of two times.

class Time {
private:
    int hours;
    int minutes;

public:
    Time(int h = 0, int m = 0) : hours(h), minutes(m) {}

    // Friend function declaration
    friend Time laterOf(const Time &t1, const Time &t2);

    void display() const {
        cout << setfill('0') << setw(2) << hours << ":"
             << setfill('0') << setw(2) << minutes << endl;
    }
};

// Friend function definition - has access to private members
Time laterOf(const Time &t1, const Time &t2) {
    int total1 = t1.hours * 60 + t1.minutes;
    int total2 = t2.hours * 60 + t2.minutes;
    return (total1 >= total2) ? t1 : t2;
}

int main() {
    Time t1(14, 30);
    Time t2(17, 15);

    cout << "Time 1: "; t1.display();
    cout << "Time 2: "; t2.display();

    Time later = laterOf(t1, t2);
    cout << "The later time is: ";
    later.display();

    return 0;
}
