#!/bin/bash

# Check if CMake is installed
if ! command -v cmake &> /dev/null
then
    echo "CMake could not be found. Please install CMake."
    exit
fi

# Create build directory if it doesn't exist
if [ ! -d "build-vs" ]; then
  mkdir build-vs
fi

# Navigate to build directory
cd build-vs

# Generate Visual Studio 2022 project files
cmake -G "Visual Studio 17 2022" ..

echo "Visual Studio project files generated in the build directory."