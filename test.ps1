cd build
conan install .. --build=missing -o build_tests=True
conan build --test ..
cd ..