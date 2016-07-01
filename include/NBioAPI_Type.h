#pragma once

#include "NBioAPI_Basic.h"

/*!
   \file NBioAPI_Type.h
   \brief eNBioBSP SDK type definition header
*/

/*!
   NBioAPI_FIR_VERSION
*/
typedef NBioAPI_UINT16  NBioAPI_FIR_VERSION;

/*!
   \struct NBioAPI_VERSION
   \brief Ex) v3.12 (Build No.34) : Major = 3, Minor = 1234
*/
typedef struct nbioapi_version 
{
   NBioAPI_UINT32      Major;    //!< Major version information
   NBioAPI_UINT32      Minor;    //!< Minor version information
} NBioAPI_VERSION, * NBioAPI_VERSION_PTR;

/*!
   NBioAPI_FIR_DATA_TYPE
*/
typedef NBioAPI_UINT16   NBioAPI_FIR_DATA_TYPE;
#define NBioAPI_FIR_DATA_TYPE_RAW               (0x00)
#define NBioAPI_FIR_DATA_TYPE_INTERMEDIATE      (0x01)
#define NBioAPI_FIR_DATA_TYPE_PROCESSED         (0x02)
#define NBioAPI_FIR_DATA_TYPE_ENCRYPTED         (0x10)
#define NBioAPI_FIR_DATA_TYPE_LINEPATTERN       (0x20)

/*!
   NBioAPI_FIR_PURPOSE
*/
typedef NBioAPI_UINT16   NBioAPI_FIR_PURPOSE;
#define NBioAPI_FIR_PURPOSE_VERIFY                          (0x01)
#define NBioAPI_FIR_PURPOSE_IDENTIFY                        (0x02)
#define NBioAPI_FIR_PURPOSE_ENROLL                          (0x03)
#define NBioAPI_FIR_PURPOSE_ENROLL_FOR_VERIFICATION_ONLY    (0x04)
#define NBioAPI_FIR_PURPOSE_ENROLL_FOR_IDENTIFICATION_ONLY  (0x05)
#define NBioAPI_FIR_PURPOSE_AUDIT                           (0x06)
#define NBioAPI_FIR_PURPOSE_UPDATE                          (0x10)

/*!
   NBioAPI_FIR_QUALITY
*/
typedef NBioAPI_UINT16   NBioAPI_FIR_QUALITY;

/*!
   \struct NBioAPI_FIR_HEADER
   \brief eNBioBSP SDK FIR header data format
*/
typedef struct nbioapi_fir_header 
{
   NBioAPI_UINT32          Length;        //!< Header Length
   NBioAPI_UINT32          DataLength;    //!< Data Length
   NBioAPI_FIR_VERSION     Version;       //!< FIR version
   NBioAPI_FIR_DATA_TYPE   DataType;      //!< FIR data type
   NBioAPI_FIR_PURPOSE     Purpose;       //!< FIR purpose
   NBioAPI_FIR_QUALITY     Quality;       //!< FIR Quality
   NBioAPI_UINT32          Reserved;      //!< Reserved
} NBioAPI_FIR_HEADER, * NBioAPI_FIR_HEADER_PTR;

/*!
   NBioAPI_FIR_DATA
*/
typedef NBioAPI_UINT8   NBioAPI_FIR_DATA;

/*!
   NBioAPI_FIR_FORMAT
*/
typedef NBioAPI_UINT32  NBioAPI_FIR_FORMAT;
#define NBioAPI_FIR_FORMAT_STANDARD          (1)
#define NBioAPI_FIR_FORMAT_NBAS              (2)
#define NBioAPI_FIR_FORMAT_EXTENSION         (3)
#define NBioAPI_FIR_FORMAT_STANDARD_AES      (4)
#define NBioAPI_FIR_FORMAT_STANDARD_3DES     (5)
#define NBioAPI_FIR_FORMAT_STANDARD_256AES   (6)

/*!
   \struct NBioAPI_FIR
   \brief eNBioBSP SDK FIR data format
*/
typedef struct nbioapi_fir 
{
   NBioAPI_FIR_FORMAT   Format;     //!< FIR format
   NBioAPI_FIR_HEADER   Header;     //!< FIR header information
   NBioAPI_FIR_DATA*    Data;       //!< FIR data pointer
} NBioAPI_FIR, * NBioAPI_FIR_PTR;

/*!
   \struct NBioAPI_FIR_PAYLOAD
   \brief eNBioBSP SDK Payload data format
*/
typedef struct nbioapi_fir_payload 
{
   NBioAPI_UINT32       Length;     //!< Payload data length
   NBioAPI_UINT8*       Data;       //!< payload data pointer
} NBioAPI_FIR_PAYLOAD, * NBioAPI_FIR_PAYLOAD_PTR;

/*!
   NBioAPI_HANDLE
*/
typedef NBioAPI_UINT                NBioAPI_HANDLE;
typedef NBioAPI_UINT*               NBioAPI_HANDLE_PTR;
#define NBioAPI_INVALID_HANDLE      (0)

/*!
   NBioAPI_FIR_HANDLE
*/
typedef NBioAPI_UINT    NBioAPI_FIR_HANDLE;
typedef NBioAPI_UINT*   NBioAPI_FIR_HANDLE_PTR;

/*!
   NBioAPI_FIR_SECURITY_LEVEL
*/
typedef NBioAPI_UINT32   NBioAPI_FIR_SECURITY_LEVEL;
#define NBioAPI_FIR_SECURITY_LEVEL_LOWEST        (1)
#define NBioAPI_FIR_SECURITY_LEVEL_LOWER         (2)
#define NBioAPI_FIR_SECURITY_LEVEL_LOW           (3)
#define NBioAPI_FIR_SECURITY_LEVEL_BELOW_NORMAL  (4)
#define NBioAPI_FIR_SECURITY_LEVEL_NORMAL        (5)
#define NBioAPI_FIR_SECURITY_LEVEL_ABOVE_NORMAL  (6)
#define NBioAPI_FIR_SECURITY_LEVEL_HIGH          (7)
#define NBioAPI_FIR_SECURITY_LEVEL_HIGHER        (8)
#define NBioAPI_FIR_SECURITY_LEVEL_HIGHEST       (9)

/*!
   \struct NBioAPI_INIT_INFO_0
   \brief eNBioBSP SDK Initial information
*/
typedef struct nbioapi_init_info_0 
{
   NBioAPI_UINT32                StructureType;           //!< must be 0
   NBioAPI_UINT32                MaxFingersForEnroll;     //!< Default = 10
   NBioAPI_UINT32                SamplesPerFinger;        //!< Default = 2 : not used
   NBioAPI_UINT32                DefaultTimeout;          //!< Default = 10000ms = 10sec
   NBioAPI_UINT32                EnrollImageQuality;      //!< Default = 50
   NBioAPI_UINT32                VerifyImageQuality;      //!< Default = 30
   NBioAPI_UINT32                IdentifyImageQuality;    //!< Default = 50
   NBioAPI_FIR_SECURITY_LEVEL    SecurityLevel;           //!< Default = NBioAPI_FIR_SECURITY_LEVEL_NORMAL
} NBioAPI_INIT_INFO_0, * NBioAPI_INIT_INFO_PTR_0;

/*!
   \struct NBioAPI_INIT_INFO_1
   \brief eNBioBSP SDK Initial information
*/
typedef struct nbioapi_init_info_1 
{
   NBioAPI_UINT32                StructureType;           //!< must be 1
   NBioAPI_FIR_SECURITY_LEVEL    SecurityLevelForEnroll;  //!< Default = NBioAPI_FIR_SECURITY_LEVEL_NORMAL
   NBioAPI_UINT32                NecessaryEnrollNum;      //!< Default = 0 : Depends on MaxFingersForEnroll
   NBioAPI_UINT32                Reserved1;               //!< Reserved
   NBioAPI_UINT32                Reserved2;               //!< Reserved
   NBioAPI_UINT32                Reserved3;               //!< Reserved
   NBioAPI_UINT32                Reserved4;               //!< Reserved
   NBioAPI_UINT32                Reserved5;               //!< Reserved
   NBioAPI_UINT32                Reserved6;               //!< Reserved
   NBioAPI_UINT32                Reserved7;               //!< Reserved
} NBioAPI_INIT_INFO_1, * NBioAPI_INIT_INFO_PTR_1;

/*!
   NBioAPI_INIT_INFO_PTR
*/
typedef NBioAPI_VOID_PTR    NBioAPI_INIT_INFO_PTR;

/*!
   \struct NBioAPI_DEVICE_INFO_0
   \brief eNBioBSP SDK Device information
*/
typedef struct nbioapi_device_info_0 
{
   NBioAPI_UINT32    StructureType;    //!< must be 0
   NBioAPI_UINT32    ImageWidth;       //!< Image Width(Read Only)
   NBioAPI_UINT32    ImageHeight;      //!< Image Height(Read Only)
   NBioAPI_UINT32    Brightness;       //!< Brightness information
   NBioAPI_UINT32    Contrast;         //!< Contrast information
   NBioAPI_UINT32    Gain;             //!< Gain information
} NBioAPI_DEVICE_INFO_0, * NBioAPI_DEVICE_INFO_PTR_0;

/*!
   NBioAPI_DEVICE_INFO_PTR
*/
typedef NBioAPI_VOID_PTR    NBioAPI_DEVICE_INFO_PTR;

/*!
   NBioAPI_DEVICE_ID<br>
   high one byte : device instance<br>
   low one byte : device name
*/
typedef NBioAPI_UINT16           NBioAPI_DEVICE_ID; 
#define NBioAPI_DEVICE_ID_NONE   (0x0000)
#define NBioAPI_DEVICE_ID_AUTO   (0x00ff)

/*!
   NBioAPI_DEVICE_NAME
*/
typedef NBioAPI_UINT8                        NBioAPI_DEVICE_NAME; 
#define NBioAPI_DEVICE_NAME_FDP02            (0x01)      // Parallel type
#define NBioAPI_DEVICE_NAME_FDU01            (0x02)      // USB type HFDU 01/04/06
#define NBioAPI_DEVICE_NAME_OSU02            (0x03)      // Not used..
#define NBioAPI_DEVICE_NAME_FDU11            (0x04)      // USB type HFUD 11/14
#define NBioAPI_DEVICE_NAME_FSC01            (0x05)      // SmartCombo
#define NBioAPI_DEVICE_NAME_FDU03            (0x06)      // USB type Mouse
#define NBioAPI_DEVICE_NAME_FDU05            (0x07)      // USB type HFDU 05/07
#define NBioAPI_DEVICE_NAME_FDU08            (0x08)      // USB type PFDU 08

#define NBioAPI_DEVICE_NAME_ADDITIONAL       (0x10)      // Additional Device
#define NBioAPI_DEVICE_NAME_ADDITIONAL_MAX   (0x9F)   

//////////////////////////////////////////////////////////////////////////
// NBioAPI_DEVICE_NAME_NND (NND: No NITGEN Device)
#define NBioAPI_DEVICE_NAME_NND_URU4KB       (0xA1)      // UareU4000B
#define NBioAPI_DEVICE_NAME_NND_FPC6410      (0xA2)      // FPC6410

//////////////////////////////////////////////////////////////////////////
// NBioAPI_MAX_DEVICE
#define NBioAPI_MAX_DEVICE                   (0xfe)

/*!
   NBioAPI_RETURN
*/
typedef NBioAPI_UINT32  NBioAPI_RETURN;

/*!
   \struct NBioAPI_FIR_TEXTENCODE
   \brief eNBioBSP SDK Text FIR information
*/
typedef struct nbioapi_fir_textencode 
{
   NBioAPI_BOOL      IsWideChar;       //!< Is wide string
   NBioAPI_CHAR_PTR  TextFIR;          //!< Text FIR data pointer
} NBioAPI_FIR_TEXTENCODE, * NBioAPI_FIR_TEXTENCODE_PTR;

/*!
   NBioAPI_INPUT_FIR_FORM
*/
typedef NBioAPI_UINT8                  NBioAPI_INPUT_FIR_FORM;
#define NBioAPI_FIR_FORM_HANDLE        (0x02)
#define NBioAPI_FIR_FORM_FULLFIR       (0x03)
#define NBioAPI_FIR_FORM_TEXTENCODE    (0x04)

/*!
   \struct NBioAPI_INPUT_FIR
   \brief eNBioBSP SDK Input FIR information
*/
typedef struct nbioapi_input_fir 
{
   NBioAPI_INPUT_FIR_FORM  Form;                //!< Input FIR form type

   union 
   {
      NBioAPI_FIR_HANDLE_PTR     FIRinBSP;      //!< Memory handle pointer
      NBioAPI_VOID_PTR           FIR;           //!< Binary data pointer
      NBioAPI_FIR_TEXTENCODE_PTR TextFIR;       //!< text data pointer
   } InputFIR;
} NBioAPI_INPUT_FIR, * NBioAPI_INPUT_FIR_PTR;

//////////////////////////////////////////////////////////////////////////
// Capture time out
#define NBioAPI_NO_TIMEOUT              (0)
#define NBioAPI_USE_DEFAULT_TIMEOUT     (-1)
#define NBioAPI_CONTINUOUS_CAPTRUE      (-2)

/*!
   NBioAPI_WINDOW_STYLE
*/
typedef NBioAPI_UINT32                    NBioAPI_WINDOW_STYLE;
#define NBioAPI_WINDOW_STYLE_POPUP        (0)
#define NBioAPI_WINDOW_STYLE_INVISIBLE    (1)            // only for NBioAPI_Capture()
#define NBioAPI_WINDOW_STYLE_CONTINUOUS   (2)

//////////////////////////////////////////////////////////////////////////
// OR flag used only in high 2 bytes.
#define NBioAPI_WINDOW_STYLE_NO_FPIMG     (0x00010000)   // Or flag
#define NBioAPI_WINDOW_STYLE_TOPMOST      (0x00020000)   // Or flag : default flag and not used after v2.3 (WinCE v1.2)
#define NBioAPI_WINDOW_STYLE_NO_WELCOME   (0x00040000)   // Or flag : only for enroll
#define NBioAPI_WINDOW_STYLE_NO_TOPMOST   (0x00080000)   // Or flag : additional flag after v2.3 (WinCE v1.2)

/*!
   \struct NBioAPI_WINDOW_CALLBACK_PARAM_EX
   \brief eNBioBSP SDK Capture callback parameter
*/
typedef struct nbioapi_window_callback_param_ex 
{
   NBioAPI_UINT32    dwDeviceError;          //!< Device error code
   NBioAPI_UINT32    dwReserved[8];          //!< Reserved array
   NBioAPI_VOID_PTR  lpReserved;             //!< Reserved
} NBioAPI_WINDOW_CALLBACK_PARAM_EX, * NBioAPI_WINDOW_CALLBACK_PARAM_PTR_EX;

/*!
   \struct NBioAPI_WINDOW_CALLBACK_PARAM_0
   \brief eNBioBSP SDK Capture callback parameter
*/
typedef struct nbioapi_window_callback_param_0 
{
   NBioAPI_UINT32    dwQuality;                       //!< Current image quality
   NBioAPI_UINT8*    lpImageBuf;                      //!< Current image buffer
   NBioAPI_WINDOW_CALLBACK_PARAM_PTR_EX  pParamEx;    //!< ParamEx struct pointer
} NBioAPI_WINDOW_CALLBACK_PARAM_0, * NBioAPI_WINDOW_CALLBACK_PARAM_PTR_0;

/*!
   \struct NBioAPI_WINDOW_CALLBACK_PARAM_1_1
   \brief eNBioBSP SDK Capture callback parameter
*/
typedef struct nbioapi_window_callback_param_1_1 
{
   NBioAPI_UINT32    dwStartTime;      //!< Capture start time
   NBioAPI_UINT32    dwCapTime;        //!< Capture time
   NBioAPI_UINT32    dwEndTime;        //!< Capture end time

   NBioAPI_UINT32    Reserved1;        //!< Reserved
   NBioAPI_UINT32    Reserved2;        //!< Reserved
   NBioAPI_UINT32    Reserved3;        //!< Reserved
   NBioAPI_UINT32    Reserved4;        //!< Reserved
   NBioAPI_UINT32    Reserved5;        //!< Reserved
   NBioAPI_UINT32    Reserved6;        //!< Reserved
   NBioAPI_UINT32    Reserved7;        //!< Reserved
   NBioAPI_UINT32    Reserved8;        //!< Reserved

   NBioAPI_VOID_PTR  lpReserved;       //!< Reserved
} NBioAPI_WINDOW_CALLBACK_PARAM_1_1, * NBioAPI_WINDOW_CALLBACK_PARAM_PTR_1_1;

/*!
   \struct NBioAPI_WINDOW_CALLBACK_PARAM_1
   \brief eNBioBSP SDK Capture callback parameter
*/
typedef struct nbioapi_window_callback_param_1 
{
   NBioAPI_UINT32    dwResult;                              //!< Result code
   NBioAPI_WINDOW_CALLBACK_PARAM_PTR_1_1  lpCBParam1_1;     //!< NBioAPI_WINDOW_CALLBACK_PARAM_1_1 sturct pointer
} NBioAPI_WINDOW_CALLBACK_PARAM_1, * NBioAPI_WINDOW_CALLBACK_PARAM_PTR_1;

//////////////////////////////////////////////////////////////////////////
// NBioAPI_WINDOW_CALLBACK_PARAM_PTR
//typedef NBioAPI_VOID_PTR   NBioAPI_WINDOW_CALLBACK_PARAM_PTR;

/*!
   NBioAPI_WINDOW_CALLBACK_0
*/
typedef NBioAPI_RETURN (NBioAPI* NBioAPI_WINDOW_CALLBACK_0)(NBioAPI_WINDOW_CALLBACK_PARAM_PTR_0, NBioAPI_VOID_PTR);
/*!
   NBioAPI_WINDOW_CALLBACK_1
*/
typedef NBioAPI_RETURN (NBioAPI* NBioAPI_WINDOW_CALLBACK_1)(NBioAPI_WINDOW_CALLBACK_PARAM_PTR_1, NBioAPI_VOID_PTR);

/*!
   \struct NBioAPI_CALLBACK_INFO_0
   \brief eNBioBSP SDK Capture callback information
*/
typedef struct nbioapi_callback_info_0 
{
   NBioAPI_UINT32             CallBackType;           //!< Callback type
   NBioAPI_WINDOW_CALLBACK_0  CallBackFunction;       //!< Callback function pointer
   NBioAPI_VOID_PTR           UserCallBackParam;      //!< Callback parameter pointer
} NBioAPI_CALLBACK_INFO_0, * NBioAPI_CALLBACK_INFO_PTR_0;

/*!
   \struct NBioAPI_CALLBACK_INFO_1
   \brief eNBioBSP SDK Capture callback information
*/
typedef struct nbioapi_callback_info_1 
{
   NBioAPI_UINT32             CallBackType;           //!< Callback type
   NBioAPI_WINDOW_CALLBACK_1  CallBackFunction;       //!< Callback function pointer
   NBioAPI_VOID_PTR           UserCallBackParam;      //!< Callback parameter pointer
} NBioAPI_CALLBACK_INFO_1, * NBioAPI_CALLBACK_INFO_PTR_1;

/*!
   \struct NBioAPI_WINDOW_OPTION_2
   \brief eNBioBSP SDK Capture option
*/
typedef struct nbioapi_window_option_2 
{
   NBioAPI_UINT8           FPForeColor[3];                  //!< Fingerprint RGB color
   NBioAPI_UINT8           FPBackColor[3];                  //!< Background RGB color
   NBioAPI_UINT8           DisableFingerForEnroll[10];      //!< 0 = Enable, 1 = Disable / [0] = Right Thumb, ... [5] = Left Thumb, ... [9] = Left little
   NBioAPI_UINT32          Reserved1[4];                    //!< Reserved
   NBioAPI_VOID_PTR        Reserved2;                       //!< Reserved
} NBioAPI_WINDOW_OPTION_2, * NBioAPI_WINDOW_OPTION_PTR_2;

/*!
   \struct NBioAPI_WINDOW_OPTION
   \brief eNBioBSP SDK Capture option
*/
typedef struct nbioapi_window_option 
{
   NBioAPI_UINT32                Length;                 //!< length
   NBioAPI_WINDOW_STYLE          WindowStyle;            //!< UI style
   NBioAPI_HWND                  ParentWnd;              //!< Parent window handle
   NBioAPI_HWND                  FingerWnd;              //!< Finger draw window handle(only for .._STYLE_INVISIBLE)
   NBioAPI_CALLBACK_INFO_0       CaptureCallBackInfo;    //!< CallBackType = 0
   NBioAPI_CALLBACK_INFO_1       FinishCallBackInfo;     //!< CallBackType = 1
   NBioAPI_CHAR_PTR              CaptionMsg;             //!< Caption message string
   NBioAPI_CHAR_PTR              CancelMsg;              //!< Cancel message string
   NBioAPI_WINDOW_OPTION_PTR_2   Option2;                //!< Default : NULL
} NBioAPI_WINDOW_OPTION, * NBioAPI_WINDOW_OPTION_PTR;

/*!
   MINCONV_DATA_TYPE for ConvertMinDataToFIRHandle()
*/
enum MINCONV_DATA_TYPE
{
   MINCONV_TYPE_FDP = 0,            //!< FDP device
   MINCONV_TYPE_FDU,                //!< FDU device
   MINCONV_TYPE_FDA,                //!< FDA device
   MINCONV_TYPE_OLD_FDA,            //!< Old FDA device
   MINCONV_TYPE_FDAC,               //!< FDAC device

   // Below type is supported after v4.10
   MINCONV_TYPE_FIM10_HV,           //!< FIM10 HV
   MINCONV_TYPE_FIM10_LV,           //!< FIM10 LV
   MINCONV_TYPE_FIM01_HV,           //!< FIM01 HV 404bytes (Header 4bytes + Template 400bytes)
   MINCONV_TYPE_FIM01_HD,           //!< FIM01 HD
   MINCONV_TYPE_FELICA,             //!< Felica 200bytes

   MINCONV_TYPE_EXTENSION,          //!< 1024bytes

   MINCONV_TYPE_TEMPLATESIZE_32,    //!< 11, Currently does not support
   MINCONV_TYPE_TEMPLATESIZE_48,    //!< Currently does not support
   MINCONV_TYPE_TEMPLATESIZE_64,    //!< Currently does not support
   MINCONV_TYPE_TEMPLATESIZE_80,    //!< Currently does not support
   MINCONV_TYPE_TEMPLATESIZE_96,    //!< Currently does not support
   MINCONV_TYPE_TEMPLATESIZE_112,   //!< Currently does not support
   MINCONV_TYPE_TEMPLATESIZE_128,   //!< 128bytes
   MINCONV_TYPE_TEMPLATESIZE_144,   //!< 144bytes
   MINCONV_TYPE_TEMPLATESIZE_160,   //!< 160bytes
   MINCONV_TYPE_TEMPLATESIZE_176,   //!< 176bytes
   MINCONV_TYPE_TEMPLATESIZE_192,   //!< 192bytes
   MINCONV_TYPE_TEMPLATESIZE_208,   //!< 208bytes
   MINCONV_TYPE_TEMPLATESIZE_224,   //!< 224bytes
   MINCONV_TYPE_TEMPLATESIZE_240,   //!< 240bytes
   MINCONV_TYPE_TEMPLATESIZE_256,   //!< 256bytes
   MINCONV_TYPE_TEMPLATESIZE_272,   //!< 272bytes
   MINCONV_TYPE_TEMPLATESIZE_288,   //!< 288bytes
   MINCONV_TYPE_TEMPLATESIZE_304,   //!< 304bytse
   MINCONV_TYPE_TEMPLATESIZE_320,   //!< 320bytes
   MINCONV_TYPE_TEMPLATESIZE_336,   //!< 336bytes
   MINCONV_TYPE_TEMPLATESIZE_352,   //!< 352bytes
   MINCONV_TYPE_TEMPLATESIZE_368,   //!< 368bytes
   MINCONV_TYPE_TEMPLATESIZE_384,   //!< 384bytes
   MINCONV_TYPE_TEMPLATESIZE_400,   //!< 500bytes

   MINCONV_TYPE_ANSI,               //!< ANSI378
   MINCONV_TYPE_ISO,                //!< ISO 19794-2

   MINCONV_TYPE_MAX                 //!< Max
};

/*!
   NBioAPI_FINGER_ID
*/
typedef NBioAPI_UINT8                     NBioAPI_FINGER_ID;
#define NBioAPI_FINGER_ID_UNKNOWN         (0)
#define NBioAPI_FINGER_ID_RIGHT_THUMB     (1)
#define NBioAPI_FINGER_ID_RIGHT_INDEX     (2)
#define NBioAPI_FINGER_ID_RIGHT_MIDDLE    (3)
#define NBioAPI_FINGER_ID_RIGHT_RING      (4)
#define NBioAPI_FINGER_ID_RIGHT_LITTLE    (5)
#define NBioAPI_FINGER_ID_LEFT_THUMB      (6)
#define NBioAPI_FINGER_ID_LEFT_INDEX      (7)
#define NBioAPI_FINGER_ID_LEFT_MIDDLE     (8)
#define NBioAPI_FINGER_ID_LEFT_RING       (9)
#define NBioAPI_FINGER_ID_LEFT_LITTLE     (10)
#define NBioAPI_FINGER_ID_MAX             (11)

//////////////////////////////////////////////////////////////////////////
// Make device ID
#define NBioAPI_MAKEDEVICEID(deviceName, instanceNum) ( ((instanceNum & 0x00FF) << 8) + (deviceName & 0x00FF) )

/*!
   \struct NBioAPI_MATCH_OPTION_0
   \brief eNBioBSP SDK Match option
*/
typedef struct nbioapi_match_option_0 
{
   NBioAPI_UINT8    StructureType;                          //!< must be 0
   NBioAPI_UINT8    NoMatchFinger[NBioAPI_FINGER_ID_MAX];   //!< 0 = Match, 1 = Sample1 not match, 2 = Sample2 not match, 3 = Not match
   NBioAPI_UINT32   Reserved[8];                            //!< Reserved
} NBioAPI_MATCH_OPTION_0, * NBioAPI_MATCH_OPTION_PTR_0;

/*!
   NBioAPI_MATCH_OPTION_PTR
*/
typedef NBioAPI_VOID_PTR    NBioAPI_MATCH_OPTION_PTR;

//////////////////////////////////////////////////////////////////////////
// NBioAPI_QUALITY
#define NBioAPI_QUALITY_NONE        (0)
#define NBioAPI_QUALITY_BAD         (1)
#define NBioAPI_QUALITY_POOR        (2)
#define NBioAPI_QUALITY_NORMAL      (3)
#define NBioAPI_QUALITY_GOOD        (4)
#define NBioAPI_QUALITY_EXCELLENT   (5)

/*!
   NBioAPI_QUALITY
*/
typedef NBioAPI_UINT8   NBioAPI_QUALITY;

/*!
   \struct NBioAPI_QUALITY_INFO_0
   \brief eNBioBSP SDK Quality information
*/
typedef struct nbioapi_quality_info_0 
{
   NBioAPI_UINT8    StructureType;                       //!< must be 0
   NBioAPI_QUALITY  Quality[NBioAPI_FINGER_ID_MAX][2];   //!< NBioAPI_QUALITY : 0 ~ 5
   NBioAPI_UINT32   Reserved[4];                         //!< reserved
} NBioAPI_QUALITY_INFO_0, * NBioAPI_QUALITY_INFO_PTR_0;

/*!
   \struct NBioAPI_QUALITY_INFO_1
   \brief eNBioBSP SDK Quality information
*/
typedef struct nbioapi_quality_info_1 
{
   NBioAPI_UINT8    StructureType;                       //!< must be 1
   NBioAPI_UINT8    Quality[NBioAPI_FINGER_ID_MAX][2];   //!< 0 ~ 100
   NBioAPI_UINT32   Reserved[4];                         //!< reserved
} NBioAPI_QUALITY_INFO_1, * NBioAPI_QUALITY_INFO_PTR_1;

/*!
   NBioAPI_QUALITY_INFO_PTR
*/
typedef NBioAPI_VOID_PTR   NBioAPI_QUALITY_INFO_PTR;

/*!
   \struct NBioAPI_DEVICE_INFO_EX
   \brief eNBioBSP SDK Device information extension
*/
typedef struct nbioapi_deviceinfoex 
{
   NBioAPI_DEVICE_ID NameID;                 //!< Device ID
   NBioAPI_UINT16    Instance;               //!< Instance value

   NBioAPI_CHAR      Name[64];               //!< Name string
   NBioAPI_CHAR      Description[256];       //!< Description string
   NBioAPI_CHAR      Dll[64];                //!< Dll name string
   NBioAPI_CHAR      Sys[64];                //!< Sys name string

   NBioAPI_UINT32    AutoOn;                 //!< Is support Auto-on
   NBioAPI_UINT32    Brightness;             //!< Brightness value
   NBioAPI_UINT32    Contrast;               //!< Contrast value
   NBioAPI_UINT32    Gain;                   //!< Gain value

   NBioAPI_UINT32    Reserved[8];            //!< reserved
} NBioAPI_DEVICE_INFO_EX, *NBioAPI_DEVICE_INFO_EX_PTR;
