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

		unsigned width, height;
		unsigned x, y;
		string filename = ConfigurationManager::getInstance()->getMapPath();//"/home/colman/Documents/manorRoboticsProject/roboticLabMap.png";
		char* secFilename = "/home/colman/Desktop/newMap.png";

		unsigned robotWidth = ConfigurationManager::getInstance()->getRobotWidth();
		unsigned robotHight = ConfigurationManager::getInstance()->getRobotHeight();
		double mapPixel = ConfigurationManager::getInstance()->getMapResolutionCM();
		unsigned widthWeight =(robotWidth/2)/mapPixel;
		unsigned heightWeight = (robotHight/2)/mapPixel;
		unsigned a,b;

		//decode
		unsigned error = lodepng::decode(originalImage, width, height, filename);

		//if there's an error, display it
			if (error)
				std::cout << "decoder error " << error << ": "
				<< lodepng_error_text(error) << std::endl;

				imageWeight.resize(width * height * 4);
				imageWeight = originalImage;
				unsigned char color = 0;

			for (y = 0; y < height; y++)
				for (x = 0; x < width; x++)
				{
					if (!(originalImage[y * width * 4 + x * 4 + 0]
					|| originalImage[y * width * 4 + x * 4 + 1]
					|| originalImage[y * width * 4 + x * 4 + 2]))
					{
						for(a = y-heightWeight; a<y+heightWeight; a++)
							for(b = x-widthWeight; b< x+widthWeight; b++)
							{
								if((a >= 0) && (a<height) && (b >= 0) && (b < width))
								{
									imageWeight[a * width * 4 + b * 4 + 0] = color;
									imageWeight[a * width * 4 + b * 4 + 1] = color;
									imageWeight[a * width * 4 + b * 4 + 2] = color;
									imageWeight[a * width * 4 + b * 4 + 3] = 255;
								}
							}
					}

				}

			//Encode the image
			 error = lodepng::encode(secFilename, imageWeight, width, height);

				//if there's an error, display it
				if (error)
					std::cout << "encoder error " << error << ": "
							<< lodepng_error_text(error) << std::endl;
}

Map::~Map() {
	// TODO Auto-generated destructor stub
}
