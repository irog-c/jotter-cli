#!/usr/bin/env python3

import subprocess

import common

for file_path in common.file_paths:
    subprocess.run(['clang-format', '-i', file_path])
