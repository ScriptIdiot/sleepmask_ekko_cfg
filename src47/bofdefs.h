// To use it, just copy and append to bofdefs.h from sleepmask kit
// Below are added for CFG
#define NT_SUCCESS(Status) ((NTSTATUS)(Status) >= 0)
#define NtCurrentThread() (  ( HANDLE ) ( LONG_PTR ) -2 )
#define NtCurrentProcess() ( ( HANDLE ) ( LONG_PTR ) -1 )

typedef struct _VM_INFORMATION
{
	DWORD					dwNumberOfOffsets;
	PULONG					plOutput;
	PCFG_CALL_TARGET_INFO	ptOffsets;
	PVOID					pMustBeZero;
	PVOID					pMoarZero;

} VM_INFORMATION, * PVM_INFORMATION;

typedef enum _VIRTUAL_MEMORY_INFORMATION_CLASS
{
	VmPrefetchInformation,
	VmPagePriorityInformation,
	VmCfgCallTargetInformation
} VIRTUAL_MEMORY_INFORMATION_CLASS;

typedef struct _MEMORY_RANGE_ENTRY
{
	PVOID  VirtualAddress;
	SIZE_T NumberOfBytes;
} MEMORY_RANGE_ENTRY, * PMEMORY_RANGE_ENTRY;

typedef enum _MEMORY_INFORMATION_CLASS {
	MemoryBasicInformation
} MEMORY_INFORMATION_CLASS;

NTSYSAPI NTSTATUS NTAPI NTDLL$NtSetInformationVirtualMemory(HANDLE, VIRTUAL_MEMORY_INFORMATION_CLASS, ULONG_PTR, PMEMORY_RANGE_ENTRY, PVOID, ULONG);
NTSYSAPI NTSTATUS NTAPI NTDLL$NtQueryVirtualMemory(HANDLE, PVOID, MEMORY_INFORMATION_CLASS, PVOID, SIZE_T, PSIZE_T);
WINBASEAPI FARPROC WINAPI KERNEL32$GetProcAddress (HMODULE, LPCSTR);
WINBASEAPI HMODULE WINAPI KERNEL32$GetModuleHandleA (LPCSTR);
