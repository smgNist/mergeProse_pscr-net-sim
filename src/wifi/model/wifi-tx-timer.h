/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2020 Universita' degli Studi di Napoli Federico II
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Stefano Avallone <stavallo@unina.it>
 */

#ifndef WIFI_TX_TIMER_H
#define WIFI_TX_TIMER_H

#include "ns3/event-id.h"
#include "ns3/nstime.h"
#include "ns3/simulator.h"

namespace ns3 {

/**
 * \ingroup wifi
 *
 * This class is used to handle the timer that a station starts when transmitting
 * a frame that solicits a response. The timeout can be rescheduled (only once)
 * when the RXSTART.indication is received from the PHY.
 */
class WifiTxTimer
{
public:
  /**
   * \enum Reason
   * \brief The reason why the timer was started
   */
  enum Reason
    {
      NOT_RUNNING = 0,
      WAIT_CTS,
      WAIT_NORMAL_ACK,
      WAIT_BLOCK_ACK,
    };

  /** Default constructor */
  WifiTxTimer ();

  virtual ~WifiTxTimer ();

  /**
   * This method is called when a frame soliciting a response is transmitted.
   * This method starts a timer of the given duration and schedules a call to
   * the given method in case the timer expires.
   *
   * \tparam MEM \deduced Class method function signature type
   * \tparam OBJ \deduced Class type of the object
   * \tparam Args \deduced Type template parameter pack
   * \param reason the reason why the timer was started
   * \param delay the time to the expiration of the timer
   * \param mem_ptr Member method pointer to invoke
   * \param obj The object on which to invoke the member method
   * \param args The arguments to pass to the invoked method
   */
  template<typename MEM, typename OBJ, typename... Args>
  void Set (Reason reason, const Time &delay, MEM mem_ptr, OBJ obj, Args... args);

  /**
   * Reschedule the timer to time out the given amount of time from the moment
   * this function is called. Note that the timer must be running and must not
   * have been already rescheduled.
   *
   * \param delay the time to the expiration of the timer
   */
  void Reschedule (const Time &delay);

  /**
   * Get the reason why the timer was started. Call
   * this method only if the timer is running
   *
   * \return the reason why the timer was started
   */
  Reason GetReason (void) const;

  /**
   * Get a string associated with the given reason
   *
   * \param reason the given reason
   * \return a string associated with the given reason
   */
  std::string GetReasonString (Reason reason) const;

  /**
   * Return true if the timer is running
   *
   * \return true if the timer is running
   */
  bool IsRunning (void) const;

  /**
   * Cancel the timer.
   */
  void Cancel (void);

  /**
   * Get the remaining time until the timer will expire.
   *
   * \return the remaining time until the timer will expire.
   *         If the timer is not running, this method returns zero.
   */
  Time GetDelayLeft (void) const;

private:
  /**
   * This method is called when the timer expires. It invokes the callbacks
   * and the method set by the user.
   *
   * \tparam MEM \deduced Class method function signature type
   * \tparam OBJ \deduced Class type of the object
   * \tparam Args \deduced Type template parameter pack
   * \param mem_ptr Member method pointer to invoke
   * \param obj The object on which to invoke the member method
   * \param args The arguments to pass to the invoked method
   */
  template<typename MEM, typename OBJ, typename... Args>
  void Timeout (MEM mem_ptr, OBJ obj, Args... args);

  EventId m_timeoutEvent;         //!< the timeout event after a missing response
  Reason m_reason;                //!< the reason why the timer was started
  Ptr<EventImpl> m_endRxEvent;       //!< event to schedule upon RXSTART.indication
  bool m_rescheduled;             //!< whether the timer has been already rescheduled
};


template<typename MEM, typename OBJ, typename... Args>
void
WifiTxTimer::Set (Reason reason, const Time &delay, MEM mem_ptr, OBJ obj, Args... args)
{
  typedef void (WifiTxTimer::*TimeoutType)(MEM, OBJ, Args...);

  m_timeoutEvent = Simulator::Schedule<TimeoutType> (delay, &WifiTxTimer::Timeout, this, mem_ptr, obj, args...);
  m_reason = reason;
  m_rescheduled = false;

  // create an event to schedule if the PHY notifies the reception of a response
  m_endRxEvent = Ptr<EventImpl> (MakeEvent<TimeoutType> (&WifiTxTimer::Timeout, this, mem_ptr, obj,
                                                      std::forward<Args> (args)... ), false);
}

template<typename MEM, typename OBJ, typename... Args>
void
WifiTxTimer::Timeout (MEM mem_ptr, OBJ obj, Args... args)
{
  // Invoke the method set by the user
  ((*obj).*mem_ptr)(args...);
}

} //namespace ns3

#endif /* WIFI_TX_TIMER_H */

