class UndergroundSystem {
public:
    unordered_map<int, pair<string,int>> info;
    unordered_map<string, pair<int,int>> record;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        info[id]={stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        const pair<string, int> &p = info[id];
        string key = p.first + "." + stationName;
        pair<int, int> &r = record[key];
        r.first += t-p.second; ++r.second;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + "." + endStation;
        const pair<int, int> &p = record[key];
        return (double)p.first/(double)p.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */