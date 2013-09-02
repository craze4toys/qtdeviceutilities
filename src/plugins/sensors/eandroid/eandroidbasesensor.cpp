#include <eandroidbasesensor.h>
#include <eandroidsensordevice.h>

EAndroidBaseSensor::EAndroidBaseSensor(int sensorType, QSensor *sensor)
    : QSensorBackend(sensor)
{
    m_type = sensorType;
    m_isStarted = false;
    EAndroidSensorDevice *device = EAndroidSensorDevice::instance();
    setDescription(device->description(sensorType));
#if 0 // #### TODO - QTBUG-33293
    qint32 maxRate = device->maxDataRate(sensorType); // convert to Hz
    addDataRate(1, 70);
    addOutputRange(1,55,6);
#endif
}

EAndroidBaseSensor::~EAndroidBaseSensor()
{
    if (m_isStarted)
        stop();
}

void EAndroidBaseSensor::start()
{
    EAndroidSensorDevice::instance()->registerListener(m_type, this, sensor()->dataRate());
    m_isStarted = true;
}

void EAndroidBaseSensor::stop()
{
    if (m_isStarted) {
        m_isStarted = false;
        EAndroidSensorDevice::instance()->unregisterListener(m_type, this);
    }
}

void EAndroidBaseSensor::processEvent(sensors_event_t &event)
{
    Q_UNUSED(event)
}
