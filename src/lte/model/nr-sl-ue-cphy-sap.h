/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 *   Copyright (c) 2019 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License version 2 as
 *   published by the Free Software Foundation;
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#ifndef NR_SL_UE_CPHY_SAP_H
#define NR_SL_UE_CPHY_SAP_H

#include <stdint.h>
#include <ns3/ptr.h>


namespace ns3 {

  class NrSlCommResourcePool;

/**
 * \ingroup lte
 *
 * Service Access Point (SAP) offered by the UE PHY to the UE RRC
 * for control purposes of NR Sidelink
 *
 * This is the PHY SAP Provider, i.e., the part of the SAP that contains
 * the PHY methods called by the RRC
 */
class NrSlUeCphySapProvider
{
public:
  /**
   * \brief Destructor
   */
  virtual ~NrSlUeCphySapProvider ();

  //Sidelink Communication
  /**
   * \brief Add NR Sidelink communication transmission pool
   *
   * Adds transmission pool for NR Sidelink communication
   *
   * \param remoteL2Id The destination Layer 2 ID
   * \param pool The pointer to the NrSlCommResourcePool
   */
  virtual void AddNrSlCommTxPool (uint32_t remoteL2Id, Ptr<const NrSlCommResourcePool> txPool) = 0;
  /**
   * \brief Add NR Sidelink communication reception pool
   *
   * Adds reception pool for NR Sidelink communication
   *
   * \param remoteL2Id The destination Layer 2 ID
   * \param pool The pointer to the NrSlCommResourcePool
   */
  virtual void AddNrSlCommRxPool (uint32_t remoteL2Id, Ptr<const NrSlCommResourcePool> rxPool) = 0;
  /**
   * \brief Add NR Sidelink remote Layer 2 Id
   *
   * Adds remote layer 2 id to list to destinations
   *
   * \param remoteL2Id The destination Layer 2 ID
   */
  virtual void AddNrSlRemoteL2Id (uint32_t remoteL2Id) = 0;

};


/**
 * \ingroup lte
 *
 * Service Access Point (SAP) offered by the UE PHY to the UE RRC
 * for control purposes of NR Sidelink
 *
 * This is the CPHY SAP User, i.e., the part of the SAP that contains the RRC
 * methods called by the PHY
*/
class NrSlUeCphySapUser
{
public:
  /**
   * \brief Destructor
   */
  virtual ~NrSlUeCphySapUser ();

};




/**
 * \ingroup lte
 *
 * Template for the implementation of the NrSlUeCphySapProvider as a member
 * of an owner class of type C to which all methods are forwarded.
 *
 * Usually, methods are forwarded to UE PHY class, which are called by UE RRC
 * to perform NR Sidelink.
 *
 */
template <class C>
class MemberNrSlUeCphySapProvider : public NrSlUeCphySapProvider
{
public:
  /**
   * \brief Constructor
   *
   * \param owner The owner class
   */
  MemberNrSlUeCphySapProvider (C* owner);

  // methods inherited from NrSlUeCphySapProvider go here
  //NR Sidelink communication
  virtual void AddNrSlCommTxPool (uint32_t remoteL2Id, Ptr<const NrSlCommResourcePool> txPool);
  virtual void AddNrSlCommRxPool (uint32_t remoteL2Id, Ptr<const NrSlCommResourcePool> rxPool);
  virtual void AddNrSlRemoteL2Id (uint32_t remoteL2Id);

private:
  MemberNrSlUeCphySapProvider ();
  C* m_owner; ///< the owner class
};

template <class C>
MemberNrSlUeCphySapProvider<C>::MemberNrSlUeCphySapProvider (C* owner)
  : m_owner (owner)
{
}

//Sidelink communication

template <class C>
void
MemberNrSlUeCphySapProvider<C>::AddNrSlCommTxPool (uint32_t remoteL2Id, Ptr<const NrSlCommResourcePool> txPool)
{
  m_owner->DoAddNrSlCommTxPool (remoteL2Id, txPool);
}

template <class C>
void
MemberNrSlUeCphySapProvider<C>::AddNrSlCommRxPool (uint32_t remoteL2Id, Ptr<const NrSlCommResourcePool> rxPool)
{
  m_owner->DoAddNrSlCommRxPool (remoteL2Id, rxPool);
}

template <class C>
void MemberNrSlUeCphySapProvider<C>::AddNrSlRemoteL2Id (uint32_t remoteL2Id)
{
  m_owner->DoAddNrSlRemoteL2Id (remoteL2Id);
}


/**
 * \ingroup lte
 *
 * Template for the implementation of the NrSlUeCphySapUser as a member
 * of an owner class of type C to which all methods are forwarded.
 *
 * Usually, methods are forwarded to UE RRC class, which are called by UE PHY
 * to perform NR Sidelink.
 *
 */
template <class C>
class MemberNrSlUeCphySapUser : public NrSlUeCphySapUser
{
public:
  /**
   * \brief Constructor
   *
   * \param owner The owner class
   */
  MemberNrSlUeCphySapUser (C* owner);

  // methods inherited from NrSlUeCphySapUser go here

private:
  C* m_owner; ///< the owner class
};

template <class C>
MemberNrSlUeCphySapUser<C>::MemberNrSlUeCphySapUser (C* owner)
  : m_owner (owner)
{
}



} // namespace ns3


#endif // NR_SL_UE_CPHY_SAP_H
