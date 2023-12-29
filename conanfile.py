import os

from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout


class Jotter(ConanFile):
    name = "jotter-cli"
    version = "0.1"
    author = "Igor Mihajlov"

    package_type = "application"
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"

    def requirements(self):
        requirements = self.conan_data.get("requirements", [])
        for requirement in requirements:
            self.requires(requirement)

    def layout(self):
        cmake_layout(self)

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
