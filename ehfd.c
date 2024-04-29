/////////     ACCOUNT ///////////////////



/**
 * Account.java
 * Account adalah sebuah kelas yang merepresentasikan akun (rekening) bank di dunia nyata
 * 
 * @author 18221048 Syafiq Ziyadul Arifin
 */

/**
 * Jangan lupa tambahkan kata kunci untuk menghandle exception
 */

public class Account {
    /**
     * Tambahkan atribut kelas disini
     */
    private String name;
    private String bankName;
    private int saldo;

    public Account(String name, String bankName, int saldo) throws Exception {
        /**
         * Konstruktor
         * Jangan lupa inisialisasi atribut kelas
         */
        if (name.length() < 3)
            throw new Exception("Nama akun harus memiliki panjang minimal 3 karakter");
        else {
            if (saldo < 0)
                throw new Exception("Tidak dapat membuat akun dengan saldo dibawah 0");
            else {
                this.name = name;
                this.bankName = bankName;
                this.saldo = saldo;
            }
        }
    }

    public String getBankName() {
        /**
         * Implementasi
         * Return bankName
         */
        return bankName;
    }

    public String getName() {
        /**
         * Implementasi
         * Return name
         */
        return name;
    }

    public void setName(String name) throws Exception {
        /**
         * Implementasi
         * Ubah name
         * 
         * Sebuah name memiliki ketentuan yaitu memiliki panjang minimal 3 karakter.
         * Apabila tidak memenuhi ketentuan ini,
         * akan dilempar sebuah exception dengan pesan "Nama akun harus memiliki panjang
         * minimal 3 karakter".
         */
        if (name.length() < 3)
            throw new Exception("Nama akun harus memiliki panjang minimal 3 karakter");
        else this.name = name;
    }

    public int getSaldo() {
        /**
         * Implementasi
         * Return saldo
         */
        return saldo;
    }

    public void decreaseSaldo(int jumlah) throws Exception {
        /**
         * Implementasi
         * Kurangi jumlah saldo
         * 
         * Apabila jumlah saldo tidak mencukupi untuk melakukan operasi,
         * dilemparkan exception dengan pesan "Saldo tidak mencukupi".
         * 
         * Apabila parameter jumlah kurang dari 0,
         * lempar exception dengan pesan "Jumlah pengurangan tidak boleh minus".
         */
        if (saldo < jumlah)
            throw new Exception("Saldo tidak mencukupi");
        else {
            if (jumlah < 0)
                throw new Exception("Jumlah pengurangan tidak boleh minus");
            else saldo -= jumlah;
        }
    }

    public void increaseSaldo(int jumlah) throws Exception {
        /**
         * Implementasi
         * Tambahi saldo
         * 
         * Apabila parameter jumlah kurang dari 0,
         * lempar exception dengan pesan "Jumlah penambahan tidak boleh minus".
         */
        if (jumlah < 0)
            throw new Exception("Jumlah penambahan tidak boleh minus");
        else saldo += jumlah;
    }
}


////////////// BANK ////////////////////////////////////





/**
 * Bank.java
 * Bank adalah sebuah kelas yang dapat mensimulasikan cara kerja bank secara sederhana
 * 
 * @author 18221048 Syafiq Ziyadul Arifin
 */

public class Bank {
    /**
     * Tambahkan atribut kelas disini
     */
    private String name;

    public Bank(String name) {
        /**
         * Konstruktor
         * Jangan lupa inisialisasi atribut kelas
         */
        this.name = name;
    }

    public void transfer(Account accountFrom, Account accountTo, int jumlah) throws Exception {
        /**
         * Implementasi
         * Transfer antar bank (akun dengan nama bank berbeda) akan dikenakan biaya
         * admin sebesar
         * 2500 yang dikurangi dari saldo pengirim.
         * 
         * Biaya admin ini tidak ikut ditransfer ke akun tujuan.
         * 
         * Apabila accountFrom memiliki nama bank yang tidak sama dengan bank yang
         * melakukan transfer,
         * lempar exception dengan pesan "Bukan akun milik bank {bankName}".
         */
        if (name.equals(accountFrom.getBankName())) {
            accountFrom.decreaseSaldo(jumlah);
            accountTo.increaseSaldo(jumlah);
            if (!accountFrom.getBankName().equals(accountTo.getBankName())) accountFrom.decreaseSaldo(2500);
        } else
            throw new Exception(String.format("Bukan akun milik bank %s", name));
    }

    public Account createAccount(String accountName, int saldo) throws Exception {
        /**
         * Implementasi
         * Akun yang dibuat akan memiliki atribut bankName dengan nama bank yang membuat
         * akun.
         * Method ini akan melanjutkan pelemparan exception dari kelas Account.
         */
        try {
            Account acc = new Account(accountName, name, saldo);
            return acc;
        } catch (Exception e) {
            System.out.println(e.getMessage());
            throw new Exception(e);
        }
    }
}








//////////////////EMAIL/////////////////////////////////




/**
 * Email.java
 * Email adalah sebuah kelas yang digunakan untuk melakukan validasi email
 * 
 * @author 18221048 Syafiq Ziyadul Arifin
 */

public class Email {
    private String email;

    public Email(String email) {
        this.email = email;
    };

    public boolean validateEmail() throws InvalidEmailException, InvalidDomainException {
        /**
         * Implementasi dengan aturan:
         * Aturan email
         * - Email harus mengandung tepat 1 karakter @ ditengah email
         * - Bagian sebelum @ tidak boleh kosong
         * - Bagian email setelah @ harus memiliki tepat 1 buah titik (.)
         * - Email hanya akan mengandung huruf, angka, (@), dan (.). Karakter lain tidak
         * perlu diperiksa
         * 
         * "john@example.com" => Email Valid
         * "jane.doe@gmail.com" => Email Valid
         * "" => mengembalikan pesan "Email tidak boleh kosong"
         * "example.com" => mengembalikan pesan "Email harus mengandung tepat satu
         * buah @"
         * "@example.com" => mengembalikan pesan "@ tidak boleh di awal email"
         * "john@com" => mengembalikan pesan "Email harus memiliki domain yang valid"
         */
        if (email.isEmpty())
            throw new InvalidEmailException("Email tidak boleh kosong");

        int atIndex = email.indexOf('@');
        if (atIndex == 0)
            throw new InvalidEmailException("@ tidak boleh di awal email");
        else if (atIndex == -1 || email.indexOf('@', atIndex + 1) != -1)
            throw new InvalidEmailException("Email harus mengandung tepat satu buah @");

        int dotIndex = email.indexOf('.', atIndex);
        if (dotIndex == -1 || dotIndex == atIndex + 1 || dotIndex == email.length() - 1
                || email.indexOf('.', dotIndex + 1) != -1)
            throw new InvalidDomainException();

        return true;
    }
}

class InvalidEmailException extends Exception {
    private String message;

    public InvalidEmailException(String message) {
        // Implementasi InvalidEmailException
        this.message = message;
    }

    public String getMessage() {
        return message;
    }
}

class InvalidDomainException extends Exception {
    public String getMessage() {
        // Implementasi custom message InvalidDomainException
        // Return pesan multak berisi: "Email harus memiliki domain yang valid
        return "Email harus memiliki domain yang valid";
    }
}









///////////////// MAIN EMAIL /////////////////////////////////





/**
 * Main.java
 * Main adalah sebuah kelas yang merupakan driver (program utama) yang menerima
 * sebuah string email lalu memvalidasinya
 * 
 * @author 18221048 Syafiq Ziyadul Arifin
 */

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Hint 1: Untuk mendapatkan input dari user, umumnya bisa dengan memasukkan
        // parameter System.in
        // ke dalam konstruktor Scanner.
        try {
            Scanner scan = new Scanner(System.in);
            Email email = new Email(scan.next());
            if (email.validateEmail()) {
                System.out.println("true");
                System.out.println("Email validated.");
            }
            scan.close();
        } catch (InvalidEmailException e) {
            System.out.println("InvalidEmailException! " + e.getMessage());
            System.out.println("Email string error!");
        } catch (InvalidDomainException e) {
            System.out.println("InvalidDomainException! " + e.getMessage());
            System.out.println("Email string error!");
        } finally {
            System.out.println("Operation finished.");
        }
    }
}








////////////// CALCULATOR ///////////////////





/**
 * Calculator.java
 * Calculator adalah sebuah kelas yang merepresentasikan kalkulator di dunia
 * nyata dan bisa menerima kalkulasi sederhana
 * 
 * @author 18221048 Syafiq Ziyadul Arifin
 */

public class Calculator {
    public Calculator() {
    };

    public double calculate(double a, double b, String operation)
            throws InvalidOperationException, InvalidDivisionByZero {
        /**
         * Implementasi
         * Apabila operasi yang diinput pengguna bukan `+`, `-`, `*`, atau `/`, maka
         * kalkulator akan mengembalikan pesan error dari kelas
         * `InvalidOperationException.java`
         * 
         * Apabila kalkulator menerima input pembagian terhadap 0, maka kalkulator juag
         * akan mengembalikan pesan error dari kelas `InvalidDivisionByZero.java`
         */
        if (operation.equals("+")) return a + b;
        else if (operation.equals("-")) return a - b;
        else if (operation.equals("*")) return a * b;
        else if (operation.equals("/"))
            if (b == 0)
                throw new InvalidDivisionByZero();
            else return a / b;
        else
            throw new InvalidOperationException(operation);
    }
}

class InvalidOperationException extends Exception {
    private String operation;

    public InvalidOperationException(String operation) {
        // Implementasi InvalidOperationException
        this.operation = operation;
    }

    public String getMessage() {
        // Implementasi custom message InvalidOperationException
        // Format: "Invalid operation: " + operation
        return "Invalid operation: " + operation;
    }
}

class InvalidDivisionByZero extends Exception {
    public InvalidDivisionByZero() {
        // Implementasi InvalidDivisionByZero
    }

    public String getMessage() {
        // Implementasi custom message InvalidDivisionByZero
        // Format: "Tidak dapat melakukan pembagian terhadap 0"
        return "Tidak dapat melakukan pembagian terhadap 0";
    }
}







/////////////////// MAIN CALCULATOR ////////////////////////






/**
 * Main.java
 * Main adalah sebuah kelas yang merupakan driver (program utama) yang menerima
 * perintah untuk melakukan kalkulasi sederhana
 * 
 * @author 18221048 Syafiq Ziyadul Arifin
 */

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Hint 1: Untuk mendapatkan input dari user, umumnya bisa dengan memasukkan
        // parameter System.in
        // ke dalam konstruktor Scanner.
        // Hint 2: Pengambilan double dari input bisa menggunakan method nextDouble()
        // dari scanner
        // Namun perlu diperhatikan bahwa nextDouble() tidak mengkonsumsi newline
        // karakter dari input
        // Sehingga apabila ingin menggunakan method nextLine() untuk mengambil String
        // setelah pemanggilan method nextDouble(), harus memanggil nextLine() dahulu
        // untuk menghabisi sisa baris input dari nextDouble().
        try {
            Calculator calc = new Calculator();
            Scanner scan = new Scanner(System.in);
            double a = scan.nextDouble();
            double b = scan.nextDouble();
            scan.nextLine();
            String op = scan.nextLine();
            System.out.println(calc.calculate(a, b, op));
            scan.close();
        } catch (InvalidDivisionByZero e) {
            System.out.println(String.format("InvalidDivisionByZero! %s", e.getMessage()));
        } catch (InvalidOperationException e) {
            System.out.println(String.format("InvalidOperationException! %s", e.getMessage()));
        } catch (Exception e) {
            System.out.println("Unknown exception!");
        } finally {
            System.out.println("Calculated.");
        }
    }

}







////////////////////////// ROBOT ////////////////////





/**
 * Robot.java
 * Robot adalah sebuah kelas yang dapat menerima perintah untuk melakukan aksi
 * 
 * @author 18221048 Syafiq Ziyadul Arifin
 */

/**
 * Jangan lupa tambahkan kata kunci untuk menghandle exception
 */
public class Robot extends Exception {
    /**
     * Tambahkan atribut kelas disini
     */
    private int x;
    private int y;

    public Robot() {
        /**
         * Konstruktor
         * Jangan lupa inisialisasi atribut kelas
         */
        x = 0;
        y = 0;
    }

    public void walk(int x, int y) throws Exception {
        /**
         * Implementasi
         * Apabila hasil penambahan x atau y melebihi 10, dilempar sebuah exception
         * dengan pesan "Tidak bisa jalan". Atribut tidak ditambahkan pada kasus ini.
         * 
         * Apabila input valid, tambahkan nilai atribut dan print pesan
         * "Sedang berjalan menuju (x, y)"
         */
        if ((this.x + x > 10) || (this.y + y > 10))
            throw new Exception(String.format("Tidak bisa jalan"));
        else {
            this.x += x;
            this.y += y;
            System.out.println(String.format("Sedang berjalan menuju (%d, %d)", x, y));
        }
    }

    public void talk(String language) throws Exception {
        /**
         * Implementasi
         * Apabila input bukan "Indonesia" atau "Inggris", lempar exception dengan pesan
         * "Tidak bisa berbicara dalam bahasa {language}"
         * 
         * Apabila input valid, print pesan "Sedang berbicara dalam bahasa {language}"
         */
        if (language.equals("Indonesia") || language.equals("Inggris"))
            System.out.println(String.format("Sedang berbicara dalam bahasa %s", language));
        else
            throw new Exception(String.format("Tidak bisa berbicara dalam bahasa %s", language));
    }

    public void receiveCommand(String command) throws Exception {
        /**
         * Implementasi
         * Apabila input bukan "walk" atau "talk", lempar exception "Perintah {command}
         * tidak dikenal"
         */
        if (!command.equals("walk") && !command.equals("talk"))
            throw new Exception(String.format("Perintah %s tidak dikenal", command));
    }
}
