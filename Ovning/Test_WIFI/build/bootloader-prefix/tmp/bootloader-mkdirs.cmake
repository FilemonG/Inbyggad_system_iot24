# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/filimonangosom/esp/v5.1-rc2/esp-idf/components/bootloader/subproject"
  "/Users/filimonangosom/Documents/GitHub/Inbyggad_system_iot24/Ovning/Test_WIFI/build/bootloader"
  "/Users/filimonangosom/Documents/GitHub/Inbyggad_system_iot24/Ovning/Test_WIFI/build/bootloader-prefix"
  "/Users/filimonangosom/Documents/GitHub/Inbyggad_system_iot24/Ovning/Test_WIFI/build/bootloader-prefix/tmp"
  "/Users/filimonangosom/Documents/GitHub/Inbyggad_system_iot24/Ovning/Test_WIFI/build/bootloader-prefix/src/bootloader-stamp"
  "/Users/filimonangosom/Documents/GitHub/Inbyggad_system_iot24/Ovning/Test_WIFI/build/bootloader-prefix/src"
  "/Users/filimonangosom/Documents/GitHub/Inbyggad_system_iot24/Ovning/Test_WIFI/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/filimonangosom/Documents/GitHub/Inbyggad_system_iot24/Ovning/Test_WIFI/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/filimonangosom/Documents/GitHub/Inbyggad_system_iot24/Ovning/Test_WIFI/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
