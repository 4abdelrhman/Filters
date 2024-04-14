#include "Image_Class.h"
#include <iostream>
using namespace std;
void blur()
{
    int red, green, blue, n;
    string ImageName;
    cout << "Please enter the image name with extension : " << endl;
    cin >> ImageName;
    cout << "enter the dgree of blurring" << endl;
    cin >> n;
    Image image(ImageName);

    for (int i = 1; i <= n; i++)
    {

        for (int i = 1; i < image.width; ++i)
        {
            for (int j = 1; j < image.height; ++j)
            {
                // Calculate the average RGB values of the surrounding pixels
                red = (image(i - 1, j - 1, 0) + image(i - 1, j, 0) + image(i, j - 1, 0) + image(i - 1, j + 1, 0) + image(i + 1, j - 1, 0) + image(i + 1, j, 0) + image(i, j + 1, 0) + image(i + 1, j + 1, 0) + image(i, j, 0)) / 9;
                green = (image(i - 1, j - 1, 1) + image(i - 1, j, 1) + image(i, j - 1, 1) + image(i - 1, j + 1, 1) + image(i + 1, j - 1, 1) + image(i + 1, j, 1) + image(i, j + 1, 1) + image(i + 1, j + 1, 1) + image(i, j, 1)) / 9;
                blue = (image(i - 1, j - 1, 2) + image(i - 1, j, 2) + image(i, j - 1, 2) + image(i - 1, j + 1, 2) + image(i + 1, j - 1, 2) + image(i + 1, j, 2) + image(i, j + 1, 2) + image(i + 1, j + 1, 2) + image(i, j, 2)) / 9;

                // Update the pixel values with the average RGB values
                image(i, j, 0) = red;
                image(i, j, 1) = green;
                image(i, j, 2) = blue;
            }
        }
    }




    cout << "Image Loaded\n";
    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: \n";
    cin >> ImageName;

    if (image.saveImage(ImageName))
    {
        cout << "Image Saved\n";
    }
}
int main()
{
blur();
}