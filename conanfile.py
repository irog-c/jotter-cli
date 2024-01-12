import os

from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout
from conan.tools.files import copy


class Jotter(ConanFile):
    def init(self):
        self.__dict__.update(self.conan_data["metadata"])

    def requirements(self):
        [self.requires(requirement) for requirement in self.conan_data["requirements"]]
        [self.test_requires(test_requirement) for test_requirement in self.conan_data["test_requirements"]]

    def layout(self):
        cmake_layout(self)

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        if not self.conf.get("tools.build:skip_test", default=False):
            test_folder = os.path.join("tests")
            if self.settings.os == "Windows":
                test_folder = os.path.join("tests", str(self.settings.build_type))
            self.run(os.path.join(test_folder, "test_hello"))

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def deploy(self):
        copy(self, "jotter", os.path.join(self.package_folder, "bin"), self.deploy_folder)
