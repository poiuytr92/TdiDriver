#pragma once
#include <ntddk.h>
#include <tdi.h>

#define TCP_DEVICE_NAME					L"\\Device\\Tcp"
#define UDP_DEVICE_NAME					L"\\Device\\Udp"
#define RAWIP_DEVICE_NAME		    	L"\\Device\\RawIp"

#ifdef __cplusplus
extern "C"
{
#endif


VOID DriverUnload(PDRIVER_OBJECT DriverObject);

NTSTATUS DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegistryPath);

//创建并绑定指定设备
NTSTATUS CreateAndAttachDevice(PDRIVER_OBJECT DriverObject, PDEVICE_OBJECT * fltObj, PDEVICE_OBJECT * oldObj, PWCHAR deviceName);

//取消绑定并删除设备
VOID DetachAndDeleteDevie(PDRIVER_OBJECT DriverObject, PDEVICE_OBJECT fltObj, PDEVICE_OBJECT oldObj);

// 分发函数
NTSTATUS DeviceDisPatch(PDEVICE_OBJECT DeviceObject, PIRP Irp);

NTSTATUS TdiCreate(PDEVICE_OBJECT DeviceObject, PIRP Irp);

#ifdef __cplusplus
}
#endif

