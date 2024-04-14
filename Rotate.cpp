#include "Image_Class.h"
#include <iostream>
using namespace std;

void rotate()
{
    string ImageName;
    cout << "Please enter the image name with extension : " << endl;
    cin >> ImageName;
    // Load the image with the given name
    Image image(ImageName);
    // Display rotation options to the user
    cout << "1) 90 degrees" << endl << "2) 180 degrees" << endl << "3) 270 degrees" << endl;
    int r;
    cin >> r;
    if (r == 1) {
        // Create a new image with swapped width and height
        Image rotatedImage(image.height, image.width);
        // Rotate by 90 degrees
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                // Rotate the pixel by 90 degrees clockwise
                rotatedImage(image.height - 1 - j, i, 0) = image(i, j, 0);
                rotatedImage(image.height - 1 - j, i, 1) = image(i, j, 1);
                rotatedImage(image.height - 1 - j, i, 2) = image(i, j, 2);
            }
        }
        cout << "Image Loaded\n";
        cout << "Please enter the image name to store the rotated image\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga: \n ";
        cin >> ImageName;
        if (rotatedImage.saveImage(ImageName)) {
            cout << "Image Saved\n";
        }
    }
    else if (r == 2) {
        // Create a new image with the same dimensions as the original image
        Image rotatedImage(image.width, image.height);
        // Rotate by 180 degrees
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                // Rotate the pixel by 180 degrees clockwise
                rotatedImage(image.width - 1 - i, image.height - 1 - j, 0) = image(i, j, 0);
                rotatedImage(image.width - 1 - i, image.height - 1 - j, 1) = image(i, j, 1);
                rotatedImage(image.width - 1 - i, image.height - 1 - j, 2) = image(i, j, 2);
            }
        }
        cout << "Image Loaded\n";
        cout << "Please enter the image name to store the rotated image\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga: \n";
        cin >> ImageName;
        if (rotatedImage.saveImage(ImageName)) {
            cout << "Image Saved\n";
        }
    }
    else if (r == 3) {
        // Create a new image with swapped width and height
        Image rotatedImage(image.height, image.width);
        // Rotate by 270 degrees
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                // Rotate the pixel by 270 degrees clockwise
                rotatedImage(j, image.width - 1 - i, 0) = image(i, j, 0);
                rotatedImage(j, image.width - 1 - i, 1) = image(i, j, 1);
                rotatedImage(j, image.width - 1 - i, 2) = image(i, j, 2);
            }
        }
        cout << "Image Loaded\n";
        cout << "Please enter the image name to store the rotated image\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga: \n ";
        cin >> ImageName;
        if (rotatedImage.saveImage(ImageName)) {
            cout << "Image Saved\n";
        }
    }
}
int main(){
    rotate();
}