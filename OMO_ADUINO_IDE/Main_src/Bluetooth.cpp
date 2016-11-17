/*
 * Bluetooth.cpp
 *
 *  Created on: Nov 1, 2016
 *      Author: Omar Elkawokgy
 */
#include "Project_Path.h"
#include RELATIVE_PATH(Bluetooth.h)
#ifdef USE_BLUETOOTH
SoftwareSerial bluetoothSerial(BLUETOOTH_RECIEVER_PIN, BLUETOOTH_TRANSMITTER_PIN, false);

Bluetooth::Bluetooth()
{

}

Bluetooth::~Bluetooth()
{

}

Bluetooth& Bluetooth::getInstance()
{
	static Bluetooth bluetoothModule;
	return bluetoothModule;
}

void Bluetooth::setupBlueToothConnection()
{
	bluetoothSerial.begin(38400); //Set BluetoothBee BaudRateto default baud rate 38400
	bluetoothSerial.print("\r\n+STWMOD=0\r\n"); //set thebluetooth work in slave mode
	bluetoothSerial.print("\r\n+STNA=SeeedBTSlave\r\n"); //set the bluetooth name as "SeeedBTSlave"Future Electronics Egypt Ltd. (Arduino Egypt).
	bluetoothSerial.print("\r\n+STPIN=0000\r\n");//Set SLAVEpincode"0000"
	bluetoothSerial.print("\r\n+STOAUT=1\r\n"); // PermitPaired device to connect me
	bluetoothSerial.print("\r\n+STAUTO=0\r\n"); // Autoconnectionshould be forbidden here
	delay(BLUETOOTH_SETUP_CONNECTION_DELAY_TIME); // This delay is required.
	bluetoothSerial.print("\r\n+INQ=1\r\n"); //make the slavebluetooth inquirable
	Serial.println("The slave bluetooth is inquirable!");
	delay(BLUETOOTH_SETUP_CONNECTION_DELAY_TIME); // This delay is required.
	bluetoothSerial.flush();
}

bool Bluetooth::isDataAvailableFromBluetooth()
{
	return bluetoothSerial.available();
}

char Bluetooth::readDataFromBluetooth()
{
	return bluetoothSerial.read();
}

void Bluetooth::writeDataToBluetooth(char character)
{
	bluetoothSerial.print(character);
}
#endif
