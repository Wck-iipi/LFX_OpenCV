#include <iostream>
#include <opencv2/core/types.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/version.hpp>
#include <string>

int main(int argc, char **argv) {
  std::cout << "Welcome to OpenCV Image Filter" << std::endl;
  std::string path = "Background.jpg";
  if (argv[1]) {
    path = argv[1];
  } else {
    std::cout << "Please enter a path to an image" << std::endl;
    return 0;
  }

  std::cout << "Reading image from path: " << path << std::endl;

  cv::Mat sourceImage = cv::imread(path);

  if (sourceImage.empty()) {
    std::cout << "Invalid image path, please enter correct path." << std::endl;
    return 0;
  }

  std::cout
      << "Enter the number filter you want to apply to image(Press -1 to exit)"
      << std::endl;
  std::cout << "1. Bilateral Filter" << std::endl;
  std::cout << "2. Blur" << std::endl;
  std::cout << "3. Box Filter" << std::endl;
  std::cout << "4. Dilate" << std::endl;
  std::cout << "5. Erode" << std::endl;
  std::cout << "6. Filter2D" << std::endl;
  std::cout << "7. Gaussian Blur" << std::endl;
  std::cout << "8. Laplacian" << std::endl;
  std::cout << "9. MedianBlur" << std::endl;
  std::cout << "10. PyrDown" << std::endl;
  std::cout << "11. Morphology Ex" << std::endl;
  std::cout << "12. Pyr Mean Shift Filtering" << std::endl;
  std::cout << "13. pyrUp" << std::endl;
  std::cout << "14. Scharr " << std::endl;
  std::cout << "15. Sobel " << std::endl;
  std::cout << "16. Square Box Filter" << std::endl;

  while (true) {
    cv::Mat dst;
    int choice;
    std::cin >> choice;
    std::cout << "You have selected: " << choice << std::endl;
    if (choice == -1) {
      std::cout << "Program Terminated" << std::endl;
      break;
    } else if (choice > 16) {
      std::cout << "Invalid choice, please enter a valid choice" << std::endl;
      continue;
    }
    std::string title;
    switch (choice) {
      case 1: {
        cv::bilateralFilter(sourceImage, dst, 15, 80, 80);
        title = "Bilateral Filter";
        break;
      }
      case 2: {
        cv::blur(sourceImage, dst, cv::Size(5, 5));
        title = "Blur";
        break;
      }
      case 3: {
        cv::boxFilter(sourceImage, dst, -1, cv::Size(3, 3));
        title = "Box Filter";
        break;
      }
      case 4: {
        cv::dilate(sourceImage, dst, cv::Mat(), cv::Point(-1, -1), 2);
        title = "Dilate";
        break;
      }
      case 5: {
        cv::erode(sourceImage, dst, cv::Mat(), cv::Point(-1, -1), 2);
        title = "Erode";
        break;
      }
      case 6: {
        cv::Mat kernel = (cv::Mat_<float>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
        cv::filter2D(sourceImage, dst, sourceImage.depth(), kernel);
        title = "Filter2D";
        break;
      }
      case 7: {
        cv::GaussianBlur(sourceImage, dst, cv::Size(5, 5), 0);
        title = "Gaussian Blur";
        break;
      }
      case 8: {
        cv::Laplacian(sourceImage, dst, sourceImage.depth(), 3);
        title = "Laplacian";
        break;
      }
      case 9: {
        cv::medianBlur(sourceImage, dst, 11);
        title = "Median Blur";
        break;
      }
      case 10: {
        cv::pyrDown(sourceImage, dst, cv::Size(sourceImage.cols / 2, sourceImage.rows / 2));
        title = "PyrDown";
        break;
      }
      case 11: {
        cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
        cv::morphologyEx(sourceImage, dst, cv::MORPH_GRADIENT, kernel);
        title = "Morphology Ex";
        break;
      }
      case 12: {
        cv::pyrMeanShiftFiltering(sourceImage, dst, 10, 10);
        title = "Pyr Mean Shift Filtering";
        break;
      }
      case 13: {
        cv::pyrUp(sourceImage, dst, cv::Size(sourceImage.cols * 2, sourceImage.rows * 2));
        title = "PyrUp";
        break;
      }
      case 14: {
        cv::Scharr(sourceImage, dst, sourceImage.depth(), 1, 0);
        title = "Scharr";
        break;
      }
      case 15: {
        cv::Sobel(sourceImage, dst, sourceImage.depth(), 1, 0);
        title = "Sobel";
        break;
      }
      case 16: {
        cv::sqrBoxFilter(sourceImage, dst, 50, cv::Size(40, 40), cv::Point(1, 1), true, cv::BORDER_REFLECT);
        title = "sqrBoxFilter";
        break;
      }
    }
    cv::imshow(title, dst);
    cv::waitKey(0);
    cv::destroyAllWindows();
  }
  return 0;
}
