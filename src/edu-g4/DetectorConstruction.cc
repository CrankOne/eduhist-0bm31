#include "edu-g4/DetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4ThreeVector.hh"
#include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4SDManager.hh"

#include "edu-g4/SensitiveDetector.hh"

namespace edu0bm31 {

G4LogicalVolume *
DetectorConstruction::ConstructHomoCell() {
    G4NistManager * nist = G4NistManager::Instance();

    auto solidCalo = new G4Box("Calo", 2.5*cm, 2.5*cm, 25*cm);
    auto logicCalo = new G4LogicalVolume(solidCalo
            , nist->FindOrBuildMaterial("G4_CESIUM_IODIDE"), "Calo");
    return logicCalo;
}

G4LogicalVolume *
DetectorConstruction::ConstructHeteroCell() {
    float cellSize[2] = { 12.5*cm, 12.5*cm }
        , converterThickness = 0.35*mm
        , scintillatorThickness = 0.15*mm
        ;

    // Get nist material manager
    G4NistManager * nist = G4NistManager::Instance();
    assert(nist->FindOrBuildMaterial("G4_Pb"));  // XXX

    // create logic for cell encompassing converter and scintillator
    auto solidCell = new G4Box("CaloCell"
            , cellSize[0]/2, cellSize[1]/2, (scintillatorThickness + converterThickness)/2 );
    auto logicCell = new G4LogicalVolume(solidCell,
            nist->FindOrBuildMaterial("G4_AIR"),
            "CaloCell");

    // create converter layer
    auto solidConverter = new G4Box("CaloCellConverter"
            , cellSize[0]/2, cellSize[1]/2, converterThickness/2 );
    auto logicConverter = new G4LogicalVolume(solidConverter,
            nist->FindOrBuildMaterial("G4_Pb"),
            "CaloCellConverter");
    auto physConverter = new G4PVPlacement(nullptr,  // no rotation
        G4ThreeVector(0, 0, -scintillatorThickness/2),  // at ...
        logicConverter,                         // its logical volume
        "CaloCellConverter",                    // its name
        logicCell,                              // its mother  volume
        false,                                  // no boolean operation
        0,                                      // copy number
        true );                            // overlaps checking

    // create scintillator layer
    auto solidScintillator = new G4Box("CaloCellScintillator"
            , cellSize[0]/2, cellSize[1]/2, scintillatorThickness/2 );
    auto logicScintillator = new G4LogicalVolume(solidScintillator,
            nist->FindOrBuildMaterial("G4_PLEXIGLASS"),
            "CaloCellScintillator");
    auto physScintillator = new G4PVPlacement(nullptr,  // no rotation
        G4ThreeVector(0, 0, converterThickness/2),  // at ...
        logicScintillator,                      // its logical volume
        "CaloCellScintillator",                 // its name
        logicCell,                              // its mother  volume
        false,                                  // no boolean operation
        0,                                      // copy number
        true );                                 // overlaps checking
    
    return logicCell;
}

G4VPhysicalVolume *
DetectorConstruction::Construct() {
    // Get nist material manager
    G4NistManager * nist = G4NistManager::Instance();
    // Option to switch on/off checking of volumes overlaps
    const G4bool checkOverlaps = true;

    // Create world (box)
    const double worldDims[] = {1*m, 1*m, 3*m};  // full world dimensions
    auto solidWorld = new G4Box("World",
            worldDims[0]/2, worldDims[1]/2, worldDims[2]/2);  // its size
    auto logicWorld = new G4LogicalVolume(solidWorld,  // its solid
            nist->FindOrBuildMaterial("G4_AIR"),     // its material
            "World");                                // its name
    auto physWorld = new G4PVPlacement(nullptr,  // no rotation
        G4ThreeVector(),                           // at (0,0,0)
        logicWorld,                                // its logical volume
        "World",                                   // its name
        nullptr,                                   // its mother  volume
        false,                                     // no boolean operation
        0,                                         // copy number
        checkOverlaps );                           // overlaps checking

    //
    // User geometry
    G4LogicalVolume * logicCalo = ConstructHeteroCell();

    auto physCalo = new G4PVPlacement(nullptr
            , G4ThreeVector(0, 0, 1*m)
            , logicCalo
            , "Calo", logicWorld, false, 0, checkOverlaps);

    return physWorld;
}

void
DetectorConstruction::ConstructSDandField() {
    auto absoSD = new SensitiveDetector("CaloSD");
    G4SDManager::GetSDMpointer()->AddNewDetector(absoSD);
    SetSensitiveDetector("CaloCellScintillator",absoSD);
}

}
