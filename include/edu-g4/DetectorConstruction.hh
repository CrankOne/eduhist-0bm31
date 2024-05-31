#pragma once

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;

namespace edu0bm31 {

class DetectorConstruction : public G4VUserDetectorConstruction {
protected:
    G4LogicalVolume * ConstructHeteroCell();
    G4LogicalVolume * ConstructHomoCell();
public:
    DetectorConstruction() = default;
    ~DetectorConstruction() override = default;

    G4VPhysicalVolume* Construct() override;
    void ConstructSDandField() override;
};

}

// +----+-|-------+
// |    | |       |
// |    | |       |
// +----+-|-------+
//    ^   |  ^
//    |   |  |

