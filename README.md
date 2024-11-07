# Sistem e-Toll

## **System Overview**

Sistem e-Toll ini dirancang untuk mengelola dan memverifikasi transaksi tol secara elektronik dengan menggunakan kartu e-Toll. Sistem ini memungkinkan pengguna untuk melakukan tap-in dan tap-out pada gerbang tol, menghitung tarif berdasarkan jarak, serta memproses pembayaran secara otomatis menggunakan saldo yang tersedia di kartu e-Toll.

### **Fitur Utama:**

- **Registrasi Kartu e-Toll**: Pengguna dapat mendaftarkan kartu e-Toll mereka untuk digunakan dalam sistem.
- **Verifikasi Kartu e-Toll**: Sistem memverifikasi validitas kartu e-Toll berdasarkan ID dan saldo yang tersedia.
- **Autentikasi Tap**: Memungkinkan pengguna untuk melakukan tap-in di gerbang tol dan memverifikasi status kartu serta saldo sebelum memasuki gerbang.
- **Perhitungan Jarak**: Sistem menghitung jarak antara dua gerbang tol yang dipilih oleh pengguna berdasarkan data yang telah disimpan.
- **Proses Pembayaran**: Pembayaran otomatis dilakukan berdasarkan jarak yang ditempuh, menggunakan saldo kartu e-Toll yang terdaftar.
- **Status Transaksi**: Sistem menampilkan status transaksi setelah pembayaran, apakah berhasil atau gagal, dan sisa saldo kartu e-Toll.

### **Arsitektur Sistem:**

Sistem ini terdiri dari dua komponen utama:

1. **ETollCard**: Kelas ini mewakili kartu e-Toll yang digunakan oleh pengguna. Setiap kartu memiliki ID, saldo, dan golongan kendaraan yang terkait.
2. **ETollSystem**: Kelas ini berfungsi untuk mengelola transaksi tol, mendaftarkan kartu e-Toll, memverifikasi tap, menghitung tarif berdasarkan jarak, dan memproses pembayaran.

### **Alur Transaksi:**

1. Pengguna memasukkan ID kartu e-Toll dan memilih gerbang tol untuk tap-in.
2. Sistem memverifikasi kartu dan status saldo.
3. Pengguna melakukan tap-out di gerbang tol tujuan.
4. Sistem menghitung jarak antara gerbang awal dan gerbang akhir.
5. Sistem memproses pembayaran berdasarkan jarak yang ditempuh, mengurangi saldo kartu e-Toll jika pembayaran berhasil.
6. Status transaksi ditampilkan, termasuk informasi golongan kendaraan, tarif, sisa saldo, dan status pembayaran.

### **Struktur Program:**

1. **VehicleType.h**: Mendefinisikan enum untuk jenis kendaraan yang digunakan untuk menentukan tarif berdasarkan golongan kendaraan.
2. **ETollCard.h / ETollCard.cpp**: Mewakili kartu e-Toll yang menyimpan informasi ID, saldo, dan golongan kendaraan, serta memiliki fungsi untuk mengurangi saldo saat pembayaran.
3. **ETollSystem.h / ETollSystem.cpp**: Mewakili sistem yang mengelola transaksi tol, termasuk pendaftaran kartu, verifikasi, perhitungan jarak, dan pemrosesan pembayaran.
4. **main.cpp**: Program utama yang menjalankan simulasi transaksi, termasuk interaksi pengguna untuk melakukan tap-in dan tap-out, serta menampilkan status transaksi.

### **Prasyarat Sistem:**

- C++ Compiler (minimal C++14)
- Sistem operasi yang mendukung pengembangan C++ (Windows, Linux, macOS)
- IDE seperti CLion atau Visual Studio Code dengan plugin C++ yang sesuai.

### **Cara Menjalankan Sistem:**

1. Clone repository ini ke mesin lokal Anda.
2. Buka proyek menggunakan IDE yang mendukung C++ (misalnya CLion).
3. Bangun dan jalankan proyek.
4. Ikuti instruksi di terminal untuk melakukan simulasi transaksi e-Toll.
