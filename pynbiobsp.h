#include <string>
#include <cstring>
#include <iostream>

#include "include/NBioAPI.h"
#include "include/NBioAPI_Export.h"
#include "include/NBioAPI_IndexSearch.h"

// Defining the global variables that will be 
// used by the application.
NBioAPI_HANDLE bspHandle;
NBioAPI_DEVICE_ID idDevice;
NBioAPI_RETURN ret;

#include "nbiobsp_init.h"
#include "nbiobsp_close.h"
#include "nbiobsp_capture.h"
#include "nbiobsp_match.h"
