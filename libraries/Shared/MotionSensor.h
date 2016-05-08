// Copyright 2008-2016 Jaroslaw Surowiec
// 

enum  EMotionSensor : int16
{
	SensorPin = 2,

	/** Time when the motion sensor is disabled after previously detected motion. */
	BlockTimeLowMS = 3000,
	BLockTimeHighMS = 1000,

	/** How often poll for the motion. */
	//MOTION_POLLING_TIME_MS = 100,

	/**
		Each HIGH state will add 1 to this, LOW state will subtract 1 from this.
		Value greater than 1 means that withing the last minute there was a movement.
	*/
	MaxMotionState = 20,

	/** Calibration time. */
	CalibrationTimeMS = 5000,
};

/** Motion sensor for . */
struct FMotionSensor
{
	/** Singleton. */
// 	FMotionSensor& Get()
// 	{
// 		static FMotionSensor Instance;
// 		return Instance;
// 	}

	/** Default constructor, Setup. */
	void SetupSensor();

	/** Loop. */
	void LoopSensor( const int32 Frametime );

	
	int8 CurrentMotionState;
	int16 CurrentMotionBlockTime;
	bool bWasMotionDetected;
};