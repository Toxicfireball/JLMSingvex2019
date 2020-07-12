
// To complete the VEXcode V5 Text project upgrade process, please follow the
// steps below.
// 
// 1. You can use the Robot Configuration window to recreate your V5 devices
//   - including any motors, sensors, 3-wire devices, and controllers.
// 
// 2. All previous code located in main.cpp has now been commented out. You
//   will need to migrate this code to the new "int main" structure created
//   below and keep in mind any new device names you may have set from the
//   Robot Configuration window. 
// 
// If you would like to go back to your original project, a complete backup
// of your original (pre-upgraded) project was created in a backup folder
// inside of this project's folder.

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
}

// /----------------------------------------------------------------------------/
// /*                                                                            */
// /*    Module:       main.cpp                                                  */
// /*    Author:       XuZhicom                                         */
// /*    Created:      Thu Jun 06 2019                                           */
// /*    Description:  V5 project                                                */
// /*                                                                            */
// /----------------------------------------------------------------------------/
// #include "vex.h"
// 
// // ---- START VEXCODE CONFIGURED DEVICES ----
// // Robot Configuration:
// // [Name]               [Type]        [Port(s)]
// // ---- END VEXCODE CONFIGURED DEVICES ----
// 
// using namespace vex;
// 
// // A global instance of vex::brain used for printing to the V5 brain screen

//decleration of robot parts, do not delete!
 vex::brain       Brain;
 vex::motor leftfront = vex::motor(vex::PORT1, vex::gearSetting::ratio18_1, false);
 vex::motor leftback = vex::motor(vex::PORT3,vex::gearSetting::ratio18_1,true);
  vex::motor rightfront = vex::motor(vex::PORT8, vex::gearSetting::ratio18_1, true);
 vex::motor rightback= vex::motor (vex::PORT6,vex::gearSetting::ratio18_1,false);
vex::motor RightIntakeclaw=vex::motor(vex::PORT5, vex::gearSetting::ratio18_1, false); 
 vex::motor LeftIntakeclaw=vex::motor(vex::PORT4,vex::gearSetting::ratio18_1,true);
 vex::motor LeftArm=vex::motor(vex::PORT2,vex::gearSetting::ratio36_1,true);
 vex::motor RightArm=vex::motor(vex::PORT7,vex::gearSetting::ratio36_1,false);
 vex::gyro Gyro = vex::gyro(Brain.ThreeWirePort.A);
vex::encoder Encoder1 = vex::encoder(Brain.ThreeWirePort.A);
 vex::encoder Encoder2 = vex::encoder(Brain.ThreeWirePort.C);
 vex::bumper Bumper = vex::bumper(Brain.ThreeWirePort.A);
 vex::pot Apotentilmeter = vex::pot(Brain.ThreeWirePort.D);
 vex::pot Spotentilmeter = vex::pot(Brain.ThreeWirePort.E);
vex::pot Cpotentilmeter = vex::pot(Brain.ThreeWirePort.E);
 vex::controller HController = vex::controller();
 vex::controller VController = vex::controller(vex::controllerType::partner);
 // A global instance of vex::competition
 vex::competition Competition;

// 
// 
// 
// 
// 
//    //setverlocity= set motor 
// //...........EZ value converters........//
// 
 float inchtoticks (float inch)
 {
	float ticks;
 	ticks=inch*26.61919474859647;
 	return ticks;
 }
 float cmToTicks(float distance)
 {
   	float cm;
 	//1 round=360 ticks
 	//wheel circumference= 10.16cm*pi=31.09=360 ticks
 
	cm=distance*10.4775;
 	return cm;
}
 float degreetodistance (float distance)//not very useful
 {
    
 	float degree;
 	//1 degree=10 gyro value
 	degree=distance*6;


	return degree;
 }
 int fixtimervalue(float rawseconds)
 {
 	float millisec;
 	millisec=rawseconds*100;
 	if(millisec<250)
 	{
		millisec=250;
 	}
 	return millisec;
 }
 
// //............................User Functions.............................//
 void movearm(int speed)
 {
     LeftArm.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
    RightArm.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
 }

 void intakeclaw(int time,int speed)
 {
     LeftIntakeclaw.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
     vex::task::sleep(time);    
 }
 void movebase(int speed)
 {
    
   leftfront.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);  
   rightfront.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct); 
   leftback.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
   rightback.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct); 
 }
 void turnbaseright(int speed)
 {
   leftfront.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);  
   rightfront.spin(vex::directionType::fwd,-speed,vex::velocityUnits::pct); 
    leftback.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);  
    rightback.spin(vex::directionType::fwd,-speed,vex::velocityUnits::pct); 
 }
 void turnbaseleft(int speed )
 {
  leftfront.spin(vex::directionType::fwd,-speed,vex::velocityUnits::pct);  
   rightfront.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct); 
    leftback.spin(vex::directionType::fwd,-speed,vex::velocityUnits::pct);  
   rightback.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);     
 }
 void movebaserev(int speed)
{
  
  leftfront.spin(vex::directionType::fwd,-speed,vex::velocityUnits::pct);  
   rightfront.spin(vex::directionType::fwd,-speed,vex::velocityUnits::pct); 
   leftback.spin(vex::directionType::fwd,-speed,vex::velocityUnits::pct);  
   rightback.spin(vex::directionType::fwd,-speed,vex::velocityUnits::pct);   
 }   
//Note: PID is under development for V5, do not use! No valid timer found. Work in progress
 void Pidbasecontrol(int target, float waittime, float maxpw, int speedlimit)
 {
 	Encoder1.resetRotation();
 	//
 	float Kp=0.2;
 	float Ki=0.02;
 	float Kd=0.5;
 	//
 
 	int error;
	float proportion;
 	int integralraw;
 	float integral;
	float lasterror;
	float derivative;
	float integralactive=inchtoticks(3);//distance//
 	float integrallimit= speedlimit; //(this is speed limit)
 
     
     Brain.resetTimer();
	float finalpower;
	bool timerbool=true;
   	vex::timer::system();
 int time;
  time=fixtimervalue(waittime);
    
 	while(vex::timer()<fixtimervalue(waittime))
 	{
		//error=target- current value
		error= inchtoticks(target)-Encoder1.rotation(vex::rotationUnits::deg);
 
 		proportion=Kp*error;
 		if (abs(error)< integralactive && error!=0)
 		{
		if(integralraw> integrallimit)
 		{
			integralraw=integrallimit;
 		}
 		if (integralraw<- integrallimit)
 		{
 			integralraw=-integrallimit;
			integralraw=integralraw+error;
		}
 		else
 		{
			integralraw=0;
		}
 		}
 
 		integral= Ki*integralraw; //if integralraw too big and we want to set the intlimit to the intraw do: Ki*(value/Ki)
 		//if there is an error eg 10 you add 10 to the integralraw then keep adding the errors with the loops

 		derivative= Kd*(error- lasterror);
 		lasterror=error;
 
 		if (error == 0)
 		{
 			derivative=0;
 		}
		finalpower= proportion+integral+derivative; //proportion+derivative+integral
 
		if (finalpower>maxpw*127)
		{
 			finalpower=maxpw*127;
 		}
 		else if(finalpower<-maxpw*127)
 		{
 			finalpower=-maxpw*127;
 		}
 
 		movebase(finalpower);
 		
 		if (error<30)
 		{
			timerbool=false;
		}
		if(timerbool)
 		{
             Brain.resetTimer();
 		}
 	}
 	movebase(0);
 }
 void Pidbasecontrolmk2(int target, float waittime, float maxpw, int speedlimit)
 {
 	Encoder1.resetRotation();
    Encoder2.resetRotation();
	//
        float Kp=0.2;
	float Ki=0.02;
 	float Kd=0.5;
 	//
 
 	int error;
 	float proportion;
 	int integralraw;
 	float integral;
 	float lasterror;
 	float derivative;
 	float integralactive=inchtoticks(3);//distance//
 	float integrallimit= speedlimit; //(this is speed limit)/ 
    
    Brain.resetTimer();
 	float finalpower;
 	bool timerbool=true;
 	
	  int time;
         time=fixtimervalue(waittime);
    
 	while(Brain.Timer.system()<fixtimervalue(waittime))
 	{
 		//error=target- current value
         int total=(Encoder1.rotation(vex::rotationUnits::deg)-Encoder2.rotation(vex::rotationUnits::deg))/2;
 		error= inchtoticks(target)-total;
 
 		proportion=Kp*error;
 		if (abs(error)< integralactive && error!=0)
 		{
 		if(integralraw> integrallimit)
 		{
 			integralraw=integrallimit;
 		}
 		if (integralraw<- integrallimit)
 		{
			integralraw=-integrallimit;
			integralraw=integralraw+error;
		}
 		else
 		{
 			integralraw=0;
		}
 		}
 
 		integral= Ki*integralraw; //if integralraw too big and we want to set the intlimit to the intraw do: Ki*(value/Ki)
 		//if there is an error eg 10 you add 10 to the integralraw then keep adding the errors with the loops
 
		derivative= Kd*(error- lasterror);
		lasterror=error;
 
 		if (error == 0)
 		{
 			derivative=0;
 		}
 		finalpower= proportion+integral+derivative; //proportion+derivative+integral
 
 		if (finalpower>maxpw*127)
 		{
 			finalpower=maxpw*127;
 		}
 		else if(finalpower<-maxpw*127)
 		{
 			finalpower=-maxpw*127;
 		}
 
 		movebase(finalpower);
 		
 		if (error<30)
 		{
 			timerbool=false;
 		}
 		if(timerbool)
 		{
             Brain.resetTimer();
 		}
 	}
 	movebase(0);
 }
 void Pidbasecontrolrev(int target, float waittime, float maxpw, int speedlimit)
 {
 	Encoder1.resetRotation();
 	//
 	float Kp=0.2;
 	float Ki=0.02;
 	float Kd=0.5;
 	//
 
 	int error;
 	float proportion;
 	int integralraw;
 	float integral;
 	float lasterror;
 	float derivative;
 	float integralactive=inchtoticks(3);//distance//
 	float integrallimit= speedlimit; //(this is speed limit)
 
     
     Brain.resetTimer();
 	float finalpower;
 	bool timerbool=true;
// 	
    // int time;
      //   time=fixtimervalue(waittime);
    
 	while(Brain.Timer.system()<fixtimervalue(waittime))
 	{
 		//error=target- current value
 		
          int total=(Encoder1.rotation(vex::rotationUnits::deg)+Encoder2.rotation(vex::rotationUnits::deg))/2;
 		error= inchtoticks(target)-total;
                proportion=Kp*error;
 		if (abs(error)< integralactive && error!=0)
 		{
 			integralraw=integralraw+error;
 		}
 		else
 		{
 			integralraw=0;
 		}
 		if(integralraw> integrallimit)
 		{
 			integralraw=integrallimit;
 		}
 		if (integralraw<- integrallimit)
 		{
 			integralraw=-integrallimit;
 		}
 
 		integral= Ki*integralraw; //if integralraw too big and we want to set the intlimit to the intraw do: Ki*(value/Ki)
 		//if there is an error eg 10 you add 10 to the integralraw then keep adding the errors with the loops
 
 		derivative= Kd*(error- lasterror);
 		lasterror=error;
 
 		if (error == 0)
 		{
 			derivative=0;
 		}
 		finalpower= proportion+integral+derivative; //proportion+derivative+integral
 
 		if (finalpower>maxpw*-127)
 		{
 			finalpower=maxpw*-127;
 		}
 		else if(finalpower<-maxpw*-127)
 		{
 			finalpower=-maxpw*-127;
 		}
 
 		movebase(finalpower);
 		
 		if (error<30)
 		{
 			timerbool=false;
 		}
 		if(timerbool)
               {
             Brain.resetTimer();
 		}
 	}
 	movebase(0);
 }
 void reset(int time,int speed)
 {
     movebase(-speed);
    vex::task::sleep(time);
     movebase(0);
     
 }
 void encoderfwd(int dist,int speed)
      {
     Encoder1.resetRotation();
     while(Encoder1.rotation(vex::rotationUnits::deg)<dist)
     {
        movebase(speed); 
     }
      movebase(speed/8);
     vex::task::sleep(5);
     movebase(0);
         
      }
 void advfwd(float dist,int speed,int slwspd )
 {
   Encoder1.resetRotation();
   Encoder2.resetRotation();
  	int error;
 	float target;
 	target= cmToTicks(dist);
     int Tvalue=Encoder1.rotation(vex::rotationUnits::deg)-Encoder2.rotation(vex::rotationUnits::deg);
     int value=Tvalue/2;
 	error= target+Encoder1.rotation(vex::rotationUnits::deg);
      while(error>target/6)
       {
           movebase(speed);
   	error= target+Encoder1.rotation(vex::rotationUnits::deg);
             
         }
     
     while(error<target/6.8&&error>0)
     {
         movebase(slwspd);
            	error= target-Encoder1.rotation(vex::rotationUnits::deg);
     }
     while(error<0)
     {
       movebase(0);
       vex::task::sleep(50);
         movebase(-slwspd);
         	error= target-Encoder1.rotation(vex::rotationUnits::deg);
     }
    
//    
     movebase(5);
     vex::task::sleep(10);
     movebase(0);
 }
 void advrev(int dist,int speed,int slwspd )
 {
  	int error;
 	float target;
 	target= cmToTicks(dist);
     Encoder1.resetRotation();
     Encoder2.resetRotation();
     int Tvalue=Encoder1.rotation(vex::rotationUnits::deg)+Encoder2.rotation(vex::rotationUnits::deg);
     int value=Tvalue/2;
 	error= target-Tvalue; 
    
      while(error>target/6)
       {
           movebase(-speed);
          int Tvalue=Encoder1.rotation(vex::rotationUnits::deg)+Encoder2.rotation(vex::rotationUnits::deg);
    
 	
             
         }
     
     while(error<target/6&&error>0)
     {
         movebase(-slwspd);
         int Tvalue=Encoder1.rotation(vex::rotationUnits::deg)+Encoder2.rotation(vex::rotationUnits::deg);
         int value=Tvalue/2;
 	    error= target-Tvalue;
     }
     while(error<0)
     {
         movebase(slwspd);
         int Tvalue=Encoder1.rotation(vex::rotationUnits::deg)+Encoder2.rotation(vex::rotationUnits::deg);
         int value=Tvalue/2;
 	     error= target-Tvalue;    
     }
     movebase(0);
 }
 void advrevWintake(int dist,int speed,int slwspd )
 {
  	int error;
 	float target;
 	target= cmToTicks(dist);
     Encoder1.resetRotation();
     Encoder2.resetRotation();
     int Tvalue=-Encoder1.rotation(vex::rotationUnits::deg)+Encoder2.rotation(vex::rotationUnits::deg);
     int value=Tvalue/2;
 	error= target-value; 
    
      while(error>target/6)
       {
           movebase(-speed);
           LeftIntakeclaw.spin(vex::directionType::rev,-100, vex::velocityUnits::pct);
           RightIntakeclaw.spin(vex::directionType::rev,-100, vex::velocityUnits::pct);
          int Tvalue=-Encoder1.rotation(vex::rotationUnits::deg)+Encoder2.rotation(vex::rotationUnits::deg);
    
 	int value=Tvalue/2;
 	error= target-value; 
             
         }
     
     while(error<target/6&&error>0)
     {
         movebase(-slwspd);
         int Tvalue=-Encoder1.rotation(vex::rotationUnits::deg)+Encoder2.rotation(vex::rotationUnits::deg);
                 
    
 	int value=Tvalue/2;
 	error= target-value; 
     }
     while(error<0)
     {
         movebase(slwspd);
         int Tvalue=-Encoder1.rotation(vex::rotationUnits::deg)+Encoder2.rotation(vex::rotationUnits::deg);
         int value=Tvalue/2;
 	     error= target-value;    
     }
     movebase(0);
 }
 void encoderturnleft(int left,int speed)
 {
     int Tvalue=Encoder1.rotation(vex::rotationUnits::deg)-Encoder2.rotation(vex::rotationUnits::deg);
     int Value=Tvalue/2;
     while(Value<left)
     {
         turnbaseleft(speed);
     }
     turnbaseleft(5);
     vex::task::sleep(7);
     turnbaseleft(0);
 }
 void encoderturnright(int right,int speed)
 {
     int Tvalue=Encoder1.rotation(vex::rotationUnits::deg)+Encoder2.rotation(vex::rotationUnits::deg);
     int Value=Tvalue/2;
     while(Value<right)
     {
         turnbaseleft(speed);
     }
     turnbaseleft(5);
     vex::task::sleep(7);
     turnbaseleft(0);
 }
 void encoderturnrightWintake(int right,int speed)
 {
     int value=Encoder1.rotation(vex::rotationUnits::deg);
     
     while(value>-right)
     {
         turnbaseleft(speed);
     }
     turnbaseleft(5);
     vex::task::sleep(7);
     turnbaseleft(0);
 }
 void gyroturn(int turn,int speed,int slwspd )
 {
     
    Gyro.startCalibration();
     Gyro.isCalibrating();
   
     while(Gyro.value(vex::rotationUnits::deg)>-turn)
     {
        turnbaseleft(speed); 
     }
         turnbaseleft(slwspd);
         vex::task::sleep(7);
         movebase(0);
 }
 
 void advTurnleft(int left,int rev,int speed)
 {
 	 Gyro.startCalibration();
     Gyro.isCalibrating();
 	int error;
     error=left+Gyro.value(vex::rotationUnits::deg);
 	
 
 	while (error>left/6)
 	{
 		turnbaseleft(speed);
 
 		 error= left+Gyro.value(vex::rotationUnits::deg);
 	}
 	while(error<left/6&&error>0)
 	{
 		turnbaseleft(rev);
 		 error= left+Gyro.value(vex::rotationUnits::deg);
 
 	}
 
 		while (error<0)
 		{
 	     turnbaseleft(-rev);
 		 error= left+Gyro.value(vex::rotationUnits::deg);
 		}
     if(error==0||Gyro.value(vex::rotationUnits::deg)==error)
 	{
 		movebase(0);
 	}
 }
 
 void advTurnleftMk2(int left,int rev,int speed)
 {
 	
 	int error;
     error=left+((Encoder1.rotation(vex::rotationUnits::deg)-Encoder2.rotation(vex::rotationUnits::deg))/2);
 	
 
 	while (error>left/6)
 	{
 		turnbaseleft(speed);
 
 		  error=left+((Encoder1.rotation(vex::rotationUnits::deg)-Encoder2.rotation(vex::rotationUnits::deg))/2);
 	
 	}
 	while(error<left/8&&error>0)
 	{
 		turnbaseleft(rev);
 		  error=left+((Encoder1.rotation(vex::rotationUnits::deg)-Encoder2.rotation(vex::rotationUnits::deg))/2);
 	
 
 	}
 
 		while (error<0)
 		{
 	     turnbaseleft(-rev);
 		 error=left+((Encoder1.rotation(vex::rotationUnits::deg)-Encoder2.rotation(vex::rotationUnits::deg))/2);// 	
 		}
     if(error==0||Gyro.value(vex::rotationUnits::deg)==error)
 	{
 		movebase(0);
 	}
 }
 void advTurnright(int right,int rev,int speed)
 {
 Encoder1.resetRotation();
 Encoder2.resetRotation();
 	int error;
 	
      error=right+((Encoder1.rotation(vex::rotationUnits::deg)+Encoder2.rotation(vex::rotationUnits::deg))/2);
 	
 	
 
 	while (error>right/6)
 	{
 		turnbaseright(speed);
 
    error=right+((Encoder1.rotation(vex::rotationUnits::deg)+Encoder2.rotation(vex::rotationUnits::deg))/2);
 	}
 	while(error<right/6&&error>0)
 	{
 		turnbaseright(rev);
 		   error=right-+(Encoder1.rotation(vex::rotationUnits::deg)+Encoder2.rotation(vex::rotationUnits::deg)/2);
 
 	}
 
 		while (error<0)
 		{
 	     turnbaseright(-rev);
    error=right+((Encoder1.rotation(vex::rotationUnits::deg)-Encoder2.rotation(vex::rotationUnits::deg))/2);
 		}
     if(error==0||Gyro.value(vex::rotationUnits::deg)==error)
 	{
 		movebase(0);
 	}
 }
 void advTurnrightWintake(int right,int rev,int speed)
 {
 Encoder1.resetRotation();
 Encoder2.resetRotation();
 	int error;
 	
      error=right+((Encoder1.rotation(vex::rotationUnits::deg)-Encoder2.rotation(vex::rotationUnits::deg))/2);
 	
 	
 
 	while (error>right/6)
 	{
 		turnbaseright(speed);
  LeftIntakeclaw.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
     RightIntakeclaw.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
    error=right+((Encoder1.rotation(vex::rotationUnits::deg)-Encoder2.rotation(vex::rotationUnits::deg))/2);
 	}
 	while(error<right/6&&error>0)
 	{
 		turnbaseright(rev);
 		   error=right-+(Encoder1.rotation(vex::rotationUnits::deg)-Encoder2.rotation(vex::rotationUnits::deg)/2);
 
 	}
 
 		while (error<0)
 		{
 	     turnbaseright(-rev);
    error=right+((Encoder1.rotation(vex::rotationUnits::deg)-Encoder2.rotation(vex::rotationUnits::deg))/2);
 		}
     if(error==0||Gyro.value(vex::rotationUnits::deg)==error)
 	{
 		movebase(0);
 	}
 }
 void timerturnrightWintake(float turn,int speed)
 {
   turnbaseright(speed);
    LeftIntakeclaw.spin(vex::directionType::fwd,- 100, vex::velocityUnits::pct);
    RightIntakeclaw.spin(vex::directionType::fwd,-100,vex::velocityUnits::pct);
    vex::task::sleep(turn);
    movebase(5);
    vex::task::sleep(50);
    movebase(0);
     LeftIntakeclaw.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct);
    RightIntakeclaw.spin(vex::directionType::fwd,0,vex::velocityUnits::pct);
 
 
 }
 void advencoderturnleftmk2(int turn,int slwspd,int speed)
  {
 	 int value1=Encoder1.rotation(vex::rotationUnits::deg);
 	 int value2=Encoder2.rotation(vex::rotationUnits::deg);
 	 int Tvalue=Encoder1.rotation(vex::rotationUnits::deg)+Encoder2.rotation(vex::rotationUnits::deg);
 	 int total=Tvalue/2;
 	 while(total>-turn)
 	 {
 		 turnbaseleft(speed);
 	
 	 int Tvalue=Encoder1.rotation(vex::rotationUnits::deg)+Encoder2.rotation(vex::rotationUnits::deg);
 		 total=Tvalue/2;
 	 }
 	 while(value1>value2)
 	 {
 		 leftfront.setVelocity(speed,vex::velocityUnits::pct);
 	 int value1=Encoder1.rotation(vex::rotationUnits::deg);
 	 int value2=Encoder2.rotation(vex::rotationUnits::deg);
 	 int Tvalue=Encoder1.rotation(vex::rotationUnits::deg)+Encoder2.rotation(vex::rotationUnits::deg);
 		 total=Tvalue/2;
 	 }
 	 while(value2>value1)
 	 {
     rightfront.setVelocity(speed,vex::velocityUnits::pct);;
 	 int value1=Encoder1.rotation(vex::rotationUnits::deg);
 	 int value2=Encoder2.rotation(vex::rotationUnits::deg);
 	 int Tvalue=Encoder1.rotation(vex::rotationUnits::deg)+Encoder2.rotation(vex::rotationUnits::deg);
 		total=Tvalue/2;
 
 	 }
 	 while(turn>-total)
 	 {
 		 turnbaseleft(-slwspd);
 	 }
 	 if(turn>total-5&&turn<total+5)
 	 {
 	 int value1=Encoder1.rotation(vex::rotationUnits::deg);
 	 int value2=Encoder2.rotation(vex::rotationUnits::deg);
 	 int Tvalue=Encoder1.rotation(vex::rotationUnits::deg)+Encoder2.rotation(vex::rotationUnits::deg);
 		 total=Tvalue/2;// 		
		 movebase(0);
 		 vex::task::sleep(100);
 	 }
  }
 
 void timerleft(int time,int spd)
 {
   turnbaseleft(spd);
   vex::task::sleep(time);
   turnbaseleft(spd/7);
   vex::task::sleep(8);
   movebase(0);
     
 }
 void stackMK1(int stacktime,int waittime,int armspd,int intakespd)
 {
         LeftIntakeclaw.spin(vex::directionType::fwd, -intakespd, vex::velocityUnits::pct);
         RightIntakeclaw.spin(vex::directionType::fwd,-intakespd,vex::velocityUnits::pct);
         LeftArm.spin(vex::directionType::fwd,armspd,vex::velocityUnits::pct);
         RightArm.spin(vex::directionType::fwd,armspd,vex::velocityUnits::pct);  
         vex::task::sleep(stacktime);
         LeftArm.spin(vex::directionType::rev,armspd,vex::velocityUnits::pct);
         RightArm.spin(vex::directionType::rev,armspd,vex::velocityUnits::pct);  
         vex::task::sleep(waittime);
         LeftArm.stop();
         RightArm.stop();
         LeftIntakeclaw.stop();
         RightIntakeclaw.stop();
 }
 void timeright(int time,int spd)
 {
   turnbaseright(spd);
   vex::task::sleep(time);
   turnbaseright(spd/7);
   vex::task::sleep(8);
   movebase(0);
 }
// 
 void rollerclaw(int time,int speed)
 {
     LeftIntakeclaw.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
     RightIntakeclaw.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
     vex::task::sleep(time);
     LeftIntakeclaw.stop();
     RightIntakeclaw.stop();
 }
 
 void armup(int up,int speed,int hold)
 {
     while(Apotentilmeter.value(vex::rotationUnits::deg)<up)
     {
         movearm(speed); 
     }
    movearm(hold);
     vex::task::sleep(7);
    movearm(0);
     
 }
 void Earmup(int dist,int speed)
 {
     LeftArm.resetRotation();
     RightArm.resetRotation();
     LeftArm.rotateFor(dist,vex::rotationUnits::rev,speed,vex::velocityUnits::pct);
     RightArm.rotateFor(dist,vex::rotationUnits::rev,speed,vex::velocityUnits::pct);
     LeftArm.stop();
     RightArm.stop();
 }
 
 void armdown(int armdown,int speed)
 {
    movearm(-speed);
     vex::task::sleep(armdown);
    movearm(0);
 }
 void scoreaim(int firstT,int secondT,int Rpw,int Lpw)
 {
   

    rightback.spin(vex::directionType::fwd,100,vex::percentUnits::pct);
   rightfront.spin(vex::directionType::fwd,100,vex::percentUnits::pct);
   vex::task::sleep(secondT);
   rightback.stop();
   rightfront.stop();
   leftback.spin(vex::directionType::fwd,100,vex::percentUnits::pct);
   leftfront.spin(vex::directionType::fwd,100,vex::percentUnits::pct);
   vex::task::sleep(firstT);
   leftback.stop();
   leftfront.stop();
   movebase(0);
   
 }
 void armupmk2(int time,int spd,int hold)
 {
     movearm(spd);
     vex::task::sleep(time);
     movearm(hold);
     vex::task::sleep(10);
     movearm(0);
 }
 void resetWintake(int time,int speed)
 {
   movebase(-speed);
   LeftIntakeclaw.spin(vex::directionType::rev,100, vex::velocityUnits::pct);
   RightIntakeclaw.spin(vex::directionType::rev,100, vex::velocityUnits::pct);
   vex::task::sleep(time);
   movebase(5);
   vex::task::sleep(20);
   movebase(0);
   LeftIntakeclaw.stop();
   RightIntakeclaw.stop();
 }
 void printTemp()
 {
     HController.Screen.print("Temp %f",(leftfront.temperature(vex::percentUnits::pct)+rightfront.temperature(vex::percentUnits::pct)+leftback.temperature(vex::percentUnits::pct)+rightback.temperature(vex::percentUnits::pct))/4);
     VController.Screen.print("Temp %f",(LeftIntakeclaw.temperature(vex::percentUnits::pct)+RightIntakeclaw.temperature(vex::percentUnits::pct))/2);
    
 }
 
 void ReducedsnesOP()
 {
    
     while(true)
     {
         float max = 127.0;
         float left_percent = HController.Axis3.value()/max;
         float right_percent = HController.Axis2.value()/max;
        
         float left_new_percent = left_percent * left_percent * left_percent;
         float right_new_percent = right_percent * right_percent * right_percent;
       
         float motor_max = 100;
         int left_power = left_new_percent * motor_max;
         int right_power = right_new_percent * motor_max;
        
         leftfront.spin(vex::directionType::fwd,left_power,vex::velocityUnits::pct);
         rightfront.spin(vex::directionType::fwd,right_power,vex::velocityUnits::pct);
  
     }
 }
 void ReducedsnesOPMk2()
 {
    
     while(true)
     {
         float max = 63.5;
         float left_percent = HController.Axis3.value()/max;
         float right_percent = HController.Axis2.value()/max;
        
         float left_new_percent = left_percent * left_percent * left_percent;
         float right_new_percent = right_percent * right_percent * right_percent;
        
         float motor_max = 100;
         int left_power = left_new_percent * motor_max;
         int right_power = right_new_percent * motor_max;
        
         leftfront.spin(vex::directionType::fwd,left_power,vex::velocityUnits::pct);
         rightfront.spin(vex::directionType::fwd,right_power,vex::velocityUnits::pct);
  
     }
 }
 void ETurntest()
 {
    int v= Encoder1.rotation(vex::rotationUnits::deg);
   // int TV=v/2;
     Brain.Screen.printAt(1,40,"Combined Value %f",v);
 }

// Enc not working,work in progress
//Switch not consisten, use manual download
 void Switch()
 {
     if(Spotentilmeter.value(vex::percentUnits::pct)<25&&Spotentilmeter.value(vex::percentUnits::pct)>0)
     {
         
     }
     else if(Spotentilmeter.value(vex::percentUnits::pct)<50&&Spotentilmeter.value(vex::percentUnits::pct)>25)
     {
         
     }
     else if(Spotentilmeter.value(vex::percentUnits::pct)<75&&Spotentilmeter.value(vex::percentUnits::pct)>50)
     {
         
     }
     else
     {
         
     }   
 }

//not doing prog skills(for once) heh (Junlong,Mencius and Mark doing)
 void programmingskilllMK1A1()
 {
     
 }
 void programmingskillMk1A2()
 {
     
 }
 void programmingskillMk2()
 {
     
 }
 void autonredmk1()
 {
  Encoder1.resetRotation();
  Encoder2.resetRotation();
  vex::task::sleep(1);
  reset(1,1);
  advfwd(1,  40, 5);
  reset(200, -60);
  //Earmup(100, 60);
  armupmk2(1200, 60, 10);
  reset(600, -40); 
  rollerclaw(800, 100);
  reset(800, 20);
  vex::task::sleep(180);
  armdown(990, 100);
 reset(200, 40);
 movebase(0);
 leftback.spin(vex::directionType::fwd,-50,vex::velocityUnits::pct);
 leftfront.spin(vex::directionType::fwd,-50,vex::velocityUnits::pct);
 vex::task::sleep(600);
 reset(600, 60);
 reset(180,-50);
 armupmk2(400, 38, 5);
 reset(400, -60);
 stackMK1(1000, 1000, -40, 100);
 reset(90, -50);
 timerleft(976, 25);
 reset(720,-45);
 stackMK1(900,100,-30,100);
 reset(120, 40);
 vex::task::sleep(30);
 timerleft(172, 50);
 reset(900,-60);
 scoreaim(300, 300, 30, 30);
 stackMK1(1800,0,34,-100);
 reset(700, 50);
 
 
           
 }
 void autonredmk2()
 {
       Encoder1.resetRotation();
   Encoder2.resetRotation();
   vex::task::sleep(100);
   reset(20,20);
   armupmk2(540, 60, 15);
 reset(810, -40);
  vex::task::sleep(100);
  stackMK1(1120, 700, -40, 100);
 reset(700, -30);
  vex::task::sleep(50);
  stackMK1(800,850,-40,100);
 reset(700,-30);
 vex::task::sleep(50);
  stackMK1(1150, 100, -55, 100);
  //advrevWintake(10, 80,10);
  resetWintake(1120, 100);
  vex::task::sleep(500);
  reset(500, -50);
  vex::task::sleep(200);
  //advTurnrightWintake(750, 10, 50);
  //encoderturnrightWintake(400, 50);
 timerturnrightWintake(1100, 35);
 vex::task::sleep(10);
 reset(800, -60);
 vex::task::sleep(100);
 scoreaim(400, 500, 20, 20);
 vex::task::sleep(200);
 stackMK1(2100,0,40,-100);
 reset(960,20);
 }
 void autonbluemk1()
 {
    Encoder1.resetRotation();
  Encoder2.resetRotation();
  vex::task::sleep(1);
  reset(1,1);
  //advfwd(1,  40, 5);
  reset(200, -60);
  //Earmup(100, 60);
  armupmk2(1100, 60, 10);
  encoderfwd(225, 30); 
  rollerclaw(800, -100);
  reset(930, 20);
  vex::task::sleep(180);
  armdown(990, 100);
 reset(190, 65);
 movebase(0);
 rightback.spin(vex::directionType::fwd,50,vex::velocityUnits::pct);
 rightfront.spin(vex::directionType::fwd,50,vex::velocityUnits::pct);
 vex::task::sleep(800);
 reset(750, 60);
 encoderfwd(50, 50);
 armupmk2(420, 39, 5);
 vex::task::sleep(50);
 encoderfwd(66, 40);
 vex::task::sleep(30);
 stackMK1(1400, 600, -40, -100);
 encoderfwd(70, 30);
 movebase(0);
 vex::task::sleep(100);
 timeright(650, 45);
 movebase(0);
 vex::task::sleep(100);
 encoderfwd(400,40);
 stackMK1(1000,100,-40,-100);
 reset(190, -45);
 vex::task::sleep(30);
 timeright(240, 50);
 advfwd(14, 40, 5);
 scoreaim(400, 100, 15, 15);
 stackMK1(2000,0,30,100);  
 }
 void autonbluemk2()
 {
       Encoder1.resetRotation();
   Encoder2.resetRotation();
   vex::task::sleep(100);
   reset(20,20);
 reset(410, -60);
  armupmk2(540, 60, 15);
  vex::task::sleep(100);
  stackMK1(920, 700, -40, 100);
 reset(400, -60);
  vex::task::sleep(50);
  stackMK1(800,850,-40,100);
 reset(400,-60);
 vex::task::sleep(50);
  stackMK1(1150, 100, -55, 100);
  //advrevWintake(10, 80,10);
  resetWintake(1120, 100);
  vex::task::sleep(500);
  reset(500, -50);
  vex::task::sleep(200);
  //advTurnrightWintake(750, 10, 50);
  //encoderturnrightWintake(400, 50);
 timerturnrightWintake(1100, -35);
 vex::task::sleep(10);
 reset(800, -60);
 vex::task::sleep(100);
 scoreaim(400, 500, 20, 20);
 vex::task::sleep(200);
 stackMK1(2100,0,40,-100);
 reset(960,20);
     
 }
 void programswitch() 
 {
     
 }
// 
// /---------------------------------------------------------------------------/
// /*                          Pre-Autonomous Functions                         */
// /*                                                                           */
// /*  You may want to perform some actions before the competition starts.      */
// /*  Do them in the following function.  You must return from this function   */
// /*  or the autonomous and usercontrol tasks will not be started.  This       */
// /*  function is only called once after the cortex has been powered on and    */ 
// /*  not every time that the robot is disabled.                               */
// /---------------------------------------------------------------------------/
// 
 void pre_auton( void ) {
   // All activities that occur before the competition starts
   // Example: clearing encoders, setting servo positions, ...
   
 }
 
// /---------------------------------------------------------------------------/
// /*                                                                           */
// /*                              Autonomous Task                              */
// /*                                                                           */
// /*  This task is used to control your robot during the autonomous phase of   */
// /*  a VEX Competition.                                                       */
// /*                                                                           */
// /*  You must modify the code to add your own robot specific commands here.   */
// /---------------------------------------------------------------------------/
// 
 void autonomous( void ) 
 {
 //Pidbasecontrolmk2(200, 0, 1, 100);
 //advfwd(400, 60, 15);
 //reset(500, 70);
 //ETurntest();
 //encoderfwd(1000, 70);
 autonredmk2();
 
 }
// 
// /---------------------------------------------------------------------------/
// /*                                                                           */
// /*                              User Control Task                            */
// /*                                                                           */
// /*  This task is used to control your robot during the user control phase of */
// /*  a VEX Competition.                                                       */
// /*                                                                           */
// /*  You must modify the code to add your own robot specific commands here.   */
// /---------------------------------------------------------------------------/
 
 void usercontrol( void ) {
   // User control code here, inside the loop
   while (1) {
         printTemp();
        rightfront.spin(vex::directionType::fwd, HController.Axis2.value(), vex::velocityUnits::pct);
         leftfront.spin(vex::directionType::fwd, HController.Axis3.value(), vex::velocityUnits::pct);
         rightback.spin(vex::directionType::fwd, HController.Axis2.value(), vex::velocityUnits::pct);
         leftback.spin(vex::directionType::fwd, HController.Axis3.value(), vex::velocityUnits::pct);
         LeftIntakeclaw.spin(vex::directionType::fwd, VController.Axis2.value(), vex::velocityUnits::pct);
         RightIntakeclaw.spin(vex::directionType::fwd,VController.Axis2.value(),vex::velocityUnits::pct);
      
        if(VController.ButtonR1.pressing())
        {
            LeftArm.spin(vex::directionType::fwd,1,vex::velocityUnits::pct);
             RightArm.spin(vex::directionType::fwd,1,vex::velocityUnits::pct);
        }
 
   //automated stacker in driver, leron dosen't really use though
      else if(VController.ButtonL2.pressing())
       {
         rightfront.stop();
         leftfront.stop();
         rightback.stop();
         leftback.stop();
         LeftIntakeclaw.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
         RightIntakeclaw.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
         LeftArm.spin(vex::directionType::fwd,-30,vex::velocityUnits::pct);
         RightArm.spin(vex::directionType::fwd,-30,vex::velocityUnits::pct);  
         vex::task::sleep(1300);  
       }
       
        else  if(VController.ButtonL1.pressing())
       {
          rightfront.stop();
          leftfront.stop();
         rightback.stop();
         leftback.stop();
         LeftIntakeclaw.spin(vex::directionType::fwd, -100, vex::velocityUnits::pct);
         RightIntakeclaw.spin(vex::directionType::fwd,-100,vex::velocityUnits::pct);
         LeftArm.spin(vex::directionType::fwd,40,vex::velocityUnits::pct);
         RightArm.spin(vex::directionType::fwd,40,vex::velocityUnits::pct);  
         vex::task::sleep(1300);  
       }
         
            else 
       {
           LeftArm.spin(vex::directionType::fwd,VController.Axis3.value(),vex::velocityUnits::pct);
        RightArm.spin(vex::directionType::fwd,VController.Axis3.value(),vex::velocityUnits::pct); 
          LeftIntakeclaw.spin(vex::directionType::fwd, VController.Axis2.value(), vex::velocityUnits::pct);
         RightIntakeclaw.spin(vex::directionType::fwd,VController.Axis2.value(),vex::velocityUnits::pct); 
       }
  
     vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
   }
 }
 
 //
 // Main will set up the competition functions and callbacks.
 int main() {
     //Set up callbacks for autonomous and driver control periods.
     Competition.autonomous( autonomous );
     Competition.drivercontrol( usercontrol );
     
     //Run the pre-autonomous function. 
     pre_auton();
        
     //Prevent main from exiting with an infinite loop.                        
     while(1) {
       vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
     }    
        
 }
