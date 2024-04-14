#include "Image_Class.h"
#include <iostream>
using namespace std;
void mergeImages() {
    string ImageName1, ImageName2;
    cout << "Please enter the first image name: ";
    cin >> ImageName1;
    Image image1(ImageName1);
    cout << "Please enter the second image name: ";
    cin >> ImageName2;
    Image image2(ImageName2);
    int ImageWidth = min(image1.width, image2.width);
    int ImageHeight = min(image1.height, image2.height);
    Image merge(ImageWidth, ImageHeight);
    for(int i = 0; i < ImageWidth; ++i) {
        for(int j = 0; j < ImageHeight; ++j) {
            for(int k = 0; k < 3; ++k) {
                merge(i,j,k) = ( ImageName1(i,j,k) + ImageName2(i,j,k) ) / 2;
            }
        }
    }
    string output;
    cout << "Please enter the name to store the new merged image (with extension .jpg, .bmp, .png, .tga): ";
    cin >> output;
    merge.saveImage(output);
}
int main(){
    mergeImages();
    return 0;
}













/*#include "Image_Class.h"

// Function to create a sketch-like effect by enhancing edges
void enhanceEdges(const std::string& inputFilename, const std::string& outputFilename) {
    // Load the original image
    Image originalImage(inputFilename);
    // Create a copy of the original image for processing
    Image processedImage(originalImage.width, originalImage.height);
    // Convert the original image to grayscale
    Image grayscaleImage(originalImage.width, originalImage.height);
    for (int y = 0; y < originalImage.height; ++y) {
        for (int x = 0; x < originalImage.width; ++x) {
            // Calculate grayscale value using average of RGB channels
            unsigned char grayValue = (originalImage(x, y, 0) + originalImage(x, y, 1) + originalImage(x, y, 2)) / 3;
            // Set grayscale value for each channel
            grayscaleImage(x, y, 0) = grayValue;
            grayscaleImage(x, y, 1) = grayValue;
            grayscaleImage(x, y, 2) = grayValue;
        }
    }
    // Apply Sobel edge detection
    // Approximate edge detection by calculating the difference in intensity between adjacent pixels
    for (int y = 1; y < grayscaleImage.height - 1; ++y) {
        for (int x = 1; x < grayscaleImage.width - 1; ++x) {
            // Calculate gradient magnitude using Sobel operator
            int gradientX = grayscaleImage(x + 1, y - 1, 0) - grayscaleImage(x - 1, y - 1, 0)
                            + 2 * (grayscaleImage(x + 1, y, 0) - grayscaleImage(x - 1, y, 0))
                            + grayscaleImage(x + 1, y + 1, 0) - grayscaleImage(x - 1, y + 1, 0);
            int gradientY = grayscaleImage(x - 1, y + 1, 0) - grayscaleImage(x - 1, y - 1, 0)
                            + 2 * (grayscaleImage(x, y + 1, 0) - grayscaleImage(x, y - 1, 0))
                            + grayscaleImage(x + 1, y + 1, 0) - grayscaleImage(x + 1, y - 1, 0);
            int gradientMagnitude = abs(gradientX) + abs(gradientY);
            // Threshold the gradient magnitude to enhance edges
            if (gradientMagnitude > 128) { // Adjust threshold as needed
                // Set pixel to black to enhance edge
                processedImage(x, y, 0) = 0;
                processedImage(x, y, 1) = 0;
                processedImage(x, y, 2) = 0;
            } else {
                // Set pixel to white for non-edge regions
                processedImage(x, y, 0) = 255;
                processedImage(x, y, 1) = 255;
                processedImage(x, y, 2) = 255;
            }
        }
    }
    // Save the resulting image
    processedImage.saveImage(outputFilename);
}

int main() {
    // Provide input and output filenames
    std::string inputFilename = "photographer.bmp";
    std::string outputFilename = "sketch_like_image.jpg";
    // Create the sketch-like effect by enhancing edges
    enhanceEdges(inputFilename, outputFilename);
    return 0;
}*/