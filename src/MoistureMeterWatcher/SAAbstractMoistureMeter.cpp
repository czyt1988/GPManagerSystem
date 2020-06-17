#include "SAAbstractMoistureMeter.h"





/**
 * @fn virtual bool openSeriesPort(const QString& portName,QSerialPort::BaudRate baudRate,QSerialPort::Parity parity,QSerialPort::DataBits dataBits,QSerialPort::StopBits stopBits,QSerialPort::FlowControl flowControl) = 0
 *
 * 建立串口通讯
 * @param portName 窗口名
 * @param baudRate 波特率
 * @param parity 校验位
 * @param dataBits 数据位
 * @param stopBits 停止位
 * @param flowControl 是否流控制
 * @return
 */

/**
 * @fn virtual void SAAbstractMoistureMeter::close()
 *
 * 结束仪表的监听
 * @return 成功返回true
 */

/**
 * @fn virtual bool SAAbstractMoistureMeter::getLastErrString()
 *
 * 获取最后错误信息
 * @return 返回错误字符描述
 */

SAAbstractMoistureMeter::SAAbstractMoistureMeter(QObject *par):QObject(par)
{

}

SAAbstractMoistureMeter::~SAAbstractMoistureMeter()
{

}

/**
 * @brief 打开串口
 * @param serial 串口指针
 * @param portName 窗口名
 * @param baudRate 波特率
 * @param parity 校验位
 * @param dataBits 数据位
 * @param stopBits 停止位
 * @param flowControl 是否流控制
 * @return
 */
bool SAAbstractMoistureMeter::setupSeriesPort(QSerialPort *serial
                                             , const QString &portName
                                             , QSerialPort::BaudRate baudRate
                                             , QSerialPort::Parity parity
                                             , QSerialPort::DataBits dataBits
                                             , QSerialPort::StopBits stopBits
                                             , QSerialPort::FlowControl flowControl
                                             )
{
    Q_CHECK_PTR(serial);
    serial->setPortName(portName);
    if(!serial->open(QIODevice::ReadWrite))
    {
        return false;
    }
    serial->setBaudRate(baudRate);
    serial->setDataBits(dataBits);
    serial->setParity(parity);
    serial->setStopBits(stopBits);
    serial->setFlowControl(flowControl);
    return true;
}
