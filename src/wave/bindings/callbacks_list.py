callback_classes = [
    ['ns3::ObjectBase *', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['bool', 'ns3::Ptr<ns3::NetDevice>', 'ns3::Ptr<const ns3::Packet>', 'unsigned short', 'const ns3::Address &', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['bool', 'ns3::Ptr<ns3::NetDevice>', 'ns3::Ptr<const ns3::Packet>', 'unsigned short', 'const ns3::Address &', 'const ns3::Address &', 'ns3::NetDevice::PacketType', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'ns3::Ptr<ns3::NetDevice>', 'ns3::Ptr<const ns3::Packet>', 'unsigned short', 'const ns3::Address &', 'const ns3::Address &', 'ns3::NetDevice::PacketType', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'ns3::Ptr<ns3::NetDevice>', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'ns3::Ptr<ns3::Socket>', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['bool', 'ns3::Ptr<ns3::Socket>', 'const ns3::Address &', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'ns3::Ptr<ns3::Socket>', 'const ns3::Address &', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'ns3::Ptr<ns3::Socket>', 'unsigned int', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'unsigned int', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'const ns3::Ipv4Header &', 'ns3::Ptr<const ns3::Packet>', 'unsigned int', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'ns3::Ptr<const ns3::Packet>', 'ns3::Ptr<ns3::Ipv4>', 'unsigned int', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'const ns3::Ipv4Header &', 'ns3::Ptr<const ns3::Packet>', 'ns3::Ipv4L3Protocol::DropReason', 'ns3::Ptr<ns3::Ipv4>', 'unsigned int', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'ns3::Ptr<const ns3::Packet>', 'ns3::Ptr<ns3::Ipv6>', 'unsigned int', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'const ns3::Ipv6Header &', 'ns3::Ptr<const ns3::Packet>', 'ns3::Ipv6L3Protocol::DropReason', 'ns3::Ptr<ns3::Ipv6>', 'unsigned int', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'const ns3::Ipv6Header &', 'ns3::Ptr<const ns3::Packet>', 'unsigned int', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'ns3::Ptr<const ns3::Packet>', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'std::basic_string<char>', 'ns3::Ptr<const ns3::Packet>', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'ns3::Ptr<const ns3::MobilityModel>', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['unsigned short', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['unsigned long', 'const ns3::WifiTxVector &', 'unsigned short', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['unsigned long', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['bool', 'const ns3::WifiTxVector &', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'ns3::Ptr<ns3::WifiPsdu>', 'ns3::RxSignalInfo', 'ns3::WifiTxVector', 'std::vector<bool, std::allocator<bool>>', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'ns3::Ptr<ns3::WifiPsdu>', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'ns3::Time', 'ns3::Time', 'WifiPhyState', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'ns3::Ptr<const ns3::Packet>', 'double', 'ns3::WifiMode', 'ns3::WifiPreamble', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'ns3::Ptr<const ns3::Packet>', 'double', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'ns3::Ptr<const ns3::Packet>', 'ns3::WifiMode', 'ns3::WifiPreamble', 'unsigned char', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'std::unordered_map<unsigned short, ns3::Ptr<const ns3::WifiPsdu>, std::hash<unsigned short>, std::equal_to<unsigned short>, std::allocator<std::pair<const unsigned short, ns3::Ptr<const ns3::WifiPsdu>>>>', 'ns3::WifiTxVector', 'double', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'ns3::Ptr<const ns3::Packet>', 'std::map<std::pair<unsigned int, unsigned int>, double, std::less<std::pair<unsigned int, unsigned int>>, std::allocator<std::pair<const std::pair<unsigned int, unsigned int>, double>>>', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'ns3::WifiTxVector', 'ns3::Time', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'ns3::Ptr<const ns3::Packet>', 'ns3::WifiPhyRxfailureReason', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'ns3::Ptr<const ns3::Packet>', 'unsigned short', 'ns3::WifiTxVector', 'ns3::MpduInfo', 'ns3::SignalNoiseDbm', 'unsigned short', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'ns3::Ptr<const ns3::Packet>', 'unsigned short', 'ns3::WifiTxVector', 'ns3::MpduInfo', 'unsigned short', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'ns3::Ptr<const ns3::Packet>', 'ns3::Mac48Address', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'ns3::Mac48Address', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'ns3::Ptr<const ns3::Packet>', 'ns3::Mac48Address', 'ns3::Mac48Address', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'const ns3::WifiMacHeader &', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'ns3::WifiMacDropReason', 'ns3::Ptr<const ns3::WifiMacQueueItem>', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'ns3::Ptr<const ns3::WifiMacQueueItem>', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'unsigned char', 'ns3::Ptr<const ns3::WifiMacQueueItem>', 'const ns3::WifiTxVector &', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'unsigned char', 'ns3::Ptr<const ns3::WifiPsdu>', 'const ns3::WifiTxVector &', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'unsigned char', 'std::unordered_map<unsigned short, ns3::Ptr<ns3::WifiPsdu>, std::hash<unsigned short>, std::equal_to<unsigned short>, std::allocator<std::pair<const unsigned short, ns3::Ptr<ns3::WifiPsdu>>>> *', 'const std::set<ns3::Mac48Address, std::less<ns3::Mac48Address>, std::allocator<ns3::Mac48Address>> *', 'unsigned long', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'unsigned int', 'unsigned int', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'ns3::Ptr<const ns3::QueueDiscItem>', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['bool', 'ns3::Ptr<ns3::WifiMac>', 'const ns3::OrganizationIdentifier &', 'ns3::Ptr<const ns3::Packet>', 'const ns3::Address &', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['bool', 'ns3::Ptr<const ns3::Packet>', 'const ns3::Address &', 'unsigned int', 'unsigned int', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'ns3::Address', 'ns3::Address', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'ns3::Mac48Address', 'unsigned char', 'bool', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'ns3::Mac48Address', 'unsigned char', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'ns3::Time', 'ns3::Mac48Address', 'unsigned char', 'ns3::OriginatorBlockAckAgreement::State', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'ns3::Time', 'ns3::Time', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
    ['void', 'ns3::Ptr<ns3::WifiMacQueueItem>', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty', 'ns3::empty'],
]
