//////////////////KELAS TERBUKA////////////////



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


















//////////////////////DAFTAR MATA KULIAH////////////////////////


/**
 * DaftarMataKuliah.java
 * DaftarMataKuliah merupakan sebuah kelas yang mengeluarkan info mata kuliah sesuai input
 *
 * @author 18221048 Syafiq Ziyadul Arifin
 */

import java.util.Scanner;

public class DaftarMataKuliah {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String kode = scan.next();
		String nama = scan.next();
		int sks = scan.nextInt();
		String dosen = scan.next();
		int kapasitas = scan.nextInt();
		int kapasitasTambahan = scan.nextInt();
		MataKuliah mk = new MataKuliah(kode, nama, sks, dosen, kapasitas);
		System.out.println("Kode Mata Kuliah: " + mk.getKode());
		System.out.println("Nama Mata Kuliah: " + mk.getNama());
		System.out.println("SKS Mata Kuliah: " + mk.getSks());
		System.out.println("Nama Dosen: " + mk.getDosen());
		System.out.println("Kapasitas Kuliah: " + mk.getKapasitas());
		mk.tambahKapasitas(kapasitasTambahan);
		System.out.println("Total Revisi Kapasitas Kuliah: " + mk.getKapasitas());
		scan.close();
	}
}







/////////////////////////INDEKS MATAKULIAH//////////////////////////


/**
 * IndeksMataKuliah.java
 * IndeksMataKuliah merupakah sebuah kelas yang memodelkan seorang mahasiswa ITB
 * 
 * @author 18221048 Syafiq Ziyadul Arifin
 */

public class IndeksMataKuliah {
    // Deklarasi atribut
    private MataKuliah mataKuliah;
    private String nama;
    private String indeks;
    private Double nilai;

    /**
     * Konstruktor
     * 
     * @param mk
     * @param nama
     * @param nilai
     * indeks ditentukan berdasarkan nilai yang diperoleh dengan
     * ketentuan sebagai berikut
     * A -> nilai = 4
     * B -> 3.0 <= nilai < 4.0
     * C -> 2.0 <= nilai < 3.0
     * D -> 1.0 <= nilai < 2.0
     * E -> 0.0 <= nilai < 1.0
     * Apabila nilai tidak valid, maka indeks dianggap E dan nilai
     * dianggap 0
     */
    public IndeksMataKuliah(MataKuliah mk, String nama, Double nilai) {
        this.mataKuliah = mk;
        this.nama = nama;
        this.nilai = nilai;
        updateIndeks(nilai);
    }

    /**
     * Getter mataKuliah
     * 
     * @return mataKuliah
     */
    public MataKuliah getMataKuliah() {
        return mataKuliah;
    }

    /**
     * Getter nama
     * 
     * @return nama
     */
    public String getNama() {
        return nama;
    }

    /**
     * Getter indeks
     * 
     * @return indeks
     */
    public String getIndeks() {
        return indeks;
    };

    /**
     * Getter nilai
     * 
     * @return nilai
     */
    public Double getNilai() {
        return nilai;
    }

    /**
     * Mengubah nilai mahasiswa
     * 
     * @param nilai nilai baru dari mahasiswa
     */
    public void ubahNilai(Double nilai) {
        this.nilai = nilai;
        updateIndeks(nilai);
    }

    /**
     * Update indeks
     * 
     */
    public void updateIndeks(Double nilai) {
        if (nilai == 4.0) indeks = "A";
        else if (nilai >= 3.0 && nilai < 4.0) indeks = "B";
        else if (nilai >= 2.0 && nilai < 3.0) indeks = "C";
        else if (nilai >= 1.0 && nilai < 2.0) indeks = "D";
        else if (nilai >= 0.0 && nilai < 1.0) indeks = "E";
        else {
            this.nilai = 0.0;
            indeks = "E";
        }
    }

    /**
     * Normalisasi nilai
     * 
     * @param countLulus jumlah mahasiswa yang lulus
     *      Normalisasi nilai dilakukan dengan menambahkan nilai saat
     *      ini dengan
     *      persentase jumlah mahasiswa yang lulus
     * 
     *      Apabila hasil normalisasi lebih dari 4.0, maka akan
     *      dianggap 4
     */
    public void normalisasiNilai(int countLulus) {
        nilai += (nilai * countLulus / (mataKuliah.getKapasitas() * 1.0));
        if (nilai > 4.0) nilai = 4.0;
    }

    /**
     * Menghitung kontribusi ke IP
     * Kontribusi ke IP dihitung dari jumlah sks dikali nilai dibagi total sks
     * 
     * @param sks total sks mahasiswa
     */
    public Double kontribusiIP(int sks) {
        return mataKuliah.getSks() * nilai / (sks * 1.0);
    }
}




/////////////////////MATAKULIAH//////////////////////////



/**
 * MataKuliah.java
 * MataKuliah merupakan sebuah kelas yang memodelkan suatu mata kuliah di ITB
 *
 * @author 18221048 Syafiq Ziyadul Arifin
 */

public class MataKuliah {
    // Deklarasi atribut
    private String kode;
    private String nama;
    private int sks;
    private String dosen;
    private int kapasitas;
    private static int jumlahMataKuliah;

    /**
     * Konstruktor
     * 
     * @param kode
     * @param nama
     * @param sks
     * @param dosen
     * @param kapasitas
     */
    public MataKuliah(String kode, String nama, int sks, String dosen, int kapasitas) {
        this.kode = kode;
        this.nama = nama;
        this.sks = sks;
        this.dosen = dosen;
        this.kapasitas = kapasitas;
        jumlahMataKuliah += 1;
    }

    /**
     * Getter kode
     * 
     * @return kode
     */
    public String getKode() {
        return kode;
    }

    /**
     * Getter nama
     * 
     * @return nama
     */
    public String getNama() {
        return nama;
    }

    /**
     * Getter sks
     * 
     * @return sks
     */
    public int getSks() {
        return sks;
    }

    /**
     * Getter dosen
     * 
     * @return dosen
     */
    public String getDosen() {
        return dosen;
    }

    /**
     * Getter kapasitas
     * 
     * @return kapasitas
     */
    public int getKapasitas() {
        return kapasitas;
    }

    /**
     * Getter jumlah mata kuliah
     * 
     * @return jumlah mata kuliah
     */
    public static int getJumlahMataKuliah() {
        return jumlahMataKuliah;
    }

    /**
     * Menambahkan kapasitas mahasiswa
     * 
     * @param tambahan jumlah kapasitas yang ditambahkan
     */
    public void tambahKapasitas(int tambahan) {
        kapasitas += tambahan;
    }
}







///////////////////////DAFTAR MAHASISWA///////////////////////





/**
 * IPMahasiswa.java
 * IPMahasiswa merupakan sebuah kelas yang mengeluarkan info mahasiswa sesuai input
 * 
 * @author 18221048 Syafiq Ziyadul Arifin
 */

import java.util.Scanner;

public class DaftarMahasiswa {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String nama = scan.next();
        String nim = scan.next();
        int sks = scan.nextInt();
        int sksTambahan = scan.nextInt();
        Mahasiswa mahasiswa = new Mahasiswa(nama, nim, sks);
        System.out.println("Nama mahasiswa: " + mahasiswa.getNama());
        System.out.println("NIM mahasiswa: " + mahasiswa.getNim());
        System.out.println("SKS mahasiswa: " + mahasiswa.getSks());
        System.out.println("Jumlah mahasiswa: " + mahasiswa.getJumlahMahasiswa());
        mahasiswa.tambahSks(sksTambahan);
        System.out.println("Total Revisi SKS mahasiswa: " + mahasiswa.getSks());
        scan.close();
    }
}








////////////////////IP MAHASISWA////////////////////////




/**
 * IPMahasiswa.java
 * IPMahasiswa merupakan sebuah kelas yang memodelkan seorang mahasiswa ITB
 * 
 * @author 18221048 Syafiq Ziyadul Arifin
 */

public class IPMahasiswa {
    // Deklarasi atribut
    private Mahasiswa mahasiswa;
    private Double ipk;

    /**
     * Konstruktor
     * 
     * @param mahasiswa
     * @param ipk
     *                  Apabila ipk > 4.00 atau <= 0.00, maka IPK secara default
     *                  akan diganti menjadi 0.00
     */
    public IPMahasiswa(Mahasiswa mahasiswa, Double ipk) {
        this.mahasiswa = mahasiswa;
        if (ipk <= 0 || ipk > 4) {
            ipk = 0.00;
        }
        this.ipk = ipk;
    }

    /**
     * Getter mahasiswa
     * 
     * @return mahasiswa
     */
    public Mahasiswa getMahasiswa() {
        return mahasiswa;
    }

    /**
     * Getter ipk
     * 
     * @return ipk
     */
    public Double getIPK() {
        return ipk;
    }

    /**
     * Method untuk mengganti IPK
     * 
     * @param ipk sebagai nilai IPK baru
     */
    public void ubahIPK(double ipk) {
        this.ipk = ipk;
    }

    /**
     * Method untuk mengembalikan informasi kemungkinan cumlaude
     * IPK dinyatakan cumlaude apabila >= 3.5
     */
    public Boolean isCumlaude() {
        return ipk >= 3.5;
    }

    /**
     * Method untuk menghitung kemungkinan agar mendapat gelar cumlaude
     * Asumsi: jumlah maksimal SKS satu mahasiswa adalah 144
     * Apabila IPK Cumlaude, maka return 0.0
     * Apabila IPK tidak cumlaude, maka untuk menghitung diffToCumlaude adalah
     * totalCumlaude dikurangi SKS mahasiswa dikali IPK saat ini kemudian dibagi
     * dengan sisa SKS yang dapat diambil
     */
    public Double avgDiffToCumlaude() {
        Double totalCumlaude = 3.5 * 144;

        // Isi dibawah ini
        if (isCumlaude()) {
            return 0.0;
        } else {
            return ((144 * 3.5) - (mahasiswa.getSks() * ipk)) / (144 - mahasiswa.getSks());
        }
    }

}











////////////////////////MAHASISWA/////////////////////////////





/**
 * Mahasiswa.java
 * Mahasiswa merupakan sebuah kelas yang memodelkan seorang mahasiswa ITB
 * 
 * @author 18221048 Syafiq Ziyadul Arifin
 */

public class Mahasiswa {
    // Deklarasi atribut
    private String nama;
    private String nim;
    private int sks;
    private static int jumlahMahasiswa;

    /**
     * Konstruktor
     * 
     * @param nama
     * @param nim
     * @param sks
     */
    public Mahasiswa(String nama, String nim, int sks) {
        this.nama = nama;
        this.nim = nim;
        this.sks = sks;
        jumlahMahasiswa++;
    }

    /**
     * Getter nama
     * 
     * @return nama
     */
    public String getNama() {
        return nama;
    }

    /**
     * Getter nim
     * 
     * @return nim
     */
    public String getNim() {
        return nim;
    }

    /**
     * Getter sks
     * 
     * @return sks
     */
    public int getSks() {
        return sks;
    }

    /**
     * Getter jumlahMahasiswa
     * 
     * @return jumlahMahasiswa yang ada
     */
    public static int getJumlahMahasiswa() {
        return jumlahMahasiswa;
    }

    /**
     * Method untuk menambah sks
     * 
     * @param sks sks yang ditambahkan
     */
    public void tambahSks(int sks) {
        this.sks += sks;
    }
}
