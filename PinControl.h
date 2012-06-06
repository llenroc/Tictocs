#ifndef __PINCONTROL_H__
#define __PINCONTROL_H__

// STL includes
// C includes
// Library includes
#include <Connector.h>
// Project includes

namespace Tictocs
{

/**
 * Example for how classes should be declared
 */

class PinControl: public Connectable
{
private:
  uint8_t pin;
  uint8_t signal_low;
  uint8_t signal_high;
protected:
  virtual void onNotify(const Connectable*, uint8_t signal);
  uint8_t get_pin(void) const { return pin; }
  void toggle(void);
public:
  PinControl(Connector& _conn,int _pin,uint8_t _signal_low, uint8_t _signal_high): Connectable(_conn), pin(_pin), signal_low(_signal_low), signal_high(_signal_high) {}
  void begin(void);
  void begin(Connectable* _whom) { begin(); listen(_whom); }
  void listen(Connectable* _whom);
};

} // namespace Tictocs

#endif // __PINCONTROL_H__
// vim:cin:ai:sts=2 sw=2 ft=cpp
