################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/HLCD_Program.c \
../src/HLEDMATRIX_Program.c \
../src/HTFT_Program.c \
../src/MEXTI_Config.c \
../src/MEXTI_Program.c \
../src/MGPIO_Program.c \
../src/MNVIC_Program.c \
../src/MRCC_Program.c \
../src/MSPI_Program.c \
../src/MSTK_Program.c \
../src/MUSART_Program.c \
../src/_initialize_hardware.c \
../src/_write.c \
../src/main.c \
../src/stm32f4xx_hal_msp.c 

OBJS += \
./src/HLCD_Program.o \
./src/HLEDMATRIX_Program.o \
./src/HTFT_Program.o \
./src/MEXTI_Config.o \
./src/MEXTI_Program.o \
./src/MGPIO_Program.o \
./src/MNVIC_Program.o \
./src/MRCC_Program.o \
./src/MSPI_Program.o \
./src/MSTK_Program.o \
./src/MUSART_Program.o \
./src/_initialize_hardware.o \
./src/_write.o \
./src/main.o \
./src/stm32f4xx_hal_msp.o 

C_DEPS += \
./src/HLCD_Program.d \
./src/HLEDMATRIX_Program.d \
./src/HTFT_Program.d \
./src/MEXTI_Config.d \
./src/MEXTI_Program.d \
./src/MGPIO_Program.d \
./src/MNVIC_Program.d \
./src/MRCC_Program.d \
./src/MSPI_Program.d \
./src/MSTK_Program.d \
./src/MUSART_Program.d \
./src/_initialize_hardware.d \
./src/_write.d \
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

