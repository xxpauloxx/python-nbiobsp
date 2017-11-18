// Method to initialize the fingerprint reader.
bool nbiobspInit(){
    if (NBioAPI_Init(&bspHandle) != NBioAPIERROR_NONE) {
        std::cout << "Initialization failed." << std::endl;
        return false;
    }

    idDevice = NBioAPI_DEVICE_ID_AUTO; // Opening the device for use.
    ret = NBioAPI_OpenDevice(bspHandle, idDevice);

    if (ret != NBioAPIERROR_NONE) {
        std::cout << "Unable to connect to device." << std::endl;
        return false;
    }

    return true;
}
