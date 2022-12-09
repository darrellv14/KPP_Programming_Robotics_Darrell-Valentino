// NAMA		: DARRELL VALENTINO
// NRP		: 5026221086
// Jurusan	: Sistem Informasi

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

#define GRAVITASI 10 //10 m/s^2
#define START_PENGUKURAN 1 //pengukuran dimulai dari 1 meter
#define SUDUT 45 //sudut elevasi tembakan
#define PHI 3.14159 // Nilai Phi

int speed_dgn_loss(int Vtangensial_roller)
{
	/* tulis fungsi hitung_loss kalian disini */
    int losses;
    if(Vtangensial_roller >= 1 && Vtangensial_roller <= 10){
        losses = 1;
    }else if(Vtangensial_roller >= 11 && Vtangensial_roller <= 20){
        losses = 3;
    }else if(Vtangensial_roller >= 21 && Vtangensial_roller <= 30){
        losses = 5;
    }else if(Vtangensial_roller > 30){
        exit(0);
    }
    return losses; 
}

int mencari_V0(int Vtangensial_roller)
{
	/* Tulis fungsi mencari v0 kalian disini */
  	return Vtangensial_roller - speed_dgn_loss(Vtangensial_roller);
}

int main() {
  	/* input adalah kecepatan tangensial maksimum roller */
    int Vtangensial;
    float jarak, V0, Vtangensial_hasil, alpha;
    std::cin >> Vtangensial;
    
    /* tulis kode utama kalian disini */
    V0 = mencari_V0(Vtangensial);
    alpha = SUDUT*PHI/180;
    jarak=((pow(V0, 2)*sin(2*alpha))/GRAVITASI);
    Vtangensial_hasil = Vtangensial-(0.1002);
  	std::cout << floor(jarak) << " " << Vtangensial_hasil  << std::endl;

    return 0;
}