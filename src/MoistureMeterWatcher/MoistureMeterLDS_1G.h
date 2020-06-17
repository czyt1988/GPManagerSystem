#ifndef MOISTUREMETERLDS_1G_H
#define MOISTUREMETERLDS_1G_H
#include "SAAbstractMoistureMeter.h"
#include <QSerialPort>
#include <vector>
/**
 * @brief The MoistureMeterLDS_1G class
 */
class MoistureMeterLDS_1G : public SAAbstractMoistureMeter
{
    Q_OBJECT
public:
    MoistureMeterLDS_1G(QObject* par);
    ~MoistureMeterLDS_1G();
    //建立串口
    virtual bool openSeriesPort(const QString& portName
                                 ,QSerialPort::BaudRate baudRate = QSerialPort::Baud9600
                                 ,QSerialPort::Parity parity = QSerialPort::NoParity
                                 ,QSerialPort::DataBits dataBits = QSerialPort::Data8
                                 ,QSerialPort::StopBits stopBits = QSerialPort::OneStop
                                 ,QSerialPort::FlowControl flowControl = QSerialPort::NoFlowControl
                                ) override;
    //开始监控
    virtual void close() override;
    //停止监控
    virtual QString getLastErrString() const override;
private slots:
    void onReadyRead();
private:
    //处理单独一帧数据
    void deal(const DataFrame& df);
private:
    class DataFrame
    {
    public:
        DataFrame();
        //判断头是否有效
        bool isHeaderValid() const;
        //插入数据
        void append(char v);
        //返回数据尺寸
        std::size_t size() const;
        //重载取值操作符
        char& operator [](std::size_t index);
        const char& operator [](std::size_t index) const;
        //清空帧
        void clear();
    private:
        std::vector<char> datas;
    };
private:
    QSerialPort m_serialPort;
    DataFrame m_tmpDatafrm;
};

#endif // MOISTUREMETERLDS_1G_H
