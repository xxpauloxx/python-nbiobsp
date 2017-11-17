// Método para inicializar o dispositivo de leitura de impressão digital.
bool pynbiobspInit(){
    if ( NBioAPI_Init(&bspHandle) != NBioAPIERROR_NONE ){
        cout << "Falha na inicialização" << endl; // Inicializando API.
        return false;
    }

    idDevice = NBioAPI_DEVICE_ID_AUTO; // Abrindo o dispositivo para uso.
    ret = NBioAPI_OpenDevice(bspHandle, idDevice);
    if ( ret != NBioAPIERROR_NONE ){
        cout << "Falha ao conectar no dispositivo" << endl;
        return false;
    }

    return true;
}
