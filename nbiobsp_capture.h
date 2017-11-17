//  Method to capture the fingerprint and return a FIR.
string pynbiobspCapture(int timeout){
    NBioAPI_FIR_HANDLE firHandle;
    NBioAPI_FIR_PURPOSE purpose;

    purpose = NBioAPI_FIR_PURPOSE_ENROLL;
    ret = NBioAPI_Capture(
        bspHandle,   // Module for handling NBioBSP module.
        purpose,
        &firHandle,  // Capture the FIR and put in the variable.
        timeout,     // Capture timeout.
        NULL,
        NULL
    );

    // Capture the digital FIR and return the hash of the template.
    NBioAPI_FIR_TEXTENCODE textFIR;
    ret = NBioAPI_GetTextFIRFromHandle(bspHandle, firHandle, &textFIR, NBioAPI_FALSE);

    if(ret == 0) return textFIR.TextFIR;
    else return "NULL";
}
