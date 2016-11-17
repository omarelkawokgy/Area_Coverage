/*
 * Bluetooth.h
 *
 *  Created on: Nov 1, 2016
 *      Author: Omar Elkawokgy
 */

#ifndef MAIN_SRC_BLUETOOTH_H_
#define MAIN_SRC_BLUETOOTH_H_
#ifdef USE_BLUETOOTH
#include "types.h"
#include "CONF.h"
#include <SoftwareSerial.h>

class Bluetooth
{
private:
	Bluetooth();

public:
	virtual ~Bluetooth();
	static Bluetooth& getInstance();
	void setupBlueToothConnection();
	bool isDataAvailableFromBluetooth();
	char readDataFromBluetooth();
	void writeDataToBluetooth(char character);

};

#endif /* MAIN_SRC_BLUETOOTH_H_ */
#endif
