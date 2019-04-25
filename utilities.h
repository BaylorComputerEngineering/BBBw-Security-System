//UTILITIES


typedef enum{
	ARMED = 0,
	DISARMED = 1
}alarmStates;

typedef enum{
	INERT = 0,
	TRIGD = 1
	}triggeredStates;

alarmStates armDevice(alarmStates alarmState){
    
    system("python PasswordQ.py");
    
    while(alarmState == DISARMED){
    	system("python ArmDisarm.py");
    	usleep(1000);
		char ArmDisarm[3];//init
		const char filename[] = "ArmDisarm.txt";
		FILE *fp;//create file pointer then reading from it to val
		fp = fopen(filename, "r" );
	    
		fscanf(fp,"%c",&ArmDisarm);//reading from the file to get the ADC val	
		
		if(strcmp(ArmDisarm, "ARM")){
			alarmState = ARMED;	
			usleep(5*1000*1000);//wait 20 (right now it's 5) seconds after the system is armed
			return alarmState;
			printf("YES DADDY WE ARMED \r\n");
		}
    }
}


alarmStates disarmDevice(triggeredStates trigState){
	
	int i = 0;
	int disable = 0;

	if(trigState == INERT){
				system("python password.py");
		    	
				//usleep(1*1000000);//delay to allow the user to enter the password
		    	char password[4];//init
				const char filename[] = "password.txt";
				FILE *fp;//create file pointer then reading from it to val
				fp = fopen(filename, "r" );
				    
		    	fscanf(fp,"%c",&password);//reading from the file to get the ADC val
		    	
		    	
		    	disable = !strcmp(password, "1234");//will need a preset internal password
			
		}  
	
	
	
	
	if(trigState == TRIGD){
		while((i < 3) && (disable == 0)){	    	
		    	system("./passwordset.sh");
		    	
				usleep(10*1000000);//delay to allow the user to enter the password
		    	char password[4];//init
				const char filename[] = "password.txt";
				FILE *fp;//create file pointer then reading from it to val
				fp = fopen(filename, "r" );
			    
				
				    
		    	fscanf(fp,"%c",&password);//reading from the file to get the ADC val
		    
		    
		    	disable = !strcmp(password, "1234");//will need a preset internal password
				i++;
			
		}  
	}
	
	 if (disable == 1){
	 	return DISARMED;
	 }
	 
	 if (disable == 0){
	 	return ARMED;
	 }
	     
}