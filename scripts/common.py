import os
import glob

os.chdir(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
file_paths = [file for pattern in ["src/*.cpp", "include/*.hpp"] for file in glob.glob(pattern)]
