#include "Image_Class.h"
#include <iostream>
using namespace std;

void purple() {
    string ImageName;
    cout << "Please enter the image name with extension :\n";
    cin >> ImageName;

  
    Image image(ImageName);

    // Apply the purple filter to the image
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            // Increase the intensity of the red channel to make it more purple
            image(i, j, 0) = min(255, image(i, j, 0) + 50); // Red
            // Decrease the intensity of the green channel to reduce green components
            image(i, j, 1) = max(0, image(i, j, 1) - 30); // Green
            // Increase the intensity of the blue channel to make it more purple
            image(i, j, 2) = min(255, image(i, j, 2) + 50); // Blue
        }
    }


    cout << "Image Loaded\n";
    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: \n";
    cin >> ImageName;

    if (image.saveImage(ImageName)) {
        cout << "Image Saved\n";
    }
}
int main()
{
    purple();
}