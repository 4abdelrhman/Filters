#include "Image_Class.h"
#include <iostream>
using namespace std;

void infrared()
{
    string ImageName;
    cout << "Please enter the image name with extension : " << endl;
    cin >> ImageName;
    Image image(ImageName);
    // Apply the inverted infrared filter with more red intensity to the image
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            // Invert the color channels
            image(i, j, 0) = 255 - image(i, j, 0); 
            image(i, j, 1) = 255 - image(i, j, 1); 
            image(i, j, 2) = 255 - image(i, j, 2); 
            // Increase the intensity of the red channel more than other channels
            image(i, j, 0) = min(255, image(i, j, 0) + 255); 
            image(i, j, 1) = min(255, image(i, j, 1) + 10); 
            image(i, j, 2) = min(255, image(i, j, 2) + 20); 
        }
    }

    cout << "Image Loaded\n";
    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: \n";
    cin >> ImageName;
    // Save the modified image
    if (image.saveImage(ImageName))
    {
        cout << "Image Saved\n";
    }
}
int main(){
    infrared();
}