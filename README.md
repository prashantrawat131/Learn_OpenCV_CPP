## How to setup OpenCV

I followed [this](https://www.youtube.com/watch?v=CnXUTG9XYGI) video. I guess this is one of the best setup tutorial to get started.

> Note: I am expecting you have Cmake and VS Code installed and running helloworld C++ code.

## These are the steps I followed to setup OpenCV in VS Code:

1. Download OpenCV from [here](https://opencv.org/releases/)

1. Create a envrioment variable `OpenCV_DIR` and set it to the path where you have installed OpenCV. For me it was `C:\opencv\build\`

1. Add following to the `Path` variable in the system variables:

   - `C:\opencv\build\x64\vc16\bin`
   - `C:\opencv\build\x64\vc16\lib`
     For me the above two are the paths in the openCV build directory. I am using openCV 4.8.0.

1. Restart VS Code. (If you have it open) - This is important.

1. Create a new C++ file in your project and add the code you like to run using OpenCV.

1. Create a CMakeLists.txt file in the project directory and add the following code:
   ```cmake
   cmake_minimum_required(VERSION 3.29.0)
   project(LearnOpenCv)
   set(CMAKE_CXX_STANDARD 17)
   find_package(OpenCV REQUIRED)
   include_directories(${OpenCV_INCLUDE_DIRS})
   add_executable(LearnOpenCv main.cpp)
   target_link_libraries(LearnOpenCv ${OpenCV_LIBS})
    ```
> Note: I am using Cmake version 3.29.0. You can check the version of Cmake by running `cmake --version` in the terminal. Also the name of my cpp file is main.cpp.


## How to run the code:
> Note: I would recommend you to see my project structure before you run the following commands.
 Open the terminal in VS Code and run the following commands:
   ```bash
    mkdir build
    cd build
    cmake ../src/
    cmake --build .
    ./Debug/LearnOpenCv.exe
    ```
    > Note: If you are using some image paths in the code then make sure the image paths are abosolute or relative to the /build/Degug/ directory. Otherwise you will get an error.
