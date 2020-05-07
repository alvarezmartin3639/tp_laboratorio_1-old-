################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/FuncionesCalculadora.c \
../src/TP1Calculadora.c 

OBJS += \
./src/FuncionesCalculadora.o \
./src/TP1Calculadora.o 

C_DEPS += \
./src/FuncionesCalculadora.d \
./src/TP1Calculadora.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


