import math

def haversine(lat1, lon1, lat2, lon2):
    # Convert coordinates from degrees to radians
    lat1, lon1, lat2, lon2 = map(math.radians, [lat1, lon1, lat2, lon2])

    # Haversine formula
    dlon = lon2 - lon1
    dlat = lat2 - lat1
    a = math.sin(dlat/2)**2 + math.cos(lat1) * math.cos(lat2) * math.sin(dlon/2)**2
    c = 2 * math.asin(math.sqrt(a))

    # Radius of Earth in kilometers
    r = 6371

    return c * r

# Test the function with the coordinates of two cities
lat1, lon1 = 12.9715987, 77.5945627  # Bengaluru
lat2, lon2 = 13.0826802, 80.2707184  # Chennai

print(haversine(lat1, lon1, lat2, lon2))
