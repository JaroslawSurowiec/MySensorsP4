// Copyright 2008-2016 Jaroslaw Surowiec
// 

#pragma once


/*-----------------------------------------------------------------------------
	Base types 
	UE4
-----------------------------------------------------------------------------*/

// Unsigned base types.
typedef unsigned char 		uint8;		// 8-bit  unsigned.
typedef unsigned int		uint16;		// 16-bit unsigned.
typedef unsigned long 		uint32;		// 32-bit unsigned.
										//typedef unsigned long long	uint64;		// 64-bit unsigned.

// Signed base types.
typedef	signed char			int8;		// 8-bit  signed.
typedef signed int			int16;		// 16-bit signed.
typedef signed long	 		int32;		// 32-bit signed.
										//typedef signed long long	int64;		// 64-bit signed.

/*-----------------------------------------------------------------------------
	Constants
-----------------------------------------------------------------------------*/

enum 
{
	/** How often print data to the serial. */
	SERIAL_TIMER_REFRESH_MS = 1000
}; 