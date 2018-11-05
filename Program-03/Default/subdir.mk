################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Driver.cpp \
../Movie.cpp \
../Movies.cpp \
../Text.cpp \
../Timer.cpp 

OBJS += \
./Driver.o \
./Movie.o \
./Movies.o \
./Text.o \
./Timer.o 

CPP_DEPS += \
./Driver.d \
./Movie.d \
./Movies.d \
./Text.d \
./Timer.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


