// Method for carrying out comparisons of FIR templates.
bool nbiobspMatch(std::string firCaptured, std::string firStored){
    NBioAPI_BOOL result;
    NBioAPI_INPUT_FIR inputFirCaptured, inputFirStored;

    // Converting to string the FIRs of the method argument.
    std::string valueFirCaptured(firCaptured);
    std::string valueFirStored(firStored);

    // Extracting the sizes of the captured and stored template values.
    int lenFirCaptured = strlen(valueFirCaptured.c_str());
    int lenFirStored = strlen(valueFirStored.c_str());

    // Extracting the hash from the captured FIR template.
    NBioAPI_FIR_TEXTENCODE textFirCaptured;
    textFirCaptured.IsWideChar = NBioAPI_FALSE;
    textFirCaptured.TextFIR = new NBioAPI_CHAR[lenFirCaptured+1];
    memcpy(textFirCaptured.TextFIR, valueFirCaptured.c_str(), lenFirCaptured+1);

    // Registering the hash of the FIR template on the captured FIR Input.
    inputFirCaptured.Form = NBioAPI_FIR_FORM_TEXTENCODE;
    inputFirCaptured.InputFIR.TextFIR = &textFirCaptured;

    // Extracting the hash from the stored FIR template.
    NBioAPI_FIR_TEXTENCODE textFirStored;
    textFirStored.IsWideChar = NBioAPI_FALSE;
    textFirStored.TextFIR = new NBioAPI_CHAR[lenFirStored+1];
    memcpy(textFirStored.TextFIR, valueFirStored.c_str(), lenFirStored+1);

    // Registering the hash of the FIR template on the stored FIR Input.
    inputFirStored.Form = NBioAPI_FIR_FORM_TEXTENCODE;
    inputFirStored.InputFIR.TextFIR = &textFirStored;

    // Match FIRs and store result in result.
    ret = NBioAPI_VerifyMatch(
        bspHandle,      	// NBioBSP Module Manipulator.
        &inputFirCaptured, 	// First FIR.
        &inputFirStored,  	// Second FIR.
        &result,    		// Result of comparing.
        NULL    			// Payload.
    );

    if(ret != NBioAPIERROR_NONE) {
        std::cout << "Problem in NBioAPI_VerifyMatch." << std::endl;
        return false;
    }

    if(result == NBioAPI_TRUE) return true;
    else return false;
}
