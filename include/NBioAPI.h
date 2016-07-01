#pragma once

#include "NBioAPI_Basic.h"
#include "NBioAPI_Type.h"
#include "NBioAPI_Error.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _NBioAPI_LOAD_LIBRARY

   /* Initializing Functions */
   NBioAPI_RETURN NBioAPI NBioAPI_Init       (NBioAPI_HANDLE_PTR  phHandle);
   NBioAPI_RETURN NBioAPI NBioAPI_Terminate  (NBioAPI_HANDLE hHandle);

   /* Validity Check Function */
   NBioAPI_RETURN NBioAPI NBioAPI_GetValidityCode(NBioAPI_HANDLE hHandle, NBioAPI_UINT32 Code1, NBioAPI_UINT32 Code2, NBioAPI_UINT32 Code3, NBioAPI_UINT32 Code4, NBioAPI_UINT32* pResult1, NBioAPI_UINT32* pResult2);

   /* Basic Functions */
   NBioAPI_RETURN NBioAPI NBioAPI_GetVersion (NBioAPI_HANDLE hHandle, NBioAPI_VERSION_PTR  pVersion);
   NBioAPI_RETURN NBioAPI NBioAPI_GetInitInfo(NBioAPI_HANDLE hHandle, NBioAPI_UINT8 nStructureType, NBioAPI_INIT_INFO_PTR pInitInfo);
   NBioAPI_RETURN NBioAPI NBioAPI_SetInitInfo(NBioAPI_HANDLE hHandle, NBioAPI_UINT8 nStructureType, NBioAPI_INIT_INFO_PTR pInitInfo);
   
   /* Device Functions */
   NBioAPI_RETURN NBioAPI NBioAPI_EnumerateDevice(NBioAPI_HANDLE hHandle, NBioAPI_UINT32* pNumDevice, NBioAPI_DEVICE_ID** ppDeviceID);
   NBioAPI_RETURN NBioAPI NBioAPI_EnumerateDeviceEx(NBioAPI_HANDLE  hHandle, 
                                                 NBioAPI_UINT32* pNumDevice, 
                                                 NBioAPI_DEVICE_ID** ppDeviceID, 
                                                 NBioAPI_DEVICE_INFO_EX** ppDeviceInfoEx);

   NBioAPI_RETURN NBioAPI NBioAPI_OpenDevice     (NBioAPI_HANDLE hHandle, NBioAPI_DEVICE_ID nDeviceID);
   NBioAPI_RETURN NBioAPI NBioAPI_CloseDevice    (NBioAPI_HANDLE hHandle, NBioAPI_DEVICE_ID nDeviceID);
   NBioAPI_RETURN NBioAPI NBioAPI_GetDeviceInfo  (NBioAPI_HANDLE hHandle, NBioAPI_DEVICE_ID nDeviceID, NBioAPI_UINT8 nStructureType, NBioAPI_DEVICE_INFO_PTR pDeviceInfo);
   NBioAPI_RETURN NBioAPI NBioAPI_SetDeviceInfo  (NBioAPI_HANDLE hHandle, NBioAPI_DEVICE_ID nDeviceID, NBioAPI_UINT8 nStructureType, NBioAPI_DEVICE_INFO_PTR pDeviceInfo);
   NBioAPI_RETURN NBioAPI NBioAPI_AdjustDevice   (NBioAPI_HANDLE hHandle, const NBioAPI_WINDOW_OPTION_PTR pWindowOption);
   NBioAPI_DEVICE_ID NBioAPI NBioAPI_GetOpenedDeviceID(NBioAPI_HANDLE hHandle);
   
   /* Memory Functions */
   NBioAPI_RETURN NBioAPI NBioAPI_FreeFIRHandle       (NBioAPI_HANDLE hHandle, NBioAPI_FIR_HANDLE hFIR);
   NBioAPI_RETURN NBioAPI NBioAPI_GetFIRFromHandle    (NBioAPI_HANDLE hHandle, NBioAPI_FIR_HANDLE hFIR, NBioAPI_FIR_PTR pFIR);
   NBioAPI_RETURN NBioAPI NBioAPI_GetHeaderFromHandle (NBioAPI_HANDLE hHandle, NBioAPI_FIR_HANDLE hFIR, NBioAPI_FIR_HEADER_PTR pHeader);
   NBioAPI_RETURN NBioAPI NBioAPI_GetExtendedFIRFromHandle   (NBioAPI_HANDLE hHandle, NBioAPI_FIR_HANDLE hFIR, NBioAPI_VOID_PTR pFIR, NBioAPI_FIR_FORMAT Format);
   NBioAPI_RETURN NBioAPI NBioAPI_GetExtendedHeaderFromHandle(NBioAPI_HANDLE hHandle, NBioAPI_FIR_HANDLE hFIR, NBioAPI_VOID_PTR pHeader, NBioAPI_FIR_FORMAT Format);
   NBioAPI_RETURN NBioAPI NBioAPI_FreeFIR             (NBioAPI_HANDLE hHandle, NBioAPI_VOID_PTR pFIR);
   NBioAPI_RETURN NBioAPI NBioAPI_FreePayload         (NBioAPI_HANDLE hHandle, NBioAPI_FIR_PAYLOAD_PTR pPayload);
   
   /* TextEncode Funtions */
   NBioAPI_RETURN NBioAPI NBioAPI_GetTextFIRFromHandle(NBioAPI_HANDLE hHandle, NBioAPI_FIR_HANDLE hFIR, NBioAPI_FIR_TEXTENCODE_PTR pTextFIR, NBioAPI_BOOL bIsWide);
   NBioAPI_RETURN NBioAPI NBioAPI_GetExtendedTextFIRFromHandle(NBioAPI_HANDLE hHandle, NBioAPI_FIR_HANDLE hFIR, NBioAPI_FIR_TEXTENCODE_PTR pTextFIR, NBioAPI_BOOL bIsWide, NBioAPI_FIR_FORMAT Format);
   NBioAPI_RETURN NBioAPI NBioAPI_FreeTextFIR         (NBioAPI_HANDLE hHandle, NBioAPI_FIR_TEXTENCODE_PTR pTextFIR);

   /* BSP Functions */
   NBioAPI_RETURN NBioAPI NBioAPI_Capture (
                                          NBioAPI_HANDLE                  hHandle, 
                                          NBioAPI_FIR_PURPOSE             nPurpose,
                                          NBioAPI_FIR_HANDLE_PTR          phCapturedFIR,
                                          NBioAPI_SINT32                  nTimeout,
                                          NBioAPI_FIR_HANDLE_PTR          phAuditData,
                                          const NBioAPI_WINDOW_OPTION_PTR pWindowOption);
   
   NBioAPI_RETURN NBioAPI NBioAPI_Process (
                                          NBioAPI_HANDLE                  hHandle, 
                                          const NBioAPI_INPUT_FIR_PTR     piCapturedFIR,
                                          NBioAPI_FIR_HANDLE_PTR          phProcessedFIR);
   
   NBioAPI_RETURN NBioAPI NBioAPI_CreateTemplate (
                                          NBioAPI_HANDLE                  hHandle, 
                                          const NBioAPI_INPUT_FIR_PTR     piCapturedFIR,
                                          const NBioAPI_INPUT_FIR_PTR     piStoredTemplate,
                                          NBioAPI_FIR_HANDLE_PTR          phNewTemplate,
                                          const NBioAPI_FIR_PAYLOAD_PTR   pPayload);
   
   NBioAPI_RETURN NBioAPI NBioAPI_VerifyMatch (
                                          NBioAPI_HANDLE                  hHandle, 
                                          const NBioAPI_INPUT_FIR_PTR     piProcessedFIR,
                                          const NBioAPI_INPUT_FIR_PTR     piStoredTemplate,
                                          NBioAPI_BOOL*                   pbResult,
                                          NBioAPI_FIR_PAYLOAD_PTR         pPayload);
   
   NBioAPI_RETURN NBioAPI NBioAPI_VerifyMatchEx (
                                          NBioAPI_HANDLE                  hHandle, 
                                          const NBioAPI_INPUT_FIR_PTR     piProcessedFIR,
                                          const NBioAPI_INPUT_FIR_PTR     piStoredTemplate,
                                          NBioAPI_BOOL*                   pbResult,
                                          NBioAPI_FIR_PAYLOAD_PTR         pPayload,
                                          NBioAPI_MATCH_OPTION_PTR        pMatchOption);
   
   NBioAPI_RETURN NBioAPI NBioAPI_Enroll (
                                          NBioAPI_HANDLE                  hHandle, 
                                          const NBioAPI_INPUT_FIR_PTR     piStoredTemplate,
                                          NBioAPI_FIR_HANDLE_PTR          phNewTemplate,
                                          const NBioAPI_FIR_PAYLOAD_PTR   pPayload,
                                          NBioAPI_SINT32                  nTimeout,
                                          NBioAPI_FIR_HANDLE_PTR          phAuditData,
                                          const NBioAPI_WINDOW_OPTION_PTR pWindowOption);
   
   NBioAPI_RETURN NBioAPI NBioAPI_Verify (
                                          NBioAPI_HANDLE                  hHandle, 
                                          const NBioAPI_INPUT_FIR_PTR     piStoredTemplate,
                                          NBioAPI_BOOL*                   pbResult,
                                          NBioAPI_FIR_PAYLOAD_PTR         pPayload,
                                          NBioAPI_SINT32                  nTimeout,
                                          NBioAPI_FIR_HANDLE_PTR          phAuditData,
                                          const NBioAPI_WINDOW_OPTION_PTR pWindowOption);
   
   NBioAPI_RETURN NBioAPI NBioAPI_CheckFinger(
                                          NBioAPI_HANDLE                  hHandle, 
                                          NBioAPI_BOOL*                   bFingerExist);
   
   NBioAPI_RETURN NBioAPI NBioAPI_GetQualityInfo (
                                          NBioAPI_HANDLE		              hHandle,
                                          const NBioAPI_INPUT_FIR_PTR	  pAuditData,
                                          const NBioAPI_INPUT_FIR_PTR	  pFIR,
                                          NBioAPI_UINT8                   nStructureType, 
                                          NBioAPI_QUALITY_INFO_PTR        pQualityInfo);
   
   NBioAPI_RETURN NBioAPI NBioAPI_RollCapture (
                                          NBioAPI_HANDLE                  hHandle,
                                          NBioAPI_FIR_PURPOSE             nPurpose,
                                          NBioAPI_SINT32                  nTimeout,
                                          NBioAPI_FIR_HANDLE_PTR          phCapturedFIR,
                                          NBioAPI_FIR_HANDLE_PTR          phAuditData,
                                          const NBioAPI_WINDOW_OPTION_PTR pWindowOption);


#ifdef WIN32
#ifndef _WIN32_WCE
   /* Skin Function */
   NBioAPI_BOOL NBioAPI NBioAPI_SetSkinResource(LPCSTR szResPath);
   NBioAPI_BOOL NBioAPI NBioAPI_SetSkinResourceW(LPCWSTR szResPath);
#endif // _WIN32_WCE
#endif // WIN32
   
#endif/* _NBioAPI_LOAD_LIBRARY */
   
   /* typedef for GetProcAddress() */
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_Init)        (NBioAPI_HANDLE_PTR  phHandle);
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_Terminate)   (NBioAPI_HANDLE hHandle);
   
   /* Validity Check Function */
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_GetValidityCode)(NBioAPI_HANDLE hHandle, NBioAPI_UINT32 Code1, NBioAPI_UINT32 Code2, NBioAPI_UINT32 Code3, NBioAPI_UINT32 Code4, NBioAPI_UINT32* pResult1, NBioAPI_UINT32* pResult2);

   /* Basic Functions */
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_GetVersion)  (NBioAPI_HANDLE hHandle, NBioAPI_VERSION_PTR  pVersion);
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_GetInitInfo) (NBioAPI_HANDLE hHandle, NBioAPI_UINT8 nStructureType, NBioAPI_INIT_INFO_PTR pInitInfo);
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_SetInitInfo) (NBioAPI_HANDLE hHandle, NBioAPI_UINT8 nStructureType, NBioAPI_INIT_INFO_PTR pInitInfo);
   
   /* Device Functions */
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_EnumerateDevice)(NBioAPI_HANDLE hHandle, NBioAPI_UINT32* pNumDevice, NBioAPI_DEVICE_ID** ppDeviceID);
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_EnumerateDeviceEx)(NBioAPI_HANDLE  hHandle, 
                                                                  NBioAPI_UINT32* pNumDevice, 
                                                                  NBioAPI_DEVICE_ID** ppDeviceID, 
                                                                  NBioAPI_DEVICE_INFO_EX** ppDeviceInfoEx);

   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_OpenDevice)     (NBioAPI_HANDLE hHandle, NBioAPI_DEVICE_ID nDeviceID);
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_CloseDevice)    (NBioAPI_HANDLE hHandle, NBioAPI_DEVICE_ID nDeviceID);
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_GetDeviceInfo)  (NBioAPI_HANDLE hHandle, NBioAPI_DEVICE_ID nDeviceID, NBioAPI_UINT8 nStructureType, NBioAPI_DEVICE_INFO_PTR pDeviceInfo);
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_SetDeviceInfo)  (NBioAPI_HANDLE hHandle, NBioAPI_DEVICE_ID nDeviceID, NBioAPI_UINT8 nStructureType, NBioAPI_DEVICE_INFO_PTR pDeviceInfo);
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_AdjustDevice)   (NBioAPI_HANDLE hHandle, const NBioAPI_WINDOW_OPTION_PTR pWindowOption);
   typedef NBioAPI_DEVICE_ID (NBioAPI *FP_NBioAPI_GetOpenedDeviceID)(NBioAPI_HANDLE hHandle);
   
   /* Memory Functions */
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_FreeFIRHandle)      (NBioAPI_HANDLE hHandle, NBioAPI_FIR_HANDLE hFIR);
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_GetFIRFromHandle)   (NBioAPI_HANDLE hHandle, NBioAPI_FIR_HANDLE hFIR, NBioAPI_FIR_PTR pFIR);
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_GetHeaderFromHandle)(NBioAPI_HANDLE hHandle, NBioAPI_FIR_HANDLE hFIR, NBioAPI_FIR_HEADER_PTR pHeader);
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_GetExtendedFIRFromHandle)   (NBioAPI_HANDLE hHandle, NBioAPI_FIR_HANDLE hFIR, NBioAPI_VOID_PTR pFIR, NBioAPI_FIR_FORMAT Format);
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_GetExtendedHeaderFromHandle)(NBioAPI_HANDLE hHandle, NBioAPI_FIR_HANDLE hFIR, NBioAPI_VOID_PTR pHeader, NBioAPI_FIR_FORMAT Format);
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_FreeFIR)            (NBioAPI_HANDLE hHandle, NBioAPI_VOID_PTR pFIR);
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_FreePayload)        (NBioAPI_HANDLE hHandle, NBioAPI_FIR_PAYLOAD_PTR pPayload);

   /* TextEncode Funtions */
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_GetTextFIRFromHandle)(NBioAPI_HANDLE hHandle, NBioAPI_FIR_HANDLE hFIR, NBioAPI_FIR_TEXTENCODE_PTR pTextFIR, NBioAPI_BOOL bIsWide);
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_GetExtendedTextFIRFromHandle)(NBioAPI_HANDLE hHandle, NBioAPI_FIR_HANDLE hFIR, NBioAPI_FIR_TEXTENCODE_PTR pTextFIR, NBioAPI_BOOL bIsWide, NBioAPI_FIR_FORMAT Format);
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_FreeTextFIR)         (NBioAPI_HANDLE hHandle, NBioAPI_FIR_TEXTENCODE_PTR pTextFIR);
   
   /* BSP Functions */
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_Capture)(
                                          NBioAPI_HANDLE                  hHandle, 
                                          NBioAPI_FIR_PURPOSE             nPurpose,
                                          NBioAPI_FIR_HANDLE_PTR          phCapturedFIR,
                                          NBioAPI_SINT32                  nTimeout,
                                          NBioAPI_FIR_HANDLE_PTR          phAuditData,
                                          const NBioAPI_WINDOW_OPTION_PTR pWindowOption);
   
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_Process)(
                                          NBioAPI_HANDLE                  hHandle, 
                                          const NBioAPI_INPUT_FIR_PTR     piCapturedFIR,
                                          NBioAPI_FIR_HANDLE_PTR          phProcessedFIR);
   
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_CreateTemplate)(
                                          NBioAPI_HANDLE                  hHandle, 
                                          const NBioAPI_INPUT_FIR_PTR     piCapturedFIR,
                                          const NBioAPI_INPUT_FIR_PTR     piStoredTemplate,
                                          NBioAPI_FIR_HANDLE_PTR          phNewTemplate,
                                          const NBioAPI_FIR_PAYLOAD_PTR   pPayload);
   
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_VerifyMatch)(
                                          NBioAPI_HANDLE                  hHandle, 
                                          const NBioAPI_INPUT_FIR_PTR     piProcessedFIR,
                                          const NBioAPI_INPUT_FIR_PTR     piStoredTemplate,
                                          NBioAPI_BOOL*                   pbResult,
                                          NBioAPI_FIR_PAYLOAD_PTR         pPayload);

   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_VerifyMatchEx)(
                                          NBioAPI_HANDLE                  hHandle, 
                                          const NBioAPI_INPUT_FIR_PTR     piProcessedFIR,
                                          const NBioAPI_INPUT_FIR_PTR     piStoredTemplate,
                                          NBioAPI_BOOL*                   pbResult,
                                          NBioAPI_FIR_PAYLOAD_PTR         pPayload,
                                          NBioAPI_MATCH_OPTION_PTR        pMatchOption);
   
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_Enroll)(
                                          NBioAPI_HANDLE                  hHandle, 
                                          const NBioAPI_INPUT_FIR_PTR     piStoredTemplate,
                                          NBioAPI_FIR_HANDLE_PTR          phNewTemplate,
                                          const NBioAPI_FIR_PAYLOAD_PTR   pPayload,
                                          NBioAPI_SINT32                  nTimeout,
                                          NBioAPI_FIR_HANDLE_PTR          phAuditData,
                                          const NBioAPI_WINDOW_OPTION_PTR WindowOption);
   
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_Verify)(
                                          NBioAPI_HANDLE                  hHandle, 
                                          const NBioAPI_INPUT_FIR_PTR     piStoredTemplate,
                                          NBioAPI_BOOL*                   pbResult,
                                          NBioAPI_FIR_PAYLOAD_PTR         pPayload,
                                          NBioAPI_SINT32                  nTimeout,
                                          NBioAPI_FIR_HANDLE_PTR          phAuditData,
                                          const NBioAPI_WINDOW_OPTION_PTR pWindowOption);

   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_CheckFinger)(
                                          NBioAPI_HANDLE                  hHandle, 
                                          NBioAPI_BOOL*                   bFingerExist);
   
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_GetQualityInfo)(
                                          NBioAPI_HANDLE		              hHandle,
                                          const NBioAPI_INPUT_FIR_PTR	  pAuditData,
                                          const NBioAPI_INPUT_FIR_PTR	  pFIR,
                                          NBioAPI_UINT8                   nStructureType, 
                                          NBioAPI_QUALITY_INFO_PTR        pQualityInfo);

   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_RollCapture)(
                                          NBioAPI_HANDLE                  hHandle,
                                          NBioAPI_FIR_PURPOSE             nPurpose,
                                          NBioAPI_SINT32                  nTimeout,
                                          NBioAPI_FIR_HANDLE_PTR          phCapturedFIR,
                                          NBioAPI_FIR_HANDLE_PTR          phAuditData,
                                          const NBioAPI_WINDOW_OPTION_PTR pWindowOption);

#ifdef WIN32   
#ifndef _WIN32_WCE
   /* Skin Function */
   typedef NBioAPI_BOOL (NBioAPI *FP_NBioAPI_SetSkinResource)(LPCSTR szResPath);
   typedef NBioAPI_BOOL (NBioAPI *FP_NBioAPI_SetSkinResourceW)(LPCWSTR szResPath);
#endif // _WIN32_WCE
#endif // WIN32

#ifdef __cplusplus
}
#endif
