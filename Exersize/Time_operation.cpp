#include <iostream>
#include <cmath>
using namespace std;

class Time
{
public:
    int hour;
    int minutes;
    int seconds;
public:
    Time()
    {
        hour = 0;
        minutes = 0;
        seconds = 0;
    }
    void Set_time(){
        cout << "Enter time data:" << endl;
        cout << ">> Hours: ";
        int user_hour = 0;
        cin >> user_hour;
        cout << ">> Minutes: ";
        int user_minute = 0;
        cin >> user_minute;
        cout << ">> Seconds: ";
        int user_second = 0;
        cin >> user_second;
        hour = user_hour;
        minutes = user_minute;
        seconds = user_second;
    }

    void Seconds_differ()
    {
        cout << "Enter count seconds: ";
        int user_seconds = 0;
        cin >> user_seconds;
        seconds = seconds - user_seconds;
        while (seconds < 0){
            minutes--;
            seconds += 60;
        }
        while (minutes < 0){
            hour--;
            minutes += 60;
        }
        if(hour < 0){
            hour = 0;
            minutes = 0;
            seconds = 0;
        }
        cout << "Time left: ";
        cout << hour << ":" << minutes << ":" << seconds;
    }

};

int main()
{
    cout << "Choose the action:" << endl;
    cout << "D - differ seconds" << endl;
    cout << "T - two moments time differ" << endl;
    cout << "Action:";
    char user_choice;
    cin >> user_choice;
    user_choice = toupper(user_choice);
    switch (user_choice){
        case 'D':{
            Time user_time;
            user_time.Set_time();
            user_time.Seconds_differ();
            break;
        }
        case 'T':{
            Time first_moment;
            cout << "Enter the first time moment" << endl;
            first_moment.Set_time();
            Time second_moment;
            cout << "Enter the second time moment" << endl;
            second_moment.Set_time();

            int first_moment_sec = first_moment.seconds + first_moment.minutes*60 + first_moment.hour*3600;
            int second_moment_sec = second_moment.seconds + second_moment.minutes*60 + second_moment.hour*3600;
            int result = abs(first_moment_sec - second_moment_sec);
            cout << "Number of seconds between entered times: " << result << endl;
            break;
        }
        default:
            cout << "Bad input!" << endl;
    }
    return 0;
}
