// Method to end device usage and free up memory.
void pynbiobspClose(){
	ret = NBioAPI_CloseDevice(bspHandle, idDevice);
	ret = NBioAPI_Terminate(bspHandle);
}
