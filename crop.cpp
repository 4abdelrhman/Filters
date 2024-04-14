#include "Image_Class.h"
#include <iostream>

using namespace std;
void crop()
{
    int x, y, width, height;
    string ImageName;
    cout << "Please enter the image name with extension : " << endl;
    cin >> ImageName;
    Image image(ImageName);
    cout << "Enter the x coordinate and y coordinate of the starting point from corner: ";
    cin >> x >> y;
    cout << "Enter the width and the height of the area to crop: ";
    cin >> width >> height;
    Image editedImage(width, height);
    // Iterate over each pixel in the editedImage
    for (int i = 0; i < width; ++i)
    {
        for (int j = 0; j < height; ++j)
        {
            // Copy the RGB values from the corresponding position in the original image to the editedImage
            editedImage(i, j, 0) = image(i + x, j + y, 0); 
            editedImage(i, j, 1) = image(i + x, j + y, 1);
            editedImage(i, j, 2) = image(i + x, j + y, 2); 
        }
    }

    cout << "Image Loaded\n";
    cout << "Please enter the image name to store the new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: \n";
    cin >> ImageName;

    if (editedImage.saveImage(ImageName))
    {
        cout << "Image Saved\n";
    }
}
int main()
{
    crop();
}