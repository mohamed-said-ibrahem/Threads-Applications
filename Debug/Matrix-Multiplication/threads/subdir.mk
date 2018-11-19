################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Matrix-Multiplication/threads/element_row_threaded.c 

OBJS += \
./Matrix-Multiplication/threads/element_row_threaded.o 

C_DEPS += \
./Matrix-Multiplication/threads/element_row_threaded.d 


# Each subdirectory must supply rules for building sources it contributes
Matrix-Multiplication/threads/%.o: ../Matrix-Multiplication/threads/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


