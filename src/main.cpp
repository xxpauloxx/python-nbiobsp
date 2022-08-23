#include <iostream>
#include <pybind11/pybind11.h>
namespace py = pybind11;

#include "NBioAPI.h"
#include "NBioAPI_Export.h"
#include "NBioAPI_IndexSearch.h"

NBioAPI_HANDLE nbioApiHandle;
NBioAPI_DEVICE_ID nbioApiDeviceId;
NBioAPI_RETURN nbioApiReturn;
NBioAPI_UINT32 pNumDevice;
NBioAPI_DEVICE_ID *pDeviceList;

void NBioBSP_Init_Device(NBioAPI_DEVICE_ID *DeviceId)
{
    nbioApiReturn = NBioAPI_OpenDevice(nbioApiHandle, *DeviceId);
    if (nbioApiReturn != NBioAPIERROR_NONE)
    {
        switch (nbioApiReturn)
        {
        case NBioAPI_INVALID_HANDLE:
            std::cout << "ERROR: Problem to invalid NBioBSP handle." << std::endl;
            break;
        case NBioAPIERROR_INVALID_DEVICE_ID:
            std::cout << "ERROR: Problem to invalid device ID." << std::endl;
            break;
        case NBioAPIERROR_DEVICE_ALREADY_OPENED:
            std::cout << "ERROR: Problem to device already opened." << std::endl;
            break;
        case NBioAPIERROR_DEVICE_OPEN_FAIL:
            std::cout << "ERROR: Problem to open device fail." << std::endl;
            break;
        case NBioAPIERROR_DEVICE_INIT_FAIL:
            std::cout << "ERROR: Problem to The FDU05 sensor has scale." << std::endl;
            break;
        default:
            std::cout << "Device ID successfully opened." << std::ends;
            break;
        }
    }
}

void NBioBSP_Connect_Devices()
{
    nbioApiReturn = NBioAPI_EnumerateDevice(nbioApiHandle, &pNumDevice, &pDeviceList);

    if (nbioApiReturn != NBioAPIERROR_NONE)
    {
        switch (nbioApiReturn)
        {
        case NBioAPI_INVALID_HANDLE:
            std::cout << "ERROR: Problem to invalid NBioBSP handle." << std::endl;
            break;
        case NBioAPIERROR_INVALID_POINTER:
            std::cout << "ERROR: Problem to invalid parameter." << std::endl;
            break;
        default:
            break;
        }
    }

    for (NBioAPI_UINT32 i = 0; i < pNumDevice; i++)
    {
        NBioBSP_Init_Device(&pDeviceList[i]);
    }
}

void NBioBSP_Close_Device(NBioAPI_DEVICE_ID *DeviceId){
    nbioApiReturn = NBioAPI_CloseDevice(nbioApiHandle, *DeviceId);
    if (nbioApiReturn != NBioAPIERROR_NONE)
    {
        switch (nbioApiReturn)
        {
        case NBioAPI_INVALID_HANDLE:
            std::cout << "ERROR: Problem to invalid NBioBSP handle." << std::endl;
            break;
        case NBioAPIERROR_WRONG_DEVICE_ID:
            std::cout << "ERROR: Problem to invalid device ID." << std::endl;
            break;
        case NBioAPIERROR_DEVICE_NOT_OPENED:
            std::cout << "ERROR: Problem to device already opened." << std::endl;
            break;
        default:
            std::cout << "Device ID successfully closed." << std::ends;
            break;
        }
    }
}

void NBioBSP_Close_All_Devices(){
    for (NBioAPI_UINT32 i = 0; i < pNumDevice; i++)
    {
        NBioBSP_Close_Device(&pDeviceList[i]);
    }
}

// Initialize the device.
bool NBioBSP_Init()
{
    if (NBioAPI_Init(&nbioApiHandle) != NBioAPIERROR_NONE)
    {
        std::cout << "ERROR: Initialization failed." << std::endl;
        return false;
    }

    NBioBSP_Connect_Devices(); // Opening the device for use.

    return true;
}

// Method to end device usage and free up memory.
void NBioBSP_Close()
{
    NBioBSP_Close_All_Devices();

    nbioApiReturn = NBioAPI_Terminate(nbioApiHandle);
    if (nbioApiReturn != NBioAPIERROR_NONE)
        std::cout << "ERROR: Problem to terminate NBioBSP handle." << std::endl;
}

//  Method to capture the fingerprint and return a FIR.
std::string NBioBSP_Capture(int timeout, bool enRoll)
{
    NBioAPI_FIR_HANDLE firHandle;

    nbioApiReturn = NBioAPI_Capture(
        nbioApiHandle, // Module for handling NBioBSP module.
        (enRoll) ? NBioAPI_FIR_PURPOSE_ENROLL : NBioAPI_FIR_PURPOSE_VERIFY,
        &firHandle, // Capture the FIR and put in the variable.
        timeout,    // Capture timeout.
        NULL,
        NULL);

    if (nbioApiReturn != NBioAPIERROR_NONE)
    {
        switch (nbioApiReturn)
        {
        case NBioAPIERROR_INVALID_HANDLE:
            return "ERROR: Invalid handle";
        case NBioAPIERROR_INVALID_POINTER:
            return "ERROR: Invalid pointer";
        case NBioAPIERROR_ENCRYPTED_DATA_ERROR:
            return "ERROR: Encrypted data error";
        case NBioAPIERROR_INTERNAL_CHECKSUM_FAIL:
            return "ERROR: Checksum fail";
        case NBioAPIERROR_MUST_BE_PROCESSED_DATA:
            return "ERROR: Must be processed data";
        default:
            return "ERROR: Unknown error";
        }
    }

    // Capture the digital FIR and return the hash of the template.
    NBioAPI_FIR_TEXTENCODE textFIR;
    nbioApiReturn = NBioAPI_GetTextFIRFromHandle(
        nbioApiHandle, firHandle, &textFIR, NBioAPI_FALSE);

    if (nbioApiReturn != NBioAPIERROR_NONE)
        return "ERROR: Problem in NBioAPI get Text FIR from Handle.";

    if (nbioApiReturn == NBioAPIERROR_NONE)
        return textFIR.TextFIR;
    else
        return "NULL";
}

// Method for carrying out comparisons of FIR templates.
bool NBioBSP_Match(std::string firCaptured, std::string firStored)
{
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
        std::cout << "ERROR: Problem in NBioAPI verify match." << std::endl;
        return false;
    }

    if (result == NBioAPI_TRUE) return true;
    else return false;
}

// Method to check the presence of a finger on the sensor
bool NBioBSP_Verify_Figer()
{
    NBioAPI_BOOL pbExistFinger;
    nbioApiReturn = NBioAPI_CheckFinger(nbioApiHandle, &pbExistFinger);

    if (nbioApiReturn != NBioAPIERROR_NONE)
    {
        switch (nbioApiReturn)
        {
        case NBioAPI_INVALID_HANDLE:
            std::cout << "ERROR: Problem to invalid NBioBSP handle." << std::endl;
            break;
        case NBioAPIERROR_DEVICE_NOT_OPENED:
            std::cout << "ERROR: Problem to device not opened." << std::endl;
            break;
        case NBioAPIERROR_LOWVERSION_DRIVER:
            std::cout << "ERROR: Problem to device driver does not support this feature. (HFDU 01/04/06(device driver version 4.1.0.1 or higher), HFDU 11/14(all version), HFDU 05/07 not support.)" << std::endl;
            break;
        default:
            break;
        }
    }

    if (pbExistFinger == NBioAPI_TRUE)
        return true;
    return false;
}

using namespace pybind11::literals;

PYBIND11_MODULE(pynbiobsp, module)
{
    module.doc() = "NBioBSP module for Python to device Nitgen Hamster III";
    module.def("init", &NBioBSP_Init, "Initialize the device");
    module.def("close", &NBioBSP_Close, "Close the device");
    module.def("capture", &NBioBSP_Capture, "Capture FIR template from fingerprint.", py::arg("enRoll")=false, "enRoll"_a = false);
    module.def("match", &NBioBSP_Match, "Match two FIRs template.");
    module.def("verify_finger", &NBioBSP_Verify_Figer, "Checks if there is a finger on the sensor.");
}

