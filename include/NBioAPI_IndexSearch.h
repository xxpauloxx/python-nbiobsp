#ifndef _NITGEN_NBioAPI_INDEXSEARCH_H
#define _NITGEN_NBioAPI_INDEXSEARCH_H

#include "NBioAPI_Basic.h"
#include "NBioAPI_Type.h"
#include "NBioAPI_IndexSearchType.h"
#include "NBioAPI_Error.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _NBioAPI_LOAD_LIBRARY

   /* IndexSearch Functions */
   NBioAPI_RETURN NBioAPI NBioAPI_InitIndexSearchEngine(NBioAPI_HANDLE hHandle);
   NBioAPI_RETURN NBioAPI NBioAPI_TerminateIndexSearchEngine(NBioAPI_HANDLE hHandle);

   /* Parameter Funtions */
   NBioAPI_RETURN NBioAPI NBioAPI_SetIndexSearchInitInfo(
                 NBioAPI_HANDLE                    hHandle,
                 NBioAPI_UINT8                     nStructureType,
                 NBioAPI_INIT_INFO_PTR             pInitInfo);
   NBioAPI_RETURN NBioAPI NBioAPI_GetIndexSearchInitInfo(
                 NBioAPI_HANDLE                    hHandle,
                 NBioAPI_UINT8                     nStructureType,
                 NBioAPI_INIT_INFO_PTR             pInitInfo);

   /* Add Funtion */
   NBioAPI_RETURN NBioAPI NBioAPI_AddFIRToIndexSearchDB(
                 NBioAPI_HANDLE                    hHandle, 
                 const NBioAPI_INPUT_FIR_PTR       pInputFIR,
                 NBioAPI_UINT32                    nUserID,
                 NBioAPI_INDEXSEARCH_SAMPLE_INFO_PTR pSampleInfo);

   /* Remove Functions */
   NBioAPI_RETURN NBioAPI NBioAPI_RemoveDataFromIndexSearchDB(
                 NBioAPI_HANDLE                    hHandle,
                 NBioAPI_INDEXSEARCH_FP_INFO_PTR   pFpInfo);
   NBioAPI_RETURN NBioAPI NBioAPI_RemoveUserFromIndexSearchDB(
                 NBioAPI_HANDLE                    hHandle,
                 NBioAPI_UINT32                    nUserID);
        
   /* Searching Funtions */
   NBioAPI_RETURN NBioAPI NBioAPI_IdentifyDataFromIndexSearchDB(
                 NBioAPI_HANDLE                    hHandle, 
                 const NBioAPI_INPUT_FIR_PTR       pInputFIR,
                 NBioAPI_FIR_SECURITY_LEVEL        nSecuLevel,
                 NBioAPI_INDEXSEARCH_FP_INFO_PTR   pFpInfo,
                 NBioAPI_INDEXSEARCH_CALLBACK_INFO_PTR_0  pCallbackInfo0);
   NBioAPI_RETURN NBioAPI NBioAPI_IdentifyDataFromIndexSearchDBEx(
                 NBioAPI_HANDLE                    hHandle, 
                 const NBioAPI_INPUT_FIR_PTR       pInputFIR,
                 NBioAPI_FIR_SECURITY_LEVEL        nSecuLevel,
                 NBioAPI_INDEXSEARCH_FP_INFO_PTR   pFpInfo,
                 NBioAPI_INDEXSEARCH_CALLBACK_INFO_PTR_0  pCallbackInfo0);

   /* DB Funtions */
   NBioAPI_RETURN NBioAPI NBioAPI_ClearIndexSearchDB(NBioAPI_HANDLE hHandle);

   NBioAPI_RETURN NBioAPI NBioAPI_SaveIndexSearchDBToFile(
                 NBioAPI_HANDLE                    hHandle, 
                 const NBioAPI_CHAR*               szFilepath);
   NBioAPI_RETURN NBioAPI NBioAPI_LoadIndexSearchDBFromFile(
                 NBioAPI_HANDLE                    hHandle, 
                 const NBioAPI_CHAR*               szFilepath);

   /* Check Functions */
   NBioAPI_RETURN NBioAPI NBioAPI_GetDataCountFromIndexSearchDB(
                 NBioAPI_HANDLE                    hHandle, 
                 NBioAPI_UINT32*                   pDataCount);
   NBioAPI_RETURN NBioAPI NBioAPI_CheckDataExistFromIndexSearchDB(
                 NBioAPI_HANDLE                    hHandle, 
                 NBioAPI_INDEXSEARCH_FP_INFO_PTR   pFpInfo,
                 NBioAPI_BOOL*                     pExist);
   
#endif/* _NBioAPI_LOAD_LIBRARY */
   
   /* IndexSearch Functions */
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_InitIndexSearchEngine)(NBioAPI_HANDLE hHandle);
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_TerminateIndexSearchEngine)(NBioAPI_HANDLE hHandle);

   /* Parameter Funtions */
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_SetIndexSearchInitInfo)(
                 NBioAPI_HANDLE                    hHandle,
                 NBioAPI_UINT8                     nStructureType,
                 NBioAPI_INIT_INFO_PTR             pInitInfo);
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_GetIndexSearchInitInfo)(
                 NBioAPI_HANDLE                    hHandle,
                 NBioAPI_UINT8                     nStructureType,
                 NBioAPI_INIT_INFO_PTR             pInitInfo);

   /* Add Funtion */
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_AddFIRToIndexSearchDB)(
                 NBioAPI_HANDLE                    hHandle,
                 const NBioAPI_INPUT_FIR_PTR       pInputFIR,
                 NBioAPI_UINT32                    nUserID,
                 NBioAPI_INDEXSEARCH_SAMPLE_INFO_PTR pSampleInfo);
   
   /* Remove Functions */
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_RemoveDataFromIndexSearchDB)(
                 NBioAPI_HANDLE                    hHandle,
                 NBioAPI_INDEXSEARCH_FP_INFO_PTR   pFpInfo);
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_RemoveUserFromIndexSearchDB)(
                 NBioAPI_HANDLE                    hHandle,
                 NBioAPI_UINT32                    nUserID);
        
   /* Searching Funtions */
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_IdentifyDataFromIndexSearchDB)(
                 NBioAPI_HANDLE                    hHandle,
                 const NBioAPI_INPUT_FIR_PTR       pInputFIR,
                 NBioAPI_FIR_SECURITY_LEVEL        nSecuLevel,
                 NBioAPI_INDEXSEARCH_FP_INFO_PTR   pFpInfo,
                 NBioAPI_INDEXSEARCH_CALLBACK_INFO_PTR_0 pCallbackInfo0);

   /* DB Funtions */
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_ClearIndexSearchDB)(NBioAPI_HANDLE hHandle);

   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_SaveIndexSearchDBToFile)(
                 NBioAPI_HANDLE                    hHandle,
                 const NBioAPI_CHAR*               szFilepath);
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_LoadIndexSearchDBFromFile)(
                 NBioAPI_HANDLE                    hHandle,
                 const NBioAPI_CHAR*               szFilepath);

   /* Check Functions */
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_GetDataCountFromIndexSearchDB)(
                 NBioAPI_HANDLE                    hHandle, 
                 NBioAPI_UINT32*                   pDataCount);
   typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_CheckDataExistFromIndexSearchDB)(
                 NBioAPI_HANDLE                    hHandle, 
                 NBioAPI_INDEXSEARCH_FP_INFO_PTR   pFpInfo,
                 NBioAPI_BOOL*                     pExist);

#ifdef __cplusplus
}
#endif

#endif/* _NITGEN_NBioAPI_INDEXSEARCH_H */
