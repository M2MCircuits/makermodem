//COMMANDS:
//http://planner.ardupilot.com/wiki/common-mavlink-mission-command-messages-mav_cmd/#commands_supported_by_copter

//SOURCE CODE FOR ARDUPILOT/APM:
//https://github.com/diydrones

//IDEAL USAGE:
//Step 1) "route1" text is read which will call
//Step 2) route1.c which will get to the MAV> prompt and
//Step 3) issue command "mode auto" from which
//Step 4) we can issue each of the commands below in route_one

//fly in a square at altitude 3 feet in the north side of the east parking lot of SPN
//coordinates can be confirmed on google maps
#include <stdio.h>
int main(int argc, char **argv){
	
	printf("\nStart Route 1 Logic\n");

	/*
	float route_one[][6] = {
		{MAV_CMD_MISSION_START,  	0, 		0,  	0,  	0,	0, 		  	0},//start in AUTO mode without need to touch the throttle on the controller
		//	CMD					P1		P2		P3		Alt		Lat			Long
		{MAV_CMD_NAV_TAKEOFF,  	0, 		0,  	0,  	3.0,	0, 		  	0},					//  go up three feet
		
		{MAV_CMD_NAV_WAYPOINT, 	0, 		0,		0,  	3.0, 	32.994596, -96.751628},			//  south-west corner
		{MAV_CMD_NAV_WAYPOINT, 	0, 		0,		0,  	3.0, 	32.994596, -96.751528},			//  south-east corner
		{MAV_CMD_NAV_WAYPOINT, 	0, 		0,		0,  	3.0, 	32.994696, -96.751528},			//  north-east corner
		{MAV_CMD_NAV_WAYPOINT, 	0, 		0,		0,  	3.0, 	32.994696, -96.751628},			//  north-west corner
	
		{MAV_CMD_NAV_LAND, 	 	0,		0,		0,  	0,		0,          0}				//  go back down three feet
	};
	*/
	
	//STEP 2
	//system("sudo su"); //change to super user to have permissions for next line
	system("echo BB-UART1 > /sys/devices/bone_capemgr.9/slots"); //UART communication
	system("sudo mavproxy.py --master=/dev/ttyO1"); //start mavproxy
	
	//STEP 3 - at this point you should have a MAV> prompt
	system("mode auto"); //get AUTO> prompt
	
	//STEP 4: issue route_one commands (need to confirm syntax)
	printf("\nEnd Route 1 Logic\n");
}
