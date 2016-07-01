#pragma once

#ifdef WIN32

#include <Windows.h>

#define NBioAPI               __stdcall

#define NBioAPI_NULL          NULL

typedef signed char           NBioAPI_SINT8;
typedef unsigned char         NBioAPI_UINT8;
typedef signed short          NBioAPI_SINT16;
typedef unsigned short        NBioAPI_UINT16;
typedef signed int            NBioAPI_SINT32;
typedef unsigned int          NBioAPI_UINT32;
typedef signed __int64        NBioAPI_SINT64;
typedef unsigned __int64      NBioAPI_UINT64;
typedef signed long           NBioAPI_SLONG;
typedef unsigned long         NBioAPI_ULONG;
typedef double                NBioAPI_DOUBLE;
typedef float                 NBioAPI_FLOAT;

typedef INT_PTR               NBioAPI_SINT;
typedef UINT_PTR              NBioAPI_UINT;

typedef BOOL                  NBioAPI_BOOL;

typedef char                  NBioAPI_CHAR;
typedef wchar_t               NBioAPI_WCHAR;
typedef unsigned char         NBioAPI_BYTE;

typedef NBioAPI_CHAR*         NBioAPI_CHAR_PTR;
typedef NBioAPI_WCHAR*        NBioAPI_WCHAR_PTR;
typedef NBioAPI_BYTE*         NBioAPI_BYTE_PTR;

typedef HWND                  NBioAPI_HWND;

typedef void*                 NBioAPI_VOID_PTR;

#define NBioAPI_FALSE         (0)
#define NBioAPI_TRUE          (!NBioAPI_FALSE)

#else

#define NBioAPI                

#define NBioAPI_NULL             0

typedef signed char              NBioAPI_SINT8;
typedef unsigned char            NBioAPI_UINT8;
typedef signed short             NBioAPI_SINT16;
typedef unsigned short           NBioAPI_UINT16;
typedef signed int               NBioAPI_SINT32;
typedef unsigned int             NBioAPI_UINT32;
typedef long long int            NBioAPI_SINT64;
typedef unsigned long long int   NBioAPI_UINT64;
typedef signed long              NBioAPI_SLONG;
typedef unsigned long            NBioAPI_ULONG;
typedef double                   NBioAPI_DOUBLE;
typedef float                    NBioAPI_FLOAT;

typedef long                     NBioAPI_SINT;
typedef unsigned long            NBioAPI_UINT;

typedef int                      NBioAPI_BOOL;

typedef char                     NBioAPI_CHAR;
typedef wchar_t                  NBioAPI_WCHAR;
typedef unsigned char            NBioAPI_BYTE;

typedef NBioAPI_CHAR*            NBioAPI_CHAR_PTR;
typedef NBioAPI_WCHAR*           NBioAPI_WCHAR_PTR;
typedef NBioAPI_BYTE*            NBioAPI_BYTE_PTR;

typedef NBioAPI_CHAR_PTR         LPSTR;
typedef NBioAPI_CHAR             CHAR;
typedef const char*              LPCTSTR;
typedef void*                    HINSTANCE;
typedef NBioAPI_UINT32           NBioAPI_HWND;

typedef void*                    NBioAPI_VOID_PTR;

#define NBioAPI_FALSE            (0)
#define NBioAPI_TRUE             (!NBioAPI_FALSE)

#endif // WIN32

/* Macros for byte-order conversion */
#ifndef LITTLE_ENDIAN   
#ifndef _UNIX
#define LITTLE_ENDIAN
#endif
#endif

#ifdef LITTLE_ENDIAN
#define EndianChange4(a)	(a)
#define EndianChange2(a)	(a)
#else
#define EndianChange4(val)\
   (\
   (((val) & 0xff000000) >> 24) | (((val) & 0x00ff0000) >> 8) |   \
   (((val) & 0x0000ff00) << 8) | (((val) & 0x000000ff) << 24)     \
   )
#define EndianChange2(val)\
   ((((val) & 0xff00) >> 8) | (((val) & 0x00ff) << 8))
#endif
