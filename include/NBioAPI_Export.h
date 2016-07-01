 #ifndef _NITGEN_NBioAPI_EXPORT_H
#define _NITGEN_NBioAPI_EXPORT_H

#include "NBioAPI.h"
#include "NBioAPI_ExportType.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _NBioAPI_LOAD_LIBRARY

/* Export Functions */
NBioAPI_RETURN NBioAPI NBioAPI_NBioBSPToFDx(
                                          NBioAPI_HANDLE                  hHandle, 
                                          const NBioAPI_INPUT_FIR_PTR     piFIR,
										            NBioAPI_EXPORT_DATA_PTR         pExportData,
										            MINCONV_DATA_TYPE               nExportType);

/* Import Functions */
NBioAPI_RETURN NBioAPI NBioAPI_FDxToNBioBSP(
                                          NBioAPI_HANDLE                  hHandle, 
                                          NBioAPI_UINT8*                  pFDxData, 
                                          NBioAPI_UINT32                  nFDxDataSize,
                                          NBioAPI_UINT32                  nFDxDataType,
                                          NBioAPI_FIR_PURPOSE             Purpose,
                                          NBioAPI_FIR_HANDLE_PTR          phProcessedFIR);

NBioAPI_RETURN NBioAPI NBioAPI_FDxToNBioBSPEx(
                                          NBioAPI_HANDLE                  hHandle, 
                                          NBioAPI_UINT8*                  pFDxData, 
                                          NBioAPI_UINT32                  nFDxDataSize,
                                          NBioAPI_UINT32                  nFDxTemplateSize,
                                          NBioAPI_UINT32                  nFDxDataType,
                                          NBioAPI_FIR_PURPOSE             Purpose,
                                          NBioAPI_FIR_HANDLE_PTR          phProcessedFIR);

NBioAPI_RETURN NBioAPI NBioAPI_ConvertFDxData(
                                          NBioAPI_HANDLE                  hHandle, 
                                          NBioAPI_UINT8*                  pFDxData, 
                                          NBioAPI_UINT32                  nFDxDataSize,
                                          NBioAPI_UINT32                  nFDxTemplateSize,
                                          NBioAPI_UINT32                  nFDxDataType,
                                          NBioAPI_UINT32                  nConvertType,
                                          NBioAPI_UINT8**                 ppConvertedData);  // ppConvertedData must be free by NBioAPI_FreeData(..)

NBioAPI_RETURN NBioAPI NBioAPI_FreeData(
                                          NBioAPI_HANDLE                  hHandle, 
                                          NBioAPI_UINT8*                  pData);

NBioAPI_RETURN NBioAPI NBioAPI_ImportDataToNBioBSP(
                                          NBioAPI_HANDLE                  hHandle, 
                                          NBioAPI_EXPORT_DATA_PTR         pExportData, 
                                          NBioAPI_FIR_PURPOSE             Purpose,
                                          NBioAPI_FIR_HANDLE_PTR          phProcessedFIR);

NBioAPI_RETURN NBioAPI NBioAPI_ImportDataToNBioBSPEx(
                                          NBioAPI_HANDLE                  hHandle, 
                                          NBioAPI_EXPORT_DATA_PTR         pExportData, 
                                          NBioAPI_FIR_PURPOSE             Purpose,
                                          NBioAPI_FIR_DATA_TYPE           DataType,
                                          NBioAPI_FIR_HANDLE_PTR          phProcessedFIR,
                                          NBioAPI_VOID_PTR                pReserved);

NBioAPI_RETURN NBioAPI NBioAPI_FreeExportData(
                                          NBioAPI_HANDLE                  hHandle, 
										            NBioAPI_EXPORT_DATA_PTR         pExportData);

/* BioAPI Opaque Data */
NBioAPI_RETURN NBioAPI NBioAPI_ImportBioAPIOpaqueToFIRHandle(
                                          NBioAPI_HANDLE                  hHandle, 
                                          NBioAPI_UINT8*                  pBioAPIOpaqueData,
                                          NBioAPI_FIR_HANDLE_PTR          pFIRHandle,
                                          NBioAPI_VOID_PTR                pReserved);
/* Image Export Functions */
NBioAPI_RETURN NBioAPI NBioAPI_NBioBSPToImage(
                                          NBioAPI_HANDLE                  hHandle, 
                                          const NBioAPI_INPUT_FIR_PTR     piAuditFIR,
										            NBioAPI_EXPORT_AUDIT_DATA_PTR   pExportAuditData);

NBioAPI_RETURN NBioAPI NBioAPI_ImageToNBioBSP(
                                          NBioAPI_HANDLE                  hHandle, 
                                          NBioAPI_EXPORT_AUDIT_DATA_PTR   pExportAuditData,
                                          NBioAPI_FIR_HANDLE_PTR          phAuditFIR);

NBioAPI_RETURN NBioAPI NBioAPI_FreeExportAuditData(
                                          NBioAPI_HANDLE                  hHandle, 
										            NBioAPI_EXPORT_AUDIT_DATA_PTR   pExportAuditData);

#endif/*_NBioAPI_LOAD_LIBRARY */


/* typedef for GetProcAddress() */

/* Export Functions */
typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_NBioBSPToFDx)(
                                          NBioAPI_HANDLE                  hHandle, 
                                          const NBioAPI_INPUT_FIR_PTR     piFIR,
										            NBioAPI_EXPORT_DATA_PTR         pExportData,
										            MINCONV_DATA_TYPE               nExportType);

/* Import Functions */
typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_FDxToNBioBSP)(
                                          NBioAPI_HANDLE                  hHandle, 
                                          NBioAPI_UINT8*                  pFDxData, 
                                          NBioAPI_UINT32                  nFDxDataSize,
                                          NBioAPI_UINT32                  nFDxDataType,
                                          NBioAPI_FIR_PURPOSE             Purpose,
                                          NBioAPI_FIR_HANDLE_PTR          phProcessedFIR);

typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_FDxToNBioBSPEx)(
                                          NBioAPI_HANDLE                  hHandle, 
                                          NBioAPI_UINT8*                  pFDxData, 
                                          NBioAPI_UINT32                  nFDxDataSize,
                                          NBioAPI_UINT32                  nFDxTemplateSize,
                                          NBioAPI_UINT32                  nFDxDataType,
                                          NBioAPI_FIR_PURPOSE             Purpose,
                                          NBioAPI_FIR_HANDLE_PTR          phProcessedFIR);

typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_ConvertFDxData)(
                                          NBioAPI_HANDLE                  hHandle, 
                                          NBioAPI_UINT8*                  pFDxData, 
                                          NBioAPI_UINT32                  nFDxDataSize,
                                          NBioAPI_UINT32                  nFDxTemplateSize,
                                          NBioAPI_UINT32                  nFDxDataType,
                                          NBioAPI_UINT32                  nConvertType,
                                          NBioAPI_UINT8**                 ppConvertedData);

typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_FreeData)(
                                          NBioAPI_HANDLE                  hHandle, 
                                          NBioAPI_UINT8*                  pData);

typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_ImportDataToNBioBSP)(
                                          NBioAPI_HANDLE                  hHandle, 
                                          NBioAPI_EXPORT_DATA_PTR         pExportData, 
                                          NBioAPI_FIR_PURPOSE             Purpose,
                                          NBioAPI_FIR_HANDLE_PTR          phProcessedFIR);

typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_ImportDataToNBioBSPEx)(
                                          NBioAPI_HANDLE                  hHandle, 
                                          NBioAPI_EXPORT_DATA_PTR         pExportData, 
                                          NBioAPI_FIR_PURPOSE             Purpose,
                                          NBioAPI_FIR_DATA_TYPE           DataType,
                                          NBioAPI_FIR_HANDLE_PTR          phProcessedFIR,
                                          NBioAPI_VOID_PTR                pReserved);

typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_FreeExportData)(
                                          NBioAPI_HANDLE                  hHandle, 
										            NBioAPI_EXPORT_DATA_PTR         pExportData);

/* BioAPI Opaque Data */
typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_ImportBioAPIOpaqueToFIRHandle)(
                                          NBioAPI_HANDLE                  hHandle, 
                                          NBioAPI_UINT8*                  pBioAPIOpaqueData,
                                          NBioAPI_FIR_HANDLE_PTR          pFIRHandle,
                                          NBioAPI_VOID_PTR                pReserved);

/* Image Export Functions */
typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_NBioBSPToImage)(
                                          NBioAPI_HANDLE                  hHandle, 
                                          const NBioAPI_INPUT_FIR_PTR     piAuditFIR,
										            NBioAPI_EXPORT_AUDIT_DATA_PTR   pExportAuditData);

typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_ImageToNBioBSP)(
                                          NBioAPI_HANDLE                  hHandle, 
                                          NBioAPI_EXPORT_AUDIT_DATA_PTR   pExportAuditData,
                                          NBioAPI_FIR_HANDLE_PTR          phAuditFIR);

typedef NBioAPI_RETURN (NBioAPI *FP_NBioAPI_FreeExportAuditData)(
                                          NBioAPI_HANDLE                  hHandle, 
										            NBioAPI_EXPORT_AUDIT_DATA_PTR   pExportAuditData);

#ifdef __cplusplus
}
#endif

#endif/*_NITGEN_NBioAPI_EXPORT_H */
