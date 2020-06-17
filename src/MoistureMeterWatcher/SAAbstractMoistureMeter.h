#ifndef SAABSTRACTMOISTUREMETER_H
#define SAABSTRACTMOISTUREMETER_H
#include <QObject>
#include <QSerialPort>
/**
 * @brief 水分仪的基类
 * 测量数值变化会触发valueChange信号
 */
class SAAbstractMoistureMeter : public QObject
{
    Q_OBJECT
public:
    SAAbstractMoistureMeter(QObject* par = nullptr);
    virtual ~SAAbstractMoistureMeter();
    //建立串口,同时开始进行监听
    virtual bool openSeriesPort(const QString& portName
                     ,QSerialPort::BaudRate baudRate = QSerialPort::Baud9600
                     ,QSerialPort::Parity parity = QSerialPort::NoParity
                     ,QSerialPort::DataBits dataBits = QSerialPort::Data8
                     ,QSerialPort::StopBits stopBits = QSerialPort::OneStop
                     ,QSerialPort::FlowControl flowControl = QSerialPort::NoFlowControl
                    ) = 0;
    //停止监控
    virtual void close() = 0;
    //获取最后错误信息
    virtual QString getLastErrString() const = 0;
public:
    //打开串口的静态函数
    static bool setupSeriesPort(QSerialPort* serial
                               , const QString& portName
                               , QSerialPort::BaudRate baudRate = QSerialPort::Baud9600
                               , QSerialPort::Parity parity = QSerialPort::NoParity
                               , QSerialPort::DataBits dataBits = QSerialPort::Data8
                               , QSerialPort::StopBits stopBits = QSerialPort::OneStop
                               , QSerialPort::FlowControl flowControl = QSerialPort::NoFlowControl
                               );
signals:
    /**
     * @brief 水分仪的数值变化会触发此槽
     * @param index 品种序号
     * @param sampleIndex 品名代号P1~P24
     * @param temperature 温度【摄氏度】
     * @param weight 重量【g】
     * @param voltage 电压【V】
     * @param measureTimes 测量次数
     */
    void valueChange(int index,unsigned short sample,double temperature,double weight,double voltage,int measureTimes);
};

#endif // SAABSTRACTMOISTUREMETER_H
