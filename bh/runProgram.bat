@echo off
cls

make
make.exe clean
make.exe release

Movies < TEST_CASE.txt > RESULT_OF_TEST_CASE.txt