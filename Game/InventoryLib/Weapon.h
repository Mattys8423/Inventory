#include <string>

class Weapon {
private:
    std::string name;
    std::string skin;
    std::string type;
    int ammo;
    std::string fireModes;
    std::string attachmentMag;
    std::string attachmentOptics;
    std::string attachmentStandardStock;
    int equippedAttachmentMagLevel;
    int equippedAttachmentOpticsLevel;
    int equippedAttachmentStandardStockLevel;
    int MagCapacity;
    double damageBody;
    double damageHead;
    double damageLegs;
    double tacticalReloadTime;
    double fullReloadTime;
    bool isFullyKitted;
    int kittedLevel;

public:
    Weapon(const std::string& name = "", const std::string& skin = "", const std::string& type = "", int ammo = 0,
        const std::string& fireModes = "", const std::string& attachmentMag = "", const std::string& attachmentOptics = "",
        const std::string& attachmentStandardStock = "", int equippedAttachmentMagLevel = 0, int equippedAttachmentOpticsLevel = 0,
        int equippedAttachmentStandardStockLevel = 0, int MagCapacity = 0, double damageBody = 0.0, double damageHead = 0.0,
        double damageLegs = 0.0, double tacticalReloadTime = 0.0, double fullReloadTime = 0.0,
        bool isFullyKitted = false, int kittedLevel = 0);

    void displayWeapon() const;

    // Getters
    const std::string& getName() const { return name; }
    const std::string& getSkin() const { return skin; }
    const std::string& getType() const { return type; }
    int getAmmo() const { return ammo; }
    const std::string& getFireModes() const { return fireModes; }
    const std::string& getAttachmentMag() const { return attachmentMag; }
    const std::string& getAttachmentOptics() const { return attachmentOptics; }
    const std::string& getAttachmentStandardStock() const { return attachmentStandardStock; }
    int getEquippedAttachmentMagLevel() const { return equippedAttachmentMagLevel; }
    int getEquippedAttachmentOpticsLevel() const { return equippedAttachmentOpticsLevel; }
    int getEquippedAttachmentStandardStockLevel() const { return equippedAttachmentStandardStockLevel; }
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
    void setAmmo(int value) { ammo = value; }
    void setFireModes(const std::string& value) { fireModes = value; }
    void setAttachmentMag(const std::string& value) { attachmentMag = value; }
    void setAttachmentOptics(const std::string& value) { attachmentOptics = value; }
    void setAttachmentStandardStock(const std::string& value) { attachmentStandardStock = value; }
    void setEquippedAttachmentMagLevel(int value) { equippedAttachmentMagLevel = value; }
    void setEquippedAttachmentOpticsLevel(int value) { equippedAttachmentOpticsLevel = value; }
    void setEquippedAttachmentStandardStockLevel(int value) { equippedAttachmentStandardStockLevel = value; }
    void setMagCapacity(int value) { MagCapacity; }
    void setDamageBody(double value) { damageBody = value; }
    void setDamageHead(double value) { damageHead = value; }
    void setDamageLegs(double value) { damageLegs = value; }
    void setTacticalReloadTime(double value) { tacticalReloadTime = value; }
    void setFullReloadTime(double value) { fullReloadTime = value; }
    void setIsFullyKitted(bool value) { isFullyKitted = value; }
    void setKittedLevel(int value) { kittedLevel = value; }
};