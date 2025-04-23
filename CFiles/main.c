#include <stdio.h>
#include <dlfcn.h>

typedef void (*InitFunction)();

int main()
{
	void* handle;
	char* error;
	int value;
	InitFunction init1;
	InitFunction init2;

	// Load DynamicLibrary1.so
	handle = dlopen("./DynamicLibrary1.so", RTLD_LAZY);
	error = dlerror();
	if (!handle)
	{
		fprintf(stderr, "%s\n", error);
	}
	error = dlerror();
	// Load DynamicLibrary1 Function ¡°Init1¡±
	init1 = (InitFunction)dlsym(handle, "Init1");
	if (error != NULL) {
		fprintf(stderr, "%s\n", error);
		dlclose(handle);
		return 1;
	}

	// Load DynamicLibrary2.so
	handle = dlopen("./DynamicLibrary2.so", RTLD_LAZY);
	error = dlerror();
	if (!handle)
	{
		fprintf(stderr, "%s\n", error);
	}
	error = dlerror();

	// Load DynamicLibrary2 Function ¡°Init2¡±
	init2 = (InitFunction)dlsym(handle, "Init2");
	if (error != NULL) {
		fprintf(stderr, "%s\n", error);
		dlclose(handle);
		return 1;
	}
	printf("Begin Execute DynamicLibrary1\n");
	init1();
	printf("End Execute DynamicLibrary1\n");

	printf("Begin Execute DynamicLibrary2\n");
	init2();
	printf("End Execute DynamicLibrary2\n");


	return 0;
}