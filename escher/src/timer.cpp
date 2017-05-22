#include <escher/timer.h>

Timer::Timer(uint32_t period) :
  m_period(period),
  m_numberOfTicksBeforeFire(period)
{
}

bool Timer::tick() {
  m_numberOfTicksBeforeFire--;
  if (m_numberOfTicksBeforeFire == 0) {
    fire();
    reset();
    return true;
  }
  return false;
}

void Timer::reset() {
  m_numberOfTicksBeforeFire = m_period;
}
