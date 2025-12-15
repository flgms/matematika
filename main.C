#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void TampilkanPesan(){
    printf("\tini adalah program matematika\t");
}

void IniRumusCircle(){
    float r, K, dia, luas;
    float r_f_l, d_f_l;
    float volume, L_P;
    float phi = 3.14;

    printf("\nMasukan R nya : ");

    // bisa pakai if 
    if (scanf("%f", &r) == 1){
        printf("R = %.2f\n", r);
    } else {
        printf("Inputan tidak valid!\n");
        return;
    } 
    //  diameter lingkarannya 
    dia = 2 * r; 
    printf("Diameter Lingkaran adalah : %.2f\n", dia);

    // keliling = K lingkaran 
    K = 2 * phi * r; 
    printf("Keliling nya :  %.2f\n", K);
    
    // luas lingkaran 
    luas = phi * r * r; 
    printf("Luas Lingkaran Adalah : %.2f\n", luas);

    // contoh penggunaan rumus d = C / π
    float dia_dari_K = K / phi; 
    printf("Diameter dari rumus d = C / Phi : %.2f\n", dia_dari_K); // kalau pakai π error
    
    // menambahkan luas A pakai rumus  r = √(A/π) 
    r_f_l = sqrt(luas / phi); 
    printf("jari - jari dari rumus (ini juga pakai akar): %.2f\n", r_f_l);

    // d = √(4A/π)
    d_f_l = sqrt((4 * luas) / phi);
    printf("Diameter dari rumus (yang pakai akar) : %.2f\n", d_f_l);

    // menambahkan volume bola 
    // V = 4/3 π r³
    volume = (4.0 / 3.0) * phi * r * r * r;
    printf("Volume Bola (V = 4/3 * Phi * r^3) : %.2f\n", volume );

    // Lp = 4 π  r²
    L_P = 4 * phi * r * r;
    printf("Luas Permukaan Bola (Lp = 4 * Phi * r^2) : %.2f\n", L_P);

    // V = 2/3 π r^3
    float volume_half = (2.0 / 3.0) * phi * r * r * r;
    printf("Volume 1/2 Bola (V = 2/3 * Phi * r^3) : %.2f\n", volume_half);

    // Lp = 3 π r^2
    float luas_permukaan_half = 3 * phi * r * r;
    printf("Luas Permukaan 1/2 Bola (Lp = 3 * Phi * r^2) : %.2f\n", luas_permukaan_half);

}


void IniRumusLog(){
        printf("\n\t=== VERIFIKASI 17 SIFAT LOGARITMA (Input Manual) ===\t\n");

    double a, b, c, m, n, p;

    // Input a (basis utama)
    printf("Masukkan nilai a (basis logaritma, a > 0 dan a ≠ 1): ");
    if (scanf("%lf", &a) != 1 || a <= 0 || a == 1) {
        printf("Input a tidak valid!\n");
        return;
    }

    // Input b
    printf("Masukkan nilai b (b > 0): ");
    if (scanf("%lf", &b) != 1 || b <= 0) {
        printf("Input b tidak valid!\n");
        return;
    }

    // Input c
    printf("Masukkan nilai c (c > 0): ");
    if (scanf("%lf", &c) != 1 || c <= 0) {
        printf("Input c tidak valid!\n");
        return;
    }

    // Input m (harus ≠ 0 karena muncul di penyebut)
    printf("Masukkan nilai m (m ≠ 0): ");
    if (scanf("%lf", &m) != 1 || m == 0) {
        printf("Input m tidak valid!\n");
        return;
    }

    // Input n
    printf("Masukkan nilai n: ");
    if (scanf("%lf", &n) != 1) {
        printf("Input n tidak valid!\n");
        return;
    }

    // Input p (basis alternatif untuk perubahan basis)
    printf("Masukkan nilai p (basis alternatif, p > 0 dan p ≠ 1): ");
    if (scanf("%lf", &p) != 1 || p <= 0 || p == 1) {
        printf("Input p tidak valid!\n");
        return;
    }

    printf("\n--- Nilai yang digunakan ---\n");
    printf("a = %.2f, b = %.2f, c = %.2f, m = %.2f, n = %.2f, p = %.2f\n\n", a, b, c, m, n, p);

    // Sifat 1: ^a log b = c  <=>  a^c = b
    {
        double c_hasil = log(b) / log(a);
        double b_cek = pow(a, c_hasil);
        printf("1. ^a log b = c  =>  c = %.4f, a^c = %.4f (harus ≈ b = %.2f)\n", c_hasil, b_cek, b);
    }

    // Sifat 2: ^a log a = 1
    {
        double hasil = log(a) / log(a);
        printf("2. ^a log a = %.4f (harus = 1)\n", hasil);
    }

    // Sifat 3: ^a log 1 = 0
    {
        double hasil = log(1.0) / log(a);
        printf("3. ^a log 1 = %.4f (harus = 0)\n", hasil);
    }

    // Sifat 4: ^a log (b^n) = n * ^a log b
    {
        double kiri = log(pow(b, n)) / log(a);
        double kanan = n * (log(b) / log(a));
        printf("4. ^a log(b^%.2f) = %.4f,  %.2f * ^a log b = %.4f\n", n, kiri, n, kanan);
    }

    // Sifat 5: ^a log (b^(1/n)) = (1/n) * ^a log b
    {
        if (n == 0) {
            printf("5. Lewat (n = 0, tidak terdefinisi)\n");
        } else {
            double kiri = log(pow(b, 1.0/n)) / log(a);
            double kanan = (1.0/n) * (log(b) / log(a));
            printf("5. ^a log(b^(1/%.2f)) = %.4f,  (1/%.2f) * ^a log b = %.4f\n", n, kiri, n, kanan);
        }
    }

    // Sifat 6: ^a log (b * c) = ^a log b + ^a log c
    {
        double kiri = log(b * c) / log(a);
        double kanan = (log(b) / log(a)) + (log(c) / log(a));
        printf("6. ^a log(%.2f * %.2f) = %.4f,  ^a log %.2f + ^a log %.2f = %.4f\n", b, c, kiri, b, c, kanan);
    }

    // Sifat 7: ^a log (b / c) = ^a log b - ^a log c
    {
        double kiri = log(b / c) / log(a);
        double kanan = (log(b) / log(a)) - (log(c) / log(a));
        printf("7. ^a log(%.2f / %.2f) = %.4f,  ^a log %.2f - ^a log %.2f = %.4f\n", b, c, kiri, b, c, kanan);
    }

    // Sifat 8: ^a log b = 1 / (^b log a)
    {
        double kiri = log(b) / log(a);
        double kanan = 1.0 / (log(a) / log(b));
        printf("8. ^a log b = %.4f,  1 / (^b log a) = %.4f\n", kiri, kanan);
    }

    // Sifat 9: ^a log b = (^p log b) / (^p log a)
    {
        double kiri = log(b) / log(a);
        double kanan = (log(b) / log(p)) / (log(a) / log(p));
        printf("9. ^a log b = %.4f,  (^%.2f log b)/(^%.2f log a) = %.4f\n", kiri, p, p, kanan);
    }

    // Sifat 10: sama dengan sifat 4 → lewati

    // Sifat 11: ^{a^m} log (b^n) = (n/m) * ^a log b
    {
        double kiri = log(pow(b, n)) / log(pow(a, m));
        double kanan = (n / m) * (log(b) / log(a));
        printf("11. ^{a^%.2f} log(b^%.2f) = %.4f,  (%.2f/%.2f)*^a log b = %.4f\n", m, n, kiri, n, m, kanan);
    }

    // Sifat 12: ^a log b * ^b log c = ^a log c
    {
        double kiri = (log(b)/log(a)) * (log(c)/log(b));
        double kanan = log(c) / log(a);
        printf("12. ^a log b * ^b log c = %.4f,  ^a log c = %.4f\n", kiri, kanan);
    }

    // Sifat 13: a^(^a log b) = b
    {
        double eksponen = log(b) / log(a);
        double hasil = pow(a, eksponen);
        printf("13. a^(^a log b) = %.4f (harus ≈ b = %.2f)\n", hasil, b);
    }

    // Sifat 14: ^a log b = log b / log a (natural vs log10)
    {
        double kiri = log(b) / log(a);
        double kanan = log10(b) / log10(a);
        printf("14. ln(b)/ln(a) = %.4f,  log10(b)/log10(a) = %.4f\n", kiri, kanan);
    }

    // Sifat 15: ^{1/a} log b = - ^a log b
    {
        double kiri = log(b) / log(1.0/a);
        double kanan = - (log(b) / log(a));
        printf("15. ^{1/a} log b = %.4f,  - ^a log b = %.4f\n", kiri, kanan);
    }

    // Sifat 16: ^{a^n} log b = (1/n) * ^a log b
    {
        if (n == 0) {
            printf("16. Lewat (n = 0, tidak terdefinisi)\n");
        } else {
            double kiri = log(b) / log(pow(a, n));
            double kanan = (1.0 / n) * (log(b) / log(a));
            printf("16. ^{a^%.2f} log b = %.4f,  (1/%.2f)*^a log b = %.4f\n", n, kiri, n, kanan);
        }
    }

    // Sifat 17: ^a log b = ^{a^n} log (b^n)
    {
        double kiri = log(b) / log(a);
        double kanan = log(pow(b, n)) / log(pow(a, n));
        printf("17. ^a log b = %.4f,  ^{a^%.2f} log(b^%.2f) = %.4f\n", kiri, n, n, kanan);
    }

    printf("\n✅ Verifikasi selesai! Perbedaan kecil karena pembulatan numerik.\n");
}


int main(){
    // pemanggilan fungsi
    TampilkanPesan();
    IniRumusCircle();
    IniRumusLog();

    printf("\n\tProgram Sudah Beres, Silahkan Bisa Keluar\t\n");

    return 0;
}
