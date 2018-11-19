################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Matrix-Multiplication/main.c 

OBJS += \
./Matrix-Multiplication/main.o 

C_DEPS += \
./Matrix-Multiplication/main.d 


# Each subdirectory must supply rules for building sources it contributes
Matrix-Multiplication/%.o: ../Matrix-Multiplication/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


