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

#ifndef NR_SL_COMM_RESOURCE_POOL
#define NR_SL_COMM_RESOURCE_POOL

#include <ns3/object.h>
#include <ns3/lte-rrc-sap.h>

#include <stdint.h>
#include <list>
#include <array>
#include <bitset>
#include <unordered_map>

namespace ns3 {


class NrSlCommResourcePool : public Object
{

public:
  /**
   * \brief NR Sidelink slot info.
   */
  struct SlotInfo
  {
    /**
     * \brief NrSlSlotInfo constructor
     * \param numSlPscchRbs Indicates the number of PRBs for PSCCH in a resource pool where it is not greater than the number PRBs of the subchannel.
     * \param slPscchSymStart Indicates the starting symbol used for sidelink PSCCH in a slot
     * \param slPscchSymlength Indicates the total number of symbols available for sidelink PSCCH
     * \param slPsschSymStart Indicates the starting symbol used for sidelink PSSCH in a slot
     * \param slPsschSymlength Indicates the total number of symbols available for sidelink PSSCH
     * \param slSubchannelSize Indicates the subchannel size in number of RBs
     * \param slMaxNumPerReserve Indicates the maximum number of reserved PSCCH/PSSCH resources that can be indicated by an SCI.
     * \param absSlotIndex Indicates the the absolute slot index
     * \param slotOffset Indicates the positive offset between two slots
     */
    SlotInfo (uint16_t numSlPscchRbs, uint16_t slPscchSymStart, uint16_t slPscchSymLength,
              uint16_t slPsschSymStart, uint16_t slPsschSymLength, uint16_t slSubchannelSize,
              uint16_t slMaxNumPerReserve, uint64_t absSlotIndex, uint32_t slotOffset)
    {
      this->numSlPscchRbs = numSlPscchRbs;
      this->slPscchSymStart = slPscchSymStart;
      this->slPscchSymLength = slPscchSymLength;
      this->slPsschSymStart = slPsschSymStart;
      this->slPsschSymLength = slPsschSymLength;
      this->slSubchannelSize = slSubchannelSize;
      this->slMaxNumPerReserve = slMaxNumPerReserve;
      this->absSlotIndex = absSlotIndex;
      this->slotOffset = slotOffset;
    }
    //PSCCH
    uint16_t numSlPscchRbs {0}; //!< Indicates the number of PRBs for PSCCH in a resource pool where it is not greater than the number PRBs of the subchannel.
    uint16_t slPscchSymStart {0}; //!< Indicates the starting symbol used for sidelink PSCCH in a slot
    uint16_t slPscchSymLength {0}; //!< Indicates the total number of symbols available for sidelink PSCCH
    //PSSCH
    uint16_t slPsschSymStart {0}; //!< Indicates the starting symbol used for sidelink PSSCH in a slot
    uint16_t slPsschSymLength {0}; //!< Indicates the total number of symbols available for sidelink PSSCH
    //subchannel size in RBs
    uint16_t slSubchannelSize {0}; //!< Indicates the subchannel size in number of RBs
    uint16_t slMaxNumPerReserve {0}; //!< The maximum number of reserved PSCCH/PSSCH resources that can be indicated by an SCI.
    uint64_t absSlotIndex {0}; //!< Indicates the the absolute slot index
    uint32_t slotOffset {0}; //!< Indicates the positive offset between two slots
  };

  /**
   * Scheduling types of sidelink pools hold by this class. At one time,
   * either all the pools will be used for UE_SELECTED scheduling or
   * network SCHEDULED. There can not be mix-up.
   */
  enum SchedulingType
  {
    UNKNOWN = 0,
    SCHEDULED,
    UE_SELECTED
  };
  /**
   * \brief Map to store the physical SL pool per BWP and per SL pool
   *
   * Key of the first map is the BWP id
   * Value of the first map is an unordered map storing physical SL pool per SL pool
   * Key of the second map is the pool id
   * Value of the second map is a vector, which is a physical SL pool
   */
  typedef std::unordered_map<uint8_t, std::unordered_map <uint16_t, std::vector <std::bitset<1>>> > PhySlPoolMap;

  /**
   * \brief Checks if two NR Sidelink pool configurations are identical
   *
   * \param other The configuration of the other resource pool
   * \return true if this configuration is the same as the other one
   */
  bool operator== (const NrSlCommResourcePool& other) const;

  /**
   * \brief Constructor
   */
  NrSlCommResourcePool ();
  /**
   * \brief Destructor
   */
  virtual ~NrSlCommResourcePool ();

  /**
   * \brief Get the type ID.
   * \return the object TypeId
   */
  static TypeId GetTypeId ();

  /**
   * \brief Set NR Sidelink preconfiguration  frequency information list
   *
   * \param slPreconfigFreqInfoList A list containing per carrier configuration for NR sidelink communication
   */
  void SetNrSlPreConfigFreqInfoList (const std::array <LteRrcSap::SlFreqConfigCommonNr, MAX_NUM_OF_FREQ_SL> &slPreconfigFreqInfoList);
  /**
   * \brief Set NR Sidelink physical pool map
   *
   * \param phySlPoolMap The Map containing the physical SL pool per BWP and per SL pool
   */
  void SetNrSlPhysicalPoolMap (NrSlCommResourcePool::PhySlPoolMap phySlPoolMap);
  /**
   * \brief Get NR Sidelink physical sidelink pool
   *
   * \param bwpId The bandwidth part id
   * \param poolId The pool id
   * \return A vector representing the the physical sidelink pool
   */
  const std::vector <std::bitset<1>> GetNrSlPhyPool (uint8_t bwpId, uint16_t poolId) const;
  /**
   * \brief Get NR Sidelink communication opportunities
   *
   * TS 38.214 8.1.2.1 <b>"Within the slot, PSSCH resource allocation starts at symbol startSLsymbols+1"</b>
   * Since we are multiplexing the PSCCH and PSSCH in time, we are already
   * taking the TS 38.214 (8.1.2.1) into the consideration. That is,
   * <b>1.</b> \f$number of PSSCH symbols = Total symbols - number of PSCCH symbols\f$
   * TS 38.214 8.1.2.1 also says <b>"The UE shall not transmit PSSCH in the last symbol configured for sidelink.</b>
   * Therefore, we to subtract one more symbol from the PSSCH symbols, i.e.,
   * <b>2.</b> \f$Total number of PSSCH symbols = number of PSSCH symbols (from 1) - 1\f$
   *
   * \param numAbsSlot The current absolute slot number
   * \param bwpId The bandwidth part id
   * \param numerology The numerology
   * \param poolId The pool id
   * \param t1 The physical layer processing delay in slots
   * \param t2 The UE specific length of the selection window in slots
   * \return A list of sidelink communication opportunities for each available slot in a selection window
   */
  std::list <NrSlCommResourcePool::SlotInfo> GetNrSlCommOpportunities (uint64_t absIndexCurretSlot, uint8_t bwpId, uint16_t numerology, uint16_t poolId, uint8_t t1, uint16_t t2) const;
  /**
   * \brief Get NR Sidelink sensing window in slots
   *
   * \param bwpId The bandwidth part id
   * \param poolId The pool id
   * \return The length of the sensing window in slots
   */
  uint16_t GetNrSlSensWindInSlots (uint8_t bwpId, uint16_t poolId, Time slotLength) const;
  /**
   * \brief Set NR Sidelink scheduling type to be used for the pools
   *
   * \param type The scheduling type [NrSlCommResourcePool::SchedulingType]
   */
  void SetNrSlSchedulingType (NrSlCommResourcePool::SchedulingType type);
  /**
   * \brief Get NR Sidelink scheduling type used for the pools
   *
   * \return The scheduling type [NrSlCommResourcePool::SchedulingType]
   */
  NrSlCommResourcePool::SchedulingType GetNrSlSchedulingType () const;
  /**
   * \brief Get NR Sidelink subchannel size
   *
   * \param bwpId The bandwidth part id
   * \param poolId The pool id
   * \return The subchannel size in RBs
   */
  uint16_t GetNrSlSubChSize (uint8_t bwpId, uint16_t poolId) const;



private:
  /**
   * \brief Get iterator to physical sidelink pool
   *
   * \param bwpId The bandwidth part id
   * \param poolId The pool id
   * \return An iterator to the stored physical sidelink pool
   */
  std::unordered_map <uint16_t, std::vector <std::bitset<1>>>::const_iterator GetIteratorToPhySlPool (uint8_t bwpId, uint16_t pooId) const;
  /*
   * \brief Get SlResourcePoolNr
   *
   * \param bwpId The BWP id
   * \param pooI The pool id
   * \return The LteRrcSap::SlResourcePoolNr, which holds the SL pool related configuration
   */
  const LteRrcSap::SlResourcePoolNr GetSlResourcePoolNr (uint8_t bwpId, uint16_t poolId) const;
  std::array <LteRrcSap::SlFreqConfigCommonNr, MAX_NUM_OF_FREQ_SL> m_slPreconfigFreqInfoList; //!< A list containing per carrier configuration for NR sidelink communication
  PhySlPoolMap m_phySlPoolMap; //!< A map to store the physical SL pool per BWP and per SL pool
  SchedulingType m_schType {SchedulingType::UNKNOWN}; //!< Type of the scheduling to be used for the pools hold by this class

};



}

#endif /* NR_SL_COMM_RESOURCE_POOL */
