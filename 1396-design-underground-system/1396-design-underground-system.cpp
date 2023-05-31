class UndergroundSystem {
unordered_map<int,pair<string,int>> checkInS;
unordered_map<string,pair<int,int>> checkOutS;
public:
    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInS[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto temp=checkInS[id];
        string route =temp.first + " " + stationName;
        checkInS.erase(id);
        checkOutS[route].first+=t-temp.second;
        checkOutS[route].second+=1;

    }
    
    double getAverageTime(string startStation, string endStation) {
        string route=startStation+" "+endStation;
        auto ans=checkOutS[route];
        double avg=0.0;
        avg=(double)(ans.first)/ans.second;
        return avg;
    }
};