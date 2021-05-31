from conans import ConanFile, CMake, tools


class ExampleConan(ConanFile):
    name = "Crucible"
    version = "0.0.1"
    settings = "os", "arch", "compiler", "build_type"
    options = {"build_tests": [True, False]}
    default_options = {"build_tests": False}
    exports_sources = "*"
    generators = "cmake"

    def configure(self):
        self.options["sfml"].graphics = True
        self.options["sfml"].window = True
        self.options["sfml"].audio = True
        self.options["sfml"].network = False

    def requirements(self):
        if self.options.build_tests:
            self.requires("gtest/1.10.0")
        self.requires("sfml/2.5.1@bincrafters/stable")
        self.requires("entt/3.7.1")
        self.requires("spdlog/[>=1.4.1]")

    def build(self):
        cmake = CMake(self)
        cmake.definitions["BUILD_TESTS"] = self.options.build_tests
        cmake.configure()
        cmake.build()
        if self.options.build_tests:
            cmake.test()

    def package(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = tools.collect_libs(self)
