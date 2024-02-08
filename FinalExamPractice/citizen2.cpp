#include <bits/stdc++.h>
using namespace std;
struct citizen
{
    string dob, father, mother, region;
    char alive;
};
unordered_map<string, citizen> db;
map<string,int> born_at;
map<string,int> born_at_cumulative;
int a[100001];
int flag;

int born(string date){
    try{
        return born_at.at(date);
    }
    catch(const std::exception& e){
        return 0;
    }
}

int most_alive(string code){
    citizen cur;
    try{
        cur = db.at(code);
    }
    catch(const std::exception& e){
        return 0;
    }
    if(flag == 1 && cur.father != "0000000" && cur.mother != "0000000"){
        flag = 0;
        return 1 + max(most_alive(cur.father),most_alive(cur.mother));
    }
    if(cur.alive == 'Y' && cur.father != "0000000" && cur.mother != "0000000"){
        return 1 + max(most_alive(cur.father),most_alive(cur.mother));
    }else{
        return 0;
    }
}

int born_between(string date1, string date2) {
    int count_start = (born_at_cumulative.lower_bound(date1) != born_at_cumulative.begin()) ? prev(born_at_cumulative.lower_bound(date1))->second : 0;
    int count_end = prev(born_at_cumulative.upper_bound(date2))->second;

    return count_end - count_start;
}

int unrealted(){
    int count  = 0;
    for(auto i = db.begin(); i != db.end();i++){
        if(i->second.father ==  "0000000"  && i->second.mother == "0000000"){
            count++;
        }
    }
    return count;
}

void calculate_cumulative() {
    int cumulative_count = 0;
    for (const auto& entry : born_at) {
        cumulative_count += entry.second; // Cộng dồn số người sinh vào ngày hiện tại
        born_at_cumulative[entry.first] = cumulative_count; // Lưu vào born_at_cumulative
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string code, dob, father, mother, region;
    char alive;
    for (;;){   
        cin >> code;
        if (code == "*") break;
        cin >> dob >> father >> mother >> alive >> region;
        citizen temp;
        temp.dob = dob;
        temp.father = father;
        temp.mother = mother;
        temp.alive = alive;
        temp.region = region;
        db[code] = temp;
        born_at[dob]++;
    }
    calculate_cumulative();
    for(;;){
        cin >> code;
        if(code == "***") break;
        if(code == "NUMBER_PEOPLE") cout << db.size() << "\n";
        if(code == "NUMBER_PEOPLE_BORN_AT"){
            cin >> dob;
            cout << born(dob) << "\n";
        }
        if(code == "MOST_ALIVE_ANCESTOR"){
            cin >> code;
            flag = 1;
            cout << most_alive(code) << "\n";
        }
        if(code == "NUMBER_PEOPLE_BORN_BETWEEN"){
            string date1,date2; cin >> date1 >> date2;
            cout << born_between(date1,date2)<< "\n";
        }
        if(code == "MAX_UNRELATED_PEOPLE") cout << unrealted()<< "\n";
    }
}