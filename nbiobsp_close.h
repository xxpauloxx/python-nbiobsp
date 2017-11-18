// Method to end device usage and free up memory.
void nbiobspClose(){
	NBioAPI_CloseDevice(bspHandle, idDevice);
	NBioAPI_Terminate(bspHandle);
}
