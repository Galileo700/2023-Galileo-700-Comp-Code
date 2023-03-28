//FL is follow line 
//DUB is drive until bumped 
//R is specific to roomba
//BB is both bump 
//RB is right bump
//LB is left bump

//global variables
int threshold = 0;

void startingcompcode(portnum){
    create_connect();
    wait_for_light(portnum);
    shut_down_in(118);
    create_full();
}
void startingcode(){
    create_connect();
    create_full();
}

void calcthres(){
    threshold = 0;
    printf("Give me a black. \n");

    while(!any_button()){

    }
    while(any_button()){
        threshold = get_create_lfcliff_amt();   
    }

    printf("Black value: %d \n", threshold); 

    printf("Give me a white. \n");

    while(!any_button()){

    }
    threshold = threshold - (threshold - get_create_lfcliff_amt())/2;   


    printf("Calculated threshold: %d \n", threshold);
    msleep(2000);
}


//follow the line followed by drive until bumped w roomba bump sensor
void FLDUBR()
{
    calcthres();
    int speed = 250;
    while ( (get_create_lbump() == 0) && (get_create_rbump() == 0) )
        {
            if (get_create_lfcliff_amt() < threshold)
        { 
            create_drive_direct(0.5*speed, speed); 
        }
        else
        {
            create_drive_direct(speed, 0.5*speed);
        }
        }
        ao();	
}

void DUBRBR(){
    while (get_create_rbump() == 0)
    {
        create_drive_direct(100,100);
    }
   	create_stop();
}

void DUBLBR(){ 
    while (get_create_lbump() == 0)
    {
        create_drive_direct(100,100);
    }
   	create_stop();
}
    
void DUBBBR(){  
    while ((get_create_rbump() == 0) && (get_create_lbump() == 0))
    {
        create_drive_direct(100,100);
    }
   	create_stop();
}
void turning(int angle){
    set_create_total_angle(0);
    while (get_create_total_angle() < (angle)){
        create_drive_direct(100, 0);
    	msleep(500);
	}
}
