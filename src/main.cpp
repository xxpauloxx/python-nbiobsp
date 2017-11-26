#include <iostream>
#include <pybind11/pybind11.h>

#include "NBioAPI.h"
#include "NBioAPI_Export.h"
#include "NBioAPI_IndexSearch.h"

NBioAPI_HANDLE nbioApiHandle;
NBioAPI_DEVICE_ID nbioApiDeviceId;
NBioAPI_RETURN nbioApiReturn;

// Initialize the device.
bool NBioBSP_Init() {
    if (NBioAPI_Init(&nbioApiHandle) != NBioAPIERROR_NONE) {
        std::cout << "Initialization failed." << std::endl;
        return false;
    }

    nbioApiDeviceId = NBioAPI_DEVICE_ID_AUTO; // Opening the device for use.
    nbioApiReturn = NBioAPI_OpenDevice(nbioApiHandle, nbioApiDeviceId);

    if (nbioApiReturn != NBioAPIERROR_NONE) {
        std::cout << "Unable to connect to device." << std::endl;
        return false;
    }

    return true;
}

// Method to end device usage and free up memory.
void NBioBSP_Close(){
	NBioAPI_CloseDevice(nbioApiHandle, nbioApiDeviceId);
	NBioAPI_Terminate(nbioApiHandle);
}

//  Method to capture the fingerprint and return a FIR.
std::string NBioBSP_Capture(int timeout){
    NBioAPI_FIR_HANDLE firHandle;

    nbioApiReturn = NBioAPI_Capture(
        nbioApiHandle,   // Module for handling NBioBSP module.
        NBioAPI_FIR_PURPOSE_ENROLL,
        &firHandle,  // Capture the FIR and put in the variable.
        timeout,     // Capture timeout.
        NULL,
        NULL
    );

    if(nbioApiReturn != NBioAPIERROR_NONE)
        return "ERROR: Problem in NBioAPI Capture.";

    // Capture the digital FIR and return the hash of the template.
    NBioAPI_FIR_TEXTENCODE textFIR;
    nbioApiReturn = NBioAPI_GetTextFIRFromHandle(
        nbioApiHandle, firHandle, &textFIR, NBioAPI_FALSE);
    
    if(nbioApiReturn != NBioAPIERROR_NONE)
        return "ERROR: Problem in NBioAPI get Text FIR from Handle.";

    if(nbioApiReturn == NBioAPIERROR_NONE) return textFIR.TextFIR;
    else return "NULL";
}

// Method for carrying out comparisons of FIR templates.
bool NBioBSP_Match(std::string firCaptured, std::string firStored){
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
    nbioApiReturn = NBioAPI_VerifyMatch(
        nbioApiHandle,      	// NBioBSP Module Manipulator.
        &inputFirCaptured, 	// First FIR.
        &inputFirStored,  	// Second FIR.
        &result,    		// Result of comparing.
        NULL    			// Payload.
    );

    if (nbioApiReturn != NBioAPIERROR_NONE) {
        std::cout << "Problem in NBioAPI_VerifyMatch." << std::endl;
        return false;
    }

    if (result == NBioAPI_TRUE) return true;
    else return false;
}

PYBIND11_MODULE(pynbiobsp, module) {
    module.doc() = "NBioBSP module for Python to device Nitgen Hamster III";
    module.def("init", &NBioBSP_Init, "Initialize the device");
    module.def("close", &NBioBSP_Close, "Close the device");
    module.def("capture", &NBioBSP_Capture, "Capture fingerprint");
    module.def("match", &NBioBSP_Match, "Compare fingerprints");
}
