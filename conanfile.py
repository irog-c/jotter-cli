import os

from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout
from conan.tools.files import copy


class Jotter(ConanFile):
    def init(self):
        self.__dict__.update(self.conan_data["metadata"])

    def requirements(self):
        [self.requires(requirement) for requirement in self.conan_data["requirements"]]

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
