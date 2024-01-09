#!/bin/bash

clang-tidy --config-file=.clang-tidy -p ./build/Release src/* include/*