#include "Weapon.h"
#include <iostream>

Weapon::Weapon(const std::string& name, const std::string& skin, const std::string& type, int ammo,
    const std::string& fireModes, const std::string& attachmentMag, const std::string& attachmentOptics,
    const std::string& attachmentStandardStock, int equippedAttachmentMagLevel, int equippedAttachmentOpticsLevel,
    int equippedAttachmentStandardStockLevel, int MagCapacity, double damageBody, double damageHead, double damageLegs,
    double tacticalReloadTime, double fullReloadTime, bool isFullyKitted, int kittedLevel)
    : name(name), skin(skin), type(type), ammo(ammo), fireModes(fireModes), attachmentMag(attachmentMag),
    attachmentOptics(attachmentOptics), attachmentStandardStock(attachmentStandardStock),
    equippedAttachmentMagLevel(equippedAttachmentMagLevel), equippedAttachmentOpticsLevel(equippedAttachmentOpticsLevel),
    equippedAttachmentStandardStockLevel(equippedAttachmentStandardStockLevel), MagCapacity(MagCapacity), damageBody(damageBody),
    damageHead(damageHead), damageLegs(damageLegs), tacticalReloadTime(tacticalReloadTime), fullReloadTime(fullReloadTime),
    isFullyKitted(isFullyKitted), kittedLevel(kittedLevel) {}


void Weapon::displayWeapon() const {
    std::cout << "Weapon Info:" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Skin: " << skin << std::endl;
    std::cout << "Type: " << type << std::endl;
    std::cout << "Ammo: " << ammo << std::endl;
    std::cout << "Fire Modes: " << fireModes << std::endl;
    std::cout << "Attachment Mag: " << attachmentMag << std::endl;
    std::cout << "Attachment Optics: " << attachmentOptics << std::endl;
    std::cout << "Attachment Standard Stock: " << attachmentStandardStock << std::endl;
    std::cout << "Equipped Attachment Mag Level: " << equippedAttachmentMagLevel << std::endl;
    std::cout << "Equipped Attachment Optics Level: " << equippedAttachmentOpticsLevel << std::endl;
    std::cout << "Equipped Attachment Standard Stock Level: " << equippedAttachmentStandardStockLevel << std::endl;
    std::cout << "Damage (Body): " << damageBody << std::endl;
    std::cout << "Damage (Head): " << damageHead << std::endl;
    std::cout << "Damage (Legs): " << damageLegs << std::endl;
    std::cout << "Tactical Reload Time: " << tacticalReloadTime << std::endl;
    std::cout << "Full Reload Time: " << fullReloadTime << std::endl;
    std::cout << "Is Fully Kitted: " << (isFullyKitted ? "Yes" : "No") << std::endl;
    std::cout << "Kitted Level: " << kittedLevel << std::endl;
}
