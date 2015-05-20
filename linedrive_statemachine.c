
#define NORM = 2;
#define ROTCW = 1;
#define ROTCCW = 4;

/* Sensor layout:
* S1 most lef
* S2 mid left;
* S3 mid right;
* S4 most right;
*/

/**
 * Error when both Sensors (S1 and S3 or S2 and S4) detect threshold (then state machine constantly switches...)
 */

int getState(state) {
	switch(state) {
		case NORM: {
			// If left sensor hits, goto state to turn C. Clockwise
			if (S1 > threshold) {
				return ROTCCW;
			}
			// If right sensor hits, goto state to turn Clockwise
			if (S4 > threshol) {
				return ROTCW;
			}
		} break;
		case ROTCW: {
			// If the sensor hits, turned enough
			if (S2 > threshold) {
				return NORM;
			}
			return ROTCW;
		} break;
		case ROTCCW: {
			// If the sensor hits, turned enough
			if (S3 > threshold) {
				return NORM;
			}
			return ROTCCW
		}
		
	}
}


void output(state) {
	switch(state) {
		case NORM: {
			driveForward();
		} break;
		case ROTCW: {
			rotateCW();
		} break;
		case ROTCCW: {
			rotateCCW();
		} break;
	}
}


int main() {
	
	// Initial state
	int state = NORM;
	
	// Main Loop
	while(true) {
		// Poll sensors
		readSensors();
		// Update state
		state = getState(state);
		// Drive
		output(state);
		// Mandatory waiting...
		waitMSec();
	}
	
	return 0;
}