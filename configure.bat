@echo off
REM invoke conan
conan install . --build missung -s build_type=Debug
REM TODO: Run premake
