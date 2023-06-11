################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Delay.c \
../src/EXTI.c \
../src/GPIO_prog.c \
../src/IR_prog.c \
../src/NVIC_program.c \
../src/RCC_prog.c \
../src/SPI_program.c \
../src/STK_prog.c \
../src/TFT_program.c \
../src/led_matrix.c \
../src/main.c \
../src/stm32f4xx_hal_msp.c 

OBJS += \
./src/Delay.o \
./src/EXTI.o \
./src/GPIO_prog.o \
./src/IR_prog.o \
./src/NVIC_program.o \
./src/RCC_prog.o \
./src/SPI_program.o \
./src/STK_prog.o \
./src/TFT_program.o \
./src/led_matrix.o \
./src/main.o \
./src/stm32f4xx_hal_msp.o 

C_DEPS += \
./src/Delay.d \
./src/EXTI.d \
./src/GPIO_prog.d \
./src/IR_prog.d \
./src/NVIC_program.d \
./src/RCC_prog.d \
./src/SPI_program.d \
./src/STK_prog.d \
./src/TFT_program.d \
./src/led_matrix.d \
./src/main.d \
./src/stm32f4xx_hal_msp.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=25000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/stm32f4xx_hal_msp.o: ../src/stm32f4xx_hal_msp.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=25000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -Wno-missing-prototypes -Wno-missing-declarations -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/stm32f4xx_hal_msp.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


