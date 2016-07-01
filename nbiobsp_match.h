
// Método para a realização de comparações de FIR templates.
bool pynbiobspMatch(string firCaptured, string firStored){
    NBioAPI_BOOL result;
    NBioAPI_INPUT_FIR inputFirCaptured, inputFirStored;

    // Convertendo para string as FIRs do argumento do método.
    std::string valueFirCaptured(firCaptured);
    std::string valueFirStored(firStored);

    // Extraindo os tamanhos dos valores do template capturado e armazenado.
    int lenFirCaptured = strlen(valueFirCaptured.c_str());
    int lenFirStored = strlen(valueFirStored.c_str());

    // Extraindo o hash do template FIR capturado.
    NBioAPI_FIR_TEXTENCODE textFirCaptured; 
    textFirCaptured.IsWideChar = NBioAPI_FALSE;         
    textFirCaptured.TextFIR = new NBioAPI_CHAR[lenFirCaptured+1];
    memcpy(textFirCaptured.TextFIR, valueFirCaptured.c_str(), lenFirCaptured+1);
 
    // Registrando o hash do template FIR no Input de FIR capturado.
    inputFirCaptured.Form = NBioAPI_FIR_FORM_TEXTENCODE; 
    inputFirCaptured.InputFIR.TextFIR = &textFirCaptured;

    // Extraindo o hash do template FIR armazenado.
    NBioAPI_FIR_TEXTENCODE textFirStored; 
    textFirStored.IsWideChar = NBioAPI_FALSE;  
    textFirStored.TextFIR = new NBioAPI_CHAR[lenFirStored+1];       
    memcpy(textFirStored.TextFIR, valueFirStored.c_str(), lenFirStored+1); 

    // Registrando o hash do template FIR no Input de FIR armazenado.
    inputFirStored.Form = NBioAPI_FIR_FORM_TEXTENCODE; 
    inputFirStored.InputFIR.TextFIR = &textFirStored;

    // Fazer match das FIR e armazenar o resultado em result.
    ret = NBioAPI_VerifyMatch( 
        bspHandle,      	// Manipulador do módulo NBioBSP
        &inputFirCaptured, 	// Primeira FIR
        &inputFirStored,  	// Segunda FIR
        &result,    		// Resultado da comparação
        NULL    			// Payload
    );     
    
    if(result == NBioAPI_TRUE){ return true; }
    else{ return false; }
}
