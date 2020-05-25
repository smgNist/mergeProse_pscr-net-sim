/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 *   Copyright (c) 2020 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
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

#ifndef NR_SL_UE_CMAC_SAP_H
#define NR_SL_UE_CMAC_SAP_H

#include <ns3/ptr.h>

#include <stdint.h>
#include <limits>


namespace ns3 {


class NrSlMacSapUser;
class NrSlCommResourcePool;

/**
 * \group lte
 *
 * \brief Service Access Point (SAP) offered by the UE MAC to the UE RRC for NR Sidelink
 *
 * This is the NR Sidelink MAC SAP Provider, i.e., the part of the SAP that
 * contains the Sidelink MAC methods called by the RRC
 */
class NrSlUeCmacSapProvider
{
public:
  virtual ~NrSlUeCmacSapProvider ();

  /**
   * NR Sidelink Logical Channel information to be passed to CmacSapProvider::AddNrSlLc
   *
   */
  struct SidelinkLogicalChannelInfo
  {
    uint32_t srcL2Id {std::numeric_limits <uint32_t>::max ()}; //!< L2 source id
    uint32_t dstL2Id {std::numeric_limits <uint32_t>::max ()}; //!< L2 destination id
    uint8_t  lcId {std::numeric_limits <uint8_t>::max ()};     //!< logical channel identifier
    uint8_t  lcGroup {std::numeric_limits <uint8_t>::max ()};  //!< logical channel group
    uint8_t  pqi {std::numeric_limits <uint8_t>::max ()};      //!< PC5 QoS Class Identifier
    uint8_t  priority {std::numeric_limits <uint8_t>::max ()};  //!< priority
    bool     isGbr {false};   //!< true if the bearer is GBR, false if the bearer is NON-GBR
    uint64_t mbr {0};   //!< maximum bitrate
    uint64_t gbr {0};   //!< guaranteed bitrate
  };


  /**
   * \brief Adds a new Logical Channel (LC) used for Sidelink
   *
   * \param slLcInfo The sidelink LC info
   * \param msu The corresponding LteMacSapUser
   */
  virtual void AddNrSlLc (const SidelinkLogicalChannelInfo &slLcInfo, NrSlMacSapUser* msu) = 0;

  /**
   * \brief Remove an existing NR Sidelink Logical Channel for a UE
   *
   * \param slLcId is the Sidelink Logical Channel Id
   * \param srcL2Id is the Source L2 ID
   * \param dstL2Id is the Destination L2 ID
   */
  virtual void RemoveNrSlLc (uint8_t slLcId, uint32_t srcL2Id, uint32_t dstL2Id) = 0;
  /**
   * \brief Reset Nr Sidelink LC map
   *
   */
  virtual void ResetNrSlLcMap () = 0;

  /**
   * \brief Add NR Sidelink communication transmission pool
   *
   * Adds transmission pool for NR Sidelink communication
   *
   * \param pool The pointer to the NrSlCommResourcePool
   */
  virtual void AddNrSlCommTxPool (Ptr<const NrSlCommResourcePool> txPool) = 0;
  /**
   * \brief Add NR Sidelink communication reception pool
   *
   * Adds reception pool for NR Sidelink communication
   *
   * \param pool The pointer to the NrSlCommResourcePool
   */
  virtual void AddNrSlCommRxPool (Ptr<const NrSlCommResourcePool> rxPool) = 0;
  /**
   * \brief Add NR Sidelink destination layer 2 Id
   *
   * Adds destination layer 2 id to list to destinations
   *
   * \param dstL2Id The destination layer 2 ID
   * \param poolId The id of the pool to used for TX and RX
   */
  virtual void AddNrSlDstL2Id (uint32_t dstL2Id, uint16_t poolId) = 0;
};

/**
 * \ingroup lte
 *
 * Template for the implementation of the NrSlUeCmacSapProvider as a member
 * of an owner class of type C to which all methods are forwarded.
 *
 * Usually, methods are forwarded to UE MAC class, which are called by UE RRC
 * to perform NR Sidelink.
 *
 */
template <class C>
class MemberNrSlUeCmacSapProvider : public NrSlUeCmacSapProvider
{
public:
  /**
   * \brief Constructor
   *
   * \param mac the MAC class
   */
  MemberNrSlUeCmacSapProvider (C* mac);

  // inherited from NrSlUeCmacSapProvider
  virtual void AddNrSlLc (const SidelinkLogicalChannelInfo &slLcInfo, NrSlMacSapUser* msu);
  virtual void RemoveNrSlLc (uint8_t slLcId, uint32_t srcL2Id, uint32_t dstL2Id);
  virtual void ResetNrSlLcMap ();
  virtual void AddNrSlCommTxPool (Ptr<const NrSlCommResourcePool> txPool);
  virtual void AddNrSlCommRxPool (Ptr<const NrSlCommResourcePool> rxPool);
  virtual void AddNrSlDstL2Id (uint32_t dstL2Id, uint16_t poolId);

private:
  C* m_mac; ///< the MAC class
};


template <class C>
MemberNrSlUeCmacSapProvider<C>::MemberNrSlUeCmacSapProvider (C* mac)
  : m_mac (mac)
{
}

template <class C>
void MemberNrSlUeCmacSapProvider<C>::AddNrSlLc (const SidelinkLogicalChannelInfo &slLcInfo, NrSlMacSapUser* msu)
{
  m_mac->DoAddNrSlLc (slLcInfo, msu);
}

template <class C>
void MemberNrSlUeCmacSapProvider<C>::RemoveNrSlLc (uint8_t slLcId, uint32_t srcL2Id, uint32_t dstL2Id)
{
  m_mac->DoRemoveNrSlLc (slLcId, srcL2Id, dstL2Id);
}

template <class C>
void MemberNrSlUeCmacSapProvider<C>::ResetNrSlLcMap ()
{
  m_mac->DoResetNrSlLcMap ();
}

template <class C>
void
MemberNrSlUeCmacSapProvider<C>::AddNrSlCommTxPool (Ptr<const NrSlCommResourcePool> txPool)
{
  m_mac->DoAddNrSlCommTxPool (txPool);
}

template <class C>
void
MemberNrSlUeCmacSapProvider<C>::AddNrSlCommRxPool (Ptr<const NrSlCommResourcePool> rxPool)
{
  m_mac->DoAddNrSlCommRxPool (rxPool);
}

template <class C>
void MemberNrSlUeCmacSapProvider<C>::AddNrSlDstL2Id (uint32_t dstL2Id, uint16_t poolId)
{
  m_mac->DoAddNrSlDstL2Id (dstL2Id, poolId);
}



/**
 * Service Access Point (SAP) offered by the UE MAC to the UE RRC
 *
 * This is the MAC SAP User, i.e., the part of the SAP that contains the RRC methods called by the MAC
 */
class NrSlUeCmacSapUser
{
public:
  virtual ~NrSlUeCmacSapUser ();

  /**
   * Notify the RRC that the MAC has detected a new incoming flow for Sidelink reception
   *
   * \param lcId The logical channel id
   * \param srcL2Id Sidelink source L2 id
   * \param dstL2Id Sidelink destination L2 id
   */
 // virtual void NotifySidelinkReception (uint8_t lcId, uint32_t srcL2Id, uint32_t dstL2Id) = 0;

  /**
   * Notify the RRC that the MAC has data to send in the PSSCH
   */
 // virtual void NotifyMacHasSlDataToSend () = 0;
  /**
   * Notify the RRC that the MAC does not have data to send in the PSSCH
   */
//  virtual void NotifyMacHasNoSlDataToSend () = 0;

  /**
   * Notify the RRC that the MAC has detected a new incoming flow for discovery reception
   *
   * \param p The packet containing the discovery message
   */
  //virtual void NotifyDiscoveryReception (Ptr<Packet> p) = 0;
};

/**
 * \ingroup lte
 *
 * Template for the implementation of the NrSlUeCmacSapUser as a member
 * of an owner class of type C to which all methods are forwarded.
 *
 * Usually, methods are forwarded to UE RRC class, which are called by UE MAC
 * to perform NR Sidelink.
 *
 */
template <class C>
class MemberNrSlUeCmacSapUser : public NrSlUeCmacSapUser
{
public:
  /**
   * \brief Constructor
   *
   * \param rrc the RRC class
   */
  MemberNrSlUeCmacSapUser (C* rrc);

  // inherited from NrSlUeCmacSapUser

private:
  C* m_rrc; ///< the MAC class
};

template <class C>
MemberNrSlUeCmacSapUser<C>::MemberNrSlUeCmacSapUser (C* rrc)
  : m_rrc (rrc)
{
}



} // namespace ns3


#endif // NR_SL_UE_CMAC_SAP_H
