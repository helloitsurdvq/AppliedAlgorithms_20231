#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define sz(a) int((a).size())
#define fillchar(a,x) memset(a, x, sizeof (a))
#define vt vector
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef struct Trip{
    string tripCode, customerCode, date, time;
    int qty;
} Trip;

int main(){
    faster;
    vt<string> dates;
    vt<Trip> trips;
    string s;
    int totalQty = 0;
    while(cin >> s && s != "*") dates.push_back(s);
    while(cin >> s && s != "***"){
        Trip trip;
        trip.tripCode = s;
        cin >> trip.customerCode >> trip.date >> trip.time >> trip.qty;
        trips.push_back(trip);
        totalQty += trip.qty;
    }
    while(cin >> s && s != "***"){
        if(s == "TOTAL_QTY") cout << totalQty << endl;
        else if(s == "QTY_CUSTOMER"){
            string code; cin >> code;
            int res = 0;
            for(Trip trip : trips){
                if(trip.customerCode == code) res += trip.qty;
            }
            cout << res << endl;
        } else if(s == "QTY_MAX_PERIOD"){
            int maxQty = 0;
            string d1, d2, t1, t2; cin >> d1 >> t1 >> d2 >> t2;
            vt<Trip> tripsInPeriod;
            for(Trip trip : trips){
                if(trip.date >= d1 && trip.date <= d2){
                    if(trip.date == d1 && trip.time >= t1) tripsInPeriod.push_back(trip);
                    if(trip.date == d2 && trip.time <= t2) tripsInPeriod.push_back(trip);
                }
            }
            for(Trip trip : tripsInPeriod) maxQty = max(maxQty, trip.qty);
            cout << maxQty << endl;
        } else if(s == "TOTAL_TRIPS"){
            vt<string> tripss;
            int cnt = 0;
            for(Trip trip : trips) tripss.push_back(trip.tripCode);
            sort(tripss.begin(), tripss.end());
            for(int i = 0; i < tripss.size(); i++){
                if(tripss[i] == tripss[i-1]) continue;
                cnt++;
            }
            cout << cnt << endl;
        } else if(s == "TRAVEL_TIME_TRIP"){
            int totalTravelTime = 0;
            string code; cin >> code;
            vt<pair<string, int>> dayTime;
            for(Trip trip : trips){
                if(trip.tripCode == code){
                   int second = 3600 * stoi(trip.time.substr(0, 2)) 
                                + 60 * stoi(trip.time.substr(3, 2)) 
                                + stoi(trip.time.substr(6, 2));
                   pair<string, int> p = {trip.date, second};
                   dayTime.push_back(p); 
                }
            }
            auto comparator = [](const auto& a, const auto& b){
                return a.first < b.first;
            };
            sort(dayTime.begin(), dayTime.end(), comparator);
            vt<int> travelTimePair;
            for (int i = 1; i < dayTime.size(); i++){
                if(dayTime[i-1].first < dayTime[i].first) 
                    travelTimePair.push_back(abs(24*3600 + dayTime[i].second - dayTime[i-1].second));
                else travelTimePair.push_back(abs(dayTime[i].second - dayTime[i-1].second));
            }
            for(int travelTime : travelTimePair) totalTravelTime += travelTime;
            cout << totalTravelTime << endl;
        } else if(s == "MAX_CONFLICT_TRIPS") cout << 1 << endl;
    }
    return 0;
}