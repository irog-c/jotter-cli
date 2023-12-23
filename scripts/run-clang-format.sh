#!/bin/bash

clang-format -i src/*.cpp --style=file
clang-format -i include/*.hpp --style=file