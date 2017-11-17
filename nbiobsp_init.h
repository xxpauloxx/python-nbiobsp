// Method to initialize the fingerprint reader.
bool pynbiobspInit(){
    if ( NBioAPI_Init(&bspHandle) != NBioAPIERROR_NONE ){
        cout << "Falha na inicialização" << endl;
        return false;
    }

    idDevice = NBioAPI_DEVICE_ID_AUTO; // Opening the device for use.
    ret = NBioAPI_OpenDevice(bspHandle, idDevice);
    if ( ret != NBioAPIERROR_NONE ){
        cout << "Falha ao conectar no dispositivo" << endl;
        return false;
    }

    return true;
}
