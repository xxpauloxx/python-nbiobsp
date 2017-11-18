//  Method to capture the fingerprint and return a FIR.
std::string nbiobspCapture(int timeout){
    NBioAPI_FIR_HANDLE firHandle;

    ret = NBioAPI_Capture(
        bspHandle,   // Module for handling NBioBSP module.
        NBioAPI_FIR_PURPOSE_ENROLL,
        &firHandle,  // Capture the FIR and put in the variable.
        timeout,     // Capture timeout.
        NULL,
        NULL
    );

    if(ret != NBioAPIERROR_NONE)
        return "ERROR: Problem in NBioAPI Capture.";

    // Capture the digital FIR and return the hash of the template.
    NBioAPI_FIR_TEXTENCODE textFIR;
    ret = NBioAPI_GetTextFIRFromHandle(
        bspHandle, firHandle, &textFIR, NBioAPI_FALSE);
    
    if(ret != NBioAPIERROR_NONE)
        return "ERROR: Problem in NBioAPI get Text FIR from Handle.";

    if(ret == NBioAPIERROR_NONE) return textFIR.TextFIR;
    else return "NULL";
}
