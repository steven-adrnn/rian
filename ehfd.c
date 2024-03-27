public class GeoCoord {
    private float lat;
    private float lon;
    public GeoCoord(float lat, float lon) {
        this.lat = lat;
        this.lon = lon;
    }
    public void setLatLon(float lat, float lon) {
        this.lat = lat;
        this.lon = lon;
    } 
    public float getLat() {
        return lat;
    }
    public float getLon() {
        return lon;
    }
}


public class GeoCoord3D extends GeoCoord {
    private int alt;
    public GeoCoord3D(float lat, float lon, int alt) {
        super(lat, lon);
        this.alt = alt;
    }
    public int getAlt() {
        return alt;
    }
    public void setAlt(int alt) {
        this.alt = alt;
    }
}

public interface Moveable {
    public void moveTo(GeoCoord newLoc);
}

public abstract class Vehicle implements Moveable {
    private GeoCoord location;
    private static int numVehicle = 0;
    public Vehicle(GeoCoord location){
        this.location = location;
        Vehicle.numVehicle += 1;
    } 
    public void printLoc() {
        System.out.println("Latitude: " + location.getLat());
        System.out.println("Longitude: " + location.getLon());
    }
    public GeoCoord getLocation() {
        return location;    
    }
    public void setLocation(GeoCoord location){
        this.location = location;
    }
    public static int getNumVehicle() {
        return numVehicle;
    }
    public void moveTo(GeoCoord newLoc){
        location = newLoc;
    }
}

public class Airplane extends Vehicle {
    private int alt;
    public Airplane(GeoCoord3D position){
        super(new GeoCoord(position.getLat(), position.getLon()));
        alt = position.getAlt();
    }
    public void printLoc(){
        super.printLoc();
        System.out.println("Altitude: " + alt);
    }
    public static void main(String[] args){
        GeoCoord3D position = new GeoCoord3D(1.2f, 2.5f, 10);
        Airplane pesawat = new Airplane(position);
        pesawat.printLoc();
        GeoCoord location = new GeoCoord(5.2f, 0.5f);
        pesawat.moveTo(location);
        pesawat.printLoc();
        System.out.println("NumVehicle: " + Vehicle.getNumVehicle());
    }
}


public class GeoLoc{
    private float lat;
    private float lon;
    private int alt;
    public GeoLoc(float lat, float lon, int alt){
        this.lat = lat;
        this.lon = lon;
        this.alt = alt;
    }
    public void setLoc(float lat, float lon, int alt){
        this.lat = lat;
        this.lon = lon;
        this.alt = alt;
    }
    public float getLat() {
        return lat;
    }
    public float getLon() {
        return lon;
    }
    public int getAlt() {
        return alt;
    }
}

public interface Moveable {
    public void moveTo(GeoLoc newLoc);
}

public abstract class Vehicle implements Moveable {
    private GeoLoc loc;
    private int speed;
    private static int numVehicle = 0;
    public Vehicle(GeoLoc loc) {
        this.loc = loc;
        numVehicle++;
    }
    public GeoLoc getLocation() {
        return loc;
    }
    public abstract void accelerate();
    public abstract void decelerate(); 
    public static int getNumVehicle() {
        return numVehicle;
    }
    public void moveTo(GeoLoc newLoc) {
        loc = newLoc;
    }
}

public class Drone extends Vehicle {
    private int vSpeed;
    public Drone(GeoLoc location){
        super(location);
    }
    public void climb(){
        getLocation().setLoc(getLocation().getLat(), getLocation().getLon(), getLocation().getAlt()+1);
    }
    public void descend(){
        getLocation().setLoc(getLocation().getLat(), getLocation().getLon(), getLocation().getAlt()-1);
    }
    public void accelerate(){
        vSpeed++;
    }
    public void decelerate(){
        vSpeed--;
    }
}


public class MainVehicle {
    public static void main(String[] args){
        Drone drone = new Drone(new GeoLoc(1.2f, 2.5f, 5));
        drone.accelerate(); 
        drone.climb(); 
        drone.decelerate(); 
        drone.descend(); 
        drone.moveTo(new GeoLoc(1.9f, 5.6f, 10));
        System.out.println("Num Vehicle: " + Vehicle.getNumVehicle());
    }
}
