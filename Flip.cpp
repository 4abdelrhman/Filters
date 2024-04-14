#include "Image_Class.h"
#include <iostream>
using namespace std;

void flip()
{
    int x;
    cout << "1) Flipped Vertical\n" << "2) Flipped Horizontally\n";
    cin >> x;
    string filename;
    cout << "Please enter the image name with extension : " << endl;
    cin >> filename;
    // Load the original image
    Image image(filename);
    // Create a new image to store the edited version
    Image editedImage(image.width, image.height);
    // Flip the image based on user input
    if (x == 1) {
        // Flip vertically
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                editedImage(i, j, 0) = image(i, image.height - 1 - j, 0);
                editedImage(i, j, 1) = image(i, image.height - 1 - j, 1);
                editedImage(i, j, 2) = image(i, image.height - 1 - j, 2);
            }
        }
    }
    else if (x == 2) {
        // Flip horizontally
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                editedImage(i, j, 0) = image(image.width - 1 - i, j, 0);
                editedImage(i, j, 1) = image(image.width - 1 - i, j, 1);
                editedImage(i, j, 2) = image(image.width - 1 - i, j, 2);
            }
        }
    }
    cout << "Image Loaded\n";
    // Prompt the user to enter the name for the new image and its extension
    cout << "Please enter the image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: \n";
    cin >> filename;
    // Save the flipped image
    if (editedImage.saveImage(filename)) {
        cout << "Image Saved\n";
    }
}
int main(){
    flip();
}