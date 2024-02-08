#include <bits/stdc++.h>
using namespace std;

#define UNIQUE(S) S.erase(unique(S.begin(), S.end()), S.end())
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define MAXN 100005

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const ll mod = 1e9 + 7; // 1e9 + 7;
const ll oo = (ll)(1e18) + 7;
const double eps = 1e-3;
const double eps_cmp = 1e-7;

ll dr[] = {1, 1, 0, -1, -1, -1, 0, 1}; // S,SE,E,NE,N,NW,W,SW neighbors
ll dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; // trick to explore an implicit 2D grid graph
ll dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
bool valid(ll i, ll j, ll n, ll m) { return i >= 1 && i <= n && j >= 1 && j <= m; }

bool isEqual(double a, double b){
    return (abs(a - b) < eps_cmp);
}

void setIO(string s){
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

template <typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &x) { return out << x.f << ' ' << x.s; }
template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &x) { return in >> x.f >> x.s; }

template <typename T>
istream &operator>>(istream &in, vector<T> &a){
    for (auto &x : a) in >> x;
    return in;
};
template <typename T>
ostream &operator<<(ostream &out, vector<T> &a){
    for (auto &x : a) out << x << ' ';
    return out;
};

map<string, int> days, qty_customer;
set<pair<string, string>> timeflag;
map<pair<string, string>, int> qty_timeflag, timeflag_to_id;
int total_qty = 0, qty, total_trip = 0;
string trip_code = "", customer_code, day = "", tim, qry = "";

int id_qty[MAXN], st[21][MAXN]; // 20 here is LG[N]
map<string, pair<string, string>> min_time, max_time;

void preprocess(int n){
    for (int i = 1; i <= n; ++i) st[0][i] = id_qty[i];
    for (int j = 1; j <= 20; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
            st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
}

int queryMax(int l, int r){
    int k = __lg(r - l + 1);
    return max(st[k][l], st[k][r - (1 << k) + 1]);
}

int seconds_since_year_start(int year, int month, int day, int hour, int minute, int second){
    static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = day - 1; // Subtract 1 because day starts at 1
    for (int m = 1; m < month; ++m) days += daysInMonth[m - 1];
    return (((days * 24 + hour) * 60 + minute) * 60 + second);
}

// Function to calculate the difference between two moments in seconds
int cal_time_dif(const std::string &date1, const std::string &time1, const std::string &date2, const std::string &time2){
    tm tm1 = {}, tm2 = {};
    istringstream ss1(date1 + " " + time1);
    istringstream ss2(date2 + " " + time2);

    ss1 >> get_time(&tm1, "%Y-%m-%d %H:%M:%S");
    ss2 >> get_time(&tm2, "%Y-%m-%d %H:%M:%S");

    int year1 = tm1.tm_year + 1900;
    int month1 = tm1.tm_mon + 1;
    int day1 = tm1.tm_mday;
    int hour1 = tm1.tm_hour;
    int minute1 = tm1.tm_min;
    int second1 = tm1.tm_sec;

    int year2 = tm2.tm_year + 1900;
    int month2 = tm2.tm_mon + 1;
    int day2 = tm2.tm_mday;
    int hour2 = tm2.tm_hour;
    int minute2 = tm2.tm_min;
    int second2 = tm2.tm_sec;

    // Calculate seconds since the start of the year for each date-time
    int seconds1 = seconds_since_year_start(year1, month1, day1, hour1, minute1, second1);
    int seconds2 = seconds_since_year_start(year2, month2, day2, hour2, minute2, second2);

    // Calculate the difference in seconds between the two moments
    int secondsPerYear = 365 * 24 * 3600;
    int diff = (year2 - year1) * secondsPerYear + seconds2 - seconds1;
    return diff;
}

void solve(){
    while (day != "*"){
        cin >> day;
        if (day != "*") days[day] = 1;
    }
    while (trip_code != "***"){
        cin >> trip_code;
        if (trip_code != "***"){
            cin >> customer_code >> day >> tim >> qty;
            total_qty += qty;
            qty_customer[customer_code] += qty;
            timeflag.insert({day, tim});
            qty_timeflag[{day, tim}] += qty;
            total_trip++;
            if (min_time[trip_code].fi == "") min_time[trip_code] = max_time[trip_code] = {day, tim};
            else{
                if (day < min_time[trip_code].fi || (day == min_time[trip_code].fi && tim < min_time[trip_code].se))
                    min_time[trip_code] = {day, tim};
                if (day > max_time[trip_code].fi || (day == max_time[trip_code].fi && tim > max_time[trip_code].se))
                    max_time[trip_code] = {day, tim};
            }
        }
    }
    int cnt = 1;
    for (auto i : timeflag){
        timeflag_to_id[i] = cnt;
        id_qty[cnt++] = qty_timeflag[i];
    }
    preprocess(cnt - 1);
    while (qry != "***"){
        cin >> qry;
        if (qry != "***"){
            if (qry == "TOTAL_QTY") cout << total_qty << '\n';
            if (qry == "QTY_CUSTOMER"){
                cin >> customer_code;
                cout << qty_customer[customer_code] << '\n';
            }
            if (qry == "QTY_MAX_PERIOD"){
                pair<string, string> fromm, too;
                cin >> fromm.fi >> fromm.se >> too.fi >> too.se;
                int id_left = timeflag_to_id[*timeflag.lower_bound(fromm)];
                int id_right;
                if (timeflag.upper_bound(too) == timeflag.end()) id_right = cnt - 1;
                else id_right = timeflag_to_id[*timeflag.upper_bound(too)] - 1;
                cout << queryMax(id_left, id_right) << '\n';
            }
            if (qry == "TOTAL_TRIPS") cout << total_trip << '\n';
            if (qry == "TRAVEL_TIME_TRIP"){
                cin >> trip_code;
                cout << cal_time_dif(min_time[trip_code].fi, min_time[trip_code].se, max_time[trip_code].fi, max_time[trip_code].se) << '\n';
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    setIO("A");
    auto start = chrono::high_resolution_clock::now();
    solve();
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration<double>(end - start);
    cout << "Time taken by function: " << duration.count() << " seconds" << endl;
    return 0;
}