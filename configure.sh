echo off
# invoke conan
conan install . --build missung -s build_type=Debug
# TODO: Run premake
