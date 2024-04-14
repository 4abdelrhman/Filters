#include "Image_Class.h"
#include <iostream>
using namespace std;

void invert()
{
    string ImageName;
    cout << "Please enter the image name with extension : " << endl;
    cin >> ImageName;
    // Load the image
    Image image(ImageName);
    // Invert the colors of the image
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            image(i, j, 0) = 255 - image(i, j, 0);
            image(i, j, 1) = 255 - image(i, j, 1);
            image(i, j, 2) = 255 - image(i, j, 2);
        }
    }
    // Inform the user that the image has been loaded
    cout << "Image Loaded\n";
    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: \n";
    // Get the new image name and extension from the user
    cin >> ImageName;
    // Save the modified image
    if (image.saveImage(ImageName))
    {
        cout << "Image Saved\n";
    }
}
int main ()
{
    invert();
}