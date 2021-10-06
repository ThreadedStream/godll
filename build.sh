#!/bin/bash

if [ -d "./build/" ]; then
  echo "found build directory"
else
  echo "creating build directory..."
  mkdir build
fi

cmake -Slib/ -B "build/"
cmake --build build/
go build linux.go
echo
echo "====================================="
echo "SYSTEM INFO"
./linux
echo "====================================="