#!/usr/bin/env python3

import subprocess
import common

clang_command = ['clang-tidy', '--config-file=.clang-tidy', '-p', './build/Release']
clang_command.extend(common.file_paths)
subprocess.run(clang_command)
