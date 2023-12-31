import os

from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout
from conan.tools.files import copy


class Jotter(ConanFile):
    name = "jotter"
    version = "0.1"
    author = "Igor Mihajlov"

    package_type = "application"
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"

    exports_sources = "CMakeLists.txt", "src*", "include*"

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

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def deploy(self):
        copy(self, "jotter", os.path.join(self.package_folder, "bin"), self.deploy_folder)
