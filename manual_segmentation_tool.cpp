// ManualSegmentationTool.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "image_processing.h"
#include "segment_by_polygon_fit.h"
#ifdef _MSC_VER
#include "application_win32.h"
#else
#include "application_glfw_opengl2.h"
#endif
#include "save_final_mask.h"

#include <vector>
#include <string>
#include <iostream>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;


std::vector<std::string> getImagesInFolder(std::string path) {
    std::vector<std::string> imageFiles;
    for (auto &file : fs::directory_iterator(path))
    {
        imageFiles.push_back(file.path().string());
    }
    return imageFiles;
}

int main()
{
    auto image_files = getImagesInFolder("./images");
    ApplicationGlfwOpengl2 app;
    app.run();
    ImageProcessing image;
    SegmentByPolygonFit s;

    for (auto& image_file: image_files) {
        std::cout << "Processing file: " << image_file << std::endl;
        image.setImage(cv::imread(image_file));
        s.run(image);
        SaveFinalMask::save_mask_into_file(image_file, "./result/mask", image.getSegmentationMask());
    }
    return 1;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
