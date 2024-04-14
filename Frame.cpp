#include "Image_Class.h"
#include <iostream>
#include <cmath>

using namespace std;
void frame()
{
    int red, green, blue, frame, color1, color2;
    string ImageName;
    cout << "Please enter the image name with extension : " << endl;
    cin >> ImageName;
    // Load the image
    Image image(ImageName);
    cout << "1) simple frame   2) fancy" << endl;
    cin >> frame;
    cout << "1) pick a color  2) pick the values of the color" << endl;
    cin >> color1;
    if (color1 == 1)
    {
        cout << "1) red     2) green  3)blue" << endl;
        cout << "4) yellow  5)pink   6)black" << endl;
        cin >> color2;
        switch (color2)
        {
        case 1:red = 255, green = 0, blue = 0; break;
        case 2:red = 0, green = 255, blue = 0; break;
        case 3:red = 0, green = 0, blue = 255; break;
        case 4:red = 255, green = 255, blue = 0; break;
        case 5:red = 255, green = 0, blue = 255; break;
        case 6:red = 0, green = 0, blue = 0; break;
        }

    }
    else if (color1)
    {
        cout << "enter the values of the color (red green blue) " << endl;
        cin >> red >> green >> blue;
    }

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j)
        {
            if (frame == 1) // normal frame
            {
                if (i < 20 || j < 20 || i > image.width - 20 || j > image.height - 20)
                {
                    image(i, j, 0) = red;
                    image(i, j, 1) = green;
                    image(i, j, 2) = blue;
                }
                else
                {
                    image(i, j, 0) = image(i, j, 0);
                    image(i, j, 1) = image(i, j, 1);
                    image(i, j, 2) = image(i, j, 2);
                }
            }
            else if (frame == 2) // fancy frame
            {
                if (i < 20 || j < 20 || i > image.width - 20 || j > image.height - 20)
                {
                    image(i, j, 0) = red;
                    image(i, j, 1) = green;
                    image(i, j, 2) = blue;
                }
                else
                {
                    image(i, j, 0) = image(i, j, 0);
                    image(i, j, 1) = image(i, j, 1);
                    image(i, j, 2) = image(i, j, 2);
                }
                if ((i >= 20 && i < 24) || (j >= 20 && j < 24) || (i > image.width - 24 && i <= image.width - 20) || (j > image.height - 24 && j <= image.height - 20) || // first white frame
                    (i >= 30 && i < 32) || (j >= 30 && j < 32) || (i > image.width - 32 && i <= image.width - 30) || (j > image.height - 32 && j <= image.height - 30) || // sec white frame
                    //draw top left circle               
                    (pow(i - 32, 2) + pow(j - 32, 2) <= 10000) && pow(i - 32, 2) + pow(j - 32, 2) > 9000 && j >= 32 && i >= 32 ||
                    (pow(i - 32, 2) + pow(j - 32, 2) <= 6000) && pow(i - 32, 2) + pow(j - 32, 2) > 5000 && j >= 32 && i >= 32 ||
                    (pow(i - 32, 2) + pow(j - 32, 2) <= 2000) && pow(i - 32, 2) + pow(j - 32, 2) > 1500 && j >= 32 && i >= 32 ||
                    (pow(i - 32, 2) + pow(j - 32, 2) <= 500) && j >= 32 && i >= 32 ||
                    //draw top right circle
                    (pow(i - (image.width - 32), 2) + pow(j - 32, 2) <= 10000) && pow(i - (image.width - 32), 2) + pow(j - 32, 2) > 9000 && j >= 32 && i <= (image.width - 32) ||
                    (pow(i - (image.width - 32), 2) + pow(j - 32, 2) <= 6000) && pow(i - (image.width - 32), 2) + pow(j - 32, 2) > 5000 && j >= 32 && i <= (image.width - 32) ||
                    (pow(i - (image.width - 32), 2) + pow(j - 32, 2) <= 2000) && pow(i - (image.width - 32), 2) + pow(j - 32, 2) > 1500 && j >= 32 && i <= (image.width - 32) ||
                    (pow(i - (image.width - 32), 2) + pow(j - 32, 2) <= 500) && j >= 32 && i <= (image.width - 32) ||
                    //draw bot right circle
                    (pow(i - (image.width - 32), 2) + pow(j - (image.height - 32), 2) <= 10000) && pow(i - (image.width - 32), 2) + pow(j - (image.height - 32), 2) > 9000 && j <= (image.height - 32) && i <= (image.width - 32) ||
                    (pow(i - (image.width - 32), 2) + pow(j - (image.height - 32), 2) <= 6000) && pow(i - (image.width - 32), 2) + pow(j - (image.height - 32), 2) > 5000 && j <= (image.height - 32) && i <= (image.width - 32) ||
                    (pow(i - (image.width - 32), 2) + pow(j - (image.height - 32), 2) <= 2000) && pow(i - (image.width - 32), 2) + pow(j - (image.height - 32), 2) > 1500 && j <= (image.height - 32) && i <= (image.width - 32) ||
                    (pow(i - (image.width - 32), 2) + pow(j - (image.height - 32), 2) <= 500) && j <= (image.height - 32) && i <= (image.width - 32) ||
                    // draw bot left circle
                    (pow(i - 32, 2) + pow(j - (image.height - 32), 2) <= 10000) && pow(i - 32, 2) + pow(j - (image.height - 32), 2) > 9000 && j <= (image.height - 32) && i >= 32 ||
                    (pow(i - 32, 2) + pow(j - (image.height - 32), 2) <= 6000) && pow(i - 32, 2) + pow(j - (image.height - 32), 2) > 5000 && j <= (image.height - 32) && i >= 32 ||
                    (pow(i - 32, 2) + pow(j - (image.height - 32), 2) <= 2000) && pow(i - 32, 2) + pow(j - (image.height - 32), 2) > 1500 && j <= (image.height - 32) && i >= 32 ||
                    (pow(i - 32, 2) + pow(j - (image.height - 32), 2) <= 500) && j <= (image.height - 32) && i >= 32)


                {   // set this drawing to white color
                    image(i, j, 0) = 255;
                    image(i, j, 1) = 255;
                    image(i, j, 2) = 255;
                }

            }


        }
    }
    // Inform the user that the image has been loaded
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
int main()
{
    frame();
}