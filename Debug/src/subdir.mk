################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Datastructre\ HW\ 1.cpp \
../src/Polar.cpp 

OBJS += \
./src/Datastructre\ HW\ 1.o \
./src/Polar.o 

CPP_DEPS += \
./src/Datastructre\ HW\ 1.d \
./src/Polar.d 


# Each subdirectory must supply rules for building sources it contributes
src/Datastructre\ HW\ 1.o: ../src/Datastructre\ HW\ 1.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Datastructre HW 1.d" -MT"src/Datastructre\ HW\ 1.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


