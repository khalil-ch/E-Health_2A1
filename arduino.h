#ifndef ARDUINO_H
#define ARDUINO_H
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

class arduino
{
    QSerialPort *serial=new QSerialPort(); //donner ou recevoir des donnes de la carte arduino
    static const quint16 arduino_uno_vendor_id=9025;
    static const quint16 arduino_uno_product_id=67;
    QString arduino_port_name;
    bool arduino_is_available;
    QByteArray data;    // donnees sur 8 bits

public:
    arduino();
    int connect_arduino();
    int close_arduino();
    int write_to_arduino(QByteArray);
    QByteArray read_from_arduino();
    QSerialPort *getserial(){return serial;}
    QString getarduino_port_name(){return arduino_port_name;}

};

#endif // ARDUINO_H
