################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Matrix-Multiplication/helper/matrix_processing.c \
../Matrix-Multiplication/helper/unsorted_array_processing.c 

OBJS += \
./Matrix-Multiplication/helper/matrix_processing.o \
./Matrix-Multiplication/helper/unsorted_array_processing.o 

C_DEPS += \
./Matrix-Multiplication/helper/matrix_processing.d \
./Matrix-Multiplication/helper/unsorted_array_processing.d 


# Each subdirectory must supply rules for building sources it contributes
Matrix-Multiplication/helper/%.o: ../Matrix-Multiplication/helper/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


