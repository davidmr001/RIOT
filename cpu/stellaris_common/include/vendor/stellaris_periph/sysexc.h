//*****************************************************************************
//
// sysexc.h - Prototypes for the System Exception Module routines.
//
// Copyright (c) 2011-2012 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
//
//   Redistribution and use in source and binary forms, with or without
//   modification, are permitted provided that the following conditions
//   are met:
//
//   Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
//
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the
//   distribution.
//
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// This is part of revision 9453 of the Stellaris Peripheral Driver Library.
//
//*****************************************************************************

#ifndef STELLARIS_SYSEXC_H
#define STELLARIS_SYSEXC_H

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
// Values that can be passed to SysExcIntEnable, SysExcIntDisable, and
// SysExcIntClear as the ulIntFlags parameter, and returned from
// SysExcIntStatus.
//
//*****************************************************************************
#define SYSEXC_INT_FP_IXC       0x00000020  // FP Inexact exception interrupt
#define SYSEXC_INT_FP_OFC       0x00000010  // FP Overflow exception interrupt
#define SYSEXC_INT_FP_UFC       0x00000008  // FP Underflow exception interrupt
#define SYSEXC_INT_FP_IOC       0x00000004  // FP Invalid operation interrupt
#define SYSEXC_INT_FP_DZC       0x00000002  // FP Divide by zero exception int
#define SYSEXC_INT_FP_IDC       0x00000001  // FP Input denormal exception int

//*****************************************************************************
//
// Prototypes.
//
//*****************************************************************************
extern void SysExcIntRegister(void (*pfnHandler)(void));
extern void SysExcIntUnregister(void);
extern void SysExcIntEnable(unsigned long ulIntFlags);
extern void SysExcIntDisable(unsigned long ulIntFlags);
extern unsigned long SysExcIntStatus(tBoolean bMasked);
extern void SysExcIntClear(unsigned long ulIntFlags);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif /* STELLARIS_SYSEXC_H */