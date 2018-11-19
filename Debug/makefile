################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Matrix-Multiplication/threads/subdir.mk
-include Matrix-Multiplication/helper/subdir.mk
-include Matrix-Multiplication/Debug/threads/subdir.mk
-include Matrix-Multiplication/Debug/helper/subdir.mk
-include Matrix-Multiplication/Debug/subdir.mk
-include Matrix-Multiplication/subdir.mk
-include BATMAN/Helper/subdir.mk
-include BATMAN/Debug/Helper/subdir.mk
-include BATMAN/Debug/subdir.mk
-include BATMAN/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Threads-Applications

# Tool invocations
Threads-Applications: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross GCC Linker'
	gcc  -o "Threads-Applications" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) Threads-Applications
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
