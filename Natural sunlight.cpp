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
