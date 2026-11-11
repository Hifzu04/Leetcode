class UndergroundSystem {
public:
    unordered_map<int , pair<string , int >> checkinMap ;     // uid - {stname , time}
    unordered_map<string , pair<double , int>>totalmap;                                                   //uid - {route , totTime , freq }

    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkinMap[id] = {stationName , t};

    }
    
    void checkOut(int id, string stationName, int t) {
        auto checkin = checkinMap[id];                    // stname , t
        checkinMap.erase(id);     //Remove after using it
    
        
        
        string route = checkin.first + "_" + stationName;
        totalmap[route].first += t - checkin.second;
        totalmap[route].second += 1 ;


        
        
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation + "_" + endStation;
         double tottime = totalmap[route].first ; 
         int freq = totalmap[route].second;
         return tottime/freq; 
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */