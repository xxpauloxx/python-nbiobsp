#ifndef _NITGEN_NBioAPI_INDEXSEARCHTYPE_H
#define _NITGEN_NBioAPI_INDEXSEARCHTYPE_H

#include "NBioAPI_Basic.h"

/* NBioAPI_INDEXSEARCH_INIT_INFO_0 */
typedef struct nbioapi_indexsearch_init_info_0 {
   NBioAPI_UINT32                StructureType;           /* must be 0 */
   NBioAPI_UINT32                PresearchRate;           /* Default = 12 */  
   NBioAPI_UINT32                researved0;              /* Reserved */
   NBioAPI_UINT32                researved1;              /* Reserved */
   NBioAPI_UINT32                researved2;              /* Reserved */
   NBioAPI_UINT32                researved3;              /* Reserved */
   NBioAPI_UINT32                researved4;              /* Reserved */
   NBioAPI_UINT32                researved5;              /* Reserved */
   NBioAPI_UINT32*               researved6;              /* Reserved */
} NBioAPI_INDEXSEARCH_INIT_INFO_0, *NBioAPI_INDEXSEARCH_INIT_INFO_PTR_0;

/* NBioAPI_INDEXSEARCH_FP_INFO */
typedef struct nbioapi_indexsearch_fp_info {
   NBioAPI_UINT32	ID;	
   NBioAPI_UINT8	FingerID;  /* NBioAPI_FINGER_ID */
   NBioAPI_UINT8	SampleNumber;
} NBioAPI_INDEXSEARCH_FP_INFO, *NBioAPI_INDEXSEARCH_FP_INFO_PTR;

/* NBioAPI_INDEXSEARCH_SAMPLE_INFO */
typedef struct nbioapi_indexsearch_sample_info {
   NBioAPI_UINT32	ID;	
   NBioAPI_UINT8	SampleCount[11];  /* Unknown = 0, Right Thumb = 1, ... , Left Little = 10 */
} NBioAPI_INDEXSEARCH_SAMPLE_INFO, *NBioAPI_INDEXSEARCH_SAMPLE_INFO_PTR;


/* NBioAPI_INDEXSEARCH_CALLBACK_PARAM_0 */
typedef struct nbioapi_indexsearch_callback_param_0 {
   NBioAPI_UINT32                TotalCount;
   NBioAPI_UINT32                ProgressPos;
   NBioAPI_INDEXSEARCH_FP_INFO   FpInfo;
   NBioAPI_UINT32                Reserved0;
   NBioAPI_UINT32                Reserved1;
   NBioAPI_UINT32                Reserved2;
   NBioAPI_UINT32                Reserved3;
   NBioAPI_VOID_PTR              Reserved4;
} NBioAPI_INDEXSEARCH_CALLBACK_PARAM_0, *NBioAPI_INDEXSEARCH_CALLBACK_PARAM_PTR_0;

/* NBioAPI_INDEXSEARCH_CALLBACK */
typedef NBioAPI_RETURN (NBioAPI* NBioAPI_INDEXSEARCH_CALLBACK_0)(NBioAPI_INDEXSEARCH_CALLBACK_PARAM_PTR_0, NBioAPI_VOID_PTR);

typedef struct nbioapi_indexsearch_callback_info_0 {
   NBioAPI_UINT32                   CallBackType;
   NBioAPI_INDEXSEARCH_CALLBACK_0   CallBackFunction; 
   NBioAPI_VOID_PTR                 UserCallBackParam;
} NBioAPI_INDEXSEARCH_CALLBACK_INFO_0, *NBioAPI_INDEXSEARCH_CALLBACK_INFO_PTR_0;

/* Callback return value */
#define NBioAPI_INDEXSEARCH_CALLBACK_OK      (0)
#define NBioAPI_INDEXSEARCH_CALLBACK_SKIP    (1)
#define NBioAPI_INDEXSEARCH_CALLBACK_STOP    (2)

#endif/*_NITGEN_NBioAPI_INDEXSEARCHTYPE_H */
