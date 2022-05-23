#!/bin/zsh
set -e

BASE_DIR=$0:a:h
BUILD_DIR=$BASE_DIR/build_2021_0_338
SKP_FILE=$BASE_DIR/demo.skp

mkdir -p $BUILD_DIR
cmake -DUSE_SKETCHUP_2021_0_338=ON -S . -B $BUILD_DIR
cmake --build $BUILD_DIR

$BUILD_DIR/sketchup-api-demo $SKP_FILE
