const int channelPinA = D2;
const int channelPinB = D3;

const int timeThreshold = 5;
long timeCounter = 0;

const int maxSteps = 10000000;
volatile int ISRCounter = 0;
int counter = 0;

bool IsCW = true;

void setup()
{
  pinMode(channelPinA, INPUT_PULLUP);
  pinMode(channelPinB, INPUT_PULLUP);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(channelPinA), doEncodeA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(channelPinB), doEncodeB, CHANGE);
}

void loop()
{
  if (counter != ISRCounter)
  {
    counter = ISRCounter;
    Serial.println(counter);
  }
  delay(50);
}

  ICACHE_RAM_ATTR void doEncodeA()
{
  if (millis() > timeCounter + timeThreshold)
  {
    if (digitalRead(channelPinA) == digitalRead(channelPinB))
    {
      IsCW = true;
      if (ISRCounter + 1 <= maxSteps) ISRCounter++;
    }
    else
    {
      IsCW = false;
      if (ISRCounter - 1 > 0) ISRCounter--;
    }
    timeCounter = millis();
  }
}

  ICACHE_RAM_ATTR void doEncodeB()
{
  if (millis() > timeCounter + timeThreshold)
  {
    if (digitalRead(channelPinA) != digitalRead(channelPinB))
    {
      IsCW = true;
      if (ISRCounter + 1 <= maxSteps) ISRCounter++;
    }
    else
    {
      IsCW = false;
      if (ISRCounter - 1 > 0) ISRCounter--;
    }
    timeCounter = millis();
  }
}
