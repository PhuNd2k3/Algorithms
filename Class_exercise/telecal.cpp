// CPP
#include <bits/stdc++.h>
using namespace std;
typedef struct
{
    int year;
    int month;
    int day;
} date_t;

typedef struct
{
    int hour;
    int minute;
    int second;
} time_type;

bool isNumeric(const string &str)
{
    for (char c : str)
    {
        if (!isdigit(c))
        {
            return false; // Nếu có bất kỳ ký tự nào không phải số, trả về false
        }
    }
    return true;
}
void input()
{
    char ch;
    char buffer[255];
    int notStop = 2;
    string system_call;
    string from_number;
    string to_number;
    date_t date;
    time_type from_time;
    time_type end_time;
    map<string, pair<int, int>> phone_info;
    int check_phone = 1;
    int total_call = 0;
    while (notStop)
    {
        cin >> system_call;
        if (system_call[0] == 'c')
        {
            cin >> from_number >> to_number;
            fgets(buffer, 255, stdin);
            sscanf(buffer, "%d-%d-%d %d:%d:%d %d:%d:%d", &date.year, &date.month, &date.day, &from_time.hour, &from_time.minute, &from_time.second, &end_time.hour, &end_time.minute, &end_time.second);
            if (!isNumeric(from_number) || !isNumeric(to_number) || from_number.length() != 10 || to_number.length() != 10)
                check_phone = 0;
            else
            {
                phone_info[from_number].first++;
                phone_info[from_number].second += (end_time.hour - from_time.hour) * 60 * 60 + (end_time.minute - from_time.minute) * 60 + (end_time.second - from_time.second);
            }
            total_call++; //?? maybe in if
        }
        if (system_call[0] == '#')
        {
            notStop--;
        }
        if (system_call[0] == '?')
        {
            if (system_call == "?check_phone_number")
            {
                cout << check_phone << endl;
            }
            if (system_call == "?number_calls_from")
            {
                cin >> from_number;
                cout << phone_info[from_number].first << endl;
            }
            if (system_call == "?number_total_calls")
            {
                cout << total_call << endl;
            }
            if (system_call == "?count_time_calls_from")
            {
                cin >> from_number;
                cout << phone_info[from_number].second << endl;
            }
        }
    }
}
int main()
{
    input();
    return 0;
}