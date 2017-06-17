/**
 * Read the input buffer and find any recognized commands. One G or M command per line.
 
void processCommand() {
  // look for commands that start with 'G'
  int cmd=parsenumber('G',-1);
  switch(cmd) {
  case 0: // move in a line
  case 1: // move in a line
    set_feedrate(parsenumber('F',fr));
    //line( parsenumber('X',(mode_abs?px:0)) + (mode_abs?0:px),
    //parsenumber('Y',(mode_abs?py:0)) + (mode_abs?0:py) );
    break;
  // case 2: // clockwise arc
  // case 3: // counter-clockwise arc
  case 4: pause(parsenumber('P',0)*1000); break; // wait a while
  case 90: mode_abs=1; break; // absolute mode
  case 91: mode_abs=0; break; // relative mode
  case 92: // set logical position
    position( parsenumber('X',0),
    parsenumber('Y',0) );
    break;
  default: break;
  }

  // look for commands that start with 'M'
  cmd=parsenumber('M',-1);
  switch(cmd) {
  case 18: // turns off power to steppers (releases the grip)
    m1.release();
    m2.release();
    break;
  case 100: help(); break;
  case 114: where(); break; // prints px, py, fr, and mode.
  default: break;
  }

  // if the string has no G or M commands it will get here and the Arduino will silently ignore it
}
*/
void processCommand(String str)
{
  //Looking for commands that start with G:
  if(str.charAt(0)=='G')
  {
    int c1=str.substring(1,3).toInt();
    Serial.print('\n');
    switch(c1)
    {
      case 00: Serial.print("Absolute ModeXY\n");
               break;

      case 01: Serial.print("Relative ModeXY\n");
               break;

      case 90: Serial.print("abs\n");
               break;
               
      case 91: Serial.print("rel\n");
    }
  }
  if(str.charAt(0)=='M')
  {
    int c1=str.substring(1,4).toInt();
    Serial.print('\n');
    switch(c1)
    {
      case 18: Serial.print("disable motors\n");
               break;

      case 100: ;
                break;

      case 114: Serial.print("Report position and feedrate");
                break;
    }
  }
}


