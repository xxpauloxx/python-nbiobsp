
// Método para capturar a impressão digital e retornar um FIR.
string pynbiobspCapture(int timeout){
    NBioAPI_FIR_HANDLE firHandle;
    NBioAPI_FIR_PURPOSE purpose;

    purpose = NBioAPI_FIR_PURPOSE_ENROLL;
    ret = NBioAPI_Capture(
        bspHandle,   // Módulo para manusear módulo NBioBSP
        purpose,     // Propósito da captura
        &firHandle,  // Manipular o FIR capturado
        timeout,     // Timeout para captura
        NULL,        // Dados para auditoria
        NULL         // Opção da janela
    );

    // Capturar FIR da digital e retornar o hash do template.
    NBioAPI_FIR_TEXTENCODE textFIR;
    ret = NBioAPI_GetTextFIRFromHandle(bspHandle, firHandle, &textFIR, NBioAPI_FALSE);

    if(ret == 0){ return textFIR.TextFIR; }
    else{ return "NULL"; }
}