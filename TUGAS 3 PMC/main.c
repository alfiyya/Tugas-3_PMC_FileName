// 18320041
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

	FILE *filetoRead;

	int JPG, PDF;
	unsigned char signPDF[5] = {0x25, 0x50, 0x44, 0x46, 0x2D};
	unsigned char signJPG[3] = {0xFF, 0xD8, 0xFF};
	unsigned char fileHeader[5], filename[100];

	printf("Masukkan nama file (contoh: 123.pdf):\t");
	scanf("%s", &filename);

	// buka dan file
	filetoRead = fopen(filename, "rb");
	fread(fileHeader, sizeof(fileHeader), 1, filetoRead);


	JPG = memcmp(signJPG, fileHeader, 3);
	PDF = memcmp(signPDF, fileHeader, 5);


	// kasus 1  PDF
	if (PDF == 0) {
		printf("Jenis file PDF\n");

	// kasus 2 JPG
	}
	else if (JPG == 0) {
		printf("Jenis file JPG\n");

	// kasus 3 bukan  keduanya
	}
	else {
		printf("Jenis File tidak terdeteksi\n");
	}

	return 0;
}
