#include <iostream>
#include <fstream>
using namespace std;
//c4binary file v1 page 14
int main() {
	ifstream xx("Beatles-LetItBe-wav_30s-1.wav", ios::binary | ios::in);
	if (!xx) return 999;  // if the file is not found
	char header[44];
	xx.read(header, 44);
	xx.close();

	unsigned short* nc, * bs;
	unsigned int* sampleRate;
	nc = (unsigned short*)(header + 22);
	sampleRate = (unsigned int*)(header + 24);
	bs = (unsigned short*)(header + 28);
	nc[0] = 1;
	sampleRate[0] = 8000;
	bs[0] = 16;
	ofstream xxx("mywave.wav", ios::binary | ios::out);
	if (!xxx) return 777;
	xxx.write(header, 44);
	const float pi = 3.141592;
	short akbo[8000], A = 10000;
	float f, t, dt = 1. / 8000.;

	f = 392.0; // G sol
	for (int i = 0; i < 8000; i++) {
		akbo[i] = (short)(A * sin(2 * pi * f * i * dt));
	}
	xxx.write((char*)akbo, 8000 * sizeof(short));
	// to
	f = 329.6; // E mi
	for (int i = 0; i < 4000; i++) {
		akbo[i] = (short)(A * sin(2 * pi * f * i * dt));
	}
	xxx.write((char*)akbo, 4000 * sizeof(short));
	// ggi
	f = 329.6; // E mi
	for (int i = 0; i < 4000; i++) {
		akbo[i] = (short)(A * sin(2 * pi * f * i * dt));
	}
	xxx.write((char*)akbo, 4000 * sizeof(short));
	// to
	f = 349.23; // F
	for (int i = 0; i < 8000; i++) {
		akbo[i] = (short)(A * sin(2 * pi * f * i * dt));
	}
	xxx.write((char*)akbo, 8000 * sizeof(short));
	// ggi
	f = 293.66; // D
	for (int i = 0; i < 4000; i++) {
		akbo[i] = (short)(A * sin(2 * pi * f * i * dt));
	}
	xxx.write((char*)akbo, 4000 * sizeof(short));
	// ya
	f = 293.66; // D
	for (int i = 0; i < 4000; i++) {
		akbo[i] = (short)(A * sin(2 * pi * f * i * dt));
	}
	xxx.write((char*)akbo, 4000 * sizeof(short));

	f = 261.63;//C
	for (int i = 0; i < 4000; i++) {
		akbo[i] = (short)(A * sin(2 * pi * f * i * dt));
	}
	xxx.write((char*)akbo, 4000 * sizeof(short));

	f = 293.66;//D
	for (int i = 0; i < 4000; i++) {
		akbo[i] = (short)(A * sin(2 * pi * f * i * dt));
	}
	xxx.write((char*)akbo, 4000 * sizeof(short));

	f = 329.63;//E
	for (int i = 0; i < 4000; i++) {
		akbo[i] = (short)(A * sin(2 * pi * f * i * dt));
	}
	xxx.write((char*)akbo, 4000 * sizeof(short));

	f = 349.23; // F
	for (int i = 0; i < 4000; i++) {
		akbo[i] = (short)(A * sin(2 * pi * f * i * dt));
	}
	xxx.write((char*)akbo, 4000 * sizeof(short));

	f = 392.0; // G sol
	for (int i = 0; i < 4000; i++) {
		akbo[i] = (short)(A * sin(2 * pi * f * i * dt));
	}
	xxx.write((char*)akbo, 4000 * sizeof(short));
	

	f = 392.0; // G sol
	for (int i = 0; i < 4000; i++) {
		akbo[i] = (short)(A * sin(2 * pi * f * i * dt));
	}
	xxx.write((char*)akbo, 4000 * sizeof(short));

	f = 392.0; // G sol
	for (int i = 0; i < 4000; i++) {
		akbo[i] = (short)(A * sin(2 * pi * f * i * dt));
	}
	xxx.write((char*)akbo, 4000 * sizeof(short));

	xxx.close();
	return 1;


}