void setup()
{
   Serial.begin(9600);
   
   pinMode(3,OUTPUT);       //  pins 3,4,5,6 are for motors that control movement  3,5(HIGH)are for forward
   pinMode(4,OUTPUT);        
   pinMode(5,OUTPUT);
   pinMode(6,OUTPUT); 
         
   pinMode(7,OUTPUT);
   pinMode(8,OUTPUT);
   
   pinMode(9,OUTPUT);       //For grabbing mechanism   (9,HIGH) &(10,LOW) is for closing the jaw 
   pinMode(10,OUTPUT);      //For grabbing mechanism  
   
   pinMode(11,OUTPUT);
   pinMode(12,OUTPUT);
}
void loop() 
{
  
  char movekey = 0;
  if(Serial.available())
    {
      movekey = Serial.read();   
    }
  if (movekey=='w')
    {
      forward();
   
    }
   else if (movekey=='s')
   {
    reverse();
 
   }
   
   
   else if (movekey=='a')
   {
    turnleft();
 
   }
 

   
   else if (movekey=='d')
   {
    turnright();
   
   }
   
  
else if (movekey=='u')
   {
    motorstop();
 
   }
   else if (movekey=='1')    // to  close the jaw of picking mechanism 
   {
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);

    
   }
    else if (movekey=='2')  //to open jaw of picking mechanism
   {
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
    
   }
    else if (movekey=='3')
   {
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
   }
     else if (movekey=='4')
     {
    digitalWrite(7,LOW);
    digitalWrite(8,LOW); 
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
      
   }
}

//creating functions
void forward()
{
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);

}
void reverse()
{
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);

}
void turnleft()
{
  digitalWrite(6,HIGH);//2
  digitalWrite(5,LOW);//3
  digitalWrite(3,HIGH);//9
  digitalWrite(4,LOW);//8

}
void turnright()
{
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);

}
void motorstop()
{
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);

}


