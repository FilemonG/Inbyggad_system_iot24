# CAN Diagnostic node
    this project is for educational purposes, CAN messages send and recive. this project will help you read data from the buss network. 

# Build
    1. install ESP-IDF extention, v5.4.1
    2. flash method use UART

# Hardware
    1. ESP32-C6
    2. SN65HVD230 VP230 (CAN Transceiver)
    


# Links
  [datasheet](https://www.ti.com/lit/ds/symlink/sn65hvd230.pdf).
  ![SN65HVD230 VP230](document/SN65HVD230_VP230.jpg)


## How to use example
We encourage the users to use the example as a template for the new projects.
A recommended way is to follow the instructions on a [docs page](https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html#start-a-new-project).

## Example folder contents

The project **sample_project** contains one source file in C language [main.c](main/main.c). The file is located in folder [main](main).

ESP-IDF projects are built using CMake. The project build configuration is contained in `CMakeLists.txt`
files that provide set of directives and instructions describing the project's source files and targets
(executable, library, or both). 

Below is short explanation of remaining files in the project folder.

```
├── CMakeLists.txt
├── main
│   ├── CMakeLists.txt
│   └── main.c
└── README.md                  This is the file you are currently reading
```
Additionally, the sample project contains Makefile and component.mk files, used for the legacy Make based build system. 
They are not used or needed when building with CMake and idf.py.

()