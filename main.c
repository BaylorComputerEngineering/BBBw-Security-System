//Security System Code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilities.h"
#include "socket_api.h"
#include "BBBiolib.h"


#define PIR_in 12



int main(){
    iolib_init();
    
    //need wifi init for BBBw
    
    
    
    //will add timer so the alarm is not triggered as the user is leaving the room
    //the system can detect movement during start up, but it is not necessarily armed
		
	
	//alarm is disabled as of now
	alarmStates alarmState = DISARMED;//the system is disarmed
	
	
	triggeredStates triggeredState = INERT;//PIR detector is not triggered
	

    
	int i=0;
	
    while(1){
		
		if (alarmState == DISARMED){
			//function to wait for text input to arm the system
			//this will execute the first time the while loop is entered
			//the function waiting for the text will have its own waiting for a text functionality
			
			//once the text is received to arm system, then the system will become armed
			//if text is 'arm' or some password, then the state will go to ARMED
			armDevice(alarmState);
			alarmState = ARMED;
			//setting up PIR motion sensor input
    		iolib_setdir(9, PIR_in , BBBIO_DIR_IN);//HIGH is motion detected. LOW is no motion detected (do nothing)
			
			
			//we might also have an audio file saying "system armed"
			printf("SECURITY SYSTEM ARMED\r\n");
		}
		
		
		
		if (alarmState = ARMED){
			if(is_high(9, PIR_in)){
				printf("Motion detected\r\n");
				
				if (i==0){
					i=1;
					system("aplay roxanne.wav &");//play alarm audio
					triggeredState = TRIGD;//alarm has been triggered
				}
				
			}
			else{
				printf("NO MOTION DETECTED\r\n");
			}
		}
		
		//armed system and motion has been detected
		if((triggeredState == TRIGD) && (alarmState == ARMED)){
			alarmStates newState = disarmDevice(triggeredState);
			alarmState = newstate;//might be the same state as before
			
			//function to receive text to disable alarm system
			//send a text saying that the alarm system has been triggered
			//logic for whether or not the text is the correct text to disable alarm system?
			
			
		}
		
		if ((triggeredState == INERT) && (alarmState == ARMED)){
			//no audio plays since no motion is detected, possibly make sure audio is off or turn it off
			//function to receive text to disable alarm system if user wants
			
		}
		
        usleep(25*1000);
    }
    

    return 0;
}