//Security System Code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socket_api.h"
#include "BBBiolib.h"


#define PIR_in 12


int main(){
    iolib_init();
    
    //will add timer so the alarm is not triggered as the user is leaving the room
    //the system can detect movement during start up, but it is not necessarily armed
    
    
    iolib_setdir(9, PIR_in , BBBIO_DIR_IN);
    
    while(1){
        if(is_high(9, PIR_in)){
            printf("Motion detected\r\n");
        }
        else{
            printf("NO MOTION DETECTED\r\n");
        }
        
        usleep(50*1000);
    }
    
    
    
    
    return 0;
}
