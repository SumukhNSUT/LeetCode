class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int t1=stoi(startTime.substr(0,2))*3600+stoi(startTime.substr(3,2))*60+stoi(startTime.substr(6,2));
        int t2=stoi(endTime.substr(0,2))*3600+stoi(endTime.substr(3,2))*60+stoi(endTime.substr(6,2));
        return abs(t1 - t2);
    }
};