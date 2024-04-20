/*

Name : Alaa Yasser Hemly         ID : 20230235    Section: 15
Flip , Black and White , crop and resize filters
Bonus: Infrared filter 

Name : Yousef Ayman Hafez        ID : 20230484    Section: 15
Rotate , Invert filters , blur and frame filters
Bonus : purple filter

Name : Abdelrhamn Ahmed Mohamed  ID:20230203    Section: 15
Grayscale , Darken And Lighten , merge and detect edges filters
Bonus : Nutral Sunlight filter

                                            https://github.com/4abdelrhman/Filters


                                        This is our 15 filters code we wish you like it <3

*/
#include "Image_Class.h"
#include <iostream>
#include <cmath>

using namespace std;
void merge()
{
    string ImageName1, ImageName2;
    // Prompt the user to enter the names of the images
    cout << "if both have the same size Enter them in no particular order" << endl;
    cout << "Please enter the bigger image name with extension: ";
    cin >> ImageName1;
    Image image1(ImageName1);
    cout << "Please enter the smaller image name with extension: ";
    cin >> ImageName2;
    Image image2(ImageName2);

    // If images have the same dimensions, merge them directly
    if (image1.width == image2.width && image1.height == image2.height)
    {
        Image merge(image1.width, image1.height);
        for (int i = 0; i < image1.width; ++i) {
            for (int j = 0; j < image1.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    // Calculate average value of corresponding pixels from both images
                    merge(i, j, k) = (image1(i, j, k) + image2(i, j, k)) / 2;
                }
            }
        }
        string output;
        cout << "Please enter the name to store the new merged image (with extension .jpg, .bmp, .png, .tga): ";
        cin >> output;
        // Save the merged image
        if (merge.saveImage(output))
        {
            cout << "Image Saved\n";
        }
    }
    else
    {
        // If images have different dimensions, offer options for resizing then merging
        string option;
        cout << "1) resize the smaller to be equal to the bigger " << endl << "2)resize the bigger to be equal top the smaller" << endl << "3) merge the common area of the smaller width and the smaller height. " << endl;
        cin >> option;
        if (option == "1")
        {
            // Resize the smaller image to match the dimensions of the bigger image
            Image resizedImage(image1.width, image1.height);
            float xR = static_cast<float>(image2.width - 1) / image1.width;
            float yR = static_cast<float>(image2.height - 1) / image1.height;
            for (int i = 0; i < image1.width; ++i)
            {
                for (int j = 0; j < image1.height; ++j)
                {
                    // Calculate corresponding pixel coordinates in the smaller image
                    int x = static_cast<int>(xR * i);
                    int y = static_cast<int>(yR * j);
                    // Copy pixel values from the smaller image to the resized image
                    resizedImage(i, j, 0) = image2(x, y, 0);
                    resizedImage(i, j, 1) = image2(x, y, 1);
                    resizedImage(i, j, 2) = image2(x, y, 2);
                }
            }
            // Merge the resized smaller image with the bigger image
            Image merge(resizedImage.width, resizedImage.height);
            for (int i = 0; i < resizedImage.width; ++i) {
                for (int j = 0; j < resizedImage.height; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        // Calculate average value of corresponding pixels from both images
                        merge(i, j, k) = (image1(i, j, k) + resizedImage(i, j, k)) / 2;
                    }
                }
            }
            string output;
            cout << "Please enter the name to store the new merged image (with extension .jpg, .bmp, .png, .tga): ";
            cin >> output;
            // Save the merged image
            if (merge.saveImage(output))
            {
                cout << "Image Saved\n";
            }
        }
        else if (option == "2")
        {
            // Resize the bigger image to match the dimensions of the smaller image
            Image resizedImage(image2.width, image2.height);
            float xR = static_cast<float>(image1.width - 1) / image2.width;
            float yR = static_cast<float>(image1.height - 1) / image2.height;
            for (int i = 0; i < image2.width; ++i)
            {
                for (int j = 0; j < image2.height; ++j)
                {
                    int x = static_cast<int>(xR * i);
                    int y = static_cast<int>(yR * j);
                    // Copy pixel values from the bigger image to the resized image
                    resizedImage(i, j, 0) = image1(x, y, 0);
                    resizedImage(i, j, 1) = image1(x, y, 1);
                    resizedImage(i, j, 2) = image1(x, y, 2);
                }
            }
            // Merge the resized bigger image with the smaller image
            Image merge(resizedImage.width, resizedImage.height);
            for (int i = 0; i < resizedImage.width; ++i) {
                for (int j = 0; j < resizedImage.height; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        // Calculate average value of corresponding pixels from both images
                        merge(i, j, k) = (image2(i, j, k) + resizedImage(i, j, k)) / 2;
                    }
                }
            }
            string output;
            cout << "Please enter the name to store the new merged image (with extension .jpg, .bmp, .png, .tga): ";
            cin >> output;
            // Save the merged image
            if (merge.saveImage(output))
            {
                cout << "Image Saved\n";
            }
        }
        else if (option == "3")
        {
            // Merge the common area of the smaller width and the smaller height
            int w, h;
            // Determine the minimum width and height between the two images
            if (image1.width < image2.width)
            {
                w = image1.width;
            }
            else
            {
                w = image2.width;
            }
            if (image1.height < image2.height)
            {
                h = image1.height;
            }
            else
            {
                h = image2.height;
            }
            // Resize both images to the common area
            Image resizedImage1(w, h);
            Image resizedImage2(w, h);
            float xR1 = static_cast<float>(image1.width - 1) / w;
            float yR1 = static_cast<float>(image1.height - 1) / h;
            for (int i = 0; i < w; ++i)
            {
                for (int j = 0; j < h; ++j)
                {
                    // Calculate corresponding pixel coordinates in the resized image
                    int x = static_cast<int>(xR1 * i);
                    int y = static_cast<int>(yR1 * j);
                    resizedImage1(i, j, 0) = image1(x, y, 0);
                    resizedImage1(i, j, 1) = image1(x, y, 1);
                    resizedImage1(i, j, 2) = image1(x, y, 2);
                }
            }
            float xR2 = static_cast<float>(image2.width - 1) / w;
            float yR2 = static_cast<float>(image2.height - 1) / h;
            for (int i = 0; i < w; ++i)
            {
                for (int j = 0; j < h; ++j)
                {
                    // Calculate corresponding pixel coordinates in the resized image
                    int x = static_cast<int>(xR2 * i);
                    int y = static_cast<int>(yR2 * j);
                    resizedImage2(i, j, 0) = image2(x, y, 0);
                    resizedImage2(i, j, 1) = image2(x, y, 1);
                    resizedImage2(i, j, 2) = image2(x, y, 2);
                }
            }
            // Merge the resized images
            Image merge(w, h);
            for (int i = 0; i < w; ++i) {
                for (int j = 0; j < h; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        // Calculate average value of corresponding pixels from both images
                        merge(i, j, k) = (resizedImage2(i, j, k) + resizedImage1(i, j, k)) / 2;
                    }
                }
            }
            string output;
            cout << "Please enter the name to store the new merged image (with extension .jpg, .bmp, .png, .tga): ";
            cin >> output;
            // Save the merged image
            if (merge.saveImage(output))
            {
                cout << "Image Saved\n";
            }
        }
    }
}
void darken_and_lighten()
{
    string op;
    cout << "1)Darken\n" << "2)Lighten\n";
    cin >> op;
    if (op == "1")
    {
        string ImageName;
        cout << "Please enter the image name with extension : " << endl;
        cin >> ImageName;
        Image image(ImageName);
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < image.channels; ++k) {
                    // Reduce the intensity of each color channel by 30% (multiply by 0.3)
                    image(i, j, k) *= 0.3;
                }
            }
        }

        cout << "Image Loaded\n";
        // Prompt the user to enter the new image name and extension
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
    else if (op == "2")
    {
        string ImageName;
        cout << "Please enter the image name with extension : " << endl;
        cin >> ImageName;
        Image image(ImageName);
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < image.channels; ++k) {
                    // Lighten the pixel value by multiplying with a factor
                    image(i, j, k) = min(255, static_cast<int>(image(i, j, k) * 1.3));
                }
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
}
void detecting_edges()
{
    string inputFilename;
    cout << "Please enter the image name with extension : " << endl;
    cin >> inputFilename;
    Image originalImage(inputFilename);
    Image processedImage(originalImage.width, originalImage.height);
    // Convert the original image to grayscale
    Image grayscaleImage(originalImage.width, originalImage.height);
    for (int y = 0; y < originalImage.height; ++y) {
        for (int x = 0; x < originalImage.width; ++x) {
            // Calculate grayscale value using average of RGB channels
            unsigned char grayValue = (originalImage(x, y, 0) + originalImage(x, y, 1) + originalImage(x, y, 2)) / 3;
            // Set grayscale value for each channel
            grayscaleImage(x, y, 0) = grayValue;
            grayscaleImage(x, y, 1) = grayValue;
            grayscaleImage(x, y, 2) = grayValue;
        }
    }
    // Approximate edge detection by calculating the difference in intensity between adjacent pixels
    for (int y = 1; y < grayscaleImage.height - 1; ++y) {
        for (int x = 1; x < grayscaleImage.width - 1; ++x) {
            // Calculate gradient magnitude using Sobel operator
            int gradientX = grayscaleImage(x + 1, y - 1, 0) - grayscaleImage(x - 1, y - 1, 0)+ 2 * (grayscaleImage(x + 1, y, 0) - grayscaleImage(x - 1, y, 0)) + grayscaleImage(x + 1, y + 1, 0) - grayscaleImage(x - 1, y + 1, 0);
            int gradientY = grayscaleImage(x - 1, y + 1, 0) - grayscaleImage(x - 1, y - 1, 0)+ 2 * (grayscaleImage(x, y + 1, 0) - grayscaleImage(x, y - 1, 0))+ grayscaleImage(x + 1, y + 1, 0) - grayscaleImage(x + 1, y - 1, 0);
            int gradientMagnitude = abs(gradientX) + abs(gradientY);
            if (gradientMagnitude > 170) { 
                processedImage(x, y, 0) = 0;
                processedImage(x, y, 1) = 0;
                processedImage(x, y, 2) = 0;
            }
            else {
                // Set pixel to white for non-edge regions
                processedImage(x, y, 0) = 255;
                processedImage(x, y, 1) = 255;
                processedImage(x, y, 2) = 255;
            }
        }
    }
    cout << "Image Loaded\n";
    cout << "Please enter the image name to store the new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: \n";
    string outputFilename;
    cin >> outputFilename;
    if (processedImage.saveImage(outputFilename))
    {
        cout << "Image Saved\n";
    }
}
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
void gray()
{
    string ImageName;
    cout << "Please enter the image name with extension : " << endl;
    cin >> ImageName;
    // Load the image
    Image image(ImageName);
    // Convert the image to grayscale
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned int avg = 0;
            // Calculate the average of the pixel values
            for (int k = 0; k < 3; ++k) {
                avg += image(i, j, k);
            }
            avg /= 3;
            // Set all channels to the average value to convert to grayscale
            image(i, j, 0) = avg;
            image(i, j, 1) = avg;
            image(i, j, 2) = avg;
        }
    }
    cout << "Image Loaded\n";
    // Prompt the user to enter the new image name and extension
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
void black_and_white()
{
    string ImageName;
    cout << "Please enter the image name  : " << endl;
    cin >> ImageName;
    // Load the image with the given name
    Image image(ImageName);
    // Iterate over each pixel in the image
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            int avg = (image(i, j, 0) + image(i, j, 1) + image(i, j, 2)) / 3;
            // If the average intensity is greater than 127, set the pixel to white; otherwise, set it to black
            if (avg > 127) {
                image(i, j, 0) = 250;
                image(i, j, 1) = 250;
                image(i, j, 2) = 250;
            }
            else {
                image(i, j, 0) = 0;
                image(i, j, 1) = 0;
                image(i, j, 2) = 0;
            }
        }
    }
    // Inform the user that the image has been loaded
    cout << "Image Loaded\n";
    // Prompt the user to enter the name for the new image and its extension
    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> ImageName;
    // Save the modified image with the new name
    if (image.saveImage(ImageName)) {
        cout << "Image Saved\n";
    }
}
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
void crop()
{
    int x, y, width, height;
    string ImageName;
    cout << "Please enter the image name with extension : " << endl;
    cin >> ImageName;
    Image image(ImageName);
    cout << "Enter the x coordinate and y coordinate of the starting point from corner: ";
    cin >> x >> y;
    if(x>0 & y>0){
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
    else{
        cout <<"Failed to Load.\n";
    }
}
void resizing()
{

    string ImageName;
    cout << "Please enter the image name with extension : " << endl;
    cin >> ImageName;


    Image image(ImageName);

    // Prompt user to enter the new width and height for resizing
    int newWidth, newHeight;
    cout << "Enter the new width and the new height : ";
    cin >> newWidth >> newHeight;

    // Create a new image object to store the resized image
    Image resizedImage(newWidth, newHeight);

    // Calculate the ratio of width and height between the original image and the new resized image
    float xR = static_cast<float>(image.width - 1) / newWidth;
    float yR = static_cast<float>(image.height - 1) / newHeight;


    for (int i = 0; i < newWidth; ++i)
    {
        for (int j = 0; j < newHeight; ++j)
        {
            // Calculate the corresponding position in the original image using the ratio
            int x = static_cast<int>(xR * i); 
            int y = static_cast<int>(yR * j); 

            // Copy the RGB values from the original image to the resized image
            resizedImage(i, j, 0) = image(x, y, 0); 
            resizedImage(i, j, 1) = image(x, y, 1); 
            resizedImage(i, j, 2) = image(x, y, 2); 
        }
    }

  
    cout << "Image Resized\n";
    cout << "Please enter the image name to store the new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: \n";
    cin >> ImageName;

    // Save the resized image
    if (resizedImage.saveImage(ImageName))
    {
        cout << "Image Saved\n";
    }

}
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
void nutural_sunlight() {

    string ImageName;
    cout << "Please enter the image name with extension : " << endl;
    cin >> ImageName;
    Image image(ImageName);

    // Apply the yellow filter to the image
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            // Increase the intensity of the red channel to enhance the yellow tint
            image(i, j, 0) = min(255, image(i, j, 0) + 50); // Red
            // Increase the intensity of the green channel to enhance the yellow tint
            image(i, j, 1) = min(255, image(i, j, 1) + 50); // Green
            // Slightly decrease the intensity of the blue channel to balance the color
            image(i, j, 2) = max(0, image(i, j, 2) - 20); // Blue
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
int main()
{
    while (true) {
        string option;  //taking the option from the user which filter needed to use
        cout << "Choose a Filter" << endl;
        cout << "1)  GrayScale            2)  Black And white  " << endl;
        cout << "3)  Invert               4)  Merge  " << endl;
        cout << "5)  Filp                 6)  Rotate " << endl;
        cout << "7)  Darken And Lighten   8)  Crop " << endl;
        cout << "9)  Adding a Frame       10) Detect Image Edges " << endl;
        cout << "11) Resizing             12) blur " << endl;
        cout << "13) Infrared             14)Purple " << endl;
        cout << "15) Nutral Sunlight      16) Exit  " << endl;
        cin >> option;
        if (option == "1")
        {
            gray();
        }
        else if (option == "2")
        {
            black_and_white();
        }
        else if (option == "3")
        {
            invert();
        }
        else if (option == "4")
        {
            merge();
        }
        else if (option == "5")
        {
            flip();
        }
        else if (option == "6")
        {
            rotate();
        }
        else if (option == "7")
        {
            darken_and_lighten();
        }
        else if (option == "8")
        {
            crop();
        }
        else if (option == "9")
        {
            frame();
        }
        else if (option == "10")
        {
            detecting_edges();
        }
        else if (option == "11")
        {
            resizing();
        }
        else if (option == "12")
        {
            blur();
        }
        else if (option == "13")
        {
            infrared();
        }
        else if (option == "14")
        {
            purple();
        }
        else if (option == "15")
        {
            nutural_sunlight();
        }
        else if (option == "16")
        {
            cout << "Thanks for using our program <3";
            break;
        }
        else {
            cout << "Please enter valid choice\n";
        }
    }
    return 0;
}
