float getRatio(float angle, char ratio);
float getJoystickAngle(int x, int y, float rate);
float getJoystickSpeed(int y, bool turbo);
bool setMotor(float angle, float speed, bool left , bool right);


bool setMotor(float angle, float speed, bool left , bool right)
{
	displayTextLine(4,"Versie 0.0.0.2");
	if ((left) && (!right))
	{
		motor[motorA] = getRatio(angle, 'A') * speed;
		motor[motorB] = speed;
		motor[motorC] = speed;
		motor[motorD] = getRatio(angle, 'D') * speed;

		if (getRatio(angle, 'A') > 0){
			motor[motorA] = -1 * getRatio(angle, 'A') * speed ;
		} else {
			motor[motorA] = getRatio(angle, 'A') * speed ;
		}

		motor[motorB] = speed;
		motor[motorC] = speed;

		if (getRatio(angle, 'D') > 0){
			motor[motorD] = -1 * getRatio(angle, 'D') * speed ;
		} else {
			motor[motorD] = getRatio(angle, 'D') * speed ;
		}

	}
	else if ((right) && (!left))
	{
		motor[motorA] = speed;
		if (getRatio(angle, 'B') > 0){
			motor[motorB] = -1 * getRatio(angle, 'B') * speed ;
		} else {
			motor[motorB] = getRatio(angle, 'B') * speed ;
		}
		if (getRatio(angle, 'C') > 0){
			motor[motorB] = -1 * getRatio(angle, 'C') * speed ;
		} else {
			motor[motorB] = getRatio(angle, 'C') * speed ;
		}
		motor[motorD] = speed;
	}
	/*
	if ((left) && (!right))
	{
		motor[motorA] = -1 * speed;
		motor[motorB] = speed;
		motor[motorC] = speed;
		motor[motorD] =  -1 * speed;
	}
	else if ((right) && (!left))
	{
		motor[motorA] = speed;
		motor[motorB] = -1 * speed;
		motor[motorC] = -1 * speed;
		motor[motorD] = speed;
	}
	 */
	else
	{
		motor[motorA] = getRatio(angle, 'A') * speed;
		motor[motorB] = getRatio(angle, 'B') * speed;
		motor[motorC] = getRatio(angle, 'C') * speed;
		motor[motorD] = getRatio(angle, 'D') * speed;
	}
	return true;
}

float getJoystickAngle(int x, int y, float rate)
{
	float angle = atan2(-x, y);
	displayTextLine(2,"%d",rate);
	if (rate < 0)
	{
		rate = rate + 360;
	}
	angle = (angle/PI) * 180;
	if (angle < 0)
	{
		angle = angle + 360;
	}
	angle = angle + rate;
	if (angle > 360)
	{
		angle = angle - 360;
	}
	return angle;
}


float getJoystickSpeed(int y, bool turbo)
{

	float	speed = (float) (y /127.0);//100;
	if(turbo)
	{
		speed = speed * 75;
	}
	else
	{
		speed = speed * 35;
	}
	if (speed < 0)
	{
		speed = 0;
	}
	return speed;
}

float getRatio(float angle, char ratio)
{
	float ratioAC = 0;
	float ratioBD = 0;

	if(angle <= 45)
	{
		ratioAC = 1;
		ratioBD = (45 - angle)/45;
	}
	else if ((angle > 45) && (angle <= 90))
	{
		ratioAC = 1;
		ratioBD = (float) ((angle - 45)/45) * -1;
	}
	else if ((angle > 90) && (angle <= 135))
	{
		ratioAC = (float)(135 - angle)/45;
		ratioBD = -1;
	}
	else if ((angle > 135) && (angle <= 180))
	{
		ratioAC = (float) ((angle - 135) / 45) * -1;
		ratioBD = -1;
	}
	else if ((angle > 180) && (angle <= 225))
	{
		ratioAC = -1;
		ratioBD = (float) ((225 - angle)/45) * -1;
	}
	else if ((angle > 225) && (angle <= 270))
	{
		ratioAC = -1;
		ratioBD = (float) ((angle - 225)/45);
	}
	else if ((angle > 270) && (angle <= 315))
	{
		ratioAC = (float) ((315 - angle)/45) * -1;
		ratioBD = 1;
	}
	else if ((angle > 315) && (angle <= 360))
	{
		ratioAC = (float) (angle - 315)/45;
		ratioBD = 1;
	}

	if ((ratio == 'A') || (ratio == 'C'))
	{
		return ratioAC;
	}
	else if ((ratio == 'B') || (ratio == 'D'))
	{
		return ratioBD;
	}
	else
	{
		return 0;
	}
}
