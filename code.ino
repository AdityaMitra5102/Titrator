#include <Servo.h>
		
	Servo knob;
	int prev[10];
	void setup() {
	  // put your setup code here, to run once:
	  pinMode(5,OUTPUT);
	  pinMode(6,OUTPUT);
	Serial.begin(9600);
	knob.attach(9);
	for(int i=0;i<10;i++)
	{
	  prev[i]=analogRead(2);
	}
	Serial.println("Starting titration");
	digitalWrite(5,1);
	}

	void loop() 
	{
	  // put your main code here, to run repeatedly:
	  int inp=analogRead(2);
	  for(int i=0;i<10;i++)
	  {
		if(inp>=prev[i]+3)
		{
		  off();
		}
	  }
	  for(int i=0;i<9;i++)
	  {
		prev[i]=prev[i+1];
	  }
	  prev[9]=inp;
	  drop();
	}

	void drop()
	{
	  for(int pos=0;pos<90;pos++)
	  {
		knob.write(pos);
		delay(10);
	  }
	  for(int pos=90;pos>0;pos--)
	  {
		knob.write(pos);
		delay(10);
	  }
	}

	void off()
	{
	  digitalWrite(5,0);
	  digitalWrite(6,0);
	  Serial.println("Titration done");
	  while(true){}
	}
