class UndergroundSystem {
public:
    map<pair<string,string> , pair<int ,int>>mpf;
    map<int , pair<int ,string>>mpi;
    
    UndergroundSystem() {
    
    }
    
    void checkIn(int id, string sn  ,int t ){
    mpi[id] ={t ,sn};
    }
    
    void checkOut(int id, string sn  ,int t ){
        if(mpi.find(id)!=mpi.end()){
            if(mpf.find({mpi[id].second, sn})!= mpf.end()){
                int p = mpf[{mpi[id].second, sn}].second;
                int q = mpf[{mpi[id].second, sn}] .first;
               mpf[{mpi[id].second, sn}] = {t-mpi[id].first + (q) ,p+1};  
            }
                else{
                    mpf[{mpi[id].second, sn}] = {t-mpi[id].first , 1};
                }
            
        }
    }
    
    double getAverageTime(string sn, string ss) {
        return (double)mpf[{sn, ss}].first / (double) mpf[{sn,ss}].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */