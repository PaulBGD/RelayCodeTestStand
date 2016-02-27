/*Relay Testing Arduino Code for test stand. Written before spring
break 2016. JWCS*/
//Ports
const int oxSafeP=          0;   //oxidizer safety port
const int fuelSafeP=        1;   //fuel safety port
const int oxOpenP=          2;   //oxidzer open port
const int fuelOpenP=        3;   //fuel open port
const int oxCloseP=         4;   //oxidizer closed port
const int fuelCloseP=       5;   //fuel close port
//Buttons
const int safeB=            6;   //safety button
const int oxSafeB=          7;   //oxidizer safety port
const int fuelSafeB=        8;   //fuel safety port
const int oxOpenB=          9;   //oxidzer open port
const int fuelOpenB=       10;  //fuel open port
const int oxCloseB=        11;  //oxidizer closed port
const int fuelCloseB=      12;  //fuel close port
//States
bool safeOn=     false;    //safety button on
bool oxSafeOn=   false;    //oxidizer safety button on
bool fuelSafeOn= false;    //fuel safety button on
bool oxDel=      false;    //oxidizer state changing (delta)
bool fuelDel=    false;    //fuel state changing (delta)
bool oxClose=    true;     //oxidizer state closing or opening
bool fuelClose=  true;     //fuel state closing or opening

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  stateUpdate();
  if(!safeOn){
    digitalWrite(oxSafeP, LOW);
    digitalWrite(fuelSafeP, LOW);
  }else{
    normalOperation();
  }
}

stateUpdate(){
  safeOn= !digitalRead(safeB)?false:true;//If button not pressed, safety off
  oxSafeOn= !digitalRead(oxSafeB)?false:true;//Ibid
  fuelSafeOn= !digitalRead(fuelSafeB)?false:true;//Ibid
  oxDel= digitalRead(oxOnB)||digitalRead(oxCloseB)?true:false;//If either is tiggered
  fuelDel= digitalRead(fuelOnB)||digitalRead(fuelCloseB)?true:false;//Ibid
  oxClose= oxDel&&digitalRead(oxCloseB)?true:false;//If changing, and not closing, open
  fuelClose= fuelDel&&digitalRead(fuelCloseB)?true:false;//Ibid
}

normalOperation(){
  
}



