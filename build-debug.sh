#!/bin/bash

set -o nounset  # (set -u) No unset variables
set -o errexit  # (set -e) Exit if any statement returns non-true value

PROJECT_NAME="PicoSerialLoopback"
BUILD_DIRECTORY="build-debug"
CMAKE_ARGS="-DCMAKE_BUILD_TYPE=Debug"

if [[ "$OSTYPE" == "linux-gnu"* ]]; then
    MAKE_CMD="make"
elif [[ "$OSTYPE" == "msys" ]]; then
    MAKE_CMD="nmake"
    CMAKE_ARGS="$CMAKE_ARGS -G 'NMake Makefiles'"
fi

cd "$(dirname -- "$0")"

# Create build directory and run cmake if necessary
if [ ! -d "$BUILD_DIRECTORY" ]; then
    mkdir -p "$BUILD_DIRECTORY"
    pushd "$BUILD_DIRECTORY"
    eval cmake $CMAKE_ARGS ..
    popd
fi

pushd "$BUILD_DIRECTORY"
$MAKE_CMD
popd
