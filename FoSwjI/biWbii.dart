import 'package:flutter/material.dart';
import 'package:location/location.dart';
import 'package:google_maps_flutter/google_maps_flutter.dart';

void main() => runApp(MyApp());

class MyApp extends StatefulWidget {
  @override
  _MyAppState createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  GoogleMapController mapController;
  LocationData currentLocation;
  Location location = Location();

  @override
  void initState() {
    super.initState();
    initLocation();
  }

  void initLocation() async {
    LocationData locationData;
    try {
      locationData = await location.getLocation();
    } catch (e) {
      locationData = null;
    }

    if (!mounted) return;

    setState(() {
      currentLocation = locationData;
    });
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: Text('GPS Location App'),
        ),
        body: Center(
          child: Column(
            children: <Widget>[
              currentLocation != null
                  ? Container(
                      height: 300,
                      width: 300,
                      child: GoogleMap(
                        onMapCreated: (GoogleMapController controller) {
                          mapController = controller;
                        },
                        initialCameraPosition: CameraPosition(
                          target: LatLng(
                            currentLocation.latitude,
                            currentLocation.longitude,
                          ),
                          zoom: 15.0,
                        ),
                        markers: Set<Marker>.of(
                          <Marker>[
                            Marker(
                              markerId: MarkerId("current_location"),
                              position: LatLng(
                                currentLocation.latitude,
                                currentLocation.longitude,
                              ),
                              infoWindow: InfoWindow(
                                title: "Current Location",
                              ),
                            ),
                          ],
                        ),
                      ),
                    )
                  : CircularProgressIndicator(),
            ],
          ),
        ),
      ),
    );
  }
}
