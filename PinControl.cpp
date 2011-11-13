// STL includes
// C includes
// Library includes
#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

// Project includes
#include <PinControl.h>

/****************************************************************************/

void PinControl::begin(void)
{
  pinMode(pin,OUTPUT);
  digitalWrite(pin,LOW);
}

/****************************************************************************/

void PinControl::listen(Connectable* _whom)
{
  Connectable::listen(_whom,signal_low);
  Connectable::listen(_whom,signal_high);
}

/****************************************************************************/

void PinControl::onNotify(const Connectable*, uint8_t signal)
{
  if (signal == signal_low)
    digitalWrite(pin,LOW);
  else if (signal == signal_high)
    digitalWrite(pin,HIGH);
}

/****************************************************************************/

// vim:cin:ai:sts=2 sw=2 ft=cpp