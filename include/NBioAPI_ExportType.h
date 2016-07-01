#pragma once

#include "NBioAPI_Type.h"

//////////////////////////////////////////////////////////////////////////
// NBioAPI_TEMPLATE_DATA
typedef struct nbioapi_template_data 
{
   NBioAPI_UINT32             Length;           // sizeof of structure
   NBioAPI_UINT8              Data[400];        // If EncryptType == MINCONV_TYPE_FIM01_HV, Data is not include header block (4byte).
} NBioAPI_TEMPLATE_DATA, * NBioAPI_TEMPLATE_DATA_PTR;

//////////////////////////////////////////////////////////////////////////
// NBioAPI_FINGER_DATA
typedef struct nbioapi_finger_data 
{
   NBioAPI_UINT32             Length;           // sizeof of structure
   NBioAPI_UINT8              FingerID;         // NBioAPI_FINGER_ID
   NBioAPI_TEMPLATE_DATA_PTR  Template;
} NBioAPI_FINGER_DATA, * NBioAPI_FINGER_DATA_PTR;

//////////////////////////////////////////////////////////////////////////
// NBioAPI_TEMPLATE_DATA_2
typedef struct nbioapi_template_data_2 
{
   NBioAPI_UINT32             Length;           // just length of Data (not sizeof structure)
   NBioAPI_UINT8*             Data;             // variable length of data
} NBioAPI_TEMPLATE_DATA_2, * NBioAPI_TEMPLATE_DATA_PTR_2;

//////////////////////////////////////////////////////////////////////////
// NBioAPI_FINGER_DATA_2
typedef struct nbioapi_finger_data_2 
{
   NBioAPI_UINT32                Length;        // sizeof of structure
   NBioAPI_UINT8                 FingerID;      // NBioAPI_FINGER_ID
   NBioAPI_TEMPLATE_DATA_PTR_2   Template;      // Template = NBioAPI_TEMPLATE_DATA_2 * SamplesPerFinger
} NBioAPI_FINGER_DATA_2, * NBioAPI_FINGER_DATA_PTR_2;

//////////////////////////////////////////////////////////////////////////
// NBioAPI_EXPORT_DATA
typedef struct nbioapi_export_data 
{
   NBioAPI_UINT32             Length;           // sizeof of structure
   NBioAPI_UINT8              EncryptType;      // Minutiae type
   NBioAPI_UINT8              FingerNum;
   NBioAPI_UINT8              DefaultFingerID;  // NBioAPI_FINGER_ID
   NBioAPI_UINT8              SamplesPerFinger;
   NBioAPI_FINGER_DATA_PTR    FingerData;       // only used for MINCONV_TYPE_FDP ~ MINCONV_TYPE_OLD_FDA
   NBioAPI_FINGER_DATA_PTR_2  FingerData2;      // used for all type
} NBioAPI_EXPORT_DATA, * NBioAPI_EXPORT_DATA_PTR;

//////////////////////////////////////////////////////////////////////////
// NBioAPI_IMAGE_DATA
typedef struct nbioapi_image_data 
{
   NBioAPI_UINT32             Length;           // sizeof of structure
   NBioAPI_UINT8*             Data;             // Data Length = ImageWidth * ImageHeight
} NBioAPI_IMAGE_DATA, * NBioAPI_IMAGE_DATA_PTR;

//////////////////////////////////////////////////////////////////////////
// NBioAPI_AUDIT_DATA
typedef struct nbioapi_audit_data 
{
   NBioAPI_UINT32             Length;           // sizeof of structure
   NBioAPI_UINT8              FingerID;         // NBioAPI_FINGER_ID
   NBioAPI_IMAGE_DATA_PTR     Image;            // AuditData = NBioAPI_IMAGE_DATA * SamplesPerFinger
} NBioAPI_AUDIT_DATA, * NBioAPI_AUDIT_DATA_PTR;

//////////////////////////////////////////////////////////////////////////
// NBioAPI_EXPORT_AUDIT_DATA
typedef struct nbioapi_export_audit_data 
{
   NBioAPI_UINT32             Length;           // sizeof of structure
   NBioAPI_UINT8              FingerNum;
   NBioAPI_UINT8              SamplesPerFinger;
   NBioAPI_UINT32             ImageWidth;
   NBioAPI_UINT32             ImageHeight;
   NBioAPI_AUDIT_DATA_PTR     AuditData;        // AuditData = NBioAPI_AUDIT_DATA * FingerNum
   NBioAPI_UINT32             Reserved2;
} NBioAPI_EXPORT_AUDIT_DATA, * NBioAPI_EXPORT_AUDIT_DATA_PTR;

