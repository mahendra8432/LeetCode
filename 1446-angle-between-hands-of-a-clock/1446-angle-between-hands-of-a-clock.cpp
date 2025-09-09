class Solution {
public:
    double angleClock(int hour, int minutes) {
        double min=6*minutes;
        double hr=(30.0)*hour + (30/360.0)*min;
        double ans=abs(min-hr);
        if(ans>180) return 360-ans;
        return ans;
    }
};