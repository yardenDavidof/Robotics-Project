/*
 * Map.cpp
 *
 *  Created on: Jun 2, 2015
 *      Author: colman
 */

#include "Map.h"

Map::Map() {
	// TODO Auto-generated constructor stub

}

 void Map::readPNG(){

	std::vector<unsigned char> image; //the raw pixels
		unsigned width, height;
		unsigned x, y;
		// TODO: get file name from the configuration
		char* filename = "/home/colman/Documents/manorRoboticsProject/roboticLabMap.png";
		char* secFilename = "/home/colman/Documents/manorRoboticsProject/newMap.png";

		//TODO:calculate it: (robotSize\2)\pixelCM
		unsigned widthWeight =6, heightWeight = 6;
		unsigned a,b;

		//decode
		unsigned error = lodepng::decode(image, width, height, filename);

		//if there's an error, display it
			if (error)
				std::cout << "decoder error " << error << ": "
				<< lodepng_error_text(error) << std::endl;

			std::vector<unsigned char> navImage; //the raw pixels
				navImage.resize(width * height * 4);
				navImage = image;
				unsigned char color = 0;

			for (y = 0; y < height; y++)
				for (x = 0; x < width; x++)
				{
					if (!(image[y * width * 4 + x * 4 + 0]
					|| image[y * width * 4 + x * 4 + 1]
					|| image[y * width * 4 + x * 4 + 2]))
					{
						for(a = y-heightWeight; a<y+heightWeight; a++)
							for(b = x-widthWeight; b< x+widthWeight; b++)
							{
								if((a >= 0) && (a<height) && (b >= 0) && (b < width))
								{
									navImage[a * width * 4 + b * 4 + 0] = color;
									navImage[a * width * 4 + b * 4 + 1] = color;
									navImage[a * width * 4 + b * 4 + 2] = color;
									navImage[a * width * 4 + b * 4 + 3] = 255;
								}
							}
					}

				}

			//Encode the image
			 error = lodepng::encode(secFilename, navImage, width, height);

				//if there's an error, display it
				if (error)
					std::cout << "encoder error " << error << ": "
							<< lodepng_error_text(error) << std::endl;
}

Map::~Map() {
	// TODO Auto-generated destructor stub
}

