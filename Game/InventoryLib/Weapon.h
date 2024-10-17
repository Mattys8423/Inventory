#include <string>

class Weapon {
private:
    std::string name;
    std::string skin;
    std::string type;
    std::string ammoType;
    std::string fireModes;
    std::string attachmentMag;
    std::string attachmentOptics;
    std::string attachmentStock;
    int equippedAttachmentMagLevel;
    std::string equippedAttachmentOptics;
    int equippedAttachmentStockLevel;
    int MagCapacity;
    double damageBody;
    double damageHead;
    double damageLegs;
    double tacticalReloadTime;
    double fullReloadTime;
    bool isFullyKitted;
    int kittedLevel;

public:
    Weapon(std::string name, const std::string& skin, const std::string& type, const std::string& ammoType,
        const std::string& fireModes, const std::string& attachmentMag, const std::string& attachmentOptics,
        const std::string& attachmentStock, int equippedAttachmentMagLevel, const std::string& equippedAttachmentOptics,
        int equippedAttachmentStockLevel, int MagCapacity, double damageBody, double damageHead, double damageLegs,
        double tacticalReloadTime, double fullReloadTime, bool isFullyKitted, int kittedLevel)
        : name(name), skin(skin), type(type), ammoType(ammoType), fireModes(fireModes), attachmentMag(attachmentMag),
        attachmentOptics(attachmentOptics), attachmentStock(attachmentStock),
        equippedAttachmentMagLevel(equippedAttachmentMagLevel), equippedAttachmentOptics(equippedAttachmentOptics),
        equippedAttachmentStockLevel(equippedAttachmentStockLevel), MagCapacity(MagCapacity), damageBody(damageBody),
        damageHead(damageHead), damageLegs(damageLegs), tacticalReloadTime(tacticalReloadTime), fullReloadTime(fullReloadTime),
        isFullyKitted(isFullyKitted), kittedLevel(kittedLevel) {}

    const void displayInConsole() const;

    // Getters
    const std::string& getName() const { return name; }
    const std::string& getSkin() const { return skin; }
    const std::string& getType() const { return type; }
    const std::string& getAmmo() const { return ammoType; }
    const std::string& getFireModes() const { return fireModes; }
    const std::string& getAttachmentMag() const { return attachmentMag; }
    const std::string& getAttachmentOptics() const { return attachmentOptics; }
    const std::string& getAttachmentStock() const { return attachmentStock; }
    int getEquippedAttachmentMagLevel() const { return equippedAttachmentMagLevel; }
    const std::string& getEquippedAttachmentOptics() const { return equippedAttachmentOptics; }
    int getEquippedAttachmentStockLevel() const { return equippedAttachmentStockLevel; }
    int getMagCapacity() const { return MagCapacity;  }
    double getDamageBody() const { return damageBody; }
    double getDamageHead() const { return damageHead; }
    double getDamageLegs() const { return damageLegs; }
    double getTacticalReloadTime() const { return tacticalReloadTime; }
    double getFullReloadTime() const { return fullReloadTime; }
    bool getIsFullyKitted() const { return isFullyKitted; }
    int getKittedLevel() const { return kittedLevel; }

    // Setters
    void setName(const std::string& value) { name = value; }
    void setSkin(const std::string& value) { skin = value; }
    void setType(const std::string& value) { type = value; }
    void setAmmo(const std::string& value) { ammoType = value; }
    void setFireModes(const std::string& value) { fireModes = value; }
    void setAttachmentMag(const std::string& value) { attachmentMag = value; }
    void setAttachmentOptics(const std::string& value) { attachmentOptics = value; }
    void setAttachmentStock(const std::string& value) { attachmentStock = value; }
    void setEquippedAttachmentMagLevel(int value) { equippedAttachmentMagLevel = value; }
    void setEquippedAttachmentOpticsLevel(const std::string& value) { equippedAttachmentOptics = value; }
    void setEquippedAttachmentStockLevel(int value) { equippedAttachmentStockLevel = value; }
    void setMagCapacity(int value) { MagCapacity; }
    void setDamageBody(double value) { damageBody = value; }
    void setDamageHead(double value) { damageHead = value; }
    void setDamageLegs(double value) { damageLegs = value; }
    void setTacticalReloadTime(double value) { tacticalReloadTime = value; }
    void setFullReloadTime(double value) { fullReloadTime = value; }
    void setIsFullyKitted(bool value) { isFullyKitted = value; }
    void setKittedLevel(int value) { kittedLevel = value; }
};