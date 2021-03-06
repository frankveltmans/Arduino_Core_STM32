/*
 *******************************************************************************
 * Copyright (c) 2021, STMicroelectronics
 * All rights reserved.
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************
 */
#pragma once

/*----------------------------------------------------------------------------
 *        STM32 pins number
 *----------------------------------------------------------------------------*/
#define PA3                     PIN_A12
#define PA2                     PIN_A13
#define PA10                    2
#define PB3                     3
#define PB5                     4
#define PB4                     5
#define PB10                    6
#define PA8                     7
#define PA9                     8
#define PC7                     9
#define PB6                     10 // PWM is not supported by D10 as no timer on PB6
#define PA7                     PIN_A6
#define PA6                     PIN_A7
#define PA5                     PIN_A14
#define PB9                     14
#define PB8                     15
// ST Morpho
// CN7 Left Side
#define PC10                    16
#define PC12                    17
#define PA13                    18 // SWD
#define PA14                    19 // SWD
#define PA15                    20
#define PB7                     21
#define PC13                    22
#define PC14                    23
#define PC15                    24
#define PH0                     25
#define PH1                     26
#define PC2                     PIN_A8
#define PC3                     PIN_A9
// CN7 Right Side
#define PC11                    29
#define PD2                     30
// CN10 Left Side
#define PC9                     31
// CN10 Right side
#define PC8                     32
#define PC6                     33
#define PC5                     PIN_A10
#define PA12                    35
#define PA11                    36
#define PB12                    37
#define PB11                    38
#define PB2                     39
#define PB1                     PIN_A15
#define PB15                    41
#define PB14                    42
#define PB13                    43
#define PC4                     PIN_A11
#define PA0                     PIN_A0
#define PA1                     PIN_A1
#define PA4                     PIN_A2
#define PB0                     PIN_A3
#define PC1                     PIN_A4 // SB56 ON SB51 ON on the board!
#define PC0                     PIN_A5

// Alternate pins number
#define PA2_ALT1                (PA2  | ALT1)
#define PA3_ALT1                (PA3  | ALT1)
#define PA14_ALT1               (PA14 | ALT1)

#define NUM_DIGITAL_PINS        51
#define NUM_ANALOG_INPUTS       16

// On-board LED pin number
#ifndef LED_BUILTIN
  #define LED_BUILTIN           PA5
#endif
#define LED_GREEN               LED_BUILTIN

// On-board user button
#ifndef USER_BTN
  #define USER_BTN              PC13
#endif

// Timer Definitions
// Use TIM6/TIM7 when possible as servo and tone don't need GPIO output pin
#ifndef TIMER_TONE
  #define TIMER_TONE            TIM21
#endif
#ifndef TIMER_SERVO
  #define TIMER_SERVO           TIM22
#endif

// UART Definitions
#ifndef SERIAL_UART_INSTANCE
  #define SERIAL_UART_INSTANCE  101
#endif

// Default pin used for generic 'Serial' instance
// Mandatory for Firmata
#ifndef PIN_SERIAL_RX
  #define PIN_SERIAL_RX         PA3
#endif
#ifndef PIN_SERIAL_TX
  #define PIN_SERIAL_TX         PA2
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus
  // These serial port names are intended to allow libraries and architecture-neutral
  // sketches to automatically default to the correct port name for a particular type
  // of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
  // the first hardware serial port whose RX/TX pins are not dedicated to another use.
  //
  // SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
  //
  // SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
  //
  // SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
  //
  // SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
  //
  // SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
  //                            pins are NOT connected to anything by default.
  #ifndef SERIAL_PORT_MONITOR
    #define SERIAL_PORT_MONITOR   Serial
  #endif
  #ifndef SERIAL_PORT_HARDWARE
    #define SERIAL_PORT_HARDWARE  Serial
  #endif
#endif
