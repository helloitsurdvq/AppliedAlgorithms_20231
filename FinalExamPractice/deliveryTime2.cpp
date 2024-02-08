#include <bits/stdc++.h>
using namespace std;
long long total_qty = 0;
int total_trip = 0;
struct SE{
    time_t S, E;
};

map<string, int> cus_qty;
map<string, time_t> start_time;
map<string, int> travel_time;
map<time_t, int> qty_time;
map<time_t, time_t> time_time;
map<string, SE> se;

time_t time_convert(string date, string time){
    struct tm dateTime1 = {0}; // Initialize all values to 0

    dateTime1.tm_year = (date[0] - '0') * 1000 + (date[1] - '0') * 100 + (date[2] - '0') * 10 + (date[3] - '0') - 1900;
    dateTime1.tm_mon = (date[5] - '0') * 10 + date[6] - '0' - 1;
    dateTime1.tm_mday = (date[8] - '0') * 10 + (date[9] - '0');
    dateTime1.tm_hour = (time[0] - '0') * 10 + (time[1] - '0');
    dateTime1.tm_min = (time[3] - '0') * 10 + (time[4] - '0');
    dateTime1.tm_sec = (time[6] - '0') * 10 + (time[7] - '0');
    return mktime(&dateTime1);
}
int max_qty(string date1, string time1, string date2, string time2){
    time_t t1 = time_convert(date1, time1);
    time_t t2 = time_convert(date2, time2);
    int max = 0;
    for (auto i = qty_time.begin(); i != qty_time.end(); i++){
        if (i->first > t1 && i->first < t2){
            if (i->second > max) max = i->second;
        }
    }
    return max;
}

int max_alc(){
    int max = 0;
    for (auto i = se.begin(); i != se.end(); i++){
        int cur_max = 0;
        for (auto j = se.begin(); j != se.end(); j++) {
            if (j->second.S > i->second.E || j->second.E < i->second.S) continue;
            cur_max++;
        }
        if (cur_max > max) max = cur_max;
    }
    return max;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string type;
    do{
        cin >> type;
        if (type == "*") continue;
    } while (type != "*");
    do{
        cin >> type;
        if (type == "*") continue;
        string trip_code, cus_code, date, time;
        int qty;
        cin >> cus_code >> date >> time >> qty;
        trip_code = type;
        total_qty += qty;
        time_t curtime = time_convert(date, time);
        qty_time[curtime] = qty;
        cus_qty[cus_code] += qty;
        if (start_time.find(trip_code) == start_time.end()){
            start_time[trip_code] = curtime;
            travel_time[trip_code] = 0;
            total_trip++;

            se[trip_code].S = curtime;
            se[trip_code].E = curtime;
        }
        else {
            int seconds = std::abs(static_cast<int>(difftime(start_time[trip_code], time_convert(date, time))));
            if (seconds > travel_time[trip_code]) {
                travel_time[trip_code] = seconds;
                se[trip_code].E = curtime;
            }
        }

    } while (type != "*");
    do {
        cin >> type;
        if (type == "*") continue;
        if (type == "TOTAL_QTY") cout << "\n"<< total_qty;
        if (type == "QTY_CUSTOMER") {
            string cus; cin >> cus;
            cout << "\n" << cus_qty[cus];
        }
        if (type == "QTY_MAX_PERIOD") {
            string date1, date2, time1, time2; cin >> date1 >> time1 >> date2 >> time2;
            cout << "\n" << max_qty(date1, time1, date2, time2);
        }
        if (type == "TOTAL_TRIPS") cout << "\n" << total_trip;
        if (type == "TRAVEL_TIME_TRIP"){
            string trip; cin >> trip;
            cout << "\n" << travel_time[trip];
        }
        if (type == "MAX_CONFLICT_TRIPS") cout << "\n" << max_alc();
    } while (type != "*");
}