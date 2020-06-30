#ifndef ITEM_H
#define ITEM_H
#include <string>
using std::string;
#include <iostream>
using std::ostream;
using std::cout;
#define _USE_MATH_DEFINES
#include <cmath>


// TODO: your code  goes here
class Item {
private:
	double latitude,longitude;
	string ID;
	int time;
	double dlon, dlat;
public:
	Item(double latitudeIn, double longitudeIn, string IDIn, int timeIn) :
		latitude(latitudeIn), longitude(longitudeIn),ID(IDIn), time(timeIn){
	}
	double getLatitude() const{
	    return latitude;
	}
    double getLongitude() const{
        return longitude;
    }
    string getID() const{
        return ID;
    }
    int getTime() const{
        return time;
    }
    double distanceTo(Item distance) {
		dlon = distance.getLongitude() - longitude;
		dlon = (dlon*M_PI)/180;
		dlat = distance.getLatitude() - latitude;
		dlat = (dlat*M_PI)/180;
		double a = pow((sin(dlat/2)), 2) + cos((latitude*M_PI)/180) * cos((distance.getLatitude()*M_PI)/180) * pow((sin(dlon/2)), 2);
		double c = 2 * atan2( sqrt(a), sqrt(1-a) );
		double distance2 = 6373000 * c;
		return distance2;
	}

};
ostream & operator<<(ostream & c, const Item & item){
    c << "{" << item.getLatitude() << ", " << item.getLongitude() << ", " << '"' << item.getID() << '"' << ", " << item.getTime() << "}";
	return c;

    }



// don't write any code below this line

#endif

