// the setup function runs once when you press reset or power the board
void setup() 
{
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() 
{
  static unsigned long lastToggleTime = 0;
  unsigned long currentTime = millis();
  unsigned long intervalOn = 5UL * 60UL * 1000UL; // 5 minutes in milliseconds
  unsigned long intervalOff = (12UL * 60UL * 60UL * 1000UL) - intervalOn; // 12 hours minus 5 minutes in milliseconds

  if (digitalRead(13) == LOW && currentTime - lastToggleTime >= intervalOff) 
  {
    lastToggleTime = currentTime;
    digitalWrite(13, HIGH); // turn the pin on
  }
  else if (digitalRead(13) == HIGH && currentTime - lastToggleTime >= intervalOn) 
  {
    lastToggleTime = currentTime;
    digitalWrite(13, LOW); // turn the pin off
  }
}