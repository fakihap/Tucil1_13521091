# Tugas Kecil 1 IF2211 Strategi Algoritma
## Permainan Kartu 24
>Permainan kartu 24 adalah permainan kartu aritmatika dengan tujuan mencari cara untuk mengubah 4 buah angka random sehingga mendapatkan hasil akhir sejumlah 24. Permainan Kartu 24 biasa dimainkan dengan menggunakan kartu remi. Kartu remi terdiri dari 52 kartu yang terbagi menjadi empat suit (sekop, hati, keriting, dan wajik) yang masing-masing terdiri dari 13 kartu (As, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, dan King). As bernilai 1, Jack bernilai 11, Queen bernilai 12, King bernilai 13, sedangkan kartu bilangan memiliki nilai dari bilangan itu sendiri. Pada awal permainan moderator atau salah satu pemain mengambil 4 kartu dari dek yang sudah dikocok secara random. Permainan berakhir ketika pemain berhasil menemukan solusi untuk membuat kumpulan nilainya menjadi 24. Pengubahan nilai tersebut dapat dilakukan menggunakan operasi dasar matematika penjumlahan (+), pengurangan (-), perkalian (×), divisi (/) dan tanda kurung ( () ). Tiap kartu harus digunakan tepat sekali dan urutan penggunaannya bebas.

## Struktur File
1. Folder `src` berisi source code
2. Folder `bin` berisi executables
3. Folder `test` berisi solusi jawaban dari data uji yang digunakan dalam laporan
4. Folder `doc` berisi laporan tugas kecil
5. `README.md` untuk deskripsi cara penggunaan program

## Requirement Program
> Untuk memastikan program berjalan dengan baik, pastikan program dijalankan dengan C++ setidaknya versi C++11.

## Cara Kompilasi Program
1. Pastikan terminal berada pada direktori utama
2. Masukkan perintah berikut pada terminal
```shell
> g++ src/main.cpp src/card.cpp src/solver.cpp src/deck.cpp src/expression.cpp -o "./bin/main.exe"
```

## Cara Menjalankan Program
1. Jalankan program `main.exe` yang ada di folder bin
atau
1. Pastikan terminal berada pada direktori utama
2. Masukkan perintah berikut pada terminal setelah kompilasi selesai
```shell
> ./bin/main.exe
```

## Cara Menggunakan Program
1. Perhatikan status kartu saat ini yang ditunjukkan oleh program
2. Untuk memberikan nilai acak pada kartu, masukkan nilai `1` pada prompt sehingga terpilihlah menu `1. Acak Kartu`
3. Untuk memberikan nilai pada kartu secara manual, masukkan nilai `2` pada prompt sehingga terpilih menu `2. Atur Kartu`
	- Masukkan nilai kartu-kartu dengan memberikan 4 nilai angka yang valid, dipisahkan oleh spasi
4. Untuk mencari solusi yang memenuhi, masukkan nilai `0` pada prompt sehingga terpilih menu `0. Cari Solusi`
5. Untuk menyimpan solusi yang sudah dicari, masukkan nilai `3` pada prompt sehingga terpilihlah menu `3. Simpan Solusi`
6. Untuk mengakhiri program, masukkan nilai `99` pada prompt sehingga terpilihlah menu `99. Keluar`

## Author
> [Fakih Anugerah Pratama - 13521091](https://github.com/fakihap/)# Tugas Kecil 1 IF2211 Strategi Algoritma