#include "Image_Class.h"
#include <iostream>
using namespace std;
void black_and_white()
{
    string ImageName;
    cout << "Please enter the image name  : " << endl;
    cin >> ImageName;
    // Load the image with the given name
    Image image(ImageName);
    // Iterate over each pixel in the image
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            int avg = (image(i, j, 0) + image(i, j, 1) + image(i, j, 2)) / 3;
            // If the average intensity is greater than 127, set the pixel to white; otherwise, set it to black
            if (avg > 127) {
                image(i, j, 0) = 250;
                image(i, j, 1) = 250;
                image(i, j, 2) = 250;
            }
            else {
                image(i, j, 0) = 0;
                image(i, j, 1) = 0;
                image(i, j, 2) = 0;
            }
        }
    }
    // Inform the user that the image has been loaded
    cout << "Image Loaded\n";
    // Prompt the user to enter the name for the new image and its extension
    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> ImageName;
    // Save the modified image with the new name
    if (image.saveImage(ImageName)) {
        cout << "Image Saved\n";
    }
}
int main()
{
    black_and_white();
}