package com.tutorial;


class Mahasiswa{
    // Data member
    String nama;
    String NIM;

    // constructor
    Mahasiswa(String nama, String NIM){
        this.nama = nama;
        this.NIM = NIM;
    }

    // method tanpa return dan tanpa parameter
    void show(){
        System.out.println("Nama : " + this.nama);
        System.out.println("NIM  : " + this.NIM);
    }

    // method tanpa return dan dengan parameter
    void setNama(String nama){
        this.nama = nama;
    }

    // method dengan return tapi tidak ada parameter
    String getNama(){
        return this.nama;
    }

    String getNIM(){
        return this.NIM;
    }

    // method dengan return dan dengan parameter
    String sayHi(String message){
        return message + " juga, nama saya adalah " + this.nama;
    }
}

public class Main{
    public static void main(String[] args) {
        Mahasiswa mahasiswa1 = new Mahasiswa("ucup","13305041");
        // method
        mahasiswa1.show();
        mahasiswa1.setNama("tutung");
        mahasiswa1.show();

        System.out.println(mahasiswa1.getNama());
        System.out.println(mahasiswa1.getNIM());

        String data = mahasiswa1.sayHi("ganteng");
        System.out.println(data);
    }
}



//reference

package com.tutorial;

class Buku{
    String judul;
    String penulis;

    Buku(String judul, String penulis){
        this.judul = judul;
        this.penulis = penulis;
    }

    void display(){
        System.out.println("\nJudul\t: " + this.judul);
        System.out.println("Penulis\t: " + this.penulis);
    }
}


public class Main{
    public static void main(String[] args) {
        Buku buku1 = new Buku("Killing Commandantore", "Haruki Murakami");
        buku1.display();

        // Menampilkan address
        String addressBuku1 = Integer.toHexString(System.identityHashCode(buku1));
        System.out.println(addressBuku1);
        
        // assignment object
        Buku buku2 = buku1;
        buku2.display();
        String addressBuku2 = Integer.toHexString(System.identityHashCode(buku2));
        System.out.println(addressBuku2);

        // karena buku1 dan buku2 berada pada address atau referensi yang sama 
        buku2.judul = "Membunuh komandantur";
        buku1.display();
        buku2.display();

        // kita akan memasukan object kedalam methods
        fungsi(buku2);
        buku1.display();
        buku2.display();
    }

    public static void fungsi(Buku dataBuku){
        String addressDataBuku = Integer.toHexString(System.identityHashCode(dataBuku));
        System.out.println("address dalam fungsi " + addressDataBuku);
        dataBuku.penulis = "Haruki Mahalkami";
    }
}


//public and pivate

package com.tutorial;

class Player{
    String name; // default, dia akan bisa dibaca dan ditulis dari luar class
    public int exp; // public, dia akan bisa dibaca dan ditulis dari luar class
    private int health; // private, hanya akan bisa dibaca dan ditulis di dalam class saja

    Player(String name, int exp, int health){
        this.name = name;
        this.exp = exp;
        this.health = health;
    }

    // default modifier access
    void display(){
        tambahExp(); // contoh mengakses private methods
        System.out.println("\nName\t: " + this.name);
        System.out.println("exp\t: " + this.exp);
        System.out.println("health\t: " + this.health); // membaca, tapi didalam class
    }

    // public
    public void ubahName(String nameBaru){
        this.name = nameBaru;
    }

    // private
    private void tambahExp(){
        this.exp += 100;
    }
}


public class Main{
    public static void main(String[] args) {
        
        Player player1 = new Player("Marni",0,100);

        // default
        System.out.println(player1.name); // membaca data
        player1.name = "Surti"; // Menulis data
        System.out.println(player1.name); // membaca data

        // public
        System.out.println(player1.exp); // membaca data
        player1.exp = 100; // Menulis data
        System.out.println(player1.exp); // membaca data

        // private (tidak bisa diakses)
        // System.out.println(player1.health); // membaca data
        // player1.health = 200; // Menulis data
        // System.out.println(player1.health); // membaca data

        // methods

        // default
        player1.display();

        // public
        player1.ubahName("Tejo");
        player1.display();

        // private (tidak bisa diakses)
        // player1.tambahExp();
    }
}




//static variable

package com.tutorial;


class Display{
    static String type = "Display";
    private String name;

    Display(String name){
        this.name = name;
    }

    void setType(String typeInput){
        // type = typeInput; // alternatif 1
        // this.type = typeInput; // alternatif 2
        Display.type = typeInput; // alternatif 3
    }

    void show(){
        System.out.println("Display name = " + this.name);
    }
}


public class Main{
    public static void main(String[] args) {
        
        Display display1 = new Display("Monitor");
        display1.show();

        Display display2 = new Display("Smartphone");
        display2.show();

        // tampilkan static variable atau class variable
        System.out.println("\nMenampilkan static variable");
        System.out.println(display1.type);
        System.out.println(display2.type);
        System.out.println(Display.type);

        // kita coba mengganti variable staticnya
        Display.type = "Tampilan";
        // display1.type = "Tampilan";
        // display2.type = "Tampilan";
        
        System.out.println("\nMenampilkan static variable");
        System.out.println(display1.type);
        System.out.println(display2.type);
        System.out.println(Display.type);

        // kita coba mengganti variable staticnya
        // display2.setType("Monitor");
        display1.setType("Monitor");

        System.out.println("\nMenampilkan static variable");
        System.out.println(display1.type);
        System.out.println(display2.type);
        System.out.println(Display.type);

    }
}




//static methods


package com.tutorial;

import java.util.ArrayList;

class Player{

    private static int numberOfPlayer;
    private static ArrayList<String> nameList = new ArrayList<String>();

    private String name;

    Player(String name){
        this.name = name;
        Player.numberOfPlayer++;
        Player.nameList.add(this.name);
    }

    void show(){
        System.out.println("Player name = " + this.name);
    }

    // static method
    static void showNumberOfPlayer(){
        System.out.println("Number of Player = " + Player.numberOfPlayer);
    }

    static ArrayList<String> getNames(){
        return Player.nameList;
    }

}

class Main{
    public static void main(String[] args) {
        Player player1 = new Player("Saitama");
        Player player2 = new Player("All Mighty");
        Player player3 = new Player("Midnight");
        Player player4 = new Player("Mt Lady");

        Player.showNumberOfPlayer();
        
        System.out.println("Names = " + Player.getNames());
        // System.out.println("Names = " + player1.getNames()); // ini bisa dilakukan
        
    }
}

//multi file

package com.tutorial;

// keyword import untuk package eksternal
import com.terminal.Console;

class Main{
    public static void main(String[] args) {
        Player player1 = new Player("Otong");
        Player player2 = new Player("Ucup");
        Player player3 = new Player("Saitama");
        player1.show();
        player2.show();
        player3.show();

        Console.log("hallo");
        Console.log("Hallo");
    }
}








/////////////////////////robot/////////////////////






/**
 * Robot.java
 * Robot merupakan sebuah kelas yang memodelkan robot di suatu dunia modern
 * 
 * @author 18221048 Syafiq Ziyadul Arifin
 */

public abstract class Robot {

    private int numberOfParts;
    private boolean isActive;

    public Robot(int numberOfParts, boolean isActive) {
        // Konstruktor
        this.numberOfParts = numberOfParts;
        this.isActive = isActive;
    }

    public int getNumberOfParts() {
        // Mengembalikan atribut numberOfParts
        return numberOfParts;
    }

    public boolean getIsActive() {
        // Mengembalikan atribut isActive
        return isActive;
    }

    public void setActivation(boolean isActive) {
        // Menetapkan atribut isActive
        this.isActive = isActive;
    }

    public String toString() {
        // Mengembalikan informasi hewan dengan format: "Number of Parts:
        // {numberOfParts}, IsActive: {isActive}"
        return "Number of Parts: " + numberOfParts + ", IsActive: " + isActive;
    }

    public abstract long getPrice();
}







///////////////////sirik//////////////////////





/**
 * Sirik.java
 * Sirik merupakan turunan dari kelas Robot
 * 
 * @author 18221048 Syafiq Ziyadul Arifin
 */

public class Sirik extends Robot {

    private long price;
    private int totalModel;

    public Sirik(long price) {
        // Konstruktor, set jumlah model bernilai 1
        super(5, false);
        this.price = price;
        totalModel = 1;
    }

    public int getTotalModel() {
        // Mengembalikan junlah
        return totalModel;
    }

    public void addModel() {
        // Menambahkan model sejumlah 1
        totalModel++;
    }

    @Override
    public long getPrice() {
        // Apabila total model lebih dari/samadengan 2,
        // maka formula = price + (500 * numberOfParts - (100 * totalModel))
        // Apabila total model kurang dari/sama dengan 2,
        // maka formula = price + (500 * numberOfParts * totalModel)
        if (totalModel <= 2) return price + (500 * getNumberOfParts() * totalModel);
        else return price + (500 * getNumberOfParts() - (100 * totalModel));
    }
}




////////////////////////wall-e/////////////////////////////





/**
 * WallE.java
 * WallE merupakan turunan dari kelas Robot
 * 
 * @author 18221048 Syafiq Ziyadul Arifin
 */

public class WallE extends Robot {

    private long mileage;

    public WallE(long mileage, boolean isActive) {
        // Konstruktor
        super(10, isActive);
        this.mileage = mileage;
    }

    public long getMileage() {
        // Mengembalikan mileage
        return mileage;
    }

    public void addMileage(long increment) {
        // Menambahkan mileage dengan increment
        mileage += increment;
    }

    @Override
    public long getPrice() {
        // Apabila sedang aktif, maka harga total adalah mileage * 1000,
        // Apabila tidak aktif maka ada tambahan biaya 500
        return mileage * 1000 + (getIsActive() ? 0 : 500);
    }
}









/////////////////bumblebee/////////////////////////








/**
 * Bumblebee.java
 * Bumblebee merupakan turunan dari kelas Robot
 * 
 * @author 18221048 Syafiq Ziyadul Arifin
 */

public class Bumblebee extends Robot {

    private int totalTransformation;

    public Bumblebee(int numberOfParts, boolean isActive) {
        // Konstruktor, set totalTransformation = 1
        super(numberOfParts, isActive);
        totalTransformation = 1;

    }

    public int getTotalTransformation() {
        // Mengembalikan totalTransformation
        return totalTransformation;
    }

    public void addTransformation() {
        // Menambahkan totalTransformation sejumlah 1
        totalTransformation++;
    }

    @Override
    public long getPrice() {
        // Apabila aktif, harga bernilai numberOfParts * 1000 * totalTransformation
        // Apabila tidak aktif, harga bernilai numberOfParts * 1000
        return getNumberOfParts() * 1000 * (getIsActive() ? totalTransformation : 1);
    }
}










//////////////dunia robot////////////







/**
 * DuniaRobot.java
 * DuniaRobot berfungsi untuk mengetahui harga dan spesifikasi masing-masing
 * model robot
 * 
 * @author 18221048 Syafiq Ziyadul Arifin
 */

import java.util.Scanner;

public class DuniaRobot {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int jenisRobot = scan.nextInt();
        if (jenisRobot == 1) {
            int numberOfParts = scan.nextInt();
            int totalTransformation = scan.nextInt();
            boolean isActive = scan.nextBoolean();
            Bumblebee robot = new Bumblebee(numberOfParts, isActive);
            for (int i = 0; i < totalTransformation; i++) {
                robot.addTransformation();
            }

            System.out.println("Number of Parts: " + robot.getNumberOfParts() + ", IsActive: " + robot.getIsActive());
            System.out.println("Jumlah transformasi: " + robot.getTotalTransformation());
            System.out.println("Harga robot: " + robot.getPrice());
        } else if (jenisRobot == 2) {
            long price = scan.nextLong();
            int totalModel = scan.nextInt();
            Sirik robot = new Sirik(price);
            for (int i = 0; i < totalModel; i++) {
                robot.addModel();
            }

            System.out.println("Number of Parts: " + robot.getNumberOfParts() + ", IsActive: " + robot.getIsActive());
            System.out.println("Jumlah model: " + robot.getTotalModel());
            System.out.println("Harga robot: " + robot.getPrice());
        } else if (jenisRobot == 3) {
            long mileage = scan.nextLong();
            boolean isActive = scan.nextBoolean();
            WallE robot = new WallE(mileage, isActive);

            System.out.println("Number of Parts: " + robot.getNumberOfParts() + ", IsActive: " + robot.getIsActive());
            System.out.println("Jumlah mileage: " + robot.getMileage());
            System.out.println("Harga robot: " + robot.getPrice());
        }
        scan.close();
    }
}
