## LFX_OpenCV
This is submitted as pretest for LFX Mentorship.

## Setup (Tested on linux)
1. Build and install the latest version of [opencv](https://docs.opencv.org/4.x/d7/d9f/tutorial_linux_install.html).
2. Install libopencv using `sudo apt install libopencv-dev`

## Running the repository
1. Clone the repository using ```git clone https://github.com/Wck-iipi/LFX_OpenCV```
2. Run the code with `pkg-config --libs --cflags opencv4`.
The final command would look something like:

```g++ main.cpp `pkg-config --libs --cflags opencv4` -o main && ./main "Background.jpg"```

### Usage
The application takes in one argument, the name of the source image and **it must be provided**. The application has 16 different filter options. These are:

 1. Bilateral Filter
  2. Blur
  3. Box Filter
  4. Dilate
  5. Erode
  6. Filter2D
  7. Gaussian Blur
  8. Laplacian
  9. MedianBlur
  10. PyrDown
  11. Morphology Ex
  12. Pyr Mean Shift Filtering
  13. pyrUp
  14. Scharr 
  15. Sobel 
  16. Square Box Filter

You would be provided with a menu in which you can select the right option by typing the number and the program will show you the image with correct filter applied to the image.

If you want to learn more about these, go to https://docs.opencv.org/4.x/d4/d86/group__imgproc__filter.html
