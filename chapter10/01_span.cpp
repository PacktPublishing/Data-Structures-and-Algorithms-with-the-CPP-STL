#include <cstdint>
#include <iostream>
#include <span>

struct UDPHeader {
  uint16_t srcPort{0};
  uint16_t destPort{0};
  uint16_t length{0};
  uint16_t checksum{0};

  void display() const {
    std::cout << "Source Port: " << srcPort << "\n"
              << "Destination Port: " << destPort << "\n"
              << "Length: " << length << "\n"
              << "Checksum: " << checksum << "\n";
  }
};

void processUDPPacket(std::span<const uint8_t> packet) {
  if (packet.size() < sizeof(UDPHeader)) {
    std::cerr << "Invalid packet size!\n";
    return;
  }

  auto headerSpan = packet.subspan(0, sizeof(UDPHeader));

  const UDPHeader &header =
      *reinterpret_cast<const UDPHeader *>(
          headerSpan.data());
  header.display();

  auto dataSpan = packet.subspan(sizeof(UDPHeader));
  std::cout << "Data size: " << dataSpan.size()
            << " bytes\n";
}

int main() {
  uint8_t udpPacket[] = {0x08, 0x15, // Source port
                         0x09, 0x16, // Destination port
                         0x00, 0x10, // Length
                         0x12, 0x34, // Checksum
                         // Some data
                         0x01, 0x02, 0x03, 0x04, 0x05,
                         0x06};

  processUDPPacket(udpPacket);

  return 0;
}