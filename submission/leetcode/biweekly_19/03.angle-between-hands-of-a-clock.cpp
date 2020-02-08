#include "bits/stdc++.h"
using namespace std;

map <int,int> dp;

//source - https://www.geeksforgeeks.org/calculate-angle-hour-hand-minute-hand/
double calcAngle(double h, double m)  
{  
    // validate the input  
    if (h <0 || m < 0 || h >12 || m > 60)  
        printf("Wrong input");  
  
    if (h == 12) h = 0;  
    if (m == 60) m = 0;  
  
    // Calculate the angles moved  
    // by hour and minute hands  
    // with reference to 12:00  
    double hour_angle = 0.5 * (h * 60 + m);  
    double minute_angle = 6 * m;  
  
    // Find the difference between two angles  
    double angle = abs(hour_angle - minute_angle);  
  
    // Return the smaller angle of two possible angles  
    angle = min(360 - angle, angle);  
  
    return angle;  
}  

class Solution
{
public:
	double angleClock(int hour, int minutes)
	{
		return calcAngle(hour,minutes);
	}
};

#ifdef LOCAL
int main()
{
	vector <int> v={11,13,17,23,29,31,7,5,2,3};
	auto ans=Solution().numOfSubarrays(v,3,5);
	cout<<ans<<endl;
}
#endif