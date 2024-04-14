#include "Image_Class.h"
#include <iostream>
using namespace std;
void Resized(){
    string ImageName;
    cout << "Please enter the image name with extension : " << endl;
    cin >> ImageName;
    Image image(ImageName);
    int newWidth, newHeight;
        cout << "Enter the new width and the new height : ";
        cin >> newWidth >> newHeight;
    Image resizedImage(newWidth, newHeight);
    float xR = static_cast<float>(image.width - 1) / newWidth;
    float yR = static_cast<float>(image.height - 1) / newHeight;
    for (int i = 0; i < newWidth; ++i)
    {
        for (int j = 0; j < newHeight; ++j)
        {
            int x = static_cast<int>(xR * i);
            int y = static_cast<int>(yR * j);
            resizedImage(i, j, 0) = image(x, y, 0);
            resizedImage(i, j, 1) = image(x, y, 1);
            resizedImage(i, j, 2) = image(x, y, 2);
        }
    }
    cout << "Image Resized\n";
    cout << "Please enter the image name to store the new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: \n";
    cin >> ImageName;
    if (resizedImage.saveImage(ImageName))
    {
        cout << "Image Saved\n";
    }
}
int main()
{
    Resized();
}