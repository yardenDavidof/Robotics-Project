#include "Map.h"

Map::Map() {
	for (int i = 0; i < HEIGHT_IN_CENTIMETERS; i++) {
		for (int j = 0; j < WIDTH_IN_CENTIMETERS; j++) {
			map[i][j] = UNKOWNN_CELL;
		}
	}
}


void Map::updateMap(int row, int column, int value) {
	map[row][column] = value;
}

int Map::getCellType(int row, int column) {
	return map[row][column];
}

void Map::getPosition(float x, float y, int &x1, int &y1) {
	x1 = ((int)x) / RESOLUTION_IN_CENTIMTERS + HEIGHT_IN_CENTIMETERS / 2;
	y1 = ((int)y) / RESOLUTION_IN_CENTIMTERS + WIDTH_IN_CENTIMETERS / 2;
}

/**
void Map::printMap() {
	FILE *f;
	unsigned char *img = NULL;
	int fileSize = 54 + 3 * WIDTH_IN_CENTIMETERS * HEIGHT_IN_CENTIMETERS;

	img = (unsigned char *) malloc(3 * WIDTH_IN_CENTIMETERS * HEIGHT_IN_CENTIMETERS);
	memset(img, 0, sizeof(img));

	for (int i = 0; i < WIDTH_IN_CENTIMETERS; i++) {
		for (int j = 0; j < HEIGHT_IN_CENTIMETERS; j++) {
			RGB* color = getCellColor(i,j);

			int x = i;
			int y = (HEIGHT_IN_CENTIMETERS - 1) - j;

			img[(x + y * WIDTH_IN_CENTIMETERS) * 3 + 2] = (unsigned char) color->red;
			img[(x + y * WIDTH_IN_CENTIMETERS) * 3 + 1] = (unsigned char) color->green;
			img[(x + y * WIDTH_IN_CENTIMETERS) * 3 + 0] = (unsigned char) color->blue;
		}
	}

	unsigned char bmpFileHeader[14] = { 'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54,
			0, 0, 0 };
	unsigned char bmpInfoHeader[40] = { 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			0, 24, 0 };
	unsigned char bmpPad[3] = { 0, 0, 0 };

	bmpFileHeader[2] = (unsigned char) (fileSize);
	bmpFileHeader[3] = (unsigned char) (fileSize >> 8);
	bmpFileHeader[4] = (unsigned char) (fileSize >> 16);
	bmpFileHeader[5] = (unsigned char) (fileSize >> 24);

	bmpInfoHeader[4] = (unsigned char) (WIDTH_IN_CENTIMETERS);
	bmpInfoHeader[5] = (unsigned char) (WIDTH_IN_CENTIMETERS >> 8);
	bmpInfoHeader[6] = (unsigned char) (WIDTH_IN_CENTIMETERS >> 16);
	bmpInfoHeader[7] = (unsigned char) (WIDTH_IN_CENTIMETERS >> 24);
	bmpInfoHeader[8] = (unsigned char) (WIDTH_IN_CENTIMETERS);
	bmpInfoHeader[9] = (unsigned char) (WIDTH_IN_CENTIMETERS >> 8);
	bmpInfoHeader[10] = (unsigned char) (WIDTH_IN_CENTIMETERS >> 16);
	bmpInfoHeader[11] = (unsigned char) (WIDTH_IN_CENTIMETERS >> 24);

	f = fopen("/home/user/Desktop/map.bmp", "wb");
	fwrite(bmpFileHeader, 1, 14, f);
	fwrite(bmpInfoHeader, 1, 40, f);

	for (int i = 0; i < HEIGHT_IN_CENTIMETERS; i++) {
		fwrite(img + (WIDTH_IN_CENTIMETERS * (HEIGHT_IN_CENTIMETERS - i - 1) * 3), 3, WIDTH_IN_CENTIMETERS, f);
		fwrite(bmpPad, 1, (4 - (WIDTH_IN_CENTIMETERS * 3) % 4) % 4, f);
	}

	if (img) {
		free(img);
	}

	fclose(f);
}
*/
RGB* Map::getCellColor(int i, int j)
{
	int state = getCellType(i, j);

	switch(state){
		case(FREE_CELL): {
			return new RGB(255, 255, 255);
			break;
		}
		case(UNKOWNN_CELL):{
			return new RGB(130, 130, 130);
			break;
		}
		case(BLOCKED_CELL): {
			return new RGB(0, 0, 0);
			break;
		}
		case(ROBOT_CURRENT_CELL):{
			return new RGB(255, 0, 0);
			break;
		}
		default:{
			return new RGB(130, 130, 130);
		}
	}
}

Map::~Map() {
}
