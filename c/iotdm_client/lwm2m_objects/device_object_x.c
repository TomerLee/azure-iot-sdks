

// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

//
// Simple implementation of IoTHub LWM2M Device object
//

//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.

#include "iotdm_internal.h"
#include "iotdm_dispatchers.h"
#include "device_object.h"

// Property Indices for for device object
#define INDEX_DEVICE_MANUFACTURER 0
#define INDEX_DEVICE_MODELNUMBER 1
#define INDEX_DEVICE_SERIALNUMBER 2
#define INDEX_DEVICE_FIRMWAREVERSION 3
#define INDEX_DEVICE_REBOOT 4
#define INDEX_DEVICE_FACTORYRESET 5
#define INDEX_DEVICE_BATTERYLEVEL 6
#define INDEX_DEVICE_MEMORYFREE 7
#define INDEX_DEVICE_CURRENTTIME 8
#define INDEX_DEVICE_UTCOFFSET 9
#define INDEX_DEVICE_TIMEZONE 10
#define INDEX_DEVICE_DEVICETYPE 11
#define INDEX_DEVICE_HARDWAREVERSION 12
#define INDEX_DEVICE_BATTERYSTATUS 13
#define INDEX_DEVICE_MEMORYTOTAL 14

void set_default_device_property_values(object_device *obj);
IOTHUB_CLIENT_RESULT on_read_device_manufacturer(object_device *obj, char **value);
IOTHUB_CLIENT_RESULT on_read_device_modelnumber(object_device *obj, char **value);
IOTHUB_CLIENT_RESULT on_read_device_serialnumber(object_device *obj, char **value);
IOTHUB_CLIENT_RESULT on_read_device_firmwareversion(object_device *obj, char **value);
IOTHUB_CLIENT_RESULT on_exec_device_reboot(object_device *obj);
IOTHUB_CLIENT_RESULT on_exec_device_factoryreset(object_device *obj);
IOTHUB_CLIENT_RESULT on_read_device_batterylevel(object_device *obj, int *value);
IOTHUB_CLIENT_RESULT on_read_device_memoryfree(object_device *obj, int *value);
IOTHUB_CLIENT_RESULT on_read_device_currenttime(object_device *obj, int *value);
IOTHUB_CLIENT_RESULT on_write_device_currenttime(object_device *obj, int value);
IOTHUB_CLIENT_RESULT on_read_device_utcoffset(object_device *obj, char **value);
IOTHUB_CLIENT_RESULT on_write_device_utcoffset(object_device *obj, char* value);
IOTHUB_CLIENT_RESULT on_read_device_timezone(object_device *obj, char **value);
IOTHUB_CLIENT_RESULT on_write_device_timezone(object_device *obj, char* value);
IOTHUB_CLIENT_RESULT on_read_device_devicetype(object_device *obj, char **value);
IOTHUB_CLIENT_RESULT on_read_device_hardwareversion(object_device *obj, char **value);
IOTHUB_CLIENT_RESULT on_read_device_batterystatus(object_device *obj, int *value);
IOTHUB_CLIENT_RESULT on_read_device_memorytotal(object_device *obj, int *value);


/**********************************************************************************
 * Device setters
 *
 **********************************************************************************/
IOTHUB_CLIENT_RESULT set_device_manufacturer(uint16_t instanceId, char* value)
{
    IOTHUB_CLIENT_RESULT result = IOTHUB_CLIENT_ERROR;
    object_device *obj = get_object_instance(OID_DEVICE, instanceId);
    if (obj != NULL)
    {
        if ((obj->propval_device_manufacturer == NULL) || strcmp(obj->propval_device_manufacturer, value))
        {
            LogInfo("Device_Manufacturer being set to [%s]\r\n", value);
            lwm2m_free(obj->propval_device_manufacturer);
            obj->propval_device_manufacturer = lwm2m_strdup(value);

            obj->resourceUpdated[INDEX_DEVICE_MANUFACTURER] = (char)true;
            wake_main_dm_thread(obj->channelHandle);
        }

        result = IOTHUB_CLIENT_OK;

    }
    return result;
}

IOTHUB_CLIENT_RESULT set_device_modelnumber(uint16_t instanceId, char* value)
{
    IOTHUB_CLIENT_RESULT result = IOTHUB_CLIENT_ERROR;
    object_device *obj = get_object_instance(OID_DEVICE, instanceId);
    if (obj != NULL)
    {
        if ((obj->propval_device_modelnumber == NULL) || strcmp(obj->propval_device_modelnumber, value))
        {
            LogInfo("Device_ModelNumber being set to [%s]\r\n", value);
            lwm2m_free(obj->propval_device_modelnumber);
            obj->propval_device_modelnumber = lwm2m_strdup(value);

            obj->resourceUpdated[INDEX_DEVICE_MODELNUMBER] = (char)true;
            wake_main_dm_thread(obj->channelHandle);
        }

        result = IOTHUB_CLIENT_OK;

    }
    return result;
}

IOTHUB_CLIENT_RESULT set_device_serialnumber(uint16_t instanceId, char* value)
{
    IOTHUB_CLIENT_RESULT result = IOTHUB_CLIENT_ERROR;
    object_device *obj = get_object_instance(OID_DEVICE, instanceId);
    if (obj != NULL)
    {
        if ((obj->propval_device_serialnumber == NULL) || strcmp(obj->propval_device_serialnumber, value))
        {
            LogInfo("Device_SerialNumber being set to [%s]\r\n", value);
            lwm2m_free(obj->propval_device_serialnumber);
            obj->propval_device_serialnumber = lwm2m_strdup(value);

            obj->resourceUpdated[INDEX_DEVICE_SERIALNUMBER] = (char)true;
            wake_main_dm_thread(obj->channelHandle);
        }

        result = IOTHUB_CLIENT_OK;

    }
    return result;
}

IOTHUB_CLIENT_RESULT set_device_firmwareversion(uint16_t instanceId, char* value)
{
    IOTHUB_CLIENT_RESULT result = IOTHUB_CLIENT_ERROR;
    object_device *obj = get_object_instance(OID_DEVICE, instanceId);
    if (obj != NULL)
    {
        if ((obj->propval_device_firmwareversion == NULL) || strcmp(obj->propval_device_firmwareversion, value))
        {
            LogInfo("Device_FirmwareVersion being set to [%s]\r\n", value);
            lwm2m_free(obj->propval_device_firmwareversion);
            obj->propval_device_firmwareversion = lwm2m_strdup(value);

            obj->resourceUpdated[INDEX_DEVICE_FIRMWAREVERSION] = (char)true;
            wake_main_dm_thread(obj->channelHandle);
        }

        result = IOTHUB_CLIENT_OK;

    }
    return result;
}

IOTHUB_CLIENT_RESULT set_device_batterylevel(uint16_t instanceId, int value)
{
    IOTHUB_CLIENT_RESULT result = IOTHUB_CLIENT_ERROR;
    object_device *obj = get_object_instance(OID_DEVICE, instanceId);
    if (obj != NULL)
    {
        if (obj->propval_device_batterylevel != value)
        {
            LogInfo("Device_BatteryLevel being set to %d\r\n", value);
            obj->propval_device_batterylevel = value;

            obj->resourceUpdated[INDEX_DEVICE_BATTERYLEVEL] = (char)true;
            wake_main_dm_thread(obj->channelHandle);
        }

        result = IOTHUB_CLIENT_OK;

    }
    return result;
}

IOTHUB_CLIENT_RESULT set_device_memoryfree(uint16_t instanceId, int value)
{
    IOTHUB_CLIENT_RESULT result = IOTHUB_CLIENT_ERROR;
    object_device *obj = get_object_instance(OID_DEVICE, instanceId);
    if (obj != NULL)
    {
        if (obj->propval_device_memoryfree != value)
        {
            LogInfo("Device_MemoryFree being set to %d\r\n", value);
            obj->propval_device_memoryfree = value;

            obj->resourceUpdated[INDEX_DEVICE_MEMORYFREE] = (char)true;
            wake_main_dm_thread(obj->channelHandle);
        }

        result = IOTHUB_CLIENT_OK;

    }
    return result;
}

IOTHUB_CLIENT_RESULT set_device_currenttime(uint16_t instanceId, int value)
{
    IOTHUB_CLIENT_RESULT result = IOTHUB_CLIENT_ERROR;
    object_device *obj = get_object_instance(OID_DEVICE, instanceId);
    if (obj != NULL)
    {
        if (obj->propval_device_currenttime != value)
        {
            LogInfo("Device_CurrentTime being set to %d\r\n", value);
            obj->propval_device_currenttime = value;

            obj->resourceUpdated[INDEX_DEVICE_CURRENTTIME] = (char)true;
            wake_main_dm_thread(obj->channelHandle);
        }

        result = IOTHUB_CLIENT_OK;

    }
    return result;
}

IOTHUB_CLIENT_RESULT set_device_utcoffset(uint16_t instanceId, char* value)
{
    IOTHUB_CLIENT_RESULT result = IOTHUB_CLIENT_ERROR;
    object_device *obj = get_object_instance(OID_DEVICE, instanceId);
    if (obj != NULL)
    {
        if ((obj->propval_device_utcoffset == NULL) || strcmp(obj->propval_device_utcoffset, value))
        {
            LogInfo("Device_UtcOffset being set to [%s]\r\n", value);
            lwm2m_free(obj->propval_device_utcoffset);
            obj->propval_device_utcoffset = lwm2m_strdup(value);

            obj->resourceUpdated[INDEX_DEVICE_UTCOFFSET] = (char)true;
            wake_main_dm_thread(obj->channelHandle);
        }

        result = IOTHUB_CLIENT_OK;

    }
    return result;
}

IOTHUB_CLIENT_RESULT set_device_timezone(uint16_t instanceId, char* value)
{
    IOTHUB_CLIENT_RESULT result = IOTHUB_CLIENT_ERROR;
    object_device *obj = get_object_instance(OID_DEVICE, instanceId);
    if (obj != NULL)
    {
        if ((obj->propval_device_timezone == NULL) || strcmp(obj->propval_device_timezone, value))
        {
            LogInfo("Device_Timezone being set to [%s]\r\n", value);
            lwm2m_free(obj->propval_device_timezone);
            obj->propval_device_timezone = lwm2m_strdup(value);

            obj->resourceUpdated[INDEX_DEVICE_TIMEZONE] = (char)true;
            wake_main_dm_thread(obj->channelHandle);
        }

        result = IOTHUB_CLIENT_OK;

    }
    return result;
}

IOTHUB_CLIENT_RESULT set_device_devicetype(uint16_t instanceId, char* value)
{
    IOTHUB_CLIENT_RESULT result = IOTHUB_CLIENT_ERROR;
    object_device *obj = get_object_instance(OID_DEVICE, instanceId);
    if (obj != NULL)
    {
        if ((obj->propval_device_devicetype == NULL) || strcmp(obj->propval_device_devicetype, value))
        {
            LogInfo("Device_DeviceType being set to [%s]\r\n", value);
            lwm2m_free(obj->propval_device_devicetype);
            obj->propval_device_devicetype = lwm2m_strdup(value);

            obj->resourceUpdated[INDEX_DEVICE_DEVICETYPE] = (char)true;
            wake_main_dm_thread(obj->channelHandle);
        }

        result = IOTHUB_CLIENT_OK;

    }
    return result;
}

IOTHUB_CLIENT_RESULT set_device_hardwareversion(uint16_t instanceId, char* value)
{
    IOTHUB_CLIENT_RESULT result = IOTHUB_CLIENT_ERROR;
    object_device *obj = get_object_instance(OID_DEVICE, instanceId);
    if (obj != NULL)
    {
        if ((obj->propval_device_hardwareversion == NULL) || strcmp(obj->propval_device_hardwareversion, value))
        {
            LogInfo("Device_HardwareVersion being set to [%s]\r\n", value);
            lwm2m_free(obj->propval_device_hardwareversion);
            obj->propval_device_hardwareversion = lwm2m_strdup(value);

            obj->resourceUpdated[INDEX_DEVICE_HARDWAREVERSION] = (char)true;
            wake_main_dm_thread(obj->channelHandle);
        }

        result = IOTHUB_CLIENT_OK;

    }
    return result;
}

IOTHUB_CLIENT_RESULT set_device_batterystatus(uint16_t instanceId, int value)
{
    IOTHUB_CLIENT_RESULT result = IOTHUB_CLIENT_ERROR;
    object_device *obj = get_object_instance(OID_DEVICE, instanceId);
    if (obj != NULL)
    {
        if (obj->propval_device_batterystatus != value)
        {
            LogInfo("Device_BatteryStatus being set to %d\r\n", value);
            obj->propval_device_batterystatus = value;

            obj->resourceUpdated[INDEX_DEVICE_BATTERYSTATUS] = (char)true;
            wake_main_dm_thread(obj->channelHandle);
        }

        result = IOTHUB_CLIENT_OK;

    }
    return result;
}

IOTHUB_CLIENT_RESULT set_device_memorytotal(uint16_t instanceId, int value)
{
    IOTHUB_CLIENT_RESULT result = IOTHUB_CLIENT_ERROR;
    object_device *obj = get_object_instance(OID_DEVICE, instanceId);
    if (obj != NULL)
    {
        if (obj->propval_device_memorytotal != value)
        {
            LogInfo("Device_MemoryTotal being set to %d\r\n", value);
            obj->propval_device_memorytotal = value;

            obj->resourceUpdated[INDEX_DEVICE_MEMORYTOTAL] = (char)true;
            wake_main_dm_thread(obj->channelHandle);
        }

        result = IOTHUB_CLIENT_OK;

    }
    return result;
}


/**********************************************************************************
 * Device creation and destruction
 *
 **********************************************************************************/
static void destroy_device_object(object_device *obj)
{
    if (obj != NULL)
    {
        lwm2m_free(obj->propval_device_manufacturer);
        lwm2m_free(obj->propval_device_modelnumber);
        lwm2m_free(obj->propval_device_serialnumber);
        lwm2m_free(obj->propval_device_firmwareversion);
        lwm2m_free(obj->propval_device_utcoffset);
        lwm2m_free(obj->propval_device_timezone);
        lwm2m_free(obj->propval_device_devicetype);
        lwm2m_free(obj->propval_device_hardwareversion);
        lwm2m_free(obj);
    }
}

static uint16_t g_next_device_instance_id = 0;
static uint16_t get_next_device_instance_id()
{
    return g_next_device_instance_id++;
}

IOTHUB_CLIENT_RESULT create_device_object(IOTHUB_CLIENT_HANDLE h, uint16_t *instanceId)
{
    IOTHUB_CLIENT_RESULT res = IOTHUB_CLIENT_OK;

    res = REGISTER_DISPATCHERS(OID_DEVICE, object_device);
    if (res != IOTHUB_CLIENT_OK)
    {
        LogError("Failed registering dispatchers");
        res = IOTHUB_CLIENT_ERROR;
    }
    else
    {
        object_device *obj = (object_device *)lwm2m_malloc(sizeof(object_device));
        if (obj == NULL)
        {
            LogError("malloc failure");
            res = IOTHUB_CLIENT_ERROR;
        }
        else
        {
            memset(obj,0,sizeof(*obj));
            obj->instanceId = get_next_device_instance_id();
            obj->channelHandle = h;
                
            res = add_dm_object(&object_device_instance_list, obj);
            if (res != IOTHUB_CLIENT_OK)
            {
                LogError("adding Device object to object list\r\n");

                destroy_device_object(obj);
                obj = NULL;
            }
            else
            {
                set_default_device_property_values(obj);
            }
        }

        if (instanceId != NULL)
        {
            *instanceId = (obj == NULL) ? 0 : obj->instanceId;
        }
    }

    return res;
}

object_device *get_device_object(uint16_t instanceId)
{
    object_device *obj = NULL;

    (void)get_dm_object(object_device_instance_list, instanceId, (void*)&obj);

    return obj;
}

#define DO_SIGNAL_RESOURCE_CHANGE(index, property) \
    if (obj->resourceUpdated[index]) \
    { \
        on_resource_value_changed(OID_DEVICE, obj->instanceId, property); \
        obj->resourceUpdated[index] = (char)false; \
    }

   
void signal_object_device_resource_changed(void *p)
{
    object_device *obj = (object_device*)p;
    DO_SIGNAL_RESOURCE_CHANGE(INDEX_DEVICE_MANUFACTURER, PID_DEVICE_MANUFACTURER)
    DO_SIGNAL_RESOURCE_CHANGE(INDEX_DEVICE_MODELNUMBER, PID_DEVICE_MODELNUMBER)
    DO_SIGNAL_RESOURCE_CHANGE(INDEX_DEVICE_SERIALNUMBER, PID_DEVICE_SERIALNUMBER)
    DO_SIGNAL_RESOURCE_CHANGE(INDEX_DEVICE_FIRMWAREVERSION, PID_DEVICE_FIRMWAREVERSION)
    DO_SIGNAL_RESOURCE_CHANGE(INDEX_DEVICE_REBOOT, PID_DEVICE_REBOOT)
    DO_SIGNAL_RESOURCE_CHANGE(INDEX_DEVICE_FACTORYRESET, PID_DEVICE_FACTORYRESET)
    DO_SIGNAL_RESOURCE_CHANGE(INDEX_DEVICE_BATTERYLEVEL, PID_DEVICE_BATTERYLEVEL)
    DO_SIGNAL_RESOURCE_CHANGE(INDEX_DEVICE_MEMORYFREE, PID_DEVICE_MEMORYFREE)
    DO_SIGNAL_RESOURCE_CHANGE(INDEX_DEVICE_CURRENTTIME, PID_DEVICE_CURRENTTIME)
    DO_SIGNAL_RESOURCE_CHANGE(INDEX_DEVICE_UTCOFFSET, PID_DEVICE_UTCOFFSET)
    DO_SIGNAL_RESOURCE_CHANGE(INDEX_DEVICE_TIMEZONE, PID_DEVICE_TIMEZONE)
    DO_SIGNAL_RESOURCE_CHANGE(INDEX_DEVICE_DEVICETYPE, PID_DEVICE_DEVICETYPE)
    DO_SIGNAL_RESOURCE_CHANGE(INDEX_DEVICE_HARDWAREVERSION, PID_DEVICE_HARDWAREVERSION)
    DO_SIGNAL_RESOURCE_CHANGE(INDEX_DEVICE_BATTERYSTATUS, PID_DEVICE_BATTERYSTATUS)
    DO_SIGNAL_RESOURCE_CHANGE(INDEX_DEVICE_MEMORYTOTAL, PID_DEVICE_MEMORYTOTAL)
}

BEGIN_READ_DISPATCHER(object_device)
    STRING_READ(PID_DEVICE_MANUFACTURER, on_read_device_manufacturer)
    STRING_READ(PID_DEVICE_MODELNUMBER, on_read_device_modelnumber)
    STRING_READ(PID_DEVICE_SERIALNUMBER, on_read_device_serialnumber)
    STRING_READ(PID_DEVICE_FIRMWAREVERSION, on_read_device_firmwareversion)
    INTEGER_READ(PID_DEVICE_BATTERYLEVEL, on_read_device_batterylevel)
    INTEGER_READ(PID_DEVICE_MEMORYFREE, on_read_device_memoryfree)
    TIME_READ(PID_DEVICE_CURRENTTIME, on_read_device_currenttime)
    STRING_READ(PID_DEVICE_UTCOFFSET, on_read_device_utcoffset)
    STRING_READ(PID_DEVICE_TIMEZONE, on_read_device_timezone)
    STRING_READ(PID_DEVICE_DEVICETYPE, on_read_device_devicetype)
    STRING_READ(PID_DEVICE_HARDWAREVERSION, on_read_device_hardwareversion)
    INTEGER_READ(PID_DEVICE_BATTERYSTATUS, on_read_device_batterystatus)
    INTEGER_READ(PID_DEVICE_MEMORYTOTAL, on_read_device_memorytotal)
END_READ_DISPATCHER()

BEGIN_EXEC_DISPATCHER(object_device)
    EXEC(PID_DEVICE_REBOOT, on_exec_device_reboot)
    EXEC(PID_DEVICE_FACTORYRESET, on_exec_device_factoryreset)
END_EXEC_DISPATCHER()

BEGIN_WRITE_DISPATCHER(object_device)
    TIME_WRITE(PID_DEVICE_CURRENTTIME, on_write_device_currenttime)
    STRING_WRITE(PID_DEVICE_UTCOFFSET, on_write_device_utcoffset)
    STRING_WRITE(PID_DEVICE_TIMEZONE, on_write_device_timezone)
END_WRITE_DISPATCHER();

BEGIN_OPERATION_LIST(object_device)
    OPERATION(PID_DEVICE_MANUFACTURER, OP_R, LWM2M_TYPE_STRING)
    OPERATION(PID_DEVICE_MODELNUMBER, OP_R, LWM2M_TYPE_STRING)
    OPERATION(PID_DEVICE_SERIALNUMBER, OP_R, LWM2M_TYPE_STRING)
    OPERATION(PID_DEVICE_FIRMWAREVERSION, OP_R, LWM2M_TYPE_STRING)
    OPERATION(PID_DEVICE_REBOOT, OP_E, LWM2M_TYPE_UNDEFINED)
    OPERATION(PID_DEVICE_FACTORYRESET, OP_E, LWM2M_TYPE_UNDEFINED)
    OPERATION(PID_DEVICE_BATTERYLEVEL, OP_R, LWM2M_TYPE_INTEGER)
    OPERATION(PID_DEVICE_MEMORYFREE, OP_R, LWM2M_TYPE_INTEGER)
    OPERATION(PID_DEVICE_CURRENTTIME, OP_RW, LWM2M_TYPE_TIME)
    OPERATION(PID_DEVICE_UTCOFFSET, OP_RW, LWM2M_TYPE_STRING)
    OPERATION(PID_DEVICE_TIMEZONE, OP_RW, LWM2M_TYPE_STRING)
    OPERATION(PID_DEVICE_DEVICETYPE, OP_R, LWM2M_TYPE_STRING)
    OPERATION(PID_DEVICE_HARDWAREVERSION, OP_R, LWM2M_TYPE_STRING)
    OPERATION(PID_DEVICE_BATTERYSTATUS, OP_R, LWM2M_TYPE_INTEGER)
    OPERATION(PID_DEVICE_MEMORYTOTAL, OP_R, LWM2M_TYPE_INTEGER)
END_OPERATION_LIST()


