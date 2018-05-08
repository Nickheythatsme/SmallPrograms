"""
This holds the data for one site collection, 
as well as the body of water aggregate data (which has many site collection objects)
"""
from math import sin, cos, atan2, sqrt, radians
from datetime import datetime


# One collection object
class collection:
    def haversine(lat1, lon1, lat2, lon2):
        R = 6371 # Radius of earth in km
        
        # Convert decimal degrees to radians
        lon1, lat1, lon2, lat2 = map(radians, [lon1, lat1, lon2, lat2])

        # Haversine formula 
        dlon = lon2 - lon1
        dlat = lat2 - lat1
        a = sin(dlat/2)**2 + cos(lat2) * cos(lat2) * sin(dlon/2)**2
        c = 2 * atan2(sqrt(a), sqrt(1-a))
        d = R * c
        return d
    
    def convert_date(dstring):
        if type(dstring) is not type(str):
            return dstring
        return datetime.strptime(dstring, "%m/%d/%Y")


    def __init__(self, id, date, lat_long, common_name, count, pathogen=None, description=None):
        self.id = id
        self.date = collection.convert_date(date)
        self.lat_long = lat_long
        self.common_name = common_name
        self.count = count
        self.pathogen = pathogen
    
    def __str__(self):
        return "id: " + str(self.id)
    
    def __hash__(self):
        return self.id
    
    def distance(self, obj):
        if type(obj) != type(self):
            raise TypeError
        return collection.haversine(self.lat_long[0], self.lat_long[1], obj.lat_long[0], obj.lat_long[1])


"""
class waterBody:
    def __init__(self, name,)
"""

def main():
    col1 = collection(id=1, date="5/17/2018", lat_long=[45.468579, -122.600887], common_name="Salmon", count=10)
    col2 = collection(id=1, date=datetime.now(), lat_long=[45.337260, -122.39303], common_name="trout", count=10)

    print("Distance: {}".format(col1.distance(col2)))

if __name__ == "__main__":
    main()