// Copyright 2008-2016 Jaroslaw Surowiec

#include <Arduino.h>
#include "ArduinoPlatform.h"
#include "MotionSensor.h"

// FMotionSensor& FMotionSensor::Get()
// {
// 	static FMotionSensor Instance;
// 	return FMotionSensor;
// }


void FMotionSensor::SetupSensor()
{
	CurrentMotionState = 0;
	CurrentMotionBlockTime = 0;
	bWasMotionDetected = false;

	pinMode( EMotionSensor::SensorPin, INPUT );
	Serial.println( "Calibrating..." );
	delay( EMotionSensor::CalibrationTimeMS );
	Serial.println( "Done, probing..." );

//	pinMode( LED_PWM_PIN, OUTPUT );
}

void FMotionSensor::LoopSensor( const int32 Frametime )
{
	CurrentMotionBlockTime -= Frametime;
	const bool bCanPollMotionSensor = CurrentMotionBlockTime <= 0;

	if( bCanPollMotionSensor )
	{
		CurrentMotionBlockTime = 0;
		const bool bIsMotionSensed = digitalRead( EMotionSensor::SensorPin ) == HIGH;

		if( bIsMotionSensed )
		{
			bWasMotionDetected = true;
			CurrentMotionState++;
			CurrentMotionBlockTime = EMotionSensor::BLockTimeHighMS;
		}
		else
		{
			if( bWasMotionDetected )
			{
				bWasMotionDetected = false;

			}
			CurrentMotionState--;
			CurrentMotionBlockTime = EMotionSensor::BlockTimeLowMS;
		}
	}

	CurrentMotionState = constrain( CurrentMotionState, 0, EMotionSensor::MaxMotionState );

// 	DisplayTimer -= Frametime;
// 
// 	if( DisplayTimer < 0 )
// 	{
// 		DisplayTimer = DISPLAY_TIMER_REFRESH;
// 
// 		Serial.print( bWasMotionDetected );
// 		Serial.print( "\t" );
// 		Serial.print( CurrentMotionState );
// 		//Serial.print( "\t" );
// 		//Serial.print( CurrentMotionBlockTime );
// 		Serial.println( "" );
// 	}
// 
// 	analogWrite( LED_PWM_PIN, 12 * CurrentMotionState );
}
