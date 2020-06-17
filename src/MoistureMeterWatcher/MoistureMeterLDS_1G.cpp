#include "MoistureMeterLDS_1G.h"
#include <QDebug>


MoistureMeterLDS_1G::DataFrame::DataFrame()
{
    datas.reserve(16);
}

/**
 * @brief 判断头是否有效
 * @return
 */
bool MoistureMeterLDS_1G::DataFrame::isHeaderValid() const
{
    if(datas.size() <= 0)
        return false;
    return datas[0] == 0x3D;
}

/**
 * @brief 追加数据，此操作会使游标增加
 * @param v
 */
void MoistureMeterLDS_1G::DataFrame::append(char v)
{
    this->datas.push_back(v);
}

std::size_t MoistureMeterLDS_1G::DataFrame::size() const
{
    return this->datas.size();
}

char &MoistureMeterLDS_1G::DataFrame::operator [](std::size_t index)
{
    return this->datas[index];
}

const char &MoistureMeterLDS_1G::DataFrame::operator [](std::size_t index) const
{
    return this->datas[index];
}

void MoistureMeterLDS_1G::DataFrame::clear()
{
    this->datas.clear();
}

MoistureMeterLDS_1G::MoistureMeterLDS_1G(QObject *par):SAAbstractMoistureMeter(par)
{
    connect(&m_serialPort,&QSerialPort::readyRead,this,&MoistureMeterLDS_1G::onReadyRead);
    m_buffer.resize(256,0);//默认初始化256
    m_index = 0;
    m_dataLen = 0;
    m_isreadedHead = false;
}

MoistureMeterLDS_1G::~MoistureMeterLDS_1G()
{

}

bool MoistureMeterLDS_1G::openSeriesPort(const QString &portName
                                          , QSerialPort::BaudRate baudRate
                                          , QSerialPort::Parity parity
                                          , QSerialPort::DataBits dataBits
                                          , QSerialPort::StopBits stopBits
                                          , QSerialPort::FlowControl flowControl)
{
    if(m_serialPort.isOpen())
    {
        m_serialPort.close();
    }
    return SAAbstractMoistureMeter::setupSeriesPort(&m_serialPort,portName,baudRate,parity,dataBits,stopBits,flowControl);
}

void MoistureMeterLDS_1G::close()
{
    m_serialPort.close();
}

QString MoistureMeterLDS_1G::getLastErrString() const
{
    return m_serialPort.errorString();
}


void MoistureMeterLDS_1G::onReadyRead()
{
    QByteArray d = m_serialPort.readAll();
    //目前一帧有10字节
    const int data_frame_len = 10;
    char* dp = d.data();
    std::size_t  bufferSize = (std::size_t)d.size();
    int index = 0;

    //说明上个数据有数据在dataframe里，还未存完，继续往此frame里写
    while( index < bufferSize )
    {
        m_tmpDatafrm.append(dp[index]);
        ++index;
        if(m_tmpDatafrm.size() == data_frame_len)
        {
            deal(m_tmpDatafrm);
            m_tmpDatafrm.clear();
        }
    }
}

/**
 * @brief 处理单独一帧数据
 * @param df
 */
void MoistureMeterLDS_1G::deal(const MoistureMeterLDS_1G::DataFrame &df)
{

}


